///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/13 23:07)

#include "WindowHIconTesting.h"
#include "resource.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Windows/WindowsRegister.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Framework/WindowRegister/WindowHIcon.h"

#include <algorithm>

namespace Framework
{
    using TestingType = WindowHIcon;
}

Framework::WindowHIconTesting::WindowHIconTesting(const OStreamShared& stream, HInstance instance)
    : ParentType{ stream },
      instance{ instance },
      container{ { 0, System::gApplication },
                 { 32512, System::gApplication },
                 { 32513, System::gIDIHand },
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
    for_each(container.begin(), container.end(), [this](const auto& value) {
        const TestingType windowHIcon1{ value.second };
        ASSERT_EQUAL(windowHIcon1.GetHIcon(), System::LoadSystemIcon(nullptr, value.second));
    });

    const TestingType windowHIcon2{ instance, IDI_ICON1 };
    ASSERT_EQUAL(windowHIcon2.GetHIcon(), System::LoadSystemIcon(instance, System::MakeIntreSource(IDI_ICON1)));
}

void Framework::WindowHIconTesting::CreateTest()
{
    for_each(container.begin(), container.end(), [this](const auto& value) {
        const auto windowHIcon1 = TestingType::Create(instance, true, value.first);
        ASSERT_EQUAL(windowHIcon1.GetHIcon(), System::LoadSystemIcon(nullptr, value.second));
    });

    const auto windowHIcon2 = TestingType::Create(instance, false, IDI_ICON1);
    ASSERT_EQUAL(windowHIcon2.GetHIcon(), System::LoadSystemIcon(instance, System::MakeIntreSource(IDI_ICON1)));
}
