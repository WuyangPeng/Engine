// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.4 (2020/03/12 10:02)

#ifndef NETWORK_TESTING_HELPER_SUITE_STREAM_MACRO_TESTING_H
#define NETWORK_TESTING_HELPER_SUITE_STREAM_MACRO_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Network
{
    class StreamMacroTesting : public CoreTools::UnitTest
    {
    public:
        UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(StreamMacroTesting);

    private:
        void MainTest();

        void TestMessageTest() noexcept;

        void DoRunUnitTest() override;
    };
}

#endif  // NETWORK_TESTING_HELPER_SUITE_STREAM_MACRO_TESTING_H