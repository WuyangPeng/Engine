// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/21 11:55)

#ifndef CORE_TOOLS_MEMORY_TOOLS_SMART_POINTER_SINGLE_DETAIL_H
#define CORE_TOOLS_MEMORY_TOOLS_SMART_POINTER_SINGLE_DETAIL_H

#include "SmartPointerSingle.h"
#include "SmartPointerManager.h"
#include "CoreTools/Helper/MemoryMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

template <typename T>
CoreTools::SmartPointerSingle<T>
	::SmartPointerSingle(T* data)
	:m_Data{ data }
{
	SMART_POINTER_SINGLETON.IncreaseReference(m_Data);

	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

template <typename T>
CoreTools::SmartPointerSingle<T>
	::~SmartPointerSingle()
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;

	auto reference = SMART_POINTER_SINGLETON.DecreaseReference(m_Data);

	if (reference == 0)
	{
		DELETE0(m_Data);
	}
}

template <typename T>
CoreTools::SmartPointerSingle<T>
	::SmartPointerSingle(const ClassType& rhs)
	:m_Data{ rhs.m_Data }
{
	SMART_POINTER_SINGLETON.CopyIncreaseReference(m_Data);

	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

template <typename T>
CoreTools::SmartPointerSingle<T>& CoreTools::SmartPointerSingle<T>
	::operator=(const ClassType& rhs)
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	ClassType temp{ rhs };
	Swap(temp);

	return *this;
}

template <typename T>
CoreTools::SmartPointerSingle<T>& CoreTools::SmartPointerSingle<T>
	::operator=(T* data)
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	ClassType temp{ data };
	Swap(temp);

	return *this;
}

// private
template <typename T>
void CoreTools::SmartPointerSingle<T>
	::Swap(ClassType& rhs) noexcept
{
	std::swap(m_Data, rhs.m_Data);
}

#ifdef OPEN_CLASS_INVARIANT
template <typename T>
bool CoreTools::SmartPointerSingle<T>
	::IsValid() const noexcept
{
	return true;
}
#endif // OPEN_CLASS_INVARIANT

template <typename T>
const T* CoreTools::SmartPointerSingle<T>
	::GetData() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return m_Data;
}

template <typename T>
CoreTools::SmartPointerSingle<T>
	::operator const T*() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return GetData();
}

template <typename T>
const T& CoreTools::SmartPointerSingle<T>
	::operator* () const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return *GetData();
}

template <typename T>
const T* CoreTools::SmartPointerSingle<T>
	::operator-> () const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return GetData();
}

template <typename T>
T* CoreTools::SmartPointerSingle<T>
	::GetData() noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	return NON_CONST_MEMBER_CALL_CONST_MEMBER(T*, GetData);
}

template <typename T>
CoreTools::SmartPointerSingle<T>
	::operator T*()  noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	return GetData();
}

template <typename T>
T& CoreTools::SmartPointerSingle<T>
	::operator* () noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	return *GetData();
}

template <typename T>
T* CoreTools::SmartPointerSingle<T>
	::operator-> ()  noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	return GetData();
}

template <typename T>
bool CoreTools
	::operator==(const SmartPointerSingle<T>& lhs, T* data) noexcept
{
	if (lhs.GetData() == data)
		return true;
	else
		return false;
}

template <typename T>
bool CoreTools
	::operator==(const SmartPointerSingle<T>& lhs, const SmartPointerSingle<T>& rhs) noexcept
{
	return lhs.GetData() == rhs.GetData();
}

#endif // CORE_TOOLS_MEMORY_TOOLS_SMART_POINTER_SINGLE_DETAIL_H
