// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/27 13:55)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_ODE_SOLVER_TEST_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_ODE_SOLVER_TEST_H

#include "Mathematics/NumericalAnalysis/OdeSolver.h"

namespace Mathematics
{
	class OdeSolverTesting;

	class OdeSolverTest : public  OdeSolver<double, OdeSolverTesting>
	{
	public:
		using ClassType = OdeSolverTest ;
		using ParentType = OdeSolver<double, OdeSolverTesting> ;
		 using RealVector = ParentType::Container;
	public:
		OdeSolverTest(int dimension, double step,Function function, const OdeSolverTesting* userData);
		virtual ~OdeSolverTest();

 
		CLASS_INVARIANT_OVERRIDE_DECLARE; 

		static const RealVector OdeSolverTestFunction(double tIn, const RealVector& xIn,const OdeSolverTesting* odeSolverTest);
 
		virtual void Update(double tIn, const RealVector& xIn,double& tOut, double* xOut);		
	};
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_ODE_SOLVER_TEST_H