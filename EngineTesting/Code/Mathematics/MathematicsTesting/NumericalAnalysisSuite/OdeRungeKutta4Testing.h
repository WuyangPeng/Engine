// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/27 13:54)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_ODE_RUNGE_KUTTA4_TESTING_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_ODE_RUNGE_KUTTA4_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

#include <vector>

namespace Mathematics
{
	class OdeRungeKutta4Testing : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(OdeRungeKutta4Testing); 

	int GetDimension() const;

	private:
		void MainTest();  
		void SolverTest();
		
		virtual void DoRunUnitTest() override;	

		static const std::vector<double> OdeRungeKutta4Function(double tIn, const std::vector<double>& xIn,const OdeRungeKutta4Testing* odeEulerTesting);

	private:
		int m_Dimension; 		
	};
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_ODE_RUNGE_KUTTA4_TESTING_H