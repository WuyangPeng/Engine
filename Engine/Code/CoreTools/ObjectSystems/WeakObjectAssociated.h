///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/20 15:28)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_WEAK_OBJECT_ASSOCIATED_H
#define CORE_TOOLS_OBJECT_SYSTEMS_WEAK_OBJECT_ASSOCIATED_H

#include "ObjectInterface.h"
#include "ObjectType.h"

namespace CoreTools
{
    template <typename T>
    struct WeakObjectAssociated final
    {
        static_assert(std::is_base_of_v<ObjectInterface, T>, "T is not base of ObjectInterface");

        using ClassType = WeakObjectAssociated<T>;
        using ObjectType = T;
        using ObjectWeakPtr = std::weak_ptr<T>;

        WeakObjectAssociated(ObjectWeakPtr object, const int64_t associated) noexcept
            : object{ std::move(object) }, associated{ associated }
        {
        }

        WeakObjectAssociated() noexcept
            : object{}, associated{ 0 }
        {
        }

        explicit WeakObjectAssociated(ObjectWeakPtr object) noexcept
            : object{ std::move(object) }, associated{ 0 }
        {
        }

        ObjectWeakPtr object;
        int64_t associated;
    };
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_WEAK_OBJECT_ASSOCIATED_H
