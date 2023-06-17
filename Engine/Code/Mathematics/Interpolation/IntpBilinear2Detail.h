///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/09 10:07)

#ifndef MATHEMATICS_INTERPOLATION_INTP_BILINEAR2_DETAIL_H
#define MATHEMATICS_INTERPOLATION_INTP_BILINEAR2_DETAIL_H

#include "IntpBilinear2.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Base/MathDetail.h"

template <typename Real>
Mathematics::IntpBilinear2<Real>::IntpBilinear2(int xBound, int yBound, Real xMin, Real xSpacing, Real yMin, Real ySpacing, const VariableMatrix<Real>& f)
    : xBound{ xBound },
      yBound{ yBound },
      quantity{ xBound * yBound },
      xMin{ xMin },
      xMax{ xMin + xSpacing * Math<Real>::GetValue(xBound - 1) },
      xSpacing{ xSpacing },
      invXSpacing{ (Math<Real>::GetValue(1)) / xSpacing },
      yMin{ yMin },
      yMax{ yMin + ySpacing * Math<Real>::GetValue(yBound - 1) },
      ySpacing{ ySpacing },
      invYSpacing{ (Math<Real>::GetValue(1)) / ySpacing },
      f{ f }
{
    MATHEMATICS_ASSERTION_0(xBound >= 2 && yBound >= 2, "无效输入。\n");
    MATHEMATICS_ASSERTION_0(xSpacing > Math<Real>::GetValue(0) && ySpacing > Math<Real>::GetValue(0), "无效输入。\n");

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::IntpBilinear2<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIAN

template <typename Real>
int Mathematics::IntpBilinear2<Real>::GetXBound() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return xBound;
}

template <typename Real>
int Mathematics::IntpBilinear2<Real>::GetYBound() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return yBound;
}

template <typename Real>
int Mathematics::IntpBilinear2<Real>::GetQuantity() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return quantity;
}

template <typename Real>
Mathematics::VariableMatrix<Real> Mathematics::IntpBilinear2<Real>::GetF() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return f;
}

template <typename Real>
Real Mathematics::IntpBilinear2<Real>::GetXMin() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return xMin;
}

template <typename Real>
Real Mathematics::IntpBilinear2<Real>::GetXMax() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return xMax;
}

template <typename Real>
Real Mathematics::IntpBilinear2<Real>::GetXSpacing() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return xSpacing;
}

template <typename Real>
Real Mathematics::IntpBilinear2<Real>::GetYMin() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return yMin;
}

template <typename Real>
Real Mathematics::IntpBilinear2<Real>::GetYMax() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return yMax;
}

template <typename Real>
Real Mathematics::IntpBilinear2<Real>::GetYSpacing() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return ySpacing;
}

template <typename Real>
Real Mathematics::IntpBilinear2<Real>::operator()(Real x, Real y) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    if (x < xMin || x > xMax || y < yMin || y > yMax)
    {
        return Math<Real>::maxReal;
    }

    auto xIndex = (x - xMin) * invXSpacing;
    auto ix = boost::numeric_cast<int>(xIndex);
    if (ix < 0)
    {
        ix = 0;
    }
    else if (ix >= xBound)
    {
        ix = xBound - 1;
    }

    auto yIndex = (y - yMin) * invYSpacing;
    auto iy = boost::numeric_cast<int>(yIndex);
    if (iy < 0)
    {
        iy = 0;
    }
    else if (iy >= yBound)
    {
        iy = yBound - 1;
    }

    std::array<Real, 2> u{ Math<Real>::GetValue(1), xIndex - ix };

    std::array<Real, 2> v{ Math<Real>::GetValue(1), yIndex - iy };

    std::array<Real, 2> p{};
    std::array<Real, 2> q{};

    for (auto row = 0; row < 2; ++row)
    {
        p.at(row) = Math<Real>::GetValue(0);
        q.at(row) = Math<Real>::GetValue(0);
        for (auto col = 0; col < 2; ++col)
        {
            p.at(row) += blend.at(row).at(col) * u.at(col);
            q.at(row) += blend.at(row).at(col) * v.at(col);
        }
    }

    auto result = Math<Real>::GetValue(0);
    for (auto row = 0; row < 2; ++row)
    {
        auto yClamp = iy + row;
        if (yClamp >= yBound)
        {
            yClamp = yBound - 1;
        }

        for (auto col = 0; col < 2; ++col)
        {
            auto xClamp = ix + col;
            if (xClamp >= xBound)
            {
                xClamp = xBound - 1;
            }

            result += q.at(row) * f[yClamp][xClamp] * p.at(col);
        }
    }

    return result;
}

template <typename Real>
Real Mathematics::IntpBilinear2<Real>::operator()(int xOrder, int yOrder, Real x, Real y) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    if (x < xMin || x > xMax || y < yMin || y > yMax)
    {
        return Math<Real>::maxReal;
    }

    auto xIndex = (x - xMin) * invXSpacing;
    auto ix = boost::numeric_cast<int>(xIndex);
    if (ix < 0)
    {
        ix = 0;
    }
    else if (ix >= xBound)
    {
        ix = xBound - 1;
    }

    auto yIndex = (y - yMin) * invYSpacing;
    auto iy = boost::numeric_cast<int>(yIndex);
    if (iy < 0)
    {
        iy = 0;
    }
    else if (iy >= yBound)
    {
        iy = yBound - 1;
    }

    std::array<Real, 2> u{};
    Real xMult{};
    switch (xOrder)
    {
        case 0:
        {
            auto dx = xIndex - ix;
            u.at(0) = Math<Real>::GetValue(1);
            u.at(1) = dx;
            xMult = Math<Real>::GetValue(1);
        }
        break;
        case 1:
        {
            u.at(0) = Math<Real>::GetValue(0);
            u.at(1) = Math<Real>::GetValue(1);
            xMult = invXSpacing;
        }
        break;
        default:
            return Math<Real>::GetValue(0);
    }

    std::array<Real, 2> v{};
    Real yMult{};
    switch (yOrder)
    {
        case 0:
        {
            auto dy = yIndex - iy;
            v.at(0) = Math<Real>::GetValue(1);
            v.at(1) = dy;
            yMult = Math<Real>::GetValue(1);
        }
        break;
        case 1:
        {
            v.at(0) = Math<Real>::GetValue(0);
            v.at(1) = Math<Real>::GetValue(1);
            yMult = invYSpacing;
        }
        break;
        default:
            return Math<Real>::GetValue(0);
    }

    std::array<Real, 2> p{};
    std::array<Real, 2> q{};

    for (auto row = 0; row < 2; ++row)
    {
        p.at(row) = Math<Real>::GetValue(0);
        q.at(row) = Math<Real>::GetValue(0);
        for (auto col = 0; col < 2; ++col)
        {
            p.at(row) += blend.at(row).at(col) * u.at(col);
            q.at(row) += blend.at(row).at(col) * v.at(col);
        }
    }

    auto result = Math<Real>::GetValue(0);
    for (auto row = 0; row < 2; ++row)
    {
        auto yClamp = iy + row;
        if (yClamp >= yBound)
        {
            yClamp = yBound - 1;
        }

        for (auto col = 0; col < 2; ++col)
        {
            auto xClamp = ix + col;
            if (xClamp >= xBound)
            {
                xClamp = xBound - 1;
            }

            result += q.at(row) * f[yClamp][xClamp] * p.at(col);
        }
    }
    result *= xMult * yMult;

    return result;
}

template <typename Real>
const std::array<std::array<Real, 2>, 2> Mathematics::IntpBilinear2<Real>::blend{ std::array<Real, 2>{ 1.0f, -1.0f },
                                                                                  std::array<Real, 2>{ 0.0f, 1.0f } };

#endif  // MATHEMATICS_INTERPOLATION_INTP_BILINEAR2_DETAIL_H