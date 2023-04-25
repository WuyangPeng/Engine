///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.6 (2023/04/11 17:58)

#include "MinHeapRecordIndexTesting.h"
#include "CoreTools/DataTypes/MinHeapRecordIndex.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
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

    MinHeapRecordIndex minHeapRecordIndex0{ recordIndexSize };

    ASSERT_EQUAL(minHeapRecordIndex0.GetMaxElements(), recordIndexSize);

    for (auto index = 0; index < recordIndexSize; ++index)
    {
        ASSERT_EQUAL(minHeapRecordIndex0.GetHeapIndex(index), index);
    }

    for (auto index = 0; index < recordIndexSize / 2; ++index)
    {
        minHeapRecordIndex0.ChangeIndex(index, recordIndexSize - index - 1);
    }

    const MinHeapRecordIndex minHeapRecordIndex1{ minHeapRecordIndex0 };

    ASSERT_EQUAL(minHeapRecordIndex1.GetMaxElements(), recordIndexSize);

    for (auto index = 0; index < minHeapRecordIndex0.GetMaxElements(); ++index)
    {
        ASSERT_EQUAL(minHeapRecordIndex0.GetHeapIndex(index), minHeapRecordIndex0.GetMaxElements() - index - 1);
    }

    const MinHeapRecordIndex minHeapRecordIndex2{ recordIndexSize + 2, minHeapRecordIndex1 };

    ASSERT_EQUAL(minHeapRecordIndex2.GetMaxElements(), recordIndexSize + 2);

    for (auto index = 0; index < minHeapRecordIndex1.GetMaxElements(); ++index)
    {
        ASSERT_EQUAL(minHeapRecordIndex2.GetHeapIndex(index), minHeapRecordIndex1.GetMaxElements() - index - 1);
    }

    for (auto index = minHeapRecordIndex1.GetMaxElements(); index < minHeapRecordIndex2.GetMaxElements(); ++index)
    {
        ASSERT_EQUAL(minHeapRecordIndex2.GetHeapIndex(index), index);
    }
}
