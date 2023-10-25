///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/20 15:12)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_LINK_DETAIL_H
#define CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_LINK_DETAIL_H

#include "ObjectLink.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h" 
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

#include <type_traits>

template <typename T>
void CoreTools::ObjectLink::ResolveLink(T& object)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    static_assert(std::is_base_of_v<ObjectInterface, typename T::ObjectType>, "T::ObjectType is not base of ObjectInterface");

    if (object.associated != 0)
    {
        object.object = boost::polymorphic_pointer_cast<T::ObjectType>(GetObjectInterface(object.associated));
    }
}

template <typename T>
void CoreTools::ObjectLink::ResolveLinkContainer(T& object)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    using ValueType = typename T::value_type;
    static_assert(std::is_base_of_v<ObjectInterface, typename ValueType::ObjectType>, "ValueType::ObjectType is not base of ObjectInterface");

    for (auto& value : object)
    {
        ResolveLink(value);
    }
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_LINK_DETAIL_H
