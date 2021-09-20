// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.3.0.2 (2020/06/04 21:56)

#include "WindowProcessManagerTesting.h"
#include "System/Window/WindowCreate.h"
#include "System/Time/Using/DeltaTimeUsing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h" 
#include "Framework/WindowCreate/WindowSize.h"
#include "Framework/WindowCreate/WindowCreateHandle.h"
#include "Framework/WindowCreate/WindowCreateParameter.h"
#include "Framework/WindowCreate/WindowInstanceParameter.h"
#include "Framework/WindowProcess/WindowProcessManager.h"
#include "Framework/MainFunctionHelper/EnvironmentDirectory.h" 

using std::const_pointer_cast;
using namespace std::literals;

Framework::WindowProcessManagerTesting
	::WindowProcessManagerTesting(const OStreamShared& stream, HWnd hwnd)
	:ParentType{ stream }, m_Hwnd{ hwnd }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
} 

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework,WindowProcessManagerTesting)

void Framework::WindowProcessManagerTesting
	::DoRunUnitTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Framework::WindowProcessManagerTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(ManagerTest);
	ASSERT_NOT_THROW_EXCEPTION_0(ClassNameTest);
	ASSERT_NOT_THROW_EXCEPTION_0(SetMainWindow);
}

void Framework::WindowProcessManagerTesting
	::ManagerTest()
{
	ASSERT_UNEQUAL_NULL_PTR(WINDOW_PROCESS_MANAGER_SINGLETON.GetProcess());
	ASSERT_UNEQUAL_NULL_PTR(WINDOW_PROCESS_MANAGER_SINGLETON.GetFunction());

	auto windowMessage1 = const_pointer_cast<WindowMessageInterface>(WINDOW_PROCESS_MANAGER_SINGLETON.GetWindowMessageInterface());

	ASSERT_UNEQUAL_NULL_PTR(windowMessage1);

	WINDOW_PROCESS_MANAGER_SINGLETON.ClearWindowMessage(windowMessage1);
	WINDOW_PROCESS_MANAGER_SINGLETON.SetWindowMessage(windowMessage1);

	auto windowMessage2 = WINDOW_PROCESS_MANAGER_SINGLETON.GetWindowMessageInterface();

	ASSERT_EQUAL(windowMessage1, windowMessage2);

	EnvironmentDirectory environmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"s), SYSTEM_TEXT(""s) };
	ASSERT_TRUE(WINDOW_PROCESS_MANAGER_SINGLETON.PreCreate(environmentDirectory));
	ASSERT_TRUE(WINDOW_PROCESS_MANAGER_SINGLETON.Initialize());

	WINDOW_PROCESS_MANAGER_SINGLETON.PreIdle();
	WINDOW_PROCESS_MANAGER_SINGLETON.Terminate();
}

void Framework::WindowProcessManagerTesting
	::ClassNameTest()
{
	System::String className{ };
    [[maybe_unused]] auto value = System::GetSystemClassName(m_Hwnd, className);

	ASSERT_TRUE(WINDOW_PROCESS_MANAGER_SINGLETON.IsClassNameExist(className));

	System::String newClassName{ SYSTEM_TEXT("New Class"s) };

	WINDOW_PROCESS_MANAGER_SINGLETON.SetNewClassName(newClassName);

	ASSERT_TRUE(WINDOW_PROCESS_MANAGER_SINGLETON.IsClassNameExist(newClassName));
}

void Framework::WindowProcessManagerTesting
	::SetMainWindow()
{
	System::String className{ };
    [[maybe_unused]] auto value = System::GetSystemClassName(m_Hwnd, className);

	auto instance = System::GetHInstance();
	auto windowName = SYSTEM_TEXT("Not Displayed Window"s);

	const WindowSize size{ 800, 600 };
	WindowCreateParameter createParameter{ windowName };
	WindowInstanceParameter instanceParameter{ instance, className };
	WindowCreateHandle create{ instanceParameter, createParameter, size };

	ASSERT_EQUAL(WINDOW_PROCESS_MANAGER_SINGLETON.GetMainWindowHwnd(), m_Hwnd);

	WINDOW_PROCESS_MANAGER_SINGLETON.SetMainWindowHwnd(create.GetHwnd());
	ASSERT_EQUAL(WINDOW_PROCESS_MANAGER_SINGLETON.GetMainWindowHwnd(), create.GetHwnd());
	
	WINDOW_PROCESS_MANAGER_SINGLETON.SetMainWindowHwnd(m_Hwnd);

	constexpr auto delta = System::g_Microseconds / 60;
	WindowMessageInterface message{ delta };

	ASSERT_EQUAL(message.CreateMessage(create.GetHwnd(), 0, 0), 0);
	ASSERT_EQUAL(message.CloseMessage(create.GetHwnd(), 0, 0), 0);
}

