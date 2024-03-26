/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 17:21)

#include "GetSystemInputTesting.h"
#include "System/Time/DeltaTime.h"
#include "System/Windows/WindowsSystem.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::GetSystemInputTesting::GetSystemInputTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, GetSystemInputTesting)

void System::GetSystemInputTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::GetSystemInputTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(GetSystemInputTest);
}

void System::GetSystemInputTesting::GetSystemInputTest() const
{
    std::ignore = GetSystemInput<int>();
    std::ignore = GetSystemInput<std::string>();
}

void System::GetSystemInputTesting::PrintTipsMessage()
{
    GetStream() << "这个测试需要在控制台上输入任意值。\n";

    SystemPause();
}
