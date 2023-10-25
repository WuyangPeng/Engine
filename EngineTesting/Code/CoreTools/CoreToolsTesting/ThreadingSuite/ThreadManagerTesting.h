///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/24 17:48)

#ifndef CORE_TOOLS_THREADING_SUITE_THREAD_MANAGER_TESTING_H
#define CORE_TOOLS_THREADING_SUITE_THREAD_MANAGER_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class ThreadManagerTesting final : public UnitTest
    {
    public:
        using ClassType = ThreadManagerTesting;
        using ParentType = UnitTest;

    public:
        explicit ThreadManagerTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

    private:
        NODISCARD static uint32_t Thread0(void* threadParameter) noexcept;
        NODISCARD static uint32_t Thread1(void* threadParameter) noexcept;

        void CreateThread();
    };
}

#endif  // CORE_TOOLS_THREADING_SUITE_THREAD_MANAGER_TESTING_H