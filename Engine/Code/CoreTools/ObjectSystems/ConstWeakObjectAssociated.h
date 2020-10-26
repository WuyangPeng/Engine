//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/21 20:13)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_CONST_WEAK_OBJECT_ASSOCIATED_H
#define CORE_TOOLS_OBJECT_SYSTEMS_CONST_WEAK_OBJECT_ASSOCIATED_H

#include "ObjectInterface.h"
#include "ObjectType.h"

namespace CoreTools
{
    template <typename T>
    struct ConstWeakObjectAssociated final
    {
        static_assert(std::is_base_of_v<ObjectInterface, T>, "T is not base of ObjectInterface");

        using ClassType = ConstWeakObjectAssociated<T>;
        using ObjectType = T;
        using ConstObjectWeakPtr = std::weak_ptr<const T>;

        ConstWeakObjectAssociated(const ConstObjectWeakPtr& object, uint64_t associated) noexcept
            : m_Object{ object }, m_Associated{ associated }
        {
        }

        ConstObjectWeakPtr m_Object;
        uint64_t m_Associated;
    };
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_CONST_WEAK_OBJECT_ASSOCIATED_H
