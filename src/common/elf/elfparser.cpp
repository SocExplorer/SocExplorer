/*------------------------------------------------------------------------------
--  This file is a part of the SocExplorer Software
--  Copyright (C) 2013, Laboratory of Plasmas Physic - CNRS
--
--  This program is free software; you can redistribute it and/or modify
--  it under the terms of the GNU General Public License as published by
--  the Free Software Foundation; either version 3 of the License, or
--  (at your option) any later version.
--
--  This program is distributed in the hope that it will be useful,
--  but WITHOUT ANY WARRANTY; without even the implied warranty of
--  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
--  GNU General Public License for more details.
--
--  You should have received a copy of the GNU General Public License
--  along with this program; if not, write to the Free Software
--  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
-------------------------------------------------------------------------------*/
/*--                  Author : Alexis Jeandet
--                     Mail : alexis.jeandet@lpp.polytechnique.fr
----------------------------------------------------------------------------*/
#include "elfparser.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

void elfresolveMachine(Elf64_Half	e_machine,char* MachineName)
{

    //Update from with bash script don't write it by yourself!
    switch(e_machine)
    {
    case EM_NONE   :
        strcpy(MachineName,"No machine");
        break;
    case EM_M32   :
        strcpy(MachineName,"AT&T WE 32100");
        break;
    case EM_SPARC   :
        strcpy(MachineName,"SUN SPARC");
        break;
    case EM_386   :
        strcpy(MachineName,"Intel 80386");
        break;
    case EM_68K   :
        strcpy(MachineName,"Motorola m68k family");
        break;
    case EM_88K   :
        strcpy(MachineName,"Motorola m88k family");
        break;
    case EM_860   :
        strcpy(MachineName,"Intel 80860");
        break;
    case EM_MIPS   :
        strcpy(MachineName,"MIPS R3000 big-endian");
        break;
    case EM_S370  :
        strcpy(MachineName,"IBM System\/370");
        break;
    case EM_MIPS_RS3_LE   :
        strcpy(MachineName,"MIPS R3000 little-endian");
        break;
    case EM_PARISC   :
        strcpy(MachineName,"HPPA");
        break;
    case EM_VPP500   :
        strcpy(MachineName,"Fujitsu VPP500");
        break;
    case EM_SPARC32PLUS   :
        strcpy(MachineName,"Sun's \"v8plus\"");
        break;
    case EM_960   :
        strcpy(MachineName,"Intel 80960");
        break;
    case EM_PPC   :
        strcpy(MachineName,"PowerPC");
        break;
    case EM_PPC64   :
        strcpy(MachineName,"PowerPC 64-bit");
        break;
    case EM_S390   :
        strcpy(MachineName,"IBM S390");
        break;
    case EM_V800   :
        strcpy(MachineName,"NEC V800 series");
        break;
    case EM_FR20   :
        strcpy(MachineName,"Fujitsu FR20");
        break;
    case EM_RH32   :
        strcpy(MachineName,"TRW RH-32");
        break;
    case EM_RCE   :
        strcpy(MachineName,"Motorola RCE");
        break;
    case EM_ARM   :
        strcpy(MachineName,"ARM");
        break;
    case EM_SH   :
        strcpy(MachineName,"Hitachi SH");
        break;
    case EM_SPARCV9   :
        strcpy(MachineName,"SPARC v9 64-bit");
        break;
    case EM_TRICORE   :
        strcpy(MachineName,"Siemens Tricore");
        break;
    case EM_ARC   :
        strcpy(MachineName,"Argonaut RISC Core");
        break;
    case EM_H8_300 :
        strcpy(MachineName,"Hitachi H8\/300");
        break;
    case EM_H8_300H  :
        strcpy(MachineName,"Hitachi H8\/300H");
        break;
    case EM_H8S   :
        strcpy(MachineName,"Hitachi H8S");
        break;
    case EM_H8_500  :
        strcpy(MachineName,"Hitachi H8\/500");
        break;
    case EM_IA_64   :
        strcpy(MachineName,"Intel Merced");
        break;
    case EM_MIPS_X   :
        strcpy(MachineName,"Stanford MIPS-X");
        break;
    case EM_COLDFIRE   :
        strcpy(MachineName,"Motorola Coldfire");
        break;
    case EM_68HC12   :
        strcpy(MachineName,"Motorola M68HC12");
        break;
    case EM_MMA   :
        strcpy(MachineName,"Fujitsu MMA Multimedia Accelerator");
        break;
    case EM_PCP   :
        strcpy(MachineName,"Siemens PCP");
        break;
    case EM_NCPU   :
        strcpy(MachineName,"Sony nCPU embeeded RISC");
        break;
    case EM_NDR1   :
        strcpy(MachineName,"Denso NDR1 microprocessor");
        break;
    case EM_STARCORE :
        strcpy(MachineName,"Motorola Start*Core processor");
        break;
    case EM_ME16   :
        strcpy(MachineName,"Toyota ME16 processor");
        break;
    case EM_ST100   :
        strcpy(MachineName,"STMicroelectronic ST100 processor");
        break;
    case EM_TINYJ   :
        strcpy(MachineName,"Advanced Logic Corp. Tinyj emb.fam");
        break;
    case EM_X86_64   :
        strcpy(MachineName,"AMD x86-64 architecture");
        break;
    case EM_PDSP   :
        strcpy(MachineName,"Sony DSP Processor");
        break;
    case EM_FX66 :
        strcpy(MachineName,"Siemens FX66 microcontroller");
        break;
    case EM_ST9PLUS :
        strcpy(MachineName,"STMicroelectronics ST9+ 8\/16 mc");
        break;
    case EM_ST7   :
        strcpy(MachineName,"STmicroelectronics ST7 8 bit mc");
        break;
    case EM_68HC16   :
        strcpy(MachineName,"Motorola MC68HC16 microcontroller");
        break;
    case EM_68HC11   :
        strcpy(MachineName,"Motorola MC68HC11 microcontroller");
        break;
    case EM_68HC08   :
        strcpy(MachineName,"Motorola MC68HC08 microcontroller");
        break;
    case EM_68HC05   :
        strcpy(MachineName,"Motorola MC68HC05 microcontroller");
        break;
    case EM_SVX   :
        strcpy(MachineName,"Silicon Graphics SVx");
        break;
    case EM_ST19   :
        strcpy(MachineName,"STMicroelectronics ST19 8 bit mc");
        break;
    case EM_VAX   :
        strcpy(MachineName,"Digital VAX");
        break;
    case EM_CRIS   :
        strcpy(MachineName,"Axis Communications 32-bit embedded processor");
        break;
    case EM_JAVELIN   :
        strcpy(MachineName,"Infineon Technologies 32-bit embedded processor");
        break;
    case EM_FIREPATH   :
        strcpy(MachineName,"Element 14 64-bit DSP Processor");
        break;
    case EM_ZSP   :
        strcpy(MachineName,"LSI Logic 16-bit DSP Processor");
        break;
    case EM_MMIX   :
        strcpy(MachineName,"Donald Knuth's educational 64-bit processor");
        break;
    case EM_HUANY   :
        strcpy(MachineName,"Harvard University machine-independent object files");
        break;
    case EM_PRISM   :
        strcpy(MachineName,"SiTera Prism");
        break;
    case EM_AVR   :
        strcpy(MachineName,"Atmel AVR 8-bit microcontroller");
        break;
    case EM_FR30   :
        strcpy(MachineName,"Fujitsu FR30");
        break;
    case EM_D10V   :
        strcpy(MachineName,"Mitsubishi D10V");
        break;
    case EM_D30V   :
        strcpy(MachineName,"Mitsubishi D30V");
        break;
    case EM_V850   :
        strcpy(MachineName,"NEC v850");
        break;
    case EM_M32R   :
        strcpy(MachineName,"Mitsubishi M32R");
        break;
    case EM_MN10300   :
        strcpy(MachineName,"Matsushita MN10300");
        break;
    case EM_MN10200   :
        strcpy(MachineName,"Matsushita MN10200");
        break;
    case EM_PJ   :
        strcpy(MachineName,"picoJava");
        break;
    case EM_OPENRISC   :
        strcpy(MachineName,"OpenRISC 32-bit embedded processor");
        break;
    case EM_ARC_A5   :
        strcpy(MachineName,"ARC Cores Tangent-A5");
        break;
    case EM_XTENSA   :
        strcpy(MachineName,"Tensilica Xtensa Architecture");
        break;
    default:
        strcpy(MachineName,"Unknow Machine");
        break;
    }

}


elfparser::elfparser()
{
    this->opened = false;
    this->type_elf = false;
    this->elfFile = NULL;
    this->e = NULL;
}


int elfparser::setFilename(const QString &name)
{
    this->closeFile();
    if(elf_version(EV_CURRENT)==EV_NONE)return 0;
#ifdef _ELF_WINDOWS_
    this->elfFile = open(name.toStdString().c_str(),O_RDONLY|O_BINARY ,0);
#else
    this->elfFile = open(name.toStdString().c_str(),O_RDONLY ,0);
#endif
    if(this->elfFile==NULL)return 0;
    this->e = elf_begin(this->elfFile,ELF_C_READ,NULL);
    if(this->e==NULL)return 0;
    this->ek = elf_kind(this->e);
    gelf_getehdr (this->e, &this->ehdr );
    elf_getshdrstrndx (this->e, &this->shstrndx);
    this->updateSegments();
    this->updateSections();
    return 1;
}


int elfparser::closeFile()
{
    if(this->elfFile!=NULL)
    {
        if(this->e!=NULL)
        {
            elf_end(this->e);
            this->e = NULL;
        }
        close(this->elfFile);
        this->elfFile = NULL;
    }
    return 0;
}


bool elfparser::isopened()
{
    return this->opened;
}


bool elfparser::iself()
{
    return this->type_elf;
}


QString elfparser::getArchitecture()
{
    QString arch("");
    char archName[256]="";
    if(this->e!=NULL)
    {
        elfresolveMachine(this->ehdr.e_machine,archName);
        arch = archName;
    }
    return arch;
}


QString elfparser::getType()
{
    QString kind("");
    if(this->e!=NULL)
    {
        switch(this->ek)
        {
        case ELF_K_AR:
            kind = "Archive";
            break;
        case ELF_K_ELF:
            kind = "Elf";
            break;
        case ELF_K_COFF:
            kind = "COFF";
            break;
        case ELF_K_NUM:
            kind = "NUM";
            break;
        case ELF_K_NONE:
            kind = "Data";
            break;
        default:
            kind = "Unknow";
            break;
        }
    }
    return kind;
}


int32_t  elfparser::getVersion()
{
    if(this->e!=NULL)
    {
        return this->ehdr.e_version;
    }
}


int elfparser::getSectioncount()
{
    return (int)this->SectionCount;
}


int elfparser::getSegmentcount()
{
    return (int)this->SegmentCount;
}


QString elfparser::getSegmentType(int index)
{
    QString type("");
    if(this->e!=NULL)
    {
        if(index < this->Segments.count())
        {
            switch(this->Segments.at(index)->p_type)
            {
            case PT_NULL:
                type = "Program header table entry unused";
                break;
            case PT_LOAD:
                type = "Loadable program segment";
                break;
            case PT_DYNAMIC	:
                type = "Dynamic linking information";
                break;
            case PT_INTERP:
                type ="Program interpreter";
                break;
            case PT_NOTE:
                type = "Auxiliary information";
                break;
            case PT_SHLIB:
                type = "Reserved";
                break;
            case PT_PHDR:
                type =	"Entry for header table itself";
                break;
            case PT_TLS:
                type = "Thread-local storage segment";
                break;
            case PT_NUM:
                type = "Number of defined types";
                break;
            case PT_LOOS:
                type =	"Start of OS-specific";
                break;
            case PT_SUNWSTACK:
                type = "Stack segment";
                break;
            case PT_LOPROC:
                type = "Start of processor-specific";
                break;
            case PT_HIPROC:
                type = "End of processor-specific";
                break;
            default:
                type = "Unknow Section Type";
                break;
            }
        }
    }

    return type;
}


int64_t elfparser::getSegmentOffset(int index)
{
    int64_t Offset;
    if(this->e!=NULL)
    {
        if(index < this->Segments.count())
        {
            Offset =  (int64_t)this->Segments.at(index)->p_offset;
        }
    }
    return Offset;
}


int64_t elfparser::getSegmentVaddr(int index)
{
    int64_t Vaddr = 0;
    if(this->e!=NULL)
    {
        if(index < this->Segments.count())
        {
            Vaddr =  (int64_t)this->Segments.at(index)->p_vaddr;
        }
    }
    return Vaddr;
}


int64_t elfparser::getSegmentPaddr(int index)
{
    int64_t Paddr=0;
    if(this->e!=NULL)
    {
        if(index < this->Segments.count())
        {
            Paddr = (int64_t)this->Segments.at(index)->p_paddr;
        }
    }
    return Paddr;
}

int64_t elfparser::getSectionPaddr(int index)
{
    int64_t Paddr=0;
    if(this->e!=NULL)
    {
        if(index < this->sections.count())
        {
            Paddr = (int64_t)this->sections.at(index)->section_header->sh_addr;
        }
    }
    return Paddr;
}


int64_t elfparser::getSegmentFilesz(int index)
{
    int64_t FileSz=0;
    if(this->e!=NULL)
    {
        if(index < this->Segments.count())
        {
            FileSz = (int64_t)this->Segments.at(index)->p_filesz;
        }
    }
    return FileSz;
}

int64_t elfparser::getSectionDatasz(int index)
{
    int64_t DataSz=0;
    if(this->e!=NULL)
    {
        if(index < this->sections.count())
        {
            DataSz = (int64_t)this->sections.at(index)->data->d_size;
        }
    }
    return DataSz;
}

bool elfparser::getSectionData(int index, char **buffer)
{
    if(this->e!=NULL)
    {
        if(index < this->sections.count())
        {
            *buffer = (char *)this->sections.at(index)->data->d_buf;
            return true;
        }
    }
    return false;
}


int64_t elfparser::getSegmentMemsz(int index)
{
    int64_t MemSz=0;
    if(this->e!=NULL)
    {
        if(index < this->Segments.count())
        {
            MemSz = (int64_t)this->Segments.at(index)->p_memsz;
        }
    }
    return MemSz;
}

int64_t elfparser::getSectionMemsz(int index)
{
    int64_t MemSz=0;
    if(this->e!=NULL)
    {
        if(index < this->sections.count())
        {
            MemSz = (int64_t)this->sections.at(index)->section_header->sh_size;
        }
    }
    return MemSz;
}


QString elfparser::getSegmentFlags(int index)
{
    QString flags("");
    if(this->e!=NULL)
    {
        if(index < this->Segments.count())
        {
            if((this->Segments.at(index)->p_flags&PF_X) == PF_X)flags+="x";
            if((this->Segments.at(index)->p_flags&PF_W) == PF_W)flags+="w";
            if((this->Segments.at(index)->p_flags&PF_R) == PF_R)flags+="r";
            if((this->Segments.at(index)->p_flags&PF_MASKOS) == PF_MASKOS)flags+=" OS-specific";
            if((this->Segments.at(index)->p_flags&PF_MASKPROC) == PF_MASKPROC)flags+=" Processor-specific";
        }
    }
    return flags;
}


QString elfparser::getSectionName(int index)
{
    char* nameChr = elf_strptr(this->e , this->shstrndx , this->sections.at(index)->section_header->sh_name);
    return QString(nameChr);
}


void elfparser::updateSections()
{
    for(int i=0;i<this->sections.count();i++)
    {
        delete this->sections.at(i);
    }
    this->sections.clear();
    this->scn = elf_nextscn (this->e , NULL );
    this->SectionCount = 0;
    while( this->scn != NULL )
    {
        GElf_Shdr* shdr = (GElf_Shdr*)malloc(sizeof(GElf_Shdr));
        gelf_getshdr ( this->scn , shdr );
        Elf_Data*  data = elf_getdata(this->scn, NULL);
        this->sections.append(new Elf_Section(data,shdr));
        this->SectionCount+=1;
        this->scn = elf_nextscn(e , scn);
    }
}


void elfparser::updateSegments()
{
    elf_getphdrnum (this->e , &this->SegmentCount);
    for(int i=0;i<this->Segments.count();i++)
    {
        free(this->Segments.at(i));
    }
    this->Segments.clear();
    for(int i=0;i<this->SegmentCount;i++)
    {
        GElf_Phdr* header=(GElf_Phdr*)malloc(sizeof(GElf_Phdr));
        gelf_getphdr (this->e , i , header );
        this->Segments.append(header);
    }
}





QString elfparser::getSectionType(int index)
{
    QString type("");
    if(this->e!=NULL)
    {
        if(index < this->Segments.count())
        {
            switch(this->Segments.at(index)->p_type)
            {
            case SHT_NULL	 :	type = "Section header table entry unused"; break;
            case SHT_PROGBITS	  :		type = "Program data"; break;
            case SHT_SYMTAB	  :		type = "Symbol table"; break;
            case SHT_STRTAB	  :		type = "String table"; break;
            case SHT_RELA	  :		type = "Relocation entries with addends"; break;
            case SHT_HASH	  :		type = "Symbol hash table"; break;
            case SHT_DYNAMIC	 :		type = "Dynamic linking information"; break;
            case SHT_NOTE	  :		type = "Notes"; break;
            case SHT_NOBITS    :type = "Program space with no data (bss)"; break;
            case SHT_REL    :type = "Relocation entries, no addends"; break;
            case SHT_SHLIB	 :		type = "Reserved"; break;
            case SHT_DYNSYM	  :		type = "Dynamic linker symbol table"; break;
            case SHT_INIT_ARRAY	  :		type = "Array of constructors"; break;
            case SHT_FINI_ARRAY	  :		type = "Array of destructors"; break;
            case SHT_PREINIT_ARRAY :		type = "Array of pre-constructors"; break;
            case SHT_GROUP	  :		type = "Section group"; break;
            case SHT_SYMTAB_SHNDX  :		type = "Extended section indeces"; break;
            case SHT_NUM		  :		type = "Number of defined types. "; break;
            case SHT_LOOS	  :	type = "Start OS-specific. "; break;
            case SHT_LOSUNW	  :	type = "Sun-specific low bound. "; break;
            case SHT_SUNW_COMDAT  : type = " "; break;
            case SHT_SUNW_syminfo  : type = " "; break;
            case SHT_GNU_verdef	  :	type = "Version definition section. "; break;
            case SHT_GNU_verneed	  :	type = "Version needs section. "; break;
            case SHT_GNU_versym	  :	type = "Version symbol table. "; break;
            case SHT_LOPROC	  :	type = "Start of processor-specific"; break;
            case SHT_HIPROC	 :	type = "End of processor-specific"; break;
            case SHT_HIUSER	 :	type = "End of application-specific"; break;
            }
        }
    }
    return type;
}

bool elfparser::isElf(const QString &File)
{
    int file =0;
#ifdef _ELF_WINDOWS_
    file = open(File.toStdString().c_str(),O_RDONLY|O_BINARY ,0);
#else
    file = open(File.toStdString().c_str(),O_RDONLY ,0);
#endif
    char Magic[4];
    if(file!=-1)
    {
        read(file,Magic,4);
        close(file);
        if(Magic[0]==0x7f && Magic[1]==0x45 && Magic[2]==0x4c && Magic[3]==0x46)
        {
            return true;
        }
    }
    return false;
}








