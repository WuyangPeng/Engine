// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.1 (2020/01/20 16:43)

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
		// 允许T****到SmartPointer4DArray的隐式转换。如果要禁止，请同时删除SmartPointer4DArray& operator= (T**** data);
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
