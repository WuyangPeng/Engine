///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助测试版本：0.7.1.4 (2021/06/12 12:54)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelperDetail.h"
#include "Example/BookOperatingSystem/BookACE/Helper/BookACEClassInvariantMacro.h"

BookACE::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "【书籍·操作系统·ACE】单元测试套件" }
{
    InitSuite();

    BOOK_ACE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookACE, TestingHelper)

void BookACE::TestingHelper::InitSuite()
{
    AddCppNetworkProgrammingSuite();
    AddTheACEProgrammersGuideSuite();
}

void BookACE::TestingHelper::AddCppNetworkProgrammingSuite()
{
    auto cppNetworkProgrammingSuite = GenerateSuite("C++ 网络编程");

    cppNetworkProgrammingSuite.AddSuite(GetCppNetworkProgrammingMasteringComplexityWithACEAndPatternsSuite());
    cppNetworkProgrammingSuite.AddSuite(GetCppNetworkProgrammingSystematicReuseWithACEAndFrameworkSuite());

    AddSuite(cppNetworkProgrammingSuite);
}

CoreTools::Suite BookACE::TestingHelper::GetCppNetworkProgrammingMasteringComplexityWithACEAndPatternsSuite()
{
    auto cppNetworkProgrammingMasteringComplexityWithACEAndPatternsSuite = GenerateSuite("C++ 网络编程  运用ACE和模式消除复杂性");

    ADD_TEST(cppNetworkProgrammingMasteringComplexityWithACEAndPatternsSuite, CppNetworkProgramming::MasteringComplexityWithACEAndPatternsPlaceholderTesting);

    return cppNetworkProgrammingMasteringComplexityWithACEAndPatternsSuite;
}

CoreTools::Suite BookACE::TestingHelper::GetCppNetworkProgrammingSystematicReuseWithACEAndFrameworkSuite()
{
    auto cppNetworkProgrammingSystematicReuseWithACEAndFrameworkSuite = GenerateSuite("C++ 网络编程  基于ACE和框架的系统化复");

    ADD_TEST(cppNetworkProgrammingSystematicReuseWithACEAndFrameworkSuite, CppNetworkProgramming::SystematicReuseWithACEAndFrameworksPlaceholderTesting);

    return cppNetworkProgrammingSystematicReuseWithACEAndFrameworkSuite;
}

void BookACE::TestingHelper::AddTheACEProgrammersGuideSuite()
{
    auto theACEProgrammersGuideSuite = GenerateSuite("ACE 程序员指南");

    ADD_TEST(theACEProgrammersGuideSuite, TheACEProgrammersGuide::TheACEProgrammersGuidePlaceholderTesting);

    AddSuite(theACEProgrammersGuideSuite);
}
