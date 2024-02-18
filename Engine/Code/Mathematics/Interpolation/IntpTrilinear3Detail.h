///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/09 10:09)

#ifndef MATHEMATICS_INTERPOLATION_INTP_TRILINEAR3_DETAIL_H
#define MATHEMATICS_INTERPOLATION_INTP_TRILINEAR3_DETAIL_H

#include "IntpTrilinear3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/MemoryTools/Array3Detail.h"
#include "Mathematics/Base/MathDetail.h"

template <typename Real>
Mathematics::IntpTrilinear3<Real>::IntpTrilinear3(int xBound, int yBound, int zBound, Real xMin, Real xSpacing, Real yMin, Real ySpacing, Real zMin, Real zSpacing, const CoreTools::Array3<Real>& f)
    : xBound{ xBound },
      yBound{ yBound },
      zBound{ zBound },
      quantity{ xBound * yBound * zBound },
      xMin{ xMin },
      xMax{ xMin + xSpacing * (boost::numeric_cast<size_t>(xBound) - 1) },
      xSpacing{ xSpacing },
      invXSpacing{ (Math<Real>::GetValue(1)) / xSpacing },
      yMin{ yMin },
      yMax{ yMin + ySpacing * (boost::numeric_cast<size_t>(yBound) - 1) },
      ySpacing{ ySpacing },
      invYSpacing{ (Math<Real>::GetValue(1)) / ySpacing },
      zMin{ zMin },
      zMax{ yMin + zSpacing * (boost::numeric_cast<size_t>(zBound) - 1) },
      zSpacing{ zSpacing },
      invZSpacing{ (Math<Real>::GetValue(1)) / zSpacing },
      f{ f }
{
    MATHEMATICS_ASSERTION_0(xBound >= 2 && yBound >= 2 && zBound >= 2, "无效输入。\n");
    MATHEMATICS_ASSERTION_0(xSpacing > Math<Real>::GetValue(0) && ySpacing > Math<Real>::GetValue(0) && zSpacing > Math<Real>::GetValue(0), "无效输入。\n");

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::IntpTrilinear3<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
int Mathematics::IntpTrilinear3<Real>::GetXBound() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return xBound;
}

template <typename Real>
int Mathematics::IntpTrilinear3<Real>::GetYBound() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return yBound;
}

template <typename Real>
int Mathematics::IntpTrilinear3<Real>::GetZBound() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return zBound;
}

template <typename Real>
int Mathematics::IntpTrilinear3<Real>::GetQuantity() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return quantity;
}

template <typename Real>
CoreTools::Array3<Real> Mathematics::IntpTrilinear3<Real>::GetF() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return f;
}

template <typename Real>
Real Mathematics::IntpTrilinear3<Real>::GetXMin() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return xMin;
}

template <typename Real>
Real Mathematics::IntpTrilinear3<Real>::GetXMax() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return xMax;
}

template <typename Real>
Real Mathematics::IntpTrilinear3<Real>::GetXSpacing() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return xSpacing;
}

template <typename Real>
Real Mathematics::IntpTrilinear3<Real>::GetYMin() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return yMin;
}

template <typename Real>
Real Mathematics::IntpTrilinear3<Real>::GetYMax() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return yMax;
}

template <typename Real>
Real Mathematics::IntpTrilinear3<Real>::GetYSpacing() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return ySpacing;
}

template <typename Real>
Real Mathematics::IntpTrilinear3<Real>::GetZMin() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return zMin;
}

template <typename Real>
Real Mathematics::IntpTrilinear3<Real>::GetZMax() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return zMax;
}

template <typename Real>
Real Mathematics::IntpTrilinear3<Real>::GetZSpacing() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return zSpacing;
}

template <typename Real>
Real Mathematics::IntpTrilinear3<Real>::operator()(Real x, Real y, Real z) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    if (x < xMin || x > xMax || y < yMin || y > yMax || z < zMin || y > zMax)
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

    auto zIndex = (z - zMin) * invZSpacing;
    auto iz = boost::numeric_cast<int>(zIndex);

    if (iz < 0)
    {
        iz = 0;
    }
    else if (iz >= zBound)
    {
        iz = zBound - 1;
    }

    std::array<Real, 2> u{ Math<Real>::GetValue(1), xIndex - ix };

    std::array<Real, 2> v{ Math<Real>::GetValue(1), yIndex - iy };

    std::array<Real, 2> w{ Math<Real>::GetValue(1), zIndex - iz };

    std::array<Real, 2> p{};
    std::array<Real, 2> q{};
    std::array<Real, 2> r{};

    for (auto row = 0; row < 2; ++row)
    {
        p.at(row) = Math<Real>::GetValue(0);
        q.at(row) = Math<Real>::GetValue(0);
        r.at(row) = Math<Real>::GetValue(0);
        for (auto col = 0; col < 2; ++col)
        {
            p.at(row) += blend.at(row).at(col) * u.at(col);
            q.at(row) += blend.at(row).at(col) * v.at(col);
            r.at(row) += blend.at(row).at(col) * w.at(col);
        }
    }

    auto result = Math<Real>::GetValue(0);
    for (auto slice = 0; slice < 2; ++slice)
    {
        auto zClamp = iz + slice;
        if (zClamp >= zBound)
        {
            zClamp = zBound - 1;
        }

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

                result += p.at(col) * q.at(row) * r.at(slice) * f(xClamp, yClamp, zClamp);
            }
        }
    }

    return result;
}

template <typename Real>
Real Mathematics::IntpTrilinear3<Real>::operator()(int xOrder, int yOrder, int zOrder, Real x, Real y, Real z) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    if (x < xMin || x > xMax || y < yMin || y > yMax || z < zMin || y > zMax)
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

    auto zIndex = (z - zMin) * invZSpacing;
    auto iz = boost::numeric_cast<int>(zIndex);
    if (iz < 0)
    {
        iz = 0;
    }
    else if (iz >= zBound)
    {
        iz = zBound - 1;
    }

    std::array<Real, 2> u{};
    Real dx{};
    Real xMult{};
    switch (xOrder)
    {
        case 0:
            dx = xIndex - ix;
            u.at(0) = Math<Real>::GetValue(1);
            u.at(1) = dx;
            xMult = Math<Real>::GetValue(1);
            break;
        case 1:
            dx = xIndex - ix;
            u.at(0) = Math<Real>::GetValue(0);
            u.at(1) = Math<Real>::GetValue(1);
            xMult = invXSpacing;
            break;
        default:
            return Math<Real>::GetValue(0);
    }

    std::array<Real, 2> v{};
    Real dy{};
    Real yMult{};
    switch (yOrder)
    {
        case 0:
            dy = yIndex - iy;
            v.at(0) = Math<Real>::GetValue(1);
            v.at(1) = dy;
            yMult = Math<Real>::GetValue(1);
            break;
        case 1:
            dy = yIndex - iy;
            v.at(0) = Math<Real>::GetValue(0);
            v.at(1) = Math<Real>::GetValue(1);
            yMult = invYSpacing;
            break;
        default:
            return Math<Real>::GetValue(0);
    }

    std::array<Real, 2> w{};
    Real dz{};
    Real zMult{};
    switch (zOrder)
    {
        case 0:
            dz = zIndex - iz;
            w.at(0) = Math<Real>::GetValue(1);
            w.at(1) = dz;
            zMult = Math<Real>::GetValue(1);
            break;
        case 1:
            dz = zIndex - iz;
            w.at(0) = Math<Real>::GetValue(0);
            w.at(1) = Math<Real>::GetValue(1);
            zMult = invZSpacing;
            break;
        default:
            return Math<Real>::GetValue(0);
    }

    std::array<Real, 2> p{};
    std::array<Real, 2> q{};
    std::array<Real, 2> r{};

    for (auto row = 0; row < 2; ++row)
    {
        p.at(row) = Math<Real>::GetValue(0);
        q.at(row) = Math<Real>::GetValue(0);
        r.at(row) = Math<Real>::GetValue(0);
        for (auto col = 0; col < 2; ++col)
        {
            p.at(row) += blend.at(row).at(col) * u.at(col);
            q.at(row) += blend.at(row).at(col) * v.at(col);
            r.at(row) += blend.at(row).at(col) * w.at(col);
        }
    }

    auto result = Math<Real>::GetValue(0);
    for (auto slice = 0; slice < 2; ++slice)
    {
        auto zClamp = iz + slice;
        if (zClamp >= zBound)
        {
            zClamp = zBound - 1;
        }

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

                result += p.at(col) * q.at(row) * r.at(slice) * f(xClamp, yClamp, zClamp);
            }
        }
    }
    result *= xMult * yMult * zMult;

    return result;
}

template <typename Real>
const std::array<std::array<Real, 2>, 2> Mathematics::IntpTrilinear3<Real>::blend{ std::array<Real, 2>{ Math<Real>::GetValue(1), Math<Real>::GetValue(-1) }, std::array<Real, 2>{ Math<Real>::GetValue(0), Math<Real>::GetValue(1) } };

#endif  // MATHEMATICS_INTERPOLATION_INTP_TRILINEAR3_DETAIL_H