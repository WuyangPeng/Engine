///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.4 (2022/03/18 20:45)

#ifndef MATHEMATICS_INTERPOLATION_INTP_AKIMA1_DETAIL_H
#define MATHEMATICS_INTERPOLATION_INTP_AKIMA1_DETAIL_H

#include "IntpAkima1.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Base/MathDetail.h"

template <typename Real>
Mathematics::IntpAkima1<Real>::IntpAkima1(int quantity, const std::vector<Real>& f)
    : quantity{ quantity }, f{ f }, poly(boost::numeric_cast<size_t>(quantity) - 1)
{
    MATHEMATICS_ASSERTION_0(quantity >= 3, "无效输入。\n");

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::IntpAkima1<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
int Mathematics::IntpAkima1<Real>::GetQuantity() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return quantity;
}

template <typename Real>
std::vector<Real> Mathematics::IntpAkima1<Real>::GetF() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return f;
}

template <typename Real>
std::vector<typename Mathematics::IntpAkima1<Real>::Polynomial> Mathematics::IntpAkima1<Real>::GetPolynomials() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return poly;
}

template <typename Real>
const typename Mathematics::IntpAkima1<Real>::Polynomial& Mathematics::IntpAkima1<Real>::GetPolynomial(int i) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return poly.at(i);
}

template <typename Real>
typename Mathematics::IntpAkima1<Real>::Polynomial& Mathematics::IntpAkima1<Real>::GetPolynomial(int i)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    return poly.at(i);
}

template <typename Real>
Real Mathematics::IntpAkima1<Real>::ComputeDerivative(const std::vector<Real>& slope) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    if (slope.at(1) != slope.at(2))
    {
        if (slope.at(0) != slope.at(1))
        {
            if (slope.at(2) != slope.at(3))
            {
                const auto ad0 = Math<Real>::FAbs(slope.at(3) - slope.at(2));
                const auto ad1 = Math<Real>::FAbs(slope.at(0) - slope.at(1));

                return (ad0 * slope.at(1) + ad1 * slope.at(2)) / (ad0 + ad1);
            }
            else
            {
                return slope.at(2);
            }
        }
        else
        {
            if (slope.at(2) != slope.at(3))
            {
                return slope.at(1);
            }
            else
            {
                return (Math<Real>::GetRational(1, 2)) * (slope.at(1) + slope.at(2));
            }
        }
    }
    else
    {
        return slope.at(1);
    }
}

template <typename Real>
Real Mathematics::IntpAkima1<Real>::operator()(Real x) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    auto index = 0;
    Real dx{};

    if (Lookup(x, index, dx))
    {
        return poly.at(index)(dx);
    }

    return Math<Real>::maxReal;
}

template <typename Real>
Real Mathematics::IntpAkima1<Real>::operator()(int order, Real x) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    auto index = 0;
    Real dx{};

    if (Lookup(x, index, dx))
    {
        return poly.at(index)(order, dx);
    }

    return Math<Real>::maxReal;
}

// IntpAkima1::Polynomial

template <typename Real>
Real Mathematics::IntpAkima1<Real>::Polynomial::operator()(Real x) const
{
    return coeff.at(0) + x * (coeff.at(1) + x * (coeff.at(2) + x * coeff.at(3)));
}

template <typename Real>
Real Mathematics::IntpAkima1<Real>::Polynomial::operator()(int order, Real x) const
{
    switch (order)
    {
        case 0:
            return coeff.at(0) + x * (coeff.at(1) + x * (coeff.at(2) + x * coeff.at(3)));
        case 1:
            return coeff.at(1) + x * ((Math<Real>::GetValue(2)) * coeff.at(2) + x * Math<Real>::GetValue(3) * coeff.at(3));
        case 2:
            return (Math<Real>::GetValue(2)) * coeff.at(2) + x * Math<Real>::GetValue(6) * coeff.at(3);
        case 3:
            return Math<Real>::GetValue(6) * coeff.at(3);
        default:
            return Math<Real>::GetValue(0);
    }
}

template <typename Real>
Real& Mathematics::IntpAkima1<Real>::Polynomial::operator[](int i)
{
    return coeff.at(i);
}

template <typename Real>
Real Mathematics::IntpAkima1<Real>::GetF(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return f.at(index);
}

#endif  // MATHEMATICS_INTERPOLATION_INTP_AKIMA1_DETAIL_H