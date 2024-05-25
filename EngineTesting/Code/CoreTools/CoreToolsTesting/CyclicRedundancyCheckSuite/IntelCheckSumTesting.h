/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/04/23 13:07)

#ifndef CORE_TOOLS_CYCLIC_REDUNDANCY_CHECK_SUITE_INTEL_CHECK_SUM_TESTING_H
#define CORE_TOOLS_CYCLIC_REDUNDANCY_CHECK_SUITE_INTEL_CHECK_SUM_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class IntelCheckSumTesting final : public UnitTest
    {
    public:
        using ClassType = IntelCheckSumTesting;
        using ParentType = UnitTest;

    public:
        explicit IntelCheckSumTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        static constexpr auto bufferSize = 256;

        using BufferType = std::array<char, bufferSize>;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void SumTest();

        NODISCARD static BufferType GetBufferType();
    };
}

#endif  // CORE_TOOLS_CYCLIC_REDUNDANCY_CHECK_SUITE_INTEL_CHECK_SUM_TESTING_H
