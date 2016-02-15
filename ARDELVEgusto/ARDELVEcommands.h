#ifndef __ardelvecommands_h__
#define __ardelvecommands_h__

//Test PAD Decoder
char EN2[]="EN2";
char EN3[]="EN3";
char ENC[]="ENC";
char ENBCK[]="ENBCK";

//Test Input Decoder
char TDext[]="TDext";
char TAext[]="TAext";

//Test PAD Mode Decoder
char DIGOUT0[]="DIGOUT0"; //1=Digital Out (TDO0)
char DIGOUT1[]="DIGOUT1"; //2=Digital Out (TDO1)
char ANAOUT0[]="ANAOUT0"; //3=Analogue Out (TAO0)
char ANAOUT1[]="ANAOUT1"; //4=Analogue Out (TAO1)
char TESTDIN[]="TESTDIN"; //5=Digital Test Input
char TESTAIN[]="TESTAIN"; //6=Analogue Test Input

//Testmode ENABLE Decoder
char Ten0[]="Ten0";
char Ten1[]="Ten1";
char Ten2[]="Ten2";
char Ten3[]="Ten3";
char Ten4[]="Ten4";
char Ten5[]="Ten5";
char Ten6[]="Ten6";
char Ten7[]="Ten7";
char Ten8[]="Ten8";
char Ten9[]="Ten9";
char Ten10[]="Ten10";
char Ten11[]="Ten11";
char Ten12[]="Ten12";
char Ten13[]="Ten13";
char Ten14[]="Ten14";
char Ten15[]="Ten15";
char ResetT[]="ResetT";

//Testmode ENABLE Addresses
#define TEN0add 0x01
#define TEN1add 0x02
#define TEN2add 0x04
#define TEN3add 0x08
#define TEN4add 0x10
#define TEN5add 0x20
#define TEN6add 0x40
#define TEN7add 0x80
#define TEN8add 0x01
#define TEN9add 0x02
#define TEN10add 0x04
#define TEN11add 0x08
#define TEN12add 0x10
#define TEN13add 0x20
#define TEN14add 0x40
#define TEN15add 0x80

//Global TAO/TDO/TEN Reset
#define TENreset 0x00
#define ResetA 0x00
#define ResetD 0x00

int DECODEmodule(char MODULE[]);
void DECODEtao(char MODULE[], char NAME[]);
void DECODEtdo(char MODULE[], char NAME[]);
int DECODEprobe(char MODULE[], char NAME[]);
int DECODEten(char NAME[]);
int DECODEtestpad(char PAD[]);
int DECODEtestINPUT(char TESTINPUT[]);
int DECODEpadmode(char PADMODE[]);

void TEN(char MODULE[], char NAME[]);

void PROBEwithINPUT(char MODULE[],char NAME[],char PADo[],char TESTINPUT[],char PADi[]);
int compare(int A, int D);

void PASSWORD();
void ENABLEtestmode();
void DISABLEtestmode();
void LOCK();

void STARTUP();
void RESETall();
void RESETtestmode();
void RESETpads();

void READallOTP();
void RESETallOTP();
int READotp(int cmd);
void WRITEotp(int BANK, int OTPdata);
void REFRESHotp();
void BURNotp();
void BYPASSotp();
void CHECKSUMotp();

void PADconf(char PAD[], char PADMODE[]);

int READi2c (int paddr, int preg);
void WRITEi2c (int paddr, int preg, int pdata);
unsigned char ModifyBitsInByte(unsigned char byte, unsigned char valuebits, int msb, int lsb);


#endif
