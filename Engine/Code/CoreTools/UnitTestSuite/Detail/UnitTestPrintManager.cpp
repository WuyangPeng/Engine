///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/14 21:36)

#include "CoreTools/CoreToolsExport.h"

#include "UnitTestPrintManager.h"
#include "System/Helper/PragmaWarning/Timer.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/ReportOutput/UnitTestSuiteReportOutput.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

using std::make_shared;
using std::string;

CoreTools::UnitTestPrintManager::UnitTestPrintManager(MasterType& unitTest, const string& timeDescribe, int borderLineLength)
    : unitTest{ unitTest }, reportOutput{ make_shared<UnitTestSuiteReportOutput>(timeDescribe, borderLineLength, unitTest.GetStream()) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool CoreTools::UnitTestPrintManager::IsValid() const noexcept
{
    if (reportOutput != nullptr)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

void CoreTools::UnitTestPrintManager::PrintTestName()
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    reportOutput->PrintNewLine();
    reportOutput->PrintTestName(typeid(unitTest).name());
    reportOutput->PrintNewLine();
}

void CoreTools::UnitTestPrintManager::PrintTestResult(int characterWidth)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    reportOutput->PrintTestResult(unitTest.GetPassedNumber(), unitTest.GetFailedNumber(), unitTest.GetErrorNumber(), characterWidth);
    reportOutput->PrintNewLine();
    reportOutput->PrintNewLine();
}

void CoreTools::UnitTestPrintManager::PrintCostTime(const CpuTimer& timePtr)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    reportOutput->PrintCostTime(timePtr);
    reportOutput->PrintNewLine();
    reportOutput->PrintBorderLine('=');
    reportOutput->PrintNewLine();
}
