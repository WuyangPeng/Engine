//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/22 16:41)

#include "CoreTools/CoreToolsExport.h"

#include "OutTopLevel.h"
#include "Detail/OutTopLevelImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::make_shared;

CoreTools::OutTopLevel::OutTopLevel([[maybe_unused]] DisableNotThrow disableNotThrow)
    : m_Impl{ make_shared<ImplType>() }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

DELAY_COPY_CONSTRUCTION_DEFINE(CoreTools, OutTopLevel)

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(CoreTools, OutTopLevel)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, OutTopLevel, IsTopLevel, ConstObjectInterfaceSharedPtr, bool)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, OutTopLevel, GetTopLevelSize, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, OutTopLevel, begin, CoreTools::ConstObjectContainerConstIter)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, OutTopLevel, end, CoreTools::ConstObjectContainerConstIter)
IMPL_NON_CONST_COPY_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, OutTopLevel, Insert, ObjectInterfaceSharedPtr, void)
