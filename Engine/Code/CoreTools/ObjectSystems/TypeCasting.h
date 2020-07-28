// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.1 (2020/01/21 15:41)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_TYPE_CASTING_H
#define CORE_TOOLS_OBJECT_SYSTEMS_TYPE_CASTING_H

#include "CoreTools/ObjectSystems/ObjectInterface.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"

#include <type_traits>
#include <memory>

namespace CoreTools
{
	// 静态和动态类型转换。

	template <typename T>
	T* StaticCast(ObjectPtr object) noexcept
	{
		static_assert(std::is_base_of_v<ObjectInterface, T>, "T is not base of ObjectInterface");

		
#include STSTEM_WARNING_PUSH
	
		#include SYSTEM_WARNING_DISABLE(26466)
		return static_cast<T*>(object);
		#include STSTEM_WARNING_POP
	}

	template <typename T>
	const T* StaticCast(ConstObjectPtr object)
	{
		static_assert(std::is_base_of_v<ObjectInterface, T>, "T is not base of ObjectInterface");

		return static_cast<const T*>(object);
	}

	template <typename T>
	T* DynamicCast(ObjectPtr object)
	{
		static_assert(std::is_base_of_v<ObjectInterface, T>, "T is not base of ObjectInterface");

		return (object != nullptr && object->IsDerived(T::sm_Type)) ? StaticCast<T>(object) : nullptr;
	}

	template <typename T>
	const T* DynamicCast(ConstObjectPtr object)
	{
		static_assert(std::is_base_of_v<ObjectInterface, T>, "T is not base of ObjectInterface");

		return (object != nullptr &&  object->IsDerived(T::sm_Type)) ? StaticCast<T>(object) : nullptr;
	}

	template <typename Target>
	Target* PolymorphicCast(ObjectPtr object)
	{
		static_assert(std::is_base_of_v<ObjectInterface, Target>, "T is not base of ObjectInterface");

		auto target = DynamicCast<Target>(object);
		if (target == nullptr)
		{
			THROW_EXCEPTION(SYSTEM_TEXT("向下转换类型失败！"s));
		}

		return target;
	}

	template <typename Target>
	const Target* PolymorphicCast(ConstObjectPtr object)
	{
		static_assert(std::is_base_of_v<ObjectInterface, Target>, "T is not base of ObjectInterface");

		auto target = DynamicCast<Target>(object);
		if (target == nullptr)
		{
			THROW_EXCEPTION(SYSTEM_TEXT("向下转换类型失败！"));
		}

		return target;
	}

	template <typename Target>
	Target* PolymorphicDowncast(ObjectPtr object) noexcept((0 <= CORE_TOOLS_ASSERT_LEVEL) && !g_AssertDebug)
	{
		static_assert(std::is_base_of_v<ObjectInterface, Target>, "T is not base of ObjectInterface");

		CORE_TOOLS_ASSERTION_DEBUG(DynamicCast<Target>(object) == object, "向下转换类型失败！");

		return StaticCast<Target>(object);
	}

	template <typename Target>
	const Target* PolymorphicDowncast(ConstObjectPtr object)
	{
		static_assert(std::is_base_of_v<ObjectInterface, Target>, "T is not base of ObjectInterface");

		CORE_TOOLS_ASSERTION_DEBUG(DynamicCast<Target>(object) == object, "向下转换类型失败！");

		return StaticCast<Target>(object);
	}

	template <typename Subclass, typename Base>
	std::shared_ptr<Subclass> PolymorphicSharedPtrCast(const std::shared_ptr<Base>& ptr)
	{
		auto subclass = std::dynamic_pointer_cast<Subclass>(ptr);

		if (!subclass)
		{
			THROW_EXCEPTION(SYSTEM_TEXT("向下转换类型失败！"s));
		}

		return subclass;
	}

	template <typename Subclass, typename Base>
	std::shared_ptr<Subclass> PolymorphicSharedPtrDowncast(const std::shared_ptr<Base>& ptr)
	{
		CORE_TOOLS_ASSERTION_DEBUG(std::dynamic_pointer_cast<Subclass>(ptr) == ptr, "向下转换类型失败！");

		return std::static_pointer_cast<Subclass>(ptr);
	}
}

#endif // CORE_TOOLS_OBJECT_SYSTEMS_TYPE_CASTING_H
