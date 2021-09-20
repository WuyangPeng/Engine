///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.1.3 (2021/05/23 22:55)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelperDetail.h"
#include "Example/BookOperatingSystem/BookWindowsAPI/Helper/BookWindowsAPIClassInvariantMacro.h"

BookWindowsAPI::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "���鼮������ϵͳ��Windows API����Ԫ�����׼�" }
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
    auto programmingWindowsSuite = GenerateSuite("Windows �������");

    programmingWindowsSuite.AddSuite(GetProgrammingWindowsFifthEditionSuite());
    programmingWindowsSuite.AddSuite(GetProgrammingWindowsSixthEditionSuite());

    AddSuite(programmingWindowsSuite);
}

CoreTools::Suite BookWindowsAPI::TestingHelper::GetProgrammingWindowsFifthEditionSuite()
{
    auto programmingWindowsFifthEditionSuite = GenerateSuite("Windows ������� ��5��");

    ADD_TEST(programmingWindowsFifthEditionSuite, ProgrammingWindowsFifthEditionCodeTesting);

    return programmingWindowsFifthEditionSuite;
}

CoreTools::Suite BookWindowsAPI::TestingHelper::GetProgrammingWindowsSixthEditionSuite()
{
    auto programmingWindowsSixthEditionSuite = GenerateSuite("Windows ������� ��6��");

    ADD_TEST(programmingWindowsSixthEditionSuite, ProgrammingWindowsSixthEditionCodeTesting);

    return programmingWindowsSixthEditionSuite;
}

void BookWindowsAPI::TestingHelper::AddProgrammingApplicationsForMicrosoftWindowsSuite()
{
    auto programmingApplicationsForMicrosoftWindowsSuite = GenerateSuite("Windows ���ı��");

    ADD_TEST(programmingApplicationsForMicrosoftWindowsSuite, ProgrammingApplicationsForMicrosoftWindowsCodeTesting);

    AddSuite(programmingApplicationsForMicrosoftWindowsSuite);
}

void BookWindowsAPI::TestingHelper::AddWindowsSystemProgrammingSuite()
{
    auto windowsSystemProgrammingSuite = GenerateSuite("Windows ϵͳ���");

    ADD_TEST(windowsSystemProgrammingSuite, WindowsSystemProgrammingCodeTesting);

    AddSuite(windowsSystemProgrammingSuite);
}

void BookWindowsAPI::TestingHelper::AddMicrosoftWindowsInternalsSuite()
{
    auto microsoftWindowsInternalsSuite = GenerateSuite("�������Windows����ϵͳ");

    microsoftWindowsInternalsSuite.AddSuite(GetMicrosoftWindowsInternalFourthEditionSuite());
    microsoftWindowsInternalsSuite.AddSuite(GetMicrosoftWindowsInternalSixthEditionSuite());

    AddSuite(microsoftWindowsInternalsSuite);
}

CoreTools::Suite BookWindowsAPI::TestingHelper::GetMicrosoftWindowsInternalFourthEditionSuite()
{
    auto microsoftWindowsInternalFourthEditionSuite = GenerateSuite("�������Windows����ϵͳ ��4��");

    ADD_TEST(microsoftWindowsInternalFourthEditionSuite, MicrosoftWindowsInternals::MicrosoftWindowsInternalsFourthEditionPlaceholderTesting);

    return microsoftWindowsInternalFourthEditionSuite;
}

CoreTools::Suite BookWindowsAPI::TestingHelper::GetMicrosoftWindowsInternalSixthEditionSuite()
{
    auto microsoftWindowsInternalSixthEditionSuite = GenerateSuite("�������Windows����ϵͳ ��6��");

    ADD_TEST(microsoftWindowsInternalSixthEditionSuite, MicrosoftWindowsInternals::MicrosoftWindowsInternalsSixthEditionPlaceholderTesting);

    return microsoftWindowsInternalSixthEditionSuite;
}

void BookWindowsAPI::TestingHelper::AddIvorHortonsBeginningVisualCppSuite()
{
    auto ivorHortonsBeginningVisualCppSuite = GenerateSuite("Visual C++ ���ž���");

    ivorHortonsBeginningVisualCppSuite.AddSuite(GetIvorHortonsBeginningVisualCppFifthEditionSuite());
    ivorHortonsBeginningVisualCppSuite.AddSuite(GetIvorHortonsBeginningVisualCppSeventhEditionSuite());

    AddSuite(ivorHortonsBeginningVisualCppSuite);
}

CoreTools::Suite BookWindowsAPI::TestingHelper::GetIvorHortonsBeginningVisualCppFifthEditionSuite()
{
    auto ivorHortonsBeginningVisualCppFifthEditionSuite = GenerateSuite("Visual C++ ���ž��� ��5��");

    ADD_TEST(ivorHortonsBeginningVisualCppFifthEditionSuite, IvorHortonsBeginningVisualCpp::IvorHortonsBeginningVisualCppFifthEditionPlaceholderTesting);

    return ivorHortonsBeginningVisualCppFifthEditionSuite;
}

CoreTools::Suite BookWindowsAPI::TestingHelper::GetIvorHortonsBeginningVisualCppSeventhEditionSuite()
{
    auto ivorHortonsBeginningVisualCppSeventhEditionSuite = GenerateSuite("Visual C++ ���ž��� ��7��");

    ADD_TEST(ivorHortonsBeginningVisualCppSeventhEditionSuite, IvorHortonsBeginningVisualCpp::IvorHortonsBeginningVisualCppSeventhEditionTesting);

    return ivorHortonsBeginningVisualCppSeventhEditionSuite;
}

void BookWindowsAPI::TestingHelper::AddTheOldNewThingSuite()
{
    auto theOldNewThingSuite = GenerateSuite("Windows �����ʾ¼");

    ADD_TEST(theOldNewThingSuite, TheOldNewThing::TheOldNewThingPlaceholderTesting);

    AddSuite(theOldNewThingSuite);
}
