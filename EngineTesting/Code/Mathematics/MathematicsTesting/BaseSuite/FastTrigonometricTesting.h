// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/19 12:48)

#ifndef MATHEMATICS_BASE_SUITE_FAST_TRIGONOMETRIC_TESTING_H
#define MATHEMATICS_BASE_SUITE_FAST_TRIGONOMETRIC_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Mathematics
{
	class FastTrigonometricTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(FastTrigonometricTesting); 

	private:
		void MainTest();	

		void FastSinTest();		
		void FloatFastSinTest();
		void DoubleFastSinTest();		

		void FastCosTest();
		void FloatFastCosTest();
		void DoubleFastCosTest();		

		void FastTanTest();
		void FloatFastTanTest();
		void DoubleFastTanTest();		

		void FastInvSinTest();
		void FloatFastInvSinTest();
		void DoubleFastInvSinTest();		

		void FastInvCosTest();
		void FloatFastInvCosTest();
		void DoubleFastInvCosTest();		

		void FastInvTanTest();	
		void FloatFastInvTanTest();
		void DoubleFastInvTanTest();		

		virtual void DoRunUnitTest() override; 
	};
}

#endif // MATHEMATICS_BASE_SUITE_FAST_TRIGONOMETRIC_TESTING_H