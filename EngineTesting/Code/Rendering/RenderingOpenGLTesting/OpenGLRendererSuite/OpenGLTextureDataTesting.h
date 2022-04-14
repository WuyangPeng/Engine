// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.0.0.3 (2019/09/09 15:36)

#ifndef RENDERING_RENDERING_OPENGL_RENDERER_SUITE_OPENGL_TEXTURE_DATA_TESTING_H
#define RENDERING_RENDERING_OPENGL_RENDERER_SUITE_OPENGL_TEXTURE_DATA_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Rendering
{
	class OpenGLTextureDataTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(OpenGLTextureDataTesting); 

	private:
		void MainTest();	 
		void Texture1DTest();
		void Texture2DTest();
		void Texture3DTest();
		void TextureCubeTest();

		void DoRunUnitTest() override;
	};
}

#endif // RENDERING_RENDERING_OPENGL_RENDERER_SUITE_OPENGL_BIND_TEXTURE_TESTING_H