///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/14 16:55)

#include "MemoryCopyTesting.h"
#include "System/MemoryTools/MemoryHelper.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <array>

using std::array;

System::MemoryCopyTesting::MemoryCopyTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, MemoryCopyTesting)

void System::MemoryCopyTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::MemoryCopyTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MemoryCopyTest);
}

void System::MemoryCopyTesting::MemoryCopyTest()
{
    constexpr auto buffSize = 256;
    constexpr auto fillValue = 1;

    array<char, buffSize> buff{};
    buff.fill(fillValue);

    array<char, buffSize> copyBuff{};

    MemoryCopy(copyBuff.data(), buff.data(), buffSize);

    array<char, buffSize> result{};
    result.fill(fillValue);

    ASSERT_EQUAL(copyBuff, result);
}
