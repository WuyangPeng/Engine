// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.0.0.3 (2019/09/09 10:06)

#ifndef RENDERING_RENDERERS_SUITE_RENDERER_PARAMETER_TESTING_H
#define RENDERING_RENDERERS_SUITE_RENDERER_PARAMETER_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Rendering
{
	class RendererParameterTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(RendererParameterTesting); 

	private:
		void MainTest();
		void AccessTest();
		void ConstructionTest();
	 
		void DoRunUnitTest() override;
	};
}

#endif // RENDERING_RENDERERS_SUITE_RENDERER_PARAMETER_TESTING_H