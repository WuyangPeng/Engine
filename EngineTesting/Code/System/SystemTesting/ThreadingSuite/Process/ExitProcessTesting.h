/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/12 18:05)

#ifndef SYSTEM_THREADING_SUITE_EXIT_PROCESS_TESTING_H
#define SYSTEM_THREADING_SUITE_EXIT_PROCESS_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    /// ����ProcessTest��ExitSystemProcess�Ĳ��ԡ�
    /// �౾���ǿղ��ԡ�
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
        void MainTest() const noexcept;
    };
}

#endif  // SYSTEM_THREADING_SUITE_EXIT_PROCESS_TESTING_H