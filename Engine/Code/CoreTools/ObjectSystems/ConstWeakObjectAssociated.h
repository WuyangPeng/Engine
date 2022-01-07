///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/24 15:50)

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
            : object{ object }, associated{ associated }
        {
        }

        ConstObjectWeakPtr object;
        uint64_t associated;
    };
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_CONST_WEAK_OBJECT_ASSOCIATED_H
