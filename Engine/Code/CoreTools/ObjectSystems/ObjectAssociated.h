/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/11 22:15)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_ASSOCIATED_H
#define CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_ASSOCIATED_H

#include "CoreTools/CoreToolsDll.h"

#include "ObjectInterface.h"
#include "ObjectType.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"

namespace CoreTools
{
    template <typename T>
    requires(std::is_base_of_v<ObjectInterface, T>)
    struct ObjectAssociated final
    {
        using ClassType = ObjectAssociated<T>;
        using ObjectType = T;
        using ObjectSharedPtr = std::shared_ptr<T>;

        ObjectAssociated() noexcept
            : object{ nullptr }, associated{ 0 }
        {
        }

        explicit ObjectAssociated(int64_t associated) noexcept
            : object{ nullptr }, associated{ associated }
        {
        }

        ObjectAssociated(ObjectSharedPtr object, const int64_t associated) noexcept
            : object{ std::move(object) }, associated{ associated }
        {
        }

        explicit ObjectAssociated(ObjectSharedPtr object) noexcept
            : object{ std::move(object) }, associated{ 0 }
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

        NODISCARD ObjectSharedPtr Clone() const
        {
            if (object != nullptr)
                return boost::polymorphic_pointer_cast<T>(object->CloneObject());
            else
                return object;
        }

        ObjectSharedPtr object;
        int64_t associated;
    };
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_ASSOCIATED_H
