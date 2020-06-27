// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/18 19:06)

#ifndef MATHEMATICS_BASE_NUMERICAL_VALUE_SYMBOL_H
#define MATHEMATICS_BASE_NUMERICAL_VALUE_SYMBOL_H

#include "System/Helper/EnumMacro.h"

namespace Mathematics
{
	enum class NumericalValueSymbol
	{
		// 负号
		Negative = -1,
		// 零
		Zero = 0,
		// 正号
		Positive = 1
	};

	ENUM_NEGATE_OPERATOR_DEFINE(NumericalValueSymbol);
	ENUM_MULTIPLICATION_OPERATOR_DEFINE(NumericalValueSymbol);
	
	template<typename T> 
	constexpr T operator*(T lhs, Mathematics::NumericalValueSymbol rhs) noexcept
	{
		return rhs * lhs;
	}
}

#endif // MATHEMATICS_BASE_NUMERICAL_VALUE_SYMBOL_H
