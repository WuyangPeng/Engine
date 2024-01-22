/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 10:18)

#include "CoreTools/CoreToolsExport.h"

#include "EquidistantReportOutput.h"
#include "Detail/EquidistantReportOutputImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

CoreTools::EquidistantReportOutput::EquidistantReportOutput(int borderLineLength, const OStreamShared& streamShared)
    : impl{ borderLineLength, streamShared }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, EquidistantReportOutput)

void CoreTools::EquidistantReportOutput::PrintNewLine()
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return impl->PrintNewLine();
}

void CoreTools::EquidistantReportOutput::PrintBorderLine(char character)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return impl->PrintBorderLine(character);
}

void CoreTools::EquidistantReportOutput::PrintString(const std::string& characterString)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return impl->PrintString(characterString);
}
