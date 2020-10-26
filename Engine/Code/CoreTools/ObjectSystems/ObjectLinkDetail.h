//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/22 13:35)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_LINK_DETAIL_H
#define CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_LINK_DETAIL_H

#include "ObjectLink.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

#include <type_traits>

template <typename T>
void CoreTools::ObjectLink::ResolveLink(T& object)
{
    static_assert(std::is_base_of_v<ObjectInterface, T::ObjectType>, "T::ObjectType is not base of ObjectInterface");

    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    if (object.m_Associated != 0)
    {
        object.m_Object = boost::polymorphic_pointer_cast<T::ObjectType>(GetObjectInterface(object.m_Associated));
    }
}

template <typename T>
void CoreTools::ObjectLink::ResolveLinkContainer(T& object)
{
    using ValueType = typename T::value_type;

    static_assert(std::is_base_of_v<ObjectInterface, ValueType::ObjectType>, "ValueType::ObjectType is not base of ObjectInterface");

    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    for (auto& value : object)
    {
        ResolveLink(value);
    }
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_LINK_DETAIL_H
