// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.4 (2019/09/10 20:16)

#ifndef FRAMEWORK_ANDROID_FRAME_SUITE_ANDROID_CALL_BACK_UNIT_TEST_SUITE_TESTING_H
#define FRAMEWORK_ANDROID_FRAME_SUITE_ANDROID_CALL_BACK_UNIT_TEST_SUITE_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Framework
{
    class AndroidCallBackUnitTestSuiteTesting : public CoreTools::UnitTest
    {
    public:
        UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(AndroidCallBackUnitTestSuiteTesting);

    private:
        void MainTest() noexcept;

        void DoRunUnitTest() final;
    };
}

#endif  // FRAMEWORK_ANDROID_FRAME_SUITE_ANDROID_CALL_BACK_UNIT_TEST_SUITE_TESTING_H