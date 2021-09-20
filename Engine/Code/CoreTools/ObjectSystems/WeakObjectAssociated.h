//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.7.1.1 (2020/10/22 11:37)

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

        WeakObjectAssociated(const ObjectWeakPtr& object, uint64_t associated) noexcept
            : m_Object{ object }, m_Associated{ associated }
        {
        }

        ObjectWeakPtr m_Object;
        uint64_t m_Associated;
    };
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_WEAK_OBJECT_ASSOCIATED_H
