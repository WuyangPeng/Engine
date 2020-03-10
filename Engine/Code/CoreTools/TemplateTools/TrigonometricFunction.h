// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.2 (2020/01/22 10:42)

#ifndef CORE_TOOLS_TEMPLATE_TOOLS_TRIGONOMETRIC_FUNCTION_H
#define CORE_TOOLS_TEMPLATE_TOOLS_TRIGONOMETRIC_FUNCTION_H

#include "CoreTools/CoreToolsDll.h"

namespace CoreTools
{
	namespace TrigonometricFunction
	{
		// �ݹ� Sine
		double CORE_TOOLS_DEFAULT_DECLARE SineSeries(double radian, int index, int maxTerms) noexcept;
		double CORE_TOOLS_DEFAULT_DECLARE RecursiveSine( double radian ) noexcept;

		// �ǵݹ� Sine
		double CORE_TOOLS_DEFAULT_DECLARE NonRecursiveSine( double radian ) noexcept;
	}	
}

#endif // CORE_TOOLS_TEMPLATE_TOOLS_TRIGONOMETRIC_FUNCTION_H
