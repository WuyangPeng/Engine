/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/13 17:19)

#ifndef SYSTEM_WINDOWS_SUITE_GET_SYSTEM_INFO_TESTING_H
#define SYSTEM_WINDOWS_SUITE_GET_SYSTEM_INFO_TESTING_H

#include "System/Windows/Using/WindowsUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class GetSystemInfoTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = GetSystemInfoTesting;
        using ParentType = UnitTest;

    public:
        explicit GetSystemInfoTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void InfoTest();

        void GetWindowSystemInfoResultTest(const WindowsSystemInfo& systemInfo);
        void GetNumaProcessorNodeNumberTest(WindowsDWord numberOfProcessors);
    };
}

#endif  // SYSTEM_WINDOWS_SUITE_GET_SYSTEM_INFO_TESTING_H