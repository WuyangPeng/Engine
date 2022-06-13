///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/15 13:34)

#ifndef SYSTEM_ANDROID_SUITE_ANDROID_INPUT_KEY_EVENT_TESTING_H
#define SYSTEM_ANDROID_SUITE_ANDROID_INPUT_KEY_EVENT_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class AndroidInputKeyEventTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = AndroidInputKeyEventTesting;
        using ParentType = UnitTest;

    public:
        explicit AndroidInputKeyEventTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest() noexcept;
    };
}

#endif  // SYSTEM_ANDROID_SUITE_ANDROID_INPUT_KEY_EVENT_TESTING_H