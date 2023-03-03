///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.3 (2023/03/01 15:48)

#include "ConsoleColorsTesting.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::ConsoleColorsTesting::ConsoleColorsTesting(const OStreamShared& stream)
    : ParentType{ stream }, console{ OutputConsoleColors::Create() }
{
#if !defined(TCRE_USE_GCC)

    COUT.imbue(std::locale("chs"));
    CERR.imbue(std::locale("chs"));

#endif  // TCRE_USE_GCC

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, ConsoleColorsTesting)

void CoreTools::ConsoleColorsTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::ConsoleColorsTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(IntensifiedColorsTest);
    ASSERT_NOT_THROW_EXCEPTION_0(BlackBackgroundColorTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ColorsTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ResetColorsTest);
}

void CoreTools::ConsoleColorsTesting::IntensifiedColorsTest()
{
    ASSERT_NOT_THROW_EXCEPTION_2(SetColorsTest, TextColour::Red, BackgroundColour::Yellow);
    GetStream() << "这条信息在控制台中文本显示为红色，背景为黄色。\n";

    ASSERT_NOT_THROW_EXCEPTION_2(SetIntensifiedTextColorsTest, TextColour::Red, BackgroundColour::Yellow);
    GetStream() << "这条信息在控制台中文本显示为加深的红色，背景为黄色。\n";

    ASSERT_NOT_THROW_EXCEPTION_2(SetIntensifiedBackgroundColorsTest, TextColour::Red, BackgroundColour::Yellow);
    GetStream() << "这条信息在控制台中文本显示为红色，背景为加深的黄色。\n";
}

void CoreTools::ConsoleColorsTesting::SetColorsTest(TextColour textColor, BackgroundColour backgroundColor)
{
    console.SetTextColor(textColor);
    console.SetBackgroundColor(backgroundColor);
}

void CoreTools::ConsoleColorsTesting::SetIntensifiedTextColorsTest(TextColour textColor, BackgroundColour backgroundColor)
{
    console.SetTextIntensifiedColor(textColor);
    console.SetBackgroundColor(backgroundColor);
}

void CoreTools::ConsoleColorsTesting::SetIntensifiedBackgroundColorsTest(TextColour textColor, BackgroundColour backgroundColor)
{
    console.SetTextColor(textColor);
    console.SetBackgroundIntensifiedColor(backgroundColor);
}

void CoreTools::ConsoleColorsTesting::BlackBackgroundColorTest()
{
    ASSERT_NOT_THROW_EXCEPTION_2(SetColorsTest, TextColour::Magenta, BackgroundColour::Black);
    GetStream() << "这条信息在控制台中文本显示为紫色，背景为黑色。\n";
}

void CoreTools::ConsoleColorsTesting::ColorsTest()
{
    ASSERT_NOT_THROW_EXCEPTION_2(SetColorsTest, TextColour::Green, BackgroundColour::Magenta);
    GetStream() << "这条信息在控制台中文本显示为绿色，背景为紫色。\n";

    ASSERT_NOT_THROW_EXCEPTION_2(SetColorsTest, TextColour::Blue, BackgroundColour::Red);
    GetStream() << "这条信息在控制台中文本显示为蓝色，背景为红色。\n";
}

void CoreTools::ConsoleColorsTesting::ResetColorsTest()
{
    console.ResetColor();

    GetStream() << "这条信息在控制台中文本显示为白色，背景为黑色。\n";
}
