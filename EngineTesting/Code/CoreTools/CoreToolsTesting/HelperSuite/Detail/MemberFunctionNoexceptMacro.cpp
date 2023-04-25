///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.6 (2023/04/11 21:03)

#include "MemberFunctionNoexceptMacro.h"
#include "MemberFunctionNoexceptMacroImpl.h"
#include "System/Helper/Tools.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::MemberFunctionNoexceptMacro CoreTools::MemberFunctionNoexceptMacro::Create()
{
    return MemberFunctionNoexceptMacro{ DisableNotThrow::Disable };
}

CoreTools::MemberFunctionNoexceptMacro::MemberFunctionNoexceptMacro(DisableNotThrow disableNotThrow)
    : impl{ ImplCreateUseDefaultConstruction::Default }
{
    System::UnusedFunction(disableNotThrow);

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, MemberFunctionNoexceptMacro)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, MemberFunctionNoexceptMacro, ConstMemberFunction, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR_NOEXCEPT(CoreTools, MemberFunctionNoexceptMacro, ConstMemberFunction, std::string, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(CoreTools, MemberFunctionNoexceptMacro, ConstMemberFunction, int, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CP_NOEXCEPT(CoreTools, MemberFunctionNoexceptMacro, ConstMemberFunction, std::string, void)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, MemberFunctionNoexceptMacro, NonConstCopyMemberFunction, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR_NOEXCEPT(CoreTools, MemberFunctionNoexceptMacro, NonConstCopyMemberFunction, std::string, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(CoreTools, MemberFunctionNoexceptMacro, NonConstCopyMemberFunction, int, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CP_NOEXCEPT(CoreTools, MemberFunctionNoexceptMacro, NonConstCopyMemberFunction, std::string, void)
