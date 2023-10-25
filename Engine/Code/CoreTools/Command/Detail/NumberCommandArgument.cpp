///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/23 10:08)

#include "CoreTools/CoreToolsExport.h"

#include "NumberCommandArgument.h"
#include "System/Helper/PragmaWarning/LexicalCast.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

CoreTools::NumberCommandArgument::NumberCommandArgument(int index, const std::string& name, const std::string& value)
    : ParentType{ index, name }, value{ value }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, NumberCommandArgument)

int CoreTools::NumberCommandArgument::GetInteger() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return boost::lexical_cast<int>(value);
}

float CoreTools::NumberCommandArgument::GetFloat() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return boost::lexical_cast<float>(value);
}

double CoreTools::NumberCommandArgument::GetDouble() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return boost::lexical_cast<double>(value);
}

std::string CoreTools::NumberCommandArgument::GetString() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    THROW_EXCEPTION(SYSTEM_TEXT("NumberCommandArgument不是字符串！"s))
}

bool CoreTools::NumberCommandArgument::IsInteger() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return true;
}

bool CoreTools::NumberCommandArgument::IsFloat() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return true;
}

bool CoreTools::NumberCommandArgument::IsDouble() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return true;
}

bool CoreTools::NumberCommandArgument::IsString() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return false;
}

bool CoreTools::NumberCommandArgument::IsNoValue() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return false;
}

CoreTools::NumberCommandArgument::CommandArgumentSharedPtr CoreTools::NumberCommandArgument::Clone() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return std::make_shared<NumberCommandArgument>(*this);
}

void CoreTools::NumberCommandArgument::AddArgumentValue(const std::string& aValue)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    System::UnusedFunction(aValue);

    THROW_EXCEPTION(SYSTEM_TEXT("NumberCommandArgument不能添加值！"s))
}
