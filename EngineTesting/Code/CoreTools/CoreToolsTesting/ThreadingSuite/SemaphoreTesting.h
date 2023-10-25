///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.5 (2023/10/24 17:48)

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