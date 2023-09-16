///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/31 16:40)

#include "CreateSystemConsoleScreenBufferTesting.h"
#include "System/Console/ConsoleHandle.h"
#include "System/Console/ConsoleScreenBuffer.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::CreateSystemConsoleScreenBufferTesting::CreateSystemConsoleScreenBufferTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, CreateSystemConsoleScreenBufferTesting)

void System::CreateSystemConsoleScreenBufferTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::CreateSystemConsoleScreenBufferTesting::MainTest()
{
    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(RandomShuffleFlags);
}

bool System::CreateSystemConsoleScreenBufferTesting::RandomShuffleFlags()
{
    ASSERT_NOT_THROW_EXCEPTION_0(RandomShuffleConsoleFlags);

    ASSERT_NOT_THROW_EXCEPTION_0(CreateNullSecurityAttributesConsoleScreenBufferTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CreateBInheritHandleTrueConsoleScreenBufferTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CreateBInheritHandleFalseConsoleScreenBufferTest);

    return true;
}

void System::CreateSystemConsoleScreenBufferTesting::CreateNullSecurityAttributesConsoleScreenBufferTest()
{
    ASSERT_NOT_THROW_EXCEPTION_1(CreateSystemConsoleScreenBufferTest, nullptr);
}

void System::CreateSystemConsoleScreenBufferTesting::CreateBInheritHandleTrueConsoleScreenBufferTest()
{
    WindowSecurityAttributes securityAttributes{};
    SetDefaultConsoleSecurityAttributes(securityAttributes, true);

    ASSERT_NOT_THROW_EXCEPTION_1(CreateSystemConsoleScreenBufferTest, &securityAttributes);
}

void System::CreateSystemConsoleScreenBufferTesting::CreateBInheritHandleFalseConsoleScreenBufferTest()
{
    WindowSecurityAttributes securityAttributes{};
    SetDefaultConsoleSecurityAttributes(securityAttributes, false);

    ASSERT_NOT_THROW_EXCEPTION_1(CreateSystemConsoleScreenBufferTest, &securityAttributes);
}

void System::CreateSystemConsoleScreenBufferTesting::CreateSystemConsoleScreenBufferTest(const WindowSecurityAttributes* securityAttributes)
{
    for (auto index = 0u; index < GetMaxSize(); ++index)
    {
        ASSERT_NOT_THROW_EXCEPTION_2(DoCreateSystemConsoleScreenBufferTest, index, securityAttributes);
    }
}

void System::CreateSystemConsoleScreenBufferTesting::DoCreateSystemConsoleScreenBufferTest(size_t index, const WindowSecurityAttributes* securityAttributes)
{
    const auto desiredAccessGeneric = GetDesiredAccessGeneric(index);
    const auto consoleScreenBufferShareMode = GetConsoleScreenBufferShareMode(index);

    const auto securityAttributesConsoleHandle = CreateSystemConsoleScreenBuffer(desiredAccessGeneric, consoleScreenBufferShareMode, securityAttributes);

    ASSERT_TRUE(IsHandleValid(securityAttributesConsoleHandle));

    ASSERT_TRUE(CloseSystemConsole(securityAttributesConsoleHandle));
}
