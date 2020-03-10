// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.1 (2020/01/20 16:42)

#ifndef CORE_TOOLS_MEMORY_TOOLS_SMART_POINTER_1D_ARRAY_H
#define CORE_TOOLS_MEMORY_TOOLS_SMART_POINTER_1D_ARRAY_H

#include <boost/operators.hpp>

namespace CoreTools
{
	template <typename T>
	class SmartPointer1DArray : private boost::equality_comparable<SmartPointer1DArray<T>,
										boost::equality_comparable<SmartPointer1DArray<T>, T*>>
	{
	public:
		using ClassType = SmartPointer1DArray<T>;

	public:
		// 允许T*到SmartPointer1DArray的隐式转换。如果要禁止，请同时删除SmartPointer1DArray& operator= (T* data);
		SmartPointer1DArray(T* data = nullptr);
		~SmartPointer1DArray();

		SmartPointer1DArray(const ClassType& rhs);
		SmartPointer1DArray& operator= (T* data);
		SmartPointer1DArray& operator= (const ClassType& rhs);

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
	bool operator== (const SmartPointer1DArray<T>& lhs, T* data) noexcept;

	template <typename T>
	bool operator== (const SmartPointer1DArray<T>& lhs, const SmartPointer1DArray<T>& rhs) noexcept;
}

#endif // CORE_TOOLS_MEMORY_TOOLS_SMART_POINTER_1D_ARRAY_H
