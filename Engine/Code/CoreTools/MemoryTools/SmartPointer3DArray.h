// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/20 16:42)

#ifndef CORE_TOOLS_MEMORY_TOOLS_SMART_POINTER_3D_ARRAY_H
#define CORE_TOOLS_MEMORY_TOOLS_SMART_POINTER_3D_ARRAY_H

#include "System/Helper/PragmaWarning/Operators.h"

namespace CoreTools
{
	template <typename T>
	class SmartPointer3DArray : private boost::equality_comparable<SmartPointer3DArray<T>,
										boost::equality_comparable<SmartPointer3DArray<T>, T***>>
	{
	public:
		using ClassType = SmartPointer3DArray<T>;

	public:
		// ����T***��SmartPointer3DArray����ʽת�������Ҫ��ֹ����ͬʱɾ��SmartPointer3DArray& operator= (T*** data);
		SmartPointer3DArray(T*** data = nullptr);
		~SmartPointer3DArray();

		SmartPointer3DArray(const ClassType& rhs);
		SmartPointer3DArray& operator= (T*** data);
		SmartPointer3DArray& operator= (const ClassType& rhs);

		CLASS_INVARIANT_DECLARE;

		T*** const GetData() const noexcept;
		operator T*** const () const noexcept;
		T** const& operator* () const noexcept;

		T*** GetData() noexcept;
		operator T*** () noexcept;
		T**& operator* () noexcept;

	private:
		void Swap(ClassType& rhs) noexcept;

	private:
		T*** m_Data;
	};

	template <typename T>
	bool operator== (const SmartPointer3DArray<T>& lhs, T*** data) noexcept;

	template <typename T>
	bool operator== (const SmartPointer3DArray<T>& lhs, const SmartPointer3DArray<T>& rhs) noexcept;
}

#endif // CORE_TOOLS_MEMORY_TOOLS_SMART_POINTER_3D_ARRAY_H
