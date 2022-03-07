///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.2 (2021/04/23 15:55)

#include "MemorySetTesting.h"
#include "System/MemoryTools/MemoryHelper.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <array>

using std::array;

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
    array<char, buffSize> buff{};

    constexpr auto fillValue = 1;
    MemorySet(buff.data(), fillValue, buffSize);

    array<char, buffSize> result{};
    result.fill(fillValue);

    ASSERT_EQUAL(buff, result);
}
