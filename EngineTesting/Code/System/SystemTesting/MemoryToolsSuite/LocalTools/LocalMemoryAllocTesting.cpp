/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/12 10:16)

#include "LocalMemoryAllocTesting.h"
#include "System/MemoryTools/LocalTools.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::LocalMemoryAllocTesting::LocalMemoryAllocTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, LocalMemoryAllocTesting)

void System::LocalMemoryAllocTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::LocalMemoryAllocTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(LocalMemoryAllocTest);
}

void System::LocalMemoryAllocTesting::LocalMemoryAllocTest()
{
    for (const auto localMemory : *this)
    {
        ASSERT_NOT_THROW_EXCEPTION_1(DoLocalMemoryAllocTest, localMemory);
    }
}

void System::LocalMemoryAllocTesting::DoLocalMemoryAllocTest(LocalMemory localMemory)
{
    const auto local = LocalMemoryAlloc(localMemory, localSize);
    ASSERT_UNEQUAL_NULL_PTR(local);

    ASSERT_NOT_THROW_EXCEPTION_1(LocalMemoryFreeTest, local);
}