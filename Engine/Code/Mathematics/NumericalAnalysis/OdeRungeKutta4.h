// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/20 12:52)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_ODE_RUNGE_KUTTA4_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_ODE_RUNGE_KUTTA4_H

#include "Mathematics/MathematicsDll.h"

#include "OdeSolver.h"

namespace Mathematics
{
	template <typename Real, typename UserDataType>
	class OdeRungeKutta4 : public OdeSolver<Real, UserDataType>
	{
	public:
		static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

		using ClassType = OdeRungeKutta4<Real, UserDataType>;
		using ParentType = OdeSolver<Real, UserDataType>;
		using Function = typename ParentType::Function;
		using RealVector = typename ParentType::RealVector;

	public:
		OdeRungeKutta4(int dimension, Real step, Function function, const UserDataType* userData);
		virtual ~OdeRungeKutta4();

		CLASS_INVARIANT_OVERRIDE_DECLARE;

		virtual void Update(Real tIn, const RealVector& xIn, Real& tOut, Real* xOut);
		virtual void SetStepSize(Real step);

	private:
		Real m_HalfStep;
		Real m_SixthStep;
		RealVector m_FirstStepFunctionValue;
		RealVector m_SecondStepFunctionValue;
		RealVector m_ThirdStepFunctionValue;
		RealVector m_FourthStepFunctionValue;
		RealVector m_SecondXIn;
	};
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_ODE_RUNGE_KUTTA4_H
