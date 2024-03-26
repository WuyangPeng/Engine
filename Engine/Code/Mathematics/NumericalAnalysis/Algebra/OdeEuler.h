/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/19 17:48)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_ALGEBRA_ODE_EULER_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_ALGEBRA_ODE_EULER_H

#include "Mathematics/MathematicsDll.h"

#include "OdeSolver.h"

/// TVector模板参数允许您在编译时已知维度N时使用Vector<N,Real>创建解算器，
/// 或在运行时已知维度N时使用VariableLengthVector<Real>创建求解器。
/// 这两个类都有'int GetSize() const'，
/// 允许OdeSolver派生类查询维度。
namespace Mathematics::Algebra
{
    template <typename Real, typename TVector>
    class OdeEuler : public OdeSolver<Real, TVector>
    {
    public:
        using ClassType = OdeEuler<Real, TVector>;
        using ParentType = OdeSolver<Real, TVector>;

        using FunctionType = std::function<TVector(Real, const TVector&)>;

    public:
        OdeEuler(Real tDelta, const FunctionType& f);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        void Update(Real tIn, const TVector& xIn, Real& tOut, TVector& xOut) override;
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_ALGEBRA_ODE_EULER_H
