///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/09/01 15:40)

#ifndef SYSTEM_WINDOWS_SUITE_SYSTEM_DIRECTORY_TESTING_H
#define SYSTEM_WINDOWS_SUITE_SYSTEM_DIRECTORY_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class SystemDirectoryTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = SystemDirectoryTesting;
        using ParentType = UnitTest;

    public:
        explicit SystemDirectoryTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void SystemDirectoryTest();
    };
}

#endif  // SYSTEM_WINDOWS_SUITE_SYSTEM_DIRECTORY_TESTING_H