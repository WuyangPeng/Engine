// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/20 12:51)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_ODE_IMPLICIT_EULER_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_ODE_IMPLICIT_EULER_H

#include "Mathematics/MathematicsDll.h"

#include "OdeSolver.h"
#include "Mathematics/Algebra/VariableMatrix.h"
#include "Mathematics/Algebra/VariableLengthVector.h"

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

		using RealVector = typename ParentType::RealVector;
		using Function = typename ParentType::Function;

		//  函数F(t,x)具有输入t，一个标量，并输入值x，一个n大小的矢量。
		// 一次导数矩阵相对于x是DF(t,x)，n乘n矩阵。
		// 进入DF[r][c]是F[r]相对于x[c]的派生物。
		// 返回值DF(t,x)
		using DerivativeFunction = const VariableMatrix(*)(Real,// t        
														   const RealVector&, // x
														   const UserDataType*); // 用户定义数据        
	public:
		OdeImplicitEuler(int dimension, Real step, typename Function function,
						 DerivativeFunction derivativeFunction, const UserDataType* userData);
		virtual ~OdeImplicitEuler();

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
