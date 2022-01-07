///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/21 18:20)

#include "CoreTools/CoreToolsExport.h"

#include "UnitTestFailReportOutput.h"
#include "Detail/UnitTestFailReportOutputImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::string;

CoreTools::UnitTestFailReportOutput::UnitTestFailReportOutput(const string& failClassName, const string& fileName, int lineNumber, const string& errorMessage, const OStreamShared& streamShared)
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