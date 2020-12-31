///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.4 (2020/11/27 10:45)

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
        using VariableMatrix = VariableMatrix<Real>;
        using VariableVector = VariableLengthVector<Real>;
        using LinearSystem = LinearSystem<Real>;

        using Container = typename ParentType::Container;
        using Function = typename ParentType::Function;
        using Data = ParentType::Data;

        //  ����F(t,x)��������t��һ��������������ֵx��һ��n��С��ʸ����
        // һ�ε������������x��DF(t,x)��n��n����
        // ����DF[r][c]��F[r]�����x[c]�������
        // ����ֵDF(t,x)
        using DerivativeFunction = const VariableMatrix (*)(Real,  // t
                                                            const Container&,  // x
                                                            const UserDataType*);  // �û���������
    public:
        OdeImplicitEuler(int dimension, Real step, typename Function function,
                         DerivativeFunction derivativeFunction, const UserDataType* userData);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        Data Update(Real tIn, const Container& xIn) override;

    private:
        void Update(const VariableMatrix& derivative);

    private:
        DerivativeFunction m_DerivativeFunction;
        VariableMatrix m_DerivativeFunctionMatrix;
        VariableVector m_FunctionVector;
        VariableMatrix m_Identity;
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_ODE_IMPLICIT_EULER_H
