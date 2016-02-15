#ifndef __moduleservice1_h__
#define __moduleservice1_h__

//SERVICE1 Testmode Address
#define SERVICE1Tadd 0x14
#define SERVICE1IOadd 0x15

extern char SERVICE1[];

//Module SERVICE1-TAI
extern char BGt[];
extern char REFIt[];
extern char IBPt[];
extern char REFI2t[];
extern char REFOt[];
extern char IBPTt[];
extern char REFI3t[];
extern char REFt[];

//Module SERVICE1-TAI
extern char BGOK[];
extern char ENreg[];
extern char BATTOKt[];
extern char BATTok[];
extern char VLOKt[];
extern char VLOK[];
extern char PORBt[];
extern char PORB[];

//Module SERVICE1 Addresses
#define BGtADD 0x40
#define REFItADD 0x41
#define IBPtADD 0x42
#define REFI2tADD 0x43
#define REFOtADD 0x44
#define IBPTtADD 0x45
#define REFI3tADD 0x46
#define REFtADD 0x47

//Module SERVICE1 Addresses
#define BGOKadd 0x80
#define ENREGadd 0x88
#define BATTOKTadd 0x90
#define BATTOKadd 0x98
#define VLOKTadd 0xA0
#define VLOKadd 0xA8
#define PORBTadd 0xB0
#define PORBadd 0xB8

int DECODEservice1TAI(char TAI[]);
int DECODEservice1TDI(char TDI[]);
int DECODEservice1TEN(char TEN[]);
        
#endif