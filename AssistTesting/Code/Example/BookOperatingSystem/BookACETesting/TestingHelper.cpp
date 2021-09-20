///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.1.4 (2021/06/12 12:54)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelperDetail.h"
#include "Example/BookOperatingSystem/BookACE/Helper/BookACEClassInvariantMacro.h"

BookACE::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "���鼮������ϵͳ��ACE����Ԫ�����׼�" }
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
    auto cppNetworkProgrammingSuite = GenerateSuite("C++ ������");

    cppNetworkProgrammingSuite.AddSuite(GetCppNetworkProgrammingMasteringComplexityWithACEAndPatternsSuite());
    cppNetworkProgrammingSuite.AddSuite(GetCppNetworkProgrammingSystematicReuseWithACEAndFrameworkSuite());

    AddSuite(cppNetworkProgrammingSuite);
}

CoreTools::Suite BookACE::TestingHelper::GetCppNetworkProgrammingMasteringComplexityWithACEAndPatternsSuite()
{
    auto cppNetworkProgrammingMasteringComplexityWithACEAndPatternsSuite = GenerateSuite("C++ ������  ����ACE��ģʽ����������");

    ADD_TEST(cppNetworkProgrammingMasteringComplexityWithACEAndPatternsSuite, CppNetworkProgramming::MasteringComplexityWithACEAndPatternsPlaceholderTesting);

    return cppNetworkProgrammingMasteringComplexityWithACEAndPatternsSuite;
}

CoreTools::Suite BookACE::TestingHelper::GetCppNetworkProgrammingSystematicReuseWithACEAndFrameworkSuite()
{
    auto cppNetworkProgrammingSystematicReuseWithACEAndFrameworkSuite = GenerateSuite("C++ ������  ����ACE�Ϳ�ܵ�ϵͳ����");

    ADD_TEST(cppNetworkProgrammingSystematicReuseWithACEAndFrameworkSuite, CppNetworkProgramming::SystematicReuseWithACEAndFrameworksPlaceholderTesting);

    return cppNetworkProgrammingSystematicReuseWithACEAndFrameworkSuite;
}

void BookACE::TestingHelper::AddTheACEProgrammersGuideSuite()
{
    auto theACEProgrammersGuideSuite = GenerateSuite("ACE ����Աָ��");

    ADD_TEST(theACEProgrammersGuideSuite, TheACEProgrammersGuide::TheACEProgrammersGuidePlaceholderTesting);

    AddSuite(theACEProgrammersGuideSuite);
}
