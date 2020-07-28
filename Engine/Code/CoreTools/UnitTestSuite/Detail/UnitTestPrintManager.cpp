// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒıÇæ°æ±¾£º0.0.2.2 (2020/01/22 10:21)

#include "CoreTools/CoreToolsExport.h"

#include "UnitTestPrintManager.h"
#include "System/Helper/PragmaWarning/Timer.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"
#include "CoreTools/ReportOutput/UnitTestSuiteReportOutput.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::string;
using std::make_shared;

CoreTools::UnitTestPrintManager
	::UnitTestPrintManager(MasterType& unitTest, const string& timeDescribe, int borderLineLength)
	:m_UnitTest{ unitTest },
	m_ReportOutputPtr{ make_shared<UnitTestSuiteReportOutput>(timeDescribe,borderLineLength,m_UnitTest.GetStream()) }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::UnitTestPrintManager
	::IsValid() const noexcept
{
	if (m_ReportOutputPtr != nullptr)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

void CoreTools::UnitTestPrintManager
	::PrintTestName()
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	m_ReportOutputPtr->PrintNewLine();
	m_ReportOutputPtr->PrintTestName(typeid(m_UnitTest).name());
	m_ReportOutputPtr->PrintNewLine();
}

void CoreTools::UnitTestPrintManager
	::PrintTestResult(int characterWidth)
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	m_ReportOutputPtr->PrintTestResult(m_UnitTest.GetPassedNumber(), m_UnitTest.GetFailedNumber(), m_UnitTest.GetErrorNumber(), characterWidth);
	m_ReportOutputPtr->PrintNewLine();
	m_ReportOutputPtr->PrintNewLine();
}

void CoreTools::UnitTestPrintManager
	::PrintCostTime(const CpuTimer& timePtr)
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	m_ReportOutputPtr->PrintCostTime(timePtr);
	m_ReportOutputPtr->PrintNewLine();
	m_ReportOutputPtr->PrintBorderLine('=');
	m_ReportOutputPtr->PrintNewLine();
}
