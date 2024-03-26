/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/07 15:23)

#include "CharBufferTesting.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::CharBufferTesting::CharBufferTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, CharBufferTesting)

void System::CharBufferTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::CharBufferTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CharBufferTest);
}

void System::CharBufferTesting::CharBufferTest() const noexcept
{
    constexpr CharBufferType charBuffer{};
    constexpr WCharBufferType wCharBuffer{};
    constexpr TCharBufferType tCharBuffer{};
}
