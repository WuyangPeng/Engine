// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/22 15:32)

#ifndef MATHEMATICS_OBJECTS3D_SUITE_ELLIPSOID3_TESTING_H
#define MATHEMATICS_OBJECTS3D_SUITE_ELLIPSOID3_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Mathematics
{
	class Ellipsoid3Testing : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(Ellipsoid3Testing); 

	private:
		void MainTest();
		void ConstructionTest();
		void CalculateTest();
	
		virtual void DoRunUnitTest() override;
	};
}

#endif // MATHEMATICS_OBJECTS3D_SUITE_ELLIPSOID3_TESTING_H