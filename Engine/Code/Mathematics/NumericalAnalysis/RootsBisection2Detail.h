/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/21 10:27)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_ROOTS_BISECTION2_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_ROOTS_BISECTION2_DETAIL_H

#include "RootsBisection2.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::RootsBisection2<Real>::RootsBisection2(int xMaxIterations, int yMaxIterations) requires(!CoreTools::IsArbitraryPrecision<Real>::value)
    : xBisector{ xMaxIterations },
      yBisector{ yMaxIterations },
      xRoot{ 0 },
      yRoot{ 0 },
      fAtRoot{ 0 },
      gAtRoot{ 0 },
      noGuaranteeForRootBound{ false }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::RootsBisection2<Real>::RootsBisection2(int precision, int xMaxIterations, int yMaxIterations) requires(CoreTools::IsArbitraryPrecision<Real>::value)
    : xBisector{ precision, xMaxIterations },
      yBisector{ precision, yMaxIterations },
      xRoot{ 0 },
      yRoot{ 0 },
      fAtRoot{ 0 },
      gAtRoot{ 0 },
      noGuaranteeForRootBound{ false }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::RootsBisection2<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
int Mathematics::RootsBisection2<Real>::operator()(const std::function<Real(const Real&, const Real&)>& f,
                                                   const std::function<Real(const Real&, const Real&)>& g,
                                                   const Real& xMin,
                                                   const Real& xMax,
                                                   const Real& yMin,
                                                   const Real& yMax,
                                                   Real& aXRoot,
                                                   Real& aYRoot,
                                                   Real& aFAtRoot,
                                                   Real& aGAtRoot)
{
    /// XFunction(x) = F(x,y), 这里 G(x,y) = 0.
    auto xFunction = [this, &f, &g, &yMin, &yMax](const Real& x) {
        /// YFunction(y) = G(x,y)
        auto yFunction = [&g, &x](Real const& y) {
            return g(x, y);
        };

        /// 在y变量中进行双截，以找到YFunction(y)的根。
        const auto numYIterations = yBisector(yFunction, yMin, yMax, yRoot, gAtRoot);
        noGuaranteeForRootBound = (numYIterations == 0);
        return f(x, yRoot);
    };

    /// 在x变量中进行双截，以找到XFunction(x)的根。
    const auto numXIterations = xBisector(xFunction, xMin, xMax, xRoot, fAtRoot);
    noGuaranteeForRootBound = (numXIterations == 0);
    aXRoot = xRoot;
    aYRoot = yRoot;
    aFAtRoot = fAtRoot;
    aGAtRoot = gAtRoot;

    return numXIterations;
}

template <typename Real>
bool Mathematics::RootsBisection2<Real>::NoGuaranteeForRootBound() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return noGuaranteeForRootBound;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_ROOTS_BISECTION2_DETAIL_H
