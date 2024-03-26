/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/12 18:05)

#ifndef SYSTEM_THREADING_SUITE_GET_PROCESS_HANDLE_TESTING_H
#define SYSTEM_THREADING_SUITE_GET_PROCESS_HANDLE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class GetProcessHandleTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = GetProcessHandleTesting;
        using ParentType = UnitTest;

    public:
        explicit GetProcessHandleTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void ProcessTest();
    };
}

#endif  // SYSTEM_THREADING_SUITE_GET_PROCESS_HANDLE_TESTING_H