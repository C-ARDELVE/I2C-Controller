#include <stdio.h>
#include <string.h>

char SERVICE1[]="SERVICE1";

//Module SERVICE1-TAI
char BGt[]="BGt";
char REFIt[]="REFIt";
char IBPt[]="IBPt";
char REFI2t[]="REFI2t";
char REFOt[]="REFOt";
char IBPTt[]="IBPTt";
char REFI3t[]="REFI3t";
char REFt[]="REFt";

//Module SERVICE1-TAI
char BGOK[]="BGOK";
char ENreg[]="ENreg";
char BATTOKt[]="BATTOKt";
char BATTok[]="BATTok";
char VLOKt[]="VLOKt";
char VLOK[]="VLOK";
char PORBt[]="PORBt";
char PORB[]="PORB";




int DECODEservice1TAI(char TAI[]){
	int TAIcode=99;
	if (strcmp(TAI,"BGt")==0){
        printf("//Measure Bandgap-TSWITCH Voltage\n");
        TAIcode=0x01;
    }
	else if (strcmp(TAI,"REFIt")==0){
        printf("//Measure REF_TSWITCH Voltage oot of BGCORE\n");
		TAIcode=0x02;
    }
	else if (strcmp(TAI,"IBPt")==0){
        printf("//Measure Bias Current_TSWITCH\n");
		TAIcode=0x04;
    }
	else if (strcmp(TAI,"REFI2t")==0){
        printf("//Measure REF_TSWITCH at input to BIAS\n");
		TAIcode=0x08;
    }
    else if (strcmp(TAI,"REFOt")==0){
        printf("//Measure REF_TSWITCH at output of BIAS\n");
		TAIcode=0x10;
    }
	else if (strcmp(TAI,"IBPTt")==0){
        printf("//Measure PTAT Bias Current_TSWITCH\n");
		TAIcode=0x20;
    }
	else if (strcmp(TAI,"REFI3t")==0){
        printf("//Measure REF_TSWITCH at input of BUFFER\n");
		TAIcode=0x40;
    }
    else if (strcmp(TAI,"REFt")==0){
        printf("//Measure REF_TSWTCH at output of BUFFER\n");
		TAIcode=0x80;
    }
    else if (strcmp(TAI,"ResetA")==0){
        printf("//Reset SERVICE1 TAOs");
		TAIcode=0x00;
    }
	else{
	printf("//%s not found in SERVICE1 Analogue Testmode\n", TAI);
	TAIcode=99;
	}
	return TAIcode;
}
int DECODEservice1TDI(char TDI[]){
	int TDIcode=99;
	if (strcmp(TDI,"BGOK")==0){
        printf("//Probe Bandgap OK output\n");
        TDIcode=0x01;
    }
	else if (strcmp(TDI,"ENreg")==0){
        printf("//Probe Enable VL Regulator\n");
		TDIcode=0x02;
        }
	else if (strcmp(TDI,"BATTOKt")==0){
        printf("//Probe Enable VL Regulator\n");
		TDIcode=0x04;
        }
	else if (strcmp(TDI,"BATTok")==0){
        printf("//Probe BATT unvervoltage Comparator");
		TDIcode=0x08;
    }
    else if (strcmp(TDI,"VLOKt")==0){
        printf("//Probe VL Regulator UVLO_TSWITCH\n");
		TDIcode=0x10;
    }
	else if (strcmp(TDI,"VLOK")==0){
        printf("//Probe VL Regulator UVLO_TSWITCH\n");
		TDIcode=0x20;
    }
	else if (strcmp(TDI,"PORBt")==0){
        printf("//Probe PORB_TSWITCH\n");
		TDIcode=0x40;
    }
    else if (strcmp(TDI,"PORB")==0){
        printf("//Probe PORB\n");
		TDIcode=0x80;    
    }
    else if (strcmp(TDI,"ResetD")==0){
        printf("//Reset SERVICE1 TDO's\n");
		TDIcode=0x00;
    }
	else{
	printf("//%s not found in SERVICE1 Digital Testmode\n",TDI);
	TDIcode=99;
	}
	return TDIcode;
}
int DECODEservice1TEN(char TEN[]){
	int TENcode=99;
	if (strcmp(TEN,"Ten1")==0){
        printf("//Enable HVUVLO Comparator\n");
        TENcode=0x01;
    }
	else if (strcmp(TEN,"Ten1")==0){
        printf("//Enable BGCORE\n");
		TENcode=0x02;
        }
	else if (strcmp(TEN,"Ten2")==0){
        printf("//Enable BGt Measurement\n");
		TENcode=0x04;
        }
	else if (strcmp(TEN,"Ten3")==0){
        printf("//Enable REFIt Measurement");
		TENcode=0x08;
    }
    else if (strcmp(TEN,"Ten4")==0){
        printf("//Enable IBPt Measurement\n");
		TENcode=0x10;
    }
	else if (strcmp(TEN,"Ten5")==0){
        printf("//Enable REFI2t Measurement\n");
        printf("//Enable REFOt Measurement\n");
		TENcode=0x20;
    }
	else if (strcmp(TEN,"Ten6")==0){
        printf("//Enable IBPt Measurement\n");
		TENcode=0x40;
    }
    else if (strcmp(TEN,"Ten7")==0){
        printf("//Drive REFERENCE Buffer Enable \n");
		TENcode=0x80;    
    }
    else if (strcmp(TEN,"ResetT")==0){
        printf("//Reset SERVICE1 TEN's\n");
		TENcode=0x00;
    }
	else{
	printf("//%s not found in SERVICE2 Testmode Enables\n",TEN);
	TENcode=99;
	}
	return TENcode;
	
return 0;
}