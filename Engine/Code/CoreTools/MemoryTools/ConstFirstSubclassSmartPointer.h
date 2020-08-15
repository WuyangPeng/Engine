// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/20 16:40)

#ifndef CORE_TOOLS_MEMORY_TOOLS_CONST_FIRST_SUBCLASS_SMART_POINTER_H
#define CORE_TOOLS_MEMORY_TOOLS_CONST_FIRST_SUBCLASS_SMART_POINTER_H

#include "CoreTools/CoreToolsDll.h"

#include "SubclassSmartPointerTraits.h"
#include "CoreTools/ImplHelper/ImplStaticAssertHelper.h"

#include "System/Helper/PragmaWarning/Operators.h"
#include <iosfwd>

namespace CoreTools
{
	template <typename BaseClass>
	class ConstFirstSubclassSmartPointer : private boost::equality_comparable<ConstFirstSubclassSmartPointer<BaseClass>,
												   boost::equality_comparable<ConstFirstSubclassSmartPointer<BaseClass>, BaseClass*> >
	{
	public:
		using BaseClassType = BaseClass;
		using ClassType = ConstFirstSubclassSmartPointer<BaseClassType>;
		using IsConstType = TrueType;
		using IsNonConstType = FalseType;
		using SubclassType = BaseClassType;

	public:
		explicit ConstFirstSubclassSmartPointer(uint64_t address, const BaseClassType* data = nullptr);
		explicit ConstFirstSubclassSmartPointer(const BaseClassType* data);
		ConstFirstSubclassSmartPointer() noexcept;
		virtual ~ConstFirstSubclassSmartPointer();

		ConstFirstSubclassSmartPointer(const ConstFirstSubclassSmartPointer& rhs);
		ConstFirstSubclassSmartPointer& operator= (const ConstFirstSubclassSmartPointer& rhs);

		ConstFirstSubclassSmartPointer(ConstFirstSubclassSmartPointer&& rhs) noexcept;
		ConstFirstSubclassSmartPointer& operator= (ConstFirstSubclassSmartPointer&& rhs)noexcept;

		CLASS_INVARIANT_VIRTUAL_DECLARE;

		virtual const BaseClassType* GetData() const;
		virtual const BaseClassType& operator* () const;
		virtual const BaseClassType* operator-> () const;

		void Reset(const BaseClassType* data = nullptr);

		// ����ת�ͣ�ʧ���׳��쳣��
		template<typename ConstSubclassSmartPointer>
		ConstSubclassSmartPointer PolymorphicCastConstSmartPointer() const;

		// ����ת�ͣ����뱣֤ת�ͳɹ���
		template<typename ConstSubclassSmartPointer>
		ConstSubclassSmartPointer PolymorphicDowncastConstSmartPointer() const;

		// Object������ת�ͣ�ʧ���׳��쳣��
		template<typename ConstSubclassSmartPointer>
		ConstSubclassSmartPointer PolymorphicCastConstObjectSmartPointer() const;

		// Object������ת�ͣ����뱣֤ת�ͳɹ���
		template<typename ConstSubclassSmartPointer>
		ConstSubclassSmartPointer PolymorphicDowncastConstObjectSmartPointer() const;

		uint64_t GetAddress() const noexcept;
		bool IsNullPtr() const noexcept;
		bool IsValidPtr() const noexcept;

	private:
		void Swap(ClassType& rhs) noexcept;

	private:
		BaseClassType* m_Data;
		uint64_t m_Address;
	};

	template <typename BaseClass>
	bool operator== (const ConstFirstSubclassSmartPointer<BaseClass>& lhs, BaseClass* data);

	template <typename BaseClass>
	bool operator== (const ConstFirstSubclassSmartPointer<BaseClass>& lhs, const ConstFirstSubclassSmartPointer<BaseClass>& rhs);

	template <typename BaseClass>
	bool operator< (const ConstFirstSubclassSmartPointer<BaseClass>& lhs, const ConstFirstSubclassSmartPointer<BaseClass>& rhs) noexcept;

	template <typename BaseClass>
	std::ostream& operator<<(std::ostream& os, const ConstFirstSubclassSmartPointer<BaseClass>& rhs);
}

#endif // CORE_TOOLS_MEMORY_TOOLS_CONST_FIRST_SUBCLASS_SMART_POINTER_H
