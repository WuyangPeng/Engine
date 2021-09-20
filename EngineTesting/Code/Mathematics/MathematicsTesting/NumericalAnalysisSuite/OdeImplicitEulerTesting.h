// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/27 13:54)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_ODE_IMPLICIT_EULER_TESTING_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_ODE_IMPLICIT_EULER_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "Mathematics/Algebra/VariableMatrix.h"

#include <vector>

namespace Mathematics
{
	class OdeImplicitEulerTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(OdeImplicitEulerTesting); 

		int GetDimension() const;

	private:
		void MainTest();  
		void SolverTest();
		
		virtual void DoRunUnitTest() override;	

		static const std::vector<double> OdeImplicitEulerFunction(double tIn, const std::vector<double>& xIn,const OdeImplicitEulerTesting* odeEulerTesting);

		static const DoubleVariableMatrix OdeImplicitEulerDerivativeFunction(double tIn, const std::vector<double>& xIn,const OdeImplicitEulerTesting* odeEulerTesting);

	private:
		int m_Dimension; 	
	};
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_ODE_IMPLICIT_EULER_TESTING_H