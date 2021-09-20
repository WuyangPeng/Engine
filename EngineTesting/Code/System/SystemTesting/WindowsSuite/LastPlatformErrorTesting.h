///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.6 (2021/07/06 13:47)

#ifndef SYSTEM_WINDOWS_SUITE_LAST_PLATFORM_ERROR_TESTING_H
#define SYSTEM_WINDOWS_SUITE_LAST_PLATFORM_ERROR_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class LastPlatformErrorTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = LastPlatformErrorTesting;
        using ParentType = UnitTest;

    public:
        explicit LastPlatformErrorTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void LastErrorTest();
        void LastErrorModeTest();
    };
}

#endif  // SYSTEM_WINDOWS_SUITE_LAST_PLATFORM_ERROR_TESTING_H