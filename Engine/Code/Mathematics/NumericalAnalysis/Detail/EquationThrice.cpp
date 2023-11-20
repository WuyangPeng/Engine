///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/27 13:45)

#include "Mathematics/MathematicsExport.h"

#include "EquationSecondary.h"
#include "EquationThrice.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Mathematics/Base/MathDetail.h"

Mathematics::EquationThrice::EquationThrice(double constant, double once, double secondary, double thrice, double epsilon)
    : ParentType{ epsilon }, constant{ constant }, once{ once }, secondary{ secondary }, thrice{ thrice }
{
    Calculate();

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, EquationThrice)

double Mathematics::EquationThrice::Substitution(double value) const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return constant + once * value +
           secondary * MathD::Square(value) +
           thrice * value * value * value;
}

Mathematics::EquationThrice::Imaginary Mathematics::EquationThrice::Substitution(const Imaginary& value) const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return constant + once * value +
           secondary * value * value +
           thrice * value * value * value;
}

double Mathematics::EquationThrice::SubstitutionTangent(double solution) const noexcept
{
    return once +
           solution * secondary * 2.0 +
           MathD::Square(solution) * thrice * 3.0;
}

Mathematics::EquationThrice::Imaginary Mathematics::EquationThrice::SubstitutionTangent(const Imaginary& solution) const noexcept
{
    return once +
           solution * secondary * 2.0 +
           solution * solution * thrice * 3.0;
}

void Mathematics::EquationThrice::Solving()
{
    // �� t = x - a / 3
    // ȥ��������õ�����x^3 + px + q = 0
    // p = -a^2/3 + b
    // q = 2a^3/27 - ab/3 +c
    // p' = p / 3 ,q' = q / 2
    const auto pThird = CalculatePThird();
    const auto qHalf = CalculateQHalf();

    // ���ʽ D' = p'^3 + q'^2
    const auto discriminant = CalculateDiscriminant(pThird, qHalf);

    CalculateResult(pThird, qHalf, discriminant);
}

bool Mathematics::EquationThrice::Predigest()
{
    // ������Ϊ��ʱ�����ⷽ�̡�
    if (MathD::FAbs(constant) <= GetEpsilon())
    {
        SetRealResult(0.0);
        const EquationSecondary equation{ once, secondary, thrice };
        AddResult(equation);

        return true;
    }

    // ������Ϊ��ʱ�����ⷽ�̡�
    if (MathD::FAbs(thrice) <= GetEpsilon())
    {
        const EquationSecondary equation{ constant, once, secondary };
        AddResult(equation);

        return true;
    }

    return false;
}

double Mathematics::EquationThrice::CalculatePThird() const noexcept
{
    const auto two = secondary / thrice;
    const auto one = once / thrice;

    const auto p = one - two * two / 3.0;
    const auto pThird = p / 3.0;

    return pThird;
}

double Mathematics::EquationThrice::CalculateQHalf() const noexcept
{
    const auto two = secondary / thrice;
    const auto one = once / thrice;
    const auto zero = constant / thrice;

    const auto q = zero - two * one / 3.0 + two * two * two / 27.0 * 2.0;
    const auto qHalf = q / 2.0;

    return qHalf;
}

void Mathematics::EquationThrice::CalculateResult(double pThird, double qHalf, double discriminant)
{
    // ���̽������������Ϊ��
    // x1 = r     + s
    // x2 = r��   + s��^2
    // x3 = r��^2 + s��
    // ����
    // ��   = -0.5 + i(sqrt(3)/2)
    // ��^2 = -0.5 - i(sqrt(3)/2)
    if (MathD::FAbs(discriminant) <= GetEpsilon())
        CalculateResultDiscriminantIsZero(qHalf);
    else if (0.0 < discriminant)
        CalculateResultDiscriminantIsPlus(qHalf, discriminant);
    else
        CalculateResultDiscriminantIsNegative(pThird, qHalf);
}

void Mathematics::EquationThrice::CalculateResultDiscriminantIsPlus(double qHalf, double discriminant)
{
    const auto two = secondary / thrice;

    const auto discriminantSqrt = MathD::Sqrt(discriminant);
    const auto rCube = -qHalf + discriminantSqrt;
    const auto sCube = -qHalf - discriminantSqrt;

    const auto r = MathD::CubeRoot(rCube);
    const auto s = MathD::CubeRoot(sCube);

    // ��ʵ����
    const auto realResult = r + s - two / 3.0;

    SetRealResult(realResult);

    // ��������
    const Imaginary density{ -0.5, MathD::Sqrt(3.0) / 2.0 };
    const Imaginary densitySquare{ -0.5, -MathD::Sqrt(3.0) / 2.0 };

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
    const auto two = secondary / thrice;

    const auto r = MathD::CubeRoot(qHalf);

    auto minRealResult = 2 * r - two / 3.0;
    auto maxRealResult = -r - two / 3.0;

    if (maxRealResult < minRealResult)
    {
        std::swap(minRealResult, maxRealResult);
    }

    SetRealResult(minRealResult);
    SetRealResult(maxRealResult);
}

void Mathematics::EquationThrice::CalculateResultDiscriminantIsNegative(double pThird, double qHalf)
{
    const auto two = secondary / thrice;

    // ���潫x = 2mcos�ȴ��뷽��
    // ������4cos^3(��) - 3cos�� = cos(3��)������̵Ľ⡣
    const auto middleAngle = MathD::ACos(-qHalf / MathD::Sqrt(-pThird * pThird * pThird)) / 3.0;
    const auto leastAngle = middleAngle - 2.0 * MathD::GetPI() / 3.0;
    const auto mostAngle = middleAngle + 2.0 * MathD::GetPI() / 3.0;
    const auto prefix = 2.0 * MathD::Sqrt(-pThird);

    const auto leastAngleRealResult = prefix * MathD::Cos(leastAngle) - two / 3.0;
    const auto middleAngleRealResult = prefix * MathD::Cos(middleAngle) - two / 3.0;
    const auto mostAngleRealResult = prefix * MathD::Cos(mostAngle) - two / 3.0;

    SetRealResult(leastAngleRealResult);
    SetRealResult(middleAngleRealResult);
    SetRealResult(mostAngleRealResult);

    SortResult();
}
