/*++

Copyright (C) 2019 Special Numbers developers

All rights reserved.

This file has been generated by the Automatic Component Toolkit (ACT) version 1.7.0-develop.

Abstract: This is an autogenerated C++-Header file in order to allow an easy
 use of Special Numbers library

Interface version: 1.0.0

*/

#ifndef __SPECIAL_HEADER_CPP
#define __SPECIAL_HEADER_CPP

#ifdef __SPECIAL_EXPORTS
#ifdef _WIN32
#define SPECIAL_DECLSPEC __declspec (dllexport)
#else // _WIN32
#define SPECIAL_DECLSPEC __attribute__((visibility("default")))
#endif // _WIN32
#else // __SPECIAL_EXPORTS
#define SPECIAL_DECLSPEC
#endif // __SPECIAL_EXPORTS

#include "special_types.hpp"

#include "numbers_dynamic.hpp"

extern "C" {

/*************************************************************************************************************************
 Class definition for Base
**************************************************************************************************************************/

/*************************************************************************************************************************
 Class definition for SpecialVariable
**************************************************************************************************************************/

SPECIAL_DECLSPEC SpecialResult numbers_specialvariable_getvalue(SpecialExtendedHandle pVariable, Numbers_double * pValue);
SPECIAL_DECLSPEC SpecialResult numbers_specialvariable_setvalue(SpecialExtendedHandle pVariable, Numbers_double dValue);

/**
* Returns the current value of this Variable as integer. i.e. it rounds
*
* @param[in] pSpecialVariable - SpecialVariable instance.
* @param[out] pValue - The current value of this Variable
* @return error code or 0 (success)
*/
SPECIAL_DECLSPEC SpecialResult special_specialvariable_getspecialvalue(SpecialExtendedHandle pSpecialVariable, Special_int64 * pValue);

/*************************************************************************************************************************
 Global functions
**************************************************************************************************************************/

/**
* Creates a new Variable instance
*
* @param[in] dInitialValue - Initial value of the new SpecialVariable
* @param[out] pInstance - New SpecialVariable instance
* @return error code or 0 (success)
*/
SPECIAL_DECLSPEC SpecialResult special_createspecialvariable(Special_double dInitialValue, SpecialExtendedHandle * pInstance);

/**
* retrieves the binary version of this library.
*
* @param[out] pMajor - returns the major version of this library
* @param[out] pMinor - returns the minor version of this library
* @param[out] pMicro - returns the micro version of this library
* @return error code or 0 (success)
*/
SPECIAL_DECLSPEC SpecialResult special_getversion(Special_uint32 * pMajor, Special_uint32 * pMinor, Special_uint32 * pMicro);

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
SPECIAL_DECLSPEC SpecialResult special_getlasterror(SpecialExtendedHandle pInstance, const Special_uint32 nErrorMessageBufferSize, Special_uint32* pErrorMessageNeededChars, char * pErrorMessageBuffer, bool * pHasError);

/**
* Releases shared ownership of an Instance
*
* @param[in] pInstance - Instance Handle
* @return error code or 0 (success)
*/
SPECIAL_DECLSPEC SpecialResult special_releaseinstance(SpecialExtendedHandle pInstance);

/**
* Acquires shared ownership of an Instance
*
* @param[in] pInstance - Instance Handle
* @return error code or 0 (success)
*/
SPECIAL_DECLSPEC SpecialResult special_acquireinstance(SpecialExtendedHandle pInstance);

/**
* Returns the address of the SymbolLookupMethod
*
* @param[out] pSymbolLookupMethod - Address of the SymbolAddressMethod
* @return error code or 0 (success)
*/
SPECIAL_DECLSPEC SpecialResult special_getsymbollookupmethod(Special_pvoid * pSymbolLookupMethod);

}

#endif // __SPECIAL_HEADER_CPP

