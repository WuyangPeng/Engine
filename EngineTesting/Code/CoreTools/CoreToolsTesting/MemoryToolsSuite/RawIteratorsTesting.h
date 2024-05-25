/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/05/18 20:15)

#ifndef CORE_TOOLS_DATA_TYPES_SUITE_RAW_ITERATORS_TESTING_H
#define CORE_TOOLS_DATA_TYPES_SUITE_RAW_ITERATORS_TESTING_H

#include "CoreTools/MemoryTools/RawIterators.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class RawIteratorsTesting final : public UnitTest
    {
    public:
        using ClassType = RawIteratorsTesting;
        using ParentType = UnitTest;

    public:
        explicit RawIteratorsTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        static constexpr auto size = 20;

        using ContainerType = std::vector<int>;
        using RawConstIteratorType = RawConstIterator<int>;
        using RawIteratorType = RawIterator<int>;

    private:
        void MainTest();
        void DoRunUnitTest() override;

        void RawConstIteratorTest();
        void RawIteratorTest();

        void ConstPrefixAdditionOperatorTest(RawConstIteratorType& rawConstIterator);
        void ConstSuffixAdditionOperatorTest(RawConstIteratorType& rawConstIterator);
        void ConstPrefixSubtractionOperatorTest(RawConstIteratorType& rawConstIterator);
        void ConstSuffixSubtractionOperatorTest(RawConstIteratorType& rawConstIterator);
        void ConstAdditionOperatorTest(RawConstIteratorType& rawConstIterator);
        void ConstSubtractionOperatorTest(RawConstIteratorType& rawConstIterator);

        void PrefixAdditionOperatorTest(RawIteratorType& rawIterator);
        void SuffixAdditionOperatorTest(RawIteratorType& rawIterator);
        void PrefixSubtractionOperatorTest(RawIteratorType& rawIterator);
        void SuffixSubtractionOperatorTest(RawIteratorType& rawIterator);
        void AdditionOperatorTest(RawIteratorType& rawIterator);
        void SubtractionOperatorTest(RawIteratorType& rawIterator);
    };
}

#endif  // CORE_TOOLS_DATA_TYPES_SUITE_RAW_ITERATORS_TESTING_H