///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.5 (2020/12/04 14:58)

#ifndef MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT_POWERS_DATA_H
#define MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT_POWERS_DATA_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/VariableLengthVector.h"
#include "Mathematics/Algebra/VariableMatrix.h"

#include <array>
#include <vector>

namespace Mathematics
{
    template <typename Real, int S>
    class MATHEMATICS_TEMPLATE_HIDDEN_DECLARE PolynomialFitPowersData final
    {
    public:
        static_assert(2 <= S && S <= 4, "2 <= S && S <= 4");
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        static constexpr auto Size = S;
        using ClassType = PolynomialFitPowersData<Real, Size>;
        using Math = Math<Real>;
        using Coefficients = std::vector<Real>;
        using VariableLengthVector = VariableLengthVector<Real>;
        using VariableMatrix = VariableMatrix<Real>;

    public:
        PolynomialFitPowersData() noexcept;

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] bool IsSolveSucceed() const noexcept;
        [[nodiscard]] int GetSize() const;
        [[nodiscard]] int GetMaxPower(int index) const;
        [[nodiscard]] Real GetMin(int index) const;
        [[nodiscard]] Real GetMax(int index) const;
        [[nodiscard]] Real GetScale(int index) const;
        [[nodiscard]] Real GetInvTwoWScale() const noexcept;
        [[nodiscard]] const Coefficients GetCoefficients() const;
        [[nodiscard]] Real GetCoefficients(int index) const;

        void SetMaxPower(int index, int power);
        void SetScale(int index, Real scale);

        void Solve(const VariableMatrix& matrix, const VariableLengthVector& vector);

    private:
        using PowerType = std::array<int, Size - 1>;
        using Container = std::array<Real, Size>;

    private:
        PowerType m_MaxPower;
        Container m_Min;
        Container m_Max;
        Container m_Scale;
        Real m_InvTwoWScale;
        Coefficients m_Coefficients;
        bool m_Solved;
    };
}

#endif  // MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT_POWERS_DATA_H
