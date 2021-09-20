//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.7.1.1 (2020/10/22 16:37)

#include "CoreTools/CoreToolsExport.h"

#include "ObjectLink.h"
#include "Detail/ObjectLinkImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::make_shared;

CoreTools::ObjectLink::ObjectLink([[maybe_unused]] DisableNotThrow disableNotThrow)
    : impl{ make_shared<ImplType>() }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, ObjectLink)

CoreTools::ObjectLink::ObjectLink(const ObjectLink& rhs)
    : impl{ std::make_shared<ImplType>(*rhs.impl) }
{
    IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;
}
CoreTools::ObjectLink& CoreTools::ObjectLink::operator=(const ObjectLink& rhs)
{
    IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;
    ObjectLink temp{ rhs };
    Swap(temp);
    return *this;
}
void CoreTools::ObjectLink::Swap(ObjectLink& rhs) noexcept
{
    
    std::swap(impl, rhs.impl);
}
CoreTools::ObjectLink::ObjectLink(ObjectLink&& rhs) noexcept
    : impl{ std::move(rhs.impl) }
{
    IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;
}
CoreTools::ObjectLink& CoreTools::ObjectLink::operator=(ObjectLink&& rhs) noexcept
{
    IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;
    impl = std::move(rhs.impl);
    return *this;
}

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
