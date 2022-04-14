///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.4 (2022/03/19 13:22)

#ifndef MATHEMATICS_INTERPOLATION_INTP_AKIMA_UNIFORM2_DEATIL_H
#define MATHEMATICS_INTERPOLATION_INTP_AKIMA_UNIFORM2_DEATIL_H

#include "IntpAkimaUniform2.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Matrix2Detail.h"
#include "Mathematics/Base/MathDetail.h"

template <typename Real>
Mathematics::IntpAkimaUniform2<Real>::IntpAkimaUniform2(int xBound, int yBound, Real xMin, Real xSpacing, Real yMin, Real ySpacing, const VariableMatrix<Real>& f)
    : xBound{ xBound },
      yBound{ yBound },
      quantity{ xBound * yBound },
      f{ f },
      poly{},
      xMin{ xMin },
      xMax{ xMin + xSpacing * Math<Real>::GetValue(xBound - 1) },
      xSpacing{ xSpacing },
      yMin{ yMin },
      yMax{ yMin + ySpacing * Math<Real>::GetValue(yBound - 1) },
      ySpacing{ ySpacing }
{
    MATHEMATICS_ASSERTION_0(xBound >= 3 && yBound >= 3, "无效输入。\n");
    MATHEMATICS_ASSERTION_0(xSpacing > Math<Real>::GetValue(0) && ySpacing > Math<Real>::GetValue(0), "无效输入。\n");

    const auto xBoundM1 = xBound - 1;
    const auto yBoundM1 = yBound - 1;

    auto invDX = (Math<Real>::GetValue(1)) / xSpacing;
    auto invDY = (Math<Real>::GetValue(1)) / ySpacing;
    auto invDXDY = invDX * invDY;
    VariableMatrix<Real> xSlope{ xBound + 3, yBound };
    VariableMatrix<Real> ySlope{ yBound + 3, xBound };

    for (auto iy = 0; iy < yBound; ++iy)
    {
        for (auto ix = 0; ix < xBoundM1; ++ix)
        {
            xSlope[iy][ix + 2] = (f[iy][ix + 1] - f[iy][ix]) * invDX;
        }

        xSlope[iy][1] = (Math<Real>::GetValue(2)) * xSlope[iy][2] - xSlope[iy][3];
        xSlope[iy][0] = (Math<Real>::GetValue(2)) * xSlope[iy][1] - xSlope[iy][2];
        xSlope[iy][xBound + 1] = (Math<Real>::GetValue(2)) * xSlope[iy][xBound] - xSlope[iy][xBound - 1];
        xSlope[iy][xBound + 2] = (Math<Real>::GetValue(2)) * xSlope[iy][xBound + 1] - xSlope[iy][xBound];
    }

    for (auto ix = 0; ix < xBound; ++ix)
    {
        for (auto iy = 0; iy < yBoundM1; ++iy)
        {
            ySlope[ix][iy + 2] = (f[iy + 1][ix] - f[iy][ix]) * invDY;
        }

        ySlope[ix][1] = (Math<Real>::GetValue(2)) * ySlope[ix][2] - ySlope[ix][3];
        ySlope[ix][0] = (Math<Real>::GetValue(2)) * ySlope[ix][1] - ySlope[ix][2];
        ySlope[ix][yBound + 1] = (Math<Real>::GetValue(2)) * ySlope[ix][yBound] - ySlope[ix][yBound - 1];
        ySlope[ix][yBound + 2] = (Math<Real>::GetValue(2)) * ySlope[ix][yBound + 1] - ySlope[ix][yBound];
    }

    VariableMatrix<Real> fx{ xBound, yBound };
    VariableMatrix<Real> fy{ xBound, yBound };

    for (auto iy = 0; iy < yBound; ++iy)
    {
        for (auto ix = 0; ix < xBound; ++ix)
        {
            std::vector<Real> derivative{ xSlope(iy, ix), xSlope(iy, ix + 1), xSlope(iy, ix + 2), xSlope(iy, ix + 3) };
            fx[iy][ix] = ComputeDerivative(derivative);
        }
    }

    for (auto ix = 0; ix < xBound; ++ix)
    {
        for (auto iy = 0; iy < yBound; ++iy)
        {
            std::vector<Real> derivative{ ySlope(ix, iy), ySlope(ix, iy + 1), ySlope(ix, iy + 2), ySlope(ix, iy + 3) };
            fy[iy][ix] = ComputeDerivative(derivative);
        }
    }

    VariableMatrix<Real> fxy{ xBound, yBound };

    const auto ix0 = xBoundM1;
    const auto ix1 = ix0 - 1;
    const auto ix2 = ix1 - 1;
    const auto iy0 = yBoundM1;
    const auto iy1 = iy0 - 1;
    const auto iy2 = iy1 - 1;

    fxy[0][0] = Math<Real>::GetRational(1, 4) * invDXDY * ((Math<Real>::GetValue(9)) * f[0][0] - (Math<Real>::GetValue(12)) * f[0][1] + (Math<Real>::GetValue(3)) * f[0][2] - (Math<Real>::GetValue(12)) * f[1][0] + (Math<Real>::GetValue(16)) * f[1][1] - (Math<Real>::GetValue(4)) * f[1][2] + (Math<Real>::GetValue(3)) * f[2][0] - (Math<Real>::GetValue(4)) * f[2][1] + f[2][2]);

    fxy[0][xBoundM1] = Math<Real>::GetRational(1, 4) * invDXDY * ((Math<Real>::GetValue(9)) * f[0][ix0] - (Math<Real>::GetValue(12)) * f[0][ix1] + (Math<Real>::GetValue(3)) * f[0][ix2] - (Math<Real>::GetValue(12)) * f[1][ix0] + (Math<Real>::GetValue(16)) * f[1][ix1] - (Math<Real>::GetValue(4)) * f[1][ix2] + (Math<Real>::GetValue(3)) * f[2][ix0] - (Math<Real>::GetValue(4)) * f[2][ix1] + f[2][ix2]);

    fxy[yBoundM1][0] = Math<Real>::GetRational(1, 4) * invDXDY * ((Math<Real>::GetValue(9)) * f[iy0][0] - (Math<Real>::GetValue(12)) * f[iy0][1] + (Math<Real>::GetValue(3)) * f[iy0][2] - (Math<Real>::GetValue(12)) * f[iy1][0] + (Math<Real>::GetValue(16)) * f[iy1][1] - (Math<Real>::GetValue(4)) * f[iy1][2] + (Math<Real>::GetValue(3)) * f[iy2][0] - (Math<Real>::GetValue(4)) * f[iy2][1] + f[iy2][2]);

    fxy[yBoundM1][xBoundM1] = Math<Real>::GetRational(1, 4) * invDXDY * ((Math<Real>::GetValue(9)) * f[iy0][ix0] - (Math<Real>::GetValue(12)) * f[iy0][ix1] + (Math<Real>::GetValue(3)) * f[iy0][ix2] - (Math<Real>::GetValue(12)) * f[iy1][ix0] + (Math<Real>::GetValue(16)) * f[iy1][ix1] - (Math<Real>::GetValue(4)) * f[iy1][ix2] + (Math<Real>::GetValue(3)) * f[iy2][ix0] - (Math<Real>::GetValue(4)) * f[iy2][ix1] + f[iy2][ix2]);

    for (auto ix = 1; ix < xBoundM1; ++ix)
    {
        fxy[0][ix] = Math<Real>::GetRational(1, 4) * invDXDY * ((Math<Real>::GetValue(3)) * (f[0][ix - 1] - f[0][ix + 1]) - (Math<Real>::GetValue(4)) * (f[1][ix - 1] - f[1][ix + 1]) + (f[2][ix - 1] - f[2][ix + 1]));

        fxy[yBoundM1][ix] = Math<Real>::GetRational(1, 4) * invDXDY * ((Math<Real>::GetValue(3)) * (f[iy0][ix - 1] - f[iy0][ix + 1]) - (Math<Real>::GetValue(4)) * (f[iy1][ix - 1] - f[iy1][ix + 1]) + (f[iy2][ix - 1] - f[iy2][ix + 1]));
    }

    for (auto iy = 1; iy < yBoundM1; ++iy)
    {
        fxy[iy][0] = Math<Real>::GetRational(1, 4) * invDXDY * ((Math<Real>::GetValue(3)) * (f[iy - 1][0] - f[iy + 1][0]) - (Math<Real>::GetValue(4)) * (f[iy - 1][1] - f[iy + 1][1]) + (f[iy - 1][2] - f[iy + 1][2]));

        fxy[iy][xBoundM1] = Math<Real>::GetRational(1, 4) * invDXDY * ((Math<Real>::GetValue(3)) * (f[iy - 1][ix0] - f[iy + 1][ix0]) - (Math<Real>::GetValue(4)) * (f[iy - 1][ix1] - f[iy + 1][ix1]) + (f[iy - 1][ix2] - f[iy + 1][ix2]));
    }

    for (auto iy = 1; iy < yBoundM1; ++iy)
    {
        for (auto ix = 1; ix < xBoundM1; ++ix)
        {
            fxy[iy][ix] = Math<Real>::GetRational(1, 4) * invDXDY * (f[iy - 1][ix - 1] - f[iy - 1][ix + 1] - f[iy + 1][ix - 1] + f[iy + 1][ix + 1]);
        }
    }

    poly.resize(xBoundM1, std::vector<Polynomial>(yBoundM1));
    for (auto iy = 0; iy < yBoundM1; ++iy)
    {
        for (auto ix = 0; ix < xBoundM1; ++ix)
        {
            const Matrix2<Real> g{ f[iy][ix], f[iy + 1][ix], f[iy][ix + 1], f[iy + 1][ix + 1] };

            const Matrix2<Real> gx{ fx[iy][ix], fx[iy + 1][ix], fx[iy][ix + 1], fx[iy + 1][ix + 1] };

            const Matrix2<Real> gy{ fy[iy][ix], fy[iy + 1][ix], fy[iy][ix + 1], fy[iy + 1][ix + 1] };

            const Matrix2<Real> gxy{ fxy[iy][ix], fxy[iy + 1][ix], fxy[iy][ix + 1], fxy[iy + 1][ix + 1] };

            Construct(poly.at(iy).at(ix), g, gx, gy, gxy);
        }
    }

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::IntpAkimaUniform2<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
int Mathematics::IntpAkimaUniform2<Real>::GetXBound() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return xBound;
}

template <typename Real>
int Mathematics::IntpAkimaUniform2<Real>::GetYBound() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return yBound;
}

template <typename Real>
int Mathematics::IntpAkimaUniform2<Real>::GetQuantity() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return quantity;
}

template <typename Real>
Mathematics::VariableMatrix<Real> Mathematics::IntpAkimaUniform2<Real>::GetF() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return f;
}

template <typename Real>
std::vector<std::vector<typename Mathematics::IntpAkimaUniform2<Real>::Polynomial>> Mathematics::IntpAkimaUniform2<Real>::GetPolynomials() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return poly;
}

template <typename Real>
const typename Mathematics::IntpAkimaUniform2<Real>::Polynomial& Mathematics::IntpAkimaUniform2<Real>::GetPolynomial(int ix, int iy) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return poly.at(iy).at(ix);
}

template <typename Real>
Real Mathematics::IntpAkimaUniform2<Real>::GetXMin() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return xMin;
}

template <typename Real>
Real Mathematics::IntpAkimaUniform2<Real>::GetXMax() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return xMax;
}

template <typename Real>
Real Mathematics::IntpAkimaUniform2<Real>::GetXSpacing() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return xSpacing;
}

template <typename Real>
Real Mathematics::IntpAkimaUniform2<Real>::GetYMin() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return yMin;
}

template <typename Real>
Real Mathematics::IntpAkimaUniform2<Real>::GetYMax() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return yMax;
}

template <typename Real>
Real Mathematics::IntpAkimaUniform2<Real>::GetYSpacing() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return ySpacing;
}

template <typename Real>
Real Mathematics::IntpAkimaUniform2<Real>::ComputeDerivative(const std::vector<Real>& slope) const
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
void Mathematics::IntpAkimaUniform2<Real>::Construct(Polynomial& polynomial, const Matrix2<Real>& f0, const Matrix2<Real>& fx, const Matrix2<Real>& fy, const Matrix2<Real>& fxy)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    auto dx = xSpacing;
    auto dy = ySpacing;
    auto invDX = (Math<Real>::GetValue(1)) / dx, fInvDX2 = invDX * invDX;
    auto invDY = (Math<Real>::GetValue(1)) / dy, fInvDY2 = invDY * invDY;

    polynomial.A(0, 0) = f0[0][0];
    polynomial.A(1, 0) = fx[0][0];
    polynomial.A(0, 1) = fy[0][0];
    polynomial.A(1, 1) = fxy[0][0];

    auto b0 = (f0[1][0] - polynomial(0, 0, dx, Math<Real>::GetValue(0))) * fInvDX2;
    auto b1 = (fx[1][0] - polynomial(1, 0, dx, Math<Real>::GetValue(0))) * invDX;
    polynomial.A(2, 0) = (Math<Real>::GetValue(3)) * b0 - b1;
    polynomial.A(3, 0) = (-(Math<Real>::GetValue(2)) * b0 + b1) * invDX;

    b0 = (f0[0][1] - polynomial(0, 0, Math<Real>::GetValue(0), dy)) * fInvDY2;
    b1 = (fy[0][1] - polynomial(0, 1, Math<Real>::GetValue(0), dy)) * invDY;
    polynomial.A(0, 2) = (Math<Real>::GetValue(3)) * b0 - b1;
    polynomial.A(0, 3) = (-(Math<Real>::GetValue(2)) * b0 + b1) * invDY;

    b0 = (fy[1][0] - polynomial(0, 1, dx, Math<Real>::GetValue(0))) * fInvDX2;
    b1 = (fxy[1][0] - polynomial(1, 1, dx, Math<Real>::GetValue(0))) * invDX;
    polynomial.A(2, 1) = (Math<Real>::GetValue(3)) * b0 - b1;
    polynomial.A(3, 1) = (-(Math<Real>::GetValue(2)) * b0 + b1) * invDX;

    b0 = (fx[0][1] - polynomial(1, 0, Math<Real>::GetValue(0), dy)) * fInvDY2;
    b1 = (fxy[0][1] - polynomial(1, 1, Math<Real>::GetValue(0), dy)) * invDY;
    polynomial.A(1, 2) = (Math<Real>::GetValue(3)) * b0 - b1;
    polynomial.A(1, 3) = (-(Math<Real>::GetValue(2)) * b0 + b1) * invDY;

    b0 = (f0[1][1] - polynomial(0, 0, dx, dy)) * fInvDX2 * fInvDY2;
    b1 = (fx[1][1] - polynomial(1, 0, dx, dy)) * invDX * fInvDY2;
    auto b2 = (fy[1][1] - polynomial(0, 1, dx, dy)) * fInvDX2 * invDY;
    auto b3 = (fxy[1][1] - polynomial(1, 1, dx, dy)) * invDX * invDY;
    polynomial.A(2, 2) = (Math<Real>::GetValue(9)) * b0 - (Math<Real>::GetValue(3)) * b1 - (Math<Real>::GetValue(3)) * b2 + b3;
    polynomial.A(3, 2) = ((Math<Real>::GetValue(-6)) * b0 + (Math<Real>::GetValue(3)) * b1 + (Math<Real>::GetValue(2)) * b2 - b3) * invDX;
    polynomial.A(2, 3) = ((Math<Real>::GetValue(-6)) * b0 + (Math<Real>::GetValue(2)) * b1 + (Math<Real>::GetValue(3)) * b2 - b3) * invDY;
    polynomial.A(3, 3) = ((Math<Real>::GetValue(4)) * b0 - (Math<Real>::GetValue(2)) * b1 - (Math<Real>::GetValue(2)) * b2 + b3) * invDX * invDY;
}

template <typename Real>
bool Mathematics::IntpAkimaUniform2<Real>::XLookup(Real x, int& xIndex, Real& dx) const noexcept
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
bool Mathematics::IntpAkimaUniform2<Real>::YLookup(Real y, int& yIndex, Real& dy) const noexcept
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

            yIndex--;
            dy = y - (yMin + ySpacing * yIndex);
            return true;
        }
    }

    return false;
}

template <typename Real>
Real Mathematics::IntpAkimaUniform2<Real>::operator()(Real x, Real y) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    auto ix = 0;
    auto iy = 0;
    Real dx{};
    Real dy{};

    if (XLookup(x, ix, dx) && YLookup(y, iy, dy))
    {
        return poly.at(iy).at(ix)(dx, dy);
    }

    return Math<Real>::maxReal;
}

template <typename Real>
Real Mathematics::IntpAkimaUniform2<Real>::operator()(int xOrder, int yOrder, Real x, Real y) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    auto ix = 0;
    auto iy = 0;
    Real dx{};
    Real dy{};

    if (XLookup(x, ix, dx) && YLookup(y, iy, dy))
    {
        return poly.at(iy).at(ix)(xOrder, yOrder, dx, dy);
    }

    return Math<Real>::maxReal;
}

// IntpAkimaUniform2::Polynomial

template <typename Real>
Mathematics::IntpAkimaUniform2<Real>::Polynomial::Polynomial() noexcept
    : coeff{}
{
}

template <typename Real>
Real& Mathematics::IntpAkimaUniform2<Real>::Polynomial::A(int ix, int iy)
{
    return coeff[ix][iy];
}

template <typename Real>
Real Mathematics::IntpAkimaUniform2<Real>::Polynomial::operator()(Real x, Real y) const
{
    Vector4<Real> b{};
    for (auto i = 0; i < 4; ++i)
    {
        b[i] = coeff[i][0] + y * (coeff[i][1] + y * (coeff[i][2] + y * coeff[i][3]));
    }

    return b[0] + x * (b[1] + x * (b[2] + x * b[3]));
}

template <typename Real>
Real Mathematics::IntpAkimaUniform2<Real>::Polynomial::operator()(int xOrder, int yOrder, Real x, Real y) const
{
    Vector4<Real> xPow{};
    switch (xOrder)
    {
        case 0:
            xPow[0] = Math<Real>::GetValue(1);
            xPow[1] = x;
            xPow[2] = x * x;
            xPow[3] = x * x * x;
            break;
        case 1:
            xPow[0] = Math<Real>::GetValue(0);
            xPow[1] = Math<Real>::GetValue(1);
            xPow[2] = (Math<Real>::GetValue(2)) * x;
            xPow[3] = (Math<Real>::GetValue(3)) * x * x;
            break;
        case 2:
            xPow[0] = Math<Real>::GetValue(0);
            xPow[1] = Math<Real>::GetValue(0);
            xPow[2] = Math<Real>::GetValue(2);
            xPow[3] = (Math<Real>::GetValue(6)) * x;
            break;
        case 3:
            xPow[0] = Math<Real>::GetValue(0);
            xPow[1] = Math<Real>::GetValue(0);
            xPow[2] = Math<Real>::GetValue(0);
            xPow[3] = Math<Real>::GetValue(6);
            break;
        default:
            return Math<Real>::GetValue(0);
    }

    Vector4<Real> yPow{};
    switch (yOrder)
    {
        case 0:
            yPow[0] = Math<Real>::GetValue(1);
            yPow[1] = y;
            yPow[2] = y * y;
            yPow[3] = y * y * y;
            break;
        case 1:
            yPow[0] = Math<Real>::GetValue(0);
            yPow[1] = Math<Real>::GetValue(1);
            yPow[2] = (Math<Real>::GetValue(2)) * y;
            yPow[3] = (Math<Real>::GetValue(3)) * y * y;
            break;
        case 2:
            yPow[0] = Math<Real>::GetValue(0);
            yPow[1] = Math<Real>::GetValue(0);
            yPow[2] = Math<Real>::GetValue(2);
            yPow[3] = (Math<Real>::GetValue(6)) * y;
            break;
        case 3:
            yPow[0] = Math<Real>::GetValue(0);
            yPow[1] = Math<Real>::GetValue(0);
            yPow[2] = Math<Real>::GetValue(0);
            yPow[3] = Math<Real>::GetValue(6);
            break;
        default:
            return Math<Real>::GetValue(0);
    }

    auto p = Math<Real>::GetValue(0);
    for (auto iy = 0; iy <= 3; ++iy)
    {
        for (auto ix = 0; ix <= 3; ++ix)
        {
            p += coeff[ix][iy] * xPow[ix] * yPow[iy];
        }
    }

    return p;
}

#endif  // MATHEMATICS_INTERPOLATION_INTP_AKIMA_UNIFORM2_DEATIL_H