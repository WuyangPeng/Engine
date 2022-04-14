// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.0.0.3 (2019/09/06 16:39)

#ifndef RENDERING_DETAIL_SUITE_BILLBOARD_NODE_TESTING_H
#define RENDERING_DETAIL_SUITE_BILLBOARD_NODE_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Rendering
{
	class BillboardNodeTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(BillboardNodeTesting); 

	private:
		void MainTest();
	    void InitTest();
	    void CopyTest();
	    void TransformTest();
	    void StreamTest();

		void DoRunUnitTest() override;
	};
}

#endif // RENDERING_DETAIL_SUITE_BILLBOARD_NODE_TESTING_H