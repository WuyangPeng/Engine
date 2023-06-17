///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/09 10:07)

#ifndef MATHEMATICS_INTERPOLATION_INTP_AKIMA_UNIFORM1_DETAIL_H
#define MATHEMATICS_INTERPOLATION_INTP_AKIMA_UNIFORM1_DETAIL_H

#include "IntpAkimaUniform1.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Base/MathDetail.h"

template <typename Real>
Mathematics::IntpAkimaUniform1<Real>::IntpAkimaUniform1(int quantity, Real xMin, Real xSpacing, const std::vector<Real>& f)
    : ParentType{ quantity, f }, xMin{ xMin }, xMax{ xMin + xSpacing * (boost::numeric_cast<size_t>(quantity) - 1) }, xSpacing{ xSpacing }
{
    MATHEMATICS_ASSERTION_0(xSpacing > Math<Real>::GetValue(0), "间距必须为正。\n");

    auto invDX = (Math<Real>::GetValue(1)) / xSpacing;
    const auto slopeSize = quantity + 3;
    std::vector<Real> slope(slopeSize);

    for (auto i = 0, ip1 = 1, ip2 = 2; i < quantity - 1; ++i, ++ip1, ++ip2)
    {
        slope.at(ip2) = (this->GetF(ip1) - this->GetF(i)) * invDX;
    }

    const auto nextQuantity = quantity + 1;
    const auto beforeQuantity = quantity - 1;
    const auto quantityAndTwo = quantity + 2;

    slope.at(1) = (Math<Real>::GetValue(2)) * slope.at(2) - slope.at(3);
    slope.at(0) = (Math<Real>::GetValue(2)) * slope.at(1) - slope.at(2);
    slope.at(nextQuantity) = (Math<Real>::GetValue(2)) * slope.at(quantity) - slope.at(beforeQuantity);
    slope.at(quantityAndTwo) = (Math<Real>::GetValue(2)) * slope.at(nextQuantity) - slope.at(quantity);

    std::vector<Real> fDer(quantity);
    for (auto i = 0; i < quantity; ++i)
    {
        std::vector<Real> derivative{ slope.begin() + i, slope.end() };
        fDer.at(i) = this->ComputeDerivative(derivative);
    }

    auto invDX2 = (Math<Real>::GetValue(1)) / (xSpacing * xSpacing);
    auto invDX3 = invDX2 / xSpacing;
    for (auto i = 0, ip1 = 1; i < quantity - 1; ++i, ++ip1)
    {
        auto& poly = this->GetPolynomial(i);

        auto f0 = this->GetF(i);
        auto f1 = this->GetF(ip1);
        auto df = f1 - f0;
        auto fDer0 = fDer.at(i);
        auto fDer1 = fDer.at(ip1);

        poly[0] = f0;
        poly[1] = fDer0;
        poly[2] = (Math<Real>::GetValue(3) * df - xSpacing * (fDer1 + (Math<Real>::GetValue(2)) * fDer0)) * invDX2;
        poly[3] = (xSpacing * (fDer0 + fDer1) - (Math<Real>::GetValue(2)) * df) * invDX3;
    }

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::IntpAkimaUniform1<Real>::IsValid() const noexcept
{
    return ParentType::IsValid();
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Real Mathematics::IntpAkimaUniform1<Real>::GetXMin() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return xMin;
}

template <typename Real>
Real Mathematics::IntpAkimaUniform1<Real>::GetXMax() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return xMax;
}

template <typename Real>
Real Mathematics::IntpAkimaUniform1<Real>::GetXSpacing() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return xSpacing;
}

template <typename Real>
bool Mathematics::IntpAkimaUniform1<Real>::Lookup(Real x, int& index, Real& dx) const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    if (x >= xMin)
    {
        if (x <= xMax)
        {
            for (index = 0; index + 1 < this->GetQuantity(); ++index)
            {
                const auto nextIndex = index + 1;
                if (x < xMin + xSpacing * (nextIndex))
                {
                    dx = x - (xMin + xSpacing * index);

                    return true;
                }
            }

            --index;
            dx = x - (xMin + xSpacing * index);

            return true;
        }
    }

    return false;
}

#endif  // MATHEMATICS_INTERPOLATION_INTP_AKIMA_UNIFORM1_DETAIL_H