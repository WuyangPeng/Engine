// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/21 11:56)

#ifndef CORE_TOOLS_MEMORY_TOOLS_SUBCLASS_WEAK_POINTER_DETAIL_H
#define CORE_TOOLS_MEMORY_TOOLS_SUBCLASS_WEAK_POINTER_DETAIL_H

#include "SubclassWeakPointer.h"
#include "SmartPointerManager.h"
#include "CoreTools/Helper/MemoryMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

template <typename SubclassSmartPointer>
CoreTools::SubclassWeakPointer<SubclassSmartPointer>
	::SubclassWeakPointer(SubclassSmartPointer data)
	:m_Data{ data.GetData() }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

template <typename SubclassSmartPointer>
void CoreTools::SubclassWeakPointer<SubclassSmartPointer>
	::Reset(SubclassSmartPointer data)
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	m_Data = data.GetData();
}

#ifdef OPEN_CLASS_INVARIANT
template <typename SubclassSmartPointer>
bool CoreTools::SubclassWeakPointer<SubclassSmartPointer>
	::IsValid() const noexcept
{
	return true;
}
#endif // OPEN_CLASS_INVARIANT

template <typename SubclassSmartPointer>
bool CoreTools::SubclassWeakPointer<SubclassSmartPointer>
	::IsNullPtr() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return m_Data == nullptr;
}

template <typename SubclassSmartPointer>
bool CoreTools::SubclassWeakPointer<SubclassSmartPointer>
	::IsValidPtr() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return !IsNullPtr();
}

template <typename SubclassSmartPointer>
typename const CoreTools::SubclassWeakPointer<SubclassSmartPointer>::SubclassSmartPointerConstType CoreTools::SubclassWeakPointer<SubclassSmartPointer>
	::GetConstSmartPointer() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	if (SMART_POINTER_SINGLETON.IsSmartPointer(m_Data))
	{
		return (typename SubclassSmartPointer::ConstType{ m_Data });
	}
	else
	{
		return (typename SubclassSmartPointer::ConstType{});
	}
}

template <typename SubclassSmartPointer>
const SubclassSmartPointer CoreTools::SubclassWeakPointer<SubclassSmartPointer>
	::GetSmartPointer() const
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	if (SMART_POINTER_SINGLETON.IsSmartPointer(m_Data))
	{
		return SubclassSmartPointer{ m_Data };
	}
	else
	{
		return SubclassSmartPointer{};
	}
}

template <typename SubclassSmartPointer>
bool CoreTools
	::operator==(const SubclassWeakPointer<SubclassSmartPointer>& lhs, typename SubclassSmartPointer::BaseClassType* data)
{
	auto lhsSmartPointer = lhs.GetConstSmartPointer();

	return lhsSmartPointer == data;
}

template <typename SubclassSmartPointer>
bool CoreTools
	::operator==(const SubclassWeakPointer<SubclassSmartPointer>& lhs, const SubclassWeakPointer<SubclassSmartPointer>& rhs)
{
	auto lhsSmartPointer = lhs.GetConstSmartPointer();
	auto rhsSmartPointer = rhs.GetConstSmartPointer();

	return lhsSmartPointer == rhsSmartPointer;
}

template <typename SubclassSmartPointer>
bool CoreTools
	::operator<(const SubclassWeakPointer<SubclassSmartPointer>& lhs, const SubclassWeakPointer<SubclassSmartPointer>& rhs)
{
	auto lhsSmartPointer = lhs.GetConstSmartPointer();
	auto rhsSmartPointer = rhs.GetConstSmartPointer();

	return lhsSmartPointer < rhsSmartPointer;
}

template <typename SubclassSmartPointer>
std::ostream& CoreTools
	::operator<<(std::ostream& os, const SubclassWeakPointer<SubclassSmartPointer>& rhs)
{
	os << "»ı◊”¿‡÷«ƒ‹÷∏’Î" << rhs.GetConstSmartPointer();

	return os;
}

#endif // CORE_TOOLS_MEMORY_TOOLS_SUBCLASS_WEAK_POINTER_DETAIL_H
