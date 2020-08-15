// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/20 12:51)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_ODE_EULER_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_ODE_EULER_H

#include "Mathematics/MathematicsDll.h"

#include "OdeSolver.h"

namespace Mathematics
{
	template <typename Real, typename UserDataType>
	class OdeEuler : public OdeSolver<Real, UserDataType>
	{
	public:
		static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

		using ClassType = OdeEuler<Real, UserDataType>;
		using ParentType = OdeSolver<Real, UserDataType>;
		using Function = typename ParentType::Function;
		using RealVector = typename ParentType::RealVector; 

	public:
		OdeEuler(int dimension, Real step, typename Function function, const UserDataType* userData);
		virtual ~OdeEuler();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		 void Update(Real tIn, const RealVector& xIn, Real& tOut, Real* xOut) override;
	};
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_ODE_EULER_H
