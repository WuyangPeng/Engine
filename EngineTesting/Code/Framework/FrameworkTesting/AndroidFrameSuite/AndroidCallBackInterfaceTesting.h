///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/08/14 13:55)

#ifndef FRAMEWORK_ANDROID_FRAME_SUITE_ANDROID_CALL_BACK_INTERFACE_TESTING_H
#define FRAMEWORK_ANDROID_FRAME_SUITE_ANDROID_CALL_BACK_INTERFACE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Framework
{
    class AndroidCallBackInterfaceTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = AndroidCallBackInterfaceTesting;
        using ParentType = UnitTest;

    public:
        explicit AndroidCallBackInterfaceTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest() noexcept;
    };
}

#endif  // FRAMEWORK_ANDROID_FRAME_SUITE_ANDROID_CALL_BACK_INTERFACE_TESTING_H