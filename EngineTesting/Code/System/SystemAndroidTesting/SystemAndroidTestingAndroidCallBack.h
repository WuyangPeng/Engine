///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.2.1 (2021/07/30 23:46)

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
