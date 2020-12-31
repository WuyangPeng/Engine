//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/23 16:41)

#include "CoreTools/CoreToolsExport.h"

#include "CommandArgumentImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::string;

CoreTools::CommandArgumentImpl::CommandArgumentImpl(int index, const std::string& name)
    : m_Index{ index }, m_Name{ name }, m_Used{ false }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::CommandArgumentImpl::IsValid() const noexcept
{
    if (1 <= m_Index)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

int CoreTools::CommandArgumentImpl::GetIndex() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return m_Index;
}

const string CoreTools::CommandArgumentImpl::GetName() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return m_Name;
}

bool CoreTools::CommandArgumentImpl::IsUsed() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return m_Used;
}

void CoreTools::CommandArgumentImpl::SetUsed() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    m_Used = true;
}
