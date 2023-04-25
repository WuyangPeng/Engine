///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.6 (2023/04/11 21:03)

#include "MemberFunctionMacro.h"
#include "MemberFunctionMacroImpl.h"
#include "System/Helper/Tools.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::MemberFunctionMacro CoreTools::MemberFunctionMacro::Create()
{
    return MemberFunctionMacro{ DisableNotThrow::Disable };
}

CoreTools::MemberFunctionMacro::MemberFunctionMacro(DisableNotThrow disableNotThrow)
    : impl{ ImplCreateUseDefaultConstruction::Default }
{
    System::UnusedFunction(disableNotThrow);

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, MemberFunctionMacro)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, MemberFunctionMacro, ConstMemberFunction, std::string)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, MemberFunctionMacro, ConstMemberFunction, std::string, std::string)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(CoreTools, MemberFunctionMacro, ConstMemberFunction, int, std::string)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CP(CoreTools, MemberFunctionMacro, ConstMemberFunction, std::string, std::string)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, MemberFunctionMacro, NonConstCopyMemberFunction, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, MemberFunctionMacro, NonConstCopyMemberFunction, std::string, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(CoreTools, MemberFunctionMacro, NonConstCopyMemberFunction, int, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CP(CoreTools, MemberFunctionMacro, NonConstCopyMemberFunction, std::string, void)
