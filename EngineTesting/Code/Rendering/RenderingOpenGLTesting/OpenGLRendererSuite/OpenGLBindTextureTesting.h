// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.3 (2019/09/09 15:35)

#ifndef RENDERING_RENDERING_OPENGL_RENDERER_SUITE_OPENGL_BIND_TEXTURE_TESTING_H
#define RENDERING_RENDERING_OPENGL_RENDERER_SUITE_OPENGL_BIND_TEXTURE_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Rendering
{
	class OpenGLBindTextureTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(OpenGLBindTextureTesting); 

	private:
		void MainTest();	
		void TextureTest();
	 
		virtual void DoRunUnitTest() override;
	};
}

#endif // RENDERING_RENDERING_OPENGL_RENDERER_SUITE_OPENGL_BIND_TEXTURE_TESTING_H