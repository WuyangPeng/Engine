// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.3 (2019/09/09 11:31)

#ifndef RENDERING_RENDERING_OPENGL_RENDERER_SUITE_OPENGL_VERTEX_FORMAT_DATA_TESTING_H
#define RENDERING_RENDERING_OPENGL_RENDERER_SUITE_OPENGL_VERTEX_FORMAT_DATA_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Rendering
{
	class OpenGLVertexFormatDataTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(OpenGLVertexFormatDataTesting); 

	private:
		void MainTest();	 
	 
		void DoRunUnitTest() override;
	};
}

#endif // RENDERING_RENDERING_OPENGL_RENDERER_SUITE_OPENGL_VERTEX_FORMAT_DATA_TESTING_H