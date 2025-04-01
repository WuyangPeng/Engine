///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/09 10:12)

#ifndef MATHEMATICS_INTERPOLATION_INTP_AKIMA_UNIFORM3_H
#define MATHEMATICS_INTERPOLATION_INTP_AKIMA_UNIFORM3_H

#include "Mathematics/MathematicsDll.h"

#include <vector>
#include <array>

namespace Mathematics
{
    template <typename Real>
    class IntpAkimaUniform3
    {
    public:
        using ClassType = IntpAkimaUniform3<Real>;
        using Container = std::vector<std::vector<std::vector<Real>>>;

    public:
        IntpAkimaUniform3(int xBound, int yBound, int zBound, Real xMin, Real xSpacing, Real yMin, Real ySpacing, Real zMin, Real zSpacing, const Container& f);

        CLASS_INVARIANT_DECLARE;

        class Polynomial
        {
        public:
            Polynomial() noexcept;

            // P(x,y,z) = sum_{i=0}^3 sum_{j=0}^3 sum_{k=0}^3 a_{ijk} x^i y^j z^k
            NODISCARD Real& A(int ix, int iy, int iz);

            NODISCARD Real operator()(Real x, Real y, Real z) const;
            NODISCARD Real operator()(int xOrder, int yOrder, int zOrder, Real x, Real y, Real z) const;

        private:
            std::array<std::array<std::array<Real, 4>, 4>, 4> coeff;
        };

        using PolynomialContainer = std::vector<std::vector<std::vector<Polynomial>>>;

        NODISCARD int GetXBound() const noexcept;
        NODISCARD int GetYBound() const noexcept;
        NODISCARD int GetZBound() const noexcept;
        NODISCARD int GetQuantity() const noexcept;
        NODISCARD Container GetF() const;
        NODISCARD PolynomialContainer GetPolynomials() const;
        NODISCARD const Polynomial& GetPolynomial(int ix, int iy, int iz) const;

        NODISCARD Real GetXMin() const noexcept;
        NODISCARD Real GetXMax() const noexcept;
        NODISCARD Real GetXSpacing() const noexcept;
        NODISCARD Real GetYMin() const noexcept;
        NODISCARD Real GetYMax() const noexcept;
        NODISCARD Real GetYSpacing() const noexcept;
        NODISCARD Real GetZMin() const noexcept;
        NODISCARD Real GetZMax() const noexcept;
        NODISCARD Real GetZSpacing() const noexcept;

        NODISCARD Real operator()(Real x, Real y, Real z) const;
        NODISCARD Real operator()(int xOrder, int yOrder, int zOrder, Real x, Real y, Real z) const;

    private:
        using ConstructType = std::array<std::array<std::array<Real, 2>, 2>, 2>;

    private:
        NODISCARD Real ComputeDerivative(const std::vector<Real>& slope) const;
        void Construct(Polynomial& poly,
                       const ConstructType& f,
                       const ConstructType& fx,
                       const ConstructType& fy,
                       const ConstructType& fz,
                       const ConstructType& fxy,
                       const ConstructType& fxz,
                       const ConstructType& fyz,
                       const ConstructType& fxyz);

        NODISCARD bool XLookup(Real x, int& xIndex, Real& dx) const noexcept;
        NODISCARD bool YLookup(Real y, int& yIndex, Real& dy) const noexcept;
        NODISCARD bool ZLookup(Real z, int& zIndex, Real& dz) const noexcept;

    private:
        NODISCARD Container GetFX();
        NODISCARD Container GetFY();
        NODISCARD Container GetFZ();
        NODISCARD Container GetFXY();
        NODISCARD Container GetFXZ();
        NODISCARD Container GetFYZ();
        NODISCARD Container GetFXYZ();

        void GetPolynomials(const Container& fx,
                            const Container& fy,
                            const Container& fz,
                            const Container& fxy,
                            const Container& fxz,
                            const Container& fyz,
                            const Container& fxyz);

    private:
        int xBound;
        int yBound;
        int zBound;
        int quantity;
        Container fContainer;
        PolynomialContainer polynomialContainer;
        Real xMin;
        Real xMax;
        Real xSpacing;
        Real yMin;
        Real yMax;
        Real ySpacing;
        Real zMin;
        Real zMax;
        Real zSpacing;
    };
}

#endif  // MATHEMATICS_INTERPOLATION_INTP_AKIMA_UNIFORM3_H
