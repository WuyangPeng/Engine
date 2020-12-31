///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.4 (2020/11/19 14:00)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_EQUATION_ONCE_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_EQUATION_ONCE_H

#include "Mathematics/MathematicsDll.h"

#include "EquationImpl.h"

namespace Mathematics
{
    class MATHEMATICS_HIDDEN_DECLARE EquationOnce final : public EquationImpl
    {
    public:
        using ClassType = EquationOnce;
        using ParentType = EquationImpl;

    public:
        EquationOnce(double constant, double once, double epsilon = DoubleMath::GetZeroTolerance());

        CLASS_INVARIANT_FINAL_DECLARE;

        [[nodiscard]] double Substitution(double value) const noexcept final;
        [[nodiscard]] const Imaginary Substitution(const Imaginary& value) const final;

    private:
        [[nodiscard]] double SubstitutionTangent(double solution) const noexcept final;
        [[nodiscard]] const Imaginary SubstitutionTangent(const Imaginary& solution) const final;

        void Solving() final;
        [[nodiscard]] bool Predigest() noexcept final;

    private:
        double m_Constant;
        double m_Once;
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_EQUATION_ONCE_H