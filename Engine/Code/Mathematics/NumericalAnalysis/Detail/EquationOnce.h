///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/13 14:43)

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
        EquationOnce(double constant, double once, double epsilon = MathD::GetZeroTolerance());

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD double Substitution(double value) const noexcept final;
        NODISCARD Imaginary Substitution(const Imaginary& value) const final;

    private:
        NODISCARD double SubstitutionTangent(double solution) const noexcept final;
        NODISCARD Imaginary SubstitutionTangent(const Imaginary& solution) const final;

        void Solving() final;
        NODISCARD bool Predigest() noexcept final;

    private:
        double constant;
        double once;
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_EQUATION_ONCE_H