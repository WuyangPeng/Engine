///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/01 10:06)

#include "MemorySetTesting.h"
#include "System/MemoryTools/MemoryHelper.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <array>

System::MemorySetTesting::MemorySetTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, MemorySetTesting)

void System::MemorySetTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::MemorySetTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MemorySetTest);
}

void System::MemorySetTesting::MemorySetTest()
{
    constexpr auto buffSize = 256;
    using BufferType = std::array<char, buffSize>;

    BufferType buffer{};

    constexpr auto fillValue = 1;
    MemorySet(buffer.data(), fillValue, buffSize);

    BufferType result{};
    result.fill(fillValue);

    ASSERT_EQUAL(buffer, result);
}
