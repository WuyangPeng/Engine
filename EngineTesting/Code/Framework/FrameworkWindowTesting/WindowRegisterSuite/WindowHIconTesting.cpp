///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/10 13:58)

#include "WindowHIconTesting.h"
#include "resource.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Windows/WindowsRegister.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Framework/WindowRegister/WindowHIcon.h"

#include <algorithm>

Framework::WindowHIconTesting::WindowHIconTesting(const OStreamShared& stream, WindowsHInstance instance)
    : ParentType{ stream },
      instance{ instance },
      container{ { 0, System::gApplication },
                 { 32512, System::gApplication },
                 { 32513, System::gIdiHand },
                 { 32514, System::gQuestion },
                 { 32515, System::gExclamation },
                 { 32516, System::gAsterisk },
                 { 32517, System::gWinLogo },
                 { 32518, System::gShield },
                 { 32515, System::gWarning },
                 { 32513, System::gError },
                 { 32516, System::gInformation } }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, WindowHIconTesting)

void Framework::WindowHIconTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Framework::WindowHIconTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ConstructorTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CreateTest);
}

void Framework::WindowHIconTesting::ConstructorTest()
{
    std::ranges::for_each(container, [this](const auto& element) {
        const WindowHIcon windowHIcon{ element.second };
        ASSERT_EQUAL(windowHIcon.GetHIcon(), System::LoadSystemIcon(nullptr, element.second));
    });

    const WindowHIcon windowHIcon{ instance, IDI_ICON1 };
    ASSERT_EQUAL(windowHIcon.GetHIcon(), System::LoadSystemIcon(instance, System::MakeIntResource(IDI_ICON1)));
}

void Framework::WindowHIconTesting::CreateTest()
{
    std::ranges::for_each(container, [this](const auto& element) {
        const auto windowHIcon = WindowHIcon::Create(instance, true, element.first);
        ASSERT_EQUAL(windowHIcon.GetHIcon(), System::LoadSystemIcon(nullptr, element.second));
    });

    const auto windowHIcon = WindowHIcon::Create(instance, false, IDI_ICON1);
    ASSERT_EQUAL(windowHIcon.GetHIcon(), System::LoadSystemIcon(instance, System::MakeIntResource(IDI_ICON1)));
}
