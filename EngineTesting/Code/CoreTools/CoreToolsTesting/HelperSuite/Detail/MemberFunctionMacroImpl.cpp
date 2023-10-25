///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/24 15:37)

#include "MemberFunctionMacroImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::MemberFunctionMacroImpl::MemberFunctionMacroImpl() noexcept
    : character{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, MemberFunctionMacroImpl)

std::string CoreTools::MemberFunctionMacroImpl::ConstMemberFunction() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return character;
}

std::string CoreTools::MemberFunctionMacroImpl::ConstMemberFunction(int value) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return std::to_string(value);
}

std::string CoreTools::MemberFunctionMacroImpl::ConstMemberFunction(const std::string& aCharacter) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return aCharacter;
}

std::string CoreTools::MemberFunctionMacroImpl::ConstMemberFunction(const std::string* aCharacter) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    if (aCharacter != nullptr)
        return *aCharacter;
    else
        return "";
}

void CoreTools::MemberFunctionMacroImpl::NonConstCopyMemberFunction()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    character = "";
}

void CoreTools::MemberFunctionMacroImpl::NonConstCopyMemberFunction(int value)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    character += std::to_string(value);
}

void CoreTools::MemberFunctionMacroImpl::NonConstCopyMemberFunction(const std::string& aCharacter)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    character = aCharacter;
}

void CoreTools::MemberFunctionMacroImpl::NonConstCopyMemberFunction(const std::string* aCharacter)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    if (aCharacter != nullptr)
    {
        character = *aCharacter;
    }
}
