/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/19 18:11)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_ALGEBRA_ODE_IMPLICIT_EULER_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_ALGEBRA_ODE_IMPLICIT_EULER_H

#include "Mathematics/MathematicsDll.h"

#include "OdeSolver.h"

/// TVector模板参数允许您在编译时已知维度N时使用Vector<N,Real>创建解算器，
/// 或在运行时已知维度N时使用VariableLengthVector<Real>创建求解器。
/// 这两个类都有'int GetSize() const'，
/// 允许OdeSolver派生类查询维度。
///
/// 函数F(t,x)具有输入t（标量）和输入x（N矢量）。
/// 关于x的一阶导数矩阵是DF(t,x)，一个N乘N的矩阵。
/// 条目DF(r,c) 是F[r]关于x[c]的导数。
namespace Mathematics::Algebra
{
    template <typename Real, typename TVector, typename TMatrix>
    class OdeImplicitEuler : public OdeSolver<Real, TVector>
    {
    public:
        using ClassType = OdeImplicitEuler<Real, TVector, TMatrix>;
        using ParentType = OdeSolver<Real, TVector>;

        using FunctionType = std::function<TVector(Real, const TVector&)>;
        using DerivativeFunctionType = std::function<TMatrix(Real, const TVector&)>;

    public:
        OdeImplicitEuler(Real tDelta, const FunctionType& f, DerivativeFunctionType df);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        /// 使用dx/dt = F(t,x)从x(t)估计 x(t + tDelta)。
        /// 您可以允许xIn和xOut是同一个对象。
        void Update(Real tIn, const TVector& xIn, Real& tOut, TVector& xOut) override;

    private:
        DerivativeFunctionType derivativeFunction;
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_ALGEBRA_ODE_IMPLICIT_EULER_H
