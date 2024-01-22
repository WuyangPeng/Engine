/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/12 14:03)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_POLYNOMIAL_ROOTS_RATIONAL_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_POLYNOMIAL_ROOTS_RATIONAL_DETAIL_H

#include "PolynomialRootsRational.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Base/MathDetail.h"
#include "Mathematics/Rational/SignRationalDetail.h"

#include <memory>

template <typename Real>
typename Mathematics::PolynomialRootsRational<Real>::PolynomialRational Mathematics::PolynomialRootsRational<Real>::GetZero() noexcept
{
    return PolynomialRational{};
};

template <typename Real>
typename Mathematics::PolynomialRootsRational<Real>::PolynomialRational Mathematics::PolynomialRootsRational<Real>::GetOne()
{
    return PolynomialRational{ Math::GetValue(1) };
}

template <typename Real>
Mathematics::PolynomialRootsRational<Real>::PolynomialRootsRational(Real epsilon) noexcept
    : quantity{ 0 }, epsilon{ epsilon }, root{}, multiplicity{}
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::PolynomialRootsRational<Real>::IsValid() const noexcept
{
    if (0 <= quantity)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
int Mathematics::PolynomialRootsRational<Real>::GetQuantity() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return quantity;
}

template <typename Real>
Real Mathematics::PolynomialRootsRational<Real>::GetRoot(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return root.at(index);
}

template <typename Real>
int Mathematics::PolynomialRootsRational<Real>::GetMultiplicity(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return multiplicity.at(index);
}

template <typename Real>
bool Mathematics::PolynomialRootsRational<Real>::Linear(Real constant, Real once)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    if (epsilon < Math::FAbs(once))
    {
        // ������ once * x + constant = 0,����once�����㡣
        const auto rationalRoot = PolynomialRational{ -constant } / PolynomialRational{ once };

        quantity = 1;

        root.at(0) = rationalRoot.template ConvertTo<Real>();
        multiplicity.at(0) = 1;

        return true;
    }

    if (epsilon < Math::FAbs(constant))
    {
        // ������ c0 = 0, ����constant������,���Է����޽� ��

        quantity = 0;

        return false;
    }

    // �ö���ʽ����������ʽ��0 = 0�������������Ľ��������
    quantity = System::EnumCastUnderlying(QuantityType::Infinite);

    return true;
}

template <typename Real>
bool Mathematics::PolynomialRootsRational<Real>::Linear(const PolynomialRational& constant, const PolynomialRational& once)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    if (once != GetZero())
    {
        // ������ once * x + constant = 0,����once�����㡣
        const auto rationalRoot = constant / once;
        quantity = 1;

        root.at(0) = -rationalRoot.template ConvertTo<Real>();
        multiplicity.at(0) = 1;

        return true;
    }

    if (constant != GetZero())
    {
        // ������ c0 = 0, ����constant������,���Է����޽� ��

        quantity = 0;

        return false;
    }

    // �ö���ʽ����������ʽ��0 = 0�������������Ľ��������
    quantity = System::EnumCastUnderlying(QuantityType::Infinite);

    return true;
}

template <typename Real>
bool Mathematics::PolynomialRootsRational<Real>::Quadratic(Real constant, Real once, Real secondary)
{
    if (Math::FAbs(secondary) <= epsilon)
    {
        return Linear(constant, once);
    }

    // ������ secondary * x^2 + once * x + constant = 0, ����secondary�Ƿ���
    const PolynomialRational rationalConstant{ constant };
    const PolynomialRational rationalOnce{ once };
    const PolynomialRational rationalSecondary{ secondary };

    // ����һ����һ����, x^2 + once * x + constant = 0.
    const auto rationalSecondaryInverse = GetOne() / rationalSecondary;

    // ���������
    return Quadratic(rationalConstant * rationalSecondaryInverse, rationalOnce * rationalSecondaryInverse);
}

template <typename Real>
bool Mathematics::PolynomialRootsRational<Real>::Quadratic(const PolynomialRational& constant, const PolynomialRational& once, const PolynomialRational& secondary)
{
    if (secondary.Abs() <= PolynomialRational{ epsilon })
    {
        return Linear(constant, once);
    }

    // ������ secondary * x^2 + once * x + constant = 0, ����secondary�Ƿ���
    // ����һ����һ����, x^2 + once * x + constant = 0.
    const auto rationalSecondaryInverse = GetOne() / secondary;

    // ���������
    return Quadratic(constant * rationalSecondaryInverse, once * rationalSecondaryInverse);
}

template <typename Real>
bool Mathematics::PolynomialRootsRational<Real>::Quadratic(const PolynomialRational& constant, const PolynomialRational& once)
{
    const PolynomialRational rationalMinusHalf{ -1, 2 };
    const auto rationalMinusOnceDivided2 = rationalMinusHalf * once;
    auto rationalDiscriminant = rationalMinusOnceDivided2 * rationalMinusOnceDivided2 - constant;
    if (GetZero() < rationalDiscriminant)
    {
        // ������ͬ��ʵ������
        quantity = 2;

        // �����б�ʽ��
        auto discriminant = rationalDiscriminant.template ConvertTo<Real>();

        MATHEMATICS_ASSERTION_3(Math::GetValue(0) < discriminant, "�������\n");

        discriminant = Math::Sqrt(discriminant);

        rationalDiscriminant = PolynomialRational(discriminant);

        const auto rationalRoot0 = rationalMinusOnceDivided2 - rationalDiscriminant;
        const auto rationalRoot1 = rationalMinusOnceDivided2 + rationalDiscriminant;

        root.at(0) = rationalRoot0.template ConvertTo<Real>();
        root.at(1) = rationalRoot1.template ConvertTo<Real>();
        multiplicity.at(0) = 1;
        multiplicity.at(1) = 1;
    }
    else if (rationalDiscriminant.Abs() <= PolynomialRational{ epsilon })
    {
        // һ��ʵ������
        quantity = 1;

        root.at(0) = rationalMinusOnceDivided2.template ConvertTo<Real>();
        multiplicity.at(0) = 2;
    }
    else
    {
        // û��ʵ����
        quantity = 0;
    }

    return 0 < quantity;
}

template <typename Real>
bool Mathematics::PolynomialRootsRational<Real>::Cubic(Real constant, Real once, Real secondary, Real thrice)
{
    if (Math::FAbs(thrice) <= epsilon)
    {
        return Quadratic(constant, once, secondary);
    }

    // �ⷽ����thrice * x^3 + secondary * x^2 + once * x + constant = 0,
    // ���� thrice�ͷ��㡣
    const PolynomialRational rationalConstant{ constant };
    const PolynomialRational rationalOnce{ once };
    const PolynomialRational rationalSecondary{ secondary };
    const PolynomialRational rationalThrice{ thrice };

    // ����һ����һ����ʽ, x^3 + secondary * x^2 + once * x + constant = 0.
    const auto rationalThriceInverse = GetOne() / rationalThrice;

    // ���������
    return Cubic(rationalConstant * rationalThriceInverse, rationalOnce * rationalThriceInverse, rationalSecondary * rationalThriceInverse);
}

template <typename Real>
bool Mathematics::PolynomialRootsRational<Real>::Cubic(const PolynomialRational& constant, const PolynomialRational& once, const PolynomialRational& secondary, const PolynomialRational& thrice)
{
    if (thrice.Abs() <= PolynomialRational{ epsilon })
    {
        return Quadratic(constant, once, secondary);
    }

    // �ⷽ����thrice * x^3 + secondary * x^2 + once * x + constant = 0,
    // ���� thrice�ͷ��㡣
    // ����һ����һ����ʽ, x^3 + secondary * x^2 + once * x + constant = 0.
    const auto rationalThriceInverse = GetOne() / thrice;

    // ���������
    return Cubic(constant * rationalThriceInverse, once * rationalThriceInverse, secondary * rationalThriceInverse);
}

template <typename Real>
bool Mathematics::PolynomialRootsRational<Real>::Cubic(const PolynomialRational& constant, const PolynomialRational& once, const PolynomialRational& secondary)
{
    // ���ٷ���Ϊy^3 + b1 * y + b0 = 0��
    static const PolynomialRational rationalHalf{ 1, 2 };
    static const PolynomialRational rationalThird{ 1, 3 };
    static const PolynomialRational rationalTwo{ 2 };

    auto rationalSecondaryDivide3 = rationalThird * secondary;
    auto rationalSecondaryDivide3Square = rationalSecondaryDivide3 * rationalSecondaryDivide3;
    auto rationalSecondaryDivide3Cube = rationalSecondaryDivide3 * rationalSecondaryDivide3Square;
    auto rationalB1 = once - rationalSecondaryDivide3 * secondary;
    auto rationalB0 = constant - once * rationalSecondaryDivide3 + rationalTwo * rationalSecondaryDivide3Cube;

    // ���������
    auto rationalQ = rationalThird * rationalB1;
    auto rationalR = rationalHalf * rationalB0;
    auto rationalDiscriminant = rationalR * rationalR + rationalQ * rationalQ * rationalQ;
    if (PolynomialRational{ epsilon } < rationalDiscriminant)
    {
        // һ��ʵ���������������������
        quantity = 1;

        // �����б�ʽ
        auto discriminant = rationalDiscriminant.template ConvertTo<Real>();
        MATHEMATICS_ASSERTION_3(Math::GetValue(0) < discriminant, "�������\n");
        auto discriminantSqrt = Math::Sqrt(discriminant);

        rationalDiscriminant = PolynomialRational{ discriminantSqrt };

        auto rationalSum0 = -rationalR + rationalDiscriminant;
        auto sum0 = rationalSum0.template ConvertTo<Real>();
        sum0 = Math::CubeRoot(sum0);

        rationalSum0 = PolynomialRational{ sum0 };

        auto rationalSum1 = -rationalR - rationalDiscriminant;
        auto sum1 = rationalSum1.template ConvertTo<Real>();
        sum1 = Math::CubeRoot(sum1);

        rationalSum1 = PolynomialRational{ sum1 };

        auto rationalRoot = rationalSum0 + rationalSum1 - rationalSecondaryDivide3;

        root.at(0) = rationalRoot.template ConvertTo<Real>();
        multiplicity.at(0) = 1;
    }
    else if (rationalDiscriminant < PolynomialRational{ epsilon })
    {
        // ������ͬ��ʵ������
        quantity = 3;

        multiplicity.at(0) = 1;
        multiplicity.at(1) = 1;
        multiplicity.at(2) = 1;

        // ͨ�����������ֵ���ö���ʽ�ĸ���
        auto negativeQ = -rationalQ.template ConvertTo<Real>();
        MATHEMATICS_ASSERTION_3(Math::GetValue(0) < negativeQ, "�������\n");

        auto negativeR = -rationalR.template ConvertTo<Real>();
        auto negativeDiscriminant = -rationalDiscriminant.template ConvertTo<Real>();
        auto negativeSecondaryDivide3 = -rationalSecondaryDivide3.template ConvertTo<Real>();

        auto sqrt3Value = Math::Sqrt(Math::GetValue(3));
        auto magnitude = Math::Sqrt(negativeQ);
        auto angle = Math::ATan2(Math::Sqrt(negativeDiscriminant), negativeR) / Math::GetValue(3);
        auto cosValue = Math::Cos(angle);
        auto sinValue = Math::Sin(angle);
        auto root0 = negativeSecondaryDivide3 + Math::GetValue(2) * magnitude * cosValue;
        auto root1 = negativeSecondaryDivide3 - magnitude * (cosValue + sqrt3Value * sinValue);
        auto root2 = negativeSecondaryDivide3 - magnitude * (cosValue - sqrt3Value * sinValue);

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

        // �Ե���˳������
        if (root0 <= root1)
        {
            root[0] = root0;
            root[1] = root1;
        }
        else
        {
            root[0] = root1;
            root[1] = root0;
        }

        if (root[1] <= root2)
        {
            root[2] = root2;
        }
        else
        {
            root[2] = root[1];
            if (root[0] <= root2)
            {
                root[1] = root2;
            }
            else
            {
                root[1] = root[0];
                root[0] = root2;
            }
        }

#include SYSTEM_WARNING_POP
    }
    else
    {
        // ����ʵ����������������������ȵġ�
        if (PolynomialRational{ epsilon } < rationalQ.Abs())
        {
            // ����ʵֵ�ĸ���һ���ظ���
            quantity = 2;

            auto r = rationalR.template ConvertTo<Real>();
            r = Math::CubeRoot(r);
            rationalR = PolynomialRational{ r };

            auto rationalRoot0 = rationalSecondaryDivide3 - rationalR;

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

            root[0] = -rationalRoot0.template ConvertTo<Real>();
            multiplicity[0] = 2;

            auto rationalRoot1 = rationalSecondaryDivide3 + rationalTwo * rationalR;
            root[1] = -rationalRoot1.template ConvertTo<Real>();
            multiplicity[1] = 1;

            if (root[1] < root[0])
            {
                std::swap(root[0], root[1]);
                std::swap(multiplicity[0], multiplicity[1]);
            }

#include SYSTEM_WARNING_POP
        }
        else
        {
            // һ��ʵ�����������ظ�
            quantity = 1;

            root.at(0) = -rationalSecondaryDivide3.template ConvertTo<Real>();
            multiplicity.at(0) = 3;
        }
    }

    return true;
}

template <typename Real>
bool Mathematics::PolynomialRootsRational<Real>::Quartic(Real constant, Real once, Real secondary, Real thrice, Real quartic)
{
    if (Math::FAbs(quartic) <= epsilon)
    {
        return Cubic(constant, once, secondary, thrice);
    }

    // ������ quartic * x^4 + thrice * x^3 + secondary * x^2 + once * x + constant = 0,
    // ����quartic�Ƿ���
    const PolynomialRational rationalConstant{ constant };
    const PolynomialRational rationalOnce{ once };
    const PolynomialRational rationalSecondary{ secondary };
    const PolynomialRational rationalThrice{ thrice };
    const PolynomialRational rationalQuartic{ quartic };

    // ������һ����ʽ, x^4 + thrice * x^3 + secondary * x^2 + once * x + constant = 0.
    const auto rationalQuarticInverse = GetOne() / rationalQuartic;

    // ���������
    return Quartic(rationalConstant * rationalQuarticInverse, rationalOnce * rationalQuarticInverse, rationalSecondary * rationalQuarticInverse, rationalThrice * rationalQuarticInverse);
}

template <typename Real>
bool Mathematics::PolynomialRootsRational<Real>::Quartic(const PolynomialRational& constant, const PolynomialRational& once, const PolynomialRational& secondary, const PolynomialRational& thrice, const PolynomialRational& quartic)
{
    if (quartic.Abs() <= PolynomialRational{ epsilon })
    {
        return Cubic(constant, once, secondary, thrice);
    }

    // ������ quartic * x^4 + thrice * x^3 + secondary * x^2 + once * x + constant = 0,
    // ����quartic�Ƿ���
    // ������һ����ʽ, x^4 + thrice * x^3 + secondary * x^2 + once * x + constant = 0.
    const auto rationalQuarticInverse = GetOne() / quartic;

    // ���������
    return Quartic(constant * rationalQuarticInverse, once * rationalQuarticInverse, secondary * rationalQuarticInverse, thrice * rationalQuarticInverse);
}

template <typename Real>
bool Mathematics::PolynomialRootsRational<Real>::Quartic(const PolynomialRational& constant, const PolynomialRational& once, const PolynomialRational& secondary, const PolynomialRational& thrice)
{
    quantity = 0;

    // �����������ζ���ʽ y^3 + secondary * y^2 + once * y + constant = 0
    static const PolynomialRational rationalHalf{ 1, 2 };
    static const PolynomialRational rationalFourth{ 1, 4 };
    static const PolynomialRational rationalEighth{ 1, 8 };
    static const PolynomialRational rationalFour{ 4 };
    static const PolynomialRational rationalTwo{ 2 };
    auto rationalR2 = -rationalHalf * secondary;
    auto rationalR1 = rationalFourth * once * thrice - constant;
    auto rationalR0 = -rationalEighth * (once * once + constant * (thrice * thrice - rationalFour * secondary));

    // ���������ٲ���һ������
    PolynomialRootsRational<Real> polynomial;
    if (!polynomial.Cubic(rationalR0, rationalR1, rationalR2))
    {
        return false;
    }
    const PolynomialRational rationalY{ polynomial.GetRoot(0) };

    auto rationalAlphaSqr = rationalFourth * thrice * thrice - secondary + rationalTwo * rationalY;
    auto alphaSqr = rationalAlphaSqr.template ConvertTo<Real>();

    if (alphaSqr < -epsilon)
    {
        return false;
    }

    if (epsilon < alphaSqr)
    {
        auto alpha = Math::Sqrt(alphaSqr);
        const auto rationalAlpha = PolynomialRational{ alpha };
        auto rationalBeta = rationalHalf * (thrice * rationalY - once) / rationalAlpha;

        auto rationalB0 = rationalY - rationalBeta;
        auto rationalB1 = rationalHalf * thrice - rationalAlpha;
        if (!polynomial.Quadratic(rationalB0, rationalB1))
        {
            return false;
        }
        for (auto i = 0; i < polynomial.GetQuantity(); ++i)
        {
            root.at(quantity) = polynomial.GetRoot(i);
            multiplicity.at(quantity) = polynomial.GetMultiplicity(i);

            ++quantity;
        }

        rationalB0 = rationalY + rationalBeta;
        rationalB1 = rationalHalf * thrice + rationalAlpha;
        if (!polynomial.Quadratic(rationalB0, rationalB1))
        {
            return false;
        }

        for (auto i = 0; i < polynomial.GetQuantity(); ++i)
        {
            root.at(quantity) = polynomial.GetRoot(i);
            multiplicity.at(quantity) = polynomial.GetMultiplicity(i);
            ++quantity;
        }

        SortRoots();

        return 0 < quantity;
    }

    auto rationalBetaSqr = rationalY * rationalY - constant;
    auto betaSqr = rationalBetaSqr.template ConvertTo<Real>();
    if (betaSqr < -epsilon)
    {
        return false;
    }

    if (epsilon < betaSqr)
    {
        auto beta = Math::Sqrt(betaSqr);
        const PolynomialRational rationalBeta{ beta };

        auto rationalB0 = rationalY - rationalBeta;
        auto rationalB1 = rationalHalf * thrice;
        if (!polynomial.Quadratic(rationalB0, rationalB1))
        {
            return false;
        }
        for (auto i = 0; i < polynomial.GetQuantity(); ++i)
        {
            root.at(quantity) = polynomial.GetRoot(i);
            multiplicity.at(quantity) = polynomial.GetMultiplicity(i);

            ++quantity;
        }

        rationalB0 = rationalY + rationalBeta;
        if (!polynomial.Quadratic(rationalB0, rationalB1))
        {
            return false;
        }

        for (auto i = 0; i < polynomial.GetQuantity(); ++i)
        {
            root.at(quantity) = polynomial.GetRoot(i);
            multiplicity.at(quantity) = polynomial.GetMultiplicity(i);

            ++quantity;
        }

        SortRoots();

        return 0 < quantity;
    }

    if (!polynomial.Quadratic(rationalY, rationalHalf * thrice))
    {
        return false;
    }
    for (auto i = 0; i < polynomial.GetQuantity(); ++i)
    {
        root.at(quantity) = polynomial.GetRoot(i);
        multiplicity.at(quantity) = 2 * polynomial.GetMultiplicity(i);

        ++quantity;
    }

    return 0 < quantity;
}

template <typename Real>
void Mathematics::PolynomialRootsRational<Real>::SortRoots() noexcept
{
    // ���������: root[0] <= ... <= root[quantity - 1].
    for (auto i0 = 0; i0 <= quantity - 2; ++i0)
    {
        // �ҵ���С�ĸ���
        auto i1 = i0;
        auto minRoot = root.at(i1);
        auto minMultiplicity = multiplicity.at(i1);
        for (auto i2 = i0 + 1; i2 < quantity; ++i2)
        {
            if (root.at(i2) < minRoot)
            {
                i1 = i2;
                minRoot = root.at(i1);
                minMultiplicity = multiplicity.at(i1);
            }
        }

        if (i1 != i0)
        {
            // �������Ͷ����ԡ�
            root.at(i1) = root.at(i0);
            root.at(i0) = minRoot;
            multiplicity.at(i1) = multiplicity.at(i0);
            multiplicity.at(i0) = minMultiplicity;
        }
    }

    // �����Ҫ�Ļ����ϲ�������
    for (auto i0 = 0; i0 < quantity - 1;)
    {
        const auto nextI0 = i0 + 1;
        if (root.at(i0) == root.at(nextI0))
        {
            // �ϲ�������
            multiplicity.at(i0) += multiplicity.at(nextI0);

            // ͨ��ƽ������Ԫ����������ĸ���
            --quantity;
            for (auto i1 = i0 + 1; i1 < quantity; i1++)
            {
                const auto nextI1 = i1 + 1;
                root.at(i1) = root.at(nextI1);
                multiplicity.at(i1) = multiplicity.at(nextI1);
            }
        }
        else
        {
            ++i0;
        }
    }
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_POLYNOMIAL_ROOTS_RATIONAL_DETAIL_H