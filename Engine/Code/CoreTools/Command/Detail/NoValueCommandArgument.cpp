//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.0 (2020/10/23 16:42)

#include "CoreTools/CoreToolsExport.h"

#include "NoValueCommandArgument.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

using std::make_shared;
using std::string;

CoreTools::NoValueCommandArgument::NoValueCommandArgument(int index, const string& name)
    : ParentType{ index, name }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, NoValueCommandArgument)

int CoreTools::NoValueCommandArgument::GetInteger() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    THROW_EXCEPTION(SYSTEM_TEXT("NoValueCommandArgument����������"s));
}

float CoreTools::NoValueCommandArgument::GetFloat() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    THROW_EXCEPTION(SYSTEM_TEXT("NoValueCommandArgument���Ǹ�������"s));
}

double CoreTools::NoValueCommandArgument::GetDouble() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    THROW_EXCEPTION(SYSTEM_TEXT("NoValueCommandArgument���Ǹ�������"s));
}

const string CoreTools::NoValueCommandArgument::GetString() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    THROW_EXCEPTION(SYSTEM_TEXT("NoValueCommandArgument�����ַ�����"s));
}

bool CoreTools::NoValueCommandArgument::IsInteger() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return false;
}

bool CoreTools::NoValueCommandArgument::IsFloat() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return false;
}

bool CoreTools::NoValueCommandArgument::IsDouble() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return false;
}

bool CoreTools::NoValueCommandArgument::IsString() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return false;
}

bool CoreTools::NoValueCommandArgument::IsNoValue() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return true;
}

CoreTools::NoValueCommandArgument::CommandArgumentSharedPtr CoreTools::NoValueCommandArgument::Clone() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return make_shared<NoValueCommandArgument>(*this);
}

void CoreTools::NoValueCommandArgument::AddArgumentValue([[maybe_unused]] const string& value)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    THROW_EXCEPTION(SYSTEM_TEXT("NoValueCommandArgumentû��ֵ��"s));
}
