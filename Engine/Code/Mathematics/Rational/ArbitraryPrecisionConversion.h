/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/09 10:05)

#ifndef MATHEMATICS_RATIONAL_RATIONAL_ARBITRARY_PRECISION_CONVERSION_H
#define MATHEMATICS_RATIONAL_RATIONAL_ARBITRARY_PRECISION_CONVERSION_H

#include "Mathematics/MathematicsDll.h"

#include "QuadraticFieldsNumber.h"

/// 这里的转换函数用于获得有理数和二次域数的任意精度近似。
namespace Mathematics
{
    template <typename Rational>
    class ArbitraryPrecisionConversion
    {
    public:
        using ClassType = ArbitraryPrecisionConversion<Rational>;

        using QuadraticFieldsN1 = QuadraticFieldsNumber<Rational, 1>;
        using QuadraticFieldsN2 = QuadraticFieldsNumber<Rational, 2>;

    public:
        ArbitraryPrecisionConversion(int precision, int maxIterations);

        CLASS_INVARIANT_DECLARE;

        /// 成员访问
        void SetPrecision(int aPrecision);
        void SetMaxIterations(int aMaxIterations);

        NODISCARD int GetPrecision() const noexcept;
        NODISCARD int GetMaxIterations() const noexcept;

        /// 输入a^2是有理的，但a本身通常是非有理的，尽管允许有理值。
        /// 计算根的边界间隔aMin <= a <= aMax，其中端点都在指定的精度内。
        NODISCARD int EstimateSqrt(const Rational& aSqr, Rational& aMin, Rational& aMax);

        /// 当不需要边界间隔时，计算根的估计值。
        NODISCARD int EstimateSqrt(const Rational& aSqr, Rational& a);

        NODISCARD int EstimateApB(const Rational& aSqr, const Rational& bSqr, Rational& tMin, Rational& tMax);

        NODISCARD int EstimateAmB(const Rational& aSqr, const Rational& bSqr, Rational& tMin, Rational& tMax);

        /// 计算根的边界间隔qMin <= q <= qMax，其中端点都在指定的精度内。
        NODISCARD int Estimate(const QuadraticFieldsN1& q, Rational& qMin, Rational& qMax);

        /// 当不需要边界间隔时，计算根的估计值。
        NODISCARD int Estimate(const QuadraticFieldsN1& q, Rational& qEstimate);

    private:
        void PreprocessSqr(const Rational& aSqr, Rational& rSqr, int& exponentA);

        NODISCARD Rational GetMinOfSqrt(const Rational& rSqr, int exponent);

        NODISCARD Rational GetMaxOfSqrt(const Rational& rSqr, int exponent);

    private:
        const Rational zero;
        const Rational one;
        const Rational three;
        const Rational five;
        int precision;
        int maxIterations;
        Rational threshold;
    };
}

#endif  // MATHEMATICS_RATIONAL_RATIONAL_ARBITRARY_PRECISION_CONVERSION_H
