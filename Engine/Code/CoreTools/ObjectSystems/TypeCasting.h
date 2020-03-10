// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/21 15:41)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_TYPE_CASTING_H
#define CORE_TOOLS_OBJECT_SYSTEMS_TYPE_CASTING_H

#include "CoreTools/ObjectSystems/ObjectInterface.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"

#include <type_traits>
#include <memory>

namespace CoreTools
{
	// ��̬�Ͷ�̬����ת����

	template <typename T>
	T* StaticCast(ObjectPtr object)
	{
		static_assert(std::is_base_of_v<ObjectInterface, T>, "T is not base of ObjectInterface");

		return static_cast<T*>(object);
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
			THROW_EXCEPTION(SYSTEM_TEXT("����ת������ʧ�ܣ�"));
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
			THROW_EXCEPTION(SYSTEM_TEXT("����ת������ʧ�ܣ�"));
		}

		return target;
	}

	template <typename Target>
	Target* PolymorphicDowncast(ObjectPtr object)
	{
		static_assert(std::is_base_of_v<ObjectInterface, Target>, "T is not base of ObjectInterface");

		CORE_TOOLS_ASSERTION_0(DynamicCast<Target>(object) == object, "����ת������ʧ�ܣ�");

		return StaticCast<Target>(object);
	}

	template <typename Target>
	const Target* PolymorphicDowncast(ConstObjectPtr object)
	{
		static_assert(std::is_base_of_v<ObjectInterface, Target>, "T is not base of ObjectInterface");

		CORE_TOOLS_ASSERTION_0(DynamicCast<Target>(object) == object, "����ת������ʧ�ܣ�");

		return StaticCast<Target>(object);
	}

	template <typename Subclass, typename Base>
	std::shared_ptr<Subclass> PolymorphicSharedPtrCast(const std::shared_ptr<Base>& ptr)
	{
		auto subclass = std::dynamic_pointer_cast<Subclass>(ptr);

		if (!subclass)
		{
			THROW_EXCEPTION(SYSTEM_TEXT("����ת������ʧ�ܣ�"));
		}

		return subclass;
	}

	template <typename Subclass, typename Base>
	std::shared_ptr<Subclass> PolymorphicSharedPtrDowncast(const std::shared_ptr<Base>& ptr)
	{
		CORE_TOOLS_ASSERTION_0(std::dynamic_pointer_cast<Subclass>(ptr) == ptr, "����ת������ʧ�ܣ�");

		return std::static_pointer_cast<Subclass>(ptr);
	}
}

#endif // CORE_TOOLS_OBJECT_SYSTEMS_TYPE_CASTING_H
