///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.1.1 (2021/03/06 21:39)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelperDetail.h"
#include "Example/BookCpp/BookStandardLibrary/Helper/BookStandardLibraryClassInvariantMacro.h"

BookStandardLibrary::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "�鼮 C++ ��׼��" }
{
    InitSuite();

    BOOK_STANDARD_LIBRARY_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookStandardLibrary, TestingHelper)

void BookStandardLibrary::TestingHelper::InitSuite()
{
    AddTheCppStandardLibrarySuite();
    AddCppSTLSuite();
    AddGenericProgrammingAndTheSTLSuite();
    AddExtendedSTLSuite();

    AddStandardCppIOStreamsAndLocalesSuite();
    AddUsingTheCppStandardTemplateLibrariesSuite();
    AddSTLTutorialAndReferenceGuideSuite();
}

void BookStandardLibrary::TestingHelper::AddTheCppStandardLibrarySuite()
{
    auto theCppStandardLibrarySuite = GenerateSuite("C++ ��׼�����");

    ADD_TEST(theCppStandardLibrarySuite, TheCppStandardLibrary::TheCppStandardLibraryPlaceholderTesting);

    AddSuite(theCppStandardLibrarySuite);
}

void BookStandardLibrary::TestingHelper::AddCppSTLSuite()
{
    auto cppSTLSuite = GenerateSuite("C++ STL");

    ADD_TEST(cppSTLSuite, CppSTL::CppSTLPlaceholderTesting);

    AddSuite(cppSTLSuite);
}

void BookStandardLibrary::TestingHelper::AddGenericProgrammingAndTheSTLSuite()
{
    auto genericProgrammingAndTheSTLSuite = GenerateSuite("���ͱ����STL");

    ADD_TEST(genericProgrammingAndTheSTLSuite, GenericProgrammingAndTheSTL::GenericProgrammingAndTheSTLPlaceholderTesting);

    AddSuite(genericProgrammingAndTheSTLSuite);
}

void BookStandardLibrary::TestingHelper::AddExtendedSTLSuite()
{
    auto extendedSTLSuite = GenerateSuite("STL ��չ�����ֲ�");

    ADD_TEST(extendedSTLSuite, ExtendedSTL::ExtendedSTLArrangementStyleTesting);
    ADD_TEST(extendedSTLSuite, ExtendedSTL::ExtendedSTLBalanceTesting);
    ADD_TEST(extendedSTLSuite, ExtendedSTL::ExtendedSTLSevenSignsOfAGoodCppLibraryTesting);

    AddSuite(extendedSTLSuite);
}

void BookStandardLibrary::TestingHelper::AddStandardCppIOStreamsAndLocalesSuite()
{
    auto standardCppIOStreamsAndLocalesSuite = GenerateSuite("��׼C++ ����������뱾�ػ�");

    ADD_TEST(standardCppIOStreamsAndLocalesSuite, StandardCppIOStreamsAndLocales::StandardCppIOStreamsAndLocalesPrefaceTesting);

    AddSuite(standardCppIOStreamsAndLocalesSuite);
}

void BookStandardLibrary::TestingHelper::AddUsingTheCppStandardTemplateLibrariesSuite()
{
    auto usingTheCppStandardTemplateLibrariesSuite = GenerateSuite("C++ ��׼ģ�����ʵս");

    ADD_TEST(usingTheCppStandardTemplateLibrariesSuite, UsingTheCppStandardTemplateLibraries::UsingTheCppStandardTemplateLibrariesPlaceholderTesting);

    AddSuite(usingTheCppStandardTemplateLibrariesSuite);
}

void BookStandardLibrary::TestingHelper::AddSTLTutorialAndReferenceGuideSuite()
{
    auto stlTutorialAndReferenceGuideSuite = GenerateSuite("��׼ģ������޽̳���ο��ֲ�");

    ADD_TEST(stlTutorialAndReferenceGuideSuite, STLTutorialAndReferenceGuide::STLTutorialAndReferenceGuidePrefaceTesting);

    AddSuite(stlTutorialAndReferenceGuideSuite);
}
