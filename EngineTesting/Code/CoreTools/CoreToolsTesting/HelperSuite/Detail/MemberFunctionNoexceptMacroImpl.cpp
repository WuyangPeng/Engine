///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/19 11:23)

#include "MemberFunctionNoexceptMacroImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::string;

CoreTools::MemberFunctionNoexceptMacroImpl::MemberFunctionNoexceptMacroImpl() noexcept
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, MemberFunctionNoexceptMacroImpl)

void CoreTools::MemberFunctionNoexceptMacroImpl::ConstMemberFunction() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;
}

void CoreTools::MemberFunctionNoexceptMacroImpl::ConstMemberFunction(MAYBE_UNUSED int value) const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;
}

void CoreTools::MemberFunctionNoexceptMacroImpl::ConstMemberFunction(MAYBE_UNUSED const string& character) const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;
}

void CoreTools::MemberFunctionNoexceptMacroImpl::ConstMemberFunction(MAYBE_UNUSED const string* character) const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;
}

void CoreTools::MemberFunctionNoexceptMacroImpl::NonConstCopyMemberFunction() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;
}

void CoreTools::MemberFunctionNoexceptMacroImpl::NonConstCopyMemberFunction(MAYBE_UNUSED int value) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;
}

void CoreTools::MemberFunctionNoexceptMacroImpl::NonConstCopyMemberFunction(MAYBE_UNUSED const string& character) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;
}

void CoreTools::MemberFunctionNoexceptMacroImpl::NonConstCopyMemberFunction(MAYBE_UNUSED const string* character) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;
}
