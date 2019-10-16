/*++

Copyright (C) 2019 Calculation developers

All rights reserved.

This file has been generated by the Automatic Component Toolkit (ACT) version 1.7.0-develop.

Abstract: This is an autogenerated C++-Header file in order to allow an easy
 use of Calculation library

Interface version: 1.0.0

*/

#ifndef __CALCULATION_HEADER_CPP
#define __CALCULATION_HEADER_CPP

#ifdef __CALCULATION_EXPORTS
#ifdef _WIN32
#define CALCULATION_DECLSPEC __declspec (dllexport)
#else // _WIN32
#define CALCULATION_DECLSPEC __attribute__((visibility("default")))
#endif // _WIN32
#else // __CALCULATION_EXPORTS
#define CALCULATION_DECLSPEC
#endif // __CALCULATION_EXPORTS

#include "calculation_types.hpp"

#include "numbers_dynamic.hpp"

extern "C" {

/*************************************************************************************************************************
 Class definition for Base
**************************************************************************************************************************/

/**
* Returns the last error recorded on this object
*
* @param[in] pBase - Base instance.
* @param[in] nErrorMessageBufferSize - size of the buffer (including trailing 0)
* @param[out] pErrorMessageNeededChars - will be filled with the count of the written bytes, or needed buffer size.
* @param[out] pErrorMessageBuffer -  buffer of Message of the last error, may be NULL
* @param[out] pHasError - Is there a last error to query
* @return error code or 0 (success)
*/
CALCULATION_DECLSPEC CalculationResult calculation_base_getlasterror(Calculation_Base pBase, const Calculation_uint32 nErrorMessageBufferSize, Calculation_uint32* pErrorMessageNeededChars, char * pErrorMessageBuffer, bool * pHasError);

/**
* Releases shared ownership of an Instance
*
* @param[in] pBase - Base instance.
* @return error code or 0 (success)
*/
CALCULATION_DECLSPEC CalculationResult calculation_base_releaseinstance(Calculation_Base pBase);

/**
* Acquires shared ownership of an Instance
*
* @param[in] pBase - Base instance.
* @return error code or 0 (success)
*/
CALCULATION_DECLSPEC CalculationResult calculation_base_acquireinstance(Calculation_Base pBase);

/*************************************************************************************************************************
 Class definition for Calculator
**************************************************************************************************************************/

/**
* Adds a Variable to the list of Variables this calculator works on
*
* @param[in] pCalculator - Calculator instance.
* @param[in] pVariable - The new variable in this calculator
* @return error code or 0 (success)
*/
CALCULATION_DECLSPEC CalculationResult calculation_calculator_enlistvariable(Calculation_Calculator pCalculator, Numbers_Variable pVariable);

/**
* Returns an instance of a enlisted variable
*
* @param[in] pCalculator - Calculator instance.
* @param[in] nIndex - The index of the variable to query
* @param[out] pVariable - The Index-th variable in this calculator
* @return error code or 0 (success)
*/
CALCULATION_DECLSPEC CalculationResult calculation_calculator_getenlistedvariable(Calculation_Calculator pCalculator, Calculation_uint32 nIndex, Numbers_Variable * pVariable);

/**
* Clears all variables in enlisted in this calculator
*
* @param[in] pCalculator - Calculator instance.
* @return error code or 0 (success)
*/
CALCULATION_DECLSPEC CalculationResult calculation_calculator_clearvariables(Calculation_Calculator pCalculator);

/**
* Multiplies all enlisted variables
*
* @param[in] pCalculator - Calculator instance.
* @param[out] pInstance - Variable that holds the product of all enlisted Variables
* @return error code or 0 (success)
*/
CALCULATION_DECLSPEC CalculationResult calculation_calculator_multiply(Calculation_Calculator pCalculator, Numbers_Variable * pInstance);

/**
* Sums all enlisted variables
*
* @param[in] pCalculator - Calculator instance.
* @param[out] pInstance - Variable that holds the sum of all enlisted Variables
* @return error code or 0 (success)
*/
CALCULATION_DECLSPEC CalculationResult calculation_calculator_add(Calculation_Calculator pCalculator, Numbers_Variable * pInstance);

/*************************************************************************************************************************
 Global functions
**************************************************************************************************************************/

/**
* Creates a new Calculator instance
*
* @param[out] pInstance - New Calculator instance
* @return error code or 0 (success)
*/
CALCULATION_DECLSPEC CalculationResult calculation_createcalculator(Calculation_Calculator * pInstance);

/**
* retrieves the binary version of this library.
*
* @param[out] pMajor - returns the major version of this library
* @param[out] pMinor - returns the minor version of this library
* @param[out] pMicro - returns the micro version of this library
* @return error code or 0 (success)
*/
CALCULATION_DECLSPEC CalculationResult calculation_getversion(Calculation_uint32 * pMajor, Calculation_uint32 * pMinor, Calculation_uint32 * pMicro);

/**
* Returns the last error recorded on this object
*
* @param[in] pInstance - Instance Handle
* @param[in] nErrorMessageBufferSize - size of the buffer (including trailing 0)
* @param[out] pErrorMessageNeededChars - will be filled with the count of the written bytes, or needed buffer size.
* @param[out] pErrorMessageBuffer -  buffer of Message of the last error, may be NULL
* @param[out] pHasError - Is there a last error to query
* @return error code or 0 (success)
*/
CALCULATION_DECLSPEC CalculationResult calculation_getlasterror(Calculation_Base pInstance, const Calculation_uint32 nErrorMessageBufferSize, Calculation_uint32* pErrorMessageNeededChars, char * pErrorMessageBuffer, bool * pHasError);

/**
* Releases shared ownership of an Instance
*
* @param[in] pInstance - Instance Handle
* @return error code or 0 (success)
*/
CALCULATION_DECLSPEC CalculationResult calculation_releaseinstance(Calculation_Base pInstance);

/**
* Acquires shared ownership of an Instance
*
* @param[in] pInstance - Instance Handle
* @return error code or 0 (success)
*/
CALCULATION_DECLSPEC CalculationResult calculation_acquireinstance(Calculation_Base pInstance);

/**
* Injects an imported component for usage within this component
*
* @param[in] pNameSpace - NameSpace of the injected component
* @param[in] pSymbolAddressMethod - Address of the SymbolAddressMethod of the injected component
* @return error code or 0 (success)
*/
CALCULATION_DECLSPEC CalculationResult calculation_injectcomponent(const char * pNameSpace, Calculation_pvoid pSymbolAddressMethod);

/**
* Returns the address of the SymbolLookupMethod
*
* @param[out] pSymbolLookupMethod - Address of the SymbolAddressMethod
* @return error code or 0 (success)
*/
CALCULATION_DECLSPEC CalculationResult calculation_getsymbollookupmethod(Calculation_pvoid * pSymbolLookupMethod);

}

#endif // __CALCULATION_HEADER_CPP

