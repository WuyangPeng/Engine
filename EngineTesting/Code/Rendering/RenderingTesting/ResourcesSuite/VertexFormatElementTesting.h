// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// Copyright (c) 2011-2018
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫1.0.0.0 (2018/01/26 14:07)

#ifndef RENDERING_RESOURCES_SUITE_VERTEX_FORMAT_ELEMENT_TESTING_H
#define RENDERING_RESOURCES_SUITE_VERTEX_FORMAT_ELEMENT_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Rendering
{
	class VertexFormatElementTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(VertexFormatElementTesting);

 

	private:
		void MainTest();
		void BaseTest();	
		
		void DoRunUnitTest() override;
	};
}

#endif // RENDERING_RESOURCES_SUITE_VERTEX_FORMAT_ELEMENT_TESTING_H