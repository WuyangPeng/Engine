///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.1 (2023/02/02 20:47)

#include "GetSystemInputTesting.h"
#include "System/Time/DeltaTime.h"
#include "System/Windows/WindowsSystem.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

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
    MAYBE_UNUSED const auto value1 = GetSystemInput<std::string>();
}

void System::GetSystemInputTesting::PrintTipsMessage()
{
    GetStream() << "���������Ҫ�ڿ���̨����������ֵ��\n";

    SystemPause();
}
