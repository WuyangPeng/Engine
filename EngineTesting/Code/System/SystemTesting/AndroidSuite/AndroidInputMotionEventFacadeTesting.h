///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/08/31 15:44)

#ifndef SYSTEM_ANDROID_SUITE_ANDROID_INPUT_MOTION_EVENT_FACADE_TESTING_H
#define SYSTEM_ANDROID_SUITE_ANDROID_INPUT_MOTION_EVENT_FACADE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class AndroidInputMotionEventFacadeTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = AndroidInputMotionEventFacadeTesting;
        using ParentType = UnitTest;

    public:
        explicit AndroidInputMotionEventFacadeTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest() noexcept;
    };
}

#endif  // SYSTEM_ANDROID_SUITE_ANDROID_INPUT_MOTION_EVENT_FACADE_TESTING_H