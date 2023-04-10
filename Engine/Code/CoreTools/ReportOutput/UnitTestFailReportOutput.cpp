///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.5 (2023/03/31 15:52)

#include "CoreTools/CoreToolsExport.h"

#include "UnitTestFailReportOutput.h"
#include "Detail/UnitTestFailReportOutputImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

CoreTools::UnitTestFailReportOutput::UnitTestFailReportOutput(const std::string& failClassName, const std::string& fileName, int lineNumber, const std::string& errorMessage, const OStreamShared& streamShared)
    : impl{ failClassName, fileName, lineNumber, errorMessage, streamShared }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, UnitTestFailReportOutput)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, UnitTestFailReportOutput, PrintNewLine, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, UnitTestFailReportOutput, PrintFailClassInformation, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, UnitTestFailReportOutput, PrintFailFileName, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, UnitTestFailReportOutput, PrintFailLineNumber, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, UnitTestFailReportOutput, PrintErrorMessage, void)