// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/28 10:51)

#ifndef MATHEMATICS_QUERY_SUITE_QUERY_SORT_TOOLS_TESTING_H
#define MATHEMATICS_QUERY_SUITE_QUERY_SORT_TOOLS_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Mathematics
{
	class QuerySortToolsTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(QuerySortToolsTesting); 

	private:
		void MainTest();	
		void SortTwoValueTest();
		void SortThreeValueTest();
		void SortFourValueTest();

		virtual void DoRunUnitTest() override; 
	};
}

#endif // MATHEMATICS_QUERY_SUITE_QUERY_SORT_TOOLS_TESTING_H