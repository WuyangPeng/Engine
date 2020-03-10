// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.2 (2020/01/22 10:39)

#ifndef CORE_TOOLS_TEMPLATE_TOOLS_PTR_COMPARE_H
#define CORE_TOOLS_TEMPLATE_TOOLS_PTR_COMPARE_H

#include "CoreTools/CoreToolsDll.h"

namespace CoreTools
{
	// ��������һ��STL������бȽ϶����ֵ��������ָ���ֵ��
	template <class T>
	class PtrLess
	{
	public:
		bool operator ()(T left, T right)
		{
			return ((*left) < (*right));
		}
	};

	template <class T>
	class PtrGreater
	{
	public:
		bool operator ()(T left, T right)
		{
			return ((*right) < (*left));
		}
	};
}

#endif // CORE_TOOLS_TEMPLATE_TOOLS_PTR_COMPARE_H

