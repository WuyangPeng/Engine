///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.6 (2023/04/14 14:45)

#include "HeapAllocateTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/MemoryTools/HeapAllocateDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::HeapAllocateTesting::HeapAllocateTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, HeapAllocateTesting)

void CoreTools::HeapAllocateTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

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
