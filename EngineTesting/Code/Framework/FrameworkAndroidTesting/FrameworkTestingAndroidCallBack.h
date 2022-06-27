///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.9 (2022/06/24 10:19)

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

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void InitSuite() override;
        void AddAndroidFrameSuite();
    };

    using AndroidProcessFrameworkTesting = AndroidProcess<FrameworkTestingAndroidCallBack>;
}

#endif  // FRAMEWORK_TESTING_FRAMEWORK_TESTING_WINDOW_MESSAGE_H
