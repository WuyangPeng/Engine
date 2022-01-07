///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/24 17:21)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_ASSOCIATED_H
#define CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_ASSOCIATED_H

#include "ObjectInterface.h"
#include "ObjectType.h"

namespace CoreTools
{
    template <typename T>
    struct ObjectAssociated final
    {
        static_assert(std::is_base_of_v<ObjectInterface, T>, "T is not base of ObjectInterface");

        using ClassType = ObjectAssociated<T>;
        using ObjectType = T;
        using ObjectSharedPtr = std::shared_ptr<T>;

        ObjectAssociated(const ObjectSharedPtr& object, uint64_t associated) noexcept
            : object{ object }, associated{ associated }
        {
        }

        ObjectSharedPtr object;
        uint64_t associated;
    };
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_ASSOCIATED_H
