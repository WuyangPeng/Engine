// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 10:36)

#ifndef CORE_TOOLS_MEMORY_TOOLS_SUITE_BUFFER_POOL_TESTING_H
#define CORE_TOOLS_MEMORY_TOOLS_SUITE_BUFFER_POOL_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace CoreTools
{
    class BufferPoolTesting : public UnitTest
    {
    public:
        UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(BufferPoolTesting);

    private:
        void MainTest();
        void PoolTest() noexcept;

        void DoRunUnitTest() override;
    };
}

#endif  // CORE_TOOLS_MEMORY_TOOLS_SUITE_BUFFER_POOL_TESTING_H