/*++

Copyright (C) 2019 Numbers developers

All rights reserved.

This file has been generated by the Automatic Component Toolkit (ACT) version 1.6.0.

Abstract: This is an autogenerated C++-Header file in order to allow an easy
 use of Numbers library

Interface version: 1.0.0

*/

#ifndef __NUMBERS_DYNAMICHEADER_CPPTYPES
#define __NUMBERS_DYNAMICHEADER_CPPTYPES

#include "numbers_types.hpp"



/*************************************************************************************************************************
 Class definition for Base
**************************************************************************************************************************/

/*************************************************************************************************************************
 Class definition for Variable
**************************************************************************************************************************/

/**
* Returns the current value of this Variable
*
* @param[in] pVariable - Variable instance.
* @param[out] pValue - The current value of this Variable
* @return error code or 0 (success)
*/
typedef NumbersResult (*PNumbersVariable_GetValuePtr) (Numbers_Variable pVariable, Numbers_double * pValue);

/**
* Set the numerical value of this Variable
*
* @param[in] pVariable - Variable instance.
* @param[in] dValue - The new value of this Variable
* @return error code or 0 (success)
*/
typedef NumbersResult (*PNumbersVariable_SetValuePtr) (Numbers_Variable pVariable, Numbers_double dValue);

/*************************************************************************************************************************
 Global functions
**************************************************************************************************************************/

/**
* Creates a new Variable instance
*
* @param[in] dInitialValue - Initial value of the new Variable
* @param[out] pInstance - New Variable instance
* @return error code or 0 (success)
*/
typedef NumbersResult (*PNumbersCreateVariablePtr) (Numbers_double dInitialValue, Numbers_Variable * pInstance);

/**
* retrieves the binary version of this library.
*
* @param[out] pMajor - returns the major version of this library
* @param[out] pMinor - returns the minor version of this library
* @param[out] pMicro - returns the micro version of this library
* @return error code or 0 (success)
*/
typedef NumbersResult (*PNumbersGetVersionPtr) (Numbers_uint32 * pMajor, Numbers_uint32 * pMinor, Numbers_uint32 * pMicro);

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
typedef NumbersResult (*PNumbersGetLastErrorPtr) (Numbers_Base pInstance, const Numbers_uint32 nErrorMessageBufferSize, Numbers_uint32* pErrorMessageNeededChars, char * pErrorMessageBuffer, bool * pHasError);

/**
* Releases shared ownership of an Instance
*
* @param[in] pInstance - Instance Handle
* @return error code or 0 (success)
*/
typedef NumbersResult (*PNumbersReleaseInstancePtr) (Numbers_Base pInstance);

/**
* Acquires shared ownership of an Instance
*
* @param[in] pInstance - Instance Handle
* @return error code or 0 (success)
*/
typedef NumbersResult (*PNumbersAcquireInstancePtr) (Numbers_Base pInstance);

/**
* Returns the address of the SymbolLookupMethod
*
* @param[out] pSymbolLookupMethod - Address of the SymbolAddressMethod
* @return error code or 0 (success)
*/
typedef NumbersResult (*PNumbersGetSymbolLookupMethodPtr) (Numbers_pvoid * pSymbolLookupMethod);

/*************************************************************************************************************************
 Function Table Structure
**************************************************************************************************************************/

typedef struct {
	void * m_LibraryHandle;
	PNumbersVariable_GetValuePtr m_Variable_GetValue;
	PNumbersVariable_SetValuePtr m_Variable_SetValue;
	PNumbersCreateVariablePtr m_CreateVariable;
	PNumbersGetVersionPtr m_GetVersion;
	PNumbersGetLastErrorPtr m_GetLastError;
	PNumbersReleaseInstancePtr m_ReleaseInstance;
	PNumbersAcquireInstancePtr m_AcquireInstance;
	PNumbersGetSymbolLookupMethodPtr m_GetSymbolLookupMethod;
} sNumbersDynamicWrapperTable;

#endif // __NUMBERS_DYNAMICHEADER_CPPTYPES

