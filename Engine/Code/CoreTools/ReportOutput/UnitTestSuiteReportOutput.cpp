///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/03/31 15:52)

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

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, UnitTestSuiteReportOutput, PrintString, std::string, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, UnitTestSuiteReportOutput, PrintNewLine, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(CoreTools, UnitTestSuiteReportOutput, PrintBorderLine, char, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, UnitTestSuiteReportOutput, PrintCostTime, CpuTimer, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, UnitTestSuiteReportOutput, PrintSuiteName, std::string, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, UnitTestSuiteReportOutput, PrintCurrentTime, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, UnitTestSuiteReportOutput, PrintTestName, std::string, void)

void CoreTools::UnitTestSuiteReportOutput::PrintTestResult(int passedNumber, int failedNumber, int errorNumber, int characterWidth)
{
    return impl->PrintTestResult(passedNumber, failedNumber, errorNumber, characterWidth);
}
