///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.6 (2021/07/10 10:20)

#ifndef SYSTEM_LINUX_SUITE_MACINTOSH_NATIVE_WINDOW_TESTING_H
#define SYSTEM_LINUX_SUITE_MACINTOSH_NATIVE_WINDOW_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class MacintoshNativeWindowTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = MacintoshNativeWindowTesting;
        using ParentType = UnitTest;

    public:
        explicit MacintoshNativeWindowTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest() noexcept;
    };
}

#endif  // SYSTEM_LINUX_SUITE_MACINTOSH_NATIVE_WINDOW_TESTING_H