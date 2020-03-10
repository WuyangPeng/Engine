// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒıÇæ°æ±¾£º0.0.2.1 (2020/01/21 17:57)

#include "CoreTools/CoreToolsExport.h"

#include "UnitTestSuiteReportOutput.h"
#include "Detail/UnitTestSuiteReportOutputImpl.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::string;
using std::ostream;
using std::make_shared;

CoreTools::UnitTestSuiteReportOutput
	::UnitTestSuiteReportOutput(const string& timeDescribe, int borderLineLength, ostream* osPtr)
	:m_Impl{ make_shared<ImplType>(timeDescribe,borderLineLength,osPtr) }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(CoreTools, UnitTestSuiteReportOutput)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, UnitTestSuiteReportOutput, PrintString, string, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, UnitTestSuiteReportOutput, PrintNewLine, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(CoreTools, UnitTestSuiteReportOutput, PrintBorderLine, char, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, UnitTestSuiteReportOutput, PrintCostTime, CpuTimerPtr, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, UnitTestSuiteReportOutput, PrintSuiteName, string, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, UnitTestSuiteReportOutput, PrintCurrentTime, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, UnitTestSuiteReportOutput, PrintTestName, string, void)

void CoreTools::UnitTestSuiteReportOutput
	::PrintTestResult(int passedNumber, int failedNumber, int errorNumber, int characterWidth)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->PrintTestResult(passedNumber, failedNumber, errorNumber, characterWidth);
}




