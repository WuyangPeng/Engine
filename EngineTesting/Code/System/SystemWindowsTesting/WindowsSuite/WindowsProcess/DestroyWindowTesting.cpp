///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.1 (2023/02/02 21:06)

#include "DestroyWindowTesting.h"
#include "System/Windows/Flags/WindowsFlags.h"
#include "System/Windows/WindowsCreate.h"
#include "System/Windows/WindowsProcess.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

System::DestroyWindowTesting::DestroyWindowTesting(const OStreamShared& stream, WindowsHWnd hwnd)
    : ParentType{ stream }, hwnd{ hwnd }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, DestroyWindowTesting)

void System::DestroyWindowTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::DestroyWindowTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(DestroyWindowTest);
}

void System::DestroyWindowTesting::DestroyWindowTest()
{
    String className{};
    const auto windowsName = SYSTEM_TEXT("Not Displayed Windows"s);
    ASSERT_TRUE(GetSystemClassName(hwnd, className));

    constexpr auto width = 800;
    constexpr auto high = 600;
    WindowsRect rect{ 0, 0, width, high };

    const auto result = CreateSystemWindow(className, windowsName, WindowsStyles::Default, 0, 0, rect, nullptr, nullptr, GetHInstance());

    ASSERT_TRUE(DestroySystemWindow(result));
}
