// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/28 10:50)

#ifndef MATHEMATICS_QUERY_SUITE_QUERY2_FILTERED_TESTING_H
#define MATHEMATICS_QUERY_SUITE_QUERY2_FILTERED_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Mathematics
{
	class Query2FilteredTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(Query2FilteredTesting); 

	private:
		void MainTest();	
		void VerticesTest();
		void LineTest();
		void TriangleTest();
		void CircumcircleTest();

		virtual void DoRunUnitTest() override; 
	};
}

#endif // MATHEMATICS_QUERY_SUITE_QUERY2_FILTERED_TESTING_H