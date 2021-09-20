// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// Copyright (c) 2011-2018
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫1.0.0.0 (2018/01/26 14:05)

#ifndef RENDERING_RESOURCES_SUITE_TEXTURE_3D_TESTING_H
#define RENDERING_RESOURCES_SUITE_TEXTURE_3D_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Rendering
{
	class Texture3DTesting : public CoreTools::UnitTest
	{
	public:
            UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(Texture3DTesting);

 

	private:
		void MainTest();
	    void BaseTest();
		void MipmapsTest();
	    void StreamTest();
		void FileTest();

		virtual void DoRunUnitTest() override;
	};
}

#endif // RENDERING_RESOURCES_SUITE_TEXTURE_3D_TESTING_H