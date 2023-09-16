///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/31 15:21)

#include "RegisterClassTesting.h"
#include "System/Helper/WindowsMacro.h"
#include "System/SystemWindowsTesting/resource.h"
#include "System/Windows/Flags/WindowsClassStyleFlags.h"
#include "System/Windows/WindowsRegister.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Framework/WindowProcess/WindowProcessManager.h"

using namespace std::literals;

System::RegisterClassTesting::RegisterClassTesting(const OStreamShared& stream, WindowsHInstance instance)
    : ParentType{ stream }, instance{ instance }, count{ 0 }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, RegisterClassTesting)

void System::RegisterClassTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::RegisterClassTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(RegisterClassTest);
}

void System::RegisterClassTesting::RegisterClassTest()
{
    const auto windowClassName = SYSTEM_TEXT("RegisterTestingClassName"s);
    const auto windowMenuName = SYSTEM_TEXT("RegisterTestingMenuName"s);
    const auto newWindowMenuName = windowClassName + ToString(count++);

    WindowsClassEx windowsClassEx{};

    windowsClassEx.cbSize = sizeof(WindowsClassEx);
    windowsClassEx.style = EnumCastUnderlying(WindowsClassStyle::CommonUse);
    windowsClassEx.lpfnWndProc = WINDOW_PROCESS_MANAGER_SINGLETON.GetProcess();
    windowsClassEx.cbClsExtra = 0;
    windowsClassEx.cbWndExtra = 0;
    windowsClassEx.hInstance = instance;
    windowsClassEx.hIcon = LoadSystemIcon(instance, MakeIntreSource(IDI_TEST_ICON));
    windowsClassEx.hCursor = LoadSystemCursor(instance, MakeIntreSource(IDC_TEST_CURSOR));
    windowsClassEx.hbrBackground = nullptr;
    windowsClassEx.lpszMenuName = windowMenuName.c_str();
    windowsClassEx.lpszClassName = newWindowMenuName.c_str();
    windowsClassEx.hIconSm = LoadSystemIcon(instance, MakeIntreSource(IDI_TEST_ICON));

    ASSERT_UNEQUAL(RegisterSystemClass(&windowsClassEx), 0);
}
