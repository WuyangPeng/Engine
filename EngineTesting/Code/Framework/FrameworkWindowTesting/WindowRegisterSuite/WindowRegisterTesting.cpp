// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.3.0.2 (2020/06/11 0:11)

#include "WindowRegisterTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/WindowProcess/WindowProcessHandleDetail.h"
#include "Framework/WindowRegister/WindowRegisterHandleDetail.h"

using namespace std::literals;

Framework::WindowRegisterTesting
	::WindowRegisterTesting(const OStreamShared& stream, HInstance instance)
	:ParentType{ stream }, m_Instance{ instance }, m_Count{ 0 }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool Framework::WindowRegisterTesting
	::IsValid() const noexcept
{
	if (ParentType::IsValid() && m_Instance != nullptr)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

void Framework::WindowRegisterTesting
	::DoRunUnitTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Framework::WindowRegisterTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(RegisterTest);
}

void Framework::WindowRegisterTesting
	::RegisterTest()
{
	const auto windowClassName = SYSTEM_TEXT("RegisterTestingClassName"s);
	const auto windowMenuName = SYSTEM_TEXT("RegisterTestingMenuName"s);

	auto newWindowClassName = windowClassName + System::ToString(m_Count++);

	EnvironmentDirectory environmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") };
	WindowPictorial windowPictorial{ System::WindowsBrushTypes::WhiteBrush };
	WindowName windowName{ newWindowClassName, windowMenuName };
	WindowRegisterHandle<WindowProcessInterface> windowRegister{ environmentDirectory, m_Instance, "",windowPictorial,windowName };

	ASSERT_EQUAL(windowRegister.GetHInstance(), m_Instance);
	ASSERT_EQUAL(windowRegister.GetWindowClassName(), newWindowClassName);
	ASSERT_EQUAL(windowRegister.GetWindowMenuName(), windowMenuName);
	ASSERT_UNEQUAL_NULL_PTR(windowRegister.GetCommand());

	auto windowProcess = windowRegister.GetWindowProcess();
	ASSERT_UNEQUAL_NULL_PTR(windowRegister.GetFunction());
	ASSERT_EQUAL(windowProcess.GetFunction(), windowRegister.GetFunction());	
}
