// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/08 16:13)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_ODE_IMPLICIT_EULER_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_ODE_IMPLICIT_EULER_H

#include "Mathematics/MathematicsDll.h"

#include "OdeSolver.h"
#include "Mathematics/Algebra/VariableMatrix.h"
#include "Mathematics/Algebra/VariableLengthVector.h"

namespace Mathematics
{
    template <typename Real,typename UserDataType>
    class OdeImplicitEuler : public OdeSolver<Real,UserDataType>
    {
    public:
		static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = OdeImplicitEuler<Real,UserDataType>;
        using ParentType = OdeSolver<Real,UserDataType>;
        using VariableMatrix = VariableMatrix<Real>;
        using  VariableVector = VariableLengthVector<Real>;

		using typename ParentType::RealVector;
		using typename ParentType::Function;
		using ParentType::GetStepSize;
		using ParentType::GetDimension;
		using ParentType::GetUserData;
		using ParentType::GetFunctionValue;
 
        //  ����F(t,x)��������t��һ��������������ֵx��һ��n��С��ʸ����
        // һ�ε������������x��DF(t,x)��n��n����
        // ����DF[r][c]��F[r]�����x[c]�������
		// ����ֵDF(t,x)
        using DerivativeFunction = const VariableMatrix(*)(Real,// t        
		                                                   const RealVector&, // x
														   const UserDataType*); // �û���������        
    public:
        OdeImplicitEuler (int dimension, Real step,typename Function function,
                          DerivativeFunction derivativeFunction,const UserDataType* userData);
        virtual ~OdeImplicitEuler ();
        
        CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		virtual void Update(Real tIn, const RealVector& xIn, Real& tOut, Real* xOut) override;

	private:
		void Update(const VariableMatrix& derivative);

    private:
        DerivativeFunction m_DerivativeFunction;
        VariableMatrix m_DerivativeFunctionMatrix;
        VariableVector m_FunctionVector;
        VariableMatrix m_Identity;
    };   
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_ODE_IMPLICIT_EULER_H
