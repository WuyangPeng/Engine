///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/13 23:08)

#include "WindowRegisterTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Framework/WindowProcess/WindowProcessHandleDetail.h"
#include "Framework/WindowRegister/WindowRegisterHandleDetail.h"

using namespace std::literals;

Framework::WindowRegisterTesting::WindowRegisterTesting(const OStreamShared& stream, HInstance instance)
    : ParentType{ stream }, instance{ instance }, count{ 0 }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool Framework::WindowRegisterTesting::IsValid() const noexcept
{
    if (ParentType::IsValid() && instance != nullptr)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

void Framework::WindowRegisterTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Framework::WindowRegisterTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(RegisterTest);
}

void Framework::WindowRegisterTesting::RegisterTest()
{
    const auto windowClassName = SYSTEM_TEXT("RegisterTestingClassName"s);
    const auto windowMenuName = SYSTEM_TEXT("RegisterTestingMenuName"s);

    auto newWindowClassName = windowClassName + System::ToString(count++);

    EnvironmentDirectory environmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") };
    WindowPictorial windowPictorial{ System::WindowsBrushTypes::WhiteBrush };
    WindowName windowName{ newWindowClassName, windowMenuName };
    WindowRegisterHandle<WindowProcessInterface> windowRegister{ environmentDirectory, instance, "", windowPictorial, windowName };

    ASSERT_EQUAL(windowRegister.GetHInstance(), instance);
    ASSERT_EQUAL(windowRegister.GetWindowClassName(), newWindowClassName);
    ASSERT_EQUAL(windowRegister.GetWindowMenuName(), windowMenuName);
    ASSERT_UNEQUAL_NULL_PTR(windowRegister.GetCommand());

    auto windowProcess = windowRegister.GetWindowProcess();
    ASSERT_UNEQUAL_NULL_PTR(windowRegister.GetFunction());
    ASSERT_EQUAL(windowProcess.GetFunction(), windowRegister.GetFunction());
}
