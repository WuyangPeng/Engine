///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.3 (2022/10/15 22:02)

#include "SetSystemConsoleScreenBufferSizeTesting.h"
#include "System/Console/ConsoleScreenBuffer.h"
#include "System/Console/Flags/ConsoleColoursFlags.h"
#include "System/Console/Flags/ConsoleScreenBufferFlags.h"
#include "System/Helper/WindowsMacro.h"
#include "System/MemoryTools/MemoryHelperDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::SetSystemConsoleScreenBufferSizeTesting::SetSystemConsoleScreenBufferSizeTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, SetSystemConsoleScreenBufferSizeTesting)

void System::SetSystemConsoleScreenBufferSizeTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::SetSystemConsoleScreenBufferSizeTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SetConsoleScreenBufferSizeTest);
}

void System::SetSystemConsoleScreenBufferSizeTesting::SetConsoleScreenBufferSizeTest()
{
    constexpr auto bufferSize = 256;

    auto attributesConsoleHandle = CreateSystemConsoleScreenBuffer(DesiredAccessGeneric::ReadAndWrite, ConsoleScreenBufferShareMode::ReadAndWrite, nullptr);

    auto originalConsoleScreenBufferInfo = GetWindowsStructDefaultSize<ConsoleScreenBufferInfoEx>();
    ASSERT_TRUE(GetSystemConsoleScreenBufferInfo(attributesConsoleHandle, &originalConsoleScreenBufferInfo));

    ConsoleCoord consoleCoord{};
    consoleCoord.X = bufferSize;
    consoleCoord.Y = bufferSize * 2;

    ASSERT_TRUE(SetSystemConsoleScreenBufferSize(attributesConsoleHandle, consoleCoord));

    auto currentConsoleScreenBufferInfoEx = GetWindowsStructDefaultSize<ConsoleScreenBufferInfoEx>();
    ASSERT_TRUE(GetSystemConsoleScreenBufferInfo(attributesConsoleHandle, &currentConsoleScreenBufferInfoEx));

    ASSERT_EQUAL(currentConsoleScreenBufferInfoEx.dwSize.X, consoleCoord.X);
    ASSERT_EQUAL(currentConsoleScreenBufferInfoEx.dwSize.Y, consoleCoord.Y);

    ASSERT_TRUE(SetSystemConsoleScreenBufferSize(attributesConsoleHandle, originalConsoleScreenBufferInfo.dwSize));
    ASSERT_TRUE(CloseSystemConsole(attributesConsoleHandle));
}
