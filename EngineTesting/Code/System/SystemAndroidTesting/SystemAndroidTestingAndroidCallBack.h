///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/08/31 13:44)

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
        void InitSuite() override;
        void AddAndroidSuite();
    };

    using SystemAndroidTestingAndroidProcess = Framework::AndroidProcess<SystemAndroidTestingAndroidCallBack>;
}

#endif  // SYSTEM_ANDROID_TESTING_ANDROID_CALL_BACK_H
