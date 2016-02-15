#ifndef __modulesequencer_h__
#define __modulesequencer_h__

//SEQUENCER Testmode Address
#define SEQUENCERTadd 0x2E
#define SEQUENCERIOadd 0x2F
char SEQUENCER[]="SEQUENCER";


//Module SEQUENCER-TAI
char OTPsew[]="OTPseq";
char ENcs[]="ENcs";
char EN3i[]="EN3i";
char EN2i[]="EN2i";
char ENCi[]="ENCi";
char ENSi[]="ENSi";
char ENLi[]="ENLi";
//char ENBCKi[]="ENBCKi";

//Module SERVICE2-TDO
char PC216[]="PC216";
char ENCSt[]="ENCSt";
char EN3t[]="EN2t";
char ENCt[]="ENCt";
char ENSt[]="ENSt";
char ENLt[]="ENLt";
//char ENBCKt[]="ENBCKt";

//Module SEQUENCER-TAO Addresses
#define ENBCKIadd 0x47
#define ENLIadd 0x46
#define ENSIadd 0x45
#define ENCIadd 0x44
#define EN2Iadd 0x43
#define EN3Iadd 0x42
#define ENCSadd 0x41
#define OTPLOCKadd 0x40

//Module SEQUENCER-TDO Addresses
#define ENBCKTadd 0xB8
#define ENLTadd 0xB0
#define ENSTadd 0xA8
#define ENCTadd 0xA0
#define EN2Tadd 0x98
#define EN3Tadd 0x90
#define ENCSTadd 0x88
#define SEQTEN0add 0x80

int DECODEsequencerTAI(char TAI[]);
int DECODEsequencerTDI(char TDI[]);
int DECODEsequencerTEN(char TEN[]);
#endif
