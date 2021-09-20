// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/19 17:06)

#ifndef MATHEMATICS_ALGEBRA_SUITE_MATRIX3_EULER_TESTING_H
#define MATHEMATICS_ALGEBRA_SUITE_MATRIX3_EULER_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Mathematics
{
	class EulerTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(EulerTesting); 

	private:
		void MainTest();
		void EulerXYZTest();
		void EulerXZYTest();
		void EulerYXZTest();
		void EulerYZXTest();
		void EulerZXYTest();
		void EulerZYXTest();
		void EulerXYXTest();
		void EulerXZXTest();
		void EulerYXYTest();
		void EulerYZYTest();
		void EulerZXZTest();
		void EulerZYZTest();

		virtual void DoRunUnitTest() override; 
	};
}

#endif // MATHEMATICS_ALGEBRA_SUITE_MATRIX3_EULER_TESTING_H