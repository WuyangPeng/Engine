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
    MinHeap<int> minHeap{ 10 };

    ASSERT_EQUAL(minHeap.GetMaxElements(), 10); 
    ASSERT_EQUAL(minHeap.GetNumElements(), 0);

    ASSERT_EQUAL(minHeap.Insert(2, 3), 0);

    ASSERT_EQUAL(minHeap.GetNumElements(), 1);

    ASSERT_TRUE(minHeap.Update(0, 5));

    const auto minHeapRecord = minHeap.Remove();

    ASSERT_EQUAL(minHeapRecord.GetHandle(), 2);
    ASSERT_EQUAL(minHeapRecord.GetWeight(), 5);

    ASSERT_EQUAL(minHeap.GetNumElements(), 0);
}

void CoreTools::MinHeapTesting::FloatTest() noexcept
{
}
