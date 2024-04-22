/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/21 21:31)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_ROOTS_CUBIC_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_ROOTS_CUBIC_H

#include "Mathematics/MathematicsDll.h"

#include "Algebra/PolynomialRoot.h"
#include "RootsQuadratic.h"
#include "Mathematics/Rational/BinaryScientificRational.h"
#include "Mathematics/Rational/UIntegerArbitraryPrecision32.h"

/// 计算具有实值系数的三次多项式的实值根。
/// 一般的三次多项式是g(x) = g0 + g1 * x + g2 * x^2 + g3 * x^3，其中g3不为零。
/// 一次三次多项式为m(x) = m0 + m1 * x + m2 * x^2 + x^3。
/// 抑制的三次多项式是d(x) = d0 + d1 * x + x^3。为了精确起见，
/// 使用有理算术对根和乘法进行分类。
///
/// 该代码对根的边界间隔使用平分。
/// 对于具有所有实根的n次多项式，
/// Samuelson不等式https://en.wikipedia.org/wiki/Samuelson%27s_inequality提供边界区间[b0,b1]，
/// 其中
///   b0 = (-p[n-1] - (n-1) * s) / (n * p[n])
///   b1 = (-p[n-1] + (n-1) * s) / (n * p[n])
///   s = sqrt(p[n-1]^2 - 2 * n * p[n] * p[n-2] / (n-1))
/// 应用于一般立方,
///   b0 = (-p2 - 2 * s) / (3 * p3)
///   b1 = (-p2 + 2 * s) / (3 * p3)
///   s = sqrt(p2^2 - 3 * p3 * p1)
/// 应用于凹陷的立方体，
///   b0 = -sqrt(-4 * p1 / 3)
///   b1 = +sqrt(-4 * p1 / 3)
///
/// 对于n次多项式，
/// 拉格朗日界为b = max(1,|p[0]/p[n]|, |p[1]/p[n]|, ..., |p[n-1]/p[n]|)
/// 实根位于区间[-b,b]中。
namespace Mathematics
{
    template <typename T>
    class RootsCubic
    {
    public:
        using ClassType = RootsCubic<T>;

        /// 使用有理算术和浮点算术的混合运算来求解根。
        /// roots[]数组必须至少有2个元素。
        /// 返回的int是roots[]数组中有效根的数目。
        using Rational = BinaryScientificRational<UIntegerArbitraryPrecision32>;
        using PolynomialRoot = Algebra::PolynomialRoot<T>;
        using PolynomialRootContainer = std::vector<PolynomialRoot>;
        using RationalPolynomialRoot = Algebra::PolynomialRoot<Rational>;
        using RationalPolynomialRootContainer = std::array<RationalPolynomialRoot, 3>;
        using Math = Math<T>;

    public:
        RootsCubic() noexcept;

        CLASS_INVARIANT_DECLARE;

        /// 求解一般立方 g0 + g1*x + g2*x^2 + g3*x^3 = 0.
        NODISCARD static int Solve(bool useBisection,
                                   const T& g0,
                                   const T& g1,
                                   const T& g2,
                                   const T& g3,
                                   PolynomialRootContainer& roots) requires(std::is_floating_point_v<T> || std::is_same_v<T, Rational>);

        /// 求解一次立方 m0 + m1*x + m2*x^2 + x^3 = 0.
        NODISCARD static int Solve(bool useBisection,
                                   const T& m0,
                                   const T& m1,
                                   const T& m2,
                                   PolynomialRootContainer& roots) requires(std::is_floating_point_v<T> || std::is_same_v<T, Rational>);

        /// 求解凹陷的立方体 d0 + d1 * x + x^3 = 0.
        NODISCARD static int Solve(bool useBisection,
                                   const T& d0,
                                   const T& d1,
                                   PolynomialRootContainer& roots) requires(std::is_floating_point_v<T> || std::is_same_v<T, Rational>);

        NODISCARD static int ComputeDepressedRoots(bool useBisection,
                                                   const Rational& rD0,
                                                   const Rational& rD1,
                                                   RationalPolynomialRootContainer& rRoots);

    private:
        using RootsLinear = RootsLinear<T>;
        using RootsQuadratic = RootsQuadratic<T>;

    private:
        /// 确定多项式是否具有零值根。
        NODISCARD static int HasZeroValuedRoots(bool useBisection,
                                                const T& g1,
                                                const T& g2,
                                                const T& g3,
                                                PolynomialRootContainer& roots);

        NODISCARD static int HasZeroValuedRoots(bool useBisection,
                                                const T& m1,
                                                const T& m2,
                                                PolynomialRootContainer& roots);

        /// 将分类器计算封装在函数中支持T类型的转换。
        /// 如果T是Rational，则g0、g1、g2和g3通过引用传递给该函数而不进行转换。
        /// 如果T是“float”或“double”，编译器将生成g0、g1、g2和g3到Rational值的隐式转换。
        static void ComputeClassifiers(const Rational& rG0,
                                       const Rational& rG1,
                                       const Rational& rG2,
                                       const Rational& rG3,
                                       Rational& rD0,
                                       Rational& rD1,
                                       Rational& rM2Div3);

        /// 将分类器计算封装在函数中支持T类型的转换。
        /// 如果T是Rational，则g0、g1和g2通过引用传递给该函数而不进行转换。
        /// 如果T是“float”或“double”，编译器将生成g0、g1和g2到Rational值的隐式转换
        static void ComputeClassifiers(const Rational& rM0,
                                       const Rational& rM1,
                                       const Rational& rM2,
                                       Rational& rD0,
                                       Rational& rD1,
                                       Rational& rM2Div3);

        NODISCARD static int ComputeDepressedRootsBisection(const Rational& rD0, const Rational& rD1, RationalPolynomialRootContainer& rRoots) requires(std::is_arithmetic_v<T>);
        NODISCARD static int ComputeDepressedRootsBisection(const Rational& rD0, const Rational& rD1, RationalPolynomialRootContainer& rRoots) requires(!std::is_arithmetic_v<T>);

        NODISCARD static int ComputeDepressedRootsClosedForm(const Rational& rD0, const Rational& rD1, RationalPolynomialRootContainer& rRoots);
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_ROOTS_CUBIC_H
