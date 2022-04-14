///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.4 (2022/03/19 13:15)

#ifndef MATHEMATICS_INTERPOLATION_INTP_AKIMA_UNIFORM2_H
#define MATHEMATICS_INTERPOLATION_INTP_AKIMA_UNIFORM2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Matrix4Detail.h"
#include "Mathematics/Algebra/VariableMatrix.h"

namespace Mathematics
{
    template <typename Real>
    class IntpAkimaUniform2
    {
    public:
        using ClassType = IntpAkimaUniform2<Real>;

    public:
        IntpAkimaUniform2(int xBound, int yBound, Real xMin, Real xSpacing, Real yMin, Real ySpacing, const VariableMatrix<Real>& f);

        CLASS_INVARIANT_DECLARE;

        class Polynomial
        {
        public:
            Polynomial() noexcept;

            NODISCARD Real& A(int ix, int iy);

            NODISCARD Real operator()(Real x, Real y) const;
            NODISCARD Real operator()(int xOrder, int yOrder, Real x, Real y) const;

        private:
            Matrix4<Real> coeff;
        };

        NODISCARD int GetXBound() const noexcept;
        NODISCARD int GetYBound() const noexcept;
        NODISCARD int GetQuantity() const noexcept;
        NODISCARD VariableMatrix<Real> GetF() const;
        NODISCARD std::vector<std::vector<Polynomial>> GetPolynomials() const;
        NODISCARD const Polynomial& GetPolynomial(int ix, int iy) const;

        NODISCARD Real GetXMin() const noexcept;
        NODISCARD Real GetXMax() const noexcept;
        NODISCARD Real GetXSpacing() const noexcept;
        NODISCARD Real GetYMin() const noexcept;
        NODISCARD Real GetYMax() const noexcept;
        NODISCARD Real GetYSpacing() const noexcept;

        NODISCARD Real operator()(Real x, Real y) const;
        NODISCARD Real operator()(int xOrder, int yOrder, Real x, Real y) const;

    private:
        NODISCARD Real ComputeDerivative(const std::vector<Real>& slope) const;
        void Construct(Polynomial& polynomial, const Matrix2<Real>& f0, const Matrix2<Real>& fx, const Matrix2<Real>& fy, const Matrix2<Real>& fxy);

        NODISCARD bool XLookup(Real x, int& xIndex, Real& dx) const noexcept;
        NODISCARD bool YLookup(Real y, int& yIndex, Real& dy) const noexcept;

    private:
        int xBound;
        int yBound;
        int quantity;
        VariableMatrix<Real> f;
        std::vector<std::vector<Polynomial>> poly;
        Real xMin;
        Real xMax;
        Real xSpacing;
        Real yMin;
        Real yMax;
        Real ySpacing;
    };
}

#endif  // MATHEMATICS_INTERPOLATION_INTP_AKIMA_UNIFORM2_H
