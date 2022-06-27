///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.9 (2022/06/27 14:16)

#include "WindowCreateParameterTesting.h"
#include "CoreTools/Contract/Noexcept.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/WindowCreate/WindowCreateParameter.h"
#include "Framework/WindowCreate/WindowPoint.h"

using namespace std::literals;

namespace Framework
{
    using TestingType = WindowCreateParameter;
}

Framework::WindowCreateParameterTesting::WindowCreateParameterTesting(const OStreamShared& stream, HWnd hwnd)
    : ParentType{ stream }, hwnd{ hwnd }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, WindowCreateParameterTesting)

void Framework::WindowCreateParameterTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Framework::WindowCreateParameterTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ValueTest);
}

void Framework::WindowCreateParameterTesting::ValueTest()
{
    const auto windowsName = SYSTEM_TEXT("WindowsName"s);
    const auto style = System::WindowsStyles::OverlappedWindow | System::WindowsStyles::Visible;
    const WindowPoint leftTopCorner{};
    constexpr auto menu = nullptr;

    TestingType parameter{ windowsName, style, hwnd, menu, leftTopCorner };

    ASSERT_EQUAL(parameter.GetWindowsName(), windowsName);
    ASSERT_ENUM_EQUAL(parameter.GetStyle(), style);
    ASSERT_EQUAL(parameter.GetParent(), hwnd);
    ASSERT_EQUAL(parameter.GetMenu(), menu);
    ASSERT_EQUAL(parameter.GetLeftTopCorner(), leftTopCorner);
}