#ifndef RS232_H 
#define RS232_H

#define badPortValue -1
#define rs232noerr 0
typedef int  rs232port_t;
typedef int  rs232speed_t;
typedef enum {rs232OneStop,rs232One5Stop,rs232TwoStop}rs232stop;
typedef enum {rs232parityNo,rs232parityOdd,rs232parityEven}rs232parity;

#ifdef __cplusplus
extern "C" {
#endif
typedef struct rs232portslist_t
{
	char* name;
	struct rs232portslist_t* next;
}rs232portslist_t;
#ifdef __cplusplus
}
#endif


#ifdef __cplusplus
    #define rs232extern extern "C"
#else
    #define rs232extern extern
#endif
rs232extern rs232port_t rs232open(char* psPortName);
rs232extern rs232portslist_t* rs232getportlist();
rs232extern void rs232deleteportlist(rs232portslist_t* list);
rs232extern int rs232close(rs232port_t fd);
rs232extern int rs232setup(rs232port_t fd, int ChSize, int BaudeRate, rs232parity Parity, rs232stop NbStop);
rs232extern int rs232write(rs232port_t fd,char *psWrite, int WriteBufferSize);
rs232extern int rs232read(rs232port_t fd,char *psRead, int ReadBufferSize);
rs232extern int rs232availablebytes(rs232port_t fd);
rs232extern int rs232setparity(rs232port_t fd, rs232parity Parity);
rs232extern int rs232setnbstop(rs232port_t fd, rs232stop NbStop);
rs232extern int rs232setcsize(rs232port_t fd, int ChSize);
rs232extern int rs232setbaudrate(rs232port_t fd, int baudrate);
rs232extern int rs232setRTS(rs232port_t fd);
rs232extern int rs232clearRTS(rs232port_t fd);
rs232extern int rs232setDTR(rs232port_t fd);
rs232extern int rs232clearDTR(rs232port_t fd);
rs232extern int rs232saferead(rs232port_t fd,char* data,int count );
rs232extern int rs232safewrite(rs232port_t fd,char* data,int count);

#endif



