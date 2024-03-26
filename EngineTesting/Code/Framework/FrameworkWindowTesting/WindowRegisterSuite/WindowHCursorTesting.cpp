///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/10 13:55)

#include "WindowHCursorTesting.h"
#include "resource.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Windows/WindowsRegister.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Framework/WindowRegister/WindowHCursor.h"

#include <algorithm>

Framework::WindowHCursorTesting::WindowHCursorTesting(const OStreamShared& stream, WindowsHInstance instance)
    : ParentType{ stream },
      instance{ instance },
      container{ { 0, System::gArrow },
                 { 32512, System::gArrow },
                 { 32513, System::gIbeam },
                 { 32514, System::gWait },
                 { 32515, System::gCross },
                 { 32516, System::gUpArrow },
                 { 32642, System::gSizeNwse },
                 { 32643, System::gSizeNesw },
                 { 32644, System::gSizeWe },
                 { 32645, System::gSizeNs },
                 { 32646, System::gSizeAll },
                 { 32648, System::gNo },
                 { 32649, System::gIdcHand },
                 { 32650, System::gAppStarting },
                 { 32651, System::gHelp } }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, WindowHCursorTesting)

void Framework::WindowHCursorTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Framework::WindowHCursorTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ConstructorTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CreateTest);
}

void Framework::WindowHCursorTesting::ConstructorTest()
{
    std::ranges::for_each(container, [this](const auto& element) {
        const WindowHCursor windowHCursor{ element.second };
        ASSERT_EQUAL(windowHCursor.GetHCursor(), System::LoadSystemCursor(nullptr, element.second));
    });

    const WindowHCursor windowHIcon{ instance, IDC_CURSOR1 };
    ASSERT_EQUAL(windowHIcon.GetHCursor(), System::LoadSystemCursor(instance, System::MakeIntResource(IDC_CURSOR1)));
}

void Framework::WindowHCursorTesting::CreateTest()
{
    std::ranges::for_each(container, [this](const auto& element) {
        const auto windowHCursor = WindowHCursor::Create(instance, true, element.first);
        ASSERT_EQUAL(windowHCursor.GetHCursor(), System::LoadSystemCursor(nullptr, element.second));
    });

    const auto windowHCursor = WindowHCursor::Create(instance, false, IDC_CURSOR1);
    ASSERT_EQUAL(windowHCursor.GetHCursor(), System::LoadSystemCursor(instance, System::MakeIntResource(IDC_CURSOR1)));
}
