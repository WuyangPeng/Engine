// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.3 (2019/09/09 15:22)

#ifndef RENDERING_RENDERERS_SUITE_PLATFORM_TEXTURE_1D_TESTING_H
#define RENDERING_RENDERERS_SUITE_PLATFORM_TEXTURE_1D_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Rendering
{
	class PlatformTexture1DTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(PlatformTexture1DTesting); 

	private:
		void MainTest();	
		void Texture1DTest();
		 
		virtual void DoRunUnitTest() override;
	};
}

#endif // RENDERING_RENDERERS_SUITE_PLATFORM_TEXTURE_1D_TESTING_H