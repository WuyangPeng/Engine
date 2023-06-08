///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.11 (2023/06/08 16:30)

#include "Mathematics/MathematicsExport.h"

#include "EquationQuartic.h"
#include "EquationSecondary.h"
#include "EquationThrice.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Mathematics/Base/MathDetail.h"
#include "Mathematics/NumericalAnalysis/EquationResultConstIteratorDetail.h"

Mathematics::EquationQuartic::EquationQuartic(double constant, double once, double secondary, double thrice, double quartic, double epsilon)
    : ParentType{ epsilon }, constant{ constant }, once{ once }, secondary{ secondary }, thrice{ thrice }, quartic{ quartic }
{
    Calculate();

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, EquationQuartic)

double Mathematics::EquationQuartic::Substitution(double value) const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return constant +
           once * value +
           secondary * MathD::Square(value) +
           thrice * value * value * value +
           quartic * MathD::Square(value) * MathD::Square(value);
}

Mathematics::EquationQuartic::Imaginary Mathematics::EquationQuartic::Substitution(const Imaginary& value) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return constant +
           once * value +
           secondary * value * value +
           thrice * value * value * value +
           quartic * value * value * value * value;
}

double Mathematics::EquationQuartic::SubstitutionTangent(double solution) const noexcept
{
    return once +
           solution * secondary * 2.0 +
           MathD::Square(solution) * thrice * 3.0 +
           solution * solution * solution * quartic * 4.0;
}

Mathematics::EquationQuartic::Imaginary Mathematics::EquationQuartic::SubstitutionTangent(const Imaginary& solution) const
{
    return once +
           solution * secondary * 2.0 +
           solution * solution * thrice * 3.0 +
           solution * solution * solution * quartic * 4.0;
}

void Mathematics::EquationQuartic::Solving()
{
    // 消去三次项
    // p = -3a^2 / 8 + b
    // q = a^3 / 8 - ab / 2 + c
    // r = -3a^4 / 256 + ba^2 / 16 - ac / 4 + d
    const auto p = CalculateP();
    const auto q = CalculateQ();
    const auto r = CalculateR();

    CalculateThriceEquation(p, q, r);
}

bool Mathematics::EquationQuartic::Predigest()
{
    // 常数项为零时，化解方程。
    if (MathD::FAbs(constant) <= GetEpsilon())
    {
        SetRealResult(0.0);
        const EquationThrice equation{ once, secondary, thrice, quartic };
        AddResult(equation);

        return true;
    }

    // 四次项为零时，化解方程。
    if (MathD::FAbs(quartic) <= GetEpsilon())
    {
        const EquationThrice equation{ constant, once, secondary, thrice };
        AddResult(equation);

        return true;
    }

    return false;
}

double Mathematics::EquationQuartic::CalculateP() const noexcept
{
    const auto three = thrice / quartic;
    const auto two = secondary / quartic;

    const auto p = two - 3.0 * three * three / 8.0;

    return p;
}

double Mathematics::EquationQuartic::CalculateQ() const noexcept
{
    const auto three = thrice / quartic;
    const auto two = secondary / quartic;
    const auto one = once / quartic;

    const auto q = one - three * two / 2.0 + three * three * three / 8.0;

    return q;
}

double Mathematics::EquationQuartic::CalculateR() const noexcept
{
    const auto three = thrice / quartic;
    const auto two = secondary / quartic;
    const auto one = once / quartic;
    const auto zero = constant / quartic;

    const auto r = zero - three * one / 4.0 +
                   three * three * two / 16.0 -
                   three * three * three * three * 3.0 / 256.0;
    return r;
}

void Mathematics::EquationQuartic::CalculateThriceEquation(double p, double q, double r)
{
    const auto two = -p / 2.0;
    const auto one = -r;
    const auto zero = (4.0 * r * p - q * q) / 8.0;

    // 先求解一个三次方程。
    const EquationThrice equationThrice{ zero, one, two, 1.0 };

    MATHEMATICS_ASSERTION_1(equationThrice.IsRealResult(), "四次方程分解的三次方程无解！");

    for (auto iter = equationThrice.GetRealBegin(); iter != equationThrice.GetRealEnd(); ++iter)
    {
        CalculateResult(*iter, p, q, r);
    }
}

void Mathematics::EquationQuartic::CalculateResult(double solution, double p, double q, double r)
{
    const auto x1 = 2.0 * solution - p;
    const auto x0 = solution * solution - r;

    if (0.0 <= x1 && 0.0 <= x0)
    {
        const auto x1sqrt = MathD::Sqrt(x1);
        const auto x0sqrt = MathD::Sqrt(x0);

        if (0 <= q)
        {
            CalculateSecondaryEquation(solution, x0sqrt, x1sqrt);
        }
        else
        {
            CalculateSecondaryEquation(solution, -x0sqrt, x1sqrt);
        }
    }
}

void Mathematics::EquationQuartic::CalculateSecondaryEquation(double thriceSolution, double secondaryConstant, double secondaryOnce)
{
    // 将四次方程分解为两个二次方程。
    const auto minConstant = thriceSolution - secondaryConstant;
    const auto maxConstant = thriceSolution + secondaryConstant;

    const EquationSecondary equation0{ minConstant, secondaryOnce, 1.0 };
    const EquationSecondary equation1{ maxConstant, -secondaryOnce, 1.0 };

    const auto three = thrice / quartic;

    AddResult(equation0, -three / 4.0);
    AddResult(equation1, -three / 4.0);
}
