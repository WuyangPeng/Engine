// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/20 16:41)

#ifndef CORE_TOOLS_MEMORY_TOOLS_CONST_SECOND_SUBCLASS_SMART_POINTER_H
#define CORE_TOOLS_MEMORY_TOOLS_CONST_SECOND_SUBCLASS_SMART_POINTER_H

#include "SubclassSmartPointerTraits.h"
#include "ConstFirstSubclassSmartPointer.h"

#include <type_traits>

namespace CoreTools
{
	template <typename SubClass, typename BaseClass = typename SubclassSmartPointerTraits<SubClass>::ParentType>
	class ConstSecondSubclassSmartPointer : public ConstFirstSubclassSmartPointer<BaseClass>
	{
	public:
		using SubclassType = SubClass;
		using BaseClassType = BaseClass;
		static_assert(std::is_base_of_v<BaseClassType, SubclassType>, "BaseClass is the base class of SubClass");

		using ClassType = ConstSecondSubclassSmartPointer<SubclassType, BaseClassType>;
		using ParentType = ConstFirstSubclassSmartPointer<BaseClassType>;

	public:
		explicit ConstSecondSubclassSmartPointer(uint64_t address, const SubclassType* data = nullptr);
		explicit ConstSecondSubclassSmartPointer(const SubclassType* data);
		ConstSecondSubclassSmartPointer() noexcept;

		CLASS_INVARIANT_OVERRIDE_DECLARE;

		const SubclassType* GetData() const override;
		const SubclassType& operator* () const override;
		const SubclassType* operator-> () const override;
	};
}

#endif // CORE_TOOLS_MEMORY_TOOLS_CONST_SECOND_SUBCLASS_SMART_POINTER_H
