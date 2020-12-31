//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/22 15:09)

#include "CoreTools/CoreToolsExport.h"

#include "InTopLevel.h"
#include "Detail/InTopLevelImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::make_shared;

CoreTools::InTopLevel::InTopLevel([[maybe_unused]] DisableNotThrow disableNotThrow)
    : m_Impl{ make_shared<ImplType>() }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

DELAY_COPY_CONSTRUCTION_DEFINE(CoreTools, InTopLevel)

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(CoreTools, InTopLevel)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, InTopLevel, IsTopLevel, ObjectInterfaceSharedPtr, bool)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, InTopLevel, GetTopLevelSize, int)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, InTopLevel, begin, CoreTools::ObjectContainerConstIter)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, InTopLevel, end, CoreTools::ObjectContainerConstIter)
IMPL_NON_CONST_COPY_MEMBER_FUNCTION_DEFINE_0(CoreTools, InTopLevel, begin, CoreTools::ObjectContainerIter)
IMPL_NON_CONST_COPY_MEMBER_FUNCTION_DEFINE_0(CoreTools, InTopLevel, end, CoreTools::ObjectContainerIter)

IMPL_NON_CONST_COPY_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, InTopLevel, Insert, ObjectInterfaceSharedPtr, void)
