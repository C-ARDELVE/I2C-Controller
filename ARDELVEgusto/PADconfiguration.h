#ifndef __padconfiguration_h__
#define __padconfiguration_h__

//PAD Configuration Register
#define addPADconf 0x00
//PAD Configuration Commands
#define RESETboth 0x04
#define RESETpad 0x02
#define RESETtest 0x01

//GPIO Configuration Address
#define EN2cmd 0x01
#define EN3cmd 0x02
#define ENCcmd 0x03
#define ENBCKcmd 0x04

//GPIO Configurations Commands
#define GPIOoD 0x03
#define GPIOoOD 0x0B
#define GPIOoA 0x10
#define GPIOiA 0x12
#define GPIOiD 0x13

//PAD1 Output Analog Address
#define addPADoSELa 0x33
//PAD1 Output Analog Selector Commands
#define PADtao0G1 0x21
#define PADtao1G1 0x11
//PAD1 Output Digital Address
#define addPADoSELd 0x34
//PAD1 Output Digial Selector Commands
#define PADtdo0G1 0x21
#define PADtdo1G1 0x11
//PAD1 Input Analog Selector Address
#define addPADiSELa 0x30
//PAD1 Input Analog Selector Commands
#define PADiaG 0xAA  //All Inputs tied to GND
#define PADia1G 0x02  //PAD1 input to GND
//PAD1 Input Digital Selector Address
#define addPADiSELd 0x31
//PAD1 Input Digital Selector Commands
#define PADid1G 0x02  //PAD1 input to GND
//PAD1 Input Testmode Selector Address
#define addPADiSELt 0x32
//PAD Input Testmode Selector Command
#define PADita1 0x04  //PAD1 to TAext
#define PADitd1 0x20  //PAD1 to TDext

//PAD2 Output Analog Selector Command
#define PADtao0G2 0x65
#define PADtao1G2 0x75
//PAD2 Output Digial Selector Command
#define PADtdo0G2 0x65
#define PADtdo1G2 0x75
//PAD2 Input Analog Selector Command
#define PADia2G 0x08
//PAD2 Input Digital Selector Command
#define PADid2G 0x08
//PAD2 Input Testmode Selector Command
#define PADita2 0x05
#define PADitd2 0x28

//PAD3 Output Analog Selector Commands
#define PADtao0G3 0xA9
#define PADtao1G3 0xB9
//PAD3 Output Digial Selector Commands
#define PADtdo0G3 0xA9
#define PADtdo1G3 0xB9
//PAD3 Input Analog Selector Commands
#define PADia3G 0x20
#define PADia4G 0x80
//PAD3 Input Digital Selector Commands
#define PADid3G 0x20
//PAD3 Input testmode Selectro Command
#define PADita3 0x06
#define PADitd3 0x38

//PAD4 Output Analog Selector Commands
#define PADtao0G4 0xED
#define PADtao1G4 0xFD
//PAD4 Output Digial Selector Commands
#define PADtdo0G4 0xED
#define PADtdo1G4 0xFD
//PAD4 Input Analog Selector Commands
#define PADia4G 0x80
//PAD4 Input Digital Selector Commands
#define PADid4G 0x80
//PAD4 Input Testmode Selector Command
#define PADita4 0x07
#define PADitd4 0x38

#endif
