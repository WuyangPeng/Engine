// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.4 (2019/09/10 14:35)

#ifndef ANDROID_CALL_BACK_UNIT_TEST_SUITE_TESTING_ANDROID_CALL_BACK_UNIT_TEST_SUITE_TESTING_ANDROID_CALL_BACK_H
#define ANDROID_CALL_BACK_UNIT_TEST_SUITE_TESTING_ANDROID_CALL_BACK_UNIT_TEST_SUITE_TESTING_ANDROID_CALL_BACK_H

#include "Framework/AndroidFrame/AndroidCallBackUnitTestSuite.h"

namespace AndroidCallBackUnitTestSuiteTesting
{
    class AndroidCallBackUnitTestSuiteTestingAndroidCallBack : public Framework::AndroidCallBackUnitTestSuite
    {
    public:
        using ClassType = AndroidCallBackUnitTestSuiteTestingAndroidCallBack;
        using ParentType = AndroidCallBackUnitTestSuite;

    public:
        explicit AndroidCallBackUnitTestSuiteTestingAndroidCallBack(int64_t delta);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void InitSuite() override;
    };

    using AndroidProcessAndroidCallBackUnitTestSuiteTesting = Framework::AndroidProcess<AndroidCallBackUnitTestSuiteTestingAndroidCallBack>;
}

#endif  // ANDROID_CALL_BACK_UNIT_TEST_SUITE_TESTING_ANDROID_CALL_BACK_UNIT_TEST_SUITE_TESTING_ANDROID_CALL_BACK_H
