///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/12 16:19)

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