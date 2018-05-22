#ifndef GRESBSTATUSQUERY_H
#define GRESBSTATUSQUERY_H

enum GresbStatusQueryOption{
    LinkStatus,
    LinkStatistics,
    NodeAddressStatistics,
    GetRoute};

struct gresb_status_query_str
{
    char protocolIdentifier;
    char reserved1;
    char reserved0;
    char option;
    char value3;
    char value2;
    char value1;
    char value0;
};
typedef gresb_status_query_str gresb_status_query_t;

struct gresb_link_status_reply_str
{
    char byte3;
    char byte2;
    char byte1;
    char byte0;
};
typedef gresb_link_status_reply_str gresb_link_status_reply_t;

struct gresb_link_statistics_reply_str
{
    char numberOfPacketsReceived[4];
    char sizeOfDataReceived[4];
    char numberOfPacketsWithEEPReceived[4];
    char numberOfTruncatedPacketsReceived[4];
    char numberOfPacketsTransmitted[4];
    char sizeOfDataTransmitted[4];

    /*char sizeOfDataTransmitted[4];
    char numberOfPacketsTransmitted[4];
    char numberOfTruncatedPacketsReceived[4];
    char numberOfPacketsWithEEPReceived[4];
    char sizeOfDataReceived[4];
    char numberOfPacketsReceived[4];*/
};
typedef gresb_link_statistics_reply_str gresb_link_statistics_reply_t;


#endif // GRESBSTATUSQUERY_H
