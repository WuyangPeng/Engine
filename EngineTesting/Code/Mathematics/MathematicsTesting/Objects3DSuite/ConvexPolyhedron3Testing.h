// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.0.0.2 (2019/08/22 15:32)

#ifndef MATHEMATICS_OBJECTS3D_SUITE_CONVEX_POLYHEDRON3_TESTING_H
#define MATHEMATICS_OBJECTS3D_SUITE_CONVEX_POLYHEDRON3_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Mathematics
{
	class ConvexPolyhedron3Testing : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(ConvexPolyhedron3Testing); 

	private:
		void MainTest();
		void ConvexPolyhedronTest();
	
		void DoRunUnitTest() override;	 
	};
}

#endif // MATHEMATICS_OBJECTS3D_SUITE_CONVEX_POLYHEDRON3_TESTING_H