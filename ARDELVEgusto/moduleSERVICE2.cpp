#include <stdio.h>
#include <string.h>

int DECODEservice2TAI(char TAI[]){
	int TAIcode=99;
	if (strcmp(TAI,"VLFBt")==0){
        printf("//Measure Feedback Voltage\n");
        TAIcode=0x01;
    }
	else if (strcmp(TAI,"PORBt")==0){
        printf("//Measure PORB\n");
		TAIcode=0x02;
    }
	else if (strcmp(TAI,"ENuvlo")==0){
        printf("//Meaure BATT UVLO Enable\n");
		TAIcode=0x04;
    }
	else if (strcmp(TAI,"ENBCKt")==0){
        printf("//Measure BUCK Enable\n");
		TAIcode=0x08;
    }
    else if (strcmp(TAI,"SRV2G4")==0){
        printf("//Testmode TAI4 Not Used\n");
		TAIcode=0x10;
    }
	else if (strcmp(TAI,"SRV2GA5")==0){
        printf("//Testmode TAI5 Not Used\n");
		TAIcode=0x20;
    }
	else if (strcmp(TAI,"SRV2GA6")==0){
        printf("//Testmode TAI6 Not Used\n");
		TAIcode=0x40;
    }
    else if (strcmp(TAI,"SRV2GA7")==0){
        printf("//Testmode TAI7 Not Used\n");
		TAIcode=0x80;
    }
    else if (strcmp(TAI,"ResetA")==0){
        printf("//Reset SERVICE2 TAOs\n");
		TAIcode=0x00;
    }
	else{
	printf("//%s not found in SERVICE2 Analogue Testmode\n", TAI);
	TAIcode=99;
	}
	return TAIcode;
}
int DECODEservice2TDI(char TDI[]){
	int TDIcode=99;
	if (strcmp(TDI,"ENBCKi")==0){
        printf("//Probe BUCK Enable\n");
        TDIcode=0x01;
    }
	else if (strcmp(TDI,"ENflt")==0){
        printf("//Probe FAULT Module Enable\n");
		TDIcode=0x02;
        }
	else if (strcmp(TDI,"OKt")==0){
        printf("//Probe REF Buffer UVLO\n");
		TDIcode=0x04;
        }
	else if (strcmp(TDI,"OTPok")==0){
        printf("//Probe OTP OK ");
		TDIcode=0x08;
    }
    else if (strcmp(TDI,"Ten15")==0){
        printf("//Probe Testmode Ten<15>\n");
		TDIcode=0x10;
    }
	else if (strcmp(TDI,"SRV2GD5")==0){
        printf("//Testmode TDi5 Not Used\n");
		TDIcode=0x20;
    }
	else if (strcmp(TDI,"SRV2GD6")==0){
        printf("//Testmode TDi5 Not Used\n");
		TDIcode=0x40;
    }
    else if (strcmp(TDI,"SRV2GD7")==0){
        printf("//Testmode TDi5 Not Used\n");
		TDIcode=0x80;    
    }
    else if (strcmp(TDI,"ResetD")==0){
        printf("//Reset SERVICE2 TDO's\n");
		TDIcode=0x00;
    }
	else{
	printf("//%s not found in SERVICE1 Digital Testmode\n",TDI);
	TDIcode=99;
	}
	return TDIcode;
}
int DECODEservice2TEN(char TEN[]){
	int TENcode=99;
	if (strcmp(TEN,"Ten8")==0){
        printf("//Enable REFt Measurement\n");
        TENcode=0x01;
    }
	else if (strcmp(TEN,"Ten9")==0){
        printf("//Select TAext as REF Buffer Input\n");
		TENcode=0x02;
        }
	else if (strcmp(TEN,"Ten10")==0){
        printf("//Enable REF Buffer Input\n");
		TENcode=0x04;
        }
	else if (strcmp(TEN,"Ten11")==0){
        printf("//Enable VLFBt Measurement");
		TENcode=0x08;
    }
    else if (strcmp(TEN,"Ten12")==0){
        printf("//Enable PORBt Measurement\n");
		TENcode=0x10;
    }
	else if (strcmp(TEN,"Ten13")==0){
        printf("//Drive ENreg \n");
		TENcode=0x20;
    }
	else if (strcmp(TEN,"Ten14")==0){
        printf("//Drive ENuvlo\n");
		TENcode=0x40;
    }
    else if (strcmp(TEN,"Ten15")==0){
        printf("//Enable UVLOflt Meaurement\n");
		TENcode=0x80;    
    }
    else if (strcmp(TEN,"ResetT")==0){
        printf("//Reset SERVICE2 TEN's\n");
		TENcode=0x00;
    }
	else{
	printf("//%s not found in SERVICE2 Testmode Enables\n",TEN);
	TENcode=99;
	}
	return TENcode;
	
return 0;
}