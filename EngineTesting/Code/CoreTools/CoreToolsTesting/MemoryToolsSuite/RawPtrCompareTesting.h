/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/22 15:45)

#ifndef CORE_TOOLS_DATA_TYPES_SUITE_RAW_PTR_COMPARE_TESTING_H
#define CORE_TOOLS_DATA_TYPES_SUITE_RAW_PTR_COMPARE_TESTING_H

#include "CoreTools/MemoryTools/RawIterators.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class RawPtrCompareTesting final : public UnitTest
    {
    public:
        using ClassType = RawPtrCompareTesting;
        using ParentType = UnitTest;

    public:
        explicit RawPtrCompareTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        static constexpr auto size = 20;

        using ContainerType = std::vector<int>;
        using RawConstIteratorType = RawConstIterator<int>;

    private:
        void MainTest();
        void DoRunUnitTest() override;

        void RawPtrCompareTest();

        void RawPtrEqualTest(const RawConstIteratorType& lhsRawConstIterator, const RawConstIteratorType& rhsRawConstIterator);
        void RawPtrUnequalTest(const RawConstIteratorType& lhsRawConstIterator, const RawConstIteratorType& rhsRawConstIterator);
        void RawPtrLessTest(const RawConstIteratorType& lhsRawConstIterator, const RawConstIteratorType& rhsRawConstIterator);
        void RawPtrLessEqualTest(const RawConstIteratorType& lhsRawConstIterator, const RawConstIteratorType& rhsRawConstIterator);
        void RawPtrGreaterTest(const RawConstIteratorType& lhsRawConstIterator, const RawConstIteratorType& rhsRawConstIterator);
        void RawPtrGreaterEqualTest(const RawConstIteratorType& lhsRawConstIterator, const RawConstIteratorType& rhsRawConstIterator);
    };
}

#endif  // CORE_TOOLS_DATA_TYPES_SUITE_RAW_PTR_COMPARE_TESTING_H