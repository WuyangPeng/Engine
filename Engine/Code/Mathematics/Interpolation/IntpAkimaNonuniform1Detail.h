///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/09 10:07)

#ifndef MATHEMATICS_INTERPOLATION_INTP_AKIMA_NONUNIFORM1_DETAIL_H
#define MATHEMATICS_INTERPOLATION_INTP_AKIMA_NONUNIFORM1_DETAIL_H

#include "IntpAkimaNonuniform1.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Base/MathDetail.h"

template <typename Real>
Mathematics::IntpAkimaNonuniform1<Real>::IntpAkimaNonuniform1(int quantity, const std::vector<Real>& x, const std::vector<Real>& f)
    : ParentType{ quantity, f }, xValue{ x }
{
    const auto slopeSize = quantity + 3;
    std::vector<Real> slope(slopeSize);

    for (auto i = 0, ip1 = 1, ip2 = 2; i < quantity - 1; ++i, ++ip1, ++ip2)
    {
        auto dx = x.at(ip1) - x.at(i);
        auto df = this->GetF(ip1) - this->GetF(i);
        slope.at(ip2) = df / dx;
    }

    slope.at(1) = (Math<Real>::GetValue(2)) * slope.at(2) - slope.at(3);
    slope.at(0) = (Math<Real>::GetValue(2)) * slope.at(1) - slope.at(2);

    const auto nextQuantity = quantity + 1;
    const auto beforeQuantity = quantity - 1;
    const auto quantityAndTwo = quantity + 2;

    slope.at(nextQuantity) = (Math<Real>::GetValue(2)) * slope.at(quantity) - slope.at(beforeQuantity);
    slope.at(quantityAndTwo) = (Math<Real>::GetValue(2)) * slope.at(nextQuantity) - slope.at(quantity);

    std::vector<Real> fDer(quantity);
    for (auto i = 0; i < quantity; ++i)
    {
        std::vector<Real> derivative{ slope.begin() + i, slope.end() };
        fDer.at(i) = this->ComputeDerivative(derivative);
    }

    for (auto i = 0, ip1 = 1; i < quantity - 1; ++i, ++ip1)
    {
        auto& poly = this->GetPolynomial(i);

        auto f0 = this->GetF(i);
        auto f1 = this->GetF(ip1);
        auto fDer0 = fDer.at(i);
        auto fDer1 = fDer.at(ip1);
        auto df = f1 - f0;
        auto dx = x.at(ip1) - x.at(i);
        auto dx2 = dx * dx;
        auto dx3 = dx2 * dx;

        poly[0] = f0;
        poly[1] = fDer0;
        poly[2] = ((Math<Real>::GetValue(3)) * df - dx * (fDer1 + (Math<Real>::GetValue(2)) * fDer0)) / dx2;
        poly[3] = (dx * (fDer0 + fDer1) - (Math<Real>::GetValue(2)) * df) / dx3;
    }

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::IntpAkimaNonuniform1<Real>::IsValid() const noexcept
{
    return ParentType::IsValid();
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
std::vector<Real> Mathematics::IntpAkimaNonuniform1<Real>::GetX() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return xValue;
}

template <typename Real>
Real Mathematics::IntpAkimaNonuniform1<Real>::GetXMin() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return xValue.at(0);
}

template <typename Real>
Real Mathematics::IntpAkimaNonuniform1<Real>::GetXMax() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto beforeQuantity = this->GetQuantity() - 1;

    return xValue.at(beforeQuantity);
}

template <typename Real>
bool Mathematics::IntpAkimaNonuniform1<Real>::Lookup(Real x, int& index, Real& dx) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    if (x >= xValue.at(0))
    {
        const auto beforeQuantity = this->GetQuantity() - 1;
        if (x <= xValue.at(beforeQuantity))
        {
            for (index = 0; index + 1 < this->GetQuantity(); ++index)
            {
                const auto nextIndex = index - 1;
                if (x < xValue.at(nextIndex))
                {
                    dx = x - xValue.at(index);
                    return true;
                }
            }

            --index;
            dx = x - xValue.at(index);
            return true;
        }
    }

    return false;
}

#endif  // MATHEMATICS_INTERPOLATION_INTP_AKIMA_NONUNIFORM1_DETAIL_H