// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/21 15:24)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_LINK_DETAIL_H
#define CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_LINK_DETAIL_H

#include "ObjectLink.h"
#include "TypeCasting.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

#include <type_traits>

template <typename T>
void CoreTools::ObjectLink
	::ResolveLink(T*& object)
{
	static_assert(std::is_base_of_v<ObjectInterface, T>, "T is not base of ObjectInterface");
	IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT;

	if (object != nullptr)
	{
		auto uniqueID = reinterpret_cast<size_t>(reinterpret_cast<void*>(object));
		if (uniqueID != 0)
		{
			object = GetObjectPtr(uniqueID).GetData();
		}
	}
}

template <typename T>
void CoreTools::ObjectLink
	::ResolveLink(int elementsNumber, T** object)
{
	static_assert(std::is_base_of_v<ObjectInterface, T>, "T is not base of ObjectInterface");
	IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT;

	for (auto i = 0; i < elementsNumber; ++i)
	{
		ResolveLink(object[i]);
	}
}

template <typename T>
void CoreTools::ObjectLink
	::ResolveObjectLink(T*& object)
{
	static_assert(std::is_base_of_v<ObjectInterface, T>, "T is not base of ObjectInterface");
	IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT;

	if (object != nullptr)
	{
		auto uniqueID = reinterpret_cast<size_t>(reinterpret_cast<void*>(object));
		if (uniqueID != 0)
		{
			object = PolymorphicCast<T>(GetObjectPtr(uniqueID).GetData());
		}
	}
}

template <typename T>
void CoreTools::ObjectLink
	::ResolveObjectLink(int elementsNumber, T** object)
{
	static_assert(std::is_base_of_v<ObjectInterface, T>, "T is not base of ObjectInterface");
	IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT;

	for (auto i = 0; i < elementsNumber; ++i)
	{
		ResolveObjectLink(object[i]);
	}
}

template <typename T>
void CoreTools::ObjectLink
	::ResolveObjectSmartPointerLink(T& object)
{
	static_assert(std::is_base_of_v<ConstObjectInterfaceSmartPointer, T>, "T is not base of ConstObjectInterfaceSmartPointer");
	IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT;

	auto uniqueID = object.GetAddress();
	if (uniqueID != 0)
	{
		object = GetObjectPtr(uniqueID).PolymorphicCastObjectSmartPointer<T>();
	}
}

template <typename T>
void CoreTools::ObjectLink
	::ResolveObjectSmartPointerLink(int elementsNumber, T* object)
{
	static_assert(std::is_base_of_v<ConstObjectInterfaceSmartPointer, T>, "T is not base of ConstObjectInterfaceSmartPointer");
	IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT;

	for (auto i = 0; i < elementsNumber; ++i)
	{
		ResolveObjectSmartPointerLink(object[i]);
	}
}

template <typename T>
void CoreTools::ObjectLink
	::ResolveObjectConstSmartPointerLink(T& object)
{
	static_assert(std::is_base_of_v<ConstObjectInterfaceSmartPointer, T>, "T is not base of ConstObjectInterfaceSmartPointer");
	IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT;

	auto uniqueID = object.GetAddress();
	if (uniqueID != 0)
	{
		object = GetObjectPtr(uniqueID).PolymorphicCastConstObjectSmartPointer<T>();
	}
}

template <typename T>
void CoreTools::ObjectLink
	::ResolveObjectConstSmartPointerLink(int elementsNumber, T* object)
{
	static_assert(std::is_base_of_v<ConstObjectInterfaceSmartPointer, T>, "T is not base of ConstObjectInterfaceSmartPointer");
	IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT;

	for (auto i = 0; i < elementsNumber; ++i)
	{
		ResolveObjectConstSmartPointerLink(object[i]);
	}
}

#endif // CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_LINK_DETAIL_H
