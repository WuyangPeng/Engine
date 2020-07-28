// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.1 (2020/01/21 15:20)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_BUFFER_TARGET_DETAIL_H
#define CORE_TOOLS_OBJECT_SYSTEMS_BUFFER_TARGET_DETAIL_H

#include "BufferTarget.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/MemoryTools/SmartPointerManager.h"

#include "System/Helper/PragmaWarning/NumericCast.h"
#include <type_traits>

template <typename T>
void CoreTools::BufferTarget
	::Write(T datum)
{
	static_assert(std::is_arithmetic_v<T>, "T is not arithmetic");
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Target.Write(sizeof(T), &datum);
}

template <typename T>
void CoreTools::BufferTarget
	::WriteWithNumber(int elementsNumber, const T* data)
{
	static_assert(std::is_arithmetic_v<T>, "T is not arithmetic");
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	m_Target.Write(sizeof(int32_t), &elementsNumber);
	WriteWithoutNumber(elementsNumber, data);
}

template <typename T>
void CoreTools::BufferTarget
	::WriteWithoutNumber(int elementsNumber, const T* data)
{
	static_assert(std::is_arithmetic_v<T>, "T is not arithmetic");
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	if (0 < elementsNumber)
	{
		m_Target.Write(sizeof(T), elementsNumber, data);
	}
}

template <typename T>
void CoreTools::BufferTarget
	::Write(const std::vector<T>& datum)
{
	static_assert(std::is_arithmetic_v<T>, "T is not arithmetic");
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	auto elementsNumber = boost::numeric_cast<int>(datum.size());

	Write(elementsNumber);
	if (0 < elementsNumber)
	{
		WriteWithoutNumber(elementsNumber, datum.data());
	}
}

template <typename T>
void CoreTools::BufferTarget
	::WriteEnum(const T datum)
{
	static_assert(std::is_enum_v<T>, "T is not enum");
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	auto value = System::EnumCastUnderlying(datum);
	m_Target.Write(sizeof(T), &value);
}

template <typename T>
void CoreTools::BufferTarget
	::WriteEnumWithNumber(int elementsNumber, const T* data)
{
	static_assert(std::is_enum_v<T>, "T is not enum");
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	m_Target.Write(sizeof(int32_t), &elementsNumber);
	WriteEnumWithoutNumber(elementsNumber, data);
}

template <typename T>
void CoreTools::BufferTarget
	::WriteEnumWithoutNumber(int elementsNumber, const T* data)
{
	static_assert(std::is_enum_v<T>, "T is not enum");
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	for (auto i = 0; i < elementsNumber; ++i)
	{
		WriteEnum(data[i]);
	}
}

template <typename T>
void CoreTools::BufferTarget
	::WriteAggregate(const std::vector<T>& datum)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	auto size = boost::numeric_cast<int32_t>(datum.size());
	Write(size);

	if (0 < size)
	{
		WriteAggregateWithoutNumber(size, datum.data());
	}
}

template <typename T>
void CoreTools::BufferTarget
	::WriteAggregateWithNumber(int elementsNumber, const T* data)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	m_Target.Write(sizeof(int32_t), &elementsNumber);
	WriteAggregateWithoutNumber(elementsNumber, data);
}

template <typename T>
void CoreTools::BufferTarget
	::WriteAggregateWithoutNumber(int elementsNumber, const T* data)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	for (auto i = 0; i < elementsNumber; ++i)
	{
		WriteAggregate(data[i]);
	}
}

template <typename T>
void CoreTools::BufferTarget
	::WritePointer(const T* object)
{
	static_assert(std::is_base_of_v<ObjectInterface, T>, "T is not base of ObjectInterface");
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	if (object == nullptr)
	{
		Write(uint64_t{ 0 });
	}
	else if (SMART_POINTER_SINGLETON.IsSmartPointer(object))
	{
		WriteUniqueID(ConstObjectInterfaceSmartPointer{ object });
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("要写入的指针不是由SmartPointer系统创建。"s));
	}
}

template <typename T>
void CoreTools::BufferTarget
	::WritePointerWithNumber(int elementsNumber, T* const* objects)
{
	static_assert(std::is_base_of_v<ObjectInterface, T>, "T is not base of ObjectInterface");
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	m_Target.Write(sizeof(int32_t), &elementsNumber);
	WritePointerWithoutNumber(elementsNumber, objects);
}

template <typename T>
void CoreTools::BufferTarget
	::WritePointerWithoutNumber(int elementsNumber, T* const* objects)
{
	static_assert(std::is_base_of_v<ObjectInterface, T>, "T is not base of ObjectInterface");
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	for (auto i = 0; i < elementsNumber; ++i)
	{
		WritePointer(objects[i]);
	}
}

template <typename T>
void CoreTools::BufferTarget
	::WriteSmartPointer(const T& object)
{
	static_assert(std::is_base_of_v<ConstObjectInterfaceSmartPointer, T>, "T is not base of ConstObjectInterfaceSmartPointer");
	static_assert(std::is_base_of_v<ObjectInterface, T::SubclassType>, "T::SubclassType is not base of ObjectInterface");
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	WriteUniqueID(object);
}

template <typename T>
void CoreTools::BufferTarget
	::WriteSmartPointerWithNumber(int elementsNumber, const T* objects)
{
	static_assert(std::is_base_of_v<ConstObjectInterfaceSmartPointer, T>, "T is not base of ConstObjectInterfaceSmartPointer");
	static_assert(std::is_base_of_v<ObjectInterface, T::SubclassType>, "T::SubclassType is not base of ObjectInterface");
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	m_Target.Write(sizeof(int32_t), &elementsNumber);
	WriteSmartPointerWithoutNumber(elementsNumber, objects);
}

template <typename T>
void CoreTools::BufferTarget
	::WriteSmartPointerWithoutNumber(int elementsNumber, const T* objects)
{
	static_assert(std::is_base_of_v<ConstObjectInterfaceSmartPointer, T>, "T is not base of ConstObjectInterfaceSmartPointer");
	static_assert(std::is_base_of_v<ObjectInterface, T::SubclassType>, "T::SubclassType is not base of ObjectInterface");
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	for (auto i = 0; i < elementsNumber; ++i)
	{
		WriteSmartPointer(objects[i]);
	}
}

template <typename T>
void CoreTools::BufferTarget
	::WriteSmartPointer(const std::vector<T>& datum)
{
	static_assert(std::is_base_of_v<ConstObjectInterfaceSmartPointer, T>, "T is not base of ConstObjectInterfaceSmartPointer");
	static_assert(std::is_base_of_v<ObjectInterface, T::SubclassType>, "T::SubclassType is not base of ObjectInterface");
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	auto elementsNumber = boost::numeric_cast<int32_t>(datum.size());

	Write(elementsNumber);

	if (0 < elementsNumber)
	{
		WriteSmartPointerWithoutNumber(elementsNumber, datum.data());
	}
}

#endif // CORE_TOOLS_OBJECT_SYSTEMS_BUFFER_TARGET_DETAIL_H