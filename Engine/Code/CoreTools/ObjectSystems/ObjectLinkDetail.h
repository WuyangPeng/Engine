// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/21 15:24)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_LINK_DETAIL_H
#define CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_LINK_DETAIL_H

#include "ObjectLink.h"
 
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/MemoryTools/FirstSubclassSmartPointer.h"
#include "System/Helper/PragmaWarning/PolymorphicCast.h"
#include <type_traits>
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)
#include SYSTEM_WARNING_DISABLE(26486)
#include SYSTEM_WARNING_DISABLE(26487)
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
			object = boost::polymorphic_cast<T>(GetObjectPtr(uniqueID).GetData());
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
	static_assert(std::is_base_of_v<ConstObjectInterfaceSharedPtr, T>, "T is not base of ConstObjectInterfaceSmartPointer");
	IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT;

	const auto uniqueID = object.GetAddress();
	if (uniqueID != 0)
	{
		object = GetObjectPtr(uniqueID).PolymorphicCastObjectSmartPointer<T>();
	}
}

template <typename T>
void CoreTools::ObjectLink
	::ResolveObjectSmartPointerLink(int elementsNumber, T* object)
{
	static_assert(std::is_base_of_v<ConstObjectInterfaceSharedPtr, T>, "T is not base of ConstObjectInterfaceSmartPointer");
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
	static_assert(std::is_base_of_v<ConstObjectInterfaceSharedPtr, T>, "T is not base of ConstObjectInterfaceSmartPointer");
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
	static_assert(std::is_base_of_v<ConstObjectInterfaceSharedPtr, T>, "T is not base of ConstObjectInterfaceSmartPointer");
	IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT;

	for (auto i = 0; i < elementsNumber; ++i)
	{
		ResolveObjectConstSmartPointerLink(object[i]);
	}
}
#include STSTEM_WARNING_POP
#endif // CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_LINK_DETAIL_H
