// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.3 (2019/09/07 14:22)

#ifndef RENDERING_SHADERS_SUITE_LOAD_VISUAL_EFFECT_TESTING_H
#define RENDERING_SHADERS_SUITE_LOAD_VISUAL_EFFECT_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Rendering
{
	class LoadVisualEffectTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(LoadVisualEffectTesting); 

	private:
		void MainTest();
	    void CreateVisualEffectFile(); 
		void VertexShaderTest(); 
		void PixelShaderTest();
		void AlphaStateTest();
		void CullStateTest();
		void DepthStateTest();
		void OffsetStateTest();
		void StencilStateTest();
		void WireStateTest();

		void DoRunUnitTest() override;
	};
}

#endif // RENDERING_SHADERS_SUITE_LOAD_VISUAL_EFFECT_TESTING_H