///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.6 (2021/07/11 20:36)

#ifndef SYSTEM_ANDROID_SUITE_ANDROID_NATIVE_WINDOW_TESTING_H
#define SYSTEM_ANDROID_SUITE_ANDROID_NATIVE_WINDOW_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class AndroidNativeWindowTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = AndroidNativeWindowTesting;
        using ParentType = UnitTest;

    public:
        explicit AndroidNativeWindowTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest() noexcept;
    };
}

#endif  // SYSTEM_ANDROID_SUITE_ANDROID_NATIVE_WINDOW_TESTING_H