/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 09:55)

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

        ConstWeakObjectAssociated() noexcept
            : object{}, associated{ 0 }
        {
        }

        ConstWeakObjectAssociated(ConstObjectWeakPtr object, int64_t associated) noexcept
            : object{ std::move(object) }, associated{ associated }
        {
        }

        explicit ConstWeakObjectAssociated(ConstObjectWeakPtr object) noexcept
            : object{ std::move(object) }, associated{ 0 }
        {
        }

        ConstObjectWeakPtr object;
        int64_t associated;
    };
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_CONST_WEAK_OBJECT_ASSOCIATED_H
