/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/16 15:07)

#include "ConsoleColorsTesting.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <iostream>

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
    GetStream() << "������Ϣ�ڿ���̨���ı���ʾΪ��ɫ������Ϊ��ɫ��\n";

    ASSERT_NOT_THROW_EXCEPTION_2(SetIntensifiedTextColorsTest, TextColour::Red, BackgroundColour::Yellow);
    GetStream() << "������Ϣ�ڿ���̨���ı���ʾΪ����ĺ�ɫ������Ϊ��ɫ��\n";

    ASSERT_NOT_THROW_EXCEPTION_2(SetIntensifiedBackgroundColorsTest, TextColour::Red, BackgroundColour::Yellow);
    GetStream() << "������Ϣ�ڿ���̨���ı���ʾΪ��ɫ������Ϊ����Ļ�ɫ��\n";
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
    GetStream() << "������Ϣ�ڿ���̨���ı���ʾΪ��ɫ������Ϊ��ɫ��\n";
}

void CoreTools::ConsoleColorsTesting::ColorsTest()
{
    ASSERT_NOT_THROW_EXCEPTION_2(SetColorsTest, TextColour::Green, BackgroundColour::Magenta);
    GetStream() << "������Ϣ�ڿ���̨���ı���ʾΪ��ɫ������Ϊ��ɫ��\n";

    ASSERT_NOT_THROW_EXCEPTION_2(SetColorsTest, TextColour::Blue, BackgroundColour::Red);
    GetStream() << "������Ϣ�ڿ���̨���ı���ʾΪ��ɫ������Ϊ��ɫ��\n";
}

void CoreTools::ConsoleColorsTesting::ResetColorsTest()
{
    console.ResetColor();

    GetStream() << "������Ϣ�ڿ���̨���ı���ʾΪ��ɫ������Ϊ��ɫ��\n";
}
