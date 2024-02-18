///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/09 10:09)

#ifndef MATHEMATICS_INTERPOLATION_INTP_TRICUBIC3_DETAIL_H
#define MATHEMATICS_INTERPOLATION_INTP_TRICUBIC3_DETAIL_H

#include "IntpTricubic3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/MemoryTools/Array3Detail.h"
#include "Mathematics/Base/MathDetail.h"

template <typename Real>
Mathematics::IntpTricubic3<Real>::IntpTricubic3(int xBound, int yBound, int zBound, Real xMin, Real xSpacing, Real yMin, Real ySpacing, Real zMin, Real zSpacing, const CoreTools::Array3<Real>& f, bool catmullRom)
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
      f{ f },
      blend{ (catmullRom ? crBlend : bsBlend) }
{
    MATHEMATICS_ASSERTION_0(xBound >= 4 && yBound >= 4 && zBound >= 4, "无效输入。\n");
    MATHEMATICS_ASSERTION_0(xSpacing > Math<Real>::GetValue(0) && ySpacing > Math<Real>::GetValue(0) && zSpacing > Math<Real>::GetValue(0), "无效输入。\n");

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::IntpTricubic3<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
int Mathematics::IntpTricubic3<Real>::GetXBound() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return xBound;
}

template <typename Real>
int Mathematics::IntpTricubic3<Real>::GetYBound() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return yBound;
}

template <typename Real>
int Mathematics::IntpTricubic3<Real>::GetZBound() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return zBound;
}

template <typename Real>
int Mathematics::IntpTricubic3<Real>::GetQuantity() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return quantity;
}

template <typename Real>
CoreTools::Array3<Real> Mathematics::IntpTricubic3<Real>::GetF() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return f;
}

template <typename Real>
Real Mathematics::IntpTricubic3<Real>::GetXMin() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return xMin;
}

template <typename Real>
Real Mathematics::IntpTricubic3<Real>::GetXMax() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return xMax;
}

template <typename Real>
Real Mathematics::IntpTricubic3<Real>::GetXSpacing() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return xSpacing;
}

template <typename Real>
Real Mathematics::IntpTricubic3<Real>::GetYMin() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return yMin;
}

template <typename Real>
Real Mathematics::IntpTricubic3<Real>::GetYMax() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return yMax;
}

template <typename Real>
Real Mathematics::IntpTricubic3<Real>::GetYSpacing() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return ySpacing;
}

template <typename Real>
Real Mathematics::IntpTricubic3<Real>::GetZMin() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return zMin;
}

template <typename Real>
Real Mathematics::IntpTricubic3<Real>::GetZMax() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return zMax;
}

template <typename Real>
Real Mathematics::IntpTricubic3<Real>::GetZSpacing() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return zSpacing;
}

template <typename Real>
Real Mathematics::IntpTricubic3<Real>::operator()(Real x, Real y, Real z) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    auto xIndex = (x - xMin) * invXSpacing;
    auto ix = boost::numeric_cast<int>(xIndex);
    if (ix < 0 || ix > xBound - 1)
    {
        return Math<Real>::maxReal;
    }

    auto yIndex = (y - yMin) * invYSpacing;
    auto iy = boost::numeric_cast<int>(yIndex);
    if (iy < 0 || iy > yBound - 1)
    {
        return Math<Real>::maxReal;
    }

    auto zIndex = (z - zMin) * invZSpacing;
    auto iz = boost::numeric_cast<int>(zIndex);
    if (iz < 0 || iz > zBound - 1)
    {
        return Math<Real>::maxReal;
    }

    std::array<Real, 4> u{};
    u.at(0) = Math<Real>::GetValue(1);
    u.at(1) = xIndex - ix;
    u.at(2) = u.at(1) * u.at(1);
    u.at(3) = u.at(1) * u.at(2);

    std::array<Real, 4> v{};
    v.at(0) = Math<Real>::GetValue(1);
    v.at(1) = yIndex - iy;
    v.at(2) = v.at(1) * v.at(1);
    v.at(3) = v.at(1) * v.at(2);

    std::array<Real, 4> w{};
    w.at(0) = Math<Real>::GetValue(1);
    w.at(1) = zIndex - iz;
    w.at(2) = w.at(1) * w.at(1);
    w.at(3) = w.at(1) * w.at(2);

    std::array<Real, 4> p{};
    std::array<Real, 4> q{};
    std::array<Real, 4> r{};

    for (auto row = 0; row < 4; ++row)
    {
        p.at(row) = Math<Real>::GetValue(0);
        q.at(row) = Math<Real>::GetValue(0);
        r.at(row) = Math<Real>::GetValue(0);
        for (auto col = 0; col < 4; ++col)
        {
            p.at(row) += blend.at(row).at(col) * u.at(col);
            q.at(row) += blend.at(row).at(col) * v.at(col);
            r.at(row) += blend.at(row).at(col) * w.at(col);
        }
    }

    --ix;
    --iy;
    --iz;
    auto result = Math<Real>::GetValue(0);
    for (auto slice = 0; slice < 4; ++slice)
    {
        auto zClamp = iz + slice;
        if (zClamp < 0)
        {
            zClamp = 0;
        }
        else if (zClamp > zBound - 1)
        {
            zClamp = zBound - 1;
        }

        for (auto row = 0; row < 4; ++row)
        {
            auto yClamp = iy + row;
            if (yClamp < 0)
            {
                yClamp = 0;
            }
            else if (yClamp > yBound - 1)
            {
                yClamp = yBound - 1;
            }

            for (auto col = 0; col < 4; ++col)
            {
                auto xClamp = ix + col;
                if (xClamp < 0)
                {
                    xClamp = 0;
                }
                else if (xClamp > xBound - 1)
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
Real Mathematics::IntpTricubic3<Real>::operator()(int xOrder, int yOrder, int zOrder, Real x, Real y, Real z) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    auto xIndex = (x - xMin) * invXSpacing;
    auto ix = boost::numeric_cast<int>(xIndex);
    if (ix < 0 || ix > xBound - 1)
    {
        return Math<Real>::maxReal;
    }

    auto yIndex = (y - yMin) * invYSpacing;
    auto iy = boost::numeric_cast<int>(yIndex);

    if (iy < 0 || iy > yBound - 1)
    {
        return Math<Real>::maxReal;
    }

    auto zIndex = (z - zMin) * invZSpacing;
    auto iz = boost::numeric_cast<int>(zIndex);
    if (iz < 0 || iz > zBound - 1)
    {
        return Math<Real>::maxReal;
    }

    std::array<Real, 4> u{};
    Real xMult{};
    switch (xOrder)
    {
        case 0:
        {
            auto dx = xIndex - ix;
            u.at(0) = Math<Real>::GetValue(1);
            u.at(1) = dx;
            u.at(2) = dx * u.at(1);
            u.at(3) = dx * u.at(2);
            xMult = Math<Real>::GetValue(1);
        }
        break;
        case 1:
        {
            auto dx = xIndex - ix;
            u.at(0) = Math<Real>::GetValue(0);
            u.at(1) = Math<Real>::GetValue(1);
            u.at(2) = (Math<Real>::GetValue(2)) * dx;
            u.at(3) = (Math<Real>::GetValue(3)) * dx * dx;
            xMult = invXSpacing;
        }
        break;
        case 2:
        {
            auto dx = xIndex - ix;
            u.at(0) = Math<Real>::GetValue(0);
            u.at(1) = Math<Real>::GetValue(0);
            u.at(2) = Math<Real>::GetValue(2);
            u.at(3) = (Math<Real>::GetValue(6)) * dx;
            xMult = invXSpacing * invXSpacing;
        }
        break;
        case 3:
        {
            u.at(0) = Math<Real>::GetValue(0);
            u.at(1) = Math<Real>::GetValue(0);
            u.at(2) = Math<Real>::GetValue(0);
            u.at(3) = Math<Real>::GetValue(6);
            xMult = invXSpacing * invXSpacing * invXSpacing;
        }
        break;
        default:
            return Math<Real>::GetValue(0);
    }

    std::array<Real, 4> v{};
    Real yMult{};
    switch (yOrder)
    {
        case 0:
        {
            auto dy = yIndex - iy;
            v.at(0) = Math<Real>::GetValue(1);
            v.at(1) = dy;
            v.at(2) = dy * v.at(1);
            v.at(3) = dy * v.at(2);
            yMult = Math<Real>::GetValue(1);
        }
        break;
        case 1:
        {
            auto dy = yIndex - iy;
            v.at(0) = Math<Real>::GetValue(0);
            v.at(1) = Math<Real>::GetValue(1);
            v.at(2) = (Math<Real>::GetValue(2)) * dy;
            v.at(3) = (Math<Real>::GetValue(3)) * dy * dy;
            yMult = invYSpacing;
        }
        break;
        case 2:
        {
            auto dy = yIndex - iy;
            v.at(0) = Math<Real>::GetValue(0);
            v.at(1) = Math<Real>::GetValue(0);
            v.at(2) = Math<Real>::GetValue(2);
            v.at(3) = (Math<Real>::GetValue(6)) * dy;
            yMult = invYSpacing * invYSpacing;
        }
        break;
        case 3:
        {
            v.at(0) = Math<Real>::GetValue(0);
            v.at(1) = Math<Real>::GetValue(0);
            v.at(2) = Math<Real>::GetValue(0);
            v.at(3) = Math<Real>::GetValue(6);
            yMult = invYSpacing * invYSpacing * invYSpacing;
        }
        break;
        default:
            return Math<Real>::GetValue(0);
    }

    std::array<Real, 4> w{};
    Real zMult{};
    switch (zOrder)
    {
        case 0:
        {
            auto dz = zIndex - iz;
            w.at(0) = Math<Real>::GetValue(1);
            w.at(1) = dz;
            w.at(2) = dz * w.at(1);
            w.at(3) = dz * w.at(2);
            zMult = Math<Real>::GetValue(1);
        }
        break;
        case 1:
        {
            auto dz = zIndex - iz;
            w.at(0) = Math<Real>::GetValue(0);
            w.at(1) = Math<Real>::GetValue(1);
            w.at(2) = (Math<Real>::GetValue(2)) * dz;
            w.at(3) = (Math<Real>::GetValue(3)) * dz * dz;
            zMult = invZSpacing;
        }
        break;
        case 2:
        {
            auto dz = zIndex - iz;
            w.at(0) = Math<Real>::GetValue(0);
            w.at(1) = Math<Real>::GetValue(0);
            w.at(2) = Math<Real>::GetValue(2);
            w.at(3) = (Math<Real>::GetValue(6)) * dz;
            zMult = invZSpacing * invZSpacing;
        }
        break;
        case 3:
        {
            w.at(0) = Math<Real>::GetValue(0);
            w.at(1) = Math<Real>::GetValue(0);
            w.at(2) = Math<Real>::GetValue(0);
            w.at(3) = Math<Real>::GetValue(6);
            zMult = invZSpacing * invZSpacing * invZSpacing;
        }
        break;
        default:
            return Math<Real>::GetValue(0);
    }

    std::array<Real, 4> p{};
    std::array<Real, 4> q{};
    std::array<Real, 4> r{};

    for (auto row = 0; row < 4; ++row)
    {
        p.at(row) = Math<Real>::GetValue(0);
        q.at(row) = Math<Real>::GetValue(0);
        r.at(row) = Math<Real>::GetValue(0);
        for (auto col = 0; col < 4; ++col)
        {
            p.at(row) += blend.at(row).at(col) * u.at(col);
            q.at(row) += blend.at(row).at(col) * v.at(col);
            r.at(row) += blend.at(row).at(col) * w.at(col);
        }
    }

    --ix;
    --iy;
    --iz;
    auto result = Math<Real>::GetValue(0);
    for (auto slice = 0; slice < 4; ++slice)
    {
        auto zClamp = iz + slice;
        if (zClamp < 0)
        {
            zClamp = 0;
        }
        else if (zClamp > zBound - 1)
        {
            zClamp = zBound - 1;
        }

        for (auto row = 0; row < 4; ++row)
        {
            auto yClamp = iy + row;
            if (yClamp < 0)
            {
                yClamp = 0;
            }
            else if (yClamp > yBound - 1)
            {
                yClamp = yBound - 1;
            }

            for (auto col = 0; col < 4; ++col)
            {
                auto xClamp = ix + col;
                if (xClamp < 0)
                {
                    xClamp = 0;
                }
                else if (xClamp > xBound - 1)
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
const std::array<std::array<Real, 4>, 4> Mathematics::IntpTricubic3<Real>::crBlend{ std::array<Real, 4>{ Math<Real>::GetValue(0), Math<Real>::GetRational(-1, 2), Math<Real>::GetValue(1), Math<Real>::GetRational(-1, 2) },
                                                                                    std::array<Real, 4>{ Math<Real>::GetValue(1), Math<Real>::GetValue(0), Math<Real>::GetRational(-5, 2), Math<Real>::GetRational(3, 2) },
                                                                                    std::array<Real, 4>{ Math<Real>::GetValue(0), Math<Real>::GetRational(1, 2), Math<Real>::GetValue(2), -Math<Real>::GetRational(-3, 2) },
                                                                                    std::array<Real, 4>{ Math<Real>::GetValue(0), Math<Real>::GetValue(0), Math<Real>::GetRational(-1, 2), Math<Real>::GetRational(1, 2) } };

template <typename Real>
const std::array<std::array<Real, 4>, 4> Mathematics::IntpTricubic3<Real>::bsBlend{ std::array<Real, 4>{ Math<Real>::GetRational(1, 6), Math<Real>::GetRational(-3, 6), Math<Real>::GetRational(3, 6), Math<Real>::GetRational(-1, 6) },
                                                                                    std::array<Real, 4>{ Math<Real>::GetRational(4, 6), Math<Real>::GetRational(0, 6), Math<Real>::GetRational(-6, 6), Math<Real>::GetRational(3, 6) },
                                                                                    std::array<Real, 4>{ Math<Real>::GetRational(1, 6), Math<Real>::GetRational(3, 6), Math<Real>::GetRational(3, 6), Math<Real>::GetRational(-3, 6) },
                                                                                    std::array<Real, 4>{ Math<Real>::GetRational(0, 6), Math<Real>::GetRational(0, 6), Math<Real>::GetRational(0, 6), Math<Real>::GetRational(1, 6) } };

#endif  // MATHEMATICS_INTERPOLATION_INTP_TRICUBIC3_DETAIL_H