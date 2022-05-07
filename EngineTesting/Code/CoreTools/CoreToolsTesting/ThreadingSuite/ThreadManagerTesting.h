///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.2.3 (2021/09/02 14:59)

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
        void DoRunUnitTest() final;
        void MainTest();

    private:
        NODISCARD static uint32_t Thread0(void* threadParameter) noexcept;
        NODISCARD static uint32_t Thread1(MAYBE_UNUSED void* threadParameter) noexcept;

        void CreateThread();
    };
}

#endif  // CORE_TOOLS_THREADING_SUITE_THREAD_MANAGER_TESTING_H