/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/08 21:24)

#ifndef MATHEMATICS_RATIONAL_RATIONAL_ARBITRARY_PRECISION_CONVERSION_DETAIL_H
#define MATHEMATICS_RATIONAL_RATIONAL_ARBITRARY_PRECISION_CONVERSION_DETAIL_H

#include "ArbitraryPrecisionConversion.h"
#include "QuadraticFieldsNumberDetail.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

#include <cfenv>

template <typename Rational>
Mathematics::ArbitraryPrecisionConversion<Rational>::ArbitraryPrecisionConversion(int precision, int maxIterations)
    : zero{ 0 },
      one{ 1 },
      three{ 3 },
      five{ 5 },
      precision{ precision },
      maxIterations{ maxIterations },
      threshold{ Ldexp(one, -precision) }
{
    MATHEMATICS_ASSERTION_0(precision > 0, "无效的精度。");
    MATHEMATICS_ASSERTION_0(maxIterations > 0, "无效的最大迭代次数。");

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Rational>
bool Mathematics::ArbitraryPrecisionConversion<Rational>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Rational>
void Mathematics::ArbitraryPrecisionConversion<Rational>::SetPrecision(int aPrecision)
{
    MATHEMATICS_CLASS_IS_VALID_9;
    MATHEMATICS_ASSERTION_0(aPrecision > 0, "无效的精度。");

    precision = aPrecision;
    threshold = Ldexp(one, -precision);
}

template <typename Rational>
void Mathematics::ArbitraryPrecisionConversion<Rational>::SetMaxIterations(int aMaxIterations)
{
    MATHEMATICS_CLASS_IS_VALID_9;
    MATHEMATICS_ASSERTION_0(aMaxIterations > 0, "无效的最大迭代次数。");

    maxIterations = aMaxIterations;
}

template <typename Rational>
int Mathematics::ArbitraryPrecisionConversion<Rational>::GetPrecision() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return precision;
}

template <typename Rational>
int Mathematics::ArbitraryPrecisionConversion<Rational>::GetMaxIterations() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return maxIterations;
}

template <typename Rational>
int Mathematics::ArbitraryPrecisionConversion<Rational>::EstimateSqrt(const Rational& aSqr, Rational& aMin, Rational& aMax)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    /// 因子a^2 = r^2 * 2^e，
    /// 其中r^2在[1/2,1)中。
    /// 计算s^2和用于生成sqrt(a^2)估计值的指数。
    auto sSqr = Rational::CreateZero();
    auto exponentA = 0;
    PreprocessSqr(aSqr, sSqr, exponentA);

    /// 使用FPU通过四舍五入将s = sqrt(sSqr)估计为53位精度。
    /// 乘以适当的指数得到上限aMax > a。
    aMax = GetMaxOfSqrt(sSqr, exponentA);

    /// 计算下限 aMin < a.
    aMin = aSqr / aMax;

    /// 计算牛顿迭代直到收敛。
    /// 最接近a的估计值是aMin，其中aMin <= a <= aMax和a - aMin <= aMax - a。
    auto iterate = 1;
    for (; iterate <= maxIterations; ++iterate)
    {
        if (aMax - aMin < threshold)
        {
            break;
        }

        /// 计算平均值 aMax = (aMin + aMax) / 2。
        /// 四舍五入至精度的两倍，以避免位数的二次增长，并确保aMin可以增加。
        aMax = Ldexp(aMin + aMax, -1);
        Convert(aMax, 2 * precision, FE_UPWARD, aMax);
        aMin = aSqr / aMax;
    }

    return iterate;
}

template <typename Rational>
int Mathematics::ArbitraryPrecisionConversion<Rational>::EstimateSqrt(Rational const& aSqr, Rational& a)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    /// 计算边界间隔 aMin <= a <= aMax.
    auto aMin = Rational::CreateZero();
    auto aMax = Rational::CreateZero();
    const auto numIterates = EstimateSqrt(aSqr, aMin, aMax);

    /// 使用区间端点的平均值作为估计值。
    a = Ldexp(aMin + aMax, -1);

    return numIterates;
}

template <typename Rational>
int Mathematics::ArbitraryPrecisionConversion<Rational>::EstimateApB(Rational const& aSqr, Rational const& bSqr, Rational& tMin, Rational& tMax)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    /// 因子a^2 = r^2 * 2^e，其中r^2在[1/2,1)中。计算u^2和用于生成sqrt(a^2)估计值的指数。
    auto uSqr = Rational::CreateZero();
    auto exponentA = 0;
    PreprocessSqr(aSqr, uSqr, exponentA);

    /// 系数b^2 = s^2 * 2^e，其中s^2在[1/2,1)中。
    /// 计算v^2和用于生成sqrt(b^2)估计值的指数。
    auto vSqr = Rational::CreateZero();
    auto exponentB = 0;
    PreprocessSqr(bSqr, vSqr, exponentB);

    /// 使用FPU通过四舍五入将u = sqrt(u^2)和v = sqrt(v^2)估计为53位精度。
    /// 乘以适当的指数以获得上限aMax > a和bMax > b。
    /// 这确保tMax = aMax + bMax > a + b。
    auto aMax = GetMaxOfSqrt(uSqr, exponentA);
    auto bMax = GetMaxOfSqrt(vSqr, exponentB);
    tMax = aMax + bMax;

    /// 计算下界 tMin < a + b.
    auto a2Pb2 = aSqr + bSqr;
    auto a2Mb2 = aSqr - bSqr;
    auto a2Mb2Sqr = a2Mb2 * a2Mb2;
    auto tMaxSqr = tMax * tMax;
    tMin = (a2Pb2 * tMaxSqr - a2Mb2Sqr) / (tMax * (tMaxSqr - a2Pb2));

    /// 计算牛顿迭代直到收敛。
    /// 最接近a + b的估计是tMin，
    /// 其中tMin < a + b < tMax和(a + b) - tMin < tMax - (a + b)。
    auto iterate = 1;
    for (; iterate <= maxIterations; ++iterate)
    {
        if (tMax - tMin < threshold)
        {
            break;
        }

        /// 计算加权平均值tMax = (3*tMin + tMax) / 4。
        /// 四舍五入至精度的两倍，以避免位数的二次增长，并确保tMin可以增加。
        tMax = Ldexp(three * tMax + tMin, -2);
        Convert(tMax, 2 * precision, FE_UPWARD, tMax);
        tMaxSqr = tMax * tMax;
        tMin = (a2Pb2 * tMaxSqr - a2Mb2Sqr) / (tMax * (tMaxSqr - a2Pb2));
    }

    return iterate;
}

template <typename Rational>
int Mathematics::ArbitraryPrecisionConversion<Rational>::EstimateAmB(Rational const& aSqr, Rational const& bSqr, Rational& tMin, Rational& tMax)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    /// 函数的返回值。
    auto iterate = 0;

    /// 计算稍后在代码中使用的各种量。
    auto a2Tb2 = aSqr * bSqr;  // a^2 * b^2
    auto a2Pb2 = aSqr + bSqr;  // a^2 + b^2
    auto a2Mb2 = aSqr - bSqr;  // a^2 - b^2
    auto a2Mb2Sqr = a2Mb2 * a2Mb2;  // (a^2 - b^2)^2
    auto twoA2Pb2 = Ldexp(a2Pb2, 1);  // 2 * (a^2 + b^2)

    /// 因子a^2 = r^2 * 2^e，其中r^2在[1/2,1)中。
    /// 计算u^2和用于生成sqrt(a^2)估计值的指数。
    auto uSqr = Rational::CreateZero();
    auto exponentA = 0;
    PreprocessSqr(aSqr, uSqr, exponentA);

    /// 系数b^2 = s^2 * 2^e，其中s^2在[1/2,1)中。
    /// 计算v^2和用于生成sqrt(b^2)估计值的指数。
    auto vSqr = Rational::CreateZero();
    auto exponentB = 0;
    PreprocessSqr(bSqr, vSqr, exponentB);

    // Compute the sign of f''(a-b)/8 = a^2 - 3*a*b + b^2. It can be
    // shown that Sign(a^2-3*a*b+b^2) = Sign(a^4-7*a^2*b^2+b^4) =
    // Sign((a^2-b^2)^2-5*a^2*b^2).
    /// 计算f''(a-b)/8 = a^2 - 3*a*b + b^2的符号。
    /// 可以看出，Sign(a^2-3*a*b+b^2) = Sign(a^4-7*a^2*b^2+b^4) =
    /// Sign((a^2-b^2)^2-5*a^2*b^2).
    auto signSecDer = a2Mb2Sqr - five * a2Tb2;

    /// 由两个主要代码块共享的局部变量。
    auto aMin = Rational::CreateZero();
    auto aMax = Rational::CreateZero();
    auto bMin = Rational::CreateZero();
    auto bMax = Rational::CreateZero();
    auto tMinSqr = Rational::CreateZero();
    auto tMaxSqr = Rational::CreateZero();
    auto tMid = Rational::CreateZero();
    auto tMidSqr = Rational::CreateZero();
    auto f = Rational::CreateZero();

    if (signSecDer > zero)
    {
        /// 选择一个初始猜测tMin < a-b。
        /// 使用FPU以指定的四舍五入将u = sqrt(u^2)和v = sqrt(v^2)估计为53位精度。
        /// 乘以适当的指数，得到tMin = aMin - bMax < a-b。
        aMin = GetMinOfSqrt(uSqr, exponentA);
        bMax = GetMaxOfSqrt(vSqr, exponentB);
        tMin = aMin - bMax;

        /// 当a-b几乎为零时，下界可能为负。
        /// 将tMin钳制为零，以保持在f"-positive所在的非负t轴上。
        if (tMin < zero)
        {
            tMin = zero;
        }

        /// 测试tMin是否在包含a-b的positive f"(t)中。
        /// 如果不是，则计算在基础中的tMin。
        /// 符号测试应用于f"(t)/4 = 3*t^2 - (a^2+b^2)。
        tMinSqr = tMin * tMin;
        signSecDer = three * tMinSqr - a2Pb2;
        if (signSecDer < zero)
        {
            /// 初始猜测满足f"(tMin) < 0。
            /// 计算上界tMax > a-b并平分[tMin,tMax]，
            /// 直到t值是指定精度内a-b的估计值，
            /// 或者直到f"(t) >= 0且f(t) >= 0。
            /// 在后一种情况下，继续牛顿的方法，然后保证收敛。
            aMax = GetMaxOfSqrt(uSqr, exponentA);
            bMin = GetMinOfSqrt(vSqr, exponentB);
            tMax = aMax - bMin;

            for (iterate = 1; iterate <= maxIterations; ++iterate)
            {
                if (tMax - tMin < threshold)
                {
                    return iterate;
                }

                tMid = Ldexp(tMin + tMax, -1);
                tMidSqr = tMid * tMid;
                signSecDer = three * tMidSqr - a2Pb2;
                if (signSecDer >= zero)
                {
                    f = tMidSqr * (tMidSqr - twoA2Pb2) + a2Mb2Sqr;
                    if (f >= zero)
                    {
                        tMin = tMid;
                        tMinSqr = tMidSqr;
                        break;
                    }
                    else
                    {
                        /// 四舍五入到精度的两倍，以避免位数的二次增长。
                        tMax = tMid;
                        Convert(tMax, 2 * precision, FE_UPWARD, tMax);
                    }
                }
                else
                {
                    /// 四舍五入到精度的两倍，以避免位数的二次增长。
                    tMin = tMid;
                    Convert(tMin, 2 * precision, FE_DOWNWARD, tMin);
                }
            }
        }

        /// 计算上限 tMax > a-b.
        tMax = (a2Pb2 * tMinSqr - a2Mb2Sqr) / (tMin * (tMinSqr - a2Pb2));

        /// 计算牛顿迭代直到收敛。
        /// 最接近a-b的估计是tMax，其中tMin < a-b < tMax并且tMax - (a-b) < (a-b) - tMin。
        for (iterate = 1; iterate <= maxIterations; ++iterate)
        {
            if (tMax - tMin < threshold)
            {
                break;
            }

            /// 计算加权平均tMin = (3*tMin+tMax)/4。
            /// 四舍五入到精度的两倍，以避免位数的二次增长，并确保tMax可以减少。
            tMin = Ldexp(three * tMin + tMax, -2);
            Convert(tMin, 2 * precision, FE_DOWNWARD, tMin);
            tMinSqr = tMin * tMin;
            tMax = (a2Pb2 * tMinSqr - a2Mb2Sqr) / (tMin * (tMinSqr - a2Pb2));
        }
        return iterate;
    }

    if (signSecDer < zero)
    {
        /// 选择一个初始猜测tMax>a-b。
        /// 使用FPU以指定的四舍五入将u = sqrt(u^2)和v = sqrt(v^2)估计为53位精度。
        /// 乘以适当的指数，得到tMax = aMax - bMin > a-b。
        aMax = GetMaxOfSqrt(uSqr, exponentA);
        bMin = GetMinOfSqrt(vSqr, exponentB);
        tMax = aMax - bMin;

        /// 测试tMax是否在包含a-b的负f"(t)中。
        /// 如果不是，则计算在基础中的tMax。
        /// 符号测试应用于f"(t)/4 = 3*t^2 - (a^2+b^2)。
        tMaxSqr = tMax * tMax;
        signSecDer = three * tMaxSqr - a2Pb2;
        if (signSecDer > zero)
        {
            /// 初始猜测满足f"(tMax) > 0。
            /// 计算下界 tMin < a-b，并平分[tMin,tMax]，
            /// 直到t值是指定精度内对a-b的估计，
            /// 或者直到f"(t) <= 0 和f(t) <= 0。
            /// 在后一种情况下，继续牛顿的方法，然后保证收敛。
            aMin = GetMinOfSqrt(uSqr, exponentA);
            bMax = GetMaxOfSqrt(vSqr, exponentB);
            tMin = aMin - bMax;

            for (iterate = 1; iterate <= maxIterations; ++iterate)
            {
                if (tMax - tMin < threshold)
                {
                    return iterate;
                }

                tMid = Ldexp(tMin + tMax, -1);
                tMidSqr = tMid * tMid;
                signSecDer = three * tMidSqr - a2Pb2;
                if (signSecDer <= zero)
                {
                    f = tMidSqr * (tMidSqr - twoA2Pb2) + a2Mb2Sqr;
                    if (f <= zero)
                    {
                        tMax = tMid;
                        tMaxSqr = tMidSqr;
                        break;
                    }
                    else
                    {
                        /// 四舍五入到精度的两倍，以避免位数的二次增长。
                        tMin = tMid;
                        Convert(tMin, 2 * precision, FE_DOWNWARD, tMin);
                    }
                }
                else
                {
                    /// 四舍五入到精度的两倍，以避免位数的二次增长。
                    tMax = tMid;
                    Convert(tMax, 2 * precision, FE_UPWARD, tMax);
                }
            }
        }

        /// 计算下界 tMin < a-b.
        tMin = (a2Pb2 * tMaxSqr - a2Mb2Sqr) / (tMax * (tMaxSqr - a2Pb2));

        /// 计算牛顿迭代直到收敛。
        /// 最接近a-b的估计是tMin，
        /// 其中tMin < a - b < tMax和(a-b) - tMin < tMax - (a-b)。
        for (iterate = 1; iterate <= maxIterations; ++iterate)
        {
            if (tMax - tMin < threshold)
            {
                break;
            }

            /// 计算加权平均值tMax = (3*tMax+tMin)/4。
            /// 四舍五入至精度的两倍，以避免位数的二次增长，
            /// 并确保tMin可以增加。
            tMax = Ldexp(three * tMax + tMin, -2);
            Convert(tMax, 2 * precision, FE_UPWARD, tMax);
            tMaxSqr = tMax * tMax;
            tMin = (a2Pb2 * tMaxSqr - a2Mb2Sqr) / (tMax * (tMaxSqr - a2Pb2));
        }

        return iterate;
    }

    /// 二阶导数的符号是Sign(a^4-7*a^2*b^2+b^4)，不能为零。
    /// 定义有理r = a^2/b^2，使a^4-7*a^2*b^2+b^4 = 0。
    /// 这意味着r^2 - 7*r^2 + 1 = 0。
    /// 无理根为r = (7 +- sqrt(45))/2，这是一个矛盾。
    THROW_EXCEPTION(SYSTEM_TEXT("这个二阶导数在a-b处不能为零。"))
}

template <typename Rational>
int Mathematics::ArbitraryPrecisionConversion<Rational>::Estimate(QuadraticFieldsN1 const& q, Rational& qMin, Rational& qMax)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    const auto x = q.GetX(0);
    const auto y = q.GetX(1);
    const auto d = q.GetD();

    auto numIterates = 0;
    if (d != zero && y != zero)
    {
        auto aSqr = y * y * d;
        numIterates = EstimateSqrt(aSqr, qMin, qMax);
        if (y > zero)
        {
            qMin = x + qMin;
            qMax = x + qMax;
        }
        else
        {
            auto diff = x - qMax;
            qMax = x - qMin;
            qMin = diff;
        }
    }
    else
    {
        numIterates = 0;
        qMin = x;
        qMax = x;
    }

    return numIterates;
}

template <typename Rational>
int Mathematics::ArbitraryPrecisionConversion<Rational>::Estimate(QuadraticFieldsN1 const& q, Rational& qEstimate)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    /// 计算边界间隔 qMin <= q <= qMax.
    auto qMin = Rational::CreateZero();
    auto qMax = Rational::CreateZero();
    const auto numIterates = Estimate(q, qMin, qMax);
    /// 使用区间端点的平均值作为估计值。
    qEstimate = Ldexp(qMin + qMax, -1);

    return numIterates;
}

template <typename Rational>
void Mathematics::ArbitraryPrecisionConversion<Rational>::PreprocessSqr(const Rational& aSqr, Rational& rSqr, int& exponentA)
{
    /// 系数a^2 = r^2 * 2^e，其中r^2在[1/2,1)中。
    int32_t exponentASqr{};
    rSqr = Frexp(aSqr, &exponentASqr);
    if (exponentASqr & 1)  // 奇数指数
    {
        // a = sqrt(2*r^2) * 2^{(e-1)/2}
        exponentA = (exponentASqr - 1) / 2;
        rSqr = Ldexp(rSqr, 1);  // = 2*rSqr
        // rSqr in [1,2)
    }
    else  // even exponent
    {
        // a = sqrt(r^2) * 2^{e/2}
        exponentA = exponentASqr / 2;
        // rSqr in [1/2,1)
    }
}

template <typename Rational>
Rational Mathematics::ArbitraryPrecisionConversion<Rational>::GetMinOfSqrt(const Rational& rSqr, int exponent)
{
    /// 计算r^2的平方根的下界。
    auto lowerRSqr = 0.0;
    Convert(rSqr, FE_DOWNWARD, lowerRSqr);
    const auto sqrtLowerRSqr = std::sqrt(lowerRSqr);
    Rational aMin{ std::nextafter(sqrtLowerRSqr, -std::numeric_limits<double>::max()) };
    aMin = Ldexp(aMin, exponent);

    return aMin;
}

template <typename Rational>
Rational Mathematics::ArbitraryPrecisionConversion<Rational>::GetMaxOfSqrt(const Rational& rSqr, int exponent)
{
    /// 计算r^2的平方根的上界。
    auto upperRSqr = 0.0;
    Convert(rSqr, FE_UPWARD, upperRSqr);
    const auto sqrtUpperRSqr = std::sqrt(upperRSqr);
    Rational aMax{ std::nextafter(sqrtUpperRSqr, +std::numeric_limits<double>::max()) };
    aMax = Ldexp(aMax, exponent);

    return aMax;
}

#endif  // MATHEMATICS_RATIONAL_RATIONAL_ARBITRARY_PRECISION_CONVERSION_DETAIL_H
