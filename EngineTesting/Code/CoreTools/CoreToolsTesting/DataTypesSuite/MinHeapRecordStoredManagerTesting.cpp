///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/19 13:53)

#include "MinHeapRecordStoredManagerTesting.h"
#include "CoreTools/DataTypes/MinHeapRecordStoredManagerDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, MinHeapRecordStoredManagerTesting)

void CoreTools::MinHeapRecordStoredManagerTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FloatTest);
    ASSERT_NOT_THROW_EXCEPTION_0(IntegerTest);
}

void CoreTools::MinHeapRecordStoredManagerTesting::FloatTest()
{
    constexpr auto recordSize = 5;

    MinHeapRecordStoredManager<int, float> firstMinHeapRecordStoredManager{ recordSize, 0.0f };

    ASSERT_EQUAL(firstMinHeapRecordStoredManager.GetMaxElements(), recordSize);

    for (auto index = 0; index < recordSize; ++index)
    {
        firstMinHeapRecordStoredManager.SetGeneratorByHeapIndex(index, recordSize - index);
        firstMinHeapRecordStoredManager.SetValueByHeapIndex(index, index * 2.0f);
    }

    MinHeapRecordStoredManager<int, float> secondMinHeapRecordStoredManager{ firstMinHeapRecordStoredManager };

    ASSERT_EQUAL(secondMinHeapRecordStoredManager.GetMaxElements(), recordSize);

    for (auto index = 0; index < recordSize; ++index)
    {
        ASSERT_EQUAL(firstMinHeapRecordStoredManager.GetGeneratorByHeapIndex(index), recordSize - index);
        ASSERT_APPROXIMATE(firstMinHeapRecordStoredManager.GetValueByHeapIndex(index), index * 2.0f, 1.0e-8f);
        ASSERT_EQUAL(firstMinHeapRecordStoredManager.GetHeapIndex(index), index);
        ASSERT_EQUAL(secondMinHeapRecordStoredManager.GetGeneratorByHeapIndex(index), recordSize - index);
        ASSERT_APPROXIMATE(secondMinHeapRecordStoredManager.GetValueByHeapIndex(index), index * 2.0f, 1.0e-8f);
        ASSERT_EQUAL(secondMinHeapRecordStoredManager.GetHeapIndex(index), index);
    }

    for (auto index = 0; index < recordSize / 2; ++index)
    {
        secondMinHeapRecordStoredManager.ChangeValue(index, recordSize - index - 1);
    }

    for (auto index = 0; index < recordSize; ++index)
    {
        ASSERT_EQUAL(firstMinHeapRecordStoredManager.GetGeneratorByHeapIndex(index), recordSize - index);
        ASSERT_APPROXIMATE(firstMinHeapRecordStoredManager.GetValueByHeapIndex(index), index * 2.0f, 1.0e-8f);
        ASSERT_EQUAL(firstMinHeapRecordStoredManager.GetHeapIndex(index), index);
        ASSERT_EQUAL(secondMinHeapRecordStoredManager.GetGeneratorByHeapIndex(recordSize - index - 1), recordSize - index);
        ASSERT_APPROXIMATE(secondMinHeapRecordStoredManager.GetValueByHeapIndex(recordSize - index - 1), index * 2.0f, 1.0e-8f);
        ASSERT_EQUAL(secondMinHeapRecordStoredManager.GetHeapIndex(recordSize - index - 1), index);
    }

    MinHeapRecordStoredManager<int, float> thirdMinHeapRecordStoredManager{ recordSize + 2, secondMinHeapRecordStoredManager };

    for (auto index = 0; index < recordSize; ++index)
    {
        ASSERT_EQUAL(thirdMinHeapRecordStoredManager.GetGeneratorByHeapIndex(recordSize - index - 1), recordSize - index);
        ASSERT_APPROXIMATE(thirdMinHeapRecordStoredManager.GetValueByHeapIndex(recordSize - index - 1), index * 2.0f, 0.00001f);
        ASSERT_EQUAL(thirdMinHeapRecordStoredManager.GetHeapIndex(recordSize - index - 1), index);
    }

    for (auto index = recordSize; index < recordSize + 2; ++index)
    {
        ASSERT_EQUAL(thirdMinHeapRecordStoredManager.GetHeapIndex(index), index);
    }
}

void CoreTools::MinHeapRecordStoredManagerTesting::IntegerTest()
{
    constexpr auto recordSize = 6;

    MinHeapRecordStoredManager<int, int> firstMinHeapRecordStoredManager{ recordSize, 0 };

    ASSERT_EQUAL(firstMinHeapRecordStoredManager.GetMaxElements(), recordSize);

    for (auto index = 0; index < recordSize; ++index)
    {
        firstMinHeapRecordStoredManager.SetGeneratorByHeapIndex(index, recordSize - index);
        firstMinHeapRecordStoredManager.SetValueByHeapIndex(index, index * 2);
    }

    MinHeapRecordStoredManager<int, int> secondMinHeapRecordStoredManager{ firstMinHeapRecordStoredManager };

    ASSERT_EQUAL(secondMinHeapRecordStoredManager.GetMaxElements(), recordSize);

    for (auto index = 0; index < recordSize; ++index)
    {
        ASSERT_EQUAL(firstMinHeapRecordStoredManager.GetGeneratorByHeapIndex(index), recordSize - index);
        ASSERT_EQUAL(firstMinHeapRecordStoredManager.GetValueByHeapIndex(index), index * 2);
        ASSERT_EQUAL(firstMinHeapRecordStoredManager.GetHeapIndex(index), index);
        ASSERT_EQUAL(secondMinHeapRecordStoredManager.GetGeneratorByHeapIndex(index), recordSize - index);
        ASSERT_EQUAL(secondMinHeapRecordStoredManager.GetValueByHeapIndex(index), index * 2);
        ASSERT_EQUAL(secondMinHeapRecordStoredManager.GetHeapIndex(index), index);
    }

    for (auto index = 0; index < recordSize / 2; ++index)
    {
        secondMinHeapRecordStoredManager.ChangeValue(index, recordSize - index - 1);
    }

    for (auto index = 0; index < recordSize; ++index)
    {
        ASSERT_EQUAL(firstMinHeapRecordStoredManager.GetGeneratorByHeapIndex(index), recordSize - index);
        ASSERT_EQUAL(firstMinHeapRecordStoredManager.GetValueByHeapIndex(index), index * 2);
        ASSERT_EQUAL(firstMinHeapRecordStoredManager.GetHeapIndex(index), index);
        ASSERT_EQUAL(secondMinHeapRecordStoredManager.GetGeneratorByHeapIndex(recordSize - index - 1), recordSize - index);
        ASSERT_EQUAL(secondMinHeapRecordStoredManager.GetValueByHeapIndex(recordSize - index - 1), index * 2);
        ASSERT_EQUAL(secondMinHeapRecordStoredManager.GetHeapIndex(recordSize - index - 1), index);
    }

    MinHeapRecordStoredManager<int, int> thirdMinHeapRecordStoredManager{ recordSize + 2, secondMinHeapRecordStoredManager };

    for (auto index = 0; index < recordSize; ++index)
    {
        ASSERT_EQUAL(thirdMinHeapRecordStoredManager.GetGeneratorByHeapIndex(recordSize - index - 1), recordSize - index);
        ASSERT_EQUAL(thirdMinHeapRecordStoredManager.GetValueByHeapIndex(recordSize - index - 1), index * 2);
        ASSERT_EQUAL(thirdMinHeapRecordStoredManager.GetHeapIndex(recordSize - index - 1), index);
    }

    for (auto index = recordSize; index < recordSize + 2; ++index)
    {
        ASSERT_EQUAL(thirdMinHeapRecordStoredManager.GetHeapIndex(index), index);
    }
}
