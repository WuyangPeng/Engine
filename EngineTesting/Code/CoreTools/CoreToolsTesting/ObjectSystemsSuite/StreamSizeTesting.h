// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 14:02)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_SUITE_STREAM_SIZE_TESTING_H
#define CORE_TOOLS_OBJECT_SYSTEMS_SUITE_STREAM_SIZE_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace CoreTools
{
	class StreamSizeTesting : public UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(StreamSizeTesting);

	private:
		void MainTest();
		void StreamSizeTest();

		void DoRunUnitTest() override;
	};
}

#endif // CORE_TOOLS_OBJECT_SYSTEMS_SUITE_STREAM_SIZE_TESTING_H