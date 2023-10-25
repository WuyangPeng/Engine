///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/20 15:47)

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

CoreTools::ObjectInterfaceSharedPtr CoreTools::ObjectLink::GetObjectInterface(int64_t uniqueId)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->GetObjectInterface(uniqueId);
}

int CoreTools::ObjectLink::GetOrderedSize() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetOrderedSize();
}

void CoreTools::ObjectLink::Sort()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->Sort();
}

CoreTools::ObjectLink::LinkSequentialContainerConstIter CoreTools::ObjectLink::begin() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->begin();
}

CoreTools::ObjectLink::LinkSequentialContainerConstIter CoreTools::ObjectLink::end() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->end();
}

CoreTools::ObjectLink::LinkSequentialContainerIter CoreTools::ObjectLink::begin() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->begin();
}

CoreTools::ObjectLink::LinkSequentialContainerIter CoreTools::ObjectLink::end() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->end();
}

void CoreTools::ObjectLink::Insert(int64_t uniqueId, const ObjectInterfaceSharedPtr& ptr)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->Insert(uniqueId, ptr);
}
