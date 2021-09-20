// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/19 12:48)

#ifndef MATHEMATICS_BASE_SUITE_BIT_HACKS_TESTING_H
#define MATHEMATICS_BASE_SUITE_BIT_HACKS_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Mathematics
{
	class BitHacksTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(BitHacksTesting); 

	private:
		void MainTest();
		void IsPowerOfTwoTest();
		void Log2OfPowerOfTwoTest();
		void ScaledFloatToIntTest();

		// IsPowerOfTwo≤‚ ‘
		void SignIntIsPowerOfTwoTrueTest();
		void UnsignIntIsPowerOfTwoTrueTest();
		void SignIntIsPowerOfTwoFalseTest();
		void UnsignIntIsPowerOfTwoFalseTest();

		// Log2OfPowerOfTwo≤‚ ‘
		void FixedValueLog2OfPowerOfTwoTest();
		void SignIntLog2OfPowerOfTwoTest();
		void UnsignIntLog2OfPowerOfTwoTest();

		// ScaledFloatToInt≤‚ ‘
		void ScaledFloatToIntMinTest();
		void ScaledFloatToIntMaxTest();
		void ScaledFloatToIntRandomTest();

		virtual void DoRunUnitTest() override; 
	};
}

#endif // MATHEMATICS_BASE_SUITE_BIT_HACKS_TESTING_H