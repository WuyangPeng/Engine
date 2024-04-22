/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/03/29 16:45)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_ROOTS_QUARTIC_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_ROOTS_QUARTIC_H

#include "Mathematics/MathematicsDll.h"

#include "Algebra/PolynomialRoot.h"
#include "RootsCubic.h"
#include "Mathematics/Rational/BinaryScientificRational.h"
#include "Mathematics/Rational/UIntegerArbitraryPrecision32.h"

/// 计算具有实值系数的四次多项式的实值根。一般的四次多项式是
///  g(x) = g0 + g1 * x + g2 * x^2 + g3 * x^3 + g4 * x^4
/// 其中g4不为零。一次四次多项式是
/// m(x) = m0 + m1 * x + m2 * x^2 + m3 * x^3 + x^4
/// 压抑的四次多项式是
/// d(x) = d0 + d1 * x + d2 * x^2 + x^4
/// 根和乘法的分类是使用有理算术进行的，以达到精确性。
///
/// 代码使用根的边界间隔。对于具有所有实根的n次多项式，
/// Samuelson不等式
/// https://en.wikipedia.org/wiki/Samuelson%27s_inequality
/// 提供间隔[b0,b1，其中
///   b0 = (-p[n-1] - (n-1) * s) / (n * p[n])
///   b1 = (-p[n-1] + (n-1) * s) / (n * p[n])
///   s = sqrt(p[n-1]^2 - 2 * n * p[n] * p[n-2] / (n-1))
/// 应用于一般的quartic( n - 4)，
///   b0 = (-p3 - 3 * s) / (4 * p4)
///   b1 = (-p3 + 3 * s) / (4 * p4)
///   s = sqrt(p3^2 - 8 * p4 * p2 / 3)
/// 应用于具有所有实根的下凹四次函数，
///   b0 = -sqrt(-3 * p2 / 2)
///   b1 = +sqrt(-3 * p2 / 2)
///
/// 对于一个n次多项式，拉格朗日（Lagrange）的界是
/// b = max(1,|p[0]/p[n]|, |p[1]/p[n]|, ..., |p[n-1]/p[n]|)
/// 真实根位于区间[-b,b]内。
namespace Mathematics
{
    template <typename T>
    class RootsQuartic
    {
    public:
        using ClassType = RootsQuartic<T>;

        /// 使用有理算术和浮点算术的混合运算来求解根。根[]数组必须至少有4个元素。
        /// 返回的int是roots[]数组中有效根的数目。
        using Rational = BinaryScientificRational<UIntegerArbitraryPrecision32>;
        using PolynomialRoot = Algebra::PolynomialRoot<T>;
        using PolynomialRootContainer = std::vector<PolynomialRoot>;
        using RationalPolynomialRoot = Algebra::PolynomialRoot<Rational>;
        using RationalPolynomialRootContainer = std::array<RationalPolynomialRoot, 4>;
        using Math = Math<T>;

    public:
        RootsQuartic() noexcept;

        CLASS_INVARIANT_DECLARE;

        /// 求解一般的四次方 g0 + g1*x + g2*x^2 + g3*x^3 + g4*x^4 = 0.
        NODISCARD static int Solve(bool useBisection,
                                   const T& g0,
                                   const T& g1,
                                   const T& g2,
                                   const T& g3,
                                   const T& g4,
                                   PolynomialRootContainer& roots) requires(std::is_floating_point_v<T> || std::is_same_v<T, Rational>);

        /// 求解一次四次方程 m0 + m1*x + m2*x^2 + m3*x^3 + x^4 = 0.
        NODISCARD static int Solve(bool useBisection,
                                   const T& m0,
                                   const T& m1,
                                   const T& m2,
                                   const T& m3,
                                   PolynomialRootContainer& roots) requires(std::is_floating_point_v<T> || std::is_same_v<T, Rational>);

        /// 求解凹陷的四次方 d0 + d1*x + d2*x^2 + x^4 = 0.
        NODISCARD static int Solve(bool useBisection,
                                   const T& d0,
                                   const T& d1,
                                   const T& d2,
                                   PolynomialRootContainer& roots) requires(std::is_floating_point_v<T> || std::is_same_v<T, Rational>);

        NODISCARD static int ComputeDepressedRoots(bool useBisection,
                                                   const Rational& rD0,
                                                   const Rational& rD1,
                                                   const Rational& rD2,
                                                   RationalPolynomialRootContainer& rRoots);

    private:
        using RationalRootsCubic = RootsCubic<Rational>;
        using RootsCubic = RootsCubic<T>;

    private:
        /// 确定多项式是否具有零值根。
        NODISCARD static int HasZeroValuedRoots(bool useBisection,
                                                const T& g1,
                                                const T& g2,
                                                const T& g3,
                                                const T& g4,
                                                PolynomialRootContainer& roots);

        NODISCARD static int HasZeroValuedRoots(bool useBisection,
                                                const T& m1,
                                                const T& m2,
                                                const T& m3,
                                                PolynomialRootContainer& roots);

        /// 将分类器计算封装在函数中支持类型T的转换。
        /// 如果T是Rational，则g0、g1、g2、g3和g4通过引用传递给该函数而不进行转换。
        /// 如果T是“float”或“double”，编译器将生成g0、g1、g2、g3和g4到Rational值的隐式转换。
        static void ComputeClassifiers(const Rational& rG0,
                                       const Rational& rG1,
                                       const Rational& rG2,
                                       const Rational& rG3,
                                       const Rational& rG4,
                                       Rational& rD0,
                                       Rational& rD1,
                                       Rational& rD2,
                                       Rational& rM3Div4);

        /// 将分类器计算封装在函数中支持T类型的转换。
        /// 如果T是有理的，则m0、m1、m2和m3通过引用传递到该函数而不进行转换。
        /// 如果T是“float”或“double”，编译器将生成m0、m1、m2和m3到Rational值的隐式转换。
        static void ComputeClassifiers(const Rational& rM0,
                                       const Rational& rM1,
                                       const Rational& rM2,
                                       const Rational& rM3,
                                       Rational& rD0,
                                       Rational& rD1,
                                       Rational& rD2,
                                       Rational& rM3Div4);

        NODISCARD static int SolveBiquadratic(bool useBisection,
                                              const Rational& rD0,
                                              const Rational& rD2,
                                              RationalPolynomialRootContainer& rRoots);

        NODISCARD static int ComputeDepressedRootsBisection(const Rational& rD0,
                                                            const Rational& rD1,
                                                            const Rational& rD2,
                                                            RationalPolynomialRootContainer& rRoots);

        NODISCARD static int ComputeDepressedRootsClosedForm(const Rational& rD0,
                                                             const Rational& rD1,
                                                             const Rational& rD2,
                                                             RationalPolynomialRootContainer& rRoots);
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_ROOTS_QUARTIC_H
