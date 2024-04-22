/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/16 15:19)

#ifndef CORE_TOOLS_THREADING_SUITE_THREAD_TESTING_H
#define CORE_TOOLS_THREADING_SUITE_THREAD_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class ThreadTesting final : public UnitTest
    {
    public:
        using ClassType = ThreadTesting;
        using ParentType = UnitTest;

    public:
        explicit ThreadTesting(const OStreamShared& stream);

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

#endif  // CORE_TOOLS_THREADING_SUITE_THREAD_TESTING_H