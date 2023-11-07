///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/09 10:07)

#ifndef MATHEMATICS_INTERPOLATION_INTP_AKIMA_UNIFORM3_DETAIL_H
#define MATHEMATICS_INTERPOLATION_INTP_AKIMA_UNIFORM3_DETAIL_H

#include "IntpAkimaUniform3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Base/MathDetail.h"

template <typename Real>
Mathematics::IntpAkimaUniform3<Real>::IntpAkimaUniform3(int xBound, int yBound, int zBound, Real xMin, Real xSpacing, Real yMin, Real ySpacing, Real zMin, Real zSpacing, const Container& f)
    : xBound{ xBound },
      yBound{ yBound },
      zBound{ zBound },
      quantity{ xBound * yBound * zBound },
      fContainer{ f },
      polynomialContainer{},
      xMin{ xMin },
      xMax{ xMin + xSpacing * Math<Real>::GetValue(xBound - 1) },
      xSpacing{ xSpacing },
      yMin{ yMin },
      yMax{ yMin + ySpacing * Math<Real>::GetValue(yBound - 1) },
      ySpacing{ ySpacing },
      zMin{ zMin },
      zMax{ zMin + zSpacing * Math<Real>::GetValue(zBound - 1) },
      zSpacing{ zSpacing }
{
    MATHEMATICS_ASSERTION_0(xBound >= 3 && yBound >= 3 && zBound >= 3, "无效输入。\n");
    MATHEMATICS_ASSERTION_0(xSpacing > Math<Real>::GetValue(0) && ySpacing > Math<Real>::GetValue(0) && zSpacing > Math<Real>::GetValue(0), "无效输入。\n");

    auto fx = GetFX();
    auto fy = GetFY();
    auto fz = GetFZ();

    auto fxy = GetFXY();
    auto fxz = GetFXZ();
    auto fyz = GetFYZ();

    auto fxyz = GetFXYZ();

    GetPolynomials(fx, fy, fz, fxy, fxz, fyz, fxyz);

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::IntpAkimaUniform3<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
typename Mathematics::IntpAkimaUniform3<Real>::Container Mathematics::IntpAkimaUniform3<Real>::GetFX()
{
    // xslope[z][y][x]
    const auto xSlopeSize = xBound + 3;
    Container slope(zBound, std::vector<std::vector<Real>>(yBound, std::vector<Real>(xSlopeSize)));
    auto invDX = (Math<Real>::GetValue(1)) / xSpacing;
    for (auto iz = 0; iz < zBound; ++iz)
    {
        for (auto iy = 0; iy < yBound; ++iy)
        {
            for (auto ix = 0; ix < xBound - 1; ++ix)
            {
                slope.at(iz).at(iy).at(boost::numeric_cast<size_t>(ix) + 2) = (fContainer.at(iz).at(iy).at(boost::numeric_cast<size_t>(ix) + 1) - fContainer.at(iz).at(iy).at(ix)) * invDX;
            }

            slope.at(iz).at(iy).at(1) = (Math<Real>::GetValue(2)) * slope.at(iz).at(iy).at(2) - slope.at(iz).at(iy).at(3);
            slope.at(iz).at(iy).at(0) = (Math<Real>::GetValue(2)) * slope.at(iz).at(iy).at(1) - slope.at(iz).at(iy).at(2);
            slope.at(iz).at(iy).at(boost::numeric_cast<size_t>(xBound) + 1) = (Math<Real>::GetValue(2)) * slope.at(iz).at(iy).at(xBound) - slope.at(iz).at(iy).at(boost::numeric_cast<size_t>(xBound) - 1);
            slope.at(iz).at(iy).at(boost::numeric_cast<size_t>(xBound) + 2) = (Math<Real>::GetValue(2)) * slope.at(iz).at(iy).at(boost::numeric_cast<size_t>(xBound) + 1) - slope.at(iz).at(iy).at(xBound);
        }
    }

    Container fx(zBound, std::vector<std::vector<Real>>(yBound, std::vector<Real>(xBound)));

    for (auto iz = 0; iz < zBound; ++iz)
    {
        for (auto iy = 0; iy < yBound; ++iy)
        {
            for (auto ix = 0; ix < xBound; ++ix)
            {
                std::vector<Real> derivative{ slope.at(iz).at(iy).at(ix), slope.at(iz).at(iy).at(boost::numeric_cast<size_t>(ix) + 1), slope.at(iz).at(iy).at(boost::numeric_cast<size_t>(ix) + 2), slope.at(iz).at(iy).at(boost::numeric_cast<size_t>(ix) + 3) };
                fx.at(iz).at(iy).at(ix) = ComputeDerivative(derivative);
            }
        }
    }

    return fx;
}

template <typename Real>
typename Mathematics::IntpAkimaUniform3<Real>::Container Mathematics::IntpAkimaUniform3<Real>::GetFY()
{
    // yslope[z][x][y]
    const auto ySlopeSize = yBound + 3;
    Container slope(zBound, std::vector<std::vector<Real>>(xBound, std::vector<Real>(ySlopeSize)));
    auto invDY = (Math<Real>::GetValue(1)) / ySpacing;
    for (auto iz = 0; iz < zBound; ++iz)
    {
        for (auto ix = 0; ix < xBound; ++ix)
        {
            for (auto iy = 0; iy < yBound - 1; ++iy)
            {
                slope.at(iz).at(ix).at(boost::numeric_cast<size_t>(iy) + 2) = (fContainer.at(iz).at(boost::numeric_cast<size_t>(iy) + 1).at(ix) - fContainer.at(iz).at(iy).at(ix)) * invDY;
            }

            slope.at(iz).at(ix).at(1) = (Math<Real>::GetValue(2)) * slope.at(iz).at(ix).at(2) - slope.at(iz).at(ix).at(3);
            slope.at(iz).at(ix).at(0) = (Math<Real>::GetValue(2)) * slope.at(iz).at(ix).at(1) - slope.at(iz).at(ix).at(2);
            slope.at(iz).at(ix).at(boost::numeric_cast<size_t>(yBound) + 1) = (Math<Real>::GetValue(2)) * slope.at(iz).at(ix).at(yBound) - slope.at(iz).at(ix).at(boost::numeric_cast<size_t>(yBound) - 1);
            slope.at(iz).at(ix).at(boost::numeric_cast<size_t>(yBound) + 2) = (Math<Real>::GetValue(2)) * slope.at(iz).at(ix).at(boost::numeric_cast<size_t>(yBound) + 1) - slope.at(iz).at(ix).at(yBound);
        }
    }

    Container fy(zBound, std::vector<std::vector<Real>>(yBound, std::vector<Real>(xBound)));
    for (auto iz = 0; iz < zBound; ++iz)
    {
        for (auto ix = 0; ix < xBound; ++ix)
        {
            for (auto iy = 0; iy < yBound; ++iy)
            {
                std::vector<Real> derivative{ slope.at(iz).at(ix).at(iy), slope.at(iz).at(ix).at(boost::numeric_cast<size_t>(iy) + 1), slope.at(iz).at(ix).at(boost::numeric_cast<size_t>(iy) + 2), slope.at(iz).at(ix).at(boost::numeric_cast<size_t>(iy) + 3) };
                fy.at(iz).at(iy).at(ix) = ComputeDerivative(derivative);
            }
        }
    }

    return fy;
}

template <typename Real>
typename Mathematics::IntpAkimaUniform3<Real>::Container Mathematics::IntpAkimaUniform3<Real>::GetFZ()
{
    // zslope[y][x][z]
    const auto zSlopeSize = zBound + 3;
    Container slope(yBound, std::vector<std::vector<Real>>(xBound, std::vector<Real>(zSlopeSize)));

    auto invDZ = (Math<Real>::GetValue(1)) / zSpacing;
    for (auto iy = 0; iy < yBound; ++iy)
    {
        for (auto ix = 0; ix < xBound; ++ix)
        {
            for (auto iz = 0; iz < zBound - 1; ++iz)
            {
                slope.at(iy).at(ix).at(boost::numeric_cast<size_t>(iz) + 2) = (fContainer.at(boost::numeric_cast<size_t>(iz) + 1).at(iy).at(ix) - fContainer.at(iz).at(iy).at(ix)) * invDZ;
            }

            slope.at(iy).at(ix).at(1) = (Math<Real>::GetValue(2)) * slope.at(iy).at(ix).at(2) - slope.at(iy).at(ix).at(3);
            slope.at(iy).at(ix).at(0) = (Math<Real>::GetValue(2)) * slope.at(iy).at(ix).at(1) - slope.at(iy).at(ix).at(2);
            slope.at(iy).at(ix).at(boost::numeric_cast<size_t>(zBound) + 1) = (Math<Real>::GetValue(2)) * slope.at(iy).at(ix).at(zBound) - slope.at(iy).at(ix).at(boost::numeric_cast<size_t>(zBound) - 1);
            slope.at(iy).at(ix).at(boost::numeric_cast<size_t>(zBound) + 2) = (Math<Real>::GetValue(2)) * slope.at(iy).at(ix).at(boost::numeric_cast<size_t>(zBound) + 1) - slope.at(iy).at(ix).at(zBound);
        }
    }

    Container fz(zBound, std::vector<std::vector<Real>>(yBound, std::vector<Real>(xBound)));

    for (auto iy = 0; iy < yBound; ++iy)
    {
        for (auto ix = 0; ix < xBound; ++ix)
        {
            for (auto iz = 0; iz < zBound; ++iz)
            {
                std::vector<Real> derivative{ slope.at(iy).at(ix).at(iz), slope.at(iy).at(ix).at(boost::numeric_cast<size_t>(iz) + 1), slope.at(iy).at(ix).at(boost::numeric_cast<size_t>(iz) + 2), slope.at(iy).at(ix).at(boost::numeric_cast<size_t>(iz) + 3) };
                fz.at(iz).at(iy).at(ix) = ComputeDerivative(derivative);
            }
        }
    }

    return fz;
}

template <typename Real>
typename Mathematics::IntpAkimaUniform3<Real>::Container Mathematics::IntpAkimaUniform3<Real>::GetFXY()
{
    const auto ix0 = xBound - 1;
    const auto ix1 = ix0 - 1;
    const auto ix2 = ix1 - 1;
    const auto iy0 = yBound - 1;
    const auto iy1 = iy0 - 1;
    const auto iy2 = iy1 - 1;

    Container fxy(zBound, std::vector<std::vector<Real>>(yBound, std::vector<Real>(xBound)));
    auto invDXDY = (Math<Real>::GetValue(1)) / (xSpacing * ySpacing);
    for (auto iz = 0; iz < zBound; ++iz)
    {
        const auto xBoundMinus1 = xBound - 1;
        const auto yBoundMinus1 = yBound - 1;

        fxy.at(iz).at(0).at(0) = Math<Real>::GetRational(1, 4) * invDXDY * ((Math<Real>::GetValue(9)) * fContainer.at(iz).at(0).at(0) - (Math<Real>::GetValue(12)) * fContainer.at(iz).at(0).at(1) + (Math<Real>::GetValue(3)) * fContainer.at(iz).at(0).at(2) - (Math<Real>::GetValue(12)) * fContainer.at(iz).at(1).at(0) + (Math<Real>::GetValue(16)) * fContainer.at(iz).at(1).at(1) - (Math<Real>::GetValue(4)) * fContainer.at(iz).at(1).at(2) + (Math<Real>::GetValue(3)) * fContainer.at(iz).at(2).at(0) - (Math<Real>::GetValue(4)) * fContainer.at(iz).at(2).at(1) + fContainer.at(iz).at(2).at(2));

        fxy.at(iz).at(0).at(xBoundMinus1) = Math<Real>::GetRational(1, 4) * invDXDY * ((Math<Real>::GetValue(9)) * fContainer.at(iz).at(0).at(ix0) - (Math<Real>::GetValue(12)) * fContainer.at(iz).at(0).at(ix1) + (Math<Real>::GetValue(3)) * fContainer.at(iz).at(0).at(ix2) - (Math<Real>::GetValue(12)) * fContainer.at(iz).at(1).at(ix0) + (Math<Real>::GetValue(16)) * fContainer.at(iz).at(1).at(ix1) - (Math<Real>::GetValue(4)) * fContainer.at(iz).at(1).at(ix2) + (Math<Real>::GetValue(3)) * fContainer.at(iz).at(2).at(ix0) - (Math<Real>::GetValue(4)) * fContainer.at(iz).at(2).at(ix1) + fContainer.at(iz).at(2).at(ix2));

        fxy.at(iz).at(yBoundMinus1).at(0) = Math<Real>::GetRational(1, 4) * invDXDY * ((Math<Real>::GetValue(9)) * fContainer.at(iz).at(iy0).at(0) - (Math<Real>::GetValue(12)) * fContainer.at(iz).at(iy0).at(1) + (Math<Real>::GetValue(3)) * fContainer.at(iz).at(iy0).at(2) - (Math<Real>::GetValue(12)) * fContainer.at(iz).at(iy1).at(0) + (Math<Real>::GetValue(16)) * fContainer.at(iz).at(iy1).at(1) - (Math<Real>::GetValue(4)) * fContainer.at(iz).at(iy1).at(2) + (Math<Real>::GetValue(3)) * fContainer.at(iz).at(iy2).at(0) - (Math<Real>::GetValue(4)) * fContainer.at(iz).at(iy2).at(1) + fContainer.at(iz).at(iy2).at(2));

        fxy.at(iz).at(yBoundMinus1).at(xBoundMinus1) = Math<Real>::GetRational(1, 4) * invDXDY * ((Math<Real>::GetValue(9)) * fContainer.at(iz).at(iy0).at(ix0) - (Math<Real>::GetValue(12)) * fContainer.at(iz).at(iy0).at(ix1) + (Math<Real>::GetValue(3)) * fContainer.at(iz).at(iy0).at(ix2) - (Math<Real>::GetValue(12)) * fContainer.at(iz).at(iy1).at(ix0) + (Math<Real>::GetValue(16)) * fContainer.at(iz).at(iy1).at(ix1) - (Math<Real>::GetValue(4)) * fContainer.at(iz).at(iy1).at(ix2) + (Math<Real>::GetValue(3)) * fContainer.at(iz).at(iy2).at(ix0) - (Math<Real>::GetValue(4)) * fContainer.at(iz).at(iy2).at(ix1) + fContainer.at(iz).at(iy2).at(ix2));

        for (auto ix = 1; ix < xBound - 1; ++ix)
        {
            const auto nextIX = ix + 1;
            const auto previousIX = ix - 1;
            fxy.at(iz).at(0).at(ix) = Math<Real>::GetRational(1, 4) * invDXDY * ((Math<Real>::GetValue(3)) * (fContainer.at(iz).at(0).at(previousIX) - fContainer.at(iz).at(0).at(nextIX)) - (Math<Real>::GetValue(4)) * (fContainer.at(iz).at(1).at(previousIX) - fContainer.at(iz).at(1).at(nextIX)) + (fContainer.at(iz).at(2).at(previousIX) - fContainer.at(iz).at(2).at(nextIX)));

            fxy.at(iz).at(yBoundMinus1).at(ix) = Math<Real>::GetRational(1, 4) * invDXDY * ((Math<Real>::GetValue(3)) * (fContainer.at(iz).at(iy0).at(previousIX) - fContainer.at(iz).at(iy0).at(nextIX)) - (Math<Real>::GetValue(4)) * (fContainer.at(iz).at(iy1).at(previousIX) - fContainer.at(iz).at(iy1).at(nextIX)) + (fContainer.at(iz).at(iy2).at(previousIX) - fContainer.at(iz).at(iy2).at(nextIX)));
        }

        for (auto iy = 1; iy < yBound - 1; ++iy)
        {
            const auto nextIY = iy + 1;
            const auto previousIY = iy - 1;
            fxy.at(iz).at(iy).at(0) = Math<Real>::GetRational(1, 4) * invDXDY * ((Math<Real>::GetValue(3)) * (fContainer.at(iz).at(previousIY).at(0) - fContainer.at(iz).at(nextIY).at(0)) - (Math<Real>::GetValue(4)) * (fContainer.at(iz).at(previousIY).at(1) - fContainer.at(iz).at(nextIY).at(1)) + (fContainer.at(iz).at(previousIY).at(2) - fContainer.at(iz).at(nextIY).at(2)));

            fxy.at(iz).at(iy).at(yBoundMinus1) = Math<Real>::GetRational(1, 4) * invDXDY * ((Math<Real>::GetValue(3)) * (fContainer.at(iz).at(previousIY).at(ix0) - fContainer.at(iz).at(nextIY).at(ix0)) - (Math<Real>::GetValue(4)) * (fContainer.at(iz).at(previousIY).at(ix1) - fContainer.at(iz).at(nextIY).at(ix1)) + (fContainer.at(iz).at(previousIY).at(ix2) - fContainer.at(iz).at(nextIY).at(ix2)));
        }

        for (auto iy = 1; iy < yBound - 1; ++iy)
        {
            for (auto ix = 1; ix < xBound - 1; ++ix)
            {
                const auto previousIX = ix - 1;
                const auto previousIY = iy - 1;

                const auto nextIX = ix + 1;
                const auto nextIY = iy + 1;

                fxy.at(iz).at(iy).at(ix) = Math<Real>::GetRational(1, 4) * invDXDY * (fContainer.at(iz).at(previousIY).at(previousIX) - fContainer.at(iz).at(previousIY).at(nextIX) - fContainer.at(iz).at(nextIY).at(previousIX) + fContainer.at(iz).at(nextIY).at(nextIX));
            }
        }
    }

    return fxy;
}

template <typename Real>
typename Mathematics::IntpAkimaUniform3<Real>::Container Mathematics::IntpAkimaUniform3<Real>::GetFXZ()
{
    const auto ix0 = xBound - 1;
    const auto ix1 = ix0 - 1;
    const auto ix2 = ix1 - 1;
    const auto iz0 = zBound - 1;
    const auto iz1 = iz0 - 1;
    const auto iz2 = iz1 - 1;

    Container fxz(zBound, std::vector<std::vector<Real>>(yBound, std::vector<Real>(xBound)));

    auto invDXDZ = (Math<Real>::GetValue(1)) / (xSpacing * zSpacing);
    for (auto iy = 0; iy < yBound; ++iy)
    {
        fxz.at(0).at(iy).at(0) = Math<Real>::GetRational(1, 4) * invDXDZ * ((Math<Real>::GetValue(9)) * fContainer.at(0).at(iy).at(0) - (Math<Real>::GetValue(12)) * fContainer.at(0).at(iy).at(1) + (Math<Real>::GetValue(3)) * fContainer.at(0).at(iy).at(2) - (Math<Real>::GetValue(12)) * fContainer.at(1).at(iy).at(0) + (Math<Real>::GetValue(16)) * fContainer.at(1).at(iy).at(1) - (Math<Real>::GetValue(4)) * fContainer.at(1).at(iy).at(2) + (Math<Real>::GetValue(3)) * fContainer.at(2).at(iy).at(0) - (Math<Real>::GetValue(4)) * fContainer.at(2).at(iy).at(1) + fContainer.at(2).at(iy).at(2));

        fxz.at(0).at(iy).at(ix0) = Math<Real>::GetRational(1, 4) * invDXDZ * ((Math<Real>::GetValue(9)) * fContainer.at(0).at(iy).at(ix0) - (Math<Real>::GetValue(12)) * fContainer.at(0).at(iy).at(ix1) + (Math<Real>::GetValue(3)) * fContainer.at(0).at(iy).at(ix2) - (Math<Real>::GetValue(12)) * fContainer.at(1).at(iy).at(ix0) + (Math<Real>::GetValue(16)) * fContainer.at(1).at(iy).at(ix1) - (Math<Real>::GetValue(4)) * fContainer.at(1).at(iy).at(ix2) + (Math<Real>::GetValue(3)) * fContainer.at(2).at(iy).at(ix0) - (Math<Real>::GetValue(4)) * fContainer.at(2).at(iy).at(ix1) + fContainer.at(2).at(iy).at(ix2));

        fxz.at(iz0).at(iy).at(0) = Math<Real>::GetRational(1, 4) * invDXDZ * ((Math<Real>::GetValue(9)) * fContainer.at(iz0).at(iy).at(0) - (Math<Real>::GetValue(12)) * fContainer.at(iz0).at(iy).at(1) + (Math<Real>::GetValue(3)) * fContainer.at(iz0).at(iy).at(2) - (Math<Real>::GetValue(12)) * fContainer.at(iz1).at(iy).at(0) + (Math<Real>::GetValue(16)) * fContainer.at(iz1).at(iy).at(1) - (Math<Real>::GetValue(4)) * fContainer.at(iz1).at(iy).at(2) + (Math<Real>::GetValue(3)) * fContainer.at(iz2).at(iy).at(0) - (Math<Real>::GetValue(4)) * fContainer.at(iz2).at(iy).at(1) + fContainer.at(iz2).at(iy).at(2));

        fxz.at(iz0).at(iy).at(ix0) = Math<Real>::GetRational(1, 4) * invDXDZ * ((Math<Real>::GetValue(9)) * fContainer.at(iz0).at(iy).at(ix0) - (Math<Real>::GetValue(12)) * fContainer.at(iz0).at(iy).at(ix1) + (Math<Real>::GetValue(3)) * fContainer.at(iz0).at(iy).at(ix2) - (Math<Real>::GetValue(12)) * fContainer.at(iz1).at(iy).at(ix0) + (Math<Real>::GetValue(16)) * fContainer.at(iz1).at(iy).at(ix1) - (Math<Real>::GetValue(4)) * fContainer.at(iz1).at(iy).at(ix2) + (Math<Real>::GetValue(3)) * fContainer.at(iz2).at(iy).at(ix0) - (Math<Real>::GetValue(4)) * fContainer.at(iz2).at(iy).at(ix1) + fContainer.at(iz2).at(iy).at(ix2));

        for (auto ix = 1; ix < xBound - 1; ++ix)
        {
            const auto previousIX = ix - 1;
            const auto nextIX = ix + 1;
            fxz.at(0).at(iy).at(ix) = Math<Real>::GetRational(1, 4) * invDXDZ * ((Math<Real>::GetValue(3)) * (fContainer.at(0).at(iy).at(previousIX) - fContainer.at(0).at(iy).at(nextIX)) - (Math<Real>::GetValue(4)) * (fContainer.at(1).at(iy).at(previousIX) - fContainer.at(1).at(iy).at(nextIX)) + (fContainer.at(2).at(iy).at(previousIX) - fContainer.at(2).at(iy).at(nextIX)));

            fxz.at(iz0).at(iy).at(ix) = Math<Real>::GetRational(1, 4) * invDXDZ * ((Math<Real>::GetValue(3)) * (fContainer.at(iz0).at(iy).at(previousIX) - fContainer.at(iz0).at(iy).at(nextIX)) - (Math<Real>::GetValue(4)) * (fContainer.at(iz1).at(iy).at(previousIX) - fContainer.at(iz1).at(iy).at(nextIX)) + (fContainer.at(iz2).at(iy).at(previousIX) - fContainer.at(iz2).at(iy).at(nextIX)));
        }

        for (auto iz = 1; iz < zBound - 1; ++iz)
        {
            const auto previousIZ = iz - 1;
            const auto nextIZ = iz + 1;
            fxz.at(iz).at(iy).at(0) = Math<Real>::GetRational(1, 4) * invDXDZ * ((Math<Real>::GetValue(3)) * (fContainer.at(previousIZ).at(iy).at(0) - fContainer.at(nextIZ).at(iy).at(0)) - (Math<Real>::GetValue(4)) * (fContainer.at(previousIZ).at(iy).at(1) - fContainer.at(nextIZ).at(iy).at(1)) + (fContainer.at(previousIZ).at(iy).at(2) - fContainer.at(nextIZ).at(iy).at(2)));

            fxz.at(iz).at(iy).at(ix0) = Math<Real>::GetRational(1, 4) * invDXDZ * ((Math<Real>::GetValue(3)) * (fContainer.at(previousIZ).at(iy).at(ix0) - fContainer.at(nextIZ).at(iy).at(ix0)) - (Math<Real>::GetValue(4)) * (fContainer.at(previousIZ).at(iy).at(ix1) - fContainer.at(nextIZ).at(iy).at(ix1)) + (fContainer.at(previousIZ).at(iy).at(ix2) - fContainer.at(nextIZ).at(iy).at(ix2)));
        }

        for (auto iz = 1; iz < zBound - 1; ++iz)
        {
            const auto previousIZ = iz - 1;
            const auto nextIZ = iz + 1;

            for (auto ix = 1; ix < xBound - 1; ++ix)
            {
                const auto previousIX = ix - 1;
                const auto nextIX = ix + 1;

                fxz.at(iz).at(iy).at(ix) = Math<Real>::GetRational(1, 4) * invDXDZ * (fContainer.at(previousIZ).at(iy).at(previousIX) - fContainer.at(previousIZ).at(iy).at(nextIX) - fContainer.at(nextIZ).at(iy).at(previousIX) + fContainer.at(nextIZ).at(iy).at(nextIX));
            }
        }
    }

    return fxz;
}

template <typename Real>
typename Mathematics::IntpAkimaUniform3<Real>::Container Mathematics::IntpAkimaUniform3<Real>::GetFYZ()
{
    const auto iy0 = yBound - 1;
    const auto iy1 = iy0 - 1;
    const auto iy2 = iy1 - 1;
    const auto iz0 = zBound - 1;
    const auto iz1 = iz0 - 1;
    const auto iz2 = iz1 - 1;

    Container fyz(zBound, std::vector<std::vector<Real>>(yBound, std::vector<Real>(xBound)));

    auto invDYDZ = (Math<Real>::GetValue(1)) / (ySpacing * zSpacing);
    for (auto ix = 0; ix < xBound; ++ix)
    {
        fyz.at(0).at(0).at(ix) = Math<Real>::GetRational(1, 4) * invDYDZ * ((Math<Real>::GetValue(9)) * fContainer.at(0).at(0).at(ix) - (Math<Real>::GetValue(12)) * fContainer.at(0).at(1).at(ix) + (Math<Real>::GetValue(3)) * fContainer.at(0).at(2).at(ix) - (Math<Real>::GetValue(12)) * fContainer.at(1).at(0).at(ix) + (Math<Real>::GetValue(16)) * fContainer.at(1).at(1).at(ix) - (Math<Real>::GetValue(4)) * fContainer.at(1).at(2).at(ix) + (Math<Real>::GetValue(3)) * fContainer.at(2).at(0).at(ix) - (Math<Real>::GetValue(4)) * fContainer.at(2).at(1).at(ix) + fContainer.at(2).at(2).at(ix));

        fyz.at(0).at(iy0).at(ix) = Math<Real>::GetRational(1, 4) * invDYDZ * ((Math<Real>::GetValue(9)) * fContainer.at(0).at(iy0).at(ix) - (Math<Real>::GetValue(12)) * fContainer.at(0).at(iy1).at(ix) + (Math<Real>::GetValue(3)) * fContainer.at(0).at(iy2).at(ix) - (Math<Real>::GetValue(12)) * fContainer.at(1).at(iy0).at(ix) + (Math<Real>::GetValue(16)) * fContainer.at(1).at(iy1).at(ix) - (Math<Real>::GetValue(4)) * fContainer.at(1).at(iy2).at(ix) + (Math<Real>::GetValue(3)) * fContainer.at(2).at(iy0).at(ix) - (Math<Real>::GetValue(4)) * fContainer.at(2).at(iy1).at(ix) + fContainer.at(2).at(iy2).at(ix));

        fyz.at(iz0).at(0).at(ix) = Math<Real>::GetRational(1, 4) * invDYDZ * ((Math<Real>::GetValue(9)) * fContainer.at(iz0).at(0).at(ix) - (Math<Real>::GetValue(12)) * fContainer.at(iz0).at(1).at(ix) + (Math<Real>::GetValue(3)) * fContainer.at(iz0).at(2).at(ix) - (Math<Real>::GetValue(12)) * fContainer.at(iz1).at(0).at(ix) + (Math<Real>::GetValue(16)) * fContainer.at(iz1).at(1).at(ix) - (Math<Real>::GetValue(4)) * fContainer.at(iz1).at(2).at(ix) + (Math<Real>::GetValue(3)) * fContainer.at(iz2).at(0).at(ix) - (Math<Real>::GetValue(4)) * fContainer.at(iz2).at(1).at(ix) + fContainer.at(iz2).at(2).at(ix));

        fyz.at(iz0).at(iy0).at(ix) = Math<Real>::GetRational(1, 4) * invDYDZ * ((Math<Real>::GetValue(9)) * fContainer.at(iz0).at(iy0).at(ix) - (Math<Real>::GetValue(12)) * fContainer.at(iz0).at(iy1).at(ix) + (Math<Real>::GetValue(3)) * fContainer.at(iz0).at(iy2).at(ix) - (Math<Real>::GetValue(12)) * fContainer.at(iz1).at(iy0).at(ix) + (Math<Real>::GetValue(16)) * fContainer.at(iz1).at(iy1).at(ix) - (Math<Real>::GetValue(4)) * fContainer.at(iz1).at(iy2).at(ix) + (Math<Real>::GetValue(3)) * fContainer.at(iz2).at(iy0).at(ix) - (Math<Real>::GetValue(4)) * fContainer.at(iz2).at(iy1).at(ix) + fContainer.at(iz2).at(iy2).at(ix));

        for (auto iy = 1; iy < yBound - 1; ++iy)
        {
            const auto previousIY = iy - 1;
            const auto nextIY = iy + 1;

            fyz.at(0).at(iy).at(ix) = Math<Real>::GetRational(1, 4) * invDYDZ * ((Math<Real>::GetValue(3)) * (fContainer.at(0).at(previousIY).at(ix) - fContainer.at(0).at(nextIY).at(ix)) - (Math<Real>::GetValue(4)) * (fContainer.at(1).at(previousIY).at(ix) - fContainer.at(1).at(nextIY).at(ix)) + (fContainer.at(2).at(previousIY).at(ix) - fContainer.at(2).at(nextIY).at(ix)));

            fyz.at(iz0).at(iy).at(ix) = Math<Real>::GetRational(1, 4) * invDYDZ * ((Math<Real>::GetValue(3)) * (fContainer.at(iz0).at(previousIY).at(ix) - fContainer.at(iz0).at(nextIY).at(ix)) - (Math<Real>::GetValue(4)) * (fContainer.at(iz1).at(previousIY).at(ix) - fContainer.at(iz1).at(nextIY).at(ix)) + (fContainer.at(iz2).at(previousIY).at(ix) - fContainer.at(iz2).at(nextIY).at(ix)));
        }

        for (auto iz = 1; iz < zBound - 1; ++iz)
        {
            const auto previousIZ = iz - 1;
            const auto nextIZ = iz + 1;

            fyz.at(iz).at(0).at(ix) = Math<Real>::GetRational(1, 4) * invDYDZ * ((Math<Real>::GetValue(3)) * (fContainer.at(previousIZ).at(0).at(ix) - fContainer.at(nextIZ).at(0).at(ix)) - (Math<Real>::GetValue(4)) * (fContainer.at(previousIZ).at(1).at(ix) - fContainer.at(nextIZ).at(1).at(ix)) + (fContainer.at(previousIZ).at(2).at(ix) - fContainer.at(nextIZ).at(2).at(ix)));

            fyz.at(iz).at(iy0).at(ix) = Math<Real>::GetRational(1, 4) * invDYDZ * ((Math<Real>::GetValue(3)) * (fContainer.at(previousIZ).at(iy0).at(ix) - fContainer.at(nextIZ).at(iy0).at(ix)) - (Math<Real>::GetValue(4)) * (fContainer.at(previousIZ).at(iy1).at(ix) - fContainer.at(nextIZ).at(iy1).at(ix)) + (fContainer.at(previousIZ).at(iy2).at(ix) - fContainer.at(nextIZ).at(iy2).at(ix)));
        }

        for (auto iz = 1; iz < zBound - 1; ++iz)
        {
            const auto previousIZ = iz - 1;
            const auto nextIZ = iz + 1;

            for (auto iy = 1; iy < yBound - 1; ++iy)
            {
                const auto previousIY = iy - 1;
                const auto nextIY = iy + 1;

                fyz.at(iz).at(iy).at(ix) = Math<Real>::GetRational(1, 4) * invDYDZ * (fContainer.at(previousIZ).at(previousIY).at(ix) - fContainer.at(previousIZ).at(nextIY).at(ix) - fContainer.at(nextIZ).at(previousIY).at(ix) + fContainer.at(nextIZ).at(nextIY).at(ix));
            }
        }
    }

    return fyz;
}

template <typename Real>
typename Mathematics::IntpAkimaUniform3<Real>::Container Mathematics::IntpAkimaUniform3<Real>::GetFXYZ()
{
    Container fxyz(zBound, std::vector<std::vector<Real>>(yBound, std::vector<Real>(xBound)));

    auto invDXDYDZ = (Math<Real>::GetValue(1)) / (xSpacing * ySpacing * zSpacing);

    std::array<Real, 3> cDer{ -Math<Real>::GetRational(1, 2), Math<Real>::GetValue(0), Math<Real>::GetRational(1, 2) };

    std::array<Real, 3> oDer{ -static_cast<Real>(1.5), Math<Real>::GetValue(2), -Math<Real>::GetRational(1, 2) };

    const auto xPreviousBound = xBound - 1;
    const auto yPreviousBound = yBound - 1;
    const auto zPreviousBound = zBound - 1;

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26451)

    fxyz.at(0).at(0).at(0) = Math<Real>::GetValue(0);
    fxyz.at(0).at(0).at(xPreviousBound) = Math<Real>::GetValue(0);
    fxyz.at(0).at(yPreviousBound).at(0) = Math<Real>::GetValue(0);
    fxyz.at(0).at(yPreviousBound).at(xPreviousBound) = Math<Real>::GetValue(0);
    fxyz.at(zPreviousBound).at(0).at(0) = Math<Real>::GetValue(0);
    fxyz.at(zPreviousBound).at(0).at(xPreviousBound) = Math<Real>::GetValue(0);
    fxyz.at(zPreviousBound).at(yPreviousBound).at(0) = Math<Real>::GetValue(0);
    fxyz.at(zPreviousBound).at(yPreviousBound).at(xPreviousBound) = Math<Real>::GetValue(0);
    for (auto iz = 0; iz <= 2; ++iz)
    {
        for (auto iy = 0; iy <= 2; ++iy)
        {
            for (auto ix = 0; ix <= 2; ++ix)
            {
                auto mask = invDXDYDZ * oDer.at(ix) * oDer.at(iy) * oDer.at(iz);

                fxyz.at(0).at(0).at(0) += mask * fContainer.at(iz).at(iy).at(ix);

                fxyz.at(0).at(0).at(xPreviousBound) += mask * fContainer.at(iz).at(iy).at(xBound - 1 - ix);

                fxyz.at(0).at(yPreviousBound).at(0) += mask * fContainer.at(iz).at(yBound - 1 - iy).at(ix);

                fxyz.at(0).at(yPreviousBound).at(xPreviousBound) += mask * fContainer.at(iz).at(yBound - 1 - iy).at(xBound - 1 - ix);

                fxyz.at(zPreviousBound).at(0).at(0) += mask * fContainer.at(zBound - 1 - iz).at(iy).at(ix);

                fxyz.at(zPreviousBound).at(0).at(xPreviousBound) += mask * fContainer.at(zBound - 1 - iz).at(iy).at(xBound - 1 - ix);

                fxyz.at(zPreviousBound).at(yPreviousBound).at(0) += mask * fContainer.at(zBound - 1 - iz).at(yBound - 1 - iy).at(ix);

                fxyz.at(zPreviousBound).at(yPreviousBound).at(xPreviousBound) += mask * fContainer.at(zBound - 1 - iz).at(yBound - 1 - iy).at(xBound - 1 - ix);
            }
        }
    }

    for (auto ix0 = 1; ix0 < xBound - 1; ++ix0)
    {
        fxyz.at(0).at(0).at(ix0) = Math<Real>::GetValue(0);
        fxyz.at(0).at(yPreviousBound).at(ix0) = Math<Real>::GetValue(0);
        fxyz.at(zPreviousBound).at(0).at(ix0) = Math<Real>::GetValue(0);
        fxyz.at(zPreviousBound).at(yPreviousBound).at(ix0) = Math<Real>::GetValue(0);
        for (auto iz = 0; iz <= 2; ++iz)
        {
            for (auto iy = 0; iy <= 2; ++iy)
            {
                for (auto ix = 0; ix <= 2; ++ix)
                {
                    auto mask = invDXDYDZ * cDer.at(ix) * oDer.at(iy) * oDer.at(iz);

                    fxyz.at(0).at(0).at(ix0) += mask * fContainer.at(iz).at(iy).at(ix0 + ix - 1);

                    fxyz.at(0).at(yPreviousBound).at(ix0) += mask * fContainer.at(iz).at(yBound - 1 - iy).at(ix0 + ix - 1);

                    fxyz.at(zPreviousBound).at(0).at(ix0) += mask * fContainer.at(zBound - 1 - iz).at(iy).at(ix0 + ix - 1);

                    fxyz.at(zPreviousBound).at(yPreviousBound).at(ix0) += mask * fContainer.at(zBound - 1 - iz).at(yBound - 1 - iy).at(ix0 + ix - 1);
                }
            }
        }
    }

    for (auto iy0 = 1; iy0 < yBound - 1; ++iy0)
    {
        fxyz.at(0).at(iy0).at(0) = Math<Real>::GetValue(0);
        fxyz.at(0).at(iy0).at(xPreviousBound) = Math<Real>::GetValue(0);
        fxyz.at(zPreviousBound).at(iy0).at(0) = Math<Real>::GetValue(0);
        fxyz.at(zPreviousBound).at(iy0).at(xPreviousBound) = Math<Real>::GetValue(0);
        for (auto iz = 0; iz <= 2; ++iz)
        {
            for (auto iy = 0; iy <= 2; ++iy)
            {
                for (auto ix = 0; ix <= 2; ++ix)
                {
                    auto mask = invDXDYDZ * oDer.at(ix) * cDer.at(iy) * oDer.at(iz);

                    fxyz.at(0).at(iy0).at(0) += mask * fContainer.at(iz).at(iy0 + iy - 1).at(ix);

                    fxyz.at(0).at(iy0).at(xPreviousBound) += mask * fContainer.at(iz).at(iy0 + iy - 1).at(xBound - 1 - ix);

                    fxyz.at(zPreviousBound).at(iy0).at(0) += mask * fContainer.at(zBound - 1 - iz).at(iy0 + iy - 1).at(ix);

                    fxyz.at(zPreviousBound).at(iy0).at(xPreviousBound) += mask * fContainer.at(zBound - 1 - iz).at(iy0 + iy - 1).at(xBound - 1 - ix);
                }
            }
        }
    }

    for (auto iz0 = 1; iz0 < zBound - 1; ++iz0)
    {
        fxyz.at(iz0).at(0).at(0) = Math<Real>::GetValue(0);
        fxyz.at(iz0).at(0).at(xPreviousBound) = Math<Real>::GetValue(0);
        fxyz.at(iz0).at(yPreviousBound).at(0) = Math<Real>::GetValue(0);
        fxyz.at(iz0).at(yPreviousBound).at(xPreviousBound) = Math<Real>::GetValue(0);
        for (auto iz = 0; iz <= 2; ++iz)
        {
            for (auto iy = 0; iy <= 2; ++iy)
            {
                for (auto ix = 0; ix <= 2; ++ix)
                {
                    auto mask = invDXDYDZ * oDer.at(ix) * oDer.at(iy) * cDer.at(iz);

                    fxyz.at(iz0).at(0).at(0) += mask * fContainer.at(iz0 + iz - 1).at(iy).at(ix);

                    fxyz.at(iz0).at(0).at(xPreviousBound) += mask * fContainer.at(iz0 + iz - 1).at(iy).at(xBound - 1 - ix);

                    fxyz.at(iz0).at(yPreviousBound).at(0) += mask * fContainer.at(iz0 + iz - 1).at(yBound - 1 - iy).at(ix);

                    fxyz.at(iz0).at(yPreviousBound).at(xPreviousBound) += mask * fContainer.at(iz0 + iz - 1).at(yBound - 1 - iy).at(xBound - 1 - ix);
                }
            }
        }
    }

    for (auto iy0 = 1; iy0 < yBound - 1; ++iy0)
    {
        for (auto ix0 = 1; ix0 < xBound - 1; ++ix0)
        {
            fxyz.at(0).at(iy0).at(ix0) = Math<Real>::GetValue(0);
            fxyz.at(zPreviousBound).at(iy0).at(ix0) = Math<Real>::GetValue(0);
            for (auto iz = 0; iz <= 2; ++iz)
            {
                for (auto iy = 0; iy <= 2; ++iy)
                {
                    for (auto ix = 0; ix <= 2; ++ix)
                    {
                        auto mask = invDXDYDZ * cDer.at(ix) * cDer.at(iy) * oDer.at(iz);

                        fxyz.at(0).at(iy0).at(ix0) += mask * fContainer.at(iz).at(iy0 + iy - 1).at(ix0 + ix - 1);

                        fxyz.at(zPreviousBound).at(iy0).at(ix0) += mask * fContainer.at(zBound - 1 - iz).at(iy0 + iy - 1).at(ix0 + ix - 1);
                    }
                }
            }
        }
    }

    for (auto iz0 = 1; iz0 < zBound - 1; ++iz0)
    {
        for (auto ix0 = 1; ix0 < xBound - 1; ++ix0)
        {
            fxyz.at(iz0).at(0).at(ix0) = Math<Real>::GetValue(0);
            fxyz.at(iz0).at(yPreviousBound).at(ix0) = Math<Real>::GetValue(0);
            for (auto iz = 0; iz <= 2; ++iz)
            {
                for (auto iy = 0; iy <= 2; ++iy)
                {
                    for (auto ix = 0; ix <= 2; ++ix)
                    {
                        auto mask = invDXDYDZ * cDer.at(ix) * oDer.at(iy) * cDer.at(iz);

                        fxyz.at(iz0).at(0).at(ix0) += mask * fContainer.at(iz0 + iz - 1).at(iy).at(ix0 + ix - 1);

                        fxyz.at(iz0).at(yPreviousBound).at(ix0) += mask * fContainer.at(iz0 + iz - 1).at(yBound - 1 - iy).at(ix0 + ix - 1);
                    }
                }
            }
        }
    }

    for (auto iz0 = 1; iz0 < zBound - 1; ++iz0)
    {
        for (auto iy0 = 1; iy0 < yBound - 1; ++iy0)
        {
            fxyz.at(iz0).at(iy0).at(0) = Math<Real>::GetValue(0);
            fxyz.at(iz0).at(iy0).at(xPreviousBound) = Math<Real>::GetValue(0);
            for (auto iz = 0; iz <= 2; ++iz)
            {
                for (auto iy = 0; iy <= 2; ++iy)
                {
                    for (auto ix = 0; ix <= 2; ++ix)
                    {
                        auto mask = invDXDYDZ * oDer.at(ix) * cDer.at(iy) * cDer.at(iz);

                        fxyz.at(iz0).at(iy0).at(0) += mask * fContainer.at(iz0 + iz - 1).at(iy0 + iy - 1).at(ix);

                        fxyz.at(iz0).at(iy0).at(xPreviousBound) += mask * fContainer.at(iz0 + iz - 1).at(iy0 + iy - 1).at(xBound - 1 - ix);
                    }
                }
            }
        }
    }

    for (auto iz0 = 1; iz0 < zBound - 1; ++iz0)
    {
        for (auto iy0 = 1; iy0 < yBound - 1; ++iy0)
        {
            for (auto ix0 = 1; ix0 < xBound - 1; ++ix0)
            {
                fxyz.at(iz0).at(iy0).at(ix0) = Math<Real>::GetValue(0);

                for (auto iz = 0; iz <= 2; ++iz)
                {
                    for (auto iy = 0; iy <= 2; ++iy)
                    {
                        for (auto ix = 0; ix <= 2; ++ix)
                        {
                            auto mask = invDXDYDZ * cDer.at(ix) * cDer.at(iy) * cDer.at(iz);

                            fxyz.at(iz0).at(iy0).at(ix0) += mask * fContainer.at(iz0 + iz - 1).at(iy0 + iy - 1).at(ix0 + ix - 1);
                        }
                    }
                }
            }
        }
    }

#include SYSTEM_WARNING_POP

    return fxyz;
}

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26451)

template <typename Real>
void Mathematics::IntpAkimaUniform3<Real>::GetPolynomials(const Container& fx,
                                                          const Container& fy,
                                                          const Container& fz,
                                                          const Container& fxy,
                                                          const Container& fxz,
                                                          const Container& fyz,
                                                          const Container& fxyz)
{
    polynomialContainer.resize(boost::numeric_cast<size_t>(zBound) - 1, std::vector<std::vector<Polynomial>>(boost::numeric_cast<size_t>(yBound) - 1, std::vector<Polynomial>(boost::numeric_cast<size_t>(xBound) - 1)));
    for (auto iz = 0; iz < zBound - 1; ++iz)
    {
        for (auto iy = 0; iy < yBound - 1; ++iy)
        {
            for (auto ix = 0; ix < xBound - 1; ++ix)
            {
                const ConstructType g{ std::array<std::array<Real, 2>, 2>{ std::array<Real, 2>{ fContainer.at(iz).at(iy).at(ix),
                                                                                                fContainer.at(iz + 1).at(iy).at(ix) },
                                                                           std::array<Real, 2>{ fContainer.at(iz).at(iy + 1).at(ix),
                                                                                                fContainer.at(iz + 1).at(iy + 1).at(ix) } },
                                       std::array<std::array<Real, 2>, 2>{ std::array<Real, 2>{ fContainer.at(iz).at(iy).at(ix + 1),
                                                                                                fContainer.at(iz + 1).at(iy).at(ix + 1) },
                                                                           std::array<Real, 2>{ fContainer.at(iz).at(iy + 1).at(ix + 1),
                                                                                                fContainer.at(iz + 1).at(iy + 1).at(ix + 1) } } };

                const ConstructType gx{ std::array<std::array<Real, 2>, 2>{ std::array<Real, 2>{ fx.at(iz).at(iy).at(ix),
                                                                                                 fx.at(iz + 1).at(iy).at(ix) },
                                                                            std::array<Real, 2>{ fx.at(iz).at(iy + 1).at(ix),
                                                                                                 fx.at(iz + 1).at(iy + 1).at(ix) } },
                                        std::array<std::array<Real, 2>, 2>{ std::array<Real, 2>{ fx.at(iz).at(iy).at(ix + 1),
                                                                                                 fx.at(iz + 1).at(iy).at(ix + 1) },
                                                                            std::array<Real, 2>{ fx.at(iz).at(iy + 1).at(ix + 1),
                                                                                                 fx.at(iz + 1).at(iy + 1).at(ix + 1) } } };

                const ConstructType gy{ std::array<std::array<Real, 2>, 2>{ std::array<Real, 2>{ fy.at(iz).at(iy).at(ix),
                                                                                                 fy.at(iz + 1).at(iy).at(ix) },
                                                                            std::array<Real, 2>{ fy.at(iz).at(iy + 1).at(ix),
                                                                                                 fy.at(iz + 1).at(iy + 1).at(ix) } },
                                        std::array<std::array<Real, 2>, 2>{ std::array<Real, 2>{ fy.at(iz).at(iy).at(ix + 1),
                                                                                                 fy.at(iz + 1).at(iy).at(ix + 1) },
                                                                            std::array<Real, 2>{ fy.at(iz).at(iy + 1).at(ix + 1),
                                                                                                 fy.at(iz + 1).at(iy + 1).at(ix + 1) } } };

                const ConstructType gz{ std::array<std::array<Real, 2>, 2>{ std::array<Real, 2>{ fz.at(iz).at(iy).at(ix),
                                                                                                 fz.at(iz + 1).at(iy).at(ix) },
                                                                            std::array<Real, 2>{ fz.at(iz).at(iy + 1).at(ix),
                                                                                                 fz.at(iz + 1).at(iy + 1).at(ix) } },
                                        std::array<std::array<Real, 2>, 2>{ std::array<Real, 2>{ fz.at(iz).at(iy).at(ix + 1),
                                                                                                 fz.at(iz + 1).at(iy).at(ix + 1) },
                                                                            std::array<Real, 2>{ fz.at(iz).at(iy + 1).at(ix + 1),
                                                                                                 fz.at(iz + 1).at(iy + 1).at(ix + 1) } } };

                const ConstructType gxy{ std::array<std::array<Real, 2>, 2>{ std::array<Real, 2>{ fxy.at(iz).at(iy).at(ix),
                                                                                                  fxy.at(iz + 1).at(iy).at(ix) },
                                                                             std::array<Real, 2>{ fxy.at(iz).at(iy + 1).at(ix),
                                                                                                  fxy.at(iz + 1).at(iy + 1).at(ix) } },
                                         std::array<std::array<Real, 2>, 2>{ std::array<Real, 2>{ fxy.at(iz).at(iy).at(ix + 1),
                                                                                                  fxy.at(iz + 1).at(iy).at(ix + 1) },
                                                                             std::array<Real, 2>{ fxy.at(iz).at(iy + 1).at(ix + 1),
                                                                                                  fxy.at(iz + 1).at(iy + 1).at(ix + 1) } } };

                const ConstructType gxz{ std::array<std::array<Real, 2>, 2>{ std::array<Real, 2>{ fxz.at(iz).at(iy).at(ix),
                                                                                                  fxz.at(iz + 1).at(iy).at(ix) },
                                                                             std::array<Real, 2>{ fxz.at(iz).at(iy + 1).at(ix),
                                                                                                  fxz.at(iz + 1).at(iy + 1).at(ix) } },
                                         std::array<std::array<Real, 2>, 2>{ std::array<Real, 2>{ fxz.at(iz).at(iy).at(ix + 1),
                                                                                                  fxz.at(iz + 1).at(iy).at(ix + 1) },
                                                                             std::array<Real, 2>{ fxz.at(iz).at(iy + 1).at(ix + 1),
                                                                                                  fxz.at(iz + 1).at(iy + 1).at(ix + 1) } } };

                const ConstructType gyz{ std::array<std::array<Real, 2>, 2>{ std::array<Real, 2>{ fyz.at(iz).at(iy).at(ix),
                                                                                                  fyz.at(iz + 1).at(iy).at(ix) },
                                                                             std::array<Real, 2>{ fyz.at(iz).at(iy + 1).at(ix),
                                                                                                  fyz.at(iz + 1).at(iy + 1).at(ix) } },
                                         std::array<std::array<Real, 2>, 2>{ std::array<Real, 2>{ fyz.at(iz).at(iy).at(ix + 1),
                                                                                                  fyz.at(iz + 1).at(iy).at(ix + 1) },
                                                                             std::array<Real, 2>{ fyz.at(iz).at(iy + 1).at(ix + 1),
                                                                                                  fyz.at(iz + 1).at(iy + 1).at(ix + 1) } } };

                const ConstructType gxyz{ std::array<std::array<Real, 2>, 2>{ std::array<Real, 2>{ fxyz.at(iz).at(iy).at(ix),
                                                                                                   fxyz.at(iz + 1).at(iy).at(ix) },
                                                                              std::array<Real, 2>{ fxyz.at(iz).at(iy + 1).at(ix),
                                                                                                   fxyz.at(iz + 1).at(iy + 1).at(ix) } },
                                          std::array<std::array<Real, 2>, 2>{ std::array<Real, 2>{ fxyz.at(iz).at(iy).at(ix + 1),
                                                                                                   fxyz.at(iz + 1).at(iy).at(ix + 1) },
                                                                              std::array<Real, 2>{ fxyz.at(iz).at(iy + 1).at(ix + 1),
                                                                                                   fxyz.at(iz + 1).at(iy + 1).at(ix + 1) } } };

                Construct(polynomialContainer.at(iz).at(iy).at(ix), g, gx, gy, gz, gxy, gxz, gyz, gxyz);
            }
        }
    }
}

#include SYSTEM_WARNING_POP

template <typename Real>
int Mathematics::IntpAkimaUniform3<Real>::GetXBound() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return xBound;
}

template <typename Real>
int Mathematics::IntpAkimaUniform3<Real>::GetYBound() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return yBound;
}

template <typename Real>
int Mathematics::IntpAkimaUniform3<Real>::GetZBound() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return zBound;
}

template <typename Real>
int Mathematics::IntpAkimaUniform3<Real>::GetQuantity() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return quantity;
}

template <typename Real>
typename Mathematics::IntpAkimaUniform3<Real>::Container Mathematics::IntpAkimaUniform3<Real>::GetF() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return fContainer;
}

template <typename Real>
typename Mathematics::IntpAkimaUniform3<Real>::PolynomialContainer Mathematics::IntpAkimaUniform3<Real>::GetPolynomials() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return polynomialContainer;
}

template <typename Real>
const typename Mathematics::IntpAkimaUniform3<Real>::Polynomial& Mathematics::IntpAkimaUniform3<Real>::GetPolynomial(int ix, int iy, int iz) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return polynomialContainer.at(iz).at(iy).at(ix);
}

template <typename Real>
Real Mathematics::IntpAkimaUniform3<Real>::GetXMin() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return xMin;
}

template <typename Real>
Real Mathematics::IntpAkimaUniform3<Real>::GetXMax() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return xMax;
}

template <typename Real>
Real Mathematics::IntpAkimaUniform3<Real>::GetXSpacing() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return xSpacing;
}

template <typename Real>
Real Mathematics::IntpAkimaUniform3<Real>::GetYMin() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return yMin;
}

template <typename Real>
Real Mathematics::IntpAkimaUniform3<Real>::GetYMax() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return yMax;
}

template <typename Real>
Real Mathematics::IntpAkimaUniform3<Real>::GetYSpacing() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return ySpacing;
}

template <typename Real>
Real Mathematics::IntpAkimaUniform3<Real>::GetZMin() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return zMin;
}

template <typename Real>
Real Mathematics::IntpAkimaUniform3<Real>::GetZMax() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return zMax;
}

template <typename Real>
Real Mathematics::IntpAkimaUniform3<Real>::GetZSpacing() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return zSpacing;
}

template <typename Real>
Real Mathematics::IntpAkimaUniform3<Real>::ComputeDerivative(const std::vector<Real>& slope) const
{
    if (slope.at(1) != slope.at(2))
    {
        if (slope.at(0) != slope.at(1))
        {
            if (slope.at(2) != slope.at(3))
            {
                auto ad0 = Math<Real>::FAbs(slope.at(3) - slope.at(2));
                auto ad1 = Math<Real>::FAbs(slope.at(0) - slope.at(1));
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
void Mathematics::IntpAkimaUniform3<Real>::Construct(Polynomial& poly,
                                                     const ConstructType& f,
                                                     const ConstructType& fx,
                                                     const ConstructType& fy,
                                                     const ConstructType& fz,
                                                     const ConstructType& fxy,
                                                     const ConstructType& fxz,
                                                     const ConstructType& fyz,
                                                     const ConstructType& fxyz)
{
    auto dx = xSpacing;
    auto dy = ySpacing;
    auto dz = zSpacing;
    auto invDX = (Math<Real>::GetValue(1)) / dx, invDX2 = invDX * invDX;
    auto invDY = (Math<Real>::GetValue(1)) / dy, invDY2 = invDY * invDY;
    auto invDZ = (Math<Real>::GetValue(1)) / dz, invDZ2 = invDZ * invDZ;

    poly.A(0, 0, 0) = f.at(0).at(0).at(0);
    poly.A(1, 0, 0) = fx.at(0).at(0).at(0);
    poly.A(0, 1, 0) = fy.at(0).at(0).at(0);
    poly.A(0, 0, 1) = fz.at(0).at(0).at(0);
    poly.A(1, 1, 0) = fxy.at(0).at(0).at(0);
    poly.A(1, 0, 1) = fxz.at(0).at(0).at(0);
    poly.A(0, 1, 1) = fyz.at(0).at(0).at(0);
    poly.A(1, 1, 1) = fxyz.at(0).at(0).at(0);

    auto b0 = (f.at(1).at(0).at(0) - poly(0, 0, 0, dx, Math<Real>::GetValue(0), Math<Real>::GetValue(0))) * invDX2;
    auto b1 = (fx.at(1).at(0).at(0) - poly(1, 0, 0, dx, Math<Real>::GetValue(0), Math<Real>::GetValue(0))) * invDX;
    poly.A(2, 0, 0) = (Math<Real>::GetValue(3)) * b0 - b1;
    poly.A(3, 0, 0) = (-(Math<Real>::GetValue(2)) * b0 + b1) * invDX;

    b0 = (f.at(0).at(1).at(0) - poly(0, 0, 0, Math<Real>::GetValue(0), dy, Math<Real>::GetValue(0))) * invDY2;
    b1 = (fy.at(0).at(1).at(0) - poly(0, 1, 0, Math<Real>::GetValue(0), dy, Math<Real>::GetValue(0))) * invDY;
    poly.A(0, 2, 0) = (Math<Real>::GetValue(3)) * b0 - b1;
    poly.A(0, 3, 0) = (-(Math<Real>::GetValue(2)) * b0 + b1) * invDY;

    b0 = (fy.at(1).at(0).at(0) - poly(0, 1, 0, dx, Math<Real>::GetValue(0), Math<Real>::GetValue(0))) * invDX2;
    b1 = (fxy.at(1).at(0).at(0) - poly(1, 1, 0, dx, Math<Real>::GetValue(0), Math<Real>::GetValue(0))) * invDX;
    poly.A(2, 1, 0) = (Math<Real>::GetValue(3)) * b0 - b1;
    poly.A(3, 1, 0) = (-(Math<Real>::GetValue(2)) * b0 + b1) * invDX;

    b0 = (fx.at(0).at(1).at(0) - poly(1, 0, 0, Math<Real>::GetValue(0), dy, Math<Real>::GetValue(0))) * invDY2;
    b1 = (fxy.at(0).at(1).at(0) - poly(1, 1, 0, Math<Real>::GetValue(0), dy, Math<Real>::GetValue(0))) * invDY;
    poly.A(1, 2, 0) = (Math<Real>::GetValue(3)) * b0 - b1;
    poly.A(1, 3, 0) = (-(Math<Real>::GetValue(2)) * b0 + b1) * invDY;

    b0 = (f.at(1).at(1).at(0) - poly(0, 0, 0, dx, dy, Math<Real>::GetValue(0))) * invDX2 * invDY2;
    b1 = (fx.at(1).at(1).at(0) - poly(1, 0, 0, dx, dy, Math<Real>::GetValue(0))) * invDX * invDY2;
    auto b2 = (fy.at(1).at(1).at(0) - poly(0, 1, 0, dx, dy, Math<Real>::GetValue(0))) * invDX2 * invDY;
    auto b3 = (fxy.at(1).at(1).at(0) - poly(1, 1, 0, dx, dy, Math<Real>::GetValue(0))) * invDX * invDY;
    poly.A(2, 2, 0) = (Math<Real>::GetValue(9)) * b0 - (Math<Real>::GetValue(3)) * b1 - (Math<Real>::GetValue(3)) * b2 + b3;
    poly.A(3, 2, 0) = (-(Math<Real>::GetValue(6)) * b0 + (Math<Real>::GetValue(3)) * b1 + (Math<Real>::GetValue(2)) * b2 - b3) * invDX;
    poly.A(2, 3, 0) = (-(Math<Real>::GetValue(6)) * b0 + (Math<Real>::GetValue(2)) * b1 + (Math<Real>::GetValue(3)) * b2 - b3) * invDY;
    poly.A(3, 3, 0) = ((Math<Real>::GetValue(4)) * b0 - (Math<Real>::GetValue(2)) * b1 - (Math<Real>::GetValue(2)) * b2 + b3) * invDX * invDY;

    b0 = (f.at(0).at(0).at(1) - poly(0, 0, 0, Math<Real>::GetValue(0), Math<Real>::GetValue(0), dz)) * invDZ2;
    b1 = (fz.at(0).at(0).at(1) - poly(0, 0, 1, Math<Real>::GetValue(0), Math<Real>::GetValue(0), dz)) * invDZ;
    poly.A(0, 0, 2) = (Math<Real>::GetValue(3)) * b0 - b1;
    poly.A(0, 0, 3) = (-(Math<Real>::GetValue(2)) * b0 + b1) * invDZ;

    b0 = (fz.at(1).at(0).at(0) - poly(0, 0, 1, dx, Math<Real>::GetValue(0), Math<Real>::GetValue(0))) * invDX2;
    b1 = (fxz.at(1).at(0).at(0) - poly(1, 0, 1, dx, Math<Real>::GetValue(0), Math<Real>::GetValue(0))) * invDX;
    poly.A(2, 0, 1) = (Math<Real>::GetValue(3)) * b0 - b1;
    poly.A(3, 0, 1) = (-(Math<Real>::GetValue(2)) * b0 + b1) * invDX;

    b0 = (fx.at(0).at(0).at(1) - poly(1, 0, 0, Math<Real>::GetValue(0), Math<Real>::GetValue(0), dz)) * invDZ2;
    b1 = (fxz.at(0).at(0).at(1) - poly(1, 0, 1, Math<Real>::GetValue(0), Math<Real>::GetValue(0), dz)) * invDZ;
    poly.A(1, 0, 2) = (Math<Real>::GetValue(3)) * b0 - b1;
    poly.A(1, 0, 3) = (-(Math<Real>::GetValue(2)) * b0 + b1) * invDZ;

    b0 = (f.at(1).at(0).at(1) - poly(0, 0, 0, dx, Math<Real>::GetValue(0), dz)) * invDX2 * invDZ2;
    b1 = (fx.at(1).at(0).at(1) - poly(1, 0, 0, dx, Math<Real>::GetValue(0), dz)) * invDX * invDZ2;
    b2 = (fz.at(1).at(0).at(1) - poly(0, 0, 1, dx, Math<Real>::GetValue(0), dz)) * invDX2 * invDZ;
    b3 = (fxz.at(1).at(0).at(1) - poly(1, 0, 1, dx, Math<Real>::GetValue(0), dz)) * invDX * invDZ;
    poly.A(2, 0, 2) = (Math<Real>::GetValue(9)) * b0 - (Math<Real>::GetValue(3)) * b1 - (Math<Real>::GetValue(3)) * b2 + b3;
    poly.A(3, 0, 2) = (-(Math<Real>::GetValue(6)) * b0 + (Math<Real>::GetValue(3)) * b1 + (Math<Real>::GetValue(2)) * b2 - b3) * invDX;
    poly.A(2, 0, 3) = (-(Math<Real>::GetValue(6)) * b0 + (Math<Real>::GetValue(2)) * b1 + (Math<Real>::GetValue(3)) * b2 - b3) * invDZ;
    poly.A(3, 0, 3) = ((Math<Real>::GetValue(4)) * b0 - (Math<Real>::GetValue(2)) * b1 - (Math<Real>::GetValue(2)) * b2 + b3) * invDX * invDZ;

    b0 = (fz.at(0).at(1).at(0) - poly(0, 0, 1, Math<Real>::GetValue(0), dy, Math<Real>::GetValue(0))) * invDY2;
    b1 = (fyz.at(0).at(1).at(0) - poly(0, 1, 1, Math<Real>::GetValue(0), dy, Math<Real>::GetValue(0))) * invDY;
    poly.A(0, 2, 1) = (Math<Real>::GetValue(3)) * b0 - b1;
    poly.A(0, 3, 1) = (-(Math<Real>::GetValue(2)) * b0 + b1) * invDY;

    b0 = (fy.at(0).at(0).at(1) - poly(0, 1, 0, Math<Real>::GetValue(0), Math<Real>::GetValue(0), dz)) * invDZ2;
    b1 = (fyz.at(0).at(0).at(1) - poly(0, 1, 1, Math<Real>::GetValue(0), Math<Real>::GetValue(0), dz)) * invDZ;
    poly.A(0, 1, 2) = (Math<Real>::GetValue(3)) * b0 - b1;
    poly.A(0, 1, 3) = (-(Math<Real>::GetValue(2)) * b0 + b1) * invDZ;

    b0 = (f.at(0).at(1).at(1) - poly(0, 0, 0, Math<Real>::GetValue(0), dy, dz)) * invDY2 * invDZ2;
    b1 = (fy.at(0).at(1).at(1) - poly(0, 1, 0, Math<Real>::GetValue(0), dy, dz)) * invDY * invDZ2;
    b2 = (fz.at(0).at(1).at(1) - poly(0, 0, 1, Math<Real>::GetValue(0), dy, dz)) * invDY2 * invDZ;
    b3 = (fyz.at(0).at(1).at(1) - poly(0, 1, 1, Math<Real>::GetValue(0), dy, dz)) * invDY * invDZ;
    poly.A(0, 2, 2) = (Math<Real>::GetValue(9)) * b0 - (Math<Real>::GetValue(3)) * b1 - (Math<Real>::GetValue(3)) * b2 + b3;
    poly.A(0, 3, 2) = (-(Math<Real>::GetValue(6)) * b0 + (Math<Real>::GetValue(3)) * b1 + (Math<Real>::GetValue(2)) * b2 - b3) * invDY;
    poly.A(0, 2, 3) = (-(Math<Real>::GetValue(6)) * b0 + (Math<Real>::GetValue(2)) * b1 + (Math<Real>::GetValue(3)) * b2 - b3) * invDZ;
    poly.A(0, 3, 3) = ((Math<Real>::GetValue(4)) * b0 - (Math<Real>::GetValue(2)) * b1 - (Math<Real>::GetValue(2)) * b2 + b3) * invDY * invDZ;

    b0 = (fyz.at(1).at(0).at(0) - poly(0, 1, 1, dx, Math<Real>::GetValue(0), Math<Real>::GetValue(0))) * invDX2;
    b1 = (fxyz.at(1).at(0).at(0) - poly(1, 1, 1, dx, Math<Real>::GetValue(0), Math<Real>::GetValue(0))) * invDX;
    poly.A(2, 1, 1) = (Math<Real>::GetValue(3)) * b0 - b1;
    poly.A(3, 1, 1) = (-(Math<Real>::GetValue(2)) * b0 + b1) * invDX;

    b0 = (fxz.at(0).at(1).at(0) - poly(1, 0, 1, Math<Real>::GetValue(0), dy, Math<Real>::GetValue(0))) * invDY2;
    b1 = (fxyz.at(0).at(1).at(0) - poly(1, 1, 1, Math<Real>::GetValue(0), dy, Math<Real>::GetValue(0))) * invDY;
    poly.A(1, 2, 1) = (Math<Real>::GetValue(3)) * b0 - b1;
    poly.A(1, 3, 1) = (-(Math<Real>::GetValue(2)) * b0 + b1) * invDY;

    b0 = (fz.at(1).at(1).at(0) - poly(0, 0, 1, dx, dy, Math<Real>::GetValue(0))) * invDX2 * invDY2;
    b1 = (fxz.at(1).at(1).at(0) - poly(1, 0, 1, dx, dy, Math<Real>::GetValue(0))) * invDX * invDY2;
    b2 = (fyz.at(1).at(1).at(0) - poly(0, 1, 1, dx, dy, Math<Real>::GetValue(0))) * invDX2 * invDY;
    b3 = (fxyz.at(1).at(1).at(0) - poly(1, 1, 1, dx, dy, Math<Real>::GetValue(0))) * invDX * invDY;
    poly.A(2, 2, 1) = (Math<Real>::GetValue(9)) * b0 - (Math<Real>::GetValue(3)) * b1 - (Math<Real>::GetValue(3)) * b2 + b3;
    poly.A(3, 2, 1) = (-(Math<Real>::GetValue(6)) * b0 + (Math<Real>::GetValue(3)) * b1 + (Math<Real>::GetValue(2)) * b2 - b3) * invDX;
    poly.A(2, 3, 1) = (-(Math<Real>::GetValue(6)) * b0 + (Math<Real>::GetValue(2)) * b1 + (Math<Real>::GetValue(3)) * b2 - b3) * invDY;
    poly.A(3, 3, 1) = ((Math<Real>::GetValue(4)) * b0 - (Math<Real>::GetValue(2)) * b1 - (Math<Real>::GetValue(2)) * b2 + b3) * invDX * invDY;

    b0 = (fxy.at(0).at(0).at(1) - poly(1, 1, 0, Math<Real>::GetValue(0), Math<Real>::GetValue(0), dz)) * invDZ2;
    b1 = (fxyz.at(0).at(0).at(1) - poly(1, 1, 1, Math<Real>::GetValue(0), Math<Real>::GetValue(0), dz)) * invDZ;
    poly.A(1, 1, 2) = (Math<Real>::GetValue(3)) * b0 - b1;
    poly.A(1, 1, 3) = (-(Math<Real>::GetValue(2)) * b0 + b1) * invDZ;

    b0 = (fy.at(1).at(0).at(1) - poly(0, 1, 0, dx, Math<Real>::GetValue(0), dz)) * invDX2 * invDZ2;
    b1 = (fxy.at(1).at(0).at(1) - poly(1, 1, 0, dx, Math<Real>::GetValue(0), dz)) * invDX * invDZ2;
    b2 = (fyz.at(1).at(0).at(1) - poly(0, 1, 1, dx, Math<Real>::GetValue(0), dz)) * invDX2 * invDZ;
    b3 = (fxyz.at(1).at(0).at(1) - poly(1, 1, 1, dx, Math<Real>::GetValue(0), dz)) * invDX * invDZ;
    poly.A(2, 1, 2) = (Math<Real>::GetValue(9)) * b0 - (Math<Real>::GetValue(3)) * b1 - (Math<Real>::GetValue(3)) * b2 + b3;
    poly.A(3, 1, 2) = (-(Math<Real>::GetValue(6)) * b0 + (Math<Real>::GetValue(3)) * b1 + (Math<Real>::GetValue(2)) * b2 - b3) * invDX;
    poly.A(2, 1, 3) = (-(Math<Real>::GetValue(6)) * b0 + (Math<Real>::GetValue(2)) * b1 + (Math<Real>::GetValue(3)) * b2 - b3) * invDZ;
    poly.A(3, 1, 3) = ((Math<Real>::GetValue(4)) * b0 - (Math<Real>::GetValue(2)) * b1 - (Math<Real>::GetValue(2)) * b2 + b3) * invDX * invDZ;

    b0 = (fx.at(0).at(1).at(1) - poly(1, 0, 0, Math<Real>::GetValue(0), dy, dz)) * invDY2 * invDZ2;
    b1 = (fxy.at(0).at(1).at(1) - poly(1, 1, 0, Math<Real>::GetValue(0), dy, dz)) * invDY * invDZ2;
    b2 = (fxz.at(0).at(1).at(1) - poly(1, 0, 1, Math<Real>::GetValue(0), dy, dz)) * invDY2 * invDZ;
    b3 = (fxyz.at(0).at(1).at(1) - poly(1, 1, 1, Math<Real>::GetValue(0), dy, dz)) * invDY * invDZ;
    poly.A(1, 2, 2) = (Math<Real>::GetValue(9)) * b0 - (Math<Real>::GetValue(3)) * b1 - (Math<Real>::GetValue(3)) * b2 + b3;
    poly.A(1, 3, 2) = (-(Math<Real>::GetValue(6)) * b0 + (Math<Real>::GetValue(3)) * b1 + (Math<Real>::GetValue(2)) * b2 - b3) * invDY;
    poly.A(1, 2, 3) = (-(Math<Real>::GetValue(6)) * b0 + (Math<Real>::GetValue(2)) * b1 + (Math<Real>::GetValue(3)) * b2 - b3) * invDZ;
    poly.A(1, 3, 3) = ((Math<Real>::GetValue(4)) * b0 - (Math<Real>::GetValue(2)) * b1 - (Math<Real>::GetValue(2)) * b2 + b3) * invDY * invDZ;

    b0 = (f.at(1).at(1).at(1) - poly(0, 0, 0, dx, dy, dz)) * invDX2 * invDY2 * invDZ2;
    b1 = (fx.at(1).at(1).at(1) - poly(1, 0, 0, dx, dy, dz)) * invDX * invDY2 * invDZ2;
    b2 = (fy.at(1).at(1).at(1) - poly(0, 1, 0, dx, dy, dz)) * invDX2 * invDY * invDZ2;
    b3 = (fz.at(1).at(1).at(1) - poly(0, 0, 1, dx, dy, dz)) * invDX2 * invDY2 * invDZ;
    auto b4 = (fxy.at(1).at(1).at(1) - poly(1, 1, 0, dx, dy, dz)) * invDX * invDY * invDZ2;
    auto b5 = (fxz.at(1).at(1).at(1) - poly(1, 0, 1, dx, dy, dz)) * invDX * invDY2 * invDZ;
    auto b6 = (fyz.at(1).at(1).at(1) - poly(0, 1, 1, dx, dy, dz)) * invDX2 * invDY * invDZ;
    auto b7 = (fxyz.at(1).at(1).at(1) - poly(1, 1, 1, dx, dy, dz)) * invDX * invDY * invDZ;
    poly.A(2, 2, 2) = (Math<Real>::GetValue(27)) * b0 - (Math<Real>::GetValue(9)) * b1 - (Math<Real>::GetValue(9)) * b2 - (Math<Real>::GetValue(9)) * b3 + (Math<Real>::GetValue(3)) * b4 + (Math<Real>::GetValue(3)) * b5 + (Math<Real>::GetValue(3)) * b6 - b7;
    poly.A(3, 2, 2) = ((Math<Real>::GetValue(-18)) * b0 + (Math<Real>::GetValue(9)) * b1 + (Math<Real>::GetValue(6)) * b2 + (Math<Real>::GetValue(6)) * b3 - (Math<Real>::GetValue(3)) * b4 - (Math<Real>::GetValue(3)) * b5 - (Math<Real>::GetValue(2)) * b6 + b7) * invDX;
    poly.A(2, 3, 2) = ((Math<Real>::GetValue(-18)) * b0 + (Math<Real>::GetValue(6)) * b1 + (Math<Real>::GetValue(9)) * b2 + (Math<Real>::GetValue(6)) * b3 - (Math<Real>::GetValue(3)) * b4 - (Math<Real>::GetValue(2)) * b5 - (Math<Real>::GetValue(3)) * b6 + b7) * invDY;
    poly.A(2, 2, 3) = ((Math<Real>::GetValue(-18)) * b0 + (Math<Real>::GetValue(6)) * b1 + (Math<Real>::GetValue(6)) * b2 + (Math<Real>::GetValue(9)) * b3 - (Math<Real>::GetValue(2)) * b4 - (Math<Real>::GetValue(3)) * b5 - (Math<Real>::GetValue(3)) * b6 + b7) * invDZ;
    poly.A(3, 3, 2) = ((Math<Real>::GetValue(12)) * b0 - (Math<Real>::GetValue(6)) * b1 - (Math<Real>::GetValue(6)) * b2 - (Math<Real>::GetValue(4)) * b3 + (Math<Real>::GetValue(3)) * b4 + (Math<Real>::GetValue(2)) * b5 + (Math<Real>::GetValue(2)) * b6 - b7) * invDX * invDY;
    poly.A(3, 2, 3) = ((Math<Real>::GetValue(12)) * b0 - (Math<Real>::GetValue(6)) * b1 - (Math<Real>::GetValue(4)) * b2 - (Math<Real>::GetValue(6)) * b3 + (Math<Real>::GetValue(2)) * b4 + (Math<Real>::GetValue(3)) * b5 + (Math<Real>::GetValue(2)) * b6 - b7) * invDX * invDZ;
    poly.A(2, 3, 3) = ((Math<Real>::GetValue(12)) * b0 - (Math<Real>::GetValue(4)) * b1 - (Math<Real>::GetValue(6)) * b2 - (Math<Real>::GetValue(6)) * b3 + (Math<Real>::GetValue(2)) * b4 + (Math<Real>::GetValue(2)) * b5 + (Math<Real>::GetValue(3)) * b6 - b7) * invDY * invDZ;
    poly.A(3, 3, 3) = ((Math<Real>::GetValue(-8)) * b0 + (Math<Real>::GetValue(4)) * b1 + (Math<Real>::GetValue(4)) * b2 + (Math<Real>::GetValue(4)) * b3 - (Math<Real>::GetValue(2)) * b4 - (Math<Real>::GetValue(2)) * b5 - (Math<Real>::GetValue(2)) * b6 + b7) * invDX * invDY * invDZ;
}

template <typename Real>
bool Mathematics::IntpAkimaUniform3<Real>::XLookup(Real x, int& xIndex, Real& dx) const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    if (x >= xMin)
    {
        if (x <= xMax)
        {
            for (xIndex = 0; xIndex + 1 < xBound; ++xIndex)
            {
                if (x < xMin + xSpacing * Math<Real>::GetValue(xIndex + 1))
                {
                    dx = x - (xMin + xSpacing * xIndex);
                    return true;
                }
            }

            --xIndex;
            dx = x - (xMin + xSpacing * xIndex);
            return true;
        }
    }

    return false;
}

template <typename Real>
bool Mathematics::IntpAkimaUniform3<Real>::YLookup(Real y, int& yIndex, Real& dy) const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    if (y >= yMin)
    {
        if (y <= yMax)
        {
            for (yIndex = 0; yIndex + 1 < yBound; ++yIndex)
            {
                if (y < yMin + ySpacing * Math<Real>::GetValue(yIndex + 1))
                {
                    dy = y - (yMin + ySpacing * yIndex);
                    return true;
                }
            }

            --yIndex;
            dy = y - (yMin + ySpacing * yIndex);
            return true;
        }
    }

    return false;
}

template <typename Real>
bool Mathematics::IntpAkimaUniform3<Real>::ZLookup(Real z, int& zIndex, Real& dz) const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    if (z >= zMin)
    {
        if (z <= zMax)
        {
            for (zIndex = 0; zIndex + 1 < zBound; ++zIndex)
            {
                if (z < zMin + zSpacing * Math<Real>::GetValue(zIndex + 1))
                {
                    dz = z - (zMin + zSpacing * zIndex);
                    return true;
                }
            }

            --zIndex;
            dz = z - (zMin + zSpacing * zIndex);
            return true;
        }
    }

    return false;
}

template <typename Real>
Real Mathematics::IntpAkimaUniform3<Real>::operator()(Real x, Real y, Real z) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    auto ix = 0;
    auto iy = 0;
    auto iz = 0;
    Real dx{};
    Real dy{};
    Real dz{};

    if (XLookup(x, ix, dx) && YLookup(y, iy, dy) && ZLookup(z, iz, dz))
    {
        return polynomialContainer.at(iz).at(iy).at(ix)(dx, dy, dz);
    }

    return Math<Real>::maxReal;
}

template <typename Real>
Real Mathematics::IntpAkimaUniform3<Real>::operator()(int xOrder, int yOrder, int zOrder, Real x, Real y, Real z) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    auto ix = 0;
    auto iy = 0;
    auto iz = 0;
    Real dx{};
    Real dy{};
    Real dz{};

    if (XLookup(x, ix, dx) && YLookup(y, iy, dy) && ZLookup(z, iz, dz))
    {
        return polynomialContainer.at(iz).at(iy).at(ix)(xOrder, yOrder, zOrder, dx, dy, dz);
    }

    return Math<Real>::maxReal;
}

// IntrpAkimaUniform3::Polynomial

template <typename Real>
Mathematics::IntpAkimaUniform3<Real>::Polynomial::Polynomial() noexcept
    : coeff{}
{
}

template <typename Real>
Real& Mathematics::IntpAkimaUniform3<Real>::Polynomial::A(int ix, int iy, int iz)
{
    return coeff.at(ix).at(iy).at(iz);
}

template <typename Real>
Real Mathematics::IntpAkimaUniform3<Real>::Polynomial::operator()(Real x, Real y, Real z) const
{
    std::array<Real, 4> xPow{ Math<Real>::GetValue(1), x, x * x, x * x * x };
    std::array<Real, 4> yPow{ Math<Real>::GetValue(1), y, y * y, y * y * y };
    std::array<Real, 4> zPow{ Math<Real>::GetValue(1), z, z * z, z * z * z };

    auto p = Math<Real>::GetValue(0);
    for (auto iz = 0; iz <= 3; ++iz)
    {
        for (auto iy = 0; iy <= 3; ++iy)
        {
            for (auto ix = 0; ix <= 3; ++ix)
            {
                p += coeff.at(ix).at(iy).at(iz) * xPow.at(ix) * yPow.at(iy) * zPow.at(iz);
            }
        }
    }

    return p;
}

template <typename Real>
Real Mathematics::IntpAkimaUniform3<Real>::Polynomial::operator()(int xOrder, int yOrder, int zOrder, Real x, Real y, Real z) const
{
    std::array<Real, 4> xPow{};
    switch (xOrder)
    {
        case 0:
            xPow.at(0) = Math<Real>::GetValue(1);
            xPow.at(1) = x;
            xPow.at(2) = x * x;
            xPow.at(3) = x * x * x;
            break;
        case 1:
            xPow.at(0) = Math<Real>::GetValue(0);
            xPow.at(1) = Math<Real>::GetValue(1);
            xPow.at(2) = (Math<Real>::GetValue(2)) * x;
            xPow.at(3) = (Math<Real>::GetValue(3)) * x * x;
            break;
        case 2:
            xPow.at(0) = Math<Real>::GetValue(0);
            xPow.at(1) = Math<Real>::GetValue(0);
            xPow.at(2) = Math<Real>::GetValue(2);
            xPow.at(3) = (Math<Real>::GetValue(6)) * x;
            break;
        case 3:
            xPow.at(0) = Math<Real>::GetValue(0);
            xPow.at(1) = Math<Real>::GetValue(0);
            xPow.at(2) = Math<Real>::GetValue(0);
            xPow.at(3) = Math<Real>::GetValue(6);
            break;
        default:
            return Math<Real>::GetValue(0);
    }

    std::array<Real, 4> yPow{};
    switch (yOrder)
    {
        case 0:
            yPow.at(0) = Math<Real>::GetValue(1);
            yPow.at(1) = y;
            yPow.at(2) = y * y;
            yPow.at(3) = y * y * y;
            break;
        case 1:
            yPow.at(0) = Math<Real>::GetValue(0);
            yPow.at(1) = Math<Real>::GetValue(1);
            yPow.at(2) = (Math<Real>::GetValue(2)) * y;
            yPow.at(3) = (Math<Real>::GetValue(3)) * y * y;
            break;
        case 2:
            yPow.at(0) = Math<Real>::GetValue(0);
            yPow.at(1) = Math<Real>::GetValue(0);
            yPow.at(2) = Math<Real>::GetValue(2);
            yPow.at(3) = (Math<Real>::GetValue(6)) * y;
            break;
        case 3:
            yPow.at(0) = Math<Real>::GetValue(0);
            yPow.at(1) = Math<Real>::GetValue(0);
            yPow.at(2) = Math<Real>::GetValue(0);
            yPow.at(3) = Math<Real>::GetValue(6);
            break;
        default:
            return Math<Real>::GetValue(0);
    }

    std::array<Real, 4> zPow{};
    switch (zOrder)
    {
        case 0:
            zPow.at(0) = Math<Real>::GetValue(1);
            zPow.at(1) = z;
            zPow.at(2) = z * z;
            zPow.at(3) = z * z * z;
            break;
        case 1:
            zPow.at(0) = Math<Real>::GetValue(0);
            zPow.at(1) = Math<Real>::GetValue(1);
            zPow.at(2) = (Math<Real>::GetValue(2)) * z;
            zPow.at(3) = (Math<Real>::GetValue(3)) * z * z;
            break;
        case 2:
            zPow.at(0) = Math<Real>::GetValue(0);
            zPow.at(1) = Math<Real>::GetValue(0);
            zPow.at(2) = Math<Real>::GetValue(2);
            zPow.at(3) = (Math<Real>::GetValue(6)) * z;
            break;
        case 3:
            zPow.at(0) = Math<Real>::GetValue(0);
            zPow.at(1) = Math<Real>::GetValue(0);
            zPow.at(2) = Math<Real>::GetValue(0);
            zPow.at(3) = Math<Real>::GetValue(6);
            break;
        default:
            return Math<Real>::GetValue(0);
    }

    auto p = Math<Real>::GetValue(0);

    for (auto iz = 0; iz <= 3; ++iz)
    {
        for (auto iy = 0; iy <= 3; ++iy)
        {
            for (auto ix = 0; ix <= 3; ++ix)
            {
                p += coeff.at(ix).at(iy).at(iz) * xPow.at(ix) * yPow.at(iy) * zPow.at(iz);
            }
        }
    }

    return p;
}

#endif  // MATHEMATICS_INTERPOLATION_INTP_AKIMA_UNIFORM3_DETAIL_H