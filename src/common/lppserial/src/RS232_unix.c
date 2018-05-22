#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <malloc.h>
#include <dirent.h>
#include <limits.h>
#include <stdlib.h>
#include <sys/stat.h>

#include <termios.h>
#include <termio.h>
#include "RS232.h"

rs232speed_t rs232cfspeed(unsigned int BaudeRate);

rs232port_t rs232open(char* psPortName)
{
    rs232port_t fd;
    int flags;
    fd = (rs232port_t)open(psPortName, O_RDWR | O_NOCTTY );//| O_NDELAY);
    //fcntl((int)fd, F_SETFL, FNDELAY);
    //fd = open(psPortName, O_RDWR | O_NOCTTY);
#ifdef RS232_debug
    if(fd==-1)printf("can't open Port\n");
#else
    if(fd!=-1)
    {
        //flags = fcntl(fd, F_GETFL);
        //flags |= O_NONBLOCK;
        //flags|=FNDELAY;
        //fcntl(fd, F_SETFL, flags);
        //fcntl((int)fd, F_SETFL, FNDELAY);
    }

#endif
    return fd;
}

int rs232close(rs232port_t fd)
{
    if ((int)fd == -1)
    {
        return -1;
    }
    else
    {
        close(fd);
        return 0;
    }
}

rs232portslist_t* rs232getportlist()
{
    struct dirent *dp;
    char* path="/dev/serial/by-path";
    DIR *dir = opendir(path);
    rs232portslist_t* firstitem=NULL;
    rs232portslist_t* previtem=NULL;
    char* linkname;
    char* devName;
    int i=0;
    if(dir!=NULL)
    {
        while ((dp=readdir(dir)) != NULL)
        {
            int len = strlen(path)+strlen(dp->d_name)+8;//+8 => let's put some margin
            linkname = (char*)malloc(len);
            memset(linkname,'\0',len);
            struct stat statbuf;
            strcpy(linkname,path);
            strcat(linkname,"/");
            strcat(linkname,dp->d_name);
            lstat(linkname, &statbuf);
            if(S_ISLNK(statbuf.st_mode))
            {
                devName=realpath(linkname, NULL);
                if(devName!=NULL)
                {
                    rs232portslist_t* item = (rs232portslist_t*)malloc(sizeof(rs232portslist_t));
                    item->name = devName;
                    item->next = NULL;
                    if(NULL!=previtem)previtem->next = item;
                    previtem = item;
                    if(NULL==firstitem)firstitem = item;
                }
            }
            free(linkname);
        }
    }
    return firstitem;
}

void rs232deleteportlist(rs232portslist_t* list)
{
    if(list!=NULL)
    {
        if(list->next != NULL)
            rs232deleteportlist(list->next);
        free(list);
    }
}

int rs232setup(rs232port_t fd, int ChSize, int BaudeRate, rs232parity Parity, rs232stop NbStop)
{
    if ((int)fd == -1)
    {
        return -1;
    }
    else
    {
        struct termios terminos;
        tcgetattr(fd, &terminos);
        terminos.c_iflag=0;
        terminos.c_oflag=0;
        terminos.c_cflag=0;
        terminos.c_lflag=0;
        cfsetispeed(&terminos, rs232cfspeed(BaudeRate));
        cfsetospeed(&terminos, rs232cfspeed(BaudeRate));
        terminos.c_cflag |= (CLOCAL | CREAD);
        rs232cfparity((int)fd, &terminos, Parity);
        rs232cfnbstop((int)fd, &terminos, NbStop);
        rs232cfcsize((int)fd, &terminos, ChSize);
        terminos.c_cc[VMIN]=0;
        terminos.c_cc[VTIME]=1;
        tcflush(fd, TCIFLUSH);
#ifdef RS232_debug
        if(tcsetattr(fd, TCSANOW, &terminos)!=0)printf("bad setup\n");
#else
        tcsetattr(fd, TCSANOW, &terminos);
#endif
        return 0;
    }
}

int rs232setbaudrate(rs232port_t fd, int baudrate)
{
    if ((int)fd == -1)
    {
        return fd;
    }
    else
    {
        struct termios terminos;
        tcgetattr((int)fd, &terminos);
        cfsetispeed(&terminos, rs232cfspeed(baudrate));
        cfsetospeed(&terminos, rs232cfspeed(baudrate));
        tcsetattr((int)fd, TCSANOW, &terminos);
        return 0;
    }
}

int rs232setparity(rs232port_t fd, rs232parity Parity)
{
    if ((int)fd == -1)
    {
        return fd;
    }
    else
    {
        struct termios terminos;
        tcgetattr((int)fd, &terminos);
        terminos.c_cflag &= ~PARENB;
        terminos.c_cflag &= ~PARODD;
        switch(Parity)
        {
        case rs232parityNo:
            terminos.c_cflag &= ~PARENB;
            break;
        case rs232parityOdd:
            terminos.c_cflag |= PARENB;
            terminos.c_cflag |= PARODD;
            break;
        case rs232parityEven:
            terminos.c_cflag |= PARENB;
            terminos.c_cflag &= ~PARODD;
            break;
        default:
            terminos.c_cflag &= ~PARENB;
            break;
        }
        tcsetattr((int)fd, TCSANOW, &terminos);
        return 0;
    }
}

int rs232setnbstop(rs232port_t fd, rs232stop NbStop)
{
    if ((int)fd == -1)
    {
        return fd;
    }
    else
    {
        struct termios terminos;
        tcgetattr((int)fd, &terminos);
        switch(NbStop)
        {
        case rs232OneStop:
            terminos.c_cflag &= ~CSTOPB;
            break;
        case rs232One5Stop:
            terminos.c_cflag |= CSTOPB;
            break;
        case rs232TwoStop:
            terminos.c_cflag |= CSTOPB;
            break;
        default:
            terminos.c_cflag &= ~CSTOPB;
            break;
        }
        tcsetattr((int)fd, TCSANOW, &terminos);
        return 0;
    }
}


int rs232setcsize(rs232port_t fd, int ChSize)
{
    if ((int)fd == -1)
    {
        return fd;
    }
    else
    {
        struct termios terminos;
        tcgetattr((int)fd, &terminos);
        terminos.c_cflag &= ~CSIZE;
        switch(ChSize)
        {
        case 5:
            terminos.c_cflag |= CS5;
            break;
        case 6:
            terminos.c_cflag |= CS6;
            break;
        case 7:
            terminos.c_cflag |= CS7;
            break;
        default:
            terminos.c_cflag |= CS8;
            break;
        }
        tcsetattr((int)fd, TCSANOW, &terminos);
        return 0;
    }
}

rs232speed_t rs232cfspeed(unsigned int BaudeRate)
{
    if(BaudeRate<25)
        return B0;

    if(BaudeRate<67)
        return B50;

    if(BaudeRate<93)
        return B75;

    if(BaudeRate<123)
        return B110;

    if(BaudeRate<142)
        return B134;

    if(BaudeRate<175)
        return B150;

    if(BaudeRate<250)
        return B200;

    if(BaudeRate<450)
        return B300;

    if(BaudeRate<900)
        return B600;

    if(BaudeRate<1500)
        return B1200;

    if(BaudeRate<2100)
        return B1800;

    if(BaudeRate<3600)
        return B2400;

    if(BaudeRate<7200)
        return B4800;

    if(BaudeRate<1400)
        return B9600;

    if(BaudeRate<28800)
        return B19200;

    if(BaudeRate<48000)
        return B38400;

    if(BaudeRate<86400)
        return B57600;

    if(BaudeRate<172800)
        return B115200;

    if(BaudeRate<345600)
        return B230400;

    if(BaudeRate<345600)
        return B460800;

    if(BaudeRate<748800)
        return B576000;

    if(BaudeRate<1210800)
        return B921600;

    if(BaudeRate<1750000)
        return B1500000;

    if(BaudeRate<2250000)
        return B2000000;

    if(BaudeRate<2750000)
        return B2500000;
    else
        return B3000000;

}


int rs232cfparity(int fd, struct termios *terminos, rs232parity Parity)
{
    if ((int)fd == -1)
    {
        return fd;
    }
    else
    {
        terminos->c_cflag &= ~PARENB;
        terminos->c_cflag &= ~PARODD;
        switch(Parity)
        {
        case rs232parityNo:
            terminos->c_cflag &= ~PARENB;
            terminos->c_cflag &= ~PARODD;
            break;
        case rs232parityOdd:
            terminos->c_cflag |= PARENB;
            terminos->c_cflag |= PARODD;
            break;
        case rs232parityEven:
            terminos->c_cflag |= PARENB;
            terminos->c_cflag &= ~PARODD;
            break;
        default:
            terminos->c_cflag &= ~PARENB;
            terminos->c_cflag &= ~PARODD;
            break;
        }
        return 0;
    }
}

int rs232cfnbstop(int fd, struct termios *terminos, rs232stop NbStop)
{
    if ((int)fd == -1)
    {
        return fd;
    }
    else
    {
        switch(NbStop)
        {
        case 2:
            terminos->c_cflag |= CSTOPB;
            break;
        default:
            terminos->c_cflag &= ~CSTOPB;
            break;
        }
        return 0;
    }
}


int rs232cfcsize(int fd, struct termios *terminos, int ChSize)
{
    if ((int)fd == -1)
    {
        return fd;
    }
    else
    {
        terminos->c_cflag &= ~CSIZE;
        switch(ChSize)
        {
        case 5:
            terminos->c_cflag |= CS5;
            break;
        case 6:
            terminos->c_cflag |= CS6;
            break;
        case 7:
            terminos->c_cflag |= CS7;
            break;
        default:
            terminos->c_cflag |= CS8;
            break;
        }
        return 0;
    }
}


int rs232write(rs232port_t fd,char *psWrite, int WriteBufferSize)
{
    if ((int)fd == -1)
    {
        return -1;
    }
    else
    {
        return write((int)fd, psWrite, WriteBufferSize);
    }
}

int rs232availablebytes(rs232port_t fd)
{
    int bytes;
    ioctl(fd, FIONREAD, &bytes);
    return bytes;
}

int rs232read(rs232port_t fd,char *psReadHex, int ReadBufferSize)
{

    if ((int)fd == -1)
    {
        return -1;
    }
    else
    {
        return read((int)fd, psReadHex, ReadBufferSize);
    }

}


int rs232setRTS(rs232port_t fd)
{
    int status;
    ioctl((int)fd, TIOCMGET, &status);
    status &= ~TIOCM_RTS;
    if (ioctl((int)fd, TIOCMSET, &status))
    {
        return -1;
    }
    return 0;
}

int rs232clearRTS(rs232port_t fd)
{
    int status;
    ioctl((int)fd, TIOCMGET, &status);
    status |= TIOCM_RTS;
    if (ioctl((int)fd, TIOCMSET, &status))
    {
        return -1;
    }
    return 0;
}

int rs232setDTR(rs232port_t fd)
{
    int status;
    ioctl((int)fd, TIOCMGET, &status);
    status &= ~TIOCM_DTR;
    if (ioctl((int)fd, TIOCMSET, &status))
    {
        return -1;
    }
    return 0;
}


int rs232clearDTR(rs232port_t fd)
{
    int status;
    ioctl((int)fd, TIOCMGET, &status);
    status |= TIOCM_DTR;
    if (ioctl((int)fd, TIOCMSET, &status))
    {
        return -1;
    }
    return 0;
}



int rs232saferead(rs232port_t fd,char* data,int count )
{
    int read=0;
    int i=0;
    for(i=0;i<1000;i++)
    {
        read = rs232read((int)fd,data,count);
        //printf("read %d bytes\n",read);
        if(read==-1)read=0;
        count-=read;
        data+=read;
        if(count==0)
            return 0;
        usleep(10);
    }
    return -1;
}



int rs232safewrite(rs232port_t fd,char* data,int count)
{
    int written=0;
    int i=0;
    for(i=0;i<1000;i++)
    {
        written = rs232write((int)fd,data+written,count);
        //printf("%d bytes written\n",written);
        if(written==-1)written=0;
        count-=written;
        data+=written;
        if(count==0)
            return 0;
    }
    return -1;
}


