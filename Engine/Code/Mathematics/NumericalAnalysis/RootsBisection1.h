/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/20 16:33)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_ROOTS_BISECTION1_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_ROOTS_BISECTION1_H

#include "Mathematics/MathematicsDll.h"

#include "CoreTools/MemoryTools/TypeTraits.h"
#include "Mathematics/Base/Math.h"

#include <functional>

/// 估计区间[tMin,tMax] 上定义的连续函数 F(t)的根。
/// 如果找到根，函数将通过tRoot返回它。
/// 此外，如果调用方想知道函数在根处有多接近零，则返回fAtTRoot = F(tRoot)；
/// 数值舍入误差可能导致fAtTRoot不完全为零。
/// 返回的int是平分线使用的迭代次数。
/// 如果该数字为0，则F(tMin)*F(tMax) > 0，并且不知道[tMin,tMax]是否包含根。
/// 如果该数字为1，则F(tMin) = 0或F(tMax) = 0（确切地说），
/// tRoot是相应的区间终点。
/// 如果该数字是2或更大，则应用平分，直到找到F(tRoot)恰好为0的tRoot，或者直到当前根估计等于tMin或tMax。
/// 后一种情况可能是由于计算中使用的固定精度（'float'为24位精度，'double'为53位精度，或任意精度数字为用户指定的精度）。
namespace Mathematics
{
    template <typename Real>
    class RootsBisection1
    {
    public:
        using ClassType = RootsBisection1<Real>;

        using MathType = Math<Real>;

    public:
        /// 当Real是浮点类型时，请使用此构造函数。
        explicit RootsBisection1(int maxIterations) requires(!CoreTools::IsArbitraryPrecision<Real>::value);

        /// 当Real是任意精度类型时，请使用此构造函数。
        /// 如果想要无限精度（不舍入任何计算结果），请将精度设置为std::numeric_limits<uint32_t>::max()。
        /// 为了在整个过程中对每个计算结果进行舍入，请将精度设置为小于int的最大值的正数。
        RootsBisection1(int precision, int maxIterations) requires(CoreTools::IsArbitraryPrecision<Real>::value);

        ~RootsBisection1() noexcept = default;
        RootsBisection1(const RootsBisection1& rhs) = delete;
        RootsBisection1& operator=(const RootsBisection1& rhs) = delete;
        RootsBisection1(RootsBisection1&& rhs) noexcept = delete;
        RootsBisection1& operator=(RootsBisection1&& rhs) noexcept = delete;

        CLASS_INVARIANT_DECLARE;

        /// 当F(tMin)和F(tMax) 未知时，使用此函数。
        NODISCARD int operator()(const std::function<Real(const Real&)>& f, const Real& tMin, const Real& tMax, Real& tRoot, Real& fAtTRoot);

        /// 当fAtTMin = F(tMin)和fAtTMax = F(tMax)已知时，使用此函数。
        /// 当|fAtTMin| 或|fAtTMax|是无穷大时，这很有用，
        /// 因为平分线只关心F(t)的符号，所以可以传递sign(fAtTMin)或sign(fAtTMax)，而不是无穷大。
        NODISCARD int operator()(const std::function<Real(const Real&)>& f, const Real& tMin, const Real& tMax, const Real& fMin, const Real& fMax, Real& tRoot, Real& fAtTRoot);

    private:
        /// 使用浮点数字时不进行舍入。
        void RoundInitial(const Real& inT0, const Real& inT1, Real& t0, Real& t1) noexcept requires(!CoreTools::IsArbitraryPrecision<Real>::value);

        NODISCARD Real RoundAverage(const Real& t0, const Real& t1) noexcept requires(!CoreTools::IsArbitraryPrecision<Real>::value);

        /// 任意精度的数字用于舍入。
        void RoundInitial(const Real& inT0, const Real& inT1, Real& t0, Real& t1) requires(CoreTools::IsArbitraryPrecision<Real>::value);

        NODISCARD Real RoundAverage(const Real& t0, const Real& t1) requires(CoreTools::IsArbitraryPrecision<Real>::value);

    private:
        int precision;
        int maxIterations;
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_ROOTS_BISECTION1_H
