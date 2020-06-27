// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/20 17:51)

#ifndef CORE_TOOLS_MEMORY_TOOLS_FIRST_SUBCLASS_SMART_POINTER_DETAIL_H
#define CORE_TOOLS_MEMORY_TOOLS_FIRST_SUBCLASS_SMART_POINTER_DETAIL_H

#include "FirstSubclassSmartPointer.h"
#include "SmartPointerManager.h"
#include "CoreTools/ObjectSystems/TypeCasting.h"
#include "CoreTools/Helper/MemoryMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h" 

#include "System/Helper/PragmaWarning/PolymorphicCast.h"

template <typename BaseClass>
CoreTools::FirstSubclassSmartPointer<BaseClass>
	::FirstSubclassSmartPointer(uint64_t address, BaseClassType* data)
	:ParentType{ address,data }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}
#include STSTEM_WARNING_PUSH

#include SYSTEM_WARNING_DISABLE(26434) 
template <typename BaseClass>
CoreTools::FirstSubclassSmartPointer<BaseClass>
	::FirstSubclassSmartPointer(BaseClassType* data)
	:ParentType{ data }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}


template <typename BaseClass>
CoreTools::FirstSubclassSmartPointer<BaseClass>
	::FirstSubclassSmartPointer() noexcept
	:ParentType{ }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}
#include STSTEM_WARNING_POP

#ifdef OPEN_CLASS_INVARIANT
template <typename BaseClass>
bool CoreTools::FirstSubclassSmartPointer<BaseClass>
	::IsValid() const noexcept
{
	if (ParentType::IsValid())
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

template <typename BaseClass>
const typename CoreTools::FirstSubclassSmartPointer<BaseClass>::BaseClassType* CoreTools::FirstSubclassSmartPointer<BaseClass>
	::GetData() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return ParentType::GetData();
}

template <typename BaseClass>
const typename CoreTools::FirstSubclassSmartPointer<BaseClass>::BaseClassType& CoreTools::FirstSubclassSmartPointer<BaseClass>
	::operator* () const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return *GetData();
}

template <typename BaseClass>
const typename CoreTools::FirstSubclassSmartPointer<BaseClass>::BaseClassType* CoreTools::FirstSubclassSmartPointer<BaseClass>
	::operator-> () const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return GetData();
}

template <typename BaseClass>
typename CoreTools::FirstSubclassSmartPointer<BaseClass>::BaseClassType* CoreTools::FirstSubclassSmartPointer<BaseClass>
	::GetData()  
{
	CORE_TOOLS_CLASS_IS_VALID_9;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26465) 
	return const_cast<BaseClassType*>(ParentType::GetData());
#include STSTEM_WARNING_POP
}

template <typename BaseClass>
typename CoreTools::FirstSubclassSmartPointer<BaseClass>::BaseClassType& CoreTools::FirstSubclassSmartPointer<BaseClass>
	::operator* ()
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	return *GetData();
}

template <typename BaseClass>
typename CoreTools::FirstSubclassSmartPointer<BaseClass>::BaseClassType* CoreTools::FirstSubclassSmartPointer<BaseClass>
	::operator-> ()
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	return GetData();
}

template <typename BaseClass>
template<typename SubclassSmartPointer>
SubclassSmartPointer CoreTools::FirstSubclassSmartPointer<BaseClass>
	::PolymorphicCastSmartPointer()
{
	static_assert(std::is_same_v<SubclassSmartPointer::IsNonConstType, CoreTools::TrueType>, "ptr is non_const_type");

	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return SubclassSmartPointer{ boost::polymorphic_cast<typename SubclassSmartPointer::SubclassType*>(GetData()) };
}

template <typename BaseClass>
template<typename SubclassSmartPointer>
SubclassSmartPointer CoreTools::FirstSubclassSmartPointer<BaseClass>
	::PolymorphicDowncastSmartPointer()
{
	static_assert(std::is_same_v<SubclassSmartPointer::IsNonConstType, CoreTools::TrueType>, "ptr is non_const_type");

	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return SubclassSmartPointer{ boost::polymorphic_downcast<typename SubclassSmartPointer::SubclassType*>(GetData()) };
}

template <typename BaseClass>
template<typename SubclassSmartPointer>
SubclassSmartPointer CoreTools::FirstSubclassSmartPointer<BaseClass>
	::PolymorphicCastObjectSmartPointer()
{
	static_assert(std::is_same_v<SubclassSmartPointer::IsNonConstType, CoreTools::TrueType>, "ptr is non_const_type");

	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return SubclassSmartPointer{ PolymorphicCast<typename SubclassSmartPointer::SubclassType>(GetData()) };
}

template <typename BaseClass>
template<typename SubclassSmartPointer>
SubclassSmartPointer CoreTools::FirstSubclassSmartPointer<BaseClass>
	::PolymorphicDowncastObjectSmartPointer()
{
	static_assert(std::is_same_v<SubclassSmartPointer::IsNonConstType, CoreTools::TrueType>, "ptr is non_const_type");

	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return SubclassSmartPointer{ PolymorphicDowncast<typename SubclassSmartPointer::SubclassType>(GetData()) };
}

template <typename BaseClass>
typename CoreTools::FirstSubclassSmartPointer<BaseClass>::ConstType CoreTools::FirstSubclassSmartPointer<BaseClass>
	::GetConstFirstSmartPointer() const
{
	static_assert(std::is_same_v<ParentType::IsConstType, CoreTools::TrueType>, "ConstFirstSubclassSmartPointer is const_type");

	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return ConstType{ GetData() };
}

template <typename BaseClass>
typename CoreTools::FirstSubclassSmartPointer<BaseClass>::ConstType CoreTools::FirstSubclassSmartPointer<BaseClass>
	::GetConstSmartPointer() const
{
	static_assert(std::is_same_v<ConstType::IsConstType, CoreTools::TrueType>, "ConstType is const_type");

	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return ConstType{ GetData() };
}

template <typename BaseClass>
CoreTools::FirstSubclassSmartPointer<BaseClass>
	::operator ConstType() const
{
	static_assert(std::is_same_v<ConstType::IsConstType, CoreTools::TrueType>, "ConstType is const_type");

	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return GetConstSmartPointer();
}

#endif // CORE_TOOLS_MEMORY_TOOLS_FIRST_SUBCLASS_SMART_POINTER_DETAIL_H
