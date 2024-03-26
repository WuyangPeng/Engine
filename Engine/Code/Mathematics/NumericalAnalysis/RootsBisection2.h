/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/21 10:27)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_ROOTS_BISECTION2_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_ROOTS_BISECTION2_H

#include "Mathematics/MathematicsDll.h"

#include "RootsBisection1.h"

/// 估计在矩形[xMin,xMax]x[yMin,yMax]上定义的连续函数 F(x,y)和G(x,y)的根。
/// 要求是对于[yMin,yMax]中的每个y'，A(x) = F(x,y')满足A(xMin) * A(xMax) < 0，这保证了A(x)有根。
/// 此外，对于[xMin,xMax]中的每个x'， B(y) = G(x',y)满足 B(yMin) * B(yMax) < 0，这保证了B(y)具有根。
/// 对于A(x)，在x方向上执行二等分。设x'为根。然后在y方向上对B(y)执行二等分。让y为根。函数值为A(x') = F(x',y')。
/// 这实际上是C(x) = F(x,h(x))沿着曲线的平分，其中G(x,h(x)) = 0。
namespace Mathematics
{
    template <typename Real>
    class RootsBisection2
    {
    public:
        using ClassType = RootsBisection2<Real>;

        using RootsBisection1 = RootsBisection1<Real>;

    public:
        /// 当Real是浮点类型时，请使用此构造函数。
        explicit RootsBisection2(int xMaxIterations, int yMaxIterations) requires(!CoreTools::IsArbitraryPrecision<Real>::value);

        /// 当Real是任意精度类型时，请使用此构造函数。
        explicit RootsBisection2(int precision, int xMaxIterations, int yMaxIterations) requires(CoreTools::IsArbitraryPrecision<Real>::value);

        ~RootsBisection2() noexcept = default;
        RootsBisection2(const RootsBisection2& rhs) = delete;
        RootsBisection2& operator=(const RootsBisection2& rhs) = delete;
        RootsBisection2(RootsBisection2&& rhs) noexcept = delete;
        RootsBisection2& operator=(RootsBisection2&& rhs) noexcept = delete;

        CLASS_INVARIANT_DECLARE;

        NODISCARD int operator()(const std::function<Real(const Real&, const Real&)>& f,
                                 const std::function<Real(const Real&, const Real&)>& g,
                                 const Real& xMin,
                                 const Real& xMax,
                                 const Real& yMin,
                                 const Real& yMax,
                                 Real& aXRoot,
                                 Real& aYRoot,
                                 Real& aFAtRoot,
                                 Real& aGAtRoot);

        NODISCARD bool NoGuaranteeForRootBound() const noexcept;

    private:
        RootsBisection1 xBisector;
        RootsBisection1 yBisector;
        Real xRoot;
        Real yRoot;
        Real fAtRoot;
        Real gAtRoot;
        bool noGuaranteeForRootBound;
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_ROOTS_BISECTION2_H
