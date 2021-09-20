// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/05 19:04)

#include "MinHeapTesting.h"
#include "CoreTools/DataTypes/MinHeapDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include "System/Helper/PragmaWarning/NumericCast.h"
#include <random>

using std::default_random_engine;
using std::uniform_int_distribution;
using std::uniform_real;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, MinHeapTesting)

void CoreTools::MinHeapTesting ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(IntegerTest);
    ASSERT_NOT_THROW_EXCEPTION_0(FloatTest);
}

void CoreTools::MinHeapTesting ::IntegerTest()
{
    MinHeap<float, int> minHeap{ 10, 5, 0 };

    ASSERT_EQUAL(minHeap.GetMaxElements(), 10);
    ASSERT_EQUAL(minHeap.GetGrowBy(), 5);
    ASSERT_EQUAL(minHeap.GetElementsNumber(), 0);

    default_random_engine generator{ boost::numeric_cast<uint32_t>(GetRandomSeed()) };
    const uniform_int_distribution<> randomDistribution{ 0, 10 };

    for (auto i = 0; i < 12; ++i)
    {
        auto randomValue = randomDistribution(generator);
        const auto index = minHeap.Insert(0.1f * i, randomValue);
        ASSERT_EQUAL(minHeap.GetRecordByUniqueIndex(index).GetValue(), randomValue);
    }

    ASSERT_EQUAL(minHeap.GetMaxElements(), 15);
    ASSERT_EQUAL(minHeap.GetGrowBy(), 5);
    ASSERT_EQUAL(minHeap.GetElementsNumber(), 12);

    auto randomUpdateValue = randomDistribution(generator);
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

void CoreTools::MinHeapTesting ::FloatTest()
{
    MinHeap<int, float> minHeap{ 5, 3, 0 };

    ASSERT_EQUAL(minHeap.GetMaxElements(), 5);
    ASSERT_EQUAL(minHeap.GetGrowBy(), 3);
    ASSERT_EQUAL(minHeap.GetElementsNumber(), 0);

    default_random_engine generator{ boost::numeric_cast<uint32_t>(GetRandomSeed()) };
    const uniform_real<float> randomDistribution{ 0.0f, 10.0f };

    for (auto i = 0; i < 6; ++i)
    {
        auto randomValue = randomDistribution(generator);
        const auto index = minHeap.Insert(i, randomValue);
        ASSERT_APPROXIMATE(minHeap.GetRecordByUniqueIndex(index).GetValue(), randomValue, 0.0001f);
    }

    ASSERT_EQUAL(minHeap.GetMaxElements(), 8);
    ASSERT_EQUAL(minHeap.GetGrowBy(), 3);
    ASSERT_EQUAL(minHeap.GetElementsNumber(), 6);

    auto randomUpdateValue = randomDistribution(generator);
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
