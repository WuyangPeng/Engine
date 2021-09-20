///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.6 (2021/07/08 22:42)

#include "GetSystemInputTesting.h"
#include "System/Windows/WindowsSystem.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using std::string;

System::GetSystemInputTesting::GetSystemInputTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
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

void System::GetSystemInputTesting::GetSystemInputTest()
{
    MAYBE_UNUSED const auto value0 = GetSystemInput<int>();
    MAYBE_UNUSED const auto value1 = GetSystemInput<string>();
}