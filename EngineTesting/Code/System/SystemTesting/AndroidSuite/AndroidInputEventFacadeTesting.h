///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.4 (2022/11/05 22:54)

#ifndef SYSTEM_ANDROID_SUITE_ANDROID_INPUT_EVENT_FACADE_TESTING_H
#define SYSTEM_ANDROID_SUITE_ANDROID_INPUT_EVENT_FACADE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class AndroidInputEventFacadeTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = AndroidInputEventFacadeTesting;
        using ParentType = UnitTest;

    public:
        explicit AndroidInputEventFacadeTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest() noexcept;
    };
}

#endif  // SYSTEM_ANDROID_SUITE_ANDROID_INPUT_EVENT_FACADE_TESTING_H