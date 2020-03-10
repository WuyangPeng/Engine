// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/20 16:43)

#ifndef CORE_TOOLS_MEMORY_TOOLS_SMART_POINTER_4D_ARRAY_H
#define CORE_TOOLS_MEMORY_TOOLS_SMART_POINTER_4D_ARRAY_H

#include <boost/operators.hpp>

namespace CoreTools
{
	template <typename T>
	class SmartPointer4DArray : private boost::equality_comparable<SmartPointer4DArray<T>,
										boost::equality_comparable<SmartPointer4DArray<T>, T****>>
	{
	public:
		using ClassType = SmartPointer4DArray<T>;

	public:
		// ����T****��SmartPointer4DArray����ʽת�������Ҫ��ֹ����ͬʱɾ��SmartPointer4DArray& operator= (T**** data);
		SmartPointer4DArray(T**** data = nullptr);
		~SmartPointer4DArray();

		SmartPointer4DArray(const ClassType& rhs);
		SmartPointer4DArray& operator= (T**** data);
		SmartPointer4DArray& operator= (const ClassType& rhs);

		CLASS_INVARIANT_DECLARE;

		T**** const GetData() const noexcept;
		operator T**** const () const noexcept;
		T*** const& operator* () const noexcept;

		T**** GetData() noexcept;
		operator T**** () noexcept;
		T***& operator* () noexcept;

	private:
		void Swap(ClassType& rhs) noexcept;

	private:
		T**** m_Data;
	};

	template <typename T>
	bool operator== (const SmartPointer4DArray<T>& lhs, T**** data) noexcept;

	template <typename T>
	bool operator== (const SmartPointer4DArray<T>& lhs, const SmartPointer4DArray<T>& rhs) noexcept;
}

#endif // CORE_TOOLS_MEMORY_TOOLS_SMART_POINTER_4D_ARRAY_H
