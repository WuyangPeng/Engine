///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.2.1 (2021/08/16 21:23)

#include "MemberFunctionNoexceptMacro.h"
#include "MemberFunctionNoexceptMacroImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::string;

CoreTools::MemberFunctionNoexceptMacro::MemberFunctionNoexceptMacro(MAYBE_UNUSED DisableNotThrow disableNotThrow)
    : impl{ ImplCreateUseDefaultConstruction::Default }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, MemberFunctionNoexceptMacro)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, MemberFunctionNoexceptMacro, ConstMemberFunction, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR_NOEXCEPT(CoreTools, MemberFunctionNoexceptMacro, ConstMemberFunction, string, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(CoreTools, MemberFunctionNoexceptMacro, ConstMemberFunction, int, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CP_NOEXCEPT(CoreTools, MemberFunctionNoexceptMacro, ConstMemberFunction, string, void)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, MemberFunctionNoexceptMacro, NonConstCopyMemberFunction, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR_NOEXCEPT(CoreTools, MemberFunctionNoexceptMacro, NonConstCopyMemberFunction, string, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(CoreTools, MemberFunctionNoexceptMacro, NonConstCopyMemberFunction, int, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CP_NOEXCEPT(CoreTools, MemberFunctionNoexceptMacro, NonConstCopyMemberFunction, string, void)