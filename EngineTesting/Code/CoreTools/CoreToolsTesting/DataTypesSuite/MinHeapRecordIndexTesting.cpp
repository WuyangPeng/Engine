///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/19 13:52)

#include "MinHeapRecordIndexTesting.h"
#include "CoreTools/DataTypes/MinHeapRecordIndex.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
CoreTools::MinHeapRecordIndexTesting::MinHeapRecordIndexTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, MinHeapRecordIndexTesting)

void CoreTools::MinHeapRecordIndexTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::MinHeapRecordIndexTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(IndexTest);
}

void CoreTools::MinHeapRecordIndexTesting::IndexTest()
{
    constexpr auto recordIndexSize = 11;

    MinHeapRecordIndex firstMinHeapRecordIndex{ recordIndexSize };

    ASSERT_EQUAL(firstMinHeapRecordIndex.GetMaxElements(), recordIndexSize);

    for (auto index = 0; index < recordIndexSize; ++index)
    {
        ASSERT_EQUAL(firstMinHeapRecordIndex.GetHeapIndex(index), index);
    }

    for (auto index = 0; index < recordIndexSize / 2; ++index)
    {
        firstMinHeapRecordIndex.ChangeIndex(index, recordIndexSize - index - 1);
    }

    MinHeapRecordIndex secondMinHeapRecordIndex{ firstMinHeapRecordIndex };

    ASSERT_EQUAL(secondMinHeapRecordIndex.GetMaxElements(), recordIndexSize);

    for (auto index = 0; index < firstMinHeapRecordIndex.GetMaxElements(); ++index)
    {
        ASSERT_EQUAL(firstMinHeapRecordIndex.GetHeapIndex(index), firstMinHeapRecordIndex.GetMaxElements() - index - 1);
    }

    MinHeapRecordIndex thirdMinHeapRecordIndex{ recordIndexSize + 2, secondMinHeapRecordIndex };

    ASSERT_EQUAL(thirdMinHeapRecordIndex.GetMaxElements(), recordIndexSize + 2);

    for (int index = 0; index < secondMinHeapRecordIndex.GetMaxElements(); ++index)
    {
        ASSERT_EQUAL(thirdMinHeapRecordIndex.GetHeapIndex(index), secondMinHeapRecordIndex.GetMaxElements() - index - 1);
    }

    for (auto index = secondMinHeapRecordIndex.GetMaxElements(); index < thirdMinHeapRecordIndex.GetMaxElements(); ++index)
    {
        ASSERT_EQUAL(thirdMinHeapRecordIndex.GetHeapIndex(index), index);
    }
}
