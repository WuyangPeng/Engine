//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.0 (2020/10/23 16:41)

#include "CoreTools/CoreToolsExport.h"

#include "CommandArgumentType.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::string;

CoreTools::CommandArgumentType::CommandArgumentType(const string& argument)
    : m_Argument{ argument }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, CommandArgumentType)

bool CoreTools::CommandArgumentType::IsArgumentsName() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    if (!m_Argument.empty() && m_Argument.at(0) == '-' && 1 < m_Argument.size())
        return true;
    else
        return false;
}

bool CoreTools::CommandArgumentType::IsDigit() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    if (!m_Argument.empty())
    {
        const auto argument = m_Argument.at(0);
        if (argument != '-' && !isdigit(static_cast<int>(argument)))
        {
            return true;
        }
    }

    return false;
}

bool CoreTools::CommandArgumentType::IsString() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    if (!m_Argument.empty() && m_Argument.at(0) != '-')
        return true;
    else
        return false;
}
