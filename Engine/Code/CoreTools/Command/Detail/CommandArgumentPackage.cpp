//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.7.1.1 (2020/10/23 16:41)

#include "CoreTools/CoreToolsExport.h"

#include "CommandArgumentPackage.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::string;

CoreTools::CommandArgumentPackage::CommandArgumentPackage(int index, const std::string& name)
    : m_Index{ index }, m_Name{ name }, m_Used{ false }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::CommandArgumentPackage::IsValid() const noexcept
{
    if (1 <= m_Index)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

int CoreTools::CommandArgumentPackage::GetIndex() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return m_Index;
}

const string CoreTools::CommandArgumentPackage::GetName() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return m_Name;
}

bool CoreTools::CommandArgumentPackage::IsUsed() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return m_Used;
}

void CoreTools::CommandArgumentPackage::SetUsed() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    m_Used = true;
}
