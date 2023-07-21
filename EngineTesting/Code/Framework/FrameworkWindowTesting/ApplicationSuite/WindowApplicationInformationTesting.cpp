///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/13 23:10)

#include "WindowApplicationInformationTesting.h"
#include "resource.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Windows/Flags/WindowsFlags.h"
#include "System/Windows/Using/WindowsRegistryUsing.h"
#include "System/Windows/WindowsRegister.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Base/MathDetail.h"
#include "Framework/Application/WindowApplicationInformation.h"
#include "Framework/WindowCreate/WindowPoint.h"
#include "Framework/WindowCreate/WindowSize.h"

using namespace std::literals;

namespace Framework
{
    using TestingType = WindowApplicationInformation;
}

Framework::WindowApplicationInformationTesting::WindowApplicationInformationTesting(const OStreamShared& stream, HInstance instance)
    : ParentType{ stream }, instance{ instance }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, WindowApplicationInformationTesting)

void Framework::WindowApplicationInformationTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Framework::WindowApplicationInformationTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(InformationTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AllowResizeTest);
    ASSERT_NOT_THROW_EXCEPTION_0(NotAllowedResizeTest);
    ASSERT_NOT_THROW_EXCEPTION_0(RendererParameterTest);
}

void Framework::WindowApplicationInformationTesting::InformationTest()
{
    constexpr auto width = 1024;
    constexpr auto height = 768;
    const WindowSize size{ width, height };

    constexpr auto x = 100;
    constexpr auto y = 120;
    constexpr WindowPoint point{ x, y };

    auto windowTitle = SYSTEM_TEXT("WindowApplicationInformation"s);
    auto windowName = SYSTEM_TEXT("Window"s);

    WindowPictorial windowPictorial{ System::WindowsBrushTypes::WhiteBrush };

    TestingType information{ windowTitle, size };

    ASSERT_EQUAL(information.GetWindowTitle(), windowTitle);
    ASSERT_EQUAL(information.GetWindowTitleWithMultiByte(), "WindowApplicationInformation"s);

    ASSERT_EQUAL(information.GetXPosition(), 0);
    ASSERT_EQUAL(information.GetYPosition(), 0);
    ASSERT_EQUAL(information.GetWidth(), width);
    ASSERT_EQUAL(information.GetHeight(), height);
    ASSERT_EQUAL(information.GetWindowSize(), size);
    ASSERT_APPROXIMATE(information.GetAspectRatio(), boost::numeric_cast<float>(width) / boost::numeric_cast<float>(height), Mathematics::MathF::epsilon);
    ASSERT_ENUM_EQUAL(information.GetStyle(), System::WindowsStyles::Default);
    ASSERT_EQUAL(information.GetWindowName().GetWindowClassName(), windowName);
    ASSERT_TRUE(information.GetWindowName().GetWindowMenuName().empty());

    ASSERT_EQUAL(information.GetWindowPictorial().GetHBrush(), windowPictorial.GetHBrush());
    ASSERT_EQUAL(information.GetWindowPictorial().GetHCursor(), windowPictorial.GetHCursor());
    ASSERT_EQUAL(information.GetWindowPictorial().GetHIcon(), windowPictorial.GetHIcon());

    const WindowSize newSize{ height, width };
    information.SetWindowSize(newSize);

    ASSERT_EQUAL(information.GetWidth(), newSize.GetWindowWidth());
    ASSERT_EQUAL(information.GetHeight(), newSize.GetWindowHeight());
    ASSERT_EQUAL(information.GetWindowSize(), newSize);
}

void Framework::WindowApplicationInformationTesting::AllowResizeTest()
{
    constexpr auto width = 1024;
    constexpr auto height = 768;
    const WindowSize size{ width, height };

    constexpr auto x = 100;
    constexpr auto y = 120;
    constexpr WindowPoint point{ x, y };

    auto windowTitle = SYSTEM_TEXT("WindowApplicationInformation"s);
    auto windowName = SYSTEM_TEXT("Window"s);

    WindowPictorial windowPictorial{ System::WindowsBrushTypes::WhiteBrush };

    TestingType information{ windowTitle, size, point, true };

    ASSERT_EQUAL(information.GetWindowTitle(), windowTitle);
    ASSERT_EQUAL(information.GetWindowTitleWithMultiByte(), "WindowApplicationInformation"s);

    ASSERT_EQUAL(information.GetXPosition(), x);
    ASSERT_EQUAL(information.GetYPosition(), y);
    ASSERT_EQUAL(information.GetWidth(), width);
    ASSERT_EQUAL(information.GetHeight(), height);
    ASSERT_EQUAL(information.GetWindowSize(), size);
    ASSERT_APPROXIMATE(information.GetAspectRatio(), boost::numeric_cast<float>(width) / boost::numeric_cast<float>(height), Mathematics::MathF::epsilon);
    ASSERT_ENUM_EQUAL(information.GetStyle(), System::WindowsStyles::Default);
    ASSERT_EQUAL(information.GetWindowName().GetWindowClassName(), windowName);
    ASSERT_TRUE(information.GetWindowName().GetWindowMenuName().empty());

    ASSERT_EQUAL(information.GetWindowPictorial().GetHBrush(), windowPictorial.GetHBrush());
    ASSERT_EQUAL(information.GetWindowPictorial().GetHCursor(), windowPictorial.GetHCursor());
    ASSERT_EQUAL(information.GetWindowPictorial().GetHIcon(), windowPictorial.GetHIcon());
}

void Framework::WindowApplicationInformationTesting::NotAllowedResizeTest()
{
    constexpr auto width = 1024;
    constexpr auto height = 768;
    const WindowSize size{ width, height };

    constexpr auto x = 100;
    constexpr auto y = 120;
    constexpr WindowPoint point{ x, y };

    auto windowTitle = SYSTEM_TEXT("WindowApplicationInformation"s);
    auto windowName = SYSTEM_TEXT("Window"s);

    WindowPictorial windowPictorial{ System::WindowsBrushTypes::WhiteBrush };

    TestingType information{ windowTitle, size, point, false };

    ASSERT_EQUAL(information.GetWindowTitle(), windowTitle);
    ASSERT_EQUAL(information.GetWindowTitleWithMultiByte(), "WindowApplicationInformation"s);

    ASSERT_EQUAL(information.GetXPosition(), x);
    ASSERT_EQUAL(information.GetYPosition(), y);
    ASSERT_EQUAL(information.GetWidth(), width);
    ASSERT_EQUAL(information.GetHeight(), height);
    ASSERT_EQUAL(information.GetWindowSize(), size);
    ASSERT_APPROXIMATE(information.GetAspectRatio(), boost::numeric_cast<float>(width) / boost::numeric_cast<float>(height), Mathematics::MathF::epsilon);
    ASSERT_ENUM_EQUAL(information.GetStyle(), System::WindowsStyles::Overlapped | System::WindowsStyles::Caption | System::WindowsStyles::SysMenu | System::WindowsStyles::MinimizeBox | System::WindowsStyles::Visible);
    ASSERT_EQUAL(information.GetWindowName().GetWindowClassName(), windowName);
    ASSERT_TRUE(information.GetWindowName().GetWindowMenuName().empty());

    ASSERT_EQUAL(information.GetWindowPictorial().GetHBrush(), windowPictorial.GetHBrush());
    ASSERT_EQUAL(information.GetWindowPictorial().GetHCursor(), windowPictorial.GetHCursor());
    ASSERT_EQUAL(information.GetWindowPictorial().GetHIcon(), windowPictorial.GetHIcon());
}

void Framework::WindowApplicationInformationTesting::RendererParameterTest() noexcept
{

}
