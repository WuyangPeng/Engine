// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 10:38)

#ifndef CORE_TOOLS_MEMORY_TOOLS_SUITE_RANDOM_TESTING_H
#define CORE_TOOLS_MEMORY_TOOLS_SUITE_RANDOM_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace CoreTools
{
    class RandomTesting : public UnitTest
    {
    public:
        UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(RandomTesting);

    private:
        void MainTest();
        void RandomTest() noexcept;

        void DoRunUnitTest() override;
    };
}

#endif  // CORE_TOOLS_??CORE_TOOLS_MEMORY_TOOLS_SUITE_RANDOM_TESTING_H