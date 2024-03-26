/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/11 18:27)

#include "DefaultTextAttributeTesting.h"
#include "System/Console/ConsoleColour.h"
#include "System/Console/ConsoleHandle.h"
#include "System/Console/Flags/ConsoleColoursFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::DefaultTextAttributeTesting::DefaultTextAttributeTesting(const OStreamShared& stream)
    : ParentType{ stream }
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
    for (const auto standardHandle : *this)
    {
        ASSERT_NOT_THROW_EXCEPTION_1(DoDefaultTextAttributeTest, standardHandle);
    }
}

void System::DefaultTextAttributeTesting::DoDefaultTextAttributeTest(StandardHandle standardHandle)
{
    ASSERT_TRUE(SetSystemConsoleDefaultTextAttribute(GetStandardHandle(standardHandle)));

    PrintMessage(standardHandle, TextColour::White, BackgroundColour::Black, ConsoleCommon::Default);
}
