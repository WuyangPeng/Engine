/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/16 15:18)

#ifndef CORE_TOOLS_THREADING_SUITE_SEMAPHORE_TESTING_H
#define CORE_TOOLS_THREADING_SUITE_SEMAPHORE_TESTING_H

#include "CoreTools/Threading/Semaphore.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class SemaphoreTesting final : public UnitTest
    {
    public:
        using ClassType = SemaphoreTesting;
        using ParentType = UnitTest;

    public:
        explicit SemaphoreTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void CreateThread();
        void ReadThread();
        void WriteThread();

    private:
        static constexpr auto threadSize = 4;
        Semaphore semaphore0;
        Semaphore semaphore1;
    };
}

#endif  // CORE_TOOLS_THREADING_SUITE_SEMAPHORE_TESTING_H