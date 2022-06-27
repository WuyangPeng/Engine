///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.9 (2022/06/24 10:19)

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
