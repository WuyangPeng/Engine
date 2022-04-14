// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.3 (2019/09/03 13:26)

#ifndef RENDERING_DATA_TYPES_SUITE_TEXTURE_COLOUR_TESTING_H
#define RENDERING_DATA_TYPES_SUITE_TEXTURE_COLOUR_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Rendering
{
	class TextureColourTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(TextureColourTesting); 

	private:
		void MainTest();
	    void R5G6B5Test();
		void A1R5G5B5Test();
		void A4R4G4B4Test();
		void A8Test();
		void L8Test();
		void A8L8Test();
		void R8G8B8Test();
		void A8R8G8B8Test();
		void A8B8G8R8Test();
		void L16Test();
		void G16R16Test();
		void A16B16G16R16Test();
		void R16FTest();
		void G16R16FTest();
		void A16B16G16R16FTest();
		void R32FTest();
		void G32R32FTest();
		void A32B32G32R32FTest(); 
		void ConvertingTest();
		void OperatorTest();
	
		void DoRunUnitTest() override;
	};
}

#endif // RENDERING_DATA_TYPES_SUITE_TEXTURE_COLOUR_TESTING_H