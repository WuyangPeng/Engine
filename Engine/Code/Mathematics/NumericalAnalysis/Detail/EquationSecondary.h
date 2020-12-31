///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.4 (2020/11/19 14:03)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_EQUATION_SECONDARY_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_EQUATION_SECONDARY_H

#include "Mathematics/MathematicsDll.h"

#include "EquationImpl.h"

namespace Mathematics
{
    class MATHEMATICS_HIDDEN_DECLARE EquationSecondary final : public EquationImpl
    {
    public:
        using ClassType = EquationSecondary;
        using ParentType = EquationImpl;

    public:
        EquationSecondary(double constant, double once, double secondary, double epsilon = DoubleMath::GetZeroTolerance());

        CLASS_INVARIANT_FINAL_DECLARE;

        [[nodiscard]] double Substitution(double value) const noexcept final;
        [[nodiscard]] const Imaginary Substitution(const Imaginary& value) const final;

    private:
        [[nodiscard]] double SubstitutionTangent(double solution) const noexcept final;
        [[nodiscard]] const Imaginary SubstitutionTangent(const Imaginary& solution) const final;

        void Solving() final;
        [[nodiscard]] bool Predigest() final;

        [[nodiscard]] double CalculateDiscriminant() const noexcept;
        [[nodiscard]] double CalculateLhs() const noexcept;

        void CalculateResult(double lhs, double discriminant);
        void CalculateResultDiscriminantIsPlus(double lhs, double discriminant);
        void CalculateResultDiscriminantIsZero(double lhs);
        void CalculateResultDiscriminantIsNegative(double lhs, double discriminant);

    private:
        double m_Constant;
        double m_Once;
        double m_Secondary;
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_EQUATION_SECONDARY_H