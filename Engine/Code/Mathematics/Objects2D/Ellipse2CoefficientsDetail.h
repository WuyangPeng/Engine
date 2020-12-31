///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.3 (2020/11/16 10:53)

#ifndef MATHEMATICS_OBJECTS2D_ELLIPSE2_COEFFICIENTS_DETAIL_H
#define MATHEMATICS_OBJECTS2D_ELLIPSE2_COEFFICIENTS_DETAIL_H

#include "Ellipse2Coefficients.h"

#if !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_ELLIPSE2_COEFFICIENTS_ACHIEVE)

    #include "Ellipse2CoefficientsAchieve.h"

#endif  //  !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_ELLIPSE2_COEFFICIENTS_ACHIEVE)

template <typename Real>
bool Mathematics::Approximate(const Ellipse2Coefficients<Real>& lhs, const Ellipse2Coefficients<Real>& rhs, const Real epsilon)
{
    auto lhsCoefficients = lhs.GetCoefficients();
    auto rhsCoefficients = rhs.GetCoefficients();

    constexpr auto coefficientsSize = Ellipse2Coefficients<Real>::sm_CoefficientsSize;

    if (lhsCoefficients.size() != coefficientsSize || rhsCoefficients.size() != coefficientsSize)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("GetCoefficients返回的数组大小错误！"s));
    }

    for (auto i = 0; i < coefficientsSize; ++i)
    {
        if (!Math<Real>::Approximate(lhsCoefficients[i], rhsCoefficients[i], epsilon))
        {
            return false;
        }
    }

    return true;
}

#endif  // MATHEMATICS_OBJECTS2D_ELLIPSE2_COEFFICIENTS_DETAIL_H
