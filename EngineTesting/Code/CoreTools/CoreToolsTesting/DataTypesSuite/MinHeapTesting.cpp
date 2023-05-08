///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.6 (2023/04/11 18:06)

#include "MinHeapTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/DataTypes/MinHeapDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <random>

CoreTools::MinHeapTesting::MinHeapTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, MinHeapTesting)

void CoreTools::MinHeapTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::MinHeapTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(IntegerTest);
    ASSERT_NOT_THROW_EXCEPTION_0(FloatTest);
}

void CoreTools::MinHeapTesting::IntegerTest()
{
    MinHeap<float, int> minHeap{ 10, 5, 0 };

    ASSERT_EQUAL(minHeap.GetMaxElements(), 10);
    ASSERT_EQUAL(minHeap.GetGrowBy(), 5);
    ASSERT_EQUAL(minHeap.GetElementsNumber(), 0);

    std::default_random_engine generator{ GetEngineRandomSeed() };
    const std::uniform_int_distribution<> randomDistribution{ 0, 10 };

    for (auto i = 0; i < 12; ++i)
    {
        auto randomValue = randomDistribution(generator);
        const auto index = minHeap.Insert(0.1f * i, randomValue);
        ASSERT_EQUAL(minHeap.GetRecordByUniqueIndex(index).GetValue(), randomValue);
    }

    ASSERT_EQUAL(minHeap.GetMaxElements(), 15);
    ASSERT_EQUAL(minHeap.GetGrowBy(), 5);
    ASSERT_EQUAL(minHeap.GetElementsNumber(), 12);

    const auto randomUpdateValue = randomDistribution(generator);
    if (minHeap.IsUniqueIndexValid(5))
    {
        const auto newIndex = minHeap.Update(5, randomUpdateValue);

        ASSERT_EQUAL(minHeap.GetMaxElements(), 15);
        ASSERT_EQUAL(minHeap.GetGrowBy(), 5);
        ASSERT_EQUAL(minHeap.GetElementsNumber(), 12);
        ASSERT_EQUAL(minHeap.GetRecordByHeapIndex(newIndex).GetValue(), randomUpdateValue);

        ASSERT_LESS_EQUAL(minHeap.GetRecordByHeapIndex(0).GetValue(), minHeap.GetRecordByHeapIndex(newIndex).GetValue());
    }

    for (auto i = 0; i < 5; ++i)
    {
        minHeap.Remove();
    }

    ASSERT_EQUAL(minHeap.GetMaxElements(), 15);
    ASSERT_EQUAL(minHeap.GetGrowBy(), 5);
    ASSERT_EQUAL(minHeap.GetElementsNumber(), 7);
}

void CoreTools::MinHeapTesting::FloatTest()
{
    MinHeap<int, float> minHeap{ 5, 3, 0 };

    ASSERT_EQUAL(minHeap.GetMaxElements(), 5);
    ASSERT_EQUAL(minHeap.GetGrowBy(), 3);
    ASSERT_EQUAL(minHeap.GetElementsNumber(), 0);

    std::default_random_engine generator{ GetEngineRandomSeed() };
    const std::uniform_real randomDistribution{ 0.0f, 10.0f };

    for (auto i = 0; i < 6; ++i)
    {
        auto randomValue = randomDistribution(generator);
        const auto index = minHeap.Insert(i, randomValue);
        ASSERT_APPROXIMATE(minHeap.GetRecordByUniqueIndex(index).GetValue(), randomValue, 0.0001f);
    }

    ASSERT_EQUAL(minHeap.GetMaxElements(), 8);
    ASSERT_EQUAL(minHeap.GetGrowBy(), 3);
    ASSERT_EQUAL(minHeap.GetElementsNumber(), 6);

    const auto randomUpdateValue = randomDistribution(generator);
    if (minHeap.IsUniqueIndexValid(2))
    {
        const auto newIndex = minHeap.Update(2, randomUpdateValue);

        ASSERT_EQUAL(minHeap.GetMaxElements(), 8);
        ASSERT_EQUAL(minHeap.GetGrowBy(), 3);
        ASSERT_EQUAL(minHeap.GetElementsNumber(), 6);
        ASSERT_APPROXIMATE(minHeap.GetRecordByHeapIndex(newIndex).GetValue(), randomUpdateValue, 0.0001f);

        ASSERT_LESS_EQUAL(minHeap.GetRecordByHeapIndex(0).GetValue(), minHeap.GetRecordByHeapIndex(newIndex).GetValue());
    }

    for (auto i = 0; i < 3; ++i)
    {
        minHeap.Remove();
    }

    ASSERT_EQUAL(minHeap.GetMaxElements(), 8);
    ASSERT_EQUAL(minHeap.GetGrowBy(), 3);
    ASSERT_EQUAL(minHeap.GetElementsNumber(), 3);
}
