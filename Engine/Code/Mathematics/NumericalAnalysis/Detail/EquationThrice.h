///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.4 (2020/11/19 14:03)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_EQUATION_THRICE_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_EQUATION_THRICE_H

#include "Mathematics/MathematicsDll.h"

#include "EquationImpl.h"

namespace Mathematics
{
    class MATHEMATICS_HIDDEN_DECLARE EquationThrice final : public EquationImpl
    {
    public:
        using ClassType = EquationThrice;
        using ParentType = EquationImpl;

    public:
        EquationThrice(double constant, double once, double secondary, double thrice, double epsilon = DoubleMath::GetZeroTolerance());

        CLASS_INVARIANT_FINAL_DECLARE;

        [[nodiscard]] double Substitution(double value) const noexcept final;
        [[nodiscard]] const Imaginary Substitution(const Imaginary& value) const final;

    private:
        [[nodiscard]] double SubstitutionTangent(double solution) const noexcept final;
        [[nodiscard]] const Imaginary SubstitutionTangent(const Imaginary& solution) const final;

        void Solving() final;
        [[nodiscard]] bool Predigest() final;

        [[nodiscard]] static constexpr double CalculateDiscriminant(double pThird, double qHalf) noexcept
        {
            return qHalf * qHalf + pThird * pThird * pThird;
        }

        [[nodiscard]] double CalculatePThird() const noexcept;
        [[nodiscard]] double CalculateQHalf() const noexcept;

        void CalculateResult(double pThird, double qHalf, double discriminant);
        void CalculateResultDiscriminantIsPlus(double qHalf, double discriminant);
        void CalculateResultDiscriminantIsZero(double qHalf);
        void CalculateResultDiscriminantIsNegative(double pThird, double qHalf);

    private:
        double m_Constant;
        double m_Once;
        double m_Secondary;
        double m_Thrice;
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_EQUATION_THRICE_H