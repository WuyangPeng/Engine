// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 18:23)

#ifndef CORE_TOOLS_BIT_ARRAY_SUITE_TWO_BIT_ARRAY_TESTING_H
#define CORE_TOOLS_BIT_ARRAY_SUITE_TWO_BIT_ARRAY_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace CoreTools
{
    class TwoBitArrayTesting : public UnitTest
    {
    public:
        UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(TwoBitArrayTesting);

    private:
        void MainTest();
        void ConstBitArrayTest() noexcept;
        void NonConstBitArrayTest() noexcept;

        void DoRunUnitTest() override;
    };
}

#endif  // CORE_TOOLS_BIT_ARRAY_SUITE_TWO_BIT_ARRAY_TESTING_H