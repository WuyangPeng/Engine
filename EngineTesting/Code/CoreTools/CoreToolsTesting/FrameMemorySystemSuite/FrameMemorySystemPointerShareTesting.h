// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.0.2.3 (2020/03/06 18:02)

#ifndef CORE_TOOLS_FRAME_MEMORY_SYSTEM_SUITE_FRAME_MEMORY_SYSTEM_POINTER_SHARE_TESTING_H
#define CORE_TOOLS_FRAME_MEMORY_SYSTEM_SUITE_FRAME_MEMORY_SYSTEM_POINTER_SHARE_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace CoreTools
{
	class FrameMemorySystemPointerShareTesting : public UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(FrameMemorySystemPointerShareTesting);

	private:
		void MainTest();
            void FrameMemorySystemPointerTest() noexcept;

		void DoRunUnitTest() override;
	};
}

#endif // CORE_TOOLS_FRAME_MEMORY_SYSTEM_SUITE_FRAME_MEMORY_SYSTEM_POINTER_SHARE_TESTING_H