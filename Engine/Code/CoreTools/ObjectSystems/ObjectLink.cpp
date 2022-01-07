///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/24 23:11)

#include "CoreTools/CoreToolsExport.h"

#include "ObjectLink.h"
#include "Detail/ObjectLinkImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::make_shared;

CoreTools::ObjectLink::ObjectLinkSharedPtr CoreTools::ObjectLink::Create()
{
    return make_shared<ClassType>(ObjectLinkInit::Default);
}

COPY_UNSHARED_CLONE_SELF_DEFINE(CoreTools, ObjectLink)

CoreTools::ObjectLink::ObjectLink(MAYBE_UNUSED ObjectLinkInit objectLinkInit)
    : impl{ ImplCreateUseDefaultConstruction::Default }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, ObjectLink)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(CoreTools, ObjectLink, GetObjectInterface, uint64_t, CoreTools::ObjectInterfaceSharedPtr)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, ObjectLink, GetOrderedSize, int)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, ObjectLink, begin, CoreTools::ObjectLink::LinkSequentialContainerConstIter)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, ObjectLink, end, CoreTools::ObjectLink::LinkSequentialContainerConstIter)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, ObjectLink, begin, CoreTools::ObjectLink::LinkSequentialContainerIter)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, ObjectLink, end, CoreTools::ObjectLink::LinkSequentialContainerIter)

void CoreTools::ObjectLink::Insert(uint64_t uniqueID, const ObjectInterfaceSharedPtr& ptr)
{
    return impl->Insert(uniqueID, ptr);
}

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, ObjectLink, Sort, void)
