///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.5 (2023/03/29 16:35)

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

        ObjectAssociated() noexcept
            : object{ nullptr }, associated{ 0 }
        {
        }

        ObjectAssociated(const ObjectSharedPtr& object, const int64_t associated) noexcept
            : object{ object }, associated{ associated }
        {
        }

        explicit ObjectAssociated(const ObjectSharedPtr& object) noexcept
            : object{ object }, associated{ 0 }
        {
        }

        NODISCARD T& operator*() noexcept
        {
            return *object;
        }

        NODISCARD const T& operator*() const noexcept
        {
            return *object;
        }

        NODISCARD T* operator->() noexcept
        {
            return object.get();
        }

        NODISCARD const T* operator->() const noexcept
        {
            return object.get();
        }

        ObjectSharedPtr object;
        int64_t associated;
    };
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_ASSOCIATED_H
