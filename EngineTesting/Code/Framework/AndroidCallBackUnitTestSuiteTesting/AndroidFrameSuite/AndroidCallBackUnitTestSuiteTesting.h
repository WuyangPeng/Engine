// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.4 (2019/09/10 14:34)

#ifndef ANDROID_CALL_BACK_UNIT_TEST_SUITE_TESTING_ANDROID_CALL_BACK_UNIT_TEST_SUITE_H
#define ANDROID_CALL_BACK_UNIT_TEST_SUITE_TESTING_ANDROID_CALL_BACK_UNIT_TEST_SUITE_H

#include "System/Windows/Flags/WindowsFlags.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace AndroidCallBackUnitTestSuiteTesting
{
    class AndroidCallBackUnitTestSuiteTestingAndroidCallBack;

    class AndroidCallBackUnitTestSuiteTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = AndroidCallBackUnitTestSuiteTesting;
        using ParentType = UnitTest;

    public:
        explicit AndroidCallBackUnitTestSuiteTesting(const CoreTools::OStreamShared& osPtr, AndroidCallBackUnitTestSuiteTestingAndroidCallBack* message);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void KeyDownMessageTest();
        void CreateMessageTest();
        void DisplayTest();

        void DoRunUnitTest() final;

    private:
        AndroidCallBackUnitTestSuiteTestingAndroidCallBack* m_Message;
    };
}

#endif  // ANDROID_CALL_BACK_UNIT_TEST_SUITE_TESTING_ANDROID_CALL_BACK_UNIT_TEST_SUITE_H
