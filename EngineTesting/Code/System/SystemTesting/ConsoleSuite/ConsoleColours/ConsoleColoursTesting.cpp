///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.3 (2022/10/15 22:07)

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
      textColourFlagsDescription{ { TextColour::Black, "黑色" },
                                  { TextColour::Red, "红色" },
                                  { TextColour::Green, "绿色" },
                                  { TextColour::Blue, "蓝色" },
                                  { TextColour::Yellow, "黄色" },
                                  { TextColour::Cyan, "青色" },
                                  { TextColour::Magenta, "品红色" },
                                  { TextColour::White, "白色" },
                                  { TextColour::IntensifiedBlack, "高亮黑色" },
                                  { TextColour::IntensifiedRed, "高亮红色" },
                                  { TextColour::IntensifiedGreen, "高亮绿色" },
                                  { TextColour::IntensifiedBlue, "高亮蓝色" },
                                  { TextColour::IntensifiedYellow, "高亮黄色" },
                                  { TextColour::IntensifiedCyan, "高亮青色" },
                                  { TextColour::IntensifiedMagenta, "高亮品红色" },
                                  { TextColour::IntensifiedWhite, "高亮白色" } },
      backgroundColourFlagsDescription{ { BackgroundColour::Black, "黑色" },
                                        { BackgroundColour::Red, "红色" },
                                        { BackgroundColour::Green, "绿色" },
                                        { BackgroundColour::Blue, "蓝色" },
                                        { BackgroundColour::Yellow, "黄色" },
                                        { BackgroundColour::Cyan, "青色" },
                                        { BackgroundColour::Magenta, "品红色" },
                                        { BackgroundColour::White, "白色" },
                                        { BackgroundColour::IntensifiedBlack, "高亮黑色" },
                                        { BackgroundColour::IntensifiedRed, "高亮红色" },
                                        { BackgroundColour::IntensifiedGreen, "高亮绿色" },
                                        { BackgroundColour::IntensifiedBlue, "高亮蓝色" },
                                        { BackgroundColour::IntensifiedYellow, "高亮黄色" },
                                        { BackgroundColour::IntensifiedCyan, "高亮青色" },
                                        { BackgroundColour::IntensifiedMagenta, "高亮品红色" },
                                        { BackgroundColour::IntensifiedWhite, "高亮白色" } },
      consoleCommonFlagsDescription{ { ConsoleCommon::Default, "默认" },
                                     { ConsoleCommon::LeadingByte, "指导字节" },
                                     { ConsoleCommon::TrailingByte, "尾随字节" },
                                     { ConsoleCommon::GridHorizontal, "顶部水平线" },
                                     { ConsoleCommon::GridLvertical, "左垂直线" },
                                     { ConsoleCommon::GridRvertical, "右垂直线" },
                                     { ConsoleCommon::ReverseVideo, "反转前景和背景属性" },
                                     { ConsoleCommon::Underscore, "下划线" },
                                     { ConsoleCommon::SbcsDbcs, "SBCS或DBCS标志" } }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, ConsoleColoursTesting)

void System::ConsoleColoursTesting::PrintMessage(StandardHandle standardHandleFlag, TextColour textColourFlag, BackgroundColour backgroundColourFlag, ConsoleCommon consoleCommonFlag)
{
    ostream& os = (standardHandleFlag == StandardHandle::Output) ? cout : cerr;

    os << "这条信息在控制台中文本显示为"
       << textColourFlagsDescription[textColourFlag]
       << "，背景为"
       << backgroundColourFlagsDescription[backgroundColourFlag]
       << "，格式为"
       << consoleCommonFlagsDescription[consoleCommonFlag]
       << "\n";
}