// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/21 11:09)

#ifndef CORE_TOOLS_MEMORY_TOOLS_SECOND_SUBCLASS_SMART_POINTER_DETAIL_H
#define CORE_TOOLS_MEMORY_TOOLS_SECOND_SUBCLASS_SMART_POINTER_DETAIL_H

#include "SecondSubclassSmartPointer.h"
#include "SmartPointerManager.h"
#include "CoreTools/Helper/MemoryMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

#include "System/Helper/PragmaWarning/PolymorphicCast.h"
#include STSTEM_WARNING_PUSH

#include SYSTEM_WARNING_DISABLE(26434)
template <typename SubClass, typename BaseClass>
CoreTools::SecondSubclassSmartPointer<SubClass, BaseClass>
	::SecondSubclassSmartPointer(uint64_t address, SubclassType* data)
	:ParentType{ address,data }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}
  
template <typename SubClass, typename BaseClass>
CoreTools::SecondSubclassSmartPointer<SubClass, BaseClass>
	::SecondSubclassSmartPointer(SubclassType* data)  
	:ParentType{ data }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
} 
#include STSTEM_WARNING_POP

#include STSTEM_WARNING_PUSH

#include SYSTEM_WARNING_DISABLE(26434)  
template <typename SubClass, typename BaseClass>
CoreTools::SecondSubclassSmartPointer<SubClass, BaseClass>
	::SecondSubclassSmartPointer() noexcept
	:ParentType{   }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}
#include STSTEM_WARNING_POP


#ifdef OPEN_CLASS_INVARIANT
template <typename SubClass, typename BaseClass>
bool CoreTools::SecondSubclassSmartPointer<SubClass, BaseClass>
	::IsValid() const noexcept
{
	if (ParentType::IsValid())
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

template <typename SubClass, typename BaseClass>
const typename CoreTools::SecondSubclassSmartPointer<SubClass, BaseClass>::SubclassType* CoreTools::SecondSubclassSmartPointer<SubClass, BaseClass>
	::GetData() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return boost::polymorphic_downcast<const SubclassType*>(ParentType::GetData());
}

template <typename SubClass, typename BaseClass>
const typename CoreTools::SecondSubclassSmartPointer<SubClass, BaseClass>::SubclassType& CoreTools::SecondSubclassSmartPointer<SubClass, BaseClass>
	::operator* () const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return *GetData();
}

template <typename SubClass, typename BaseClass>
const typename CoreTools::SecondSubclassSmartPointer<SubClass, BaseClass>::SubclassType* CoreTools::SecondSubclassSmartPointer<SubClass, BaseClass>
	::operator-> () const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return GetData();
}

template <typename SubClass, typename BaseClass>
typename CoreTools::SecondSubclassSmartPointer<SubClass, BaseClass>::SubclassType* CoreTools::SecondSubclassSmartPointer<SubClass, BaseClass>
	::GetData()
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	return boost::polymorphic_downcast<SubclassType*>(ParentType::GetData());
}

template <typename SubClass, typename BaseClass>
typename CoreTools::SecondSubclassSmartPointer<SubClass, BaseClass>::SubclassType& CoreTools::SecondSubclassSmartPointer<SubClass, BaseClass>
	::operator* ()
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	return *GetData();
}

template <typename SubClass, typename BaseClass>
typename CoreTools::SecondSubclassSmartPointer<SubClass, BaseClass>::SubclassType* CoreTools::SecondSubclassSmartPointer<SubClass, BaseClass>
	::operator-> ()
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	return GetData();
}

template <typename SubClass, typename BaseClass>
typename CoreTools::SecondSubclassSmartPointer<SubClass, BaseClass>::ConstType CoreTools::SecondSubclassSmartPointer<SubClass, BaseClass>
	::GetConstSmartPointer() const
{
	static_assert(std::is_same_v<ConstType::IsConstType, CoreTools::TrueType>, "ConstType is const_type");

	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return ConstType{ GetData() };
}

template <typename SubClass, typename BaseClass>
CoreTools::SecondSubclassSmartPointer<SubClass, BaseClass>
	::operator ConstType() const
{
	static_assert(std::is_same_v<ConstType::IsConstType, CoreTools::TrueType>, "ConstType is const_type");

	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return GetConstSmartPointer();
}

#endif // CORE_TOOLS_MEMORY_TOOLS_SECOND_SUBCLASS_SMART_POINTER_DETAIL_H
