#include <stdio.h>
#include <string.h>
#include "Address.h"

#include "PADconfiguration.h"
#include "OTPregisters.h"
#include "ARDELVEcommands.h"

#include "moduleESD.h"
#include "moduleOUT1.h"
#include "moduleSERVICE1.h"
#include "moduleSERVICE2.h"
#include "moduleQPMP.h"
#include "moduleOUT2.h"
#include "moduleOUT3A.h"
#include "moduleOUT3B.h"
#include "moduleOTP.h"
#include "moduleSEQUENCER.h"
#include "moduleCS.h"
#include "moduleFAULT.h"

//General Commands
int compare(int A, int D){
   return A - D;
}

//I2C Commands
unsigned char ModifyBitsInByte(unsigned char byte, unsigned char valuebits, int msb, int lsb){
	//Old Data, New Data, MSB Bit Position, LSB Bit Position
    int i;
    unsigned char maskmsb = 0x01;
    unsigned char masklsb = 0x00;

    unsigned char finalmask;

    for(i=0;i<msb;i++){
        maskmsb = (maskmsb << 1) | 0x01;
    }
    for(i=0;i<lsb;i++){
        masklsb = (masklsb << 1) | 0x01;
    }
    finalmask = ~(maskmsb ^ masklsb);
    return (byte & finalmask) | (valuebits << lsb);
}
int READi2c (int paddr, int preg){
    int RDi2c=0;
	printf("RDi2c %02X %02X\n",paddr,preg);
    return RDi2c;
}
void WRITEi2c (int paddr, int preg, int pdata){
    int RDold=0x00;
    int TEMPrd;
    RDold = READi2c(paddr,preg);
    printf("Read Old Data...%02X\n",RDold);
    TEMPrd = ModifyBitsInByte(RDold, pdata, 7, 0);
	printf("WRi2c %02X %02X %02X\n",paddr,TEMPrd,pdata);
}

//Instruction Decoder
int DECODEmodule(char MODULE[]){
	int MODcode=99;
	if (strcmp(MODULE,"ESD")==0)
        MODcode=0;
	else if (strcmp(MODULE,"HVREG")==0)
		MODcode=1;
	else if (strcmp(MODULE,"SERVICE1")==0)
		MODcode=2;
	else if (strcmp(MODULE,"SERVICE2")==0)
		MODcode=3;
    else if (strcmp(MODULE,"BUCK")==0)
		MODcode=4;
	else if (strcmp(MODULE,"QPMP")==0)
		MODcode=5;
	else if (strcmp(MODULE,"FAULT")==0)
		MODcode=6;
    	else if (strcmp(MODULE,"OUT2")==0)
		MODcode=7;
	else if (strcmp(MODULE,"OUT31")==0)
		MODcode=8;
	else if (strcmp(MODULE,"OUT32")==0)
		MODcode=9;
    else if (strcmp(MODULE,"LVSW")==0)
		MODcode=10;
	else if (strcmp(MODULE,"RESET")==0)
		MODcode=11;
	else if (strcmp(MODULE,"CS")==0)
		MODcode=12;
    else if (strcmp(MODULE,"BATSNS")==0)
		MODcode=13;
	else if (strcmp(MODULE,"OTP")==0)
		MODcode=14;
	else if (strcmp(MODULE,"SEQUENCER")==0)
		MODcode=15;
	else{
	printf("//Invalid PAD Name %s\n",MODULE);
	MODcode=99;
	}
	return MODcode;
}
void DECODEtao(char MODULE[], char NAME[]){
        int MODcode =99;
        int TAOcode =99;
        MODcode = DECODEmodule(MODULE);
if (MODcode==0){
		printf("//Write ESD TAO:%02X\n",TAOcode);
//		WRITEi2c(I2CtestW,ESDIOadd,TAOcode);
		}
else if (MODcode==1){
		printf("//Write OUT1 TAO:%02X\n",TAOcode);
//		WRITEi2c(I2CtestW,OUT1IOadd,TAOcode);
		}
 if (MODcode==2){
        TAOcode = DECODEservice1TAI(NAME);
		printf("//Write SERVICE1 TAO:%02X\n",TAOcode);
		WRITEi2c(I2CtestW,SERVICE1IOadd,TAOcode);
		}
else if (MODcode==3){
		printf("//Write SERVICE2 TAO:%02X\n",TAOcode);
//		WRITEi2c(I2CtestW,SERVICE2IOadd,TAOcode);
		}
else if (MODcode==5){
		printf("//Write QPMP TAO:%02X\n",TAOcode);
//		WRITEi2c(I2CtestW,QPMPIOadd,TAOcode);
		}  
else if (MODcode==6){
//		printf("//Write FAULT TAO:%02X\n",TAOcode);
		WRITEi2c(I2CtestW,FAULTIOadd,TAOcode);
		} 
else if (MODcode==7){
//		printf("//Write OUT2 TAO:%02X\n",TAOcode);
		WRITEi2c(I2CtestW,OUT2IOadd,TAOcode);
		} 
else if (MODcode==8){
		printf("//Write OUT3A TAO:%02X\n",TAOcode);
//		WRITEi2c(I2CtestW,OUT3AIOadd,TAOcode);
		} 
else if (MODcode==9){
		printf("//Write OUT3B TAO:%02X\n",TAOcode);
//		WRITEi2c(I2CtestW,OUT3BIOadd,TAOcode);
		}   
else if (MODcode==12){
		printf("//Write CS TAO:%02X\n",TAOcode);
//		WRITEi2c(I2CtestW,CSIOadd,TAOcode);
		}             
else if (MODcode==14){
		printf("//Write OTP TAO:%02X\n",TAOcode);
//		WRITEi2c(I2CtestW,OTPIOadd,TAOcode);
		}
else if (MODcode==15){
		printf("//Write SEQUENCER TAO: %02X\n",TAOcode);
//		WRITEi2c(I2CtestW,SEQUENCERIOadd,TAOcode);
		}
else{
	printf("//Invalid Write TA0 Command\n");
    MODcode=99;
    }
}
void DECODEtdo(char MODULE[], char NAME[]){
    int MODcode =99;
    int TDOcode =99;
    MODcode = DECODEmodule(MODULE);
if (MODcode==0){
		printf("Write ESD TDO:%02X\n",TDOcode);
//		WRITEi2c(I2CtestW,ESDIOadd,NAMEcode);
		}
else if (MODcode==1){
		printf("Write OUT1 TDO:%02X\n",TDOcode);
//		WRITEi2c(I2CtestW,OUT1IOadd,NAMEcode);
		}
else if (MODcode==2){
        TDOcode = DECODEservice1TDI(NAME);
		printf("Write SERVICE1 TDO:%02X\n",TDOcode);
		WRITEi2c(I2CtestW,SERVICE1IOadd,TDOcode);
		}
else if (MODcode==3){
		printf("Write SERVICE2 TDO:%02X\n",TDOcode);
//		WRITEi2c(I2CtestW,SERVICE2IOadd,TDOcode);
		}  
else if (MODcode==5){
		printf("Write QPMP TDO:%02X",TDOcode);
//		WRITEi2c(I2CtestW,QPMPIOadd,TDOcode);
		} 
else if (MODcode==6){
		printf("Write FAULT TDO:%02X\n",TDOcode);
//		WRITEi2c(I2CtestW,FAULTIOadd,TDOcode);
		}  
else if (MODcode==7){
		printf("Write OUT2 TDO:%02X\n",TDOcode);
//		WRITEi2c(I2CtestW,OUT2IOadd,TDOcode);
		} 
else if (MODcode==8){
		printf("Write OUT3A TDO:%02X",TDOcode);
//		WRITEi2c(I2CtestW,OUT3AIOadd,TDOcode);
		} 
else if (MODcode==9){
		printf("Write OUT3B TDO:%02X\n",TDOcode);
//		WRITEi2c(I2CtestW,OUT3BIOadd,TDOcode);
		}  
else if (MODcode==12){
		printf("Write CS TDO:%02X\n",TDOcode);
//		WRITEi2c(I2CtestW,CSIOadd,TDOcode);
		}  
else if (MODcode==14){
		printf("Write OTP TDO:%02X\n",TDOcode);
//		WRITEi2c(I2CtestW,OTPIOadd,TDOcode);
		}
else if (MODcode==15){
		printf("Write SEQUENCER TDO: %02X\n",TDOcode);
//		WRITEi2c(I2CtestW,SEQUENCERIOadd,TDOcode);
		}
else
	printf("Invalid Write TD0 Command");
}
int DECODEprobe(char MODULE[], char NAME[]){
    int MODcode=99;
    int PROBEcode=99;
    int PROBEcodeA=99;
    int PROBEcodeD=99;
    //Find MODULE NUMBER
    MODcode = DECODEmodule(MODULE);
    printf("//Module decoded to=%d\n", MODcode);
    //FIND PROBE NUMBER
    if (MODcode==0){
	//PROBEcodeA = DECODEesdTAI(NAME);
    if (PROBEcodeA==99){
    //PROBEcodeD=DECODEesdTDI(NAME);
    }
    }
	else if (MODcode==1){
	//PROBEcodeA = DECODEout1TAI(NAME);
    if (PROBEcodeA==99){
    //PROBEcodeD=DECODEout1TDI(NAME);
    }
	int Calc = compare(PROBEcodeA,PROBEcodeD);
	if (Calc==0)
		PROBEcode = PROBEcodeA;
	if (Calc==1)
			PROBEcode = PROBEcodeD;
	printf("//Probe Name Decoded to=%d/n",PROBEcode);
    }
	else if (MODcode==2){
	PROBEcodeA = DECODEservice1TAI(NAME);
    if (PROBEcodeA==99){
    PROBEcodeD=DECODEservice1TDI(NAME);
    }
	int Calc = compare(PROBEcodeA,PROBEcodeD);
	if (Calc==0)
		PROBEcode = PROBEcodeA;
	if (Calc==1)
			PROBEcode = PROBEcodeD;
	printf("//Probe Name Decoded to=%d/n",PROBEcode);
	}
    else if (MODcode==3){
	//PROBEcodeA = DECODEservice2TAI(NAME);
    if (PROBEcodeA==99){
    //PROBEcodeD=DECODEservice2TDI(NAME);
    }
	int Calc = compare(PROBEcodeA,PROBEcodeD);
	if (Calc==0)
		PROBEcode = PROBEcodeA;
	if (Calc==1)
			PROBEcode = PROBEcodeD;
	printf("//Probe Name Decoded to=%d/n",PROBEcode);
    }
    else if (MODcode==5){
	//PROBEcodeA = DECODEqpmpTAI(NAME);
    if (PROBEcodeA==99){
    //PROBEcodeD=DECODEqpmpTDI(NAME);
    }
	int Calc = compare(PROBEcodeA,PROBEcodeD);
	if (Calc==0)
		PROBEcode = PROBEcodeA;
	if (Calc==1)
			PROBEcode = PROBEcodeD;
	printf("//Probe Name Decoded to=%d/n",PROBEcode);
    }
    else if (MODcode==6){
	//PROBEcodeA = DECODEfaultTAI(NAME);
    if (PROBEcodeA==99){
    //PROBEcodeD=DECODEfaultTDI(NAME);
    }
	int Calc = compare(PROBEcodeA,PROBEcodeD);
	if (Calc==0)
		PROBEcode = PROBEcodeA;
	if (Calc==1)
			PROBEcode = PROBEcodeD;
	printf("//Probe Name Decoded to=%d/n",PROBEcode);
    }
    else if (MODcode==7){
	//PROBEcodeA = DECODEout2TAI(NAME);
    if (PROBEcodeA==99){
    //PROBEcodeD=DECODEservice1TDI(NAME);
    }
	int Calc = compare(PROBEcodeA,PROBEcodeD);
	if (Calc==0)
		PROBEcode = PROBEcodeA;
	if (Calc==1)
			PROBEcode = PROBEcodeD;
	printf("//Probe Name Decoded to=%d/n",PROBEcode);
    }
    else if (MODcode==8){
	//PROBEcodeA = DECODEout3ATAI(NAME);
    if (PROBEcodeA==99){
    //PROBEcodeD=DECODEout3ATDI(NAME);
    }
	int Calc = compare(PROBEcodeA,PROBEcodeD);
	if (Calc==0)
		PROBEcode = PROBEcodeA;
	if (Calc==1)
			PROBEcode = PROBEcodeD;
	printf("//Probe Name Decoded to=%d/n",PROBEcode);
    }
    else if (MODcode==9){
	//PROBEcodeA = DECODEout3BTAI(NAME);
    if (PROBEcodeA==99){
    //PROBEcodeD=DECODEout3BTDI(NAME);
    }
	int Calc = compare(PROBEcodeA,PROBEcodeD);
	if (Calc==0)
		PROBEcode = PROBEcodeA;
	if (Calc==1)
			PROBEcode = PROBEcodeD;
	printf("//Probe Name Decoded to=%d/n",PROBEcode);
    }
    else if (MODcode==10){
	//PROBEcodeA = DECODElvswTAI(NAME);
    if (PROBEcodeA==99){
    //PROBEcodeD=DECODElvswTDI(NAME);
    }
	int Calc = compare(PROBEcodeA,PROBEcodeD);
	if (Calc==0)
		PROBEcode = PROBEcodeA;
	if (Calc==1)
			PROBEcode = PROBEcodeD;
	printf("//Probe Name Decoded to=%d/n",PROBEcode);
    }
    else if (MODcode==11){
	//PROBEcodeA = DECODEresetTAI(NAME);
    if (PROBEcodeA==99){
    //PROBEcodeD=DECODEresetTDI(NAME);
    }
	int Calc = compare(PROBEcodeA,PROBEcodeD);
	if (Calc==0)
		PROBEcode = PROBEcodeA;
	if (Calc==1)
			PROBEcode = PROBEcodeD;
	printf("//Probe Name Decoded to=%d/n",PROBEcode);
    }
    else if (MODcode==12){
	//PROBEcodeA = DECODEcsTAI(NAME);
	if (PROBEcodeA==99){
    //PROBEcodeD=DECODEcsTDI(NAME);
    }
	int Calc = compare(PROBEcodeA,PROBEcodeD);
	if (Calc==0)
		PROBEcode = PROBEcodeA;
	if (Calc==1)
			PROBEcode = PROBEcodeD;
	printf("//Probe Name Decoded to=%d/n",PROBEcode);
    }
    else if (MODcode==13){
	//PROBEcodeA = DECODEbatsnsTAI(NAME);
    if (PROBEcodeA==99){
    //PROBEcodeD=DECODEbatsnsTDI(NAME);
    }
	int Calc = compare(PROBEcodeA,PROBEcodeD);
	if (Calc==0)
		PROBEcode = PROBEcodeA;
	if (Calc==1)
			PROBEcode = PROBEcodeD;
	printf("//Probe Name Decoded to=%d/n",PROBEcode);
    }
    else if (MODcode==14){
	//PROBEcodeA = DECODEotpTAI(NAME);
    if (PROBEcodeA==99){
    //PROBEcodeD=DECODEotpTDI(NAME);
    }
	int Calc = compare(PROBEcodeA,PROBEcodeD);
	if (Calc==0)
		PROBEcode = PROBEcodeA;
	if (Calc==1)
			PROBEcode = PROBEcodeD;
	printf("//Probe Name Decoded to=%d/n",PROBEcode);
    }
    else if (MODcode==15){
	//PROBEcodeA = DECODEsequencerTAI(NAME);
    if (PROBEcodeA==99){
    //PROBEcodeD=DECODEsequencerTDI(NAME);
    }
	int Calc = compare(PROBEcodeA,PROBEcodeD);
	if (Calc==0)
		PROBEcode = PROBEcodeA;
	if (Calc==1)
			PROBEcode = PROBEcodeD;
	printf("//Probe Name Decoded to=%d/n",PROBEcode);
    }
    else{
    printf("//Error in Module Name %s\n", MODULE);  
	}
	return 0;
}
int DECODEten(char NAME[]){
	int TENcode=99;
	if (strcmp(NAME,"Ten0")==0)
		TENcode=0x01;
	else if (strcmp(NAME,"Ten1")==0)
		TENcode=0x02;
	else if (strcmp(NAME,"Ten2")==0)
		TENcode=0x04;
	else if (strcmp(NAME,"Ten3")==0)
		TENcode=0x08;
	else if (strcmp(NAME,"Ten4")==0)
		TENcode=0x10;
	else if (strcmp(NAME,"Ten5")==0)
		TENcode=0x20;
	else if (strcmp(NAME,"Ten6")==0)
		TENcode=0x40;
	else if (strcmp(NAME,"Ten7")==0)
		TENcode=0x80;
	else{
		TENcode=99;
	printf("//InValid Ten Code %s\n",NAME);
	}
	return TENcode;
}
int DECODEtestpad(char PAD[]){
	int TESTPADcode=0;
	if (strcmp(PAD,"ENC")==0)
	TESTPADcode=1;
	else if (strcmp(PAD,"EN3")==0)
		TESTPADcode=2;
	else if (strcmp(PAD,"EN2")==0)
		TESTPADcode=3;
	else if (strcmp(PAD,"ENBCK")==0)
		TESTPADcode=4;
	else{
	printf("//Invalid PAD Name\n");
	TESTPADcode=0;
	}
	return TESTPADcode;
}


//TestMode Commands
void TEN(char MODULE[], char NAME[]){
    int MODcode=99;
    int TENcode=99;
    int OFFSET = TENcode+8; 
    MODcode = DECODEmodule(MODULE);
    printf("//Module= %d\n", MODcode);
	TENcode = DECODEten(NAME);
if (MODcode==0){
		printf("//Write ESD Ten:%02X\n",TENcode);
		WRITEi2c(I2CtestW,ESDTadd,TENcode);
		}
else if (MODcode==1){;
		printf("//Write OUT1 Ten:%02X\n",TENcode);
		WRITEi2c(I2CtestW,OUT1Tadd,TENcode);
		}
else if (MODcode==2){
        TENcode = DECODEservice1TEN(NAME);
		printf("//Write SERVICE1 Ten:0x%02X\n",TENcode);
		WRITEi2c(I2CtestW,SERVICE1Tadd,TENcode);
		}
else if (MODcode==3){
		printf("//Write SERVICE2 Ten:%02X\n",TENcode);
		WRITEi2c(I2CtestW,SERVICE2Tadd,TENcode);
		}
else if (MODcode==5){
		printf("//Write QPMP Ten:%02X\n",TENcode);
		WRITEi2c(I2CtestW,QPMPTadd,TENcode);
		}
else if (MODcode==6){
		printf("//Write FAULT Ten:%02X\n",TENcode);
		WRITEi2c(I2CtestW,FAULTTadd,TENcode);
		}
else if (MODcode==7){
		printf("//Write OUT2 Ten:%02X\n",TENcode);
		WRITEi2c(I2CtestW,OUT2Tadd,TENcode);
		}
else if (MODcode==8){
		printf("//Write OUT3 Ten:%02X\n",TENcode);
		WRITEi2c(I2CtestW,OUT3ATadd,TENcode);
		}
else if (MODcode==9){
		printf("//Write OUT3 Ten:%02X\n",OFFSET);
		WRITEi2c(I2CtestW,OUT3BTadd,TENcode);
		}
else if (MODcode==12){
		printf("//Write CS Ten:%02X\n",TENcode);
		WRITEi2c(I2CtestW,CSTadd,TENcode);
		}
else if (MODcode==14){
		printf("//Write OTP Ten:%02X\n",TENcode);
		WRITEi2c(I2CtestW,OTPTadd,TENcode);
		}
else if (MODcode==15){
		printf("//Write SEQUENCER Ten: %02X\n",TENcode);
		WRITEi2c(I2CtestW,SEQUENCERTadd,TENcode);
		}
else
	printf("//Invalid Attemp to write Ten:%02X\n",TENcode);
}


//OTP Commands
void READallOTP(){
	READi2c(I2CotpR, BANK00); 
	READi2c(I2CotpR, BANK01);
	READi2c(I2CotpR, BANK02);
	READi2c(I2CotpR, BANK03);
	READi2c(I2CotpR, BANK10);
	READi2c(I2CotpR, BANK11);
	READi2c(I2CotpR, BANK12);
	READi2c(I2CotpR, BANK13);
	READi2c(I2CotpR, BANK20);
	READi2c(I2CotpR, BANK21);
	READi2c(I2CotpR, BANK22);
	READi2c(I2CotpR, BANK23);
	READi2c(I2CotpR, BANK30);
	READi2c(I2CotpR, BANK31);
	READi2c(I2CotpR, BANK32);
	READi2c(I2CotpR, BANK33);
}
int READotp(int cmd){
	int RDotp=0;
	printf("//Read OTP BANK%02X\n",cmd);
	READi2c(I2CotpR, cmd);
	return RDotp;
}
void RESETallOTP(){
	printf("//Write OTPconf RESET......\n");
	WRITEi2c(I2CotpR, OTPconf, OTPRreset);
}
void WRITEotp(int BANK, int OTPdata){
	WRITEi2c(I2CotpW, BANK, OTPdata);
}
void REFRESHotp(){
	printf("//Read OTP from Flash......\n");
	WRITEi2c(I2CotpR, OTPconf, OTPRread);
}
void BURNotp(){
	printf("//Start Burn OTP Sequence......\n");
	WRITEi2c(I2CotpR, OTPconf, OTPRburn);
}
void BYPASSotp(){
	printf("//BYPASS OTP......\n");
	WRITEi2c(I2CotpR, OTPconf, OTPRbypass);
}
void CHECKSUMotp(){
	printf("//CHECKSUM OTP......\n");
	READi2c(I2CotpR, OTPcrc);
}

//PAD Commands
int DECODEtestINPUT(char TESTINPUT[]){
	int TESTINPUTcode=99;
	if (strcmp(TESTINPUT,"TDext")==0)
	TESTINPUTcode=13;
    else if (strcmp(TESTINPUT,"TAext")==0)
    TESTINPUTcode=12;
	else{
	printf("//Invalid PAD Test Input Name %s\n",TESTINPUT);
	TESTINPUTcode=99;
	}
	return TESTINPUTcode;
}
int DECODEpadmode(char PADMODE[]){
	int TESTPADMODEcode=99;
	if (strcmp(PADMODE,"DIGOUT0")==0)
	TESTPADMODEcode=1;
    else if (strcmp(PADMODE,"DIGOUT1")==0)
    TESTPADMODEcode=2;
    if (strcmp(PADMODE,"ANAOUT0")==0)
	TESTPADMODEcode=3;
    else if (strcmp(PADMODE,"ANAOUT1")==0)
    TESTPADMODEcode=4;
    if (strcmp(PADMODE,"TESTDIN")==0)
	TESTPADMODEcode=5;
    else if (strcmp(PADMODE,"TESTAIN")==0)
    TESTPADMODEcode=6;
	else{
	printf("//Invalid PAD Mode Selected\n");
	TESTPADMODEcode=99;
	}
	return TESTPADMODEcode;
}
void PADconf(char PAD[], char PADMODE[]){
    int TESTPADcode=99;
    int TESTPADMODEcode=99;
    printf("//Decode PAD\n");
    TESTPADcode = DECODEtestpad(PAD);
    printf("//PAD= %d\n", TESTPADcode);
	if (TESTPADcode==1){
	if (TESTPADMODEcode==1){
        printf("//Set ENC to Digital In\n");
		WRITEi2c(I2CtestW, ENCcmd,GPIOoD);
		printf("//Set ENC to TDO<0>\n");
		WRITEi2c(I2CtestW, addPADoSELd,PADtdo0G1);
		}
	else if (TESTPADMODEcode==2){
        printf("//Set ENC to Digital In\n");
		WRITEi2c(I2CtestW, ENCcmd,GPIOoD);
		printf("//Set ENC to TDO<1>\n");
		WRITEi2c(I2CtestW, addPADoSELd,PADtdo1G1);
		}
	else if (TESTPADMODEcode==3){
        printf("//Set ENC to Analogue\n");
		WRITEi2c(I2CtestW, ENCcmd,GPIOoA);
		printf("//Set ENC to TAO<0>\n");
		WRITEi2c(I2CtestW, addPADoSELa,PADtao0G1);
		}
	else if (TESTPADMODEcode==4){
        printf("//Set ENC to Analogue Out\n");
		WRITEi2c(I2CtestW, ENCcmd,GPIOoA);
		printf("//Set ENC to TAO<1>\n");
		WRITEi2c(I2CtestW, addPADoSELa,PADtao1G1);
		}
	else if (TESTPADMODEcode==5){
        printf("//Set ENC to Digital In\n");
		WRITEi2c(I2CtestW, ENCcmd,GPIOiD);
		printf("//Set ENC to TDext\n");
		WRITEi2c(I2CtestW, addPADiSELt,PADitd1);
		}
	else if (TESTPADMODEcode==6){
        printf("//Set ENC to Analogue In\n");
		WRITEi2c(I2CtestW, ENCcmd,GPIOiA);
		printf("//Set ENC to TAext\n");
		WRITEi2c(I2CtestW, addPADiSELt,PADita1);
		}
    else{
            printf("//Error in Setting PAD Mode\n");
        }
	}
	if (TESTPADcode==2){
	if (TESTPADMODEcode==1){
        printf("//Set EN3 to Digital Out\n");
		WRITEi2c(I2CtestW, EN3cmd,GPIOoD);
		printf("//Set EN3 to measure TDO<0>\n");
		WRITEi2c(I2CtestW, addPADoSELd,PADtdo0G2);
		}
	else if (TESTPADMODEcode==2){
        printf("//Set EN3 to Digital Out\n");
		WRITEi2c(I2CtestW, EN3cmd,GPIOoD);
		printf("//Set EN3 to TDO<1>\n");
		WRITEi2c(I2CtestW, addPADoSELd,PADtdo1G2);
	}
	else if (TESTPADMODEcode==3){
        printf("//Set EN3 to Analogue Output\n");
		WRITEi2c(I2CtestW, EN3cmd,GPIOoA);
		printf("//Set EN3 to TAO<0>\n");
		WRITEi2c(I2CtestW, addPADoSELa,PADtao0G2);
		}
	else if (TESTPADMODEcode==4){
        printf("//Set EN3 to Analogue Output\n");
		WRITEi2c(I2CtestW, EN3cmd, GPIOoA);
        printf("Set EN3 to TAO<1>\n");
		WRITEi2c(I2CtestW, addPADoSELa,PADtao1G2);
		}
	else if (TESTPADMODEcode==5){
        printf("//Set EN3 to Digital Input\n");
		WRITEi2c(I2CtestW, EN3cmd,GPIOiD);
		printf("//Set EN3 to TDext\n");
		WRITEi2c(I2CtestW, addPADiSELt,PADitd2);
		}
	else if (TESTPADMODEcode==6){
        printf("//Set EN3 to Analogue Input\n");
		WRITEi2c(I2CtestW, EN3cmd,GPIOiA);
		printf("//Set EN3 to TAext\n");
		WRITEi2c(I2CtestW, addPADiSELt,PADita2);
		}
    else{
            printf("//Error in PAD setting\n");
        }
	}
	if (TESTPADcode==3){
	if (TESTPADMODEcode==1){
        printf("//Set EN2 to Digital Out\n");
		WRITEi2c(I2CtestW, EN2cmd,GPIOoD);
		printf("//Set EN2 to TDO<0>\n");
		WRITEi2c(I2CtestW, addPADoSELd,PADtdo0G3);
		}
	else if (TESTPADMODEcode==2){
        printf("//Set EN2 to Digital Out\n");
		WRITEi2c(I2CtestW, EN2cmd,GPIOoD);
		printf("//Set EN2 to TDO<1>\n");
		WRITEi2c(I2CtestW, addPADoSELd,PADtdo1G3);
	}
	else if (TESTPADMODEcode==3){
        printf("//Set EN2 to Analogue Input\n");
		WRITEi2c(I2CtestW, EN2cmd,GPIOiA);
		printf("//Set EN2 to TAO<0>\n");
		WRITEi2c(I2CtestW, addPADoSELa,PADtao0G3);
		}
	else if (TESTPADMODEcode==4){
        printf("//Set EN2 to Analogue Input\n");
		WRITEi2c(I2CtestW, EN2cmd,GPIOiA);
		printf("//Set EN2 to TAO<1>\n");
		WRITEi2c(I2CtestW, addPADoSELa,PADtao1G3);
		}
	else if (TESTPADMODEcode==5){
        printf("//Set EN2 to Digital Input");
		WRITEi2c(I2CtestW, EN2cmd,GPIOiD);
		printf("//Set EN2 to TDext\n");
		WRITEi2c(I2CtestW, addPADiSELt,PADitd3);
		}
	else if (TESTPADMODEcode==6){
        printf("//Set EN2 to Analogue Input\n");
		WRITEi2c(I2CtestW, EN2cmd,GPIOiA);
		printf("//Set EN2 to TAext\n");
		WRITEi2c(I2CtestW, addPADiSELt,PADita3);
		}
    else{
            printf("//Error in PAD setting\n");
        }
	}
	if (TESTPADcode==4){
	if (TESTPADMODEcode==1){
        printf("//Set ENBCK to Digital Out\n");
		WRITEi2c(I2CtestW, ENBCKcmd,GPIOoD);
		printf("//Set ENBCK to TDO<0>\n");
		WRITEi2c(I2CtestW, addPADoSELd,PADtdo0G4);
		}
	else if (TESTPADMODEcode==2){
        printf("//Set ENBCK to Digital Out\n");
		WRITEi2c(I2CtestW, ENBCKcmd,GPIOoD);
		printf("//Set ENBCK to TDO<1>\n");
		WRITEi2c(I2CtestW, addPADoSELd,PADtdo1G4);
	}
	else if (TESTPADMODEcode==3){
		printf("//Set ENBCK to Analogue Output\n");
		WRITEi2c(I2CtestW, ENBCKcmd,GPIOoA);
        printf("//Set ENBCK to TAO<0>\n");
		WRITEi2c(I2CtestW, addPADoSELa,PADtao0G4);
		}
	else if (TESTPADMODEcode==4){
		printf("//Set ENBCK to Analogue Output\n");
		WRITEi2c(I2CtestW, ENBCKcmd,GPIOoA);
        printf("//Set ENBCK to TAO<1>\n");
		WRITEi2c(I2CtestW, addPADoSELa,PADtao1G4);
		}
	else if (TESTPADMODEcode==5){
        printf("//Set ENBCK to Digital Input\n");
		WRITEi2c(I2CtestW, ENBCKcmd,GPIOiD);
		printf("//Set ENBCK to TDext\n");
		WRITEi2c(I2CtestW, addPADiSELt,PADitd4);
		}
	else if (TESTPADMODEcode==6){
        printf("//Set ENBCK to Analogue Input\n");
		WRITEi2c(I2CtestW, ENBCKcmd,GPIOiA);
		printf("//Set ENBCK to TAext\n");
		WRITEi2c(I2CtestW, addPADiSELt,PADita4);
		}
    else{
            printf("//Error in PAD CONFIGURATION setting\n");
        }
    }
    else{
            printf("//Error in PAD Setting\n");
        }
}


//Global MK7013 Commands
void PASSWORD(){
	printf("//Set Password0......\n");
	WRITEi2c(I2CtestW, CMDpswd0, Password0);
	printf("//Set Password1......\n");
	WRITEi2c(I2CtestW, CMDpswd1, Password1);
}
void LOCK(){
	printf("//Set OTP Bypass......");
	WRITEi2c(I2CotpW, OTPconf, OTPRbypass);
	printf("//Write OTP LOCK......");
	WRITEi2c(I2CotpW, BANK10, 0x40);
}
void STARTUP(){
	printf("//Start Up Sequence\n");
	PASSWORD();
    printf("//End Start Up Sequence\n");
}
void RESETall(){
	printf("//Reseting all PAD and TM Configurations\n");
	WRITEi2c(I2CtestW, addPADconf, RESETboth);
}
void RESETtestmode(){
	printf("//Reseting all TM* Configurations......\n");
	WRITEi2c(I2CtestW, addPADconf, RESETtest);
}
void RESETpads(){
	printf("//Resetinf PAD Configuration\n");
	WRITEi2c(I2CtestW, addPADconf, RESETpad);
}




//MK7013 COMMANDS
void PROBEwithINPUT(char MODULE[],char NAME[],char PADo[],char TESTINPUT[],char PADi[]){
	int MODcode=99;
    int PROBEcode=99;
    int PADOcode=0;
    int TESTINPUTcode=0;
    int PADIcode=0;
    
    //FInd MODULE NUMBER
    MODcode = DECODEmodule(MODULE);
    printf("//Module decoded to=%d\n", MODcode);
    
    //Find PROBE NUMBER
    PROBEcode = DECODEprobe(MODULE,NAME);
    printf("//Probe decoded to=%d\n", PROBEcode);
    
    //FIND PROBE OUTPUT PAD CONFIGURATION
    PADOcode = DECODEtestpad(PADo);
    printf("//Output PAD=%d\n", PADOcode);
    
    //FIND TEST I/O PAD
	PADIcode = DECODEtestpad(PADi);
    printf("//Input PAD=%d\n", PADIcode);
    
    //FIND TESTMODE I/O CODE
    TESTINPUTcode = DECODEtestINPUT(TESTINPUT);
    printf("//Test Input=%d\n", TESTINPUTcode);
    
    
    
    
    
    
    //NAMEcode = DECODEana(NAME);
    //printf("//======Enable testmodes==================");
    //void ENABLEtestmode();
    //printf("//==========Apply TAext on PAD %s\n", PADi);
    //PADconf(PADIcode,INPUTcode);
    
	//printf("//==========Measure UVLO on PAD %s\n",PADo);
    //PROBEt(7,7);
	//PROBEd0(12, 0, PADOcode);
    //printf("//==========Apply TAext on PAD %s\n", PADi);
    //PROBEa0(7,0,PADIcode);
    //printf("//Ramp TAext and Measure UVLO on PAD: %s\n",PADo);
	//TENclear(15);
    //TDOclear(12);
	//printf("//==========End CS Sequence==========\n");
//	printf("\n");
}