/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/19 17:09)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_ALGEBRA_ODE_SOLVER_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_ALGEBRA_ODE_SOLVER_H

#include "Mathematics/MathematicsDll.h"

#include <functional>

/// TVector模板参数允许您在编译时已知维度N时使用Vector<N,Real>创建解算器，
/// 或在运行时已知维度N时使用VariableLengthVector<Real>创建求解器。
/// 这两个类都有'int GetSize() const'，
/// 允许OdeSolver派生类查询维度。
namespace Mathematics::Algebra
{
    template <typename Real, typename TVector>
    class OdeSolver
    {
    public:
        using ClassType = OdeSolver<Real, TVector>;

        using FunctionType = std::function<TVector(Real, const TVector&)>;

    public:
        OdeSolver(Real tDelta, FunctionType f) noexcept;
        virtual ~OdeSolver() noexcept;
        OdeSolver(const OdeSolver& rhs) = default;
        OdeSolver& operator=(const OdeSolver& rhs) = default;
        OdeSolver(OdeSolver&& rhs) = default;
        OdeSolver& operator=(OdeSolver&& rhs) = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        NODISCARD TVector GetFunction(Real tIn, const TVector& xIn) const;

    public:
        /// 成员访问
        void SetTDelta(Real aTDelta) noexcept;

        NODISCARD Real GetTDelta() const noexcept;

        /// 使用 dx/dt = F(t,x)从x(t)估计x(t + tDelta) 。
        /// 派生类实现了这一点，因此xIn和xOut可能是同一个对象。
        virtual void Update(Real tIn, TVector const& xIn, Real& tOut, TVector& xOut) = 0;

    private:
        Real tDelta;
        FunctionType function;
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_ALGEBRA_ODE_SOLVER_H
