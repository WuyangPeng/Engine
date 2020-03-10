// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/20 16:55)

#ifndef CORE_TOOLS_MEMORY_TOOLS_CONST_FIRST_SUBCLASS_SMART_POINTER_DETAIL_H
#define CORE_TOOLS_MEMORY_TOOLS_CONST_FIRST_SUBCLASS_SMART_POINTER_DETAIL_H

#include "ConstFirstSubclassSmartPointer.h"
#include "SmartPointerManager.h"
#include "CoreTools/ObjectSystems/TypeCasting.h"
#include "CoreTools/Helper/MemoryMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

#include <boost/polymorphic_cast.hpp>

template <typename BaseClass>
CoreTools::ConstFirstSubclassSmartPointer<BaseClass>
	::ConstFirstSubclassSmartPointer(uint64_t address, const BaseClassType* data)
	:m_Data{ const_cast<BaseClass*>(data) }, m_Address{ address }
{
	if (m_Data != nullptr)
	{
		SMART_POINTER_SINGLETON.IncreaseReference(m_Data);
	}

	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

template <typename BaseClass>
CoreTools::ConstFirstSubclassSmartPointer<BaseClass>
	::ConstFirstSubclassSmartPointer(const BaseClassType* data)
	:m_Data{ const_cast<BaseClassType*>(data) }, m_Address{ reinterpret_cast<size_t>(m_Data) }
{
	if (m_Data != nullptr)
	{
		SMART_POINTER_SINGLETON.IncreaseReference(m_Data);
	}

	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

template <typename BaseClass>
CoreTools::ConstFirstSubclassSmartPointer<BaseClass>
	::~ConstFirstSubclassSmartPointer()
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;

	if (m_Data != nullptr)
	{
		auto reference = SMART_POINTER_SINGLETON.DecreaseReference(m_Data);

		if (reference == 0)
		{
			DELETE0(m_Data);
		}
	}
}

template <typename BaseClass>
CoreTools::ConstFirstSubclassSmartPointer<BaseClass>
	::ConstFirstSubclassSmartPointer(const ClassType& rhs)
	:m_Data{ rhs.m_Data }, m_Address{ rhs.m_Address }
{
	SMART_POINTER_SINGLETON.CopyIncreaseReference(m_Data);

	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

template <typename BaseClass>
CoreTools::ConstFirstSubclassSmartPointer<BaseClass>& CoreTools::ConstFirstSubclassSmartPointer<BaseClass>
	::operator=(const ClassType& rhs)
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	ClassType temp{ rhs };
	Swap(temp);

	return *this;
}

template <typename BaseClass>
void CoreTools::ConstFirstSubclassSmartPointer<BaseClass>
	::Reset(const BaseClassType* data)
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	ClassType temp{ data };
	Swap(temp);
}

// private
template <typename BaseClass>
void CoreTools::ConstFirstSubclassSmartPointer<BaseClass>
	::Swap(ClassType& rhs) noexcept
{
	std::swap(m_Data, rhs.m_Data);
	std::swap(m_Address, rhs.m_Address);
}

#ifdef OPEN_CLASS_INVARIANT
template <typename BaseClass>
bool CoreTools::ConstFirstSubclassSmartPointer<BaseClass>
	::IsValid() const noexcept
{
	return true;
}
#endif // OPEN_CLASS_INVARIANT

template <typename BaseClass>
const typename CoreTools::ConstFirstSubclassSmartPointer<BaseClass>::BaseClassType* CoreTools::ConstFirstSubclassSmartPointer<BaseClass>
	::GetData() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return m_Data;
}

template <typename BaseClass>
const typename CoreTools::ConstFirstSubclassSmartPointer<BaseClass>::BaseClassType& CoreTools::ConstFirstSubclassSmartPointer<BaseClass>
	::operator* () const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return *GetData();
}

template <typename BaseClass>
const typename CoreTools::ConstFirstSubclassSmartPointer<BaseClass>::BaseClassType* CoreTools::ConstFirstSubclassSmartPointer<BaseClass>
	::operator-> () const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return GetData();
}

template <typename BaseClass>
uint64_t CoreTools::ConstFirstSubclassSmartPointer<BaseClass>
	::GetAddress() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return m_Address;
}

template <typename BaseClass>
template<typename ConstSubclassSmartPointer>
ConstSubclassSmartPointer CoreTools::ConstFirstSubclassSmartPointer<BaseClass>
	::PolymorphicCastConstSmartPointer() const
{
	static_assert(std::is_same_v<ConstSubclassSmartPointer::IsConstType, CoreTools::TrueType>, "ptr is const_type");

	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return ConstSubclassSmartPointer{ boost::polymorphic_cast<const ConstSubclassSmartPointer::SubclassType*>(m_Data) };
}

template <typename BaseClass>
template<typename ConstSubclassSmartPointer>
ConstSubclassSmartPointer CoreTools::ConstFirstSubclassSmartPointer<BaseClass>
	::PolymorphicDowncastConstSmartPointer() const
{
	static_assert(std::is_same_v<ConstSubclassSmartPointer::IsConstType, CoreTools::TrueType>, "ptr is const_type");

	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return ConstSubclassSmartPointer{ boost::polymorphic_downcast<const ConstSubclassSmartPointer::SubclassType*>(m_Data) };
}

template <typename BaseClass>
template<typename ConstSubclassSmartPointer>
ConstSubclassSmartPointer CoreTools::ConstFirstSubclassSmartPointer<BaseClass>
	::PolymorphicCastConstObjectSmartPointer() const
{
	static_assert(std::is_same_v<ConstSubclassSmartPointer::IsConstType, CoreTools::TrueType>, "ptr is const_type");

	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return ConstSubclassSmartPointer{ PolymorphicCast<ConstSubclassSmartPointer::SubclassType>(m_Data) };
}

template <typename BaseClass>
template<typename ConstSubclassSmartPointer>
ConstSubclassSmartPointer CoreTools::ConstFirstSubclassSmartPointer<BaseClass>
	::PolymorphicDowncastConstObjectSmartPointer() const
{
	static_assert(std::is_same_v<ConstSubclassSmartPointer::IsConstType, CoreTools::TrueType>, "ptr is const_type");

	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return ConstSubclassSmartPointer{ PolymorphicDowncast<ConstSubclassSmartPointer::SubclassType>(m_Data) };
}

template <typename BaseClass>
bool CoreTools::ConstFirstSubclassSmartPointer<BaseClass>
	::IsNullPtr() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return !IsValidPtr();
}

template <typename BaseClass>
bool CoreTools::ConstFirstSubclassSmartPointer<BaseClass>
	::IsValidPtr() const  noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return m_Data != nullptr;
}

template <typename BaseClass>
bool CoreTools
	::operator==(const ConstFirstSubclassSmartPointer<BaseClass>& lhs, BaseClass* data)
{
	if (lhs.GetData() == data)
		return true;
	else
		return false;
}

template <typename BaseClass>
bool CoreTools
	::operator<(const ConstFirstSubclassSmartPointer<BaseClass>& lhs, const ConstFirstSubclassSmartPointer<BaseClass>& rhs)
{
	return lhs.GetAddress() < rhs.GetAddress();
}

template <typename BaseClass>
bool CoreTools
	::operator==(const ConstFirstSubclassSmartPointer<BaseClass>& lhs, const ConstFirstSubclassSmartPointer<BaseClass>& rhs)
{
	return lhs.GetData() == rhs.GetData();
}

template <typename BaseClass>
std::ostream& CoreTools
	::operator<<(std::ostream& os, const ConstFirstSubclassSmartPointer<BaseClass>& rhs)
{
	os << "◊”¿‡÷«ƒ‹÷∏’Î" << rhs.GetAddress();

	return os;
}

#endif // CORE_TOOLS_MEMORY_TOOLS_CONST_FIRST_SUBCLASS_SMART_POINTER_DETAIL_H
