// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/20 16:42)

#ifndef CORE_TOOLS_MEMORY_TOOLS_SECOND_SUBCLASS_SMART_POINTER_H
#define CORE_TOOLS_MEMORY_TOOLS_SECOND_SUBCLASS_SMART_POINTER_H

#include "SubclassSmartPointerTraits.h"
#include "FirstSubclassSmartPointer.h"
#include "ConstSecondSubclassSmartPointer.h"

#include <type_traits>

namespace CoreTools
{
	template <typename SubClass, typename BaseClass = typename SubclassSmartPointerTraits<SubClass>::ParentType>
	class SecondSubclassSmartPointer : public FirstSubclassSmartPointer<BaseClass>
	{
	public:
		using SubclassType = SubClass;
		using BaseClassType = BaseClass;
		static_assert(std::is_base_of_v<BaseClassType, SubclassType>, "BaseClass is the base class of SubClass");

		using ClassType = SecondSubclassSmartPointer<SubclassType, BaseClassType>;
		using ParentType = FirstSubclassSmartPointer<BaseClassType>;
		using ConstType = ConstSecondSubclassSmartPointer<SubclassType, BaseClassType>;

	public:
		explicit SecondSubclassSmartPointer(uint64_t address, SubclassType* data = nullptr);
		explicit SecondSubclassSmartPointer(SubclassType* data);
		SecondSubclassSmartPointer() noexcept;

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		SubclassType* GetData() override;
		SubclassType& operator* () override;
		SubclassType* operator-> () override;

		const SubclassType* GetData() const override;
		const SubclassType& operator* () const override;
		const SubclassType* operator-> () const override;

		ConstType GetConstSmartPointer() const;

		operator ConstType () const;
	};
}

#endif // CORE_TOOLS_MEMORY_TOOLS_SECOND_SUBCLASS_SMART_POINTER_H
