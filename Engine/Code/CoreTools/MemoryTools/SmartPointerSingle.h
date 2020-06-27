// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/20 16:43)

#ifndef CORE_TOOLS_MEMORY_TOOLS_SMART_POINTER_SINGLE_H
#define CORE_TOOLS_MEMORY_TOOLS_SMART_POINTER_SINGLE_H

#include "System/Helper/PragmaWarning/Operators.h"

namespace CoreTools
{
	template <typename T>
	class SmartPointerSingle : private boost::equality_comparable<SmartPointerSingle<T>,
									   boost::equality_comparable<SmartPointerSingle<T>, T*>>
	{
	public:
		using ClassType = SmartPointerSingle<T>;

	public:
		// ����T*��PointerSingle����ʽת�������Ҫ��ֹ����ͬʱɾ��PointerSingle& operator= (T* data);
		SmartPointerSingle(T* data = nullptr);
		~SmartPointerSingle();

		SmartPointerSingle(const ClassType& rhs);
		SmartPointerSingle& operator= (T* data);
		SmartPointerSingle& operator= (const ClassType& rhs);

		CLASS_INVARIANT_DECLARE;

		const T* GetData() const noexcept;
		operator const T* () const noexcept;
		const T& operator* () const noexcept;
		const T* operator-> () const noexcept;

		T* GetData() noexcept;
		operator T* () noexcept;
		T& operator* () noexcept;
		T* operator-> () noexcept;

	private:
		void Swap(ClassType& rhs) noexcept;

	private:
		T* m_Data;
	};

	template <typename T>
	bool operator== (const SmartPointerSingle<T>& lhs, T* data) noexcept;

	template <typename T>
	bool operator== (const SmartPointerSingle<T>& lhs, const SmartPointerSingle<T>& rhs) noexcept;
}

#endif // CORE_TOOLS_MEMORY_TOOLS_SMART_POINTER_SINGLE_H
