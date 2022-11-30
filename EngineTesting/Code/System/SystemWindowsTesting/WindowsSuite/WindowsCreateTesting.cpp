///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.4 (2022/11/05 19:41)

#include "WindowsCreateTesting.h"
#include "System/Windows/Flags/WindowsCreateFlags.h"
#include "System/Windows/Flags/WindowsFlags.h"
#include "System/Windows/WindowsCreate.h"
#include "System/Windows/WindowsProcess.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

System::WindowsCreateTesting::WindowsCreateTesting(const OStreamShared& stream, WindowsHInstance instance, WindowsHWnd hwnd)
    : ParentType{ stream }, instance{ instance }, hwnd{ hwnd }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, WindowsCreateTesting)

void System::WindowsCreateTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::WindowsCreateTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CreateSystemWindowTest);
    ASSERT_NOT_THROW_EXCEPTION_0(GetHInstanceTest);
    ASSERT_NOT_THROW_EXCEPTION_0(MenuTest);
}

void System::WindowsCreateTesting::CreateSystemWindowTest()
{
    String className{};
    ASSERT_TRUE(GetSystemClassName(hwnd, className));

    constexpr auto width = 800;
    constexpr auto high = 600;
    WindowsRect rect{ 0, 0, width, high };

    ASSERT_TRUE(AdjustSystemWindowRect(&rect, WindowsStyles::OverlappedWindow));
    ASSERT_LESS_EQUAL(width, abs(rect.right - rect.left));
    ASSERT_LESS_EQUAL(high, abs(rect.top - rect.bottom));

    const auto windowsName = SYSTEM_TEXT("Test Windows"s);
    auto systemWindow = CreateSystemWindow(className, windowsName, WindowsStyles::Default, 0, 0, rect, nullptr, nullptr, instance);

    ASSERT_UNEQUAL_NULL_PTR(systemWindow);

    String newClassName{};
    String newWindowsName{};

    ASSERT_TRUE(GetSystemClassName(systemWindow, newClassName));
    ASSERT_EQUAL(newClassName, className);

    ASSERT_TRUE(GetWindowTextString(systemWindow, newWindowsName));
    ASSERT_EQUAL(newWindowsName, windowsName);
}

void System::WindowsCreateTesting::GetHInstanceTest()
{
    auto hInstance = GetHInstance();

    ASSERT_EQUAL(hInstance, instance);
}

void System::WindowsCreateTesting::MenuTest()
{
    String className{};
    ASSERT_TRUE(GetSystemClassName(hwnd, className));

    constexpr auto width = 800;
    constexpr auto high = 600;
    WindowsRect rect{ 0, 0, width, high };

    ASSERT_TRUE(AdjustSystemWindowRect(&rect, WindowsStyles::OverlappedWindow));
    ASSERT_LESS_EQUAL(width, abs(rect.right - rect.left));
    ASSERT_LESS_EQUAL(high, abs(rect.top - rect.bottom));

    const auto windowsName = SYSTEM_TEXT("Test Windows"s);
    auto systemWindow = CreateSystemWindow(className, windowsName, WindowsStyles::Default, 0, 0, rect, nullptr, nullptr, instance);

    ASSERT_UNEQUAL_NULL_PTR(systemWindow);

    ASSERT_TRUE(RemoveMenuCloseButton(systemWindow));

    auto menu = GetWindowSystemMenu(systemWindow);

    ASSERT_UNEQUAL_NULL_PTR(menu);

    ASSERT_TRUE(RemoveSystemMenu(menu, SystemMenuCommand::Minimize, MenuItem::ByCommand));

    ASSERT_TRUE(DestroySystemWindow(systemWindow));
}
