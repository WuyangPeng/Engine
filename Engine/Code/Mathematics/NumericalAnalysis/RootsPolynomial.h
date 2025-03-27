/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/12 14:42)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_ROOTS_POLYNOMIAL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_ROOTS_POLYNOMIAL_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Base/Math.h"

#include <cmath>
#include <map>
#include <vector>

/// Find函数返回根的数量（如果有的话），并且输出的元素数量是有效的。
/// 如果多项式完全为零，则Find返回1。
///
/// 下面将提到多项式实值根的一些根定界算法 p(t) = c[0] + c[1]*t + ... + c[d-1]*t^{d-1} + c[d]*t^d.
///
/// 1. 根必须包含在区间[-M,M]中
///   M = 1 + max{|c[0]|, ..., |c[d-1]|}/|c[d]| >= 1
/// 称为柯西边界。
///
/// 2.  您可以在区间[-1,1]中搜索根。定义
///   q(t) = t^d*p(1/t) = c[0]*t^d + c[1]*t^{d-1} + ... + c[d-1]*t + c[d]
///   不在[-1,1]中的p(t)的根是[-1,1]的q(t)根
///
/// 3. 在导数p'(t)的两个连续根之间，
/// 例如r0此外，如果p(r0) * p(r1) <= 0，
/// 则p(x)在闭区间[r0，r1]上具有唯一根。
/// 因此，可以通过d阶计算p(t)的导数，找到k+1阶导数的根，
/// 然后使用这些来绑定k阶导数的根号。
///
/// 4. 多项式的Sturm序列可以用于确定根上的边界。
/// 这是一种比第3项更复杂的根边界方法。
/// 此外，Sturm序列允许您计算指定区间上实值根的数量。

/// 注意：不赞成使用RootsPolynomial。
/// 对于低阶寻根器，请使用RootsLinear、RootsQuadratic、RootsCubic和RootsQuartic。
/// 对于一般度数，请使用RootsGeneralPolynomial。

namespace Mathematics
{
    template <typename Real>
    requires(std::is_arithmetic_v<Real>)
    class RootsPolynomial
    {
    public:
        using ClassType = RootsPolynomial<Real>;

        using MathType = Math<Real>;

    public:
        RootsPolynomial() noexcept;

        CLASS_INVARIANT_DECLARE;

        /// 低阶寻根器。
        /// 这些算法使用精确的有理算术进行理论上正确的根分类。
        /// 根本身是用混合类型（有理和浮点算术）计算的。
        /// Rational类型必须支持有理算术(+, -, *, /)；
        /// 例如， BSRational<UIntegerAP32>就足够了。
        /// Rational类必须具有单个输入构造函数，其中输入类型为Real。
        /// 这确保您可以使用浮点输入调用Solve*函数；
        /// 它们将被隐式地转换为Rational。
        /// 最高阶系数必须为非零（p2 != 0表示二次方，p3 != 0表示三次方，p4 != 0代表四次方）。

        template <typename Rational>
        static void SolveQuadratic(const Rational& p0, const Rational& p1, const Rational& p2, std::map<Real, int>& rmMap);

        template <typename Rational>
        static void SolveCubic(const Rational& p0, const Rational& p1, const Rational& p2, const Rational& p3, std::map<Real, int>& rmMap);

        template <typename Rational>
        static void SolveQuartic(const Rational& p0, const Rational& p1, const Rational& p2, const Rational& p3, const Rational& p4, std::map<Real, int>& rmMap);

        /// 只返回实值根的个数及其乘积。
        /// info.size() 是实值根的数量，info[i]是与索引i对应的根的多重性。
        template <typename Rational>
        static void GetRootInfoQuadratic(const Rational& p0, const Rational& p1, const Rational& p2, std::vector<int>& info);

        template <typename Rational>
        static void GetRootInfoCubic(const Rational& p0, const Rational& p1, const Rational& p2, const Rational& p3, std::vector<int>& info);

        template <typename Rational>
        static void GetRootInfoQuartic(const Rational& p0, const Rational& p1, const Rational& p2, const Rational& p3, const Rational& p4, std::vector<int>& info);

        /// 一般方程：sum_{i=0}^{d} c(i)*t^i = 0。
        /// 输入数组'c'必须至少具有d+1个元素，
        /// 输出数组'root'必须至少有d个元素。

        /// 在(-infinity,+infinity)上求根。
        static int Find(int degree, const std::vector<Real>& c, int maxIterations, std::vector<Real>& roots);

        /// 如果你知道p(tMin) * p(tMax) <= 0，那么[tMin, tMax]中必须至少有一个根。使用平分法计算。
        NODISCARD static bool Find(int degree, const std::vector<Real>& c, Real tMin, Real tMax, int maxIterations, Real& root);

    private:
        /// 支持Solve*函数。
        template <typename Rational>
        static void SolveDepressedQuadratic(const Rational& c0, std::map<Rational, int>& rmMap);

        template <typename Rational>
        static void SolveDepressedCubic(const Rational& c0, const Rational& c1, std::map<Rational, int>& rmMap);

        template <typename Rational>
        static void SolveDepressedQuartic(const Rational& c0, const Rational& c1, const Rational& c2, std::map<Rational, int>& rmMap);

        template <typename Rational>
        static void SolveBiquadratic(const Rational& c0, const Rational& c2, std::map<Rational, int>& rmMap);

        /// 支持GetNumRoots*函数。
        template <typename Rational>
        static void GetRootInfoDepressedQuadratic(const Rational& c0, std::vector<int>& info);

        template <typename Rational>
        static void GetRootInfoDepressedCubic(const Rational& c0, const Rational& c1, std::vector<int>& info);

        template <typename Rational>
        static void GetRootInfoDepressedQuartic(const Rational& c0, const Rational& c1, const Rational& c2, std::vector<int>& info);

        template <typename Rational>
        static void GetRootInfoBiquadratic(const Rational& c0, const Rational& c2, std::vector<int>& info);

        /// 支持查找函数。
        NODISCARD static int FindRecursive(int degree, const std::vector<Real>& c, Real tMin, Real tMax, int maxIterations, std::vector<Real>& roots);

        NODISCARD static Real Evaluate(int degree, const std::vector<Real>& c, Real t);
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_ROOTS_POLYNOMIAL_H
