///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助测试版本：0.7.2.4 (2021/10/10 19:52)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelperDetail.h"
#include "Example/BookOperatingSystem/BookDebugging/Helper/BookDebuggingClassInvariantMacro.h"

BookDebugging::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "【书籍·操作系统·调试】单元测试套件" }
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
    auto safeCppSuite = GenerateSuite("C++ 编程调试秘笈");

    ADD_TEST(safeCppSuite, SafeCpp::SafeCppPlaceholderTesting);

    AddSuite(safeCppSuite);
}

void BookDebugging::TestingHelper::AddDebuggingCppSuite()
{
    auto debuggingCppSuite = GenerateSuite("C++ 程序调试实用手册");

    ADD_TEST(debuggingCppSuite, DebuggingCpp::DebuggingCppPlaceholderTesting);

    AddSuite(debuggingCppSuite);
}

void BookDebugging::TestingHelper::AddAdvancedWindowsDebuggingSuite()
{
    auto advancedWindowsDebuggingSuite = GenerateSuite("Windows 高级调试");

    ADD_TEST(advancedWindowsDebuggingSuite, AdvancedWindowsDebugging::AdvancedWindowsDebuggingPlaceholderTesting);

    AddSuite(advancedWindowsDebuggingSuite);
}

void BookDebugging::TestingHelper::AddTheDevelopersGuideToDebuggingSuite()
{
    auto theDevelopersGuideToDebuggingSuite = GenerateSuite("软件调试实战");

    ADD_TEST(theDevelopersGuideToDebuggingSuite, TheDevelopersGuideToDebugging::TheDevelopersGuideToDebuggingPlaceholderTesting);

    AddSuite(theDevelopersGuideToDebuggingSuite);
}
