///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/03/30 17:15)

#include "CoreTools/CoreToolsExport.h"

#include "ObjectLink.h"
#include "Detail/ObjectLinkImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

CoreTools::ObjectLink::ObjectLinkSharedPtr CoreTools::ObjectLink::Create()
{
    return std::make_shared<ClassType>(ObjectLinkInit::Default);
}

COPY_UNSHARED_CLONE_SELF_DEFINE(CoreTools, ObjectLink)

CoreTools::ObjectLink::ObjectLink(ObjectLinkInit objectLinkInit)
    : impl{ ImplCreateUseDefaultConstruction::Default }
{
    System::UnusedFunction(objectLinkInit);

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, ObjectLink)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(CoreTools, ObjectLink, GetObjectInterface, uint64_t, CoreTools::ObjectInterfaceSharedPtr)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, ObjectLink, GetOrderedSize, int)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, ObjectLink, begin, CoreTools::ObjectLink::LinkSequentialContainerConstIter)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, ObjectLink, end, CoreTools::ObjectLink::LinkSequentialContainerConstIter)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, ObjectLink, begin, CoreTools::ObjectLink::LinkSequentialContainerIter)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, ObjectLink, end, CoreTools::ObjectLink::LinkSequentialContainerIter)

void CoreTools::ObjectLink::Insert(uint64_t uniqueId, const ObjectInterfaceSharedPtr& ptr)
{
    return impl->Insert(uniqueId, ptr);
}

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, ObjectLink, Sort, void)
