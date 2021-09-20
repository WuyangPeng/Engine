// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/28 10:51)

#ifndef MATHEMATICS_QUERY_SUITE_QUERY2_INTEGER_TESTING_H
#define MATHEMATICS_QUERY_SUITE_QUERY2_INTEGER_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Mathematics
{
	class Query2IntegerTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(Query2IntegerTesting); 

	private:
		void MainTest();	
		void VerticesTest();
		void LineTest();
		void TriangleTest();
		void CircumcircleTest();

		virtual void DoRunUnitTest() override; 
	};
}

#endif // MATHEMATICS_QUERY_SUITE_QUERY2_INTEGER_TESTING_H