// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/20 17:01)

#ifndef CORE_TOOLS_MEMORY_TOOLS_CONST_SECOND_SUBCLASS_SMART_POINTER_DETAIL_H
#define CORE_TOOLS_MEMORY_TOOLS_CONST_SECOND_SUBCLASS_SMART_POINTER_DETAIL_H

#include "ConstSecondSubclassSmartPointer.h"
#include "SmartPointerManager.h"
#include "CoreTools/Helper/MemoryMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

#include <boost/polymorphic_cast.hpp>

template <typename SubClass, typename BaseClass>
CoreTools::ConstSecondSubclassSmartPointer<SubClass, BaseClass>
	::ConstSecondSubclassSmartPointer(uint64_t address, const SubclassType* data)
	:ParentType{ address,data }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

template <typename SubClass, typename BaseClass>
CoreTools::ConstSecondSubclassSmartPointer<SubClass, BaseClass>
	::ConstSecondSubclassSmartPointer(const SubclassType* data)
	:ParentType{ data }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

template <typename SubClass, typename BaseClass>
CoreTools::ConstSecondSubclassSmartPointer<SubClass, BaseClass>
	::~ConstSecondSubclassSmartPointer()
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename SubClass, typename BaseClass>
bool CoreTools::ConstSecondSubclassSmartPointer<SubClass, BaseClass>
	::IsValid() const noexcept
{
	if (ParentType::IsValid())
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

template <typename SubClass, typename BaseClass>
const typename CoreTools::ConstSecondSubclassSmartPointer<SubClass, BaseClass>::SubclassType* CoreTools::ConstSecondSubclassSmartPointer<SubClass, BaseClass>
	::GetData() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return boost::polymorphic_downcast<const SubclassType*>(ParentType::GetData());
}

template <typename SubClass, typename BaseClass>
const typename CoreTools::ConstSecondSubclassSmartPointer<SubClass, BaseClass>::SubclassType& CoreTools::ConstSecondSubclassSmartPointer<SubClass, BaseClass>
	::operator* () const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return *GetData();
}

template <typename SubClass, typename BaseClass>
const typename CoreTools::ConstSecondSubclassSmartPointer<SubClass, BaseClass>::SubclassType* CoreTools::ConstSecondSubclassSmartPointer<SubClass, BaseClass>
	::operator-> () const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return GetData();
}

#endif // CORE_TOOLS_MEMORY_TOOLS_CONST_SECOND_SUBCLASS_SMART_POINTER_DETAIL_H
