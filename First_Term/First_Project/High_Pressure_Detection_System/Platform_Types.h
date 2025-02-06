/*
 *********************************************************
 * @file         : Platform_Types.h
 * @author       : Mina Gamil 
 * @date         : 24 Dec. 2024
 * @brief        : Platform Types Definitions Header File 
 *********************************************************   
*/

#ifndef PLATFORM_TYPES_H_
#define PLATFORM_TYPES_H_

/************** TRUE-FALSE DEFINITION *************/
#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

/************ BOOLEAN DATA TYPE *************/
typedef unsigned char       boolean;

/******************** UNSIGNED DATA TYPES ********************/
typedef unsigned char                  uint8;            // 0..255
typedef unsigned short                 uint16;           // 0..65535
typedef unsigned int                   uint32;           // 0..4294967295
typedef signed long long               uint64;           // 0..18446744073709551615

typedef unsigned char                  uint8_least;      // At least 0..255
typedef unsigned short                 uint16_least;     // At least 0..65535
typedef unsigned int                   uint32_least;     // At least 0..4294967295

typedef volatile unsigned char         vuint8;           // 0..255
typedef volatile unsigned short        vuint16;          // 0..65535
typedef volatile unsigned int          vuint32;          // 0..4294967295
typedef volatile unsigned long long    vuint64;          // 0..18446744073709551615

/******************** SIGNED DATA TYPES ********************/
typedef signed char                    sint8;            // -127..+127
typedef signed short                   sint16;           // -32768..+32767
typedef signed int                     sint32;           // -2147483648..+2147483647
typedef signed long long               sint64;           // -9223372036854775808..+9223372036854775807

typedef signed char                    sint8_least;      // At least -127..+127
typedef signed short                   sint16_least;     // At least -32768..+32767
typedef signed int                     sint32_least;     // At least -2147483648..+2147483647

typedef volatile signed char           vsint8;           // -127..+127
typedef volatile signed short          vsint16;          // -32768..+32767
typedef volatile signed int            vsint32;          // -2147483648..+2147483647
typedef volatile signed long long      vsint64;          // -9223372036854775808..+9223372036854775807

typedef float                          float32;          // -3.4028235e+38..+3.4028235e+38
typedef double                         float64;          // -1.7976931348623157e+308..+1.7976931348623157e+308

typedef volatile float                 vfloat32;         // -3.4028235e+38..+3.4028235e+38
typedef volatile double                vfloat64;         // -1.7976931348623157e+308..+1.7976931348623157e+308

/******************** VOID POINTERS ********************/
typedef void*                          VoidPtr;          // Void Pointer 
typedef const void*                    ConstVoidPtr;     // Contant Void Pointer 


#endif /* PLATFORM_TYPES_H_ */