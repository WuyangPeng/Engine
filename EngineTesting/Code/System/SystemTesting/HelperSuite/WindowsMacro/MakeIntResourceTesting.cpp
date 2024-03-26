/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/08 09:59)

#include "MakeIntResourceTesting.h"
#include "System/Helper/WindowsMacro.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::MakeIntResourceTesting::MakeIntResourceTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, MakeIntResourceTesting)

void System::MakeIntResourceTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::MakeIntResourceTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MakeIntResourceTest);
}

void System::MakeIntResourceTesting::MakeIntResourceTest()
{
    constexpr WindowsWord id{ 101 };

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)

    const auto* intPtr = reinterpret_cast<TChar*>(static_cast<uint64_t>(id));

#include SYSTEM_WARNING_POP

    const auto* intResource = MakeIntResource(id);

    ASSERT_TRUE(intPtr == intResource);
}
