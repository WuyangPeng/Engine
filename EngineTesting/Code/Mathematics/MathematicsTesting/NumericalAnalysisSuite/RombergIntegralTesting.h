// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.0.0.2 (2019/08/27 13:55)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_ROMBERG_INTEGRAL_TESTING_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_ROMBERG_INTEGRAL_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Mathematics
{
	class RombergIntegralTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(RombergIntegralTesting); 

	private:
		void MainTest();  
		void ValueTest();		 
		
		virtual void DoRunUnitTest() override;	

		static double Solution(double input, const RombergIntegralTesting* userData);
		double  GetUserData() const;
	};
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_ROMBERG_INTEGRAL_TESTING_H