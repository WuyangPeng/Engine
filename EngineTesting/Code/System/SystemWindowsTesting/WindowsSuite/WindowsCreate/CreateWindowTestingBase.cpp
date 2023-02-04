///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.1 (2023/02/02 19:46)

#include "CreateWindowTestingBase.h"
#include "System/Windows/Flags/WindowsFlags.h"
#include "System/Windows/WindowsCreate.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

System::CreateWindowTestingBase::CreateWindowTestingBase(const OStreamShared& stream, WindowsHInstance instance, WindowsHWnd hwnd)
    : ParentType{ stream }, instance{ instance }, hwnd{ hwnd }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, CreateWindowTestingBase)

System::String System::CreateWindowTestingBase::GetWindowsName()
{
    return SYSTEM_TEXT("Test Windows"s);
}

System::String System::CreateWindowTestingBase::GetWindowsClassName()
{
    SYSTEM_CLASS_IS_VALID_1;

    String className{};
    ASSERT_TRUE(GetSystemClassName(hwnd, className));

    return className;
}

System::WindowsHWnd System::CreateWindowTestingBase::CreateWindowTest(const String& className)
{
    SYSTEM_CLASS_IS_VALID_1;

    constexpr auto width = 800;
    constexpr auto high = 600;
    WindowsRect rect{ 0, 0, width, high };

    ASSERT_TRUE(AdjustSystemWindowRect(&rect, WindowsStyles::OverlappedWindow));
    ASSERT_LESS_EQUAL(width, abs(rect.right - rect.left));
    ASSERT_LESS_EQUAL(high, abs(rect.top - rect.bottom));

    auto systemWindow = CreateSystemWindow(className, GetWindowsName(), WindowsStyles::Default, 0, 0, rect, nullptr, nullptr, instance);

    return systemWindow;
}
