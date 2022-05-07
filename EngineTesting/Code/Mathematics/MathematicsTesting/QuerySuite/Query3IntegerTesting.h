// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.0.0.2 (2019/08/28 10:51)

#ifndef MATHEMATICS_QUERY_SUITE_QUERY3_INTEGER_TESTING_H
#define MATHEMATICS_QUERY_SUITE_QUERY3_INTEGER_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Mathematics
{
	class Query3IntegerTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(Query3IntegerTesting); 

	private:
		void MainTest();	
		void VerticesTest();
		void PlaneTest();
		void TetrahedronTest();
		void CircumspherTest();
	
		void DoRunUnitTest() override; 
	};
}

#endif // MATHEMATICS_QUERY_SUITE_QUERY3_INTEGER_TESTING_H