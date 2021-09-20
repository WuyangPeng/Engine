// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// Copyright (c) 2011-2018
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫1.0.0.0 (2018/01/26 14:05)

#ifndef RENDERING_RESOURCES_SUITE_BUFFER_TESTING_H
#define RENDERING_RESOURCES_SUITE_BUFFER_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Rendering
{
	class BufferTesting : public CoreTools::UnitTest
	{
	public:
            UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(BufferTesting);

 

	private:
		void MainTest();
	    void VertexBufferTest();
	    void IndexBufferTest();	    
	    void StreamTest();
		void FileTest();

		virtual void DoRunUnitTest() override;
	};
}

#endif // RENDERING_RESOURCES_SUITE_BUFFER_TESTING_H