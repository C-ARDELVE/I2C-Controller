#ifndef __moduleesd_h__
#define __moduleesd_h__

//OTP Testmode Address
#define ESDTadd 0x10
#define ESDIOadd 0x11

//Module ESD-TAO
#define TEN7 0x47
#define TAext 0x46
#define PADOa3 0x45
#define PADOa2 0x44
#define PADOa1 0x43
#define PADinA3 0x42
#define PADinA2 0x41
#define PADinA1 0x40
#define ESDallA 0x00

//Module ESD-TDO
#define UNLOCK 0xB8
#define TDext 0xB0
#define TMI3 0xA8
#define TMI2 0xA0
#define SDApd 0x98
#define TMen 0x90
#define PADId2 0x88
#define PADid1 0x80
#define ESDallD 0x00

//Module ESD-Ten
#define ESDtenOFF 0x00
#define ESDten0 0x01
#define ESDten1 0x02
#define ESDten2 0x04
#define ESDten3 0x08
#define ESDten4 0x10
#define ESDten5 0x20
#define ESDten6 0x40
#define ESDten7 0x80

#endif
