// Threading Core Render Engine
// ���ߣ������������ʶ���������
// Copyright (c) 2011-2018
//
// ������԰汾��1.0.0.0 (2018/01/26 14:08)

#ifndef RENDERING_RESOURCES_SUITE_VERTEX_FORMAT_TESTING_H
#define RENDERING_RESOURCES_SUITE_VERTEX_FORMAT_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Rendering
{
	class VertexFormatTesting : public CoreTools::UnitTest
	{
	public:
            UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(VertexFormatTesting);

 

	private:
		void MainTest();
		void BaseTest();	
		void StreamTest();		

		void DoRunUnitTest() override;
	};
}

#endif // RENDERING_RESOURCES_SUITE_VERTEX_FORMAT_TESTING_H