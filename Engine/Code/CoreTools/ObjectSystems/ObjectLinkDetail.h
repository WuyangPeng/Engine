/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/11 21:59)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_LINK_DETAIL_H
#define CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_LINK_DETAIL_H

#include "ObjectLink.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

#include <type_traits>

template <typename T>
requires(std::is_base_of_v<CoreTools::ObjectInterface, typename T::ObjectType>)
void CoreTools::ObjectLink::ResolveLink(T& object)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    if (object.associated != 0)
    {
        object.object = boost::polymorphic_pointer_cast<typename T::ObjectType>(GetObjectInterface(object.associated));
    }
}

template <typename T>
requires(std::is_base_of_v<CoreTools::ObjectInterface, typename T::value_type::ObjectType>)
void CoreTools::ObjectLink::ResolveLinkContainer(T& object)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    for (auto& element : object)
    {
        ResolveLink(element);
    }
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_LINK_DETAIL_H
