/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/12 13:44)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_ODE_IMPLICIT_EULER_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_ODE_IMPLICIT_EULER_H

#include "Mathematics/MathematicsDll.h"

#include "OdeSolver.h"
#include "Mathematics/Algebra/VariableLengthVector.h"
#include "Mathematics/Algebra/VariableMatrix.h"

namespace Mathematics
{
    template <typename Real, typename UserDataType>
    class OdeImplicitEuler : public OdeSolver<Real, UserDataType>
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = OdeImplicitEuler<Real, UserDataType>;
        using ParentType = OdeSolver<Real, UserDataType>;

        using VariableMatrixType = VariableMatrix<Real>;
        using VariableVectorType = VariableLengthVector<Real>;
        using LinearSystemType = LinearSystem<Real>;

        using Container = typename ParentType::Container;
        using Function = typename ParentType::Function;
        using Data = typename ParentType::Data;

        //  函数F(t,x)具有输入t，一个标量，并输入值x，一个n大小的矢量。
        // 一次导数矩阵相对于x是DF(t,x)，n乘n矩阵。
        // 进入DF[r][c]是F[r]相对于x[c]的派生物。
        // 返回值DF(t,x)
        using DerivativeFunction = VariableMatrixType (*)(Real,  // t
                                                          const Container&,  // x
                                                          const UserDataType*);  // 用户定义数据
    public:
        OdeImplicitEuler(int dimension,
                         Real step,
                         Function function,
                         DerivativeFunction derivativeFunction,
                         const UserDataType* userData);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Data Update(Real tIn, const Container& xIn) override;

    private:
        void Update(const VariableMatrixType& derivative);

    private:
        DerivativeFunction derivativeFunction;
        VariableMatrixType derivativeFunctionMatrix;
        VariableVectorType functionVector;
        VariableMatrixType identity;
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_ODE_IMPLICIT_EULER_H
