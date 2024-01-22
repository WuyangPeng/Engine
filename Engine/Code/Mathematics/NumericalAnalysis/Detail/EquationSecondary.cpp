/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/12 13:29)

#include "Mathematics/MathematicsExport.h"

#include "EquationOnce.h"
#include "EquationSecondary.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Mathematics/Base/MathDetail.h"

Mathematics::EquationSecondary::EquationSecondary(double constant, double once, double secondary, double epsilon)
    : ParentType{ epsilon }, constant{ constant }, once{ once }, secondary{ secondary }
{
    Calculate();

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, EquationSecondary)

double Mathematics::EquationSecondary::Substitution(double value) const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return constant + once * value + secondary * value * value;
}

Mathematics::EquationSecondary::Imaginary Mathematics::EquationSecondary::Substitution(const Imaginary& value) const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return constant + once * value + secondary * value * value;
}

double Mathematics::EquationSecondary::SubstitutionTangent(double solution) const noexcept
{
    return once + solution * secondary * 2.0;
}

Mathematics::EquationSecondary::Imaginary Mathematics::EquationSecondary::SubstitutionTangent(const Imaginary& solution) const noexcept
{
    return once + solution * secondary * 2.0;
}

void Mathematics::EquationSecondary::Solving()
{
    const auto discriminant = CalculateDiscriminant();
    const auto lhsTemporarily = CalculateLhs();

    CalculateResult(lhsTemporarily, discriminant);
}

bool Mathematics::EquationSecondary::Predigest()
{
    // 求出一个解为0，并简化为一次方程
    if (MathD::FAbs(constant) <= GetEpsilon())
    {
        SetRealResult(0.0);
        const EquationOnce equation{ once, secondary };
        AddResult(equation);

        return true;
    }

    // 简化为一次方程
    if (MathD::FAbs(secondary) <= GetEpsilon())
    {
        const EquationOnce equation{ constant, once };
        AddResult(equation);

        return true;
    }

    return false;
}

double Mathematics::EquationSecondary::CalculateDiscriminant() const noexcept
{
    // 计算b^2 - 4ac
    return -secondary * constant * 4.0 + once * once;
}

double Mathematics::EquationSecondary::CalculateLhs() const noexcept
{
    // 计算-b / 2a
    return -once / secondary / 2.0;
}

void Mathematics::EquationSecondary::CalculateResult(double lhs, double discriminant)
{
    if (MathD::FAbs(discriminant) <= GetEpsilon())
        CalculateResultDiscriminantIsZero(lhs);
    else if (0.0 < discriminant)
        CalculateResultDiscriminantIsPlus(lhs, discriminant);
    else
        CalculateResultDiscriminantIsNegative(lhs, discriminant);
}

void Mathematics::EquationSecondary::CalculateResultDiscriminantIsPlus(double lhs, double discriminant)
{
    // 计算sqrt(discriminant) / 2a
    auto rhs = MathD::Sqrt(discriminant) / secondary / 2.0;

    const auto minResult = lhs - rhs;
    const auto maxResult = lhs + rhs;

    SetRealResult(minResult);
    SetRealResult(maxResult);
}

void Mathematics::EquationSecondary::CalculateResultDiscriminantIsZero(double lhs)
{
    SetRealResult(lhs);
}

void Mathematics::EquationSecondary::CalculateResultDiscriminantIsNegative(double lhs, double discriminant)
{
    // 计算sqrt(-discriminant) / 2a
    const auto rhs = MathD::Sqrt(-discriminant) / secondary / 2.0;

    SetImaginaryResult(Imaginary{ lhs, -rhs });
    SetImaginaryResult(Imaginary{ lhs, rhs });
}
