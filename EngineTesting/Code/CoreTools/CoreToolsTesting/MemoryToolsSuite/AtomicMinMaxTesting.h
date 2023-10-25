///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/25 13:42)

#ifndef CORE_TOOLS_DATA_TYPES_SUITE_ATOMIC_MIN_MAX_TESTING_H
#define CORE_TOOLS_DATA_TYPES_SUITE_ATOMIC_MIN_MAX_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class AtomicMinMaxTesting final : public UnitTest
    {
    public:
        using ClassType = AtomicMinMaxTesting;
        using ParentType = UnitTest;

    public:
        explicit AtomicMinMaxTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void MainTest();
        void DoRunUnitTest() override;

        void AtomicMinThreadTest();
        void AtomicMaxThreadTest();
        void AtomicMinTest();
        void AtomicMaxTest();

    private:
        std::atomic<int> atomic;

        static constexpr auto threadCount = 5;
    };
}

#endif  // CORE_TOOLS_DATA_TYPES_SUITE_ATOMIC_MIN_MAX_TESTING_H