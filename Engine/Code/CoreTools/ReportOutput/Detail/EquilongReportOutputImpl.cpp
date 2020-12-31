//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/23 9:59)

#include "CoreTools/CoreToolsExport.h"

#include "EquilongReportOutputImpl.h" 
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::string;

CoreTools::EquilongReportOutputImpl::EquilongReportOutputImpl(int borderLineLength, const OStreamShared& streamShared) noexcept
    : ParentType{ streamShared }, m_BorderLineLength{ borderLineLength }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::EquilongReportOutputImpl::IsValid() const noexcept
{
    if (ParentType::IsValid() && 0 < m_BorderLineLength)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

void CoreTools::EquilongReportOutputImpl::PrintBorderLine(char character)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    string borderLine(m_BorderLineLength, character);

    PrintString(borderLine);
}

// protected
int CoreTools::EquilongReportOutputImpl::GetBorderLineLength() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return m_BorderLineLength;
}
