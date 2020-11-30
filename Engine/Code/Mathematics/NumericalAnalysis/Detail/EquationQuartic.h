///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.4 (2020/11/19 14:01)

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
        EquationQuartic(double constant, double once, double secondary, double thrice, double quartic, double epsilon = DoubleMath::GetZeroTolerance());

        CLASS_INVARIANT_FINAL_DECLARE;

        [[nodiscard]] double Substitution(double value) const noexcept final;
        [[nodiscard]] const Imaginary Substitution(const Imaginary& value) const final;

    private:
        [[nodiscard]] double SubstitutionTangent(double solution) const noexcept final;
        [[nodiscard]] const Imaginary SubstitutionTangent(const Imaginary& solution) const final;

        void Solving() final;
        [[nodiscard]] bool Predigest() final;

        [[nodiscard]] double CalculateP() const noexcept;
        [[nodiscard]] double CalculateQ() const noexcept;
        [[nodiscard]] double CalculateR() const noexcept;
        void CalculateThriceEquation(double p, double q, double r);

        void CalculateResult(double solution, double p, double q, double r);
        void CalculateSecondaryEquation(double thriceSolution, double constant, double once);

    private:
        double m_Constant;
        double m_Once;
        double m_Secondary;
        double m_Thrice;
        double m_Quartic;
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_EQUATION_QUARTIC_H