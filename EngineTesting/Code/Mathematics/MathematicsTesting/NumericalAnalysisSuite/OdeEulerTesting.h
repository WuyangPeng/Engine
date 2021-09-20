// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/27 13:54)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_ODE_EULER_TESTING_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_ODE_EULER_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

#include <vector>

namespace Mathematics
{
	class OdeEulerTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(OdeEulerTesting); 

		int GetDimension() const;

	private:
		void MainTest();  
		void SolverTest();
		
		virtual void DoRunUnitTest() override;	

		static const std::vector<double> OdeEulerFunction(double tIn, const std::vector<double>& xIn,const OdeEulerTesting* odeEulerTesting);

	private:
		int m_Dimension; 
	};
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_ODE_EULER_TESTING_H