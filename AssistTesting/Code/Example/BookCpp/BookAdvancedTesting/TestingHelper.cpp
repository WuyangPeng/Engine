///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助测试版本：0.7.1.1 (2021/03/20 20:11)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelperDetail.h"
#include "Example/BookCpp/BookAdvanced/Helper/BookAdvancedClassInvariantMacro.h"

BookAdvanced::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "书籍 C++ 高级" }
{
    InitSuite();

    BOOK_ADVANCED_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookAdvanced, TestingHelper)

void BookAdvanced::TestingHelper::InitSuite()
{
    AddCleanCppSustainableSoftwareDevelopmentSuite();
    AddTheDesignAndEvolutionOfCppSuite();
    AddCrossPlatformDevelopmentInCppSuite();
    AddAPIDesignForCppSuite();
    AddDiscoveringModernCppSuite();

    AddModernCppDesignSuite();
    AddTheArtOfCppSuite();
    AddInsideTheCppObjectModelSuite();
    AddLargeScaleCppSoftwareDesignSuite();
    AddSecureCodingInCAndCppSuite();

    AddDesigningAndCodingReusableCppSuite();
    AddMultiParadigmDesignForCppSuite();
    AddCppGUIProgrammingWithQt4Suite();
    AddAdvancedQtProgrammingSuite();
}

void BookAdvanced::TestingHelper::AddCleanCppSustainableSoftwareDevelopmentSuite()
{
    auto cleanCppSustainableSoftwareDevelopmentSuite = GenerateSuite("C++ 代码整洁之道：C++17可持续软件开发模式实践");

    ADD_TEST(cleanCppSustainableSoftwareDevelopmentSuite, CleanCppSustainableSoftwareDevelopment::CleanCppSustainableSoftwareDevelopmentChapter1ClazzTesting);
    ADD_TEST(cleanCppSustainableSoftwareDevelopmentSuite, CleanCppSustainableSoftwareDevelopment::CleanCppSustainableSoftwareDevelopmentChapter2TestTesting);
    ADD_TEST(cleanCppSustainableSoftwareDevelopmentSuite, CleanCppSustainableSoftwareDevelopment::MoneyTest);
    ADD_TEST(cleanCppSustainableSoftwareDevelopmentSuite, CleanCppSustainableSoftwareDevelopment::CleanCppSustainableSoftwareDevelopmentChapter2CustomerTesting);
    ADD_TEST(cleanCppSustainableSoftwareDevelopmentSuite, CleanCppSustainableSoftwareDevelopment::CleanCppSustainableSoftwareDevelopmentChapter2ClazzTesting);
    ADD_TEST(cleanCppSustainableSoftwareDevelopmentSuite, CleanCppSustainableSoftwareDevelopment::CleanCppSustainableSoftwareDevelopmentChapter2ServiceTesting);

    AddSuite(cleanCppSustainableSoftwareDevelopmentSuite);
}

void BookAdvanced::TestingHelper::AddTheDesignAndEvolutionOfCppSuite()
{
    auto theDesignAndEvolutionOfCppSuite = GenerateSuite("C++ 语言的设计和演化");

    ADD_TEST(theDesignAndEvolutionOfCppSuite, TheDesignAndEvolutionOfCpp::TheDesignAndEvolutionOfCppPlaceholderTesting);

    AddSuite(theDesignAndEvolutionOfCppSuite);
}

void BookAdvanced::TestingHelper::AddCrossPlatformDevelopmentInCppSuite()
{
    auto crossPlatformDevelopmentInCppSuite = GenerateSuite("C++ 跨平台开发技术指南");

    ADD_TEST(crossPlatformDevelopmentInCppSuite, CrossPlatformDevelopmentInCpp::CrossPlatformDevelopmentInCppFibonacciTesting);
    ADD_TEST(crossPlatformDevelopmentInCppSuite, CrossPlatformDevelopmentInCpp::CrossPlatformDevelopmentInCppHelloWorldTesting);
    ADD_TEST(crossPlatformDevelopmentInCppSuite, CrossPlatformDevelopmentInCpp::CrossPlatformDevelopmentInCppOperatingSystemInterfaceTesting);

    AddSuite(crossPlatformDevelopmentInCppSuite);
}

void BookAdvanced::TestingHelper::AddAPIDesignForCppSuite()
{
    auto apiDesignForCppSuite = GenerateSuite("C++ API设计");

    ADD_TEST(apiDesignForCppSuite, APIDesignForCpp::APIDesignForCppPlaceholderTesting);

    AddSuite(apiDesignForCppSuite);
}

void BookAdvanced::TestingHelper::AddDiscoveringModernCppSuite()
{
    auto discoveringModernCppSuite = GenerateSuite("深度探索C++14");

    ADD_TEST(discoveringModernCppSuite, DiscoveringModernCpp::DiscoveringModernCppGradientTesting);

    AddSuite(discoveringModernCppSuite);
}

void BookAdvanced::TestingHelper::AddModernCppDesignSuite()
{
    auto modernCppDesignSuite = GenerateSuite("C++ 设计新思维");

    ADD_TEST(modernCppDesignSuite, ModernCppDesign::ModernCppDesignPhysicalTesting);
    ADD_TEST(modernCppDesignSuite, ModernCppDesign::ModernCppDesignCTAssertTesting);

    AddSuite(modernCppDesignSuite);
}

void BookAdvanced::TestingHelper::AddTheArtOfCppSuite()
{
    auto theArtOfCppSuite = GenerateSuite("C++ 编程艺术");

    ADD_TEST(theArtOfCppSuite, TheArtOfCpp::TheArtOfCppPlaceholderTesting);

    AddSuite(theArtOfCppSuite);
}

void BookAdvanced::TestingHelper::AddInsideTheCppObjectModelSuite()
{
    auto insideTheCppObjectModelSuite = GenerateSuite("深度探索C++对象模型");

    ADD_TEST(insideTheCppObjectModelSuite, InsideTheCppObjectModel::InsideTheCppObjectModelConstructorTesting);

    AddSuite(insideTheCppObjectModelSuite);
}

void BookAdvanced::TestingHelper::AddLargeScaleCppSoftwareDesignSuite()
{
    auto largeScaleCppSoftwareDesignSuite = GenerateSuite("大规模C++程序设计");

    ADD_TEST(largeScaleCppSoftwareDesignSuite, LargeScaleCppSoftwareDesign::LargeScaleCppSoftwareDesignPlaceholderTesting);

    AddSuite(largeScaleCppSoftwareDesignSuite);
}

void BookAdvanced::TestingHelper::AddSecureCodingInCAndCppSuite()
{
    auto secureCodingInCAndCppSuite = GenerateSuite("C和C++安全编码");

    ADD_TEST(secureCodingInCAndCppSuite, SecureCodingInCAndCpp::SecureCodingInCAndCppPlaceholderTesting);

    AddSuite(secureCodingInCAndCppSuite);
}

void BookAdvanced::TestingHelper::AddDesigningAndCodingReusableCppSuite()
{
    auto designingAndCodingReusableCppSuite = GenerateSuite("C++ 代码设计与重用");

    ADD_TEST(designingAndCodingReusableCppSuite, DesigningAndCodingReusableCpp::DesigningAndCodingReusableCppConstructorTesting);

    AddSuite(designingAndCodingReusableCppSuite);
}

void BookAdvanced::TestingHelper::AddMultiParadigmDesignForCppSuite()
{
    auto multiParadigmDesignForCppSuite = GenerateSuite("C++ 多范型设计");

    ADD_TEST(multiParadigmDesignForCppSuite, MultiParadigmDesignForCpp::MultiParadigmDesignForCppPlaceholderTesting);

    AddSuite(multiParadigmDesignForCppSuite);
}

void BookAdvanced::TestingHelper::AddCppGUIProgrammingWithQt4Suite()
{
    auto cppGUIProgrammingWithQt4Suite = GenerateSuite("C++ GUI Qt 4编程");

    ADD_TEST(cppGUIProgrammingWithQt4Suite, CppGUIProgrammingWithQt4::CppGUIProgrammingWithQt4PlaceholderTesting);

    AddSuite(cppGUIProgrammingWithQt4Suite);
}

void BookAdvanced::TestingHelper::AddAdvancedQtProgrammingSuite()
{
    auto advancedQtProgrammingSuite = GenerateSuite("Qt高级编程");

    ADD_TEST(advancedQtProgrammingSuite, AdvancedQtProgramming::AdvancedQtProgrammingPlaceholderTesting);

    AddSuite(advancedQtProgrammingSuite);
}
