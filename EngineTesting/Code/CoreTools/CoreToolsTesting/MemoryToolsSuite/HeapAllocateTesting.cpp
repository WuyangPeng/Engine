///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/18 18:20)

#include "HeapAllocateTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/MemoryTools/HeapAllocateDetail.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, HeapAllocateTesting)

void CoreTools::HeapAllocateTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CharTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DoubleTest);
}

void CoreTools::HeapAllocateTesting::CharTest()
{
    constexpr auto size = 10;

    HeapAllocate<char> heap{ size };

    ASSERT_EQUAL(heap.GetLength(), size);
    ASSERT_EQUAL(heap.GetByteLength(), size * boost::numeric_cast<int>(sizeof(char)));
    ASSERT_UNEQUAL_NULL_PTR(heap.GetPoint());
}

void CoreTools::HeapAllocateTesting::DoubleTest()
{
    constexpr auto size = 20;

    const HeapAllocate<double> heap{ size };

    ASSERT_EQUAL(heap.GetLength(), size);
    ASSERT_EQUAL(heap.GetByteLength(), size * boost::numeric_cast<int>(sizeof(double)));
    ASSERT_UNEQUAL_NULL_PTR(heap.GetPoint());
}
