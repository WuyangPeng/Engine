// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.1 (2020/01/20 16:41)

#ifndef CORE_TOOLS_MEMORY_TOOLS_FIRST_SUBCLASS_SMART_POINTER_H
#define CORE_TOOLS_MEMORY_TOOLS_FIRST_SUBCLASS_SMART_POINTER_H

#include "ConstFirstSubclassSmartPointer.h"

namespace CoreTools
{
	template <typename BaseClass>
	class FirstSubclassSmartPointer : public ConstFirstSubclassSmartPointer<BaseClass>
	{
	public:
		using BaseClassType = typename ConstFirstSubclassSmartPointer<BaseClass>::BaseClassType;
		using ClassType = FirstSubclassSmartPointer<BaseClassType>;
		using ParentType = ConstFirstSubclassSmartPointer<BaseClassType>;
		using ConstType = ConstFirstSubclassSmartPointer<BaseClassType>;
		using IsConstType = FalseType;
		using IsNonConstType = TrueType;

	public:
		explicit FirstSubclassSmartPointer(uint64_t address, BaseClassType* data = nullptr);
		explicit FirstSubclassSmartPointer(BaseClassType* data) ;
		FirstSubclassSmartPointer() noexcept;

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;
		 
		virtual BaseClassType* GetData();
		virtual BaseClassType& operator* ();
		virtual BaseClassType* operator-> ();

		const BaseClassType* GetData() const override;
		const BaseClassType& operator* () const override;
		const BaseClassType* operator-> () const override;

		// 向下转型，失败抛出异常。
		template<typename SubclassSmartPointer>
		SubclassSmartPointer PolymorphicCastSmartPointer();

		// 向下转型，必须保证转型成功。
		template<typename SubclassSmartPointer>
		SubclassSmartPointer PolymorphicDowncastSmartPointer();

		// 向下转型，失败抛出异常。
		template<typename SubclassSmartPointer>
		SubclassSmartPointer PolymorphicCastObjectSmartPointer();

		// 向下转型，必须保证转型成功。
		template<typename SubclassSmartPointer>
		SubclassSmartPointer PolymorphicDowncastObjectSmartPointer();

		ConstType GetConstFirstSmartPointer() const;

		ConstType GetConstSmartPointer() const;

		operator ConstType () const;
	};
}

#endif // CORE_TOOLS_MEMORY_TOOLS_FIRST_SUBCLASS_SMART_POINTER_H
