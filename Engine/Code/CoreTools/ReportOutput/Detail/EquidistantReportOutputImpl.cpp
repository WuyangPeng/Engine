///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/20 14:57)

#include "CoreTools/CoreToolsExport.h"

#include "EquidistantReportOutputImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::EquidistantReportOutputImpl::EquidistantReportOutputImpl(int borderLineLength, const OStreamShared& streamShared) noexcept
    : ParentType{ streamShared }, borderLineLength{ borderLineLength }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool CoreTools::EquidistantReportOutputImpl::IsValid() const noexcept
{
    if (ParentType::IsValid() && 0 < borderLineLength)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

void CoreTools::EquidistantReportOutputImpl::PrintBorderLine(char character)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    const std::string borderLine(borderLineLength, character);

    PrintString(borderLine);
}

int CoreTools::EquidistantReportOutputImpl::GetBorderLineLength() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return borderLineLength;
}
