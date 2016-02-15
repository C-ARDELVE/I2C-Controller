#ifndef __moduleotp_h__
#define __moduleotp_h__

//OTP Testmode Address
#define OTPTadd 0x2C
#define OTPIOadd 0x2D

//Module OTP-TAO
#define BANKCSB0 0x47
#define BANKDATA1 0x46
#define BANKDATA0 0x45
#define CEB1 0x44
#define CEB0 0x43
#define PROG 0x42
#define BURN 0x41
#define RST 0x40
#define OTPallA 0x00

//Module OTP-TDO
#define ENotp 0xB8
#define TDext 0xB0
#define ENvpp 0xA8
#define VPPOKt 0xA0
#define BANKbyp 0x98
#define OTPclk 0x90
#define BANKRSTB 0x88
#define READ 0x80
#define OTPallD 0x00

//Module OTP-Ten
#define OTPtenOFF 0x00
#define OTPten0 0x01
#define OTPten1 0x02
#define OTPten2 0x04
#define OTPten3 0x08
#define OTPten4 0x10
#define OTPten5 0x20
#define OTPten6 0x40
#define OTPten7 0x80

#endif
