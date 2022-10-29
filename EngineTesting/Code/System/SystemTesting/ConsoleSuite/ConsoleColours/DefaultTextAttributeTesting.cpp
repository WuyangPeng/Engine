///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.3 (2022/10/15 22:07)

#include "DefaultTextAttributeTesting.h"
#include "System/Console/ConsoleColours.h"
#include "System/Console/ConsoleHandle.h"
#include "System/Console/Flags/ConsoleColoursFlags.h"
#include "System/Console/Flags/ConsoleHandleFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::DefaultTextAttributeTesting::DefaultTextAttributeTesting(const OStreamShared& stream)
    : ParentType{ stream }, standardHandleFlags{ StandardHandle::Output, StandardHandle::Error }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, DefaultTextAttributeTesting)

void System::DefaultTextAttributeTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::DefaultTextAttributeTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(DefaultTextAttributeTest);
}

void System::DefaultTextAttributeTesting::DefaultTextAttributeTest()
{
    for (auto standardHandle : standardHandleFlags)
    {
        ASSERT_TRUE(SetSystemConsoleDefaultTextAttribute(GetStandardHandle(standardHandle)));

        PrintMessage(standardHandle, TextColour::White, BackgroundColour::Black, ConsoleCommon::Default);
    }
}
