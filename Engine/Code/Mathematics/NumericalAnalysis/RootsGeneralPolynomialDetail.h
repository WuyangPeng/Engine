/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/03/28 22:21)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_ROOTS_GENERAL_POLYNOMIAL_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_ROOTS_GENERAL_POLYNOMIAL_DETAIL_H

#include "RootsGeneralPolynomial.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

#include <thread>

template <typename T>
requires(std::is_arithmetic_v<T>)
Mathematics::RootsGeneralPolynomial<T>::RootsGeneralPolynomial() noexcept
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename T>
requires(std::is_arithmetic_v<T>)
bool Mathematics::RootsGeneralPolynomial<T>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename T>
requires(std::is_arithmetic_v<T>)
void Mathematics::RootsGeneralPolynomial<T>::Solve(const Container& p, bool useThreading, Container& roots)
{
    roots.clear();

    /// p的顺序是p.size()。p的度数是p.size() - 1
    if (p.size() <= 1)
    {
        /// 多项式完全是一个常数。即使该常量为0，也不要报告根。
        return;
    }

    /// 移除高阶零值系数。
    auto degree = boost::numeric_cast<int>(p.size() - 1);
    while (degree >= 1 && Math::Approximate(p.at(degree), T{}))
    {
        --degree;
    }

    if (degree == 1)
    {
        roots.emplace_back(-p.at(0) / p.at(1));
        return;
    }

    if (degree == 0)
    {
        /// 多项式完全是一个常数。即使该常量为0，也不要报告根。
        return;
    }

    /// 此时的度数至少为2。为p(x)创建一个具有有理系数的多项式。
    RationalContainer rP(p.size(), Rational::CreateZero());
    for (auto i = 0; i <= degree; ++i)
    {
        rP.at(i) = Rational{ p.at(i) };
    }

    /// 使多项式为monic。
    /// 从理论上讲，这与有理系数多项式的根估计无关。
    /// 然而，在递归过程中，有理系数可能相当大，因此使用一次多项式有助于提高鲁棒性。
    const Rational rOne{ 1 };
    auto& rLast = rP.at(degree);
    if (rLast != rOne)
    {
        for (auto i = 0; i < degree; ++i)
        {
            rP.at(i) /= rLast;
        }
        rP.at(degree) = Rational{ 1 };
    }

    /// 计算柯西边界，并在多项式次数上使用递归求解根。
    RationalContainer rRoots{};

    InitiateSolver(rP, useThreading, rRoots);

    /// 将有理根转换为浮点。
    for (const auto& element : rRoots)
    {
        roots.emplace_back(static_cast<T>(element));
    }
}

template <typename T>
requires(std::is_arithmetic_v<T>)
void Mathematics::RootsGeneralPolynomial<T>::Solve(const RationalContainer& rP, bool useThreading, RationalContainer& rRoots)
{
    rRoots.clear();

    /// p的顺序是p.size()。p的度数是p.size() - 1。
    if (rP.size() <= 1)
    {
        /// 多项式完全是一个常数。即使该常量为0，也不要报告根。
        return;
    }

    /// 移除高阶零值系数。
    auto degree = boost::numeric_cast<int>(rP.size() - 1);
    while (degree >= 1 && rP.at(degree).GetSign() == 0)
    {
        --degree;
    }

    if (degree == 1)
    {
        rRoots.emplace_back(-rP.at(0) / rP.at(1));
        return;
    }

    if (degree == 0)
    {
        /// 多项式完全是一个常数。即使该常量为0，也不要报告根。
        return;
    }

    /// 此时的度数至少为2。

    /// 使多项式为monic。
    /// 从理论上讲，这与有理系数多项式的根估计无关。
    /// 然而，在递归过程中，有理系数可能相当大，
    /// 因此使用一次多项式有助于提高鲁棒性。
    const Rational rOne{ 1 };
    RationalContainer rPMonic(rP.size(), Rational::CreateZero());

    if (auto& rLast = rP.at(degree);
        rLast != rOne)
    {
        for (auto i = 0; i < degree; ++i)
        {
            rPMonic.at(i) = rP.at(i) / rLast;
        }
        rPMonic.at(degree) = rOne;
    }
    else
    {
        rPMonic = rP;
    }

    /// 计算柯西边界，并在多项式次数上使用递归求解根。
    InitiateSolver(rPMonic, useThreading, rRoots);
}

template <typename T>
requires(std::is_arithmetic_v<T>)
void Mathematics::RootsGeneralPolynomial<T>::InitiateSolver(const RationalContainer& rP, bool useThreading, RationalContainer& rRoots)
{
    /// 计算柯西边界以获得包含p(x).的根的区间。此时多项式为monic。
    const auto degree = boost::numeric_cast<int>(rP.size() - 1);
    auto rCauchyBound = Fabs(rP.at(0));
    for (auto i = 1; i + 1 <= degree; ++i)
    {
        if (auto rCandidate = Fabs(rP.at(i));
            rCandidate > rCauchyBound)
        {
            rCauchyBound = rCandidate;
        }
    }
    rCauchyBound += Rational{ 1 };

    /// 以度为单位递归求解。
    SolveRecursive(rP, -rCauchyBound, rCauchyBound, useThreading, rRoots);
}

template <typename T>
requires(std::is_arithmetic_v<T>)
void Mathematics::RootsGeneralPolynomial<T>::SolveRecursive(const RationalContainer& rP, const Rational& rXMin, const Rational& rXMax, bool useThreading, RationalContainer& rRoots)
{
    /// 递归的基础。
    const Rational rZero{ 0 };
    const auto degree = boost::numeric_cast<int>(rP.size() - 1);
    if (degree == 1)
    {
        if (rP.at(1) != rZero)
        {
            rRoots.emplace_back(-rP.at(0) / rP.at(1));
        }
        return;
    }

    /// 使用有理数计算p(x)的导数多项式p'(x)。
    RationalContainer rPDerivative(degree, Rational::CreateZero());
    for (auto i0 = 0, i1 = 1; i1 <= degree; i0 = i1++)
    {
        rPDerivative.at(i0) = rP.at(i1) * Rational{ i1 };
    }

    /// 估计导数多项式的根。
    RationalContainer rRootsDerivative{};
    SolveRecursive(rPDerivative, rXMin, rXMax, true, rRootsDerivative);

    /// 将 rP(x)的系数四舍五入为浮点数。这是通过基于浮点的平分来实现快速性能的。
    Container tP(rP.size());
    for (auto i = 0u; i < rP.size(); ++i)
    {
        tP.at(i) = static_cast<T>(rP.at(i));
    }

    /// 该多项式在导数的连续根之间是单调的。
    /// 该特征和导数根处的多项式值用于通过平分来计算多项式根。
    auto rRoot = Rational::CreateZero();
    if (!rRootsDerivative.empty())
    {
        if (useThreading)
        {
            std::vector<std::thread> process(rRootsDerivative.size() + 1);
            std::vector rootInfo(process.size(), std::make_pair(Rational{ 0 }, false));

            /// 设rXUpper = rRootsDerivative.front()。
            /// 估计区间[rXMin,rXUpper]上的根（如果有的话）。
            process.front() = std::thread([&tP, &rP, &rXMin, &rRootsDerivative, &rootInfo]() {
                rootInfo.front().second = Bisect(tP,
                                                 rP,
                                                 rXMin,
                                                 rRootsDerivative.front(),
                                                 rootInfo.front().first);
            });

            /// 设rXLower = rRootsDerivative.at(i)，设rXUpper = rRootsDerivative[i+1]。
            /// 估计[rXLower,rXUpper]上的根（如果有）。
            for (auto i0 = 0u, i1 = 1u; i1 < rRootsDerivative.size(); i0 = i1++)
            {
                /// 循环计数器必须按值传递。
                /// 否则，它们将被修改为下一个process[]构造函数，
                /// 但上一个process[]正在尝试使用较旧的值。
                process.at(i1) = std::thread([&tP, &rP, i0, i1, &rRootsDerivative, &rootInfo]() {
                    rootInfo.at(i1).second = Bisect(tP,
                                                    rP,
                                                    rRootsDerivative.at(i0),
                                                    rRootsDerivative.at(i1),
                                                    rootInfo.at(i1).first);
                });
            }

            /// 设rXLower = rRootsDerivative.back()。
            /// 估计区间[rXLower,rXMax].上的根（如果有）。
            process.back() = std::thread(
                [&tP, &rP, &rRootsDerivative, &rXMax, &rootInfo]() {
                    rootInfo.back().second = Bisect(tP,
                                                    rP,
                                                    rRootsDerivative.back(),
                                                    rXMax,
                                                    rootInfo.back().first);
                });

            for (auto i = 0u; i < process.size(); ++i)
            {
                process.at(i).join();
                if (rootInfo.at(i).second)
                {
                    rRoots.emplace_back(rootInfo.at(i).first);
                }
            }
        }
        else
        {
            /// 设rXUpper = rRootsDerivative.front()。估计区间[rXMin,rXUpper]上的根（如果有的话）。
            if (Bisect(tP, rP, rXMin, rRootsDerivative.front(), rRoot))
            {
                rRoots.emplace_back(rRoot);
            }

            /// 设rXLower = rRootsDerivative.at(i)，
            /// 设rXUpper = rRootsDerivative[i+1]。估计 [rXLower,rXUpper]上的根（如果有）。
            for (auto i0 = 0u, i1 = 1u; i1 < rRootsDerivative.size(); i0 = i1++)
            {
                if (Bisect(tP, rP, rRootsDerivative.at(i0), rRootsDerivative.at(i1), rRoot))
                {
                    rRoots.emplace_back(rRoot);
                }
            }

            /// 设rXLower = rRootsDerivative.back()。
            /// 估计区间[rXLower,rXMax]上的根（如果有）。
            if (Bisect(tP, rP, rRootsDerivative.back(), rXMax, rRoot))
            {
                rRoots.emplace_back(rRoot);
            }
        }
    }
    else
    {
        /// 多项式在[rXMin,rXMax]上是单调的，所以它最多有一个根。
        if (Bisect(tP, rP, rXMin, rXMax, rRoot))
        {
            rRoots.emplace_back(rRoot);
        }
    }
}

template <typename T>
requires(std::is_arithmetic_v<T>)
bool Mathematics::RootsGeneralPolynomial<T>::Bisect(const Container& tP, const RationalContainer& rP, const Rational& rXMin, const Rational& rXMax, Rational& rRoot)
{
    /// 第一个区间是[-cauchyBound,derivativeRoot.first]。
    /// p'(x)的根可能小于p(x)最小根，在这种情况下，传入的区间端点没有正确排序。
    /// 这样的区间不能产生p(x)的根。
    /// 最后一个区间是[derivative.last,+cauchyBound]。
    /// 可能p'(x)的根大于p(x)最大根，
    /// 在这种情况下，传入的间隔端点没有正确排序。这样的区间不能产生p(x)的根。
    if (rXMin >= rXMax)
    {
        return false;
    }

    const auto rPMin = Evaluate(rP, rXMin);
    const auto signRpMin = rPMin.GetSign();
    if (signRpMin == 0)
    {
        rRoot = rXMin;
        return true;
    }

    const auto rPMax = Evaluate(rP, rXMax);
    const auto signRpMax = rPMax.GetSign();
    if (signRpMax == 0)
    {
        /// 不要返回根rXMax。下一个间隔将负责管理此根。
        return false;
    }

    if (signRpMin * signRpMax > 0)
    {
        /// 多项式p（x）在[rXMin,rXMax]上是单调的，因此它不能在区间上有根。
        return false;
    }

    /// 此时，rPMin和rPMax具有相反的符号。
    /// 在[rXMin,rXMax]上必须有一个唯一的根，
    /// 因为导数在区间上不为零，这意味着p(x)在区间上是单调的。

    /// 使用浮点运算来提高速度。
    /// 请注意，从有理数到浮点数的转换可能会影响符号测试。
    /// 重新计算浮点数的端点测试。

    auto tXMin = static_cast<T>(rXMin);
    auto tPMin = Evaluate(tP, tXMin);
    const auto signTpMin = (tPMin > T{} ? +1 : (tPMin < T{} ? -1 : 0));
    if (signTpMin == 0)
    {
        rRoot = rXMin;
        return true;
    }

    auto tXMax = static_cast<T>(rXMax);
    auto tPMax = Evaluate(tP, tXMax);
    const auto signTpMax = (tPMax > T{} ? +1 : (tPMax < T{} ? -1 : 0));
    if (signTpMax == 0)
    {
        /// 不要返回根rXMax。下一个间隔将负责管理此根。
        return false;
    }

    if (signTpMin * signTpMax > 0)
    {
        /// 我们知道rPMin和rPMax有相反的符号。
        /// 舍入错误导致tPMin和tPMax具有相同的符号。
        /// 与其像有理算术情况那样返回'false'，不如返回'true'，
        /// 其根由x轴与通过(rXMin,rPMin)和(rXMax,rPMax)的线的交点给定。
        /// 这相当于用线段在区间上近似一个几乎平坦的多项式。
        rRoot = (rXMin * rPMax - rXMax * rPMin) / (rPMax - rPMin);
        return true;
    }

    /// 此时，tPMin和tPMax具有相反的符号。
    /// Bisect寻找根源。
    /// 理论上，根是唯一的，但浮点舍入错误可能导致多个根（几乎都是相同的浮点数）。

    /// 当使用浮点数（'float'或 'double'）时，最大迭代次数足以实现收敛。
    constexpr auto maxIterations = 4096;

    T tRoot{};
    for (auto i = 0; i < maxIterations; ++i)
    {
        tRoot = Math::GetRational(1, 2) * (tXMin + tXMax);

        /// 当tXMin和tXMax是连续的浮点数时，
        /// 该测试是为'float'或'double'设计的。
        if (tRoot == tXMin || tRoot == tXMax)
        {
            break;
        }

        auto tPAtRoot = Evaluate(tP, tRoot);
        const auto signTpAtRoot = (tPAtRoot > T{} ? +1 : (tPAtRoot < T{} ? -1 : 0));
        const auto sign = signTpAtRoot * signTpMin;
        if (sign < 0)
        {
            tXMax = tRoot;
            tPMax = tPAtRoot;
        }
        else if (sign > 0)
        {
            tXMin = tRoot;
            tPMin = tPAtRoot;
        }
        else
        {
            /// 根正是tRoot。
            break;
        }
    }

    rRoot = Rational{ tRoot };
    return true;
}

template <typename T>
requires(std::is_arithmetic_v<T>)
template <typename Numeric>
Numeric Mathematics::RootsGeneralPolynomial<T>::Evaluate(const std::vector<Numeric>& p, const Numeric& x)
{
    constexpr auto sMax = std::numeric_limits<size_t>::max();
    auto i = p.size() - 1;
    auto result = p.at(i);
    while (--i != sMax)
    {
        result = x * result + p.at(i);
    }
    return result;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_ROOTS_GENERAL_POLYNOMIAL_DETAIL_H
