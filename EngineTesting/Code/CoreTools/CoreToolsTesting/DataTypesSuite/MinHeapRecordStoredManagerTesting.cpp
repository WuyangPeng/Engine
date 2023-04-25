///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.6 (2023/04/11 17:59)

#include "MinHeapRecordStoredManagerTesting.h"
#include "CoreTools/DataTypes/MinHeapRecordStoredManagerDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Base/MathDetail.h"

CoreTools::MinHeapRecordStoredManagerTesting::MinHeapRecordStoredManagerTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, MinHeapRecordStoredManagerTesting)

void CoreTools::MinHeapRecordStoredManagerTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::MinHeapRecordStoredManagerTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FloatTest);
    ASSERT_NOT_THROW_EXCEPTION_0(IntegerTest);
}

void CoreTools::MinHeapRecordStoredManagerTesting::FloatTest()
{
    constexpr auto recordSize = 5;

    MinHeapRecordStoredManager<int, float> minHeapRecordStoredManager0{ recordSize, 0.0f };

    ASSERT_EQUAL(minHeapRecordStoredManager0.GetMaxElements(), recordSize);

    for (auto index = 0; index < recordSize; ++index)
    {
        minHeapRecordStoredManager0.SetGeneratorByHeapIndex(index, recordSize - index);
        minHeapRecordStoredManager0.SetValueByHeapIndex(index, index * 2.0f);
    }

    MinHeapRecordStoredManager minHeapRecordStoredManager1{ minHeapRecordStoredManager0 };

    ASSERT_EQUAL(minHeapRecordStoredManager1.GetMaxElements(), recordSize);

    for (auto index = 0; index < recordSize; ++index)
    {
        ASSERT_EQUAL(minHeapRecordStoredManager0.GetGeneratorByHeapIndex(index), recordSize - index);
        ASSERT_APPROXIMATE(minHeapRecordStoredManager0.GetValueByHeapIndex(index), index * 2.0f, Mathematics::MathF::GetZeroTolerance());
        ASSERT_EQUAL(minHeapRecordStoredManager0.GetHeapIndex(index), index);
        ASSERT_EQUAL(minHeapRecordStoredManager1.GetGeneratorByHeapIndex(index), recordSize - index);
        ASSERT_APPROXIMATE(minHeapRecordStoredManager1.GetValueByHeapIndex(index), index * 2.0f, Mathematics::MathF::GetZeroTolerance());
        ASSERT_EQUAL(minHeapRecordStoredManager1.GetHeapIndex(index), index);
    }

    for (auto index = 0; index < recordSize / 2; ++index)
    {
        minHeapRecordStoredManager1.ChangeValue(index, recordSize - index - 1);
    }

    for (auto index = 0; index < recordSize; ++index)
    {
        ASSERT_EQUAL(minHeapRecordStoredManager0.GetGeneratorByHeapIndex(index), recordSize - index);
        ASSERT_APPROXIMATE(minHeapRecordStoredManager0.GetValueByHeapIndex(index), index * 2.0f, Mathematics::MathF::GetZeroTolerance());
        ASSERT_EQUAL(minHeapRecordStoredManager0.GetHeapIndex(index), index);
        ASSERT_EQUAL(minHeapRecordStoredManager1.GetGeneratorByHeapIndex(recordSize - index - 1), recordSize - index);
        ASSERT_APPROXIMATE(minHeapRecordStoredManager1.GetValueByHeapIndex(recordSize - index - 1), index * 2.0f, Mathematics::MathF::GetZeroTolerance());
        ASSERT_EQUAL(minHeapRecordStoredManager1.GetHeapIndex(recordSize - index - 1), index);
    }

    MinHeapRecordStoredManager minHeapRecordStoredManager2{ recordSize + 2, minHeapRecordStoredManager1 };

    for (auto index = 0; index < recordSize; ++index)
    {
        ASSERT_EQUAL(minHeapRecordStoredManager2.GetGeneratorByHeapIndex(recordSize - index - 1), recordSize - index);
        ASSERT_APPROXIMATE(minHeapRecordStoredManager2.GetValueByHeapIndex(recordSize - index - 1), index * 2.0f, Mathematics::MathF::GetZeroTolerance());
        ASSERT_EQUAL(minHeapRecordStoredManager2.GetHeapIndex(recordSize - index - 1), index);
    }

    for (auto index = recordSize; index < recordSize + 2; ++index)
    {
        ASSERT_EQUAL(minHeapRecordStoredManager2.GetHeapIndex(index), index);
    }
}

void CoreTools::MinHeapRecordStoredManagerTesting::IntegerTest()
{
    constexpr auto recordSize = 6;

    MinHeapRecordStoredManager<int, int> minHeapRecordStoredManager0{ recordSize, 0 };

    ASSERT_EQUAL(minHeapRecordStoredManager0.GetMaxElements(), recordSize);

    for (auto index = 0; index < recordSize; ++index)
    {
        minHeapRecordStoredManager0.SetGeneratorByHeapIndex(index, recordSize - index);
        minHeapRecordStoredManager0.SetValueByHeapIndex(index, index * 2);
    }

    MinHeapRecordStoredManager minHeapRecordStoredManager1{ minHeapRecordStoredManager0 };

    ASSERT_EQUAL(minHeapRecordStoredManager1.GetMaxElements(), recordSize);

    for (auto index = 0; index < recordSize; ++index)
    {
        ASSERT_EQUAL(minHeapRecordStoredManager0.GetGeneratorByHeapIndex(index), recordSize - index);
        ASSERT_EQUAL(minHeapRecordStoredManager0.GetValueByHeapIndex(index), index * 2);
        ASSERT_EQUAL(minHeapRecordStoredManager0.GetHeapIndex(index), index);
        ASSERT_EQUAL(minHeapRecordStoredManager1.GetGeneratorByHeapIndex(index), recordSize - index);
        ASSERT_EQUAL(minHeapRecordStoredManager1.GetValueByHeapIndex(index), index * 2);
        ASSERT_EQUAL(minHeapRecordStoredManager1.GetHeapIndex(index), index);
    }

    for (auto index = 0; index < recordSize / 2; ++index)
    {
        minHeapRecordStoredManager1.ChangeValue(index, recordSize - index - 1);
    }

    for (auto index = 0; index < recordSize; ++index)
    {
        ASSERT_EQUAL(minHeapRecordStoredManager0.GetGeneratorByHeapIndex(index), recordSize - index);
        ASSERT_EQUAL(minHeapRecordStoredManager0.GetValueByHeapIndex(index), index * 2);
        ASSERT_EQUAL(minHeapRecordStoredManager0.GetHeapIndex(index), index);
        ASSERT_EQUAL(minHeapRecordStoredManager1.GetGeneratorByHeapIndex(recordSize - index - 1), recordSize - index);
        ASSERT_EQUAL(minHeapRecordStoredManager1.GetValueByHeapIndex(recordSize - index - 1), index * 2);
        ASSERT_EQUAL(minHeapRecordStoredManager1.GetHeapIndex(recordSize - index - 1), index);
    }

    const MinHeapRecordStoredManager minHeapRecordStoredManager2{ recordSize + 2, minHeapRecordStoredManager1 };

    for (auto index = 0; index < recordSize; ++index)
    {
        ASSERT_EQUAL(minHeapRecordStoredManager2.GetGeneratorByHeapIndex(recordSize - index - 1), recordSize - index);
        ASSERT_EQUAL(minHeapRecordStoredManager2.GetValueByHeapIndex(recordSize - index - 1), index * 2);
        ASSERT_EQUAL(minHeapRecordStoredManager2.GetHeapIndex(recordSize - index - 1), index);
    }

    for (auto index = recordSize; index < recordSize + 2; ++index)
    {
        ASSERT_EQUAL(minHeapRecordStoredManager2.GetHeapIndex(index), index);
    }
}
