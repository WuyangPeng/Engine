// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/03 15:46)

#ifndef MATHEMATICS_BASE_FAST_NEGATIVE_EXP_DETAIL_H
#define MATHEMATICS_BASE_FAST_NEGATIVE_EXP_DETAIL_H

#include "FastNegativeExp.h"

#if !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_FAST_NEGATIVE_EXP_DETAIL)

#include "MathDetail.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"

template <typename Real>
Real Mathematics::FastNegativeExp<Real>
	::FastNegativeExpMoreRoughCalculation (Real value)
{
	MATHEMATICS_ASSERTION_3(Math<Real>::sm_Zero <= value,"����ֵ�����ڷ�Χ[0,�����)��\n");

    Real result = static_cast<Real>(0.0038278);

    result *= value;
    result += static_cast<Real>(0.0292732);
    result *= value;
    result += static_cast<Real>(0.2507213);
    result *= value;
    result += Math<Real>::sm_One;
    result *= result;
    result *= result;
    result = Math<Real>::sm_One / result;

    return result;
}

template <typename Real>
Real Mathematics::FastNegativeExp<Real>
	::FastNegativeExpRoughCalculation (Real value)
{
	MATHEMATICS_ASSERTION_3(Math<Real>::sm_Zero <= value,"����ֵ�����ڷ�Χ[0,�����)��\n");

    Real result = static_cast<Real>(0.00026695);

    result *= value;
    result += static_cast<Real>(0.00227723);
    result *= value;
    result += static_cast<Real>(0.03158565);
    result *= value;
    result += static_cast<Real>(0.24991035);
    result *= value;
    result += Math<Real>::sm_One;
    result *= result;
    result *= result;
    result = Math<Real>::sm_One / result;

    return result;
}

template <typename Real>
Real Mathematics::FastNegativeExp<Real>
	::FastNegativeExpPreciseCalculation (Real value)
{
	MATHEMATICS_ASSERTION_3(Math<Real>::sm_Zero <= value,"����ֵ�����ڷ�Χ[0,�����)��\n");

    Real result = static_cast<Real>(0.000014876);

    result *= value;
    result += static_cast<Real>(0.000127992);
    result *= value;
    result += static_cast<Real>(0.002673255);
    result *= value;
    result += static_cast<Real>(0.031198056);
    result *= value;
    result += static_cast<Real>(0.250010936);
    result *= value;
    result += Math<Real>::sm_One;
    result *= result;
    result *= result;
    result = Math<Real>::sm_One / result;

    return result;
}

template <typename Real>
Real Mathematics::FastNegativeExp<Real>
	::FastNegativeExpMorePreciseCalculation (Real value)
{
	MATHEMATICS_ASSERTION_3(Math<Real>::sm_Zero <= value,"����ֵ�����ڷ�Χ[0,�����)��\n");

    Real result = static_cast<Real>(0.0000006906);

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
    result += Math<Real>::sm_One;
    result *= result;
    result *= result;
    result = Math<Real>::sm_One / result;

    return result;
}

#endif // !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_FAST_NEGATIVE_EXP_DETAIL)

#endif // MATHEMATICS_BASE_FAST_NEGATIVE_EXP_DETAIL_H