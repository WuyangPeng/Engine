// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/19 17:15)

#ifndef MATHEMATICS_ALGEBRA_SUITE_VECTOR_3D_TOOLS_TESTING_H
#define MATHEMATICS_ALGEBRA_SUITE_VECTOR_3D_TOOLS_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Mathematics
{
	class Vector3DToolsTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(Vector3DToolsTesting); 

	private:
		void MainTest();	
		void DistanceTest();
		void ProductTest();
		void ProjectionTest();
		void ConversionTest();
		void CompareTest();
		void OtherCalculateTest();	

		virtual void DoRunUnitTest() override;

		static double Half(double value); 
	};
}

#endif // MATHEMATICS_ALGEBRA_SUITE_VECTOR_3D_TOOLS_TESTING_H