// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/21 15:26)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_REGISTER_DETAIL_H
#define CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_REGISTER_DETAIL_H

#include "ObjectRegister.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

#include <type_traits>
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)
#include SYSTEM_WARNING_DISABLE(26486)
template <typename T>
void CoreTools::ObjectRegister
	::Register(const T* object)
{
	static_assert(std::is_base_of_v<ObjectInterface, T>, "T is not base of ObjectInterface");

	IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT;

	if (object != nullptr)
	{
		object->Register(*this);
	}
}

template <typename T>
void CoreTools::ObjectRegister
	::Register(int elementsNumber, T* const* objects)
{
	static_assert(std::is_base_of_v<ObjectInterface, T>, "T is not base of ObjectInterface");

	IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT;

	for (auto i = 0; i < elementsNumber; ++i)
	{
		Register(objects[i]);
	}
}

template <typename T>
void CoreTools::ObjectRegister
	::RegisterSmartPointer(const T& object)
{
	static_assert(std::is_base_of_v<ConstObjectInterfaceSmartPointer, T>, "T is not base of ConstObjectInterfaceSmartPointer");

	IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT;

	if (object != nullptr)
	{
		object->Register(*this);
	}
}

template <typename T>
void CoreTools::ObjectRegister
	::RegisterSmartPointer(int elementsNumber, const T* objects)
{
	static_assert(std::is_base_of_v<ConstObjectInterfaceSmartPointer, T>, "T is not base of ConstObjectInterfaceSmartPointer");

	IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT;

	for (auto i = 0; i < elementsNumber; ++i)
	{
		RegisterSmartPointer(objects[i]);
	}
}
#include STSTEM_WARNING_POP
#endif // CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_REGISTER_DETAIL_H