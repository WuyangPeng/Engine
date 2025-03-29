/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/12 13:44)

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

        //  ����F(t,x)��������t��һ��������������ֵx��һ��n��С��ʸ����
        // һ�ε������������x��DF(t,x)��n��n����
        // ����DF[r][c]��F[r]�����x[c]�������
        // ����ֵDF(t,x)
        using DerivativeFunction = VariableMatrixType (*)(Real,  // t
                                                          const Container&,  // x
                                                          const UserDataType*);  // �û���������
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
