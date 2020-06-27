// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/20 12:53)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_ODE_SOLVER_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_ODE_SOLVER_H

#include "Mathematics/MathematicsDll.h"

#include <type_traits> 
#include <vector>

namespace Mathematics
{
	template <typename Real, typename UserDataType>
	class OdeSolver
	{
	public:
		static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

		using ClassType = OdeSolver<Real, UserDataType>;
		using RealVector = std::vector<Real>;

		// 该系统是dx/dt = F(t,x)。
		// x的维度传递给OdeSolver的构造函数，要和x和F(t,x) 大小一致。
		// 返回值F(t,x) 
		using Function = const RealVector(*)(Real, // t
											 const RealVector&, // x
											 const UserDataType*); // 用户定义数据							

	public:
		OdeSolver(int dimension, Real step, Function function, const UserDataType* userData);
		virtual ~OdeSolver();

		CLASS_INVARIANT_VIRTUAL_DECLARE;

		virtual void Update(Real tIn, const RealVector& xIn, Real& tOut, Real* xOut) = 0;
		virtual void SetStepSize(Real step);
		Real GetStepSize() const;
		void SetUserData(const UserDataType* UserData);
		const UserDataType* GetUserData() const;
		int GetDimension() const;

	protected:
		void CalculateFunctionValue(Real tIn, const RealVector& xIn);

		Real GetStepFunctionValue(int index) const;
		Real GetFunctionValue(int index) const;
		const RealVector GetFunctionValue() const;
		void SetFunctionValue(const RealVector& functionValue);

	private:
		int m_Dimension;
		Function m_Function;
		const UserDataType* m_UserData;
		Real m_Step;
		RealVector m_FunctionValue;
	};
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_ODE_SOLVER_H
