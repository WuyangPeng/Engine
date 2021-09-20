///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助测试版本：0.7.1.3 (2021/05/23 22:55)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelperDetail.h"
#include "Example/BookOperatingSystem/BookWindowsAPI/Helper/BookWindowsAPIClassInvariantMacro.h"

BookWindowsAPI::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "【书籍·操作系统·Windows API】单元测试套件" }
{
    InitSuite();

    BOOK_WINDOWS_API_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookWindowsAPI, TestingHelper)

void BookWindowsAPI::TestingHelper::InitSuite()
{
    AddProgrammingWindowsSuite();
    AddProgrammingApplicationsForMicrosoftWindowsSuite();
    AddWindowsSystemProgrammingSuite();
    AddMicrosoftWindowsInternalsSuite();
    AddIvorHortonsBeginningVisualCppSuite();
    AddTheOldNewThingSuite();
}

void BookWindowsAPI::TestingHelper::AddProgrammingWindowsSuite()
{
    auto programmingWindowsSuite = GenerateSuite("Windows 程序设计");

    programmingWindowsSuite.AddSuite(GetProgrammingWindowsFifthEditionSuite());
    programmingWindowsSuite.AddSuite(GetProgrammingWindowsSixthEditionSuite());

    AddSuite(programmingWindowsSuite);
}

CoreTools::Suite BookWindowsAPI::TestingHelper::GetProgrammingWindowsFifthEditionSuite()
{
    auto programmingWindowsFifthEditionSuite = GenerateSuite("Windows 程序设计 第5版");

    ADD_TEST(programmingWindowsFifthEditionSuite, ProgrammingWindowsFifthEditionCodeTesting);

    return programmingWindowsFifthEditionSuite;
}

CoreTools::Suite BookWindowsAPI::TestingHelper::GetProgrammingWindowsSixthEditionSuite()
{
    auto programmingWindowsSixthEditionSuite = GenerateSuite("Windows 程序设计 第6版");

    ADD_TEST(programmingWindowsSixthEditionSuite, ProgrammingWindowsSixthEditionCodeTesting);

    return programmingWindowsSixthEditionSuite;
}

void BookWindowsAPI::TestingHelper::AddProgrammingApplicationsForMicrosoftWindowsSuite()
{
    auto programmingApplicationsForMicrosoftWindowsSuite = GenerateSuite("Windows 核心编程");

    ADD_TEST(programmingApplicationsForMicrosoftWindowsSuite, ProgrammingApplicationsForMicrosoftWindowsCodeTesting);

    AddSuite(programmingApplicationsForMicrosoftWindowsSuite);
}

void BookWindowsAPI::TestingHelper::AddWindowsSystemProgrammingSuite()
{
    auto windowsSystemProgrammingSuite = GenerateSuite("Windows 系统编程");

    ADD_TEST(windowsSystemProgrammingSuite, WindowsSystemProgrammingCodeTesting);

    AddSuite(windowsSystemProgrammingSuite);
}

void BookWindowsAPI::TestingHelper::AddMicrosoftWindowsInternalsSuite()
{
    auto microsoftWindowsInternalsSuite = GenerateSuite("深入解析Windows操作系统");

    microsoftWindowsInternalsSuite.AddSuite(GetMicrosoftWindowsInternalFourthEditionSuite());
    microsoftWindowsInternalsSuite.AddSuite(GetMicrosoftWindowsInternalSixthEditionSuite());

    AddSuite(microsoftWindowsInternalsSuite);
}

CoreTools::Suite BookWindowsAPI::TestingHelper::GetMicrosoftWindowsInternalFourthEditionSuite()
{
    auto microsoftWindowsInternalFourthEditionSuite = GenerateSuite("深入解析Windows操作系统 第4版");

    ADD_TEST(microsoftWindowsInternalFourthEditionSuite, MicrosoftWindowsInternals::MicrosoftWindowsInternalsFourthEditionPlaceholderTesting);

    return microsoftWindowsInternalFourthEditionSuite;
}

CoreTools::Suite BookWindowsAPI::TestingHelper::GetMicrosoftWindowsInternalSixthEditionSuite()
{
    auto microsoftWindowsInternalSixthEditionSuite = GenerateSuite("深入解析Windows操作系统 第6版");

    ADD_TEST(microsoftWindowsInternalSixthEditionSuite, MicrosoftWindowsInternals::MicrosoftWindowsInternalsSixthEditionPlaceholderTesting);

    return microsoftWindowsInternalSixthEditionSuite;
}

void BookWindowsAPI::TestingHelper::AddIvorHortonsBeginningVisualCppSuite()
{
    auto ivorHortonsBeginningVisualCppSuite = GenerateSuite("Visual C++ 入门经典");

    ivorHortonsBeginningVisualCppSuite.AddSuite(GetIvorHortonsBeginningVisualCppFifthEditionSuite());
    ivorHortonsBeginningVisualCppSuite.AddSuite(GetIvorHortonsBeginningVisualCppSeventhEditionSuite());

    AddSuite(ivorHortonsBeginningVisualCppSuite);
}

CoreTools::Suite BookWindowsAPI::TestingHelper::GetIvorHortonsBeginningVisualCppFifthEditionSuite()
{
    auto ivorHortonsBeginningVisualCppFifthEditionSuite = GenerateSuite("Visual C++ 入门经典 第5版");

    ADD_TEST(ivorHortonsBeginningVisualCppFifthEditionSuite, IvorHortonsBeginningVisualCpp::IvorHortonsBeginningVisualCppFifthEditionPlaceholderTesting);

    return ivorHortonsBeginningVisualCppFifthEditionSuite;
}

CoreTools::Suite BookWindowsAPI::TestingHelper::GetIvorHortonsBeginningVisualCppSeventhEditionSuite()
{
    auto ivorHortonsBeginningVisualCppSeventhEditionSuite = GenerateSuite("Visual C++ 入门经典 第7版");

    ADD_TEST(ivorHortonsBeginningVisualCppSeventhEditionSuite, IvorHortonsBeginningVisualCpp::IvorHortonsBeginningVisualCppSeventhEditionTesting);

    return ivorHortonsBeginningVisualCppSeventhEditionSuite;
}

void BookWindowsAPI::TestingHelper::AddTheOldNewThingSuite()
{
    auto theOldNewThingSuite = GenerateSuite("Windows 编程启示录");

    ADD_TEST(theOldNewThingSuite, TheOldNewThing::TheOldNewThingPlaceholderTesting);

    AddSuite(theOldNewThingSuite);
}
