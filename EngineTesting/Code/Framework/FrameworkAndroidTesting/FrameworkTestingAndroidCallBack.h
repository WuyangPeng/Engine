// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.4 (2019/09/10 20:06)

#ifndef FRAMEWORK_TESTING_FRAMEWORK_TESTING_WINDOW_MESSAGE_H
#define FRAMEWORK_TESTING_FRAMEWORK_TESTING_WINDOW_MESSAGE_H

#include "Framework/AndroidFrame/AndroidCallBackUnitTestSuite.h"

namespace Framework
{
    class FrameworkTestingAndroidCallBack : public AndroidCallBackUnitTestSuite
    {
    public:
        using ClassType = FrameworkTestingAndroidCallBack;
        using ParentType = AndroidCallBackUnitTestSuite;

    public:
        explicit FrameworkTestingAndroidCallBack(int64_t delta);
        virtual ~FrameworkTestingAndroidCallBack();

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void InitSuite() override;
        void AddAndroidFrameSuite();
    };

    using AndroidProcessFrameworkTesting = AndroidProcess<FrameworkTestingAndroidCallBack>;
}

#endif  // FRAMEWORK_TESTING_FRAMEWORK_TESTING_WINDOW_MESSAGE_H
