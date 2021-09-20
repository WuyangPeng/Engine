// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.3 (2019/09/06 15:11)

#ifndef RENDERING_SHADER_FLOATS_SUITE_MATERIAL_AMBIENT_CONSTANT_TESTING_H
#define RENDERING_SHADER_FLOATS_SUITE_MATERIAL_AMBIENT_CONSTANT_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Rendering
{
	class MaterialAmbientConstantTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(MaterialAmbientConstantTesting); 

	private:
		void MainTest();
	    void InitTest();
	    void CopyTest();	  
	    void StreamTest();
		void UpdateTest();

		virtual void DoRunUnitTest() override; 
	};
}

#endif // RENDERING_SHADER_FLOATS_SUITE_MATERIAL_AMBIENT_CONSTANT_TESTING_H