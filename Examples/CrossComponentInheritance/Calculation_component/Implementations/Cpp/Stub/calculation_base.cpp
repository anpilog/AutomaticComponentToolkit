/*++

Copyright (C) 2019 Calculation developers

All rights reserved.

Abstract: This is a stub class definition of CBase

*/

#include "calculation_base.hpp"
#include "calculation_interfaceexception.hpp"

// Include custom headers here.


using namespace Calculation::Impl;

/*************************************************************************************************************************
 Class definition of CBase 
**************************************************************************************************************************/

void CBase::ClearErrorMessages()
{
	m_pErrors.reset();
}

void CBase::RegisterErrorMessage(const std::string & sErrorMessage)
{
	if (!m_pErrors) {
		m_pErrors.reset(new std::list<std::string>());
	}
	m_pErrors->clear();
	m_pErrors->push_back(sErrorMessage);
}

bool CBase::GetLastError(std::string & sErrorMessage)
{
	if (m_pErrors && !m_pErrors->empty()) {
		sErrorMessage = m_pErrors->back();
		return true;
	} else {
		sErrorMessage = "";
		return false;
	}
}

void CBase::ReleaseInstance()
{
	m_nReferenceCount--;
	if (!m_nReferenceCount) {
		delete this;
	}
}

void CBase::AcquireInstance()
{
	++m_nReferenceCount;
}

