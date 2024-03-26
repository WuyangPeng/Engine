/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/21 22:07)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_ROOTS_QUADRATIC_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_ROOTS_QUADRATIC_H

#include "Mathematics/MathematicsDll.h"

#include "Algebra/PolynomialRoot.h"
#include "RootsLinear.h"
#include "Mathematics/Rational/BinaryScientificRational.h"
#include "Mathematics/Rational/UIntegerArbitraryPrecision32.h"

/// 计算具有实值系数的二次多项式的实值根。一般的二次多项式是
/// g(x) = g0 + g1 * x + g2 * x^2
/// 其中g2不为零。一次二次多项式是
///  m(x) = m0 + m1 * x + x^2
/// 压抑的二次多项式是
///  d(x) = d0 + x^2
/// 根和乘法的分类是使用有理算术进行的，以达到精确性。
///
/// 该代码对根的边界间隔使用平分。对于n次多项式，拉格朗日界为
/// b = max(1,|p[0]/p[n]|, |p[1]/p[n]|, ..., |p[n-1]/p[n]|)
/// 真正的根在区间[-b，b]。
namespace Mathematics
{
    template <typename T>
    class RootsQuadratic
    {
    public:
        using ClassType = RootsQuadratic<T>;

        /// 使用有理算术和浮点算术的混合运算来求解根。
        /// roots[]数组必须至少有2个元素。
        /// 返回的int是roots[]数组中有效根的数目。
        using Rational = BinaryScientificRational<UIntegerArbitraryPrecision32>;
        using PolynomialRoot = Algebra::PolynomialRoot<T>;
        using PolynomialRootContainer = std::vector<PolynomialRoot>;
        using RationalPolynomialRoot = Algebra::PolynomialRoot<Rational>;
        using RationalPolynomialRootContainer = std::array<RationalPolynomialRoot, 2>;
        using Math = Math<T>;

    public:
        RootsQuadratic() noexcept;

        CLASS_INVARIANT_DECLARE;

        /// 求解一般二次型 g0 + g1*x + g2*x^2 = 0.
        NODISCARD static int Solve(bool useBisection,
                                   const T& g0,
                                   const T& g1,
                                   const T& g2,
                                   PolynomialRootContainer& roots) requires(std::is_floating_point_v<T> || std::is_same_v<T, Rational>);

        /// 求解monic二次型 m0 + m1*x + x^2 = 0.
        NODISCARD static int Solve(bool useBisection,
                                   const T& m0,
                                   const T& m1,
                                   PolynomialRootContainer& roots) requires(std::is_floating_point_v<T> || std::is_same_v<T, Rational>);

        /// 求解凹陷的二次型 d0 + x^2 = 0.
        NODISCARD static int Solve(bool useBisection,
                                   const T& d0,
                                   PolynomialRootContainer& roots) requires(std::is_floating_point_v<T> || std::is_same_v<T, Rational>);

        NODISCARD static int ComputeDepressedRoots(bool useBisection,
                                                   const Rational& rD0,
                                                   RationalPolynomialRootContainer& rRoots);

    private:
        using RootsLinear = RootsLinear<T>;

    private:
        /// 确定多项式是否具有零值根。
        NODISCARD static int HasZeroValuedRoots(const T& g1,
                                                const T& g2,
                                                PolynomialRootContainer& roots);

        NODISCARD static int HasZeroValuedRoots(const T& m1, PolynomialRootContainer& roots);

        /// 将分类器计算封装在函数中支持T类型的转换。
        /// 如果T是Rational，则g0、g1和g2通过引用传递给该函数而不进行转换。
        /// 如果T是“float”或“double”，编译器将生成g0、g1和g2到Rational值的隐式转换。
        static void ComputeClassifiers(const Rational& rG0,
                                       const Rational& rG1,
                                       const Rational& rG2,
                                       Rational& rD0,
                                       Rational& rM1Div2);

        /// 将分类器计算封装在函数中支持T类型的转换。
        /// 如果T是Rational，则m0和m1通过引用传递到该函数而不进行转换。
        /// 如果T是“float”或“double”，编译器将生成m0和m1到值的隐式转换。
        static void ComputeClassifiers(const Rational& rM0,
                                       const Rational& rM1,
                                       Rational& rD0,
                                       Rational& rM1Div2);

        NODISCARD static int ComputeDepressedRootsBisection(const Rational& rD0, RationalPolynomialRootContainer& rRoots);

        NODISCARD static int ComputeDepressedRootsClosedForm(const Rational& rD0, RationalPolynomialRootContainer& rRoots);
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_ROOTS_QUADRATIC_H
