// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/28 10:51)

#ifndef MATHEMATICS_QUERY_SUITE_QUERY3_INT64_TESTING_H
#define MATHEMATICS_QUERY_SUITE_QUERY3_INT64_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Mathematics
{
	class Query3Int64Testing : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(Query3Int64Testing); 

	private:
		void MainTest();	
		void VerticesTest();
		void PlaneTest();
		void TetrahedronTest();
		void CircumspherTest();
		
		virtual void DoRunUnitTest() override; 
	};
}

#endif // MATHEMATICS_QUERY_SUITE_QUERY3_INT64_TESTING_H