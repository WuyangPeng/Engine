///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.6 (2023/04/11 18:04)

#include "MinHeapRecordStoredTesting.h"
#include "CoreTools/DataTypes/MinHeapRecordStoredDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::MinHeapRecordStoredTesting::MinHeapRecordStoredTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, MinHeapRecordStoredTesting)

void CoreTools::MinHeapRecordStoredTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::MinHeapRecordStoredTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FloatTest);
    ASSERT_NOT_THROW_EXCEPTION_0(IntegerTest);
}

void CoreTools::MinHeapRecordStoredTesting::FloatTest()
{
    constexpr auto arraySize = 5;

    MinHeapRecordStored<int, float> minHeapRecordArray0{ arraySize, 0.0f };

    ASSERT_EQUAL(minHeapRecordArray0.GetMaxElements(), arraySize);

    for (auto index = 0; index < arraySize; ++index)
    {
        minHeapRecordArray0.SetGenerator(index, arraySize - index);
        minHeapRecordArray0.SetValue(index, index * 2.0f);
    }

    const MinHeapRecordStored minHeapRecordArray1{ minHeapRecordArray0 };

    ASSERT_EQUAL(minHeapRecordArray1.GetMaxElements(), arraySize);

    for (auto index = 0; index < arraySize; ++index)
    {
        ASSERT_EQUAL(minHeapRecordArray0.GetGenerator(index), arraySize - index);
        ASSERT_APPROXIMATE(minHeapRecordArray0.GetValue(index), index * 2.0f, 1.0e-8f);
        ASSERT_EQUAL(minHeapRecordArray0.GetUniqueIndex(index), index);
        ASSERT_EQUAL(minHeapRecordArray1.GetGenerator(index), arraySize - index);
        ASSERT_APPROXIMATE(minHeapRecordArray1.GetValue(index), index * 2.0f, 1.0e-8f);
        ASSERT_EQUAL(minHeapRecordArray1.GetUniqueIndex(index), index);
    }

    MinHeapRecordStored<int, float> minHeapRecordArray2{ arraySize + 1, 0.0f };

    ASSERT_EQUAL(minHeapRecordArray2.GetMaxElements(), arraySize + 1);

    for (auto index = 0; index < arraySize + 1; ++index)
    {
        minHeapRecordArray2.SetGenerator(index, arraySize - index + 2);
        minHeapRecordArray2.SetValue(index, index * 3.0f);
    }

    minHeapRecordArray0 = minHeapRecordArray2;

    ASSERT_EQUAL(minHeapRecordArray0.GetMaxElements(), arraySize + 1);

    for (auto index = 0; index < arraySize + 1; ++index)
    {
        ASSERT_EQUAL(minHeapRecordArray0.GetGenerator(index), arraySize - index + 2);
        ASSERT_APPROXIMATE(minHeapRecordArray0.GetValue(index), index * 3.0f, 1.0e-8f);
        ASSERT_EQUAL(minHeapRecordArray0.GetUniqueIndex(index), index);
        ASSERT_EQUAL(minHeapRecordArray2.GetGenerator(index), arraySize - index + 2);
        ASSERT_APPROXIMATE(minHeapRecordArray2.GetValue(index), index * 3.0f, 1.0e-8f);
        ASSERT_EQUAL(minHeapRecordArray2.GetUniqueIndex(index), index);
    }
}

void CoreTools::MinHeapRecordStoredTesting::IntegerTest()
{
    constexpr auto arraySize = 6;

    MinHeapRecordStored<int, int> minHeapRecordArray0{ arraySize, 0 };

    ASSERT_EQUAL(minHeapRecordArray0.GetMaxElements(), arraySize);

    for (auto index = 0; index < arraySize; ++index)
    {
        minHeapRecordArray0.SetGenerator(index, arraySize - index);
        minHeapRecordArray0.SetValue(index, index * 2);
    }

    const MinHeapRecordStored minHeapRecordArray1{ minHeapRecordArray0 };

    ASSERT_EQUAL(minHeapRecordArray1.GetMaxElements(), arraySize);

    for (auto index = 0; index < arraySize; ++index)
    {
        ASSERT_EQUAL(minHeapRecordArray0.GetGenerator(index), arraySize - index);
        ASSERT_EQUAL(minHeapRecordArray0.GetValue(index), index * 2);
        ASSERT_EQUAL(minHeapRecordArray0.GetUniqueIndex(index), index);
        ASSERT_EQUAL(minHeapRecordArray1.GetGenerator(index), arraySize - index);
        ASSERT_EQUAL(minHeapRecordArray1.GetValue(index), index * 2);
        ASSERT_EQUAL(minHeapRecordArray1.GetUniqueIndex(index), index);
    }

    MinHeapRecordStored minHeapRecordArray2{ arraySize + 1, minHeapRecordArray1 };

    for (auto index = 0; index < arraySize; ++index)
    {
        ASSERT_EQUAL(minHeapRecordArray2.GetGenerator(index), arraySize - index);
        ASSERT_EQUAL(minHeapRecordArray2.GetValue(index), index * 2);
    }

    ASSERT_EQUAL(minHeapRecordArray2.GetValue(arraySize), 0);

    ASSERT_EQUAL(minHeapRecordArray2.GetMaxElements(), arraySize + 1);

    for (auto index = 0; index < arraySize + 1; ++index)
    {
        minHeapRecordArray2.SetGenerator(index, arraySize - index + 2);
        minHeapRecordArray2.SetValue(index, index * 3);
    }

    minHeapRecordArray0 = minHeapRecordArray2;

    ASSERT_EQUAL(minHeapRecordArray0.GetMaxElements(), arraySize + 1);

    for (auto index = 0; index < arraySize + 1; ++index)
    {
        ASSERT_EQUAL(minHeapRecordArray0.GetGenerator(index), arraySize - index + 2);
        ASSERT_EQUAL(minHeapRecordArray0.GetValue(index), index * 3);
        ASSERT_EQUAL(minHeapRecordArray0.GetUniqueIndex(index), index);
        ASSERT_EQUAL(minHeapRecordArray2.GetGenerator(index), arraySize - index + 2);
        ASSERT_EQUAL(minHeapRecordArray2.GetValue(index), index * 3);
        ASSERT_EQUAL(minHeapRecordArray2.GetUniqueIndex(index), index);
    }

    for (auto index = 0; index < arraySize / 2 + 1; ++index)
    {
        minHeapRecordArray0.ChangeValue(index, arraySize - index);
    }

    for (auto index = 0; index < arraySize + 1; ++index)
    {
        ASSERT_EQUAL(minHeapRecordArray0.GetGenerator(arraySize - index), arraySize - index + 2);
        ASSERT_EQUAL(minHeapRecordArray0.GetValue(arraySize - index), index * 3);
        ASSERT_EQUAL(minHeapRecordArray0.GetUniqueIndex(arraySize - index), index);
    }
}
