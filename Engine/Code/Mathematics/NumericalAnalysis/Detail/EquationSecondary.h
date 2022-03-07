///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/13 14:46)

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
        EquationSecondary(double constant, double once, double secondary, double epsilon = MathD::GetZeroTolerance());

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD double Substitution(double value) const noexcept final;
        NODISCARD Imaginary Substitution(const Imaginary& value) const final;

    private:
        NODISCARD double SubstitutionTangent(double solution) const noexcept final;
        NODISCARD Imaginary SubstitutionTangent(const Imaginary& solution) const final;

        void Solving() final;
        NODISCARD bool Predigest() final;

        NODISCARD double CalculateDiscriminant() const noexcept;
        NODISCARD double CalculateLhs() const noexcept;

        void CalculateResult(double lhs, double discriminant);
        void CalculateResultDiscriminantIsPlus(double lhs, double discriminant);
        void CalculateResultDiscriminantIsZero(double lhs);
        void CalculateResultDiscriminantIsNegative(double lhs, double discriminant);

    private:
        double constant;
        double once;
        double secondary;
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_EQUATION_SECONDARY_H