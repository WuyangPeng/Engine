// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.3 (2019/09/09 15:36)

#ifndef RENDERING_RENDERING_OPENGL_RENDERER_SUITE_OPENGL_TEXTURE_DATA_MANAGE_TESTING_H
#define RENDERING_RENDERING_OPENGL_RENDERER_SUITE_OPENGL_TEXTURE_DATA_MANAGE_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Rendering
{
	class OpenGLTextureDataManageTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(OpenGLTextureDataManageTesting); 

	private:
		void MainTest();	 
		void Texture1DTest();
		void Texture2DTest();
		void Texture3DTest();
		void TextureCubeTest();
	 
		virtual void DoRunUnitTest() override;
	};
}

#endif // RENDERING_RENDERING_OPENGL_RENDERER_SUITE_OPENGL_TEXTURE_DATA_MANAGE_TESTING_H