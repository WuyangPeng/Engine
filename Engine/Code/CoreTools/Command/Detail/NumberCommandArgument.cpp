//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.7.1.1 (2020/10/23 16:43)

#include "CoreTools/CoreToolsExport.h"

#include "NumberCommandArgument.h"
#include "System/Helper/PragmaWarning/LexicalCast.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

using std::make_shared;
using std::string;

CoreTools::NumberCommandArgument::NumberCommandArgument(int index, const string& name, const string& value)
    : ParentType{ index, name }, m_Value{ value }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, NumberCommandArgument)

int CoreTools::NumberCommandArgument::GetInteger() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return boost::lexical_cast<int>(m_Value);
}

float CoreTools::NumberCommandArgument::GetFloat() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return boost::lexical_cast<float>(m_Value);
}

double CoreTools::NumberCommandArgument::GetDouble() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return boost::lexical_cast<double>(m_Value);
}

const string CoreTools::NumberCommandArgument::GetString() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    THROW_EXCEPTION(SYSTEM_TEXT("NumberCommandArgument不是字符串！"s));
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

    return make_shared<NumberCommandArgument>(*this);
}

void CoreTools::NumberCommandArgument::AddArgumentValue([[maybe_unused]] const string& value)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    THROW_EXCEPTION(SYSTEM_TEXT("NumberCommandArgument不能添加值！"s));
}
