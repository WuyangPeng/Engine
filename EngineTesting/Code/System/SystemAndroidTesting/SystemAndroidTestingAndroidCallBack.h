///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.4 (2022/11/05 22:50)

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

    using SystemAndroidTestingAndroidProcess = Framework::AndroidProcess<SystemAndroidTestingAndroidCallBack>;
}

#endif  // SYSTEM_ANDROID_TESTING_ANDROID_CALL_BACK_H
