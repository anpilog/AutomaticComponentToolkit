/*++

Copyright (C) 2019 Calculator developers

All rights reserved.

This file has been generated by the Automatic Component Toolkit (ACT) version 1.6.0.

Abstract: This is an autogenerated C++-Header file with basic types in
order to allow an easy use of Calculator library

Interface version: 1.0.0

*/

#ifndef __CALCULATOR_TYPES_HEADER_CPP
#define __CALCULATOR_TYPES_HEADER_CPP


/*************************************************************************************************************************
 Scalar types definition
**************************************************************************************************************************/

#ifdef CALCULATOR_USELEGACYINTEGERTYPES

typedef unsigned char Calculator_uint8;
typedef unsigned short Calculator_uint16 ;
typedef unsigned int Calculator_uint32;
typedef unsigned long long Calculator_uint64;
typedef char Calculator_int8;
typedef short Calculator_int16;
typedef int Calculator_int32;
typedef long long Calculator_int64;

#else // CALCULATOR_USELEGACYINTEGERTYPES

#include <stdint.h>

typedef uint8_t Calculator_uint8;
typedef uint16_t Calculator_uint16;
typedef uint32_t Calculator_uint32;
typedef uint64_t Calculator_uint64;
typedef int8_t Calculator_int8;
typedef int16_t Calculator_int16;
typedef int32_t Calculator_int32;
typedef int64_t Calculator_int64 ;

#endif // CALCULATOR_USELEGACYINTEGERTYPES

typedef float Calculator_single;
typedef double Calculator_double;

/*************************************************************************************************************************
 General type definitions
**************************************************************************************************************************/

typedef Calculator_int32 CalculatorResult;
typedef void * CalculatorHandle;
typedef void * Calculator_pvoid;

/*************************************************************************************************************************
 Version for Calculator
**************************************************************************************************************************/

#define CALCULATOR_VERSION_MAJOR 1
#define CALCULATOR_VERSION_MINOR 0
#define CALCULATOR_VERSION_MICRO 0
#define CALCULATOR_VERSION_PRERELEASEINFO ""
#define CALCULATOR_VERSION_BUILDINFO ""

/*************************************************************************************************************************
 Error constants for Calculator
**************************************************************************************************************************/

#define CALCULATOR_SUCCESS 0
#define CALCULATOR_ERROR_NOTIMPLEMENTED 1
#define CALCULATOR_ERROR_INVALIDPARAM 2
#define CALCULATOR_ERROR_INVALIDCAST 3
#define CALCULATOR_ERROR_BUFFERTOOSMALL 4
#define CALCULATOR_ERROR_GENERICEXCEPTION 5
#define CALCULATOR_ERROR_COULDNOTLOADLIBRARY 6
#define CALCULATOR_ERROR_COULDNOTFINDLIBRARYEXPORT 7
#define CALCULATOR_ERROR_INCOMPATIBLEBINARYVERSION 8

/*************************************************************************************************************************
 Declaration of handle classes 
**************************************************************************************************************************/

typedef CalculatorHandle Calculator_Base;
typedef CalculatorHandle Calculator_Variable;
typedef CalculatorHandle Calculator_Calculator;

namespace Calculator {

} // namespace Calculator;

// define legacy C-names for enums, structs and function types

#endif // __CALCULATOR_TYPES_HEADER_CPP
