///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/09/01 14:35)

#ifndef SYSTEM_THREADING_SUITE_EXIT_PROCESS_TESTING_H
#define SYSTEM_THREADING_SUITE_EXIT_PROCESS_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class ExitProcessTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = ExitProcessTesting;
        using ParentType = UnitTest;

    public:
        explicit ExitProcessTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest() noexcept;
    };
}

#endif  // SYSTEM_THREADING_SUITE_EXIT_PROCESS_TESTING_H