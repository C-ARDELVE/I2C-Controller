#ifndef __moduleservice2_h__
#define __moduleservice2_h__

//SERVICE2 Testmode Address
#define SERVICE2Tadd 0x16
#define SERVICE2IOadd 0x17
char SERVICE2[]="SERVICE2";

//Module SERVICE2-TAI
char VLFBt[]="VLFBt";
char SRV2PORBt[]="SRV2PORBt";
char ENuvlo[]="ENuvlo";
char ENBCKt[]="ENBCKt";
char SRV2GA4[]="SRV2GA4";
char SRV2GA5[]="SRV2GA5";
char SRV2GA6[]="SRV2GA6";
char SRV2GA7[]="SRV2GA7";

//Module SERVICE2-TDO
char ENBCKi[]="ENBCKi";
char ENflt[]="ENflt";
char OKt[]="OKt";
char OTPok[]="OTPok";
char SRV2GD4[]="SRV2GD5";
char SRV2GD5[]="SRV2GD6";
char SRV2GD7[]="SRV2GD7";

//Module SERVICE2-Addresses
#define SRV2GA7add 0x47
#define SRV2GA6add 0x46
#define SRV2GA5add 0x45
#define SRV2GA4add 0x44
#define ENBCKadd 0x43
#define ENUVLOadd 0x42
#define SRV2PORBtadd 0x41
#define VLFBtadd 0x40

//Module SERVICE2-Addresses
#define SRV2GD7add 0xB8
#define SRV2GD6add 0xB0
#define SRV2GD5add 0xA8
#define SRV2ten15add 0xA0
#define OTPOKadd 0x98
#define OKTadd 0x90
#define ENFLTadd 0x88
#define SRV2ENBCKiadd 0x80

int DECODEservice2TAI(char TAI[]);
int DECODEservice2TDI(char TDI[]);
int DECODEservice2TEN(char TEN[]);
        
#endif
