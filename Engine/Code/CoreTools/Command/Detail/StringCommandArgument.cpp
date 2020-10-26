//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/23 16:43)

#include "CoreTools/CoreToolsExport.h"

#include "StringCommandArgument.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

using std::make_shared;
using std::string;

CoreTools::StringCommandArgument::StringCommandArgument(int index, const string& name, const string& value)
    : ParentType{ index, name }, m_String{ value }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, StringCommandArgument)

int CoreTools::StringCommandArgument::GetInteger() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    THROW_EXCEPTION(SYSTEM_TEXT("StringCommandArgument不是整数！"s));
}

float CoreTools::StringCommandArgument::GetFloat() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    THROW_EXCEPTION(SYSTEM_TEXT("StringCommandArgument不是浮点数！"s));
}

double CoreTools::StringCommandArgument::GetDouble() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    THROW_EXCEPTION(SYSTEM_TEXT("StringCommandArgument不是浮点数！"s));
}

const string CoreTools::StringCommandArgument::GetString() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return m_String;
}

bool CoreTools::StringCommandArgument::IsInteger() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return false;
}

bool CoreTools::StringCommandArgument::IsFloat() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return false;
}

bool CoreTools::StringCommandArgument::IsDouble() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return false;
}

bool CoreTools::StringCommandArgument::IsString() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return true;
}

bool CoreTools::StringCommandArgument::IsNoValue() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return false;
}

CoreTools::StringCommandArgument::CommandArgumentSharedPtr CoreTools::StringCommandArgument::Clone() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return make_shared<StringCommandArgument>(*this);
}

void CoreTools::StringCommandArgument::AddArgumentValue(const string& value)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    m_String += " ";
    m_String += value;
}
