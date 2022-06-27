///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.9 (2022/06/27 13:52)

#include "WindowHCursorTesting.h"
#include "resource.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Windows/WindowsRegister.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/WindowRegister/WindowHCursor.h"

#include <algorithm>

namespace Framework
{
    using TestingType = WindowHCursor;
}

Framework::WindowHCursorTesting::WindowHCursorTesting(const OStreamShared& stream, HInstance instance)
    : ParentType{ stream },
      instance{ instance },
      container{ { 0, System::g_Arrow },
                   { 32512, System::g_Arrow },
                   { 32513, System::g_Ibeam },
                   { 32514, System::g_Wait },
                   { 32515, System::g_Cross },
                   { 32516, System::g_UpArrow },
                   { 32642, System::g_SizeNwse },
                   { 32643, System::g_SizeNesw },
                   { 32644, System::g_SizeWe },
                   { 32645, System::g_SizeNs },
                   { 32646, System::g_SizeAll },
                   { 32648, System::g_No },
                   { 32649, System::g_IDCHand },
                   { 32650, System::g_AppStarting },
                   { 32651, System::g_Help } }
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
