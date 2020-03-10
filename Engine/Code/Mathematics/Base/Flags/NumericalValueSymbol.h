// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/03 19:18)

#ifndef MATHEMATICS_BASE_NUMERICAL_VALUE_SYMBOL_H
#define MATHEMATICS_BASE_NUMERICAL_VALUE_SYMBOL_H

#include "System/Helper/EnumMacro.h"

namespace Mathematics
{	
	enum class NumericalValueSymbol
	{
		// ����
		Negative = -1, 
		// ��
		Zero = 0, 
		// ����
		Positive = 1
	};	

	ENUM_NEGATE_OPERATOR_DEFINE(NumericalValueSymbol);
	ENUM_MULTIPLICATION_OPERATOR_DEFINE(NumericalValueSymbol); 
}

#endif // MATHEMATICS_BASE_NUMERICAL_VALUE_SYMBOL_H
