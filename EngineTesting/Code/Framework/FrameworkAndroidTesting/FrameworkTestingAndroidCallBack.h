///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/08/11 14:17)

#ifndef FRAMEWORK_TESTING_FRAMEWORK_TESTING_WINDOW_MESSAGE_H
#define FRAMEWORK_TESTING_FRAMEWORK_TESTING_WINDOW_MESSAGE_H

#include "Framework/AndroidFrame/AndroidCallBackUnitTestSuite.h"

namespace Framework
{
    class FrameworkTestingAndroidCallBack final : public AndroidCallBackUnitTestSuite
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
