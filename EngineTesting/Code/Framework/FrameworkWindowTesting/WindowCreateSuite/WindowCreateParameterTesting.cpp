// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.4 (2019/09/16 14:33)

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
    : ParentType{ stream }, m_Hwnd{ hwnd }
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

    TestingType parameter{ windowsName, style, m_Hwnd, menu, leftTopCorner };

    ASSERT_EQUAL(parameter.GetWindowsName(), windowsName);
    ASSERT_ENUM_EQUAL(parameter.GetStyle(), style);
    ASSERT_EQUAL(parameter.GetParent(), m_Hwnd);
    ASSERT_EQUAL(parameter.GetMenu(), menu);
    ASSERT_EQUAL(parameter.GetLeftTopCorner(), leftTopCorner);
}