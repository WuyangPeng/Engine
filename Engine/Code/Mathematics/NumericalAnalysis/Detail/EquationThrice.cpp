///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.4 (2020/11/19 14:14)

#include "Mathematics/MathematicsExport.h"

#include "EquationSecondary.h"
#include "EquationThrice.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Mathematics/Base/MathDetail.h"

using std::swap;

Mathematics::EquationThrice::EquationThrice(double constant, double once, double secondary, double thrice, double epsilon)
    : ParentType{ epsilon }, m_Constant{ constant }, m_Once{ once }, m_Secondary{ secondary }, m_Thrice{ thrice }
{
    Calculate();

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, EquationThrice)

double Mathematics::EquationThrice::Substitution(double value) const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Constant + m_Once * value +
           m_Secondary * DoubleMath::Square(value) +
           m_Thrice * value * value * value;
}

const Mathematics::EquationThrice::Imaginary Mathematics::EquationThrice::Substitution(const Imaginary& value) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Constant + m_Once * value +
           m_Secondary * value * value +
           m_Thrice * value * value * value;
}

double Mathematics::EquationThrice::SubstitutionTangent(double solution) const noexcept
{
    return m_Once + solution * m_Secondary * 2.0 +
           DoubleMath::Square(solution) * m_Thrice * 3.0;
}

const Mathematics::EquationThrice::Imaginary Mathematics::EquationThrice::SubstitutionTangent(const Imaginary& solution) const
{
    return m_Once + solution * m_Secondary * 2.0 +
           solution * solution * m_Thrice * 3.0;
}

void Mathematics::EquationThrice::Solving()
{
    // 另 t = x - a / 3
    // 去掉二次项，得到方程x^3 + px + q = 0
    // p = -a^2/3 + b
    // q = 2a^3/27 - ab/3 +c
    // p' = p / 3 ,q' = q / 2
    const auto pThird = CalculatePThird();
    const auto qHalf = CalculateQHalf();

    // 差别式 D' = p'^3 + q'^2
    const auto discriminant = CalculateDiscriminant(pThird, qHalf);

    CalculateResult(pThird, qHalf, discriminant);
}

bool Mathematics::EquationThrice::Predigest()
{
    // 常数项为零时，化解方程。
    if (DoubleMath::FAbs(m_Constant) <= GetEpsilon())
    {
        SetRealResult(0.0);
        EquationSecondary equation{ m_Once, m_Secondary, m_Thrice };
        AddResult(equation);

        return true;
    }

    // 三次项为零时，化解方程。
    if (DoubleMath::FAbs(m_Thrice) <= GetEpsilon())
    {
        EquationSecondary equation{ m_Constant, m_Once, m_Secondary };
        AddResult(equation);

        return true;
    }

    return false;
}

double Mathematics::EquationThrice::CalculatePThird() const noexcept
{
    const auto two = m_Secondary / m_Thrice;
    const auto one = m_Once / m_Thrice;

    const auto p = one - two * two / 3.0;
    const auto pThird = p / 3.0;

    return pThird;
}

double Mathematics::EquationThrice::CalculateQHalf() const noexcept
{
    const auto two = m_Secondary / m_Thrice;
    const auto one = m_Once / m_Thrice;
    const auto zero = m_Constant / m_Thrice;

    const auto q = zero - two * one / 3.0 + two * two * two / 27.0 * 2.0;
    const auto qHalf = q / 2.0;

    return qHalf;
}

void Mathematics::EquationThrice::CalculateResult(double pThird, double qHalf, double discriminant)
{
    // 方程解的三个复数根为：
    // x1 = r     + s
    // x2 = rρ   + sρ^2
    // x3 = rρ^2 + sρ
    // 其中
    // ρ   = -0.5 + i(sqrt(3)/2)
    // ρ^2 = -0.5 - i(sqrt(3)/2)
    if (DoubleMath::FAbs(discriminant) <= GetEpsilon())
        CalculateResultDiscriminantIsZero(qHalf);
    else if (0.0 < discriminant)
        CalculateResultDiscriminantIsPlus(qHalf, discriminant);
    else
        CalculateResultDiscriminantIsNegative(pThird, qHalf);
}

void Mathematics::EquationThrice::CalculateResultDiscriminantIsPlus(double qHalf, double discriminant)
{
    const auto two = m_Secondary / m_Thrice;

    const auto discriminantSqrt = DoubleMath::Sqrt(discriminant);
    const auto rCube = -qHalf + discriminantSqrt;
    const auto sCube = -qHalf - discriminantSqrt;

    const auto r = DoubleMath::CubeRoot(rCube);
    const auto s = DoubleMath::CubeRoot(sCube);

    // 求实数根
    const auto realResult = r + s - two / 3.0;

    SetRealResult(realResult);

    // 求虚数根
    const Imaginary density{ -0.5, DoubleMath::Sqrt(3.0) / 2.0 };
    const Imaginary densitySquare{ -0.5, -DoubleMath::Sqrt(3.0) / 2.0 };

    auto minImaginaryResult = density * r + densitySquare * s - two / 3.0;
    auto maxImaginaryResult = density * s + densitySquare * r - two / 3.0;

    if (0 < minImaginaryResult.imag())
    {
        swap(minImaginaryResult, maxImaginaryResult);
    }

    SetImaginaryResult(minImaginaryResult);
    SetImaginaryResult(maxImaginaryResult);
}

void Mathematics::EquationThrice::CalculateResultDiscriminantIsZero(double qHalf)
{
    const auto two = m_Secondary / m_Thrice;

    const auto r = DoubleMath::CubeRoot(qHalf);

    auto minRealResult = 2 * r - two / 3.0;
    auto maxRealResult = -r - two / 3.0;

    if (maxRealResult < minRealResult)
    {
        swap(minRealResult, maxRealResult);
    }

    SetRealResult(minRealResult);
    SetRealResult(maxRealResult);
}

void Mathematics::EquationThrice::CalculateResultDiscriminantIsNegative(double pThird, double qHalf)
{
    const auto two = m_Secondary / m_Thrice;

    // 下面将x = 2mcosθ代入方程
    // 并根据4cos^3(θ) - 3cosθ = cos(3θ)求出方程的解。
    const auto middleAngle = DoubleMath::ACos(-qHalf / DoubleMath::Sqrt(-pThird * pThird * pThird)) / 3.0;
    const auto leastAngle = middleAngle - 2.0 * DoubleMath::GetPI() / 3.0;
    const auto mostAngle = middleAngle + 2.0 * DoubleMath::GetPI() / 3.0;
    const auto prefix = 2.0 * DoubleMath::Sqrt(-pThird);

    const auto leastAngleRealResult = prefix * DoubleMath::Cos(leastAngle) - two / 3.0;
    const auto middleAngleRealResult = prefix * DoubleMath::Cos(middleAngle) - two / 3.0;
    const auto mostAngleRealResult = prefix * DoubleMath::Cos(mostAngle) - two / 3.0;

    SetRealResult(leastAngleRealResult);
    SetRealResult(middleAngleRealResult);
    SetRealResult(mostAngleRealResult);

    SortResult();
}
