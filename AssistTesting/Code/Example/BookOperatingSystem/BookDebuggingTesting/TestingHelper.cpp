///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.2.4 (2021/10/10 19:52)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelperDetail.h"
#include "Example/BookOperatingSystem/BookDebugging/Helper/BookDebuggingClassInvariantMacro.h"

BookDebugging::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "���鼮������ϵͳ�����ԡ���Ԫ�����׼�" }
{
    InitSuite();

    BOOK_DEBUGGING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookDebugging, TestingHelper)

void BookDebugging::TestingHelper::InitSuite()
{
    AddSafeCppSuite();
    AddDebuggingCppSuite();
    AddAdvancedWindowsDebuggingSuite();
    AddTheDevelopersGuideToDebuggingSuite();
}

void BookDebugging::TestingHelper::AddSafeCppSuite()
{
    auto safeCppSuite = GenerateSuite("C++ ��̵�������");

    ADD_TEST(safeCppSuite, SafeCpp::SafeCppPlaceholderTesting);

    AddSuite(safeCppSuite);
}

void BookDebugging::TestingHelper::AddDebuggingCppSuite()
{
    auto debuggingCppSuite = GenerateSuite("C++ �������ʵ���ֲ�");

    ADD_TEST(debuggingCppSuite, DebuggingCpp::DebuggingCppPlaceholderTesting);

    AddSuite(debuggingCppSuite);
}

void BookDebugging::TestingHelper::AddAdvancedWindowsDebuggingSuite()
{
    auto advancedWindowsDebuggingSuite = GenerateSuite("Windows �߼�����");

    ADD_TEST(advancedWindowsDebuggingSuite, AdvancedWindowsDebugging::AdvancedWindowsDebuggingPlaceholderTesting);

    AddSuite(advancedWindowsDebuggingSuite);
}

void BookDebugging::TestingHelper::AddTheDevelopersGuideToDebuggingSuite()
{
    auto theDevelopersGuideToDebuggingSuite = GenerateSuite("�������ʵս");

    ADD_TEST(theDevelopersGuideToDebuggingSuite, TheDevelopersGuideToDebugging::TheDevelopersGuideToDebuggingPlaceholderTesting);

    AddSuite(theDevelopersGuideToDebuggingSuite);
}
