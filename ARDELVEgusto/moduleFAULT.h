#ifndef __modulefault_h__
#define __modulefault_h__


//FAULT Testmode Address
#define FAULTTadd 0x1C
#define FAULTIOadd 0x1D

//Module FAULT-TAO
#define VBEt 0x47
#define TDACt 0x46
#define THERMt 0x45
#define REFbuf 0x44
#define VFLTpd 0x43
#define RESETpd 0x42
#define LFLTpd 0x41
#define THRM 0x40
#define FAULTallOFFa 0x00

//Module FAULT-TDO
#define FOSCt 0xB8
#define CSF10ms 0xB0
#define FLTenLO 0xA8
#define ENbckoV 0xA0
#define EN3o 0x98
#define EN2o 0x90
#define ENCo 0x88
#define ENSo 0x80
#define FAULTallOFFd 0x00

//Module FAULT-Ten
#define FAULTtenOFF 0x00
#define FAULTten0 0x01
#define FAULTten1 0x02
#define FAULTten2 0x04
#define FAULTten3 0x08
#define FAULTten4 0x10
#define FAULTten5 0x20
#define FAULTten6 0x40
#define FAULTten7 0x80

#endif