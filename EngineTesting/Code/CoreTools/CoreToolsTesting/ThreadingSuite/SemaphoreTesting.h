///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/17 15:54)

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
        void DoRunUnitTest() final;
        void MainTest();

        void CreateThread();
        void ReadThread();
        void WirteThread();

    private:
        static constexpr auto threadSize = 4;
        Semaphore semaphore0;
        Semaphore semaphore1;
    };
}

#endif  // CORE_TOOLS_THREADING_SUITE_SEMAPHORE_TESTING_H