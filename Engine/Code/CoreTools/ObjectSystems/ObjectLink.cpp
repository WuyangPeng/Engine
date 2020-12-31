//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/22 16:37)

#include "CoreTools/CoreToolsExport.h"

#include "ObjectLink.h"
#include "Detail/ObjectLinkImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::make_shared;

CoreTools::ObjectLink::ObjectLink([[maybe_unused]] DisableNotThrow disableNotThrow)
    : m_Impl{ make_shared<ImplType>() }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(CoreTools, ObjectLink)

COPY_CONSTRUCTION_DEFINE(CoreTools, ObjectLink);

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(CoreTools, ObjectLink, GetObjectInterface, uint64_t, CoreTools::ObjectInterfaceSharedPtr)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, ObjectLink, GetOrderedSize, int)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, ObjectLink, begin, CoreTools::ObjectLink::LinkSequentialContainerConstIter)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, ObjectLink, end, CoreTools::ObjectLink::LinkSequentialContainerConstIter)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, ObjectLink, begin, CoreTools::ObjectLink::LinkSequentialContainerIter)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, ObjectLink, end, CoreTools::ObjectLink::LinkSequentialContainerIter)

void CoreTools::ObjectLink::Insert(uint64_t uniqueID, const ObjectInterfaceSharedPtr& ptr)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    return m_Impl->Insert(uniqueID, ptr);
}

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, ObjectLink, Sort, void)
