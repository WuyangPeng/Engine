///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.2 (2021/04/23 15:55)

#include "FillMemoryTesting.h"
#include "System/MemoryTools/MemoryHelperDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::FillMemoryTesting::FillMemoryTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, FillMemoryTesting)

void System::FillMemoryTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::FillMemoryTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FillMemoryTest);
}

void System::FillMemoryTesting::FillMemoryTest()
{
    int32_t fillValue = 1;

    FillMemoryToZero(fillValue);

    ASSERT_EQUAL(fillValue, 0);
}
