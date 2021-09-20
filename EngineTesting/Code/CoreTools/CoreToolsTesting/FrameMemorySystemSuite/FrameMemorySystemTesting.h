// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 18:10)

#ifndef CORE_TOOLS_FRAME_MEMORY_SYSTEM_SUITE_FRAME_MEMORY_SYSTEM_TESTING_H
#define CORE_TOOLS_FRAME_MEMORY_SYSTEM_SUITE_FRAME_MEMORY_SYSTEM_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace CoreTools
{
    class FrameMemorySystemTesting : public UnitTest
    {
    public:
        UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(FrameMemorySystemTesting);

    private:
        void MainTest();
        void SucceedTest() noexcept;
        void ExceptionTest() noexcept;

        void DoRunUnitTest() override;
    };
}

#endif  // CORE_TOOLS_FRAME_MEMORY_SYSTEM_SUITE_FRAME_MEMORY_SYSTEM_TESTING_H