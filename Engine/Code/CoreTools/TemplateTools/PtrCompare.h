// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.2 (2020/01/22 10:39)

#ifndef CORE_TOOLS_TEMPLATE_TOOLS_PTR_COMPARE_H
#define CORE_TOOLS_TEMPLATE_TOOLS_PTR_COMPARE_H

#include "CoreTools/CoreToolsDll.h"

namespace CoreTools
{
	// 该类允许一个STL对象进行比较对象的值，而不是指针的值。
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

