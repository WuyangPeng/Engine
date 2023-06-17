///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/12 15:44)

#include "WindowsParameterTesting.h"
#include "System/Windows/Flags/WindowsPictorialFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Rendering/DataTypes/ColourDetail.h"
#include "Rendering/Renderers/WindowsParameter.h"

using namespace std::literals;

Rendering::WindowsParameterTesting::WindowsParameterTesting(const OStreamShared& stream)
    : ParentType{ stream },
      colour{ 0.0f, 0.0f, 0.0f, 1.0f },
      windowTitle{},
      windowX{ 0 },
      windowY{ 0 },
      isAllowResize{ true },
      className{},
      menuName{},
      icon{ 0 },
      isIconDefault{ false },
      cursor{ 0 },
      isCursorDefault{ false },
      background{ WindowsBrushTypes::Null }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, WindowsParameterTesting)

void Rendering::WindowsParameterTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Rendering::WindowsParameterTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(AccessTest);
}

void Rendering::WindowsParameterTesting::AccessTest()
{
    auto windowsParameter = WindowsParameter::Create();
    ASSERT_NOT_THROW_EXCEPTION_1(ExecuteTest, windowsParameter);

    ASSERT_NOT_THROW_EXCEPTION_1(SetClearColorTest, windowsParameter);
    ASSERT_NOT_THROW_EXCEPTION_1(SetWindowParameterTest, windowsParameter);
    ASSERT_NOT_THROW_EXCEPTION_1(SetWindowClassNameTest, windowsParameter);
    ASSERT_NOT_THROW_EXCEPTION_1(SetWindowMenuNameTest, windowsParameter);
    ASSERT_NOT_THROW_EXCEPTION_1(SetWindowPictorialParameterTest, windowsParameter);
}

void Rendering::WindowsParameterTesting::ExecuteTest(const WindowsParameter& windowsParameter)
{
    ASSERT_TRUE(Approximate(windowsParameter.GetClearColor(), colour, 1e-8f));

    ASSERT_EQUAL(windowsParameter.GetWindowTitle(), windowTitle);
    ASSERT_EQUAL(windowsParameter.GetXPosition(), windowX);
    ASSERT_EQUAL(windowsParameter.GetYPosition(), windowY);
    ASSERT_EQUAL(windowsParameter.IsAllowResize(), isAllowResize);

    ASSERT_EQUAL(windowsParameter.GetWindowClassName(), className);
    ASSERT_EQUAL(windowsParameter.GetWindowMenuName(), menuName);

    ASSERT_EQUAL(windowsParameter.GetIcon(), icon);
    ASSERT_EQUAL(windowsParameter.IsIconDefault(), isIconDefault);
    ASSERT_EQUAL(windowsParameter.GetCursor(), cursor);
    ASSERT_EQUAL(windowsParameter.IsCursorDefault(), isCursorDefault);
    ASSERT_ENUM_EQUAL(windowsParameter.GetBackground(), background);
}

void Rendering::WindowsParameterTesting::SetClearColorTest(WindowsParameter& windowsParameter)
{
    colour.SetColour(1.0f, 0.3f, 0.5f, 0.4f);
    windowsParameter.SetClearColor(colour.GetRed(), colour.GetGreen(), colour.GetBlue(), colour.GetAlpha());
    ASSERT_NOT_THROW_EXCEPTION_1(ExecuteTest, windowsParameter);
}

void Rendering::WindowsParameterTesting::SetWindowParameterTest(WindowsParameter& windowsParameter)
{
    windowTitle = "windowTitle";
    windowX = 10;
    windowY = 110;
    isAllowResize = false;
    windowsParameter.SetWindowParameter(windowTitle, windowX, windowY, isAllowResize);
    ASSERT_NOT_THROW_EXCEPTION_1(ExecuteTest, windowsParameter);
}

void Rendering::WindowsParameterTesting::SetWindowClassNameTest(WindowsParameter& windowsParameter)
{
    className = SYSTEM_TEXT("className"s);
    windowsParameter.SetWindowClassName(className);
    ASSERT_NOT_THROW_EXCEPTION_1(ExecuteTest, windowsParameter);
}

void Rendering::WindowsParameterTesting::SetWindowMenuNameTest(WindowsParameter& windowsParameter)
{
    menuName = SYSTEM_TEXT("menuName"s);
    windowsParameter.SetWindowMenuName(menuName);
    ASSERT_NOT_THROW_EXCEPTION_1(ExecuteTest, windowsParameter);
}

void Rendering::WindowsParameterTesting::SetWindowPictorialParameterTest(WindowsParameter& windowsParameter)
{
    icon = 1;
    isIconDefault = true;
    cursor = 2;
    isCursorDefault = true;
    background = WindowsBrushTypes::WhiteBrush;
    windowsParameter.SetWindowPictorialParameter(icon, isIconDefault, cursor, isCursorDefault, background);
    ASSERT_NOT_THROW_EXCEPTION_1(ExecuteTest, windowsParameter);
}
