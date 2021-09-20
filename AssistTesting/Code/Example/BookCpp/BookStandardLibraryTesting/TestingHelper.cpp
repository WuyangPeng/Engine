///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助测试版本：0.7.1.1 (2021/03/06 21:39)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelperDetail.h"
#include "Example/BookCpp/BookStandardLibrary/Helper/BookStandardLibraryClassInvariantMacro.h"

BookStandardLibrary::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "书籍 C++ 标准库" }
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
    auto theCppStandardLibrarySuite = GenerateSuite("C++ 标准程序库");

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
    auto genericProgrammingAndTheSTLSuite = GenerateSuite("泛型编程与STL");

    ADD_TEST(genericProgrammingAndTheSTLSuite, GenericProgrammingAndTheSTL::GenericProgrammingAndTheSTLPlaceholderTesting);

    AddSuite(genericProgrammingAndTheSTLSuite);
}

void BookStandardLibrary::TestingHelper::AddExtendedSTLSuite()
{
    auto extendedSTLSuite = GenerateSuite("STL 扩展技术手册");

    ADD_TEST(extendedSTLSuite, ExtendedSTL::ExtendedSTLArrangementStyleTesting);
    ADD_TEST(extendedSTLSuite, ExtendedSTL::ExtendedSTLBalanceTesting);
    ADD_TEST(extendedSTLSuite, ExtendedSTL::ExtendedSTLSevenSignsOfAGoodCppLibraryTesting);

    AddSuite(extendedSTLSuite);
}

void BookStandardLibrary::TestingHelper::AddStandardCppIOStreamsAndLocalesSuite()
{
    auto standardCppIOStreamsAndLocalesSuite = GenerateSuite("标准C++ 输入输出流与本地化");

    ADD_TEST(standardCppIOStreamsAndLocalesSuite, StandardCppIOStreamsAndLocales::StandardCppIOStreamsAndLocalesPrefaceTesting);

    AddSuite(standardCppIOStreamsAndLocalesSuite);
}

void BookStandardLibrary::TestingHelper::AddUsingTheCppStandardTemplateLibrariesSuite()
{
    auto usingTheCppStandardTemplateLibrariesSuite = GenerateSuite("C++ 标准模板库编程实战");

    ADD_TEST(usingTheCppStandardTemplateLibrariesSuite, UsingTheCppStandardTemplateLibraries::UsingTheCppStandardTemplateLibrariesPlaceholderTesting);

    AddSuite(usingTheCppStandardTemplateLibrariesSuite);
}

void BookStandardLibrary::TestingHelper::AddSTLTutorialAndReferenceGuideSuite()
{
    auto stlTutorialAndReferenceGuideSuite = GenerateSuite("标准模板库自修教程与参考手册");

    ADD_TEST(stlTutorialAndReferenceGuideSuite, STLTutorialAndReferenceGuide::STLTutorialAndReferenceGuidePrefaceTesting);

    AddSuite(stlTutorialAndReferenceGuideSuite);
}
