#include <stdio.h>
#include <string.h>

int DECODEsequencerTAI(char TAI[]){
	int TAIcode=99;
	if (strcmp(TAI,"OTPseq")==0){
        printf("//Measure OTP Sequencer State\n");
        TAIcode=0x01;
    }
	else if (strcmp(TAI,"ENcs")==0){
        printf("//Measure ENcs");
		TAIcode=0x02;
    }
	else if (strcmp(TAI,"EN3i")==0){
        printf("//Meaure EN3i\n");
		TAIcode=0x04;
    }
	else if (strcmp(TAI,"EN2i")==0){
        printf("//Measure EN2i\n");
		TAIcode=0x08;
    }
    else if (strcmp(TAI,"ENCi")==0){
        printf("//Measure ENCi\n");
		TAIcode=0x10;
    }
	else if (strcmp(TAI,"ENSi")==0){
        printf("//Measure ENSi\n");
		TAIcode=0x20;
    }
	else if (strcmp(TAI,"ENLi")==0){
        printf("//Measure ENLi\n");
		TAIcode=0x40;
    }
    else if (strcmp(TAI,"ENBCKi")==0){
        printf("//Measure ENBCKi\n");
		TAIcode=0x80;
    }
    else if (strcmp(TAI,"ResetA")==0){
        printf("//Reset SEQUENCER TAOs\n");
		TAIcode=0x00;
    }
	else{
	printf("//%s not found in SERVICE2 Analogue Testmode\n", TAI);
	TAIcode=99;
	}
	return TAIcode;
}
int DECODEsequencerTDI(char TDI[]){
	int TDIcode=99;
	if (strcmp(TDI,"PC216")==0){
        printf("//Measure Bi6 of PC21<7:0>\n");
        TDIcode=0x01;
    }
	else if (strcmp(TDI,"ENCSt")==0){
        printf("//Probe ENCSt\n");
		TDIcode=0x02;
        }
	else if (strcmp(TDI,"EN3t")==0){
        printf("//Probe EN3t\n");
		TDIcode=0x04;
        }
	else if (strcmp(TDI,"EN2t")==0){
        printf("//Probe EN2t\n");
		TDIcode=0x08;
    }
    else if (strcmp(TDI,"ENCt")==0){
        printf("//Probe ENCt\n");
		TDIcode=0x10;
    }
	else if (strcmp(TDI,"ENSt")==0){
        printf("//Probe ENSt\n");
		TDIcode=0x20;
    }
	else if (strcmp(TDI,"ENLy")==0){
        printf("//Probe ENLt\n");
		TDIcode=0x40;
    }
    else if (strcmp(TDI,"ENBCKt")==0){
        printf("//Probe ENBCKt\n");
		TDIcode=0x80;    
    }
    else if (strcmp(TDI,"ResetD")==0){
        printf("//Reset SEQUENCER TDO's\n");
		TDIcode=0x00;
    }
	else{
	printf("//%s not found in SERVICE1 Digital Testmode\n",TDI);
	TDIcode=99;
	}
	return TDIcode;
}
int DECODEsequencerTEN(char TEN[]){
	int TENcode=99;
	if (strcmp(TEN,"Ten0")==0){
        printf("//Enable Global Testmode Outputs\n");
        TENcode=0x01;
    }
	else if (strcmp(TEN,"Ten1")==0){
        printf("//Drive EN2t\n");
		TENcode=0x02;
        }
	else if (strcmp(TEN,"Ten2")==0){
        printf("//Drive ENCSt\n");
		TENcode=0x04;
        }
	else if (strcmp(TEN,"Ten3")==0){
        printf("//Drive EN3t");
		TENcode=0x08;
    }
    else if (strcmp(TEN,"Ten4")==0){
        printf("//Drive ENCt\n");
		TENcode=0x10;
    }
	else if (strcmp(TEN,"Ten5")==0){
        printf("//Drive ENSt \n");
		TENcode=0x20;
    }
	else if (strcmp(TEN,"Ten6")==0){
        printf("//Drive ENLt\n");
		TENcode=0x40;
    }
    else if (strcmp(TEN,"Ten7")==0){
        printf("//Drive ENBCKt\n");
		TENcode=0x80;    
    }
    else if (strcmp(TEN,"ResetT")==0){
        printf("//Reset SEQUENCER TEN's\n");
		TENcode=0x00;
    }
	else{
	printf("//%s not found in SEQUENCER Testmode Enables\n",TEN);
	TENcode=99;
	}
	return TENcode;
	
return 0;
}