// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒıÇæ°æ±¾£º0.0.2.2 (2020/01/22 10:20)

#include "CoreTools/CoreToolsExport.h"

#include "UnitTestFailPrintManager.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"
#include "CoreTools/ReportOutput/UnitTestFailReportOutput.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::string;
using std::make_shared;

CoreTools::UnitTestFailPrintManager
	::UnitTestFailPrintManager(UnitTest& unitTest, const string& fileName, int lineNumber, const string& errorMessage)
	:m_ReportOutputPtr{ make_shared<UnitTestFailReportOutput>(typeid(unitTest).name(),fileName,lineNumber,errorMessage,unitTest.GetStream()) }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::UnitTestFailPrintManager
	::IsValid() const noexcept
{
	if (m_ReportOutputPtr != nullptr)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

void CoreTools::UnitTestFailPrintManager
	::PrintFailClassInformation()
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	m_ReportOutputPtr->PrintNewLine();
	m_ReportOutputPtr->PrintFailClassInformation();
	m_ReportOutputPtr->PrintNewLine();
}

void CoreTools::UnitTestFailPrintManager
	::PrintFailFileName()
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	m_ReportOutputPtr->PrintFailFileName();
	m_ReportOutputPtr->PrintNewLine();
}

void CoreTools::UnitTestFailPrintManager
	::PrintFailLineNumber()
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	m_ReportOutputPtr->PrintFailLineNumber();
	m_ReportOutputPtr->PrintNewLine();
}

void CoreTools::UnitTestFailPrintManager
	::PrintErrorMessage()
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	m_ReportOutputPtr->PrintErrorMessage();
	m_ReportOutputPtr->PrintNewLine();
	m_ReportOutputPtr->PrintNewLine();
}


