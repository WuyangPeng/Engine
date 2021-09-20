// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.3.0.2 (2020/06/03 16:20)

#include "WindowCreateHandleTesting.h"
#include "System/Window/WindowCreate.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/WindowCreate/WindowCreate.h"
#include "Framework/WindowCreate/WindowCreateParameter.h"
#include "Framework/WindowCreate/WindowInstanceParameter.h"
#include "Framework/WindowCreate/WindowSize.h"
#include "Framework/WindowProcess/WindowProcessManager.h"

using namespace std::literals;

namespace Framework
{
    using TestingType = WindowCreateHandle;
}

Framework::WindowCreateHandleTesting ::WindowCreateHandleTesting(const OStreamShared& stream, HInstance instance, HWnd hwnd)
    : ParentType{ stream }, m_Instance{ instance }, m_Hwnd{ hwnd }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, WindowCreateHandleTesting)

void Framework::WindowCreateHandleTesting ::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Framework::WindowCreateHandleTesting ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CreateTest);
}

void Framework::WindowCreateHandleTesting ::CreateTest()
{
    System::String className{};
    [[maybe_unused]] auto value = System::GetSystemClassName(m_Hwnd, className);
    auto windowName = SYSTEM_TEXT("New Main Window"s);

    const WindowSize size{ 800, 600 };
    WindowCreateParameter createParameter{ windowName };
    WindowInstanceParameter instanceParameter{ m_Instance, className };

    auto oldHwnd = WINDOW_PROCESS_MANAGER_SINGLETON.GetMainWindowHwnd();

    TestingType create{ instanceParameter, createParameter, size };
    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(create.GetHwnd(), "¥¥Ω®¥∞ø⁄ ß∞‹£°");

    create.SetMainWindow();

    ASSERT_EQUAL(WINDOW_PROCESS_MANAGER_SINGLETON.GetMainWindowHwnd(), create.GetHwnd());

    WINDOW_PROCESS_MANAGER_SINGLETON.SetMainWindowHwnd(oldHwnd);
}
