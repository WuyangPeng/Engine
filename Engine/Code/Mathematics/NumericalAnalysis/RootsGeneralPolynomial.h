/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/03/28 22:16)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_ROOTS_GENERAL_POLYNOMIAL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_ROOTS_GENERAL_POLYNOMIAL_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Base/Math.h"
#include "Mathematics/Rational/BinaryScientificRational.h"
#include "Mathematics/Rational/UIntegerArbitraryPrecision32.h"

/// Solve函数返回多项式的实值根
/// p(x) = p[0] + p[1] * x + p[2] * x^2 + ... + p[d] * x^d
/// 导数是
/// p'(x) = p[1] + 2 * p[2] * x + ... + d * p[d] * x^{d-1}.
/// 如果r0和r1是p'(x)的连续根，比如r0 < r1，那么p(t)在开区间(r0,r1)上是单调的。
/// 此外，如果p(r0) * p(r1) <= 0，则p(x)在闭区间[r0,r1]上具有唯一根。
/// 使用这一观察结果，可以通过d阶计算p(x)的导数，找到k+1阶导数的根，然后使用这些根来绑定k阶导数的根号。
/// 这是一个递归公式，实现为递归函数调用。
/// TODO:用模拟递归替换递归函数调用，以避免调用堆栈溢出。
///
/// 现在已弃用的旧代码是RootsPolynomial<T>::Find(...)。
/// 它只使用浮点运算。计算多项式导数系数时的舍入误差可能是灾难性的，导致极不准确的根。
/// 对k+1阶导数的根的估计使用快速的平分。
/// 不幸的是，快速和不准确是不可取的。
/// 旧代码确实支持有理数的模板类型，但平分需要很长时间，因此实际上永远不会收敛。
///
/// 新代码混合使用了有理算术和浮点算术。
/// 多项式导数的系数是用有理算术计算的。
/// 当到了平分的时候，区间位于端点处的有理多项式值具有相反符号的区间。
/// 有理值平分实际上不会收敛（有理中的位数非常大），
/// 因此多项式系数被四舍五入到最接近的浮点数，并且多项式在端点使用浮点运算进行评估。
/// 对有理多项式值具有相反符号但浮点多项式值不具有相反符号的情况进行了特殊处理。

namespace Mathematics
{
    template <typename T>
    requires(std::is_arithmetic_v<T>)
    class RootsGeneralPolynomial
    {
    public:
        using ClassType = RootsGeneralPolynomial<T>;

        using Rational = BinaryScientificRational<UIntegerArbitraryPrecision32>;
        using RationalContainer = std::vector<Rational>;
        using Container = std::vector<T>;
        using MathType = Math<T>;

    public:
        RootsGeneralPolynomial() noexcept;

        CLASS_INVARIANT_DECLARE;

        static void Solve(const Container& p, bool useThreading, Container& roots);

        static void Solve(const RationalContainer& rP, bool useThreading, RationalContainer& rRoots);

    private:
        static void InitiateSolver(const RationalContainer& rP, bool useThreading, RationalContainer& rRoots);

        static void SolveRecursive(const RationalContainer& rP, const Rational& rXMin, const Rational& rXMax, bool useThreading, RationalContainer& rRoots);

        NODISCARD static bool Bisect(const Container& tP, const RationalContainer& rP, const Rational& rXMin, const Rational& rXMax, Rational& rRoot);

        template <typename Numeric>
        static Numeric Evaluate(const std::vector<Numeric>& p, const Numeric& x);
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_ROOTS_GENERAL_POLYNOMIAL_H
