// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/21 11:55)

#ifndef CORE_TOOLS_MEMORY_TOOLS_SMART_POINTER_4D_ARRAY_DETAIL_H
#define CORE_TOOLS_MEMORY_TOOLS_SMART_POINTER_4D_ARRAY_DETAIL_H

#include "SmartPointer4DArray.h"
#include "SmartPointerManager.h"
#include "CoreTools/Helper/MemoryMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

template <typename T>
CoreTools::SmartPointer4DArray<T>
	::SmartPointer4DArray(T**** data)
	:m_Data{ data }
{
	SMART_POINTER_SINGLETON.IncreaseReference(m_Data);

	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

template <typename T>
CoreTools::SmartPointer4DArray<T>
	::~SmartPointer4DArray()
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;

	auto reference = SMART_POINTER_SINGLETON.DecreaseReference(m_Data);

	if (reference == 0)
	{
		DELETE4(m_Data);
	}
}

template <typename T>
CoreTools::SmartPointer4DArray<T>
	::SmartPointer4DArray(const ClassType& rhs)
	:m_Data{ rhs.m_Data }
{
	SMART_POINTER_SINGLETON.CopyIncreaseReference(m_Data);

	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

template <typename T>
CoreTools::SmartPointer4DArray<T>& CoreTools::SmartPointer4DArray<T>
	::operator=(const ClassType& rhs)
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	ClassType temp{ rhs };
	Swap(temp);

	return *this;
}

template <typename T>
CoreTools::SmartPointer4DArray<T>& CoreTools::SmartPointer4DArray<T>
	::operator=(T**** data)
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	ClassType temp{ data };
	Swap(temp);

	return *this;
}

// private
template <typename T>
void CoreTools::SmartPointer4DArray<T>
	::Swap(ClassType& rhs) noexcept
{
	std::swap(m_Data, rhs.m_Data);
}

#ifdef OPEN_CLASS_INVARIANT
template <typename T>
bool CoreTools::SmartPointer4DArray<T>
	::IsValid() const noexcept
{
	return true;
}
#endif // OPEN_CLASS_INVARIANT

template <typename T>
T**** const CoreTools::SmartPointer4DArray<T>
	::GetData() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return m_Data;
}

template <typename T>
CoreTools::SmartPointer4DArray<T>
	::operator T**** const() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return GetData();
}

template <typename T>
T*** const& CoreTools::SmartPointer4DArray<T>
	::operator* () const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return *GetData();
}

template <typename T>
T**** CoreTools::SmartPointer4DArray<T>
	::GetData() noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	return NON_CONST_MEMBER_CALL_CONST_MEMBER(T****, GetData);
}

template <typename T>
CoreTools::SmartPointer4DArray<T>
	::operator T****()  noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	return GetData();
}

template <typename T>
T***& CoreTools::SmartPointer4DArray<T>
	::operator* () noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	return *GetData();
}

template <typename T>
bool CoreTools
	::operator==(const SmartPointer4DArray<T>& lhs, T**** data) noexcept
{
	if (lhs.GetData() == data)
		return true;
	else
		return false;
}

template <typename T>
bool CoreTools
	::operator==(const SmartPointer4DArray<T>& lhs, const SmartPointer4DArray<T>& rhs) noexcept
{
	return lhs.GetData() == rhs.GetData();
}

#endif // CORE_TOOLS_MEMORY_TOOLS_SMART_POINTER_4D_ARRAY_DETAIL_H
