///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.4 (2022/03/21 14:19)

#ifndef MATHEMATICS_INTERPOLATION_INTP_THIN_PLATE_SPLINE2_DETAIL_H
#define MATHEMATICS_INTERPOLATION_INTP_THIN_PLATE_SPLINE2_DETAIL_H

#include "IntpThinPlateSpline2.h"
#include "CoreTools/Exception/Error.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Base/MathDetail.h"
#include "Mathematics/NumericalAnalysis/LinearSystemDetail.h"

template <typename Real>
Mathematics::IntpThinPlateSpline2<Real>::IntpThinPlateSpline2(int quantity, const std::vector<Real>& x, const std::vector<Real>& y, const std::vector<Real>& f, Real smooth, bool transformToUnitSquare)
    : initialized{ false },
      quantity{ quantity },
      xValue(quantity),
      yValue(quantity),
      smooth{ smooth },
      a(quantity),
      b{},
      xMin{},
      xMax{},
      xInvRange{},
      yMin{},
      yMax{},
      yInvRange{}
{
    MATHEMATICS_ASSERTION_0(quantity >= 3 && smooth >= Math<Real>::GetValue(0), "无限输入。\n");

    if (transformToUnitSquare)
    {
        xMin = x.at(0);
        xMax = xMin;
        for (auto i = 1; i < quantity; ++i)
        {
            if (x.at(i) < xMin)
            {
                xMin = x.at(i);
            }
            if (x.at(i) > xMax)
            {
                xMax = x.at(i);
            }
        }
        xInvRange = (Math<Real>::GetValue(1)) / (xMax - xMin);
        for (auto i = 0; i < quantity; ++i)
        {
            xValue.at(i) = (x.at(i) - xMin) * xInvRange;
        }

        yMin = y.at(0);
        yMax = yMin;
        for (auto i = 1; i < quantity; ++i)
        {
            if (y.at(i) < yMin)
            {
                yMin = y.at(i);
            }
            if (y.at(i) > yMax)
            {
                yMax = y.at(i);
            }
        }
        yInvRange = (Math<Real>::GetValue(1)) / (yMax - yMin);
        for (auto i = 0; i < quantity; ++i)
        {
            yValue.at(i) = (y.at(i) - yMin) * yInvRange;
        }
    }
    else
    {
        xMin = Math<Real>::GetValue(0);
        xMax = Math<Real>::GetValue(1);
        xInvRange = Math<Real>::GetValue(1);
        yMin = Math<Real>::GetValue(0);
        yMax = Math<Real>::GetValue(1);
        yInvRange = Math<Real>::GetValue(1);
    }

    VariableMatrix<Real> aMat{ quantity, quantity };
    for (auto row = 0; row < quantity; ++row)
    {
        for (auto col = 0; col < quantity; ++col)
        {
            if (row == col)
            {
                aMat[row][col] = smooth;
            }
            else
            {
                auto dx = xValue.at(row) - xValue.at(col);
                auto dy = yValue.at(row) - yValue.at(col);
                auto t = Math<Real>::Sqrt(dx * dx + dy * dy);
                aMat[row][col] = Kernel(t);
            }
        }
    }

    VariableMatrix<Real> bMat{ quantity, 3 };
    for (auto row = 0; row < quantity; ++row)
    {
        bMat[row][0] = Math<Real>::GetValue(1);
        bMat[row][1] = xValue.at(row);
        bMat[row][2] = yValue.at(row);
    }

    VariableMatrix<Real> invAMat(quantity, quantity);
    try
    {
        invAMat = LinearSystem<Real>().Inverse(aMat);
    }
    catch (CoreTools::Error&)
    {
        return;
    }

    VariableMatrix<Real> pMat = TransposeTimes(bMat, invAMat);

    VariableMatrix<Real> qMat = pMat * bMat;

    VariableMatrix<Real> invQMat{ 3, 3 };
    try
    {
        invQMat = LinearSystem<Real>().Inverse(qMat);
    }
    catch (CoreTools::Error&)
    {
        return;
    }

    std::array<Real, 3> prod{};
    for (auto row = 0; row < 3; ++row)
    {
        prod.at(row) = Math<Real>::GetValue(0);
        for (auto i = 0; i < quantity; ++i)
        {
            prod.at(row) += pMat[row][i] * f.at(i);
        }
    }

    for (auto row = 0; row < 3; ++row)
    {
        b.at(row) = Math<Real>::GetValue(0);
        for (auto i = 0; i < 3; ++i)
        {
            b.at(row) += invQMat[row][i] * prod.at(i);
        }
    }

    std::vector<Real> tmp(quantity);
    for (auto row = 0; row < quantity; ++row)
    {
        tmp.at(row) = f.at(row);
        for (auto i = 0; i < 3; ++i)
        {
            tmp.at(row) -= bMat[row][i] * b.at(i);
        }
    }

    for (auto row = 0; row < quantity; ++row)
    {
        a.at(row) = Math<Real>::GetValue(0);
        for (auto i = 0; i < quantity; ++i)
        {
            a.at(row) += invAMat[row][i] * tmp.at(i);
        }
    }

    initialized = true;

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::IntpThinPlateSpline2<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::IntpThinPlateSpline2<Real>::IsInitialized() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return initialized;
}

template <typename Real>
std::vector<Real> Mathematics::IntpThinPlateSpline2<Real>::GetACoefficients() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return a;
}

template <typename Real>
std::array<Real, 3> Mathematics::IntpThinPlateSpline2<Real>::GetBCoefficients() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return b;
}

template <typename Real>
Real Mathematics::IntpThinPlateSpline2<Real>::GetSmooth() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return smooth;
}

template <typename Real>
Real Mathematics::IntpThinPlateSpline2<Real>::ComputeFunctional() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    auto functional = Math<Real>::GetValue(0);
    for (auto row = 0; row < quantity; ++row)
    {
        for (auto col = 0; col < quantity; ++col)
        {
            if (row == col)
            {
                functional += smooth * a.at(row) * a.at(col);
            }
            else
            {
                auto dx = xValue.at(row) - xValue.at(col);
                auto dy = yValue.at(row) - yValue.at(col);
                auto t = Math<Real>::Sqrt(dx * dx + dy * dy);
                auto k = Kernel(t);
                functional += k * a.at(row) * a.at(col);
            }
        }
    }

    if (smooth > Math<Real>::GetValue(0))
    {
        functional *= smooth;
    }

    return functional;
}

template <typename Real>
Real Mathematics::IntpThinPlateSpline2<Real>::operator()(Real x, Real y)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    if (initialized)
    {
        x = (x - xMin) * xInvRange;
        y = (y - yMin) * yInvRange;

        auto result = b.at(0) + b.at(1) * x + b.at(2) * y;
        for (int i = 0; i < quantity; ++i)
        {
            auto dx = x - xValue.at(i);
            auto dy = y - yValue.at(i);
            auto t = Math<Real>::Sqrt(dx * dx + dy * dy);
            result += a.at(i) * Kernel(t);
        }
        return result;
    }

    return Math<Real>::maxReal;
}

template <typename Real>
Real Mathematics::IntpThinPlateSpline2<Real>::Kernel(Real t) noexcept(gAssert < 3 || gMathematicsAssert < 3)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    if (t > Math<Real>::GetValue(0))
    {
        auto t2 = t * t;
        return t2 * Math<Real>::Log(t2);
    }

    return Math<Real>::GetValue(0);
}

#endif  // MATHEMATICS_INTERPOLATION_INTP_THIN_PLATE_SPLINE2_DETAIL_H