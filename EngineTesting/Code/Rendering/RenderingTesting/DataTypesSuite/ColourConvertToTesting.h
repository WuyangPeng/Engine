// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.3 (2019/09/03 13:26)

#ifndef RENDERING_DATA_TYPES_SUITE_COLOUR_CONVERT_TO_TESTING_H
#define RENDERING_DATA_TYPES_SUITE_COLOUR_CONVERT_TO_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Rendering
{
	class ColourConvertToTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(ColourConvertToTesting); 

	private:
		void MainTest();
	    void R5G6B5ConvertTest();
		void A1R5G5B5ConvertTest();
		void A4R4G4B4ConvertTest();
		void A8ConvertTest();
		void L8ConvertTest();
		void A8L8ConvertTest();
		void R8G8B8ConvertTest();
		void A8R8G8B8ConvertTest();
		void A8B8G8R8ConvertTest();
		void L16ConvertTest();
		void G16R16ConvertTest();
		void A16B16G16R16ConvertTest();
		void R16FConvertTest();
		void G16R16FConvertTest();
		void A16B16G16R16FConvertTest();
		void R32FConvertTest();
		void G32R32FConvertTest();
		void A32B32G32R32FConvertTest();

		virtual void DoRunUnitTest() override; 
	};
}

#endif // RENDERING_DATA_TYPES_SUITE_COLOUR_CONVERT_TO_TESTING_H