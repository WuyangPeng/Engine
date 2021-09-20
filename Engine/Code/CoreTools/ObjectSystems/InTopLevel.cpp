//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.7.1.1 (2020/10/22 15:09)

#include "CoreTools/CoreToolsExport.h"

#include "../Contract/Flags/ImplFlags.h"
#include "InTopLevel.h"
#include "Detail/InTopLevelImpl.h"

#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
using std::make_shared;

CoreTools::InTopLevel::InTopLevel([[maybe_unused]] DisableNotThrow disableNotThrow)
    : impl{ ImplCreateUseDefaultConstruction::Default }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, InTopLevel)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, InTopLevel, IsTopLevel, ObjectInterfaceSharedPtr, bool)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, InTopLevel, GetTopLevelSize, int)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, InTopLevel, begin, CoreTools::ObjectContainerConstIter)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, InTopLevel, end, CoreTools::ObjectContainerConstIter)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, InTopLevel, begin, CoreTools::ObjectContainerIter)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, InTopLevel, end, CoreTools::ObjectContainerIter)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, InTopLevel, Insert, ObjectInterfaceSharedPtr, void)

COPY_UNSHARED_CLONE_SELF_DEFINE(CoreTools, InTopLevel)