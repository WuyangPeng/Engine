///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/21 18:20)

#include "CoreTools/CoreToolsExport.h"

#include "EquilongReportOutput.h"
#include "Detail/EquilongReportOutputImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

CoreTools::EquilongReportOutput::EquilongReportOutput(int borderLineLength, const OStreamShared& streamShared)
    : impl{ borderLineLength, streamShared }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, EquilongReportOutput)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, EquilongReportOutput, PrintNewLine, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(CoreTools, EquilongReportOutput, PrintBorderLine, char, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, EquilongReportOutput, PrintString, std::string, void)