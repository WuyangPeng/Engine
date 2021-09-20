//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.7.1.1 (2020/10/23 14:47)

#include "CoreTools/CoreToolsExport.h"

#include "UnitTestPrintManager.h"
#include "System/Helper/PragmaWarning/Timer.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/ReportOutput/UnitTestSuiteReportOutput.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

using std::make_shared;
using std::string;

CoreTools::UnitTestPrintManager::UnitTestPrintManager(MasterType& unitTest, const string& timeDescribe, int borderLineLength)
    : m_UnitTest{ unitTest }, m_ReportOutputPtr{ make_shared<UnitTestSuiteReportOutput>(timeDescribe, borderLineLength, m_UnitTest.GetStream()) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::UnitTestPrintManager::IsValid() const noexcept
{
    if (m_ReportOutputPtr != nullptr)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

void CoreTools::UnitTestPrintManager::PrintTestName()
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    m_ReportOutputPtr->PrintNewLine();
    m_ReportOutputPtr->PrintTestName(typeid(m_UnitTest).name());
    m_ReportOutputPtr->PrintNewLine();
}

void CoreTools::UnitTestPrintManager::PrintTestResult(int characterWidth)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    m_ReportOutputPtr->PrintTestResult(m_UnitTest.GetPassedNumber(), m_UnitTest.GetFailedNumber(), m_UnitTest.GetErrorNumber(), characterWidth);
    m_ReportOutputPtr->PrintNewLine();
    m_ReportOutputPtr->PrintNewLine();
}

void CoreTools::UnitTestPrintManager::PrintCostTime(const CpuTimer& timePtr)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    m_ReportOutputPtr->PrintCostTime(timePtr);
    m_ReportOutputPtr->PrintNewLine();
    m_ReportOutputPtr->PrintBorderLine('=');
    m_ReportOutputPtr->PrintNewLine();
}
