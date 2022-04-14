///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.4 (2022/03/18 20:43)

#ifndef MATHEMATICS_INTERPOLATION_INTP_AKIMA1_H
#define MATHEMATICS_INTERPOLATION_INTP_AKIMA1_H

#include "Mathematics/MathematicsDll.h"

#include <array>
#include <vector>

namespace Mathematics
{
    template <typename Real>
    class IntpAkima1
    {
    public:
        using ClassType = IntpAkima1<Real>;

    public:
        virtual ~IntpAkima1() noexcept = default;
        IntpAkima1(const IntpAkima1& rhs) = default;
        IntpAkima1& operator=(const IntpAkima1& rhs) = default;
        IntpAkima1(IntpAkima1&& rhs) noexcept = default;
        IntpAkima1& operator=(IntpAkima1&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        class Polynomial
        {
        public:
            // P(x) = c[0] + c[1] * x + c[2] * x^2 + c[3] * x^3
            NODISCARD Real& operator[](int i);

            NODISCARD Real operator()(Real x) const;
            NODISCARD Real operator()(int order, Real x) const;

        private:
            std::array<Real, 4> coeff;
        };

        NODISCARD int GetQuantity() const noexcept;
        NODISCARD std::vector<Real> GetF() const;
        NODISCARD std::vector<Polynomial> GetPolynomials() const;
        NODISCARD const Polynomial& GetPolynomial(int i) const;

        NODISCARD virtual Real GetXMin() const = 0;
        NODISCARD virtual Real GetXMax() const = 0;

        NODISCARD Real operator()(Real x) const;
        NODISCARD Real operator()(int order, Real x) const;

    protected:
        IntpAkima1(int quantity, const std::vector<Real>& f);

        NODISCARD Real ComputeDerivative(const std::vector<Real>& slope) const;
        NODISCARD virtual bool Lookup(Real x, int& index, Real& dx) const = 0;
        NODISCARD Real GetF(int index) const;
        NODISCARD Polynomial& GetPolynomial(int i);

    private:
        int quantity;
        std::vector<Real> f;
        std::vector<Polynomial> poly;
    };
}

#endif  // MATHEMATICS_INTERPOLATION_INTP_AKIMA1_H
