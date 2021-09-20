// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/19 12:49)

#ifndef MATHEMATICS_BASE_SUITE_FLOAT_4_TESTING_H
#define MATHEMATICS_BASE_SUITE_FLOAT_4_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Mathematics
{
	class Float4Testing : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(Float4Testing); 

	private:
		void MainTest();	
		void ConstructorTest();
		void DelayCopyTest();

		virtual void DoRunUnitTest() override;		
	};
}

#endif // MATHEMATICS_BASE_SUITE_FLOAT_4_TESTING_H