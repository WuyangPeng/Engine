///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.2 (2020/11/10 11:28)

#ifndef MATHEMATICS_ALGEBRA_POLYNOMIAL_DETAIL_H
#define MATHEMATICS_ALGEBRA_POLYNOMIAL_DETAIL_H

#include "Polynomial.h"

#if !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_POLYNOMIAL_ACHIEVE)

    #include "PolynomialAchieve.h"

#endif  // !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_POLYNOMIAL_ACHIEVE)

template <typename T>
bool Mathematics::Approximate(const Polynomial<T>& lhs, const Polynomial<T>& rhs, const T epsilon)
{
    if (lhs.GetDegree() != rhs.GetDegree())
    {
        return false;
    }
    else
    {
        for (auto i = 0; i <= rhs.GetDegree(); ++i)
        {
            if (!Math<T>::Approximate(lhs[i], rhs[i], epsilon))
            {
                return false;
            }
        }

        return true;
    }
}

template <typename Real>
const Mathematics::Polynomial<Real> Mathematics::operator*(const Polynomial<Real>& lhs, const Polynomial<Real>& rhs)
{
    Polynomial<Real> result{ lhs.GetDegree() + rhs.GetDegree() };

    for (auto lhsIndex = 0; lhsIndex <= lhs.GetDegree(); ++lhsIndex)
    {
        for (auto rhsIndex = 0; rhsIndex <= rhs.GetDegree(); ++rhsIndex)
        {
            const auto index = lhsIndex + rhsIndex;
            result[index] += lhs[lhsIndex] * rhs[rhsIndex];
        }
    }

    return result;
}

#endif  // MATHEMATICS_ALGEBRA_POLYNOMIAL_DETAIL_H
