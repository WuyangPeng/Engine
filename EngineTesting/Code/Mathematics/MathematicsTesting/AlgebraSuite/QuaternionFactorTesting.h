// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/19 17:08)

#ifndef MATHEMATICS_ALGEBRA_SUITE_QUATERNION_FACTOR_TESTING_H
#define MATHEMATICS_ALGEBRA_SUITE_QUATERNION_FACTOR_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Mathematics
{
	class QuaternionFactorTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(QuaternionFactorTesting); 

	private:
		void MainTest();
		void FactorXYZTest();
		void FactorXZYTest();
		void FactorYZXTest();
		void FactorYXZTest();
		void FactorZXYTest();
		void FactorZYXTest();
		
		void DoRunUnitTest() override;	 
	};
}

#endif // MATHEMATICS_ALGEBRA_SUITE_QUATERNION_FACTOR_TESTING_H