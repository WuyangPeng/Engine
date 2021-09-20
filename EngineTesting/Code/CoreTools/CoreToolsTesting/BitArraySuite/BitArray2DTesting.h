// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 18:23)

#ifndef CORE_TOOLS_BIT_ARRAY_SUITE_BIT_ARRAY_2D_TESTING_H
#define CORE_TOOLS_BIT_ARRAY_SUITE_BIT_ARRAY_2D_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace CoreTools
{
    class BitArray2DTesting : public UnitTest
    {
    public:
        UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(BitArray2DTesting);

    private:
        void MainTest();
        void ConstBitArray2DTest() noexcept;
        void NonConstBitArray2DTest() noexcept;

        void DoRunUnitTest() override;
    };
}

#endif  // CORE_TOOLS_BIT_ARRAY_SUITE_BIT_ARRAY_2D_TESTING_H