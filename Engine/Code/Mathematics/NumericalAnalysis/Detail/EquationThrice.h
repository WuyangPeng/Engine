/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/12 13:52)

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

        NODISCARD double Substitution(double value) const noexcept override;
        NODISCARD Imaginary Substitution(const Imaginary& value) const noexcept override;

    private:
        NODISCARD double SubstitutionTangent(double solution) const noexcept override;
        NODISCARD Imaginary SubstitutionTangent(const Imaginary& solution) const noexcept override;

        void Solving() override;
        NODISCARD bool Predigest() override;

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