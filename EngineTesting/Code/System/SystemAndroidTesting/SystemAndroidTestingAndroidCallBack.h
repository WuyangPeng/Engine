///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.2.1 (2021/07/30 23:46)

#ifndef SYSTEM_ANDROID_TESTING_ANDROID_CALL_BACK_H
#define SYSTEM_ANDROID_TESTING_ANDROID_CALL_BACK_H

#include "Framework/AndroidFrame/AndroidCallBackUnitTestSuite.h"

namespace System
{
    class SystemAndroidTestingAndroidCallBack final : public Framework::AndroidCallBackUnitTestSuite
    {
    public:
        using ClassType = SystemAndroidTestingAndroidCallBack;
        using ParentType = AndroidCallBackUnitTestSuite;

    public:
        explicit SystemAndroidTestingAndroidCallBack(int64_t delta);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void InitSuite() final;
        void AddAndroidSuite();
    };

    using AndroidProcessSystemAndroidTesting = Framework::AndroidProcess<SystemAndroidTestingAndroidCallBack>;
}

#endif  // SYSTEM_ANDROID_TESTING_ANDROID_CALL_BACK_H
