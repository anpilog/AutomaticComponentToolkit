/*++

Copyright (C) 2019 Calculation developers

All rights reserved.

This file has been generated by the Automatic Component Toolkit (ACT) version 1.6.0.

Abstract: This is an autogenerated C++-Header file in order to allow an easy
 use of Calculation library

Interface version: 1.0.0

*/

#ifndef __CALCULATION_CPPHEADER_DYNAMIC_CPP
#define __CALCULATION_CPPHEADER_DYNAMIC_CPP

#include "calculation_types.hpp"
#include "calculation_dynamic.h"

#include "numbers_dynamic.hpp"

#ifdef _WIN32
#include <windows.h>
#else // _WIN32
#include <dlfcn.h>
#endif // _WIN32
#include <string>
#include <memory>
#include <vector>
#include <exception>

namespace Calculation {

/*************************************************************************************************************************
 Forward Declaration of all classes
**************************************************************************************************************************/
class CWrapper;
class CBase;
class CCalculator;

/*************************************************************************************************************************
 Declaration of deprecated class types
**************************************************************************************************************************/
typedef CWrapper CCalculationWrapper;
typedef CBase CCalculationBase;
typedef CCalculator CCalculationCalculator;

/*************************************************************************************************************************
 Declaration of shared pointer types
**************************************************************************************************************************/
typedef std::shared_ptr<CWrapper> PWrapper;
typedef std::shared_ptr<CBase> PBase;
typedef std::shared_ptr<CCalculator> PCalculator;

/*************************************************************************************************************************
 Declaration of deprecated shared pointer types
**************************************************************************************************************************/
typedef PWrapper PCalculationWrapper;
typedef PBase PCalculationBase;
typedef PCalculator PCalculationCalculator;


/*************************************************************************************************************************
 Class ECalculationException 
**************************************************************************************************************************/
class ECalculationException : public std::exception {
protected:
	/**
	* Error code for the Exception.
	*/
	CalculationResult m_errorCode;
	/**
	* Error message for the Exception.
	*/
	std::string m_errorMessage;

public:
	/**
	* Exception Constructor.
	*/
	ECalculationException(CalculationResult errorCode, const std::string & sErrorMessage)
		: m_errorMessage("Calculation Error " + std::to_string(errorCode) + " (" + sErrorMessage + ")")
	{
		m_errorCode = errorCode;
	}

	/**
	* Returns error code
	*/
	CalculationResult getErrorCode() const noexcept
	{
		return m_errorCode;
	}

	/**
	* Returns error message
	*/
	const char* what() const noexcept
	{
		return m_errorMessage.c_str();
	}

};

/*************************************************************************************************************************
 Class CInputVector
**************************************************************************************************************************/
template <typename T>
class CInputVector {
private:
	
	const T* m_data;
	size_t m_size;
	
public:
	
	CInputVector( const std::vector<T>& vec)
		: m_data( vec.data() ), m_size( vec.size() )
	{
	}
	
	CInputVector( const T* in_data, size_t in_size)
		: m_data( in_data ), m_size(in_size )
	{
	}
	
	const T* data() const
	{
		return m_data;
	}
	
	size_t size() const
	{
		return m_size;
	}
	
};

// declare deprecated class name
template<typename T>
using CCalculationInputVector = CInputVector<T>;

/*************************************************************************************************************************
 Class CWrapper 
**************************************************************************************************************************/
class CWrapper {
public:
	
	CWrapper(void* pSymbolLookupMethod)
	{
		CheckError(nullptr, initWrapperTable(&m_WrapperTable));
		CheckError(nullptr, loadWrapperTableFromSymbolLookupMethod(&m_WrapperTable, pSymbolLookupMethod));
		
		CheckError(nullptr, checkBinaryVersion());
	}
	
	CWrapper(const std::string &sFileName)
	{
		CheckError(nullptr, initWrapperTable(&m_WrapperTable));
		CheckError(nullptr, loadWrapperTable(&m_WrapperTable, sFileName.c_str()));
		
		CheckError(nullptr, checkBinaryVersion());
	}
	
	static PWrapper loadLibrary(const std::string &sFileName)
	{
		return std::make_shared<CWrapper>(sFileName);
	}
	
	static PWrapper loadLibraryFromSymbolLookupMethod(void* pSymbolLookupMethod)
	{
		return std::make_shared<CWrapper>(pSymbolLookupMethod);
	}
	
	~CWrapper()
	{
		releaseWrapperTable(&m_WrapperTable);
	}
	
	inline void CheckError(CBase * pBaseClass, CalculationResult nResult);

	inline PCalculator CreateCalculator();
	inline void GetVersion(Calculation_uint32 & nMajor, Calculation_uint32 & nMinor, Calculation_uint32 & nMicro);
	inline bool GetLastError(CBase * pInstance, std::string & sErrorMessage);
	inline void ReleaseInstance(CBase * pInstance);
	inline void AcquireInstance(CBase * pInstance);
	inline void InjectComponent(const std::string & sNameSpace, const Calculation_pvoid pSymbolAddressMethod);
	inline Calculation_pvoid GetSymbolLookupMethod();

private:
	sCalculationDynamicWrapperTable m_WrapperTable;
	// Injected Components
	Numbers::PWrapper m_pNumbersWrapper;

	
	CalculationResult checkBinaryVersion()
	{
		Calculation_uint32 nMajor, nMinor, nMicro;
		GetVersion(nMajor, nMinor, nMicro);
		if ( (nMajor != CALCULATION_VERSION_MAJOR) || (nMinor < CALCULATION_VERSION_MINOR) ) {
			return CALCULATION_ERROR_INCOMPATIBLEBINARYVERSION;
		}
		return CALCULATION_SUCCESS;
	}
	CalculationResult initWrapperTable(sCalculationDynamicWrapperTable * pWrapperTable);
	CalculationResult releaseWrapperTable(sCalculationDynamicWrapperTable * pWrapperTable);
	CalculationResult loadWrapperTable(sCalculationDynamicWrapperTable * pWrapperTable, const char * pLibraryFileName);
	CalculationResult loadWrapperTableFromSymbolLookupMethod(sCalculationDynamicWrapperTable * pWrapperTable, void* pSymbolLookupMethod);

	friend class CBase;
	friend class CCalculator;

};

	
/*************************************************************************************************************************
 Class CBase 
**************************************************************************************************************************/
class CBase {
public:
	
protected:
	/* Wrapper Object that created the class. */
	CWrapper * m_pWrapper;
	/* Handle to Instance in library*/
	CalculationHandle m_pHandle;

	/* Checks for an Error code and raises Exceptions */
	void CheckError(CalculationResult nResult)
	{
		if (m_pWrapper != nullptr)
			m_pWrapper->CheckError(this, nResult);
	}
public:
	/**
	* CBase::CBase - Constructor for Base class.
	*/
	CBase(CWrapper * pWrapper, CalculationHandle pHandle)
		: m_pWrapper(pWrapper), m_pHandle(pHandle)
	{
	}

	/**
	* CBase::~CBase - Destructor for Base class.
	*/
	virtual ~CBase()
	{
		if (m_pWrapper != nullptr)
			m_pWrapper->ReleaseInstance(this);
		m_pWrapper = nullptr;
	}

	/**
	* CBase::GetHandle - Returns handle to instance.
	*/
	CalculationHandle GetHandle()
	{
		return m_pHandle;
	}
	
	friend class CWrapper;
};
	
/*************************************************************************************************************************
 Class CCalculator 
**************************************************************************************************************************/
class CCalculator : public CBase {
public:
	
	/**
	* CCalculator::CCalculator - Constructor for Calculator class.
	*/
	CCalculator(CWrapper* pWrapper, CalculationHandle pHandle)
		: CBase(pWrapper, pHandle)
	{
	}
	
	inline void EnlistVariable(Numbers::CVariable * pVariable);
	inline Numbers::PVariable GetEnlistedVariable(const Calculation_uint32 nIndex);
	inline void ClearVariables();
	inline Numbers::PVariable Multiply();
	inline Numbers::PVariable Add();
};
	
	/**
	* CWrapper::CreateCalculator - Creates a new Calculator instance
	* @return New Calculator instance
	*/
	inline PCalculator CWrapper::CreateCalculator()
	{
		CalculationHandle hInstance = nullptr;
		CheckError(nullptr,m_WrapperTable.m_CreateCalculator(&hInstance));
		
		if (!hInstance) {
			CheckError(nullptr,CALCULATION_ERROR_INVALIDPARAM);
		}
		return std::make_shared<CCalculator>(this, hInstance);
	}
	
	/**
	* CWrapper::GetVersion - retrieves the binary version of this library.
	* @param[out] nMajor - returns the major version of this library
	* @param[out] nMinor - returns the minor version of this library
	* @param[out] nMicro - returns the micro version of this library
	*/
	inline void CWrapper::GetVersion(Calculation_uint32 & nMajor, Calculation_uint32 & nMinor, Calculation_uint32 & nMicro)
	{
		CheckError(nullptr,m_WrapperTable.m_GetVersion(&nMajor, &nMinor, &nMicro));
	}
	
	/**
	* CWrapper::GetLastError - Returns the last error recorded on this object
	* @param[in] pInstance - Instance Handle
	* @param[out] sErrorMessage - Message of the last error
	* @return Is there a last error to query
	*/
	inline bool CWrapper::GetLastError(CBase * pInstance, std::string & sErrorMessage)
	{
		CalculationHandle hInstance = nullptr;
		if (pInstance != nullptr) {
			hInstance = pInstance->GetHandle();
		};
		Calculation_uint32 bytesNeededErrorMessage = 0;
		Calculation_uint32 bytesWrittenErrorMessage = 0;
		bool resultHasError = 0;
		CheckError(nullptr,m_WrapperTable.m_GetLastError(hInstance, 0, &bytesNeededErrorMessage, nullptr, &resultHasError));
		std::vector<char> bufferErrorMessage(bytesNeededErrorMessage);
		CheckError(nullptr,m_WrapperTable.m_GetLastError(hInstance, bytesNeededErrorMessage, &bytesWrittenErrorMessage, &bufferErrorMessage[0], &resultHasError));
		sErrorMessage = std::string(&bufferErrorMessage[0]);
		
		return resultHasError;
	}
	
	/**
	* CWrapper::ReleaseInstance - Releases shared ownership of an Instance
	* @param[in] pInstance - Instance Handle
	*/
	inline void CWrapper::ReleaseInstance(CBase * pInstance)
	{
		CalculationHandle hInstance = nullptr;
		if (pInstance != nullptr) {
			hInstance = pInstance->GetHandle();
		};
		CheckError(nullptr,m_WrapperTable.m_ReleaseInstance(hInstance));
	}
	
	/**
	* CWrapper::AcquireInstance - Acquires shared ownership of an Instance
	* @param[in] pInstance - Instance Handle
	*/
	inline void CWrapper::AcquireInstance(CBase * pInstance)
	{
		CalculationHandle hInstance = nullptr;
		if (pInstance != nullptr) {
			hInstance = pInstance->GetHandle();
		};
		CheckError(nullptr,m_WrapperTable.m_AcquireInstance(hInstance));
	}
	
	/**
	* CWrapper::InjectComponent - Injects an imported component for usage within this component
	* @param[in] sNameSpace - NameSpace of the injected component
	* @param[in] pSymbolAddressMethod - Address of the SymbolAddressMethod of the injected component
	*/
	inline void CWrapper::InjectComponent(const std::string & sNameSpace, const Calculation_pvoid pSymbolAddressMethod)
	{
		CheckError(nullptr,m_WrapperTable.m_InjectComponent(sNameSpace.c_str(), pSymbolAddressMethod));
		
		bool bNameSpaceFound = false;
		if (sNameSpace == "Numbers") {
			if (m_pNumbersWrapper != nullptr) {
				throw ECalculationException(CALCULATION_ERROR_COULDNOTLOADLIBRARY, "Library with namespace " + sNameSpace + " is already registered.");
			}
			m_pNumbersWrapper = Numbers::CWrapper::loadLibraryFromSymbolLookupMethod(pSymbolAddressMethod);
			bNameSpaceFound = true;
		}
		if (!bNameSpaceFound)
			throw ECalculationException(CALCULATION_ERROR_COULDNOTLOADLIBRARY, "Unknown namespace " + sNameSpace);
	}
	
	/**
	* CWrapper::GetSymbolLookupMethod - Returns the address of the SymbolLookupMethod
	* @return Address of the SymbolAddressMethod
	*/
	inline Calculation_pvoid CWrapper::GetSymbolLookupMethod()
	{
		Calculation_pvoid resultSymbolLookupMethod = 0;
		CheckError(nullptr,m_WrapperTable.m_GetSymbolLookupMethod(&resultSymbolLookupMethod));
		
		return resultSymbolLookupMethod;
	}
	
	inline void CWrapper::CheckError(CBase * pBaseClass, CalculationResult nResult)
	{
		if (nResult != 0) {
			std::string sErrorMessage;
			if (pBaseClass != nullptr) {
				GetLastError(pBaseClass, sErrorMessage);
			}
			throw ECalculationException(nResult, sErrorMessage);
		}
	}
	

	inline CalculationResult CWrapper::initWrapperTable(sCalculationDynamicWrapperTable * pWrapperTable)
	{
		if (pWrapperTable == nullptr)
			return CALCULATION_ERROR_INVALIDPARAM;
		
		pWrapperTable->m_LibraryHandle = nullptr;
		pWrapperTable->m_Calculator_EnlistVariable = nullptr;
		pWrapperTable->m_Calculator_GetEnlistedVariable = nullptr;
		pWrapperTable->m_Calculator_ClearVariables = nullptr;
		pWrapperTable->m_Calculator_Multiply = nullptr;
		pWrapperTable->m_Calculator_Add = nullptr;
		pWrapperTable->m_CreateCalculator = nullptr;
		pWrapperTable->m_GetVersion = nullptr;
		pWrapperTable->m_GetLastError = nullptr;
		pWrapperTable->m_ReleaseInstance = nullptr;
		pWrapperTable->m_AcquireInstance = nullptr;
		pWrapperTable->m_InjectComponent = nullptr;
		pWrapperTable->m_GetSymbolLookupMethod = nullptr;
		
		return CALCULATION_SUCCESS;
	}

	inline CalculationResult CWrapper::releaseWrapperTable(sCalculationDynamicWrapperTable * pWrapperTable)
	{
		if (pWrapperTable == nullptr)
			return CALCULATION_ERROR_INVALIDPARAM;
		
		if (pWrapperTable->m_LibraryHandle != nullptr) {
		#ifdef _WIN32
			HMODULE hModule = (HMODULE) pWrapperTable->m_LibraryHandle;
			FreeLibrary(hModule);
		#else // _WIN32
			dlclose(pWrapperTable->m_LibraryHandle);
		#endif // _WIN32
			return initWrapperTable(pWrapperTable);
		}
		
		return CALCULATION_SUCCESS;
	}

	inline CalculationResult CWrapper::loadWrapperTable(sCalculationDynamicWrapperTable * pWrapperTable, const char * pLibraryFileName)
	{
		if (pWrapperTable == nullptr)
			return CALCULATION_ERROR_INVALIDPARAM;
		if (pLibraryFileName == nullptr)
			return CALCULATION_ERROR_INVALIDPARAM;
		
		#ifdef _WIN32
		// Convert filename to UTF16-string
		int nLength = (int)strlen(pLibraryFileName);
		int nBufferSize = nLength * 2 + 2;
		std::vector<wchar_t> wsLibraryFileName(nBufferSize);
		int nResult = MultiByteToWideChar(CP_UTF8, 0, pLibraryFileName, nLength, &wsLibraryFileName[0], nBufferSize);
		if (nResult == 0)
			return CALCULATION_ERROR_COULDNOTLOADLIBRARY;
		
		HMODULE hLibrary = LoadLibraryW(wsLibraryFileName.data());
		if (hLibrary == 0) 
			return CALCULATION_ERROR_COULDNOTLOADLIBRARY;
		#else // _WIN32
		void* hLibrary = dlopen(pLibraryFileName, RTLD_LAZY);
		if (hLibrary == 0) 
			return CALCULATION_ERROR_COULDNOTLOADLIBRARY;
		dlerror();
		#endif // _WIN32
		
		#ifdef _WIN32
		pWrapperTable->m_Calculator_EnlistVariable = (PCalculationCalculator_EnlistVariablePtr) GetProcAddress(hLibrary, "calculation_calculator_enlistvariable");
		#else // _WIN32
		pWrapperTable->m_Calculator_EnlistVariable = (PCalculationCalculator_EnlistVariablePtr) dlsym(hLibrary, "calculation_calculator_enlistvariable");
		dlerror();
		#endif // _WIN32
		if (pWrapperTable->m_Calculator_EnlistVariable == nullptr)
			return CALCULATION_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		#ifdef _WIN32
		pWrapperTable->m_Calculator_GetEnlistedVariable = (PCalculationCalculator_GetEnlistedVariablePtr) GetProcAddress(hLibrary, "calculation_calculator_getenlistedvariable");
		#else // _WIN32
		pWrapperTable->m_Calculator_GetEnlistedVariable = (PCalculationCalculator_GetEnlistedVariablePtr) dlsym(hLibrary, "calculation_calculator_getenlistedvariable");
		dlerror();
		#endif // _WIN32
		if (pWrapperTable->m_Calculator_GetEnlistedVariable == nullptr)
			return CALCULATION_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		#ifdef _WIN32
		pWrapperTable->m_Calculator_ClearVariables = (PCalculationCalculator_ClearVariablesPtr) GetProcAddress(hLibrary, "calculation_calculator_clearvariables");
		#else // _WIN32
		pWrapperTable->m_Calculator_ClearVariables = (PCalculationCalculator_ClearVariablesPtr) dlsym(hLibrary, "calculation_calculator_clearvariables");
		dlerror();
		#endif // _WIN32
		if (pWrapperTable->m_Calculator_ClearVariables == nullptr)
			return CALCULATION_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		#ifdef _WIN32
		pWrapperTable->m_Calculator_Multiply = (PCalculationCalculator_MultiplyPtr) GetProcAddress(hLibrary, "calculation_calculator_multiply");
		#else // _WIN32
		pWrapperTable->m_Calculator_Multiply = (PCalculationCalculator_MultiplyPtr) dlsym(hLibrary, "calculation_calculator_multiply");
		dlerror();
		#endif // _WIN32
		if (pWrapperTable->m_Calculator_Multiply == nullptr)
			return CALCULATION_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		#ifdef _WIN32
		pWrapperTable->m_Calculator_Add = (PCalculationCalculator_AddPtr) GetProcAddress(hLibrary, "calculation_calculator_add");
		#else // _WIN32
		pWrapperTable->m_Calculator_Add = (PCalculationCalculator_AddPtr) dlsym(hLibrary, "calculation_calculator_add");
		dlerror();
		#endif // _WIN32
		if (pWrapperTable->m_Calculator_Add == nullptr)
			return CALCULATION_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		#ifdef _WIN32
		pWrapperTable->m_CreateCalculator = (PCalculationCreateCalculatorPtr) GetProcAddress(hLibrary, "calculation_createcalculator");
		#else // _WIN32
		pWrapperTable->m_CreateCalculator = (PCalculationCreateCalculatorPtr) dlsym(hLibrary, "calculation_createcalculator");
		dlerror();
		#endif // _WIN32
		if (pWrapperTable->m_CreateCalculator == nullptr)
			return CALCULATION_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		#ifdef _WIN32
		pWrapperTable->m_GetVersion = (PCalculationGetVersionPtr) GetProcAddress(hLibrary, "calculation_getversion");
		#else // _WIN32
		pWrapperTable->m_GetVersion = (PCalculationGetVersionPtr) dlsym(hLibrary, "calculation_getversion");
		dlerror();
		#endif // _WIN32
		if (pWrapperTable->m_GetVersion == nullptr)
			return CALCULATION_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		#ifdef _WIN32
		pWrapperTable->m_GetLastError = (PCalculationGetLastErrorPtr) GetProcAddress(hLibrary, "calculation_getlasterror");
		#else // _WIN32
		pWrapperTable->m_GetLastError = (PCalculationGetLastErrorPtr) dlsym(hLibrary, "calculation_getlasterror");
		dlerror();
		#endif // _WIN32
		if (pWrapperTable->m_GetLastError == nullptr)
			return CALCULATION_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		#ifdef _WIN32
		pWrapperTable->m_ReleaseInstance = (PCalculationReleaseInstancePtr) GetProcAddress(hLibrary, "calculation_releaseinstance");
		#else // _WIN32
		pWrapperTable->m_ReleaseInstance = (PCalculationReleaseInstancePtr) dlsym(hLibrary, "calculation_releaseinstance");
		dlerror();
		#endif // _WIN32
		if (pWrapperTable->m_ReleaseInstance == nullptr)
			return CALCULATION_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		#ifdef _WIN32
		pWrapperTable->m_AcquireInstance = (PCalculationAcquireInstancePtr) GetProcAddress(hLibrary, "calculation_acquireinstance");
		#else // _WIN32
		pWrapperTable->m_AcquireInstance = (PCalculationAcquireInstancePtr) dlsym(hLibrary, "calculation_acquireinstance");
		dlerror();
		#endif // _WIN32
		if (pWrapperTable->m_AcquireInstance == nullptr)
			return CALCULATION_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		#ifdef _WIN32
		pWrapperTable->m_InjectComponent = (PCalculationInjectComponentPtr) GetProcAddress(hLibrary, "calculation_injectcomponent");
		#else // _WIN32
		pWrapperTable->m_InjectComponent = (PCalculationInjectComponentPtr) dlsym(hLibrary, "calculation_injectcomponent");
		dlerror();
		#endif // _WIN32
		if (pWrapperTable->m_InjectComponent == nullptr)
			return CALCULATION_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		#ifdef _WIN32
		pWrapperTable->m_GetSymbolLookupMethod = (PCalculationGetSymbolLookupMethodPtr) GetProcAddress(hLibrary, "calculation_getsymbollookupmethod");
		#else // _WIN32
		pWrapperTable->m_GetSymbolLookupMethod = (PCalculationGetSymbolLookupMethodPtr) dlsym(hLibrary, "calculation_getsymbollookupmethod");
		dlerror();
		#endif // _WIN32
		if (pWrapperTable->m_GetSymbolLookupMethod == nullptr)
			return CALCULATION_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		pWrapperTable->m_LibraryHandle = hLibrary;
		return CALCULATION_SUCCESS;
	}

	inline CalculationResult CWrapper::loadWrapperTableFromSymbolLookupMethod(sCalculationDynamicWrapperTable * pWrapperTable, void* pSymbolLookupMethod)
{
		if (pWrapperTable == nullptr)
			return CALCULATION_ERROR_INVALIDPARAM;
		if (pSymbolLookupMethod == nullptr)
			return CALCULATION_ERROR_INVALIDPARAM;
		
		typedef CalculationResult(*SymbolLookupType)(const char*, void**);
		
		SymbolLookupType pLookup = (SymbolLookupType)pSymbolLookupMethod;
		
		CalculationResult eLookupError = CALCULATION_SUCCESS;
		eLookupError = (*pLookup)("calculation_calculator_enlistvariable", (void**)&(pWrapperTable->m_Calculator_EnlistVariable));
		if ( (eLookupError != 0) || (pWrapperTable->m_Calculator_EnlistVariable == nullptr) )
			return CALCULATION_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		eLookupError = (*pLookup)("calculation_calculator_getenlistedvariable", (void**)&(pWrapperTable->m_Calculator_GetEnlistedVariable));
		if ( (eLookupError != 0) || (pWrapperTable->m_Calculator_GetEnlistedVariable == nullptr) )
			return CALCULATION_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		eLookupError = (*pLookup)("calculation_calculator_clearvariables", (void**)&(pWrapperTable->m_Calculator_ClearVariables));
		if ( (eLookupError != 0) || (pWrapperTable->m_Calculator_ClearVariables == nullptr) )
			return CALCULATION_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		eLookupError = (*pLookup)("calculation_calculator_multiply", (void**)&(pWrapperTable->m_Calculator_Multiply));
		if ( (eLookupError != 0) || (pWrapperTable->m_Calculator_Multiply == nullptr) )
			return CALCULATION_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		eLookupError = (*pLookup)("calculation_calculator_add", (void**)&(pWrapperTable->m_Calculator_Add));
		if ( (eLookupError != 0) || (pWrapperTable->m_Calculator_Add == nullptr) )
			return CALCULATION_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		eLookupError = (*pLookup)("calculation_createcalculator", (void**)&(pWrapperTable->m_CreateCalculator));
		if ( (eLookupError != 0) || (pWrapperTable->m_CreateCalculator == nullptr) )
			return CALCULATION_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		eLookupError = (*pLookup)("calculation_getversion", (void**)&(pWrapperTable->m_GetVersion));
		if ( (eLookupError != 0) || (pWrapperTable->m_GetVersion == nullptr) )
			return CALCULATION_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		eLookupError = (*pLookup)("calculation_getlasterror", (void**)&(pWrapperTable->m_GetLastError));
		if ( (eLookupError != 0) || (pWrapperTable->m_GetLastError == nullptr) )
			return CALCULATION_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		eLookupError = (*pLookup)("calculation_releaseinstance", (void**)&(pWrapperTable->m_ReleaseInstance));
		if ( (eLookupError != 0) || (pWrapperTable->m_ReleaseInstance == nullptr) )
			return CALCULATION_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		eLookupError = (*pLookup)("calculation_acquireinstance", (void**)&(pWrapperTable->m_AcquireInstance));
		if ( (eLookupError != 0) || (pWrapperTable->m_AcquireInstance == nullptr) )
			return CALCULATION_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		eLookupError = (*pLookup)("calculation_injectcomponent", (void**)&(pWrapperTable->m_InjectComponent));
		if ( (eLookupError != 0) || (pWrapperTable->m_InjectComponent == nullptr) )
			return CALCULATION_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		eLookupError = (*pLookup)("calculation_getsymbollookupmethod", (void**)&(pWrapperTable->m_GetSymbolLookupMethod));
		if ( (eLookupError != 0) || (pWrapperTable->m_GetSymbolLookupMethod == nullptr) )
			return CALCULATION_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		return CALCULATION_SUCCESS;
}

	
	
	/**
	 * Method definitions for class CBase
	 */
	
	/**
	 * Method definitions for class CCalculator
	 */
	
	/**
	* CCalculator::EnlistVariable - Adds a Variable to the list of Variables this calculator works on
	* @param[in] pVariable - The new variable in this calculator
	*/
	void CCalculator::EnlistVariable(Numbers::CVariable * pVariable)
	{
		NumbersHandle hVariable = nullptr;
		if (pVariable != nullptr) {
			hVariable = pVariable->GetHandle();
		};
		CheckError(m_pWrapper->m_WrapperTable.m_Calculator_EnlistVariable(m_pHandle, hVariable));
	}
	
	/**
	* CCalculator::GetEnlistedVariable - Returns an instance of a enlisted variable
	* @param[in] nIndex - The index of the variable to query
	* @return The Index-th variable in this calculator
	*/
	Numbers::PVariable CCalculator::GetEnlistedVariable(const Calculation_uint32 nIndex)
	{
		CalculationHandle hVariable = nullptr;
		CheckError(m_pWrapper->m_WrapperTable.m_Calculator_GetEnlistedVariable(m_pHandle, nIndex, &hVariable));
		
		if (!hVariable) {
			CheckError(CALCULATION_ERROR_INVALIDPARAM);
		}
		return std::make_shared<Numbers::CVariable>(m_pWrapper->m_pNumbersWrapper.get(), hVariable);
	}
	
	/**
	* CCalculator::ClearVariables - Clears all variables in enlisted in this calculator
	*/
	void CCalculator::ClearVariables()
	{
		CheckError(m_pWrapper->m_WrapperTable.m_Calculator_ClearVariables(m_pHandle));
	}
	
	/**
	* CCalculator::Multiply - Multiplies all enlisted variables
	* @return Variable that holds the product of all enlisted Variables
	*/
	Numbers::PVariable CCalculator::Multiply()
	{
		CalculationHandle hInstance = nullptr;
		CheckError(m_pWrapper->m_WrapperTable.m_Calculator_Multiply(m_pHandle, &hInstance));
		
		if (!hInstance) {
			CheckError(CALCULATION_ERROR_INVALIDPARAM);
		}
		return std::make_shared<Numbers::CVariable>(m_pWrapper->m_pNumbersWrapper.get(), hInstance);
	}
	
	/**
	* CCalculator::Add - Sums all enlisted variables
	* @return Variable that holds the sum of all enlisted Variables
	*/
	Numbers::PVariable CCalculator::Add()
	{
		CalculationHandle hInstance = nullptr;
		CheckError(m_pWrapper->m_WrapperTable.m_Calculator_Add(m_pHandle, &hInstance));
		
		if (!hInstance) {
			CheckError(CALCULATION_ERROR_INVALIDPARAM);
		}
		return std::make_shared<Numbers::CVariable>(m_pWrapper->m_pNumbersWrapper.get(), hInstance);
	}

} // namespace Calculation

#endif // __CALCULATION_CPPHEADER_DYNAMIC_CPP

