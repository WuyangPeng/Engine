// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/18 19:12)

#ifndef MATHEMATICS_BASE_FAST_NEGATIVE_EXP_DETAIL_H
#define MATHEMATICS_BASE_FAST_NEGATIVE_EXP_DETAIL_H

#include "FastNegativeExp.h"

#if !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_FAST_NEGATIVE_EXP_DETAIL)

#include "MathDetail.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Contract/Noexcept.h"

template <typename Real>
Real Mathematics::FastNegativeExp<Real>
	::FastNegativeExpMoreRoughCalculation(Real value)
{
	MATHEMATICS_ASSERTION_3(Math::GetValue(0) <= value, "输入值必须在范围[0,无穷大)！\n");

	auto result = static_cast<Real>(0.0038278);

	result *= value;
	result += static_cast<Real>(0.0292732);
	result *= value;
	result += static_cast<Real>(0.2507213);
	result *= value;
	result += Math::GetValue(1);
	result *= result;
	result *= result;
	result = Math::GetValue(1) / result;

	CoreTools::DisableNoexcept();

	return result;
}

template <typename Real>
Real Mathematics::FastNegativeExp<Real>
	::FastNegativeExpRoughCalculation(Real value)
{
	MATHEMATICS_ASSERTION_3(Math::GetValue(0) <= value, "输入值必须在范围[0,无穷大)！\n");

	auto result = static_cast<Real>(0.00026695);

	result *= value;
	result += static_cast<Real>(0.00227723);
	result *= value;
	result += static_cast<Real>(0.03158565);
	result *= value;
	result += static_cast<Real>(0.24991035);
	result *= value;
	result += Math::GetValue(1);
	result *= result;
	result *= result;
	result = Math::GetValue(1) / result;

	CoreTools::DisableNoexcept();

	return result;
}

template <typename Real>
Real Mathematics::FastNegativeExp<Real>
	::FastNegativeExpPreciseCalculation(Real value)
{
	MATHEMATICS_ASSERTION_3(Math::GetValue(0) <= value, "输入值必须在范围[0,无穷大)！\n");

	auto result = static_cast<Real>(0.000014876);

	result *= value;
	result += static_cast<Real>(0.000127992);
	result *= value;
	result += static_cast<Real>(0.002673255);
	result *= value;
	result += static_cast<Real>(0.031198056);
	result *= value;
	result += static_cast<Real>(0.250010936);
	result *= value;
	result += Math::GetValue(1);
	result *= result;
	result *= result;

	result = Math::GetValue(1) / result;

	CoreTools::DisableNoexcept();

	return result;
}

template <typename Real>
Real Mathematics::FastNegativeExp<Real>
	::FastNegativeExpMorePreciseCalculation(Real value)
{
	MATHEMATICS_ASSERTION_3(Math::GetValue(0) <= value, "输入值必须在范围[0,无穷大)！\n");

	auto result = static_cast<Real>(0.0000006906);

	result *= value;
	result += static_cast<Real>(0.0000054302);
	result *= value;
	result += static_cast<Real>(0.0001715620);
	result *= value;
	result += static_cast<Real>(0.0025913712);
	result *= value;
	result += static_cast<Real>(0.0312575832);
	result *= value;
	result += static_cast<Real>(0.2499986842);
	result *= value;
	result += Math::GetValue(1);
	result *= result;
	result *= result;
	result = Math::GetValue(1) / result;

	CoreTools::DisableNoexcept();

	return result;
}

#endif // !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_FAST_NEGATIVE_EXP_DETAIL)

#endif // MATHEMATICS_BASE_FAST_NEGATIVE_EXP_DETAIL_H