// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.2 (2019/07/03 15:42)

#ifndef MATHEMATICS_BASE_BIT_HACKS_DETAIL_H
#define MATHEMATICS_BASE_BIT_HACKS_DETAIL_H

#include "BitHacks.h"
#include "Log2OfPowerOfTwoDetail.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"

#include <boost/type_traits/is_integral.hpp>
#include <boost/static_assert.hpp>

template <typename T>
bool Mathematics::BitHacks
	::IsPowerOfTwo( T value )
{
	BOOST_STATIC_ASSERT((boost::is_integral<T>::value));
	
	return (0 < value) && ((value & (value - 1)) == 0);
}

// log2的快速整数算法
// 通过掩码计算出powerOfTwo的最高位数，即log2(powerOfTwo)的值。
template <typename T>
T Mathematics::BitHacks
	::Log2OfPowerOfTwo( T powerOfTwo )
{
	BOOST_STATIC_ASSERT((boost::is_integral<T>::value));
	MATHEMATICS_ASSERTION_3(0 < powerOfTwo,"值powerOfTwo必须大于0");

	Mathematics::Log2OfPowerOfTwo<T> log2OfPowerOfTwo{ powerOfTwo };

	return log2OfPowerOfTwo.GetLog2();
}

#endif // MATHEMATICS_BASE_BIT_HACKS_DETAIL_H
