///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.7 (2023/04/25 16:32)

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