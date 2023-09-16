///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/08/31 16:37)

#include "ConsoleColourTesting.h"
#include "System/Console/ConsoleColour.h"
#include "System/Console/ConsoleHandle.h"
#include "System/Console/Flags/ConsoleColoursFlags.h"
#include "System/Console/Flags/ConsoleHandleFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::ConsoleColourTesting::ConsoleColourTesting(const OStreamShared& stream)
    : ParentType{ stream },
      textColourDescription{ { TextColour::Black, "��ɫ" },
                             { TextColour::Red, "��ɫ" },
                             { TextColour::Green, "��ɫ" },
                             { TextColour::Blue, "��ɫ" },
                             { TextColour::Yellow, "��ɫ" },
                             { TextColour::Cyan, "��ɫ" },
                             { TextColour::Magenta, "Ʒ��ɫ" },
                             { TextColour::White, "��ɫ" },
                             { TextColour::IntensifiedBlack, "������ɫ" },
                             { TextColour::IntensifiedRed, "������ɫ" },
                             { TextColour::IntensifiedGreen, "������ɫ" },
                             { TextColour::IntensifiedBlue, "������ɫ" },
                             { TextColour::IntensifiedYellow, "������ɫ" },
                             { TextColour::IntensifiedCyan, "������ɫ" },
                             { TextColour::IntensifiedMagenta, "����Ʒ��ɫ" },
                             { TextColour::IntensifiedWhite, "������ɫ" } },
      backgroundColourDescription{ { BackgroundColour::Black, "��ɫ" },
                                   { BackgroundColour::Red, "��ɫ" },
                                   { BackgroundColour::Green, "��ɫ" },
                                   { BackgroundColour::Blue, "��ɫ" },
                                   { BackgroundColour::Yellow, "��ɫ" },
                                   { BackgroundColour::Cyan, "��ɫ" },
                                   { BackgroundColour::Magenta, "Ʒ��ɫ" },
                                   { BackgroundColour::White, "��ɫ" },
                                   { BackgroundColour::IntensifiedBlack, "������ɫ" },
                                   { BackgroundColour::IntensifiedRed, "������ɫ" },
                                   { BackgroundColour::IntensifiedGreen, "������ɫ" },
                                   { BackgroundColour::IntensifiedBlue, "������ɫ" },
                                   { BackgroundColour::IntensifiedYellow, "������ɫ" },
                                   { BackgroundColour::IntensifiedCyan, "������ɫ" },
                                   { BackgroundColour::IntensifiedMagenta, "����Ʒ��ɫ" },
                                   { BackgroundColour::IntensifiedWhite, "������ɫ" } },
      consoleCommonDescription{ { ConsoleCommon::Default, "Ĭ��" },
                                { ConsoleCommon::LeadingByte, "ָ���ֽ�" },
                                { ConsoleCommon::TrailingByte, "β���ֽ�" },
                                { ConsoleCommon::GridHorizontal, "����ˮƽ��" },
                                { ConsoleCommon::GridLVertical, "��ֱ��" },
                                { ConsoleCommon::GridRVertical, "�Ҵ�ֱ��" },
                                { ConsoleCommon::ReverseVideo, "��תǰ���ͱ�������" },
                                { ConsoleCommon::Underscore, "�»���" },
                                { ConsoleCommon::SbcsDbcs, "SBCS��DBCS��־" } }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, ConsoleColourTesting)

void System::ConsoleColourTesting::PrintMessage(StandardHandle standardHandle, TextColour textColour, BackgroundColour backgroundColour, ConsoleCommon consoleCommon) const
{
    auto& os = (standardHandle == StandardHandle::Output) ? std::cout : std::cerr;

    os << "������Ϣ�ڿ���̨���ı���ʾΪ"
       << textColourDescription.at(textColour)
       << "������Ϊ"
       << backgroundColourDescription.at(backgroundColour)
       << "����ʽΪ"
       << consoleCommonDescription.at(consoleCommon)
       << "\n";
}
