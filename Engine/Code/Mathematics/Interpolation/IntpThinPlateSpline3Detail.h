///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/09 10:09)

#ifndef MATHEMATICS_INTERPOLATION_INTP_THIN_PLATE_SPLINE3_DETAIL_H
#define MATHEMATICS_INTERPOLATION_INTP_THIN_PLATE_SPLINE3_DETAIL_H

#include "IntpThinPlateSpline3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Base/MathDetail.h"
#include "Mathematics/NumericalAnalysis/LinearSystemDetail.h"

template <typename Real>
Mathematics::IntpThinPlateSpline3<Real>::IntpThinPlateSpline3(int quantity, const std::vector<Real>& x, const std::vector<Real>& y, const std::vector<Real>& z, const std::vector<Real>& f, Real smooth, bool transformToUnitCube)
    : initialized{ false },
      quantity{ false },
      xValue(quantity),
      yValue(quantity),
      zValue(quantity),
      smooth{ smooth },
      a(quantity),
      b{},
      xMin{},
      xMax{},
      xInvRange{},
      yMin{},
      yMax{},
      yInvRange{},
      zMin{},
      zMax{},
      zInvRange{}
{
    MATHEMATICS_ASSERTION_0(quantity >= 4 && smooth >= Math<Real>::GetValue(0), "无效输入。\n");

    if (transformToUnitCube)
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

        zMin = z.at(0);
        zMax = zMin;
        for (auto i = 1; i < quantity; ++i)
        {
            if (z.at(i) < zMin)
            {
                zMin = z.at(i);
            }
            if (z.at(i) > zMax)
            {
                zMax = z.at(i);
            }
        }
        zInvRange = (Math<Real>::GetValue(1)) / (zMax - zMin);
        for (auto i = 0; i < quantity; ++i)
        {
            zValue.at(i) = (z.at(i) - zMin) * zInvRange;
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
        zMin = Math<Real>::GetValue(0);
        zMax = Math<Real>::GetValue(1);
        zInvRange = Math<Real>::GetValue(1);
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
                auto dz = zValue.at(row) - zValue.at(col);
                auto t = Math<Real>::Sqrt(dx * dx + dy * dy + dz * dz);
                aMat[row][col] = Kernel(t);
            }
        }
    }

    VariableMatrix<Real> bMat{ quantity, 4 };
    for (auto row = 0; row < quantity; ++row)
    {
        bMat[row][0] = Math<Real>::GetValue(1);
        bMat[row][1] = xValue.at(row);
        bMat[row][2] = yValue.at(row);
        bMat[row][3] = zValue.at(row);
    }

    VariableMatrix<Real> invAMat{ quantity, quantity };
    invAMat = LinearSystem<Real>().Inverse(aMat);  // 失败抛出异常

    auto pMat = TransposeTimes(bMat, invAMat);

    auto qMat = pMat * bMat;

    VariableMatrix<Real> invQMat{ 4, 4 };
    invQMat = LinearSystem<Real>().Inverse(qMat);  // 失败抛出异常

    std::array<Real, 4> prod{};
    for (auto row = 0; row < 4; ++row)
    {
        prod.at(row) = Math<Real>::GetValue(0);
        for (auto i = 0; i < quantity; ++i)
        {
            prod.at(row) += pMat[row][i] * f.at(i);
        }
    }

    for (auto row = 0; row < 4; ++row)
    {
        b.at(row) = Math<Real>::GetValue(0);
        for (auto i = 0; i < 4; ++i)
        {
            b.at(row) += invQMat[row][i] * prod.at(i);
        }
    }

    std::vector<Real> tmp(quantity);
    for (auto row = 0; row < quantity; ++row)
    {
        tmp.at(row) = f.at(row);
        for (auto i = 0; i < 4; ++i)
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
bool Mathematics::IntpThinPlateSpline3<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::IntpThinPlateSpline3<Real>::IsInitialized() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return initialized;
}

template <typename Real>
std::vector<Real> Mathematics::IntpThinPlateSpline3<Real>::GetACoefficients() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return a;
}

template <typename Real>
std::array<Real, 4> Mathematics::IntpThinPlateSpline3<Real>::GetBCoefficients() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return b;
}

template <typename Real>
Real Mathematics::IntpThinPlateSpline3<Real>::GetSmooth() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return smooth;
}

template <typename Real>
Real Mathematics::IntpThinPlateSpline3<Real>::operator()(Real x, Real y, Real z)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    if (initialized)
    {
        x = (x - xMin) * xInvRange;
        y = (y - yMin) * yInvRange;
        z = (z - zMin) * zInvRange;

        auto result = b.at(0) + b.at(1) * x + b.at(2) * y + b.at(3) * z;
        for (int i = 0; i < quantity; ++i)
        {
            auto dx = x - xValue.at(i);
            auto dy = y - yValue.at(i);
            auto dz = z - zValue.at(i);
            auto t = Math<Real>::Sqrt(dx * dx + dy * dy + dz * dz);
            result += a.at(i) * Kernel(t);
        }
        return result;
    }

    return Math<Real>::maxReal;
}

template <typename Real>
Real Mathematics::IntpThinPlateSpline3<Real>::ComputeFunctional() const
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
                auto dz = zValue.at(row) - zValue.at(col);
                auto t = Math<Real>::Sqrt(dx * dx + dy * dy + dz * dz);
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
Real Mathematics::IntpThinPlateSpline3<Real>::Kernel(Real t) noexcept
{
    return -Math<Real>::FAbs(t);
}

#endif  // MATHEMATICS_INTERPOLATION_INTP_THIN_PLATE_SPLINE3_DETAIL_H