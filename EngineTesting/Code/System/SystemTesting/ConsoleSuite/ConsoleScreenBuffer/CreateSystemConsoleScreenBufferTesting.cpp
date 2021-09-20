///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.2 (2021/04/08 18:28)

#include "CreateSystemConsoleScreenBufferTesting.h"
#include "System/Console/ConsoleHandle.h"
#include "System/Console/ConsoleScreenBuffer.h"
#include "System/Console/Flags/ConsoleScreenBufferFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using std::max;

System::CreateSystemConsoleScreenBufferTesting::CreateSystemConsoleScreenBufferTesting(const OStreamShared& stream)
    : ParentType{ stream },
      desiredAccessGenericFlags{ DesiredAccessGeneric::Read, DesiredAccessGeneric::Write, DesiredAccessGeneric::ReadAndWrite },
      consoleScreenBufferShareModeFlags{ ConsoleScreenBufferShareMode::Read, ConsoleScreenBufferShareMode::Write, ConsoleScreenBufferShareMode::ReadAndWrite },
      maxSize{ max(desiredAccessGenericFlags.size(), consoleScreenBufferShareModeFlags.size()) }
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
    shuffle(desiredAccessGenericFlags.begin(), desiredAccessGenericFlags.end(), randomEngine);
    shuffle(consoleScreenBufferShareModeFlags.begin(), consoleScreenBufferShareModeFlags.end(), randomEngine);

    ASSERT_NOT_THROW_EXCEPTION_0(CreateNullSecurityAttributesConsoleScreenBufferTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CreateBInheritHandleTrueConsoleScreenBufferTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CreateBInheritHandleFalseConsoleScreenBufferTest);

    return true;
}

void System::CreateSystemConsoleScreenBufferTesting::CreateNullSecurityAttributesConsoleScreenBufferTest()
{
    for (auto index = 0u; index < maxSize; ++index)
    {
        auto desiredAccessGeneric = desiredAccessGenericFlags.at(index % desiredAccessGenericFlags.size());
        auto consoleScreenBufferShareMode = consoleScreenBufferShareModeFlags.at(index % consoleScreenBufferShareModeFlags.size());

        auto nullSecurityAttributesConsoleHandle = CreateSystemConsoleScreenBuffer(desiredAccessGeneric, consoleScreenBufferShareMode, nullptr);

        ASSERT_TRUE(IsHandleValid(nullSecurityAttributesConsoleHandle));

        ASSERT_TRUE(CloseSystemConsole(nullSecurityAttributesConsoleHandle));
    }
}

void System::CreateSystemConsoleScreenBufferTesting::CreateBInheritHandleTrueConsoleScreenBufferTest()
{
    WindowSecurityAttributes securityAttributes{};
    SetDefaultConsoleSecurityAttributes(securityAttributes, true);

    for (auto index = 0u; index < maxSize; ++index)
    {
        auto desiredAccessGeneric = desiredAccessGenericFlags.at(index % desiredAccessGenericFlags.size());
        auto consoleScreenBufferShareMode = consoleScreenBufferShareModeFlags.at(index % consoleScreenBufferShareModeFlags.size());

        auto nullSecurityAttributesConsoleHandle = CreateSystemConsoleScreenBuffer(desiredAccessGeneric, consoleScreenBufferShareMode, &securityAttributes);

        ASSERT_TRUE(IsHandleValid(nullSecurityAttributesConsoleHandle));

        ASSERT_TRUE(CloseSystemConsole(nullSecurityAttributesConsoleHandle));
    }
}

void System::CreateSystemConsoleScreenBufferTesting::CreateBInheritHandleFalseConsoleScreenBufferTest()
{
    WindowSecurityAttributes securityAttributes{};
    SetDefaultConsoleSecurityAttributes(securityAttributes, false);

    for (auto index = 0u; index < maxSize; ++index)
    {
        auto desiredAccessGeneric = desiredAccessGenericFlags.at(index % desiredAccessGenericFlags.size());
        auto consoleScreenBufferShareMode = consoleScreenBufferShareModeFlags.at(index % consoleScreenBufferShareModeFlags.size());

        auto nullSecurityAttributesConsoleHandle = CreateSystemConsoleScreenBuffer(desiredAccessGeneric, consoleScreenBufferShareMode, &securityAttributes);

        ASSERT_TRUE(IsHandleValid(nullSecurityAttributesConsoleHandle));

        ASSERT_TRUE(CloseSystemConsole(nullSecurityAttributesConsoleHandle));
    }
}
