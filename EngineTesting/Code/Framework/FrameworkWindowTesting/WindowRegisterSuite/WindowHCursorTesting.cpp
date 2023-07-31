///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/13 23:07)

#include "WindowHCursorTesting.h"
#include "resource.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Windows/WindowsRegister.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Framework/WindowRegister/WindowHCursor.h"

#include <algorithm>

namespace Framework
{
    using TestingType = WindowHCursor;
}

Framework::WindowHCursorTesting::WindowHCursorTesting(const OStreamShared& stream, HInstance instance)
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
    for_each(container.begin(), container.end(), [this](const auto& value) {
        const TestingType windowHCursor1{ value.second };
        ASSERT_EQUAL(windowHCursor1.GetHCursor(), System::LoadSystemCursor(nullptr, value.second));
    });

    const TestingType windowHIcon2{ instance, IDC_CURSOR1 };
    ASSERT_EQUAL(windowHIcon2.GetHCursor(), System::LoadSystemCursor(instance, System::MakeIntreSource(IDC_CURSOR1)));
}

void Framework::WindowHCursorTesting::CreateTest()
{
    for_each(container.begin(), container.end(), [this](const auto& value) {
        const auto windowHCursor1 = TestingType::Create(instance, true, value.first);
        ASSERT_EQUAL(windowHCursor1.GetHCursor(), System::LoadSystemCursor(nullptr, value.second));
    });

    const auto windowHCursor2 = TestingType::Create(instance, false, IDC_CURSOR1);
    ASSERT_EQUAL(windowHCursor2.GetHCursor(), System::LoadSystemCursor(instance, System::MakeIntreSource(IDC_CURSOR1)));
}
