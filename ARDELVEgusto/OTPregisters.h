#ifndef __otpregisters_h__
#define __otpregisters_h__

//OTP Registers
#define BANK00 0x00
#define BANK01 0x01
#define BANK02 0x02
#define BANK03 0x03
#define BANK10 0x04
#define BANK11 0x05
#define BANK12 0x06
#define BANK13 0x07
#define BANK20 0x08
#define BANK21 0x09
#define BANK22 0x0A
#define BANK23 0x0B
#define BANK30 0x0C
#define BANK31 0x0D
#define BANK32 0x0E
#define BANK33 0x0F
#define BANK40 0x10
#define BANK41 0x11
#define BANK42 0x12
#define BANK43 0x13
#define BANK50 0x14
#define BANK51 0x15
#define BANK52 0x16
#define BANK53 0x17
#define BANK60 0x18
#define BANK61 0x19
#define BANK62 0x1A
#define BANK63 0x1B
#define BANK70 0x1C
#define BANK71 0x1D
#define BANK72 0x1E
#define BANK73 0x1F

#define OTPconf 0x20
#define OTPcrc 0x21
#define ORPseq 0x22

//Define OTP Commandd
#define OTPRbypass 0x02
#define OTPRreset 0x04
#define OTPRread 0x80
#define OTPRburn 0x10

//#define OTP UNLOCK BYTE
#define OTPlock 0x40

//define OTP Manger Locations
#define VBGmsb 4
#define VBGlsb 0
#define REFmsb 7
#define REFlsb 5

#endif
