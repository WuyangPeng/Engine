/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/14 21:06)

#include "MemberFunctionNoexceptMacroImpl.h"
#include "System/Helper/Tools.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::MemberFunctionNoexceptMacroImpl::MemberFunctionNoexceptMacroImpl() noexcept
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, MemberFunctionNoexceptMacroImpl)

void CoreTools::MemberFunctionNoexceptMacroImpl::ConstMemberFunction() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;
}

void CoreTools::MemberFunctionNoexceptMacroImpl::ConstMemberFunction(int value) const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(value);
}

void CoreTools::MemberFunctionNoexceptMacroImpl::ConstMemberFunction(const std::string& character) const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(character);
}

void CoreTools::MemberFunctionNoexceptMacroImpl::ConstMemberFunction(const std::string* character) const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(character);
}

void CoreTools::MemberFunctionNoexceptMacroImpl::NonConstCopyMemberFunction() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;
}

void CoreTools::MemberFunctionNoexceptMacroImpl::NonConstCopyMemberFunction(int value) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    System::UnusedFunction(value);
}

void CoreTools::MemberFunctionNoexceptMacroImpl::NonConstCopyMemberFunction(const std::string& character) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    System::UnusedFunction(character);
}

void CoreTools::MemberFunctionNoexceptMacroImpl::NonConstCopyMemberFunction(const std::string* character) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    System::UnusedFunction(character);
}