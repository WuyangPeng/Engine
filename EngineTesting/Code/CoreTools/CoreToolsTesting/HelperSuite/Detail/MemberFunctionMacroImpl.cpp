///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/19 11:23)

#include "MemberFunctionMacroImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::string;
using std::to_string;

CoreTools::MemberFunctionMacroImpl::MemberFunctionMacroImpl() noexcept
    : mCharacter{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, MemberFunctionMacroImpl)

string CoreTools::MemberFunctionMacroImpl::ConstMemberFunction() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return mCharacter;
}

string CoreTools::MemberFunctionMacroImpl::ConstMemberFunction(int value) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return to_string(value);
}

string CoreTools::MemberFunctionMacroImpl::ConstMemberFunction(const string& character) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return character;
}

string CoreTools::MemberFunctionMacroImpl::ConstMemberFunction(const string* character) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    if (character != nullptr)
        return *character;
    else
        return "";
}

void CoreTools::MemberFunctionMacroImpl::NonConstCopyMemberFunction()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    mCharacter = "";
}

void CoreTools::MemberFunctionMacroImpl::NonConstCopyMemberFunction(int value)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    mCharacter += to_string(value);
}

void CoreTools::MemberFunctionMacroImpl::NonConstCopyMemberFunction(const string& character)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    mCharacter = character;
}

void CoreTools::MemberFunctionMacroImpl::NonConstCopyMemberFunction(const string* character)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    if (character != nullptr)
    {
        mCharacter = *character;
    }
}
