#include "rmapoperations.h"

RMAP::RMAP(RMAP_command_codes commandCode, char targetLogicalAddress, char initiatorLogicalAddress, int startAddress, int nbBytes, char* data)
{
    char packetType;            // 2 most Significant Bits
    char command;               // 4 bits
    char replyAddressLength;    // 2 Least Significant Bits
    int SPWPacketSize;

    // GRESB HEADER
    if (data == NULL){
        SPWPacketSize = sizeof(RMAPHeader) ;
        dataCRC = 0x00;
    }
    else{
        SPWPacketSize = sizeof(RMAPHeader) + nbBytes + 1 ; // SPW Packet = Header + Data + dataCRC
        dataCRC = RMAPCalculateDataCRC(data, nbBytes);
    }
    GRESBHeader.GRESBProtocoleID = 0x00; // packets with protocole ID 0 have SpaceWire a packet as payload
    GRESBHeader.SPWPacketSize2 = (SPWPacketSize>>16);
    GRESBHeader.SPWPacketSize1 = (SPWPacketSize>>8);
    GRESBHeader.SPWPacketSize0 = (SPWPacketSize);

    // SPACEWIRE HEADER
    packetType = (char) 0b01;               // 0b01 for a command, 0b00 for a reply
    command = (char) commandCode;
    replyAddressLength = (char) 0b00;       // RMAP command: number of bytes in the reply address field
                                            // RMAP reply: copy of the reply address field of the command
    switch (commandCode){
    case writeSingle_noVer_noRep:
    case writeSingle_noVer_Rep:
    case writeSingle_ver_noRep:
    case writeSingle_ver_rep:
        if (nbBytes > 4) command = command + 1; // switch between Single and Incremental Read/Write operations
        break;
    default:
        break;
    }
    RMAPHeader.targetLogicalAddress = targetLogicalAddress ;
    RMAPHeader.protocolIdentifier = 0x01;      // 0x01 is the protocole identifier for RMAP
    RMAPHeader.instruction = (packetType<<6) + (command<<2) + (replyAddressLength);
    RMAPHeader.key = 0;                        // used for command authorization
    RMAPHeader.initiatorLogicalAddress = initiatorLogicalAddress; // 0 is the default address for the GRESB module
    RMAPHeader.transactionIdentifier1 = 0x00;
    RMAPHeader.transactionIdentifier0 = 0x01;
    RMAPHeader.extendedAddress = 0x00;
    RMAPHeader.address3 = (char) (startAddress>>24);
    RMAPHeader.address2 = (char) (startAddress>>16);
    RMAPHeader.address1 = (char) (startAddress>>8);
    RMAPHeader.address0 = (char) (startAddress);
    RMAPHeader.dataLength2 = (char) (nbBytes>>16);
    RMAPHeader.dataLength1 = (char) (nbBytes>>8);
    RMAPHeader.dataLength0 = (char) (nbBytes);
    RMAPHeader.headerCRC = RMAPCalculateHeaderCRC();
}

unsigned char RMAP::RMAPCalculateCRC(unsigned char INCR, unsigned char INBYTE)
{
    return RMAP_CRCTable[INCR ^ INBYTE];
}

unsigned char RMAP::RMAPCalculateHeaderCRC()
{
    unsigned char INCR = 0;

    INCR = RMAPCalculateCRC(INCR, RMAPHeader.targetLogicalAddress);
    INCR = RMAPCalculateCRC(INCR, RMAPHeader.protocolIdentifier);
    INCR = RMAPCalculateCRC(INCR, RMAPHeader.instruction);
    INCR = RMAPCalculateCRC(INCR, RMAPHeader.key);
    INCR = RMAPCalculateCRC(INCR, RMAPHeader.initiatorLogicalAddress);
    INCR = RMAPCalculateCRC(INCR, RMAPHeader.transactionIdentifier1);
    INCR = RMAPCalculateCRC(INCR, RMAPHeader.transactionIdentifier0);
    INCR = RMAPCalculateCRC(INCR, RMAPHeader.extendedAddress);
    INCR = RMAPCalculateCRC(INCR, RMAPHeader.address3);
    INCR = RMAPCalculateCRC(INCR, RMAPHeader.address2);
    INCR = RMAPCalculateCRC(INCR, RMAPHeader.address1);
    INCR = RMAPCalculateCRC(INCR, RMAPHeader.address0);
    INCR = RMAPCalculateCRC(INCR, RMAPHeader.dataLength2);
    INCR = RMAPCalculateCRC(INCR, RMAPHeader.dataLength1);
    INCR = RMAPCalculateCRC(INCR, RMAPHeader.dataLength0);

    return(INCR);
}

unsigned char RMAP::RMAPCalculateDataCRC(char *data, int nbBytes)
{
    unsigned char INCR = 0;

    for (int k=0; k<nbBytes; k++)
    {
        INCR = RMAPCalculateCRC(INCR, data[k]);
    }

    return(INCR);
}
