///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.3 (2022/10/15 22:07)

#include "ConsoleColoursTesting.h"
#include "System/Console/ConsoleColours.h"
#include "System/Console/ConsoleHandle.h"
#include "System/Console/Flags/ConsoleColoursFlags.h"
#include "System/Console/Flags/ConsoleHandleFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using std::cerr;
using std::cout;
using std::ostream;

System::ConsoleColoursTesting::ConsoleColoursTesting(const OStreamShared& stream)
    : ParentType{ stream },
      textColourFlagsDescription{ { TextColour::Black, "��ɫ" },
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
      backgroundColourFlagsDescription{ { BackgroundColour::Black, "��ɫ" },
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
      consoleCommonFlagsDescription{ { ConsoleCommon::Default, "Ĭ��" },
                                     { ConsoleCommon::LeadingByte, "ָ���ֽ�" },
                                     { ConsoleCommon::TrailingByte, "β���ֽ�" },
                                     { ConsoleCommon::GridHorizontal, "����ˮƽ��" },
                                     { ConsoleCommon::GridLvertical, "��ֱ��" },
                                     { ConsoleCommon::GridRvertical, "�Ҵ�ֱ��" },
                                     { ConsoleCommon::ReverseVideo, "��תǰ���ͱ�������" },
                                     { ConsoleCommon::Underscore, "�»���" },
                                     { ConsoleCommon::SbcsDbcs, "SBCS��DBCS��־" } }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, ConsoleColoursTesting)

void System::ConsoleColoursTesting::PrintMessage(StandardHandle standardHandleFlag, TextColour textColourFlag, BackgroundColour backgroundColourFlag, ConsoleCommon consoleCommonFlag)
{
    ostream& os = (standardHandleFlag == StandardHandle::Output) ? cout : cerr;

    os << "������Ϣ�ڿ���̨���ı���ʾΪ"
       << textColourFlagsDescription[textColourFlag]
       << "������Ϊ"
       << backgroundColourFlagsDescription[backgroundColourFlag]
       << "����ʽΪ"
       << consoleCommonFlagsDescription[consoleCommonFlag]
       << "\n";
}