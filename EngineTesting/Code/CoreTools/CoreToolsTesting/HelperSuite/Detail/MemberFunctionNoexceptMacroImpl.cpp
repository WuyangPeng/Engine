///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.2.1 (2021/08/16 21:23)

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
