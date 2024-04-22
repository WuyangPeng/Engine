/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/12 11:12)

#include "CoreTools/CoreToolsExport.h"

#include "UnitTestSuiteReportOutput.h"
#include "Detail/UnitTestSuiteReportOutputImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

CoreTools::UnitTestSuiteReportOutput::UnitTestSuiteReportOutput(const std::string& timeDescribe, int borderLineLength, const OStreamShared& streamShared)
    : impl{ timeDescribe, borderLineLength, streamShared }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, UnitTestSuiteReportOutput)

void CoreTools::UnitTestSuiteReportOutput::PrintString(const std::string& characterString)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return impl->PrintString(characterString);
}

void CoreTools::UnitTestSuiteReportOutput::PrintNewLine()
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return impl->PrintNewLine();
}

void CoreTools::UnitTestSuiteReportOutput::PrintBorderLine(char character)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return impl->PrintBorderLine(character);
}

void CoreTools::UnitTestSuiteReportOutput::PrintCurrentTime()
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return impl->PrintCurrentTime();
}

void CoreTools::UnitTestSuiteReportOutput::PrintCostTime(const CpuTimer& cpuTime)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return impl->PrintCostTime(cpuTime);
}

void CoreTools::UnitTestSuiteReportOutput::PrintSuiteName(const std::string& suiteName)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return impl->PrintSuiteName(suiteName);
}

void CoreTools::UnitTestSuiteReportOutput::PrintTestName(const std::string& testName)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return impl->PrintTestName(testName);
}

void CoreTools::UnitTestSuiteReportOutput::PrintTestResult(int passedNumber, int failedNumber, int errorNumber, int characterWidth)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return impl->PrintTestResult(passedNumber, failedNumber, errorNumber, characterWidth);
}
