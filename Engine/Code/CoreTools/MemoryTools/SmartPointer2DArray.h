// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/20 16:42)

#ifndef CORE_TOOLS_MEMORY_TOOLS_SMART_POINTER_2D_ARRAY_H
#define CORE_TOOLS_MEMORY_TOOLS_SMART_POINTER_2D_ARRAY_H

#include <boost/operators.hpp>

namespace CoreTools
{
	template <typename T>
	class SmartPointer2DArray : private boost::equality_comparable<SmartPointer2DArray<T>,
										boost::equality_comparable<SmartPointer2DArray<T>, T**>>
	{
	public:
		using ClassType = SmartPointer2DArray<T>;

	public:
		// ����T**��SmartPointer2DArray����ʽת�������Ҫ��ֹ����ͬʱɾ��SmartPointer2DArray& operator= (T** data);
		SmartPointer2DArray(T** data = nullptr);
		~SmartPointer2DArray();

		SmartPointer2DArray(const ClassType& rhs);
		SmartPointer2DArray& operator= (T** data);
		SmartPointer2DArray& operator= (const ClassType& rhs);

		CLASS_INVARIANT_DECLARE;

		T** const GetData() const noexcept;
		operator T** const() const noexcept;
		T* const& operator* () const noexcept;

		T** GetData() noexcept;
		operator T** () noexcept;
		T*& operator* () noexcept;

	private:
		void Swap(ClassType& rhs) noexcept;

	private:
		T** m_Data;
	};

	template <typename T>
	bool operator== (const SmartPointer2DArray<T>& lhs, T** data) noexcept;

	template <typename T>
	bool operator== (const SmartPointer2DArray<T>& lhs, const SmartPointer2DArray<T>& rhs) noexcept;
}

#endif // CORE_TOOLS_MEMORY_TOOLS_SMART_POINTER_2D_ARRAY_H
