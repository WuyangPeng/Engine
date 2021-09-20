// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.3.0.2 (2020/06/05 21:10)

#include "WindowProcessHandleTesting.h"
#include "System/Window/WindowCreate.h"
#include "System/Time/Using/DeltaTimeUsing.h" 
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/MainFunctionHelper/EnvironmentDirectory.h"
#include "Framework/WindowProcess/WindowProcessManager.h"
#include "Framework/WindowProcess/WindowProcessHandleDetail.h"

using std::const_pointer_cast;
using namespace std::literals;

namespace Framework
{
	using TestingType = WindowProcessInterface;
}

Framework::WindowProcessHandleTesting
	::WindowProcessHandleTesting(const OStreamShared& stream, HWnd hwnd)
	:ParentType{ stream }, m_Hwnd{ hwnd }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, WindowProcessHandleTesting)

void Framework::WindowProcessHandleTesting
	::DoRunUnitTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Framework::WindowProcessHandleTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(BaseTest);
	ASSERT_NOT_THROW_EXCEPTION_0(ClassNameTest);
	ASSERT_NOT_THROW_EXCEPTION_0(HWndTest);
}

void Framework::WindowProcessHandleTesting
	::BaseTest()
{
	TestingType process{ System::g_Microseconds / 60 };

	ASSERT_UNEQUAL_NULL_PTR(process.GetFunction());
	ASSERT_UNEQUAL_NULL_PTR(process.GetProcess());

	EnvironmentDirectory environmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"s), SYSTEM_TEXT(""s) };

	ASSERT_TRUE(process.PreCreate(environmentDirectory));
	ASSERT_TRUE(process.Initialize());
	process.PreIdle();
	process.Terminate();	
}

void Framework::WindowProcessHandleTesting
	::ClassNameTest()
{
	System::String className{ };
    [[maybe_unused]] auto value = System::GetSystemClassName(m_Hwnd, className);

	TestingType process{ System::g_Microseconds / 60 };

	ASSERT_TRUE(process.IsClassNameExist(className));

	auto newClassName = SYSTEM_TEXT("New Class"s);

	process.SetNewClassName(newClassName);

	ASSERT_TRUE(process.IsClassNameExist(newClassName));
}

void Framework::WindowProcessHandleTesting
	::HWndTest()
{
	TestingType process{ System::g_Microseconds / 60 };

	ASSERT_EQUAL_NULL_PTR(process.GetMainWindowHwnd());
}



