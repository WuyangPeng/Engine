///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.3 (2023/03/01 18:09)

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