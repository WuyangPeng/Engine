// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/05 11:54)

#ifndef CORE_TOOLS_THREADING_SUITE_THREAD_TESTING_H
#define CORE_TOOLS_THREADING_SUITE_THREAD_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace CoreTools
{
    class ThreadTesting : public UnitTest
    {
    public:
        UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(ThreadTesting);

    private:
        static uint32_t Thread1(void* threadParameter) noexcept;
        static uint32_t Thread2(void* threadParameter) noexcept;

        void MainTest();

        void CreateThread();

        void DoRunUnitTest() override;
    };
}

#endif  // CORE_TOOLS_THREADING_SUITE_THREAD_TESTING_H