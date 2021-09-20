//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.7.1.1 (2020/10/23 10:20)

#include "CoreTools/CoreToolsExport.h"

#include "UnitTestSuiteReportOutput.h"
#include "Detail/UnitTestSuiteReportOutputImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::make_shared;
using std::ostream;
using std::string;

CoreTools::UnitTestSuiteReportOutput::UnitTestSuiteReportOutput(const string& timeDescribe, int borderLineLength, const OStreamShared& streamShared)
    : impl{  timeDescribe, borderLineLength, streamShared  }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, UnitTestSuiteReportOutput)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, UnitTestSuiteReportOutput, PrintString, string, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, UnitTestSuiteReportOutput, PrintNewLine, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(CoreTools, UnitTestSuiteReportOutput, PrintBorderLine, char, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, UnitTestSuiteReportOutput, PrintCostTime, CpuTimer, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, UnitTestSuiteReportOutput, PrintSuiteName, string, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, UnitTestSuiteReportOutput, PrintCurrentTime, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, UnitTestSuiteReportOutput, PrintTestName, string, void)

void CoreTools::UnitTestSuiteReportOutput::PrintTestResult(int passedNumber, int failedNumber, int errorNumber, int characterWidth)
{
    

    return impl->PrintTestResult(passedNumber, failedNumber, errorNumber, characterWidth);
}
