///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.2.1 (2021/08/16 21:23)

#include "MemberFunctionMacro.h"
#include "MemberFunctionMacroImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::string;

CoreTools::MemberFunctionMacro::MemberFunctionMacro(MAYBE_UNUSED DisableNotThrow disableNotThrow)
    : impl{ ImplCreateUseDefaultConstruction::Default }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, MemberFunctionMacro)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, MemberFunctionMacro, ConstMemberFunction, string)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, MemberFunctionMacro, ConstMemberFunction, string, string)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(CoreTools, MemberFunctionMacro, ConstMemberFunction, int, string)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CP(CoreTools, MemberFunctionMacro, ConstMemberFunction, string, string)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, MemberFunctionMacro, NonConstCopyMemberFunction, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, MemberFunctionMacro, NonConstCopyMemberFunction, string, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(CoreTools, MemberFunctionMacro, NonConstCopyMemberFunction, int, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CP(CoreTools, MemberFunctionMacro, NonConstCopyMemberFunction, string, void)