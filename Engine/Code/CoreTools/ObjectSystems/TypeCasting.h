//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.0.2 (2020/09/12 22:53)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_TYPE_CASTING_H
#define CORE_TOOLS_OBJECT_SYSTEMS_TYPE_CASTING_H

#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"

#include <memory>
#include <type_traits>

namespace CoreTools
{
    template <typename T>
    [[nodiscard]] std::shared_ptr<T> ObjectCast(const ObjectInterfaceSharedPtr& object)
    {
        static_assert(std::is_base_of_v<ObjectInterface, T>, "T is not base of ObjectInterface");

        if (object != nullptr && object->IsDerived(T::sm_Type))
        {
            CORE_TOOLS_ASSERTION_DEBUG(std::dynamic_pointer_cast<T>(object) == object, "向下转换类型失败！");

            return std::static_pointer_cast<T>(object);
        }
        else
        {
            THROW_EXCEPTION(SYSTEM_TEXT("向下转换类型失败！"s));
        }
    }

    template <typename T>
    [[nodiscard]] std::shared_ptr<const T> ObjectCast(const ConstObjectInterfaceSharedPtr& object)
    {
        static_assert(std::is_base_of_v<ObjectInterface, T>, "T is not base of ObjectInterface");

        if (object != nullptr && object->IsDerived(T::sm_Type))
        {
            CORE_TOOLS_ASSERTION_DEBUG(std::dynamic_pointer_cast<const T>(object) == object, "向下转换类型失败！");

            return std::static_pointer_cast<const T>(object);
        }
        else
        {
            THROW_EXCEPTION(SYSTEM_TEXT("向下转换类型失败！"s));
        }
    }

    template <typename T>
    [[nodiscard]] std::shared_ptr<T> ObjectDowncast(const ObjectInterfaceSharedPtr& object) noexcept(g_Assert < 0 || g_CoreToolsAssert < 0 || !g_AssertDebug)
    {
        static_assert(std::is_base_of_v<ObjectInterface, T>, "T is not base of ObjectInterface");

        CORE_TOOLS_ASSERTION_DEBUG(object != nullptr && object->IsDerived(T::sm_Type) && std::dynamic_pointer_cast<T>(object) == object, "向下转换类型失败！");

        return std::static_pointer_cast<T>(object);
    }

    template <typename T>
    [[nodiscard]] std::shared_ptr<const T> ObjectDowncast(const ConstObjectInterfaceSharedPtr& object) noexcept(g_Assert < 0 || g_CoreToolsAssert < 0 || !g_AssertDebug)
    {
        static_assert(std::is_base_of_v<ObjectInterface, T>, "T is not base of ObjectInterface");

        CORE_TOOLS_ASSERTION_DEBUG(object != nullptr && object->IsDerived(T::sm_Type) && std::dynamic_pointer_cast<const T>(object) == object, "向下转换类型失败！");

        return std::static_pointer_cast<const T>(object);
    }

    template <typename Subclass, typename Base>
    [[nodiscard]] std::shared_ptr<Subclass> PolymorphicObjectCast(const std::shared_ptr<Base>& object)
    {
        static_assert(std::is_base_of_v<ObjectInterface, Subclass>, "Subclass is not base of ObjectInterface");
        static_assert(std::is_base_of_v<ObjectInterface, Base>, "Base is not base of ObjectInterface");
        static_assert(std::is_base_of_v<Base, Subclass>, "Subclass is not base of Base");

        if (object != nullptr && object->IsDerived(Subclass::sm_Type))
        {
            CORE_TOOLS_ASSERTION_DEBUG(std::dynamic_pointer_cast<Subclass>(object) == object, "向下转换类型失败！");

            return std::static_pointer_cast<Subclass>(object);
        }
        else
        {
            THROW_EXCEPTION(SYSTEM_TEXT("向下转换类型失败！"s));
        }
    }

    template <typename Subclass, typename Base>
    [[nodiscard]] std::shared_ptr<const Subclass> PolymorphicObjectCast(const std::shared_ptr<const Base>& object) 
    {
        static_assert(std::is_base_of_v<ObjectInterface, Subclass>, "Subclass is not base of ObjectInterface");
        static_assert(std::is_base_of_v<ObjectInterface, Base>, "Base is not base of ObjectInterface");
        static_assert(std::is_base_of_v<Base, Subclass>, "Subclass is not base of Base");

        if (object != nullptr && object->IsDerived(Subclass::sm_Type))
        {
            CORE_TOOLS_ASSERTION_DEBUG(std::dynamic_pointer_cast<const Subclass>(object) == object, "向下转换类型失败！");

            return std::static_pointer_cast<const Subclass>(object);
        }
        else
        {
            THROW_EXCEPTION(SYSTEM_TEXT("向下转换类型失败！"s));
        }
    }

    template <typename Subclass, typename Base>
    [[nodiscard]] std::shared_ptr<Subclass> PolymorphicObjectDowncast(const std::shared_ptr<Base>& object) noexcept(g_Assert < 0 || g_CoreToolsAssert < 0 || !g_AssertDebug)
    {
        static_assert(std::is_base_of_v<ObjectInterface, Subclass>, "Subclass is not base of ObjectInterface");
        static_assert(std::is_base_of_v<ObjectInterface, Base>, "Base is not base of ObjectInterface");
        static_assert(std::is_base_of_v<Base, Subclass>, "Subclass is not base of Base");

        CORE_TOOLS_ASSERTION_DEBUG(object != nullptr && object->IsDerived(Subclass::sm_Type) && std::dynamic_pointer_cast<Subclass>(object) == object, "向下转换类型失败！");

        return std::static_pointer_cast<Subclass>(object);
    }

    template <typename Subclass, typename Base>
    [[nodiscard]] std::shared_ptr<const Subclass> PolymorphicObjectDowncast(const std::shared_ptr<const Base>& object) noexcept(g_Assert < 0 || g_CoreToolsAssert < 0 || !g_AssertDebug)
    {
        static_assert(std::is_base_of_v<ObjectInterface, Subclass>, "Subclass is not base of ObjectInterface");
        static_assert(std::is_base_of_v<ObjectInterface, Base>, "Base is not base of ObjectInterface");
        static_assert(std::is_base_of_v<Base, Subclass>, "Subclass is not base of Base");

        CORE_TOOLS_ASSERTION_DEBUG(object != nullptr && object->IsDerived(Subclass::sm_Type) && std::dynamic_pointer_cast<const Subclass>(object) == object, "向下转换类型失败！");

        return std::static_pointer_cast<const Subclass>(object);
    }
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_TYPE_CASTING_H
