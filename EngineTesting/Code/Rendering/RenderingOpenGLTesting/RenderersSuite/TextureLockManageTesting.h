// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.3 (2019/09/09 15:22)

#ifndef RENDERING_RENDERERS_SUITE_TEXTURE_LOCK_MANAGE_TESTING_H
#define RENDERING_RENDERERS_SUITE_TEXTURE_LOCK_MANAGE_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Rendering
{
	class TextureLockManageTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(TextureLockManageTesting); 

	private:
		void MainTest();	 
		void Texture1DTest();
		void Texture2DTest();
		void Texture3DTest();
		void TextureCubeTest();

		virtual void DoRunUnitTest() override;
	};
}

#endif // RENDERING_RENDERERS_SUITE_TEXTURE_LOCK_MANAGE_TESTING_H