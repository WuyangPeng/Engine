/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/12 13:52)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_EQUATION_QUARTIC_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_EQUATION_QUARTIC_H

#include "Mathematics/MathematicsDll.h"

#include "EquationImpl.h"

namespace Mathematics
{
    class MATHEMATICS_HIDDEN_DECLARE EquationQuartic final : public EquationImpl
    {
    public:
        using ClassType = EquationQuartic;
        using ParentType = EquationImpl;

    public:
        EquationQuartic(double constant, double once, double secondary, double thrice, double quartic, double epsilon = MathD::GetZeroTolerance());

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD double Substitution(double value) const noexcept override;
        NODISCARD Imaginary Substitution(const Imaginary& value) const noexcept override;

    private:
        NODISCARD double SubstitutionTangent(double solution) const noexcept override;
        NODISCARD Imaginary SubstitutionTangent(const Imaginary& solution) const noexcept override;

        void Solving() override;
        NODISCARD bool Predigest() override;

        NODISCARD double CalculateP() const noexcept;
        NODISCARD double CalculateQ() const noexcept;
        NODISCARD double CalculateR() const noexcept;
        void CalculateThriceEquation(double p, double q, double r);

        void CalculateResult(double solution, double p, double q, double r);
        void CalculateSecondaryEquation(double thriceSolution, double secondaryConstant, double secondaryOnce);

    private:
        double constant;
        double once;
        double secondary;
        double thrice;
        double quartic;
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_EQUATION_QUARTIC_H