/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/19 21:43)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_ALGEBRA_ODE_RUNGE_KUTTA4_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_ALGEBRA_ODE_RUNGE_KUTTA4_H

#include "Mathematics/MathematicsDll.h"

#include "OdeSolver.h"
#include "Mathematics/Base/Math.h"

/// TVector模板参数允许您在编译时已知维度N时使用Vector<N,Real>创建解算器，
/// 或在运行时已知维度N时使用VariableLengthVector<Real>创建求解器。
/// 这两个类都有'int GetSize() const'，
/// 允许OdeSolver派生类查询维度。
namespace Mathematics::Algebra
{
    template <typename Real, typename TVector>
    class OdeRungeKutta4 : public OdeSolver<Real, TVector>
    {
    public:
        using ClassType = OdeRungeKutta4<Real, TVector>;
        using ParentType = OdeSolver<Real, TVector>;

        using Math = Math<Real>;
        using FunctionType = std::function<TVector(Real, const TVector&)>;

    public:
        OdeRungeKutta4(Real tDelta, const FunctionType& f);

        CLASS_INVARIANT_DECLARE;

        /// 使用dx/dt = F(t,x)从x(t) 估计x(t + tDelta)。您可以允许xIn和xOut是同一个对象。
        void Update(Real tIn, const TVector& xIn, Real& tOut, TVector& xOut) override;
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_ALGEBRA_ODE_RUNGE_KUTTA4_H
