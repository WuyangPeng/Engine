// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/20 12:52)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_ODE_MID_POINT_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_ODE_MID_POINT_H

#include "Mathematics/MathematicsDll.h"

#include "OdeSolver.h"

namespace Mathematics
{
	template <typename Real, typename UserDataType>
	class OdeMidpoint : public OdeSolver<Real, UserDataType>
	{
	public:
		using ClassType = OdeMidpoint<Real, UserDataType>;
		using ParentType = OdeSolver<Real, UserDataType>;
		using Function = typename ParentType::Function;
		using RealVector = typename ParentType::RealVector;

	public:
		static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

		OdeMidpoint(int dimension, Real step, Function function, const UserDataType* userData);
		virtual ~OdeMidpoint();

		CLASS_INVARIANT_OVERRIDE_DECLARE;

		 void Update(Real tIn, const RealVector& xIn, Real& tOut, Real* xOut) override;
		 void SetStepSize(Real step) override;

	private:
		Real m_HalfStep;
		RealVector m_SecondXIn;
	};
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_ODE_MID_POINT_H
