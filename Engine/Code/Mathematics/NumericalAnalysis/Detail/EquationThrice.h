///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/13 14:47)

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
        EquationThrice(double constant, double once, double secondary, double thrice, double epsilon = MathD::GetZeroTolerance());

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD double Substitution(double value) const noexcept final;
        NODISCARD Imaginary Substitution(const Imaginary& value) const final;

    private:
        NODISCARD double SubstitutionTangent(double solution) const noexcept final;
        NODISCARD Imaginary SubstitutionTangent(const Imaginary& solution) const final;

        void Solving() final;
        NODISCARD bool Predigest() final;

        NODISCARD static constexpr double CalculateDiscriminant(double pThird, double qHalf) noexcept
        {
            return qHalf * qHalf + pThird * pThird * pThird;
        }

        NODISCARD double CalculatePThird() const noexcept;
        NODISCARD double CalculateQHalf() const noexcept;

        void CalculateResult(double pThird, double qHalf, double discriminant);
        void CalculateResultDiscriminantIsPlus(double qHalf, double discriminant);
        void CalculateResultDiscriminantIsZero(double qHalf);
        void CalculateResultDiscriminantIsNegative(double pThird, double qHalf);

    private:
        double constant;
        double once;
        double secondary;
        double thrice;
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_EQUATION_THRICE_H