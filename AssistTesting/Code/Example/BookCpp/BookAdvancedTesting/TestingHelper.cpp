///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.1.1 (2021/03/20 20:11)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelperDetail.h"
#include "Example/BookCpp/BookAdvanced/Helper/BookAdvancedClassInvariantMacro.h"

BookAdvanced::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "�鼮 C++ �߼�" }
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
    auto cleanCppSustainableSoftwareDevelopmentSuite = GenerateSuite("C++ ��������֮����C++17�ɳ����������ģʽʵ��");

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
    auto theDesignAndEvolutionOfCppSuite = GenerateSuite("C++ ���Ե���ƺ��ݻ�");

    ADD_TEST(theDesignAndEvolutionOfCppSuite, TheDesignAndEvolutionOfCpp::TheDesignAndEvolutionOfCppPlaceholderTesting);

    AddSuite(theDesignAndEvolutionOfCppSuite);
}

void BookAdvanced::TestingHelper::AddCrossPlatformDevelopmentInCppSuite()
{
    auto crossPlatformDevelopmentInCppSuite = GenerateSuite("C++ ��ƽ̨��������ָ��");

    ADD_TEST(crossPlatformDevelopmentInCppSuite, CrossPlatformDevelopmentInCpp::CrossPlatformDevelopmentInCppFibonacciTesting);
    ADD_TEST(crossPlatformDevelopmentInCppSuite, CrossPlatformDevelopmentInCpp::CrossPlatformDevelopmentInCppHelloWorldTesting);
    ADD_TEST(crossPlatformDevelopmentInCppSuite, CrossPlatformDevelopmentInCpp::CrossPlatformDevelopmentInCppOperatingSystemInterfaceTesting);

    AddSuite(crossPlatformDevelopmentInCppSuite);
}

void BookAdvanced::TestingHelper::AddAPIDesignForCppSuite()
{
    auto apiDesignForCppSuite = GenerateSuite("C++ API���");

    ADD_TEST(apiDesignForCppSuite, APIDesignForCpp::APIDesignForCppPlaceholderTesting);

    AddSuite(apiDesignForCppSuite);
}

void BookAdvanced::TestingHelper::AddDiscoveringModernCppSuite()
{
    auto discoveringModernCppSuite = GenerateSuite("���̽��C++14");

    ADD_TEST(discoveringModernCppSuite, DiscoveringModernCpp::DiscoveringModernCppGradientTesting);

    AddSuite(discoveringModernCppSuite);
}

void BookAdvanced::TestingHelper::AddModernCppDesignSuite()
{
    auto modernCppDesignSuite = GenerateSuite("C++ �����˼ά");

    ADD_TEST(modernCppDesignSuite, ModernCppDesign::ModernCppDesignPhysicalTesting);
    ADD_TEST(modernCppDesignSuite, ModernCppDesign::ModernCppDesignCTAssertTesting);

    AddSuite(modernCppDesignSuite);
}

void BookAdvanced::TestingHelper::AddTheArtOfCppSuite()
{
    auto theArtOfCppSuite = GenerateSuite("C++ �������");

    ADD_TEST(theArtOfCppSuite, TheArtOfCpp::TheArtOfCppPlaceholderTesting);

    AddSuite(theArtOfCppSuite);
}

void BookAdvanced::TestingHelper::AddInsideTheCppObjectModelSuite()
{
    auto insideTheCppObjectModelSuite = GenerateSuite("���̽��C++����ģ��");

    ADD_TEST(insideTheCppObjectModelSuite, InsideTheCppObjectModel::InsideTheCppObjectModelConstructorTesting);

    AddSuite(insideTheCppObjectModelSuite);
}

void BookAdvanced::TestingHelper::AddLargeScaleCppSoftwareDesignSuite()
{
    auto largeScaleCppSoftwareDesignSuite = GenerateSuite("���ģC++�������");

    ADD_TEST(largeScaleCppSoftwareDesignSuite, LargeScaleCppSoftwareDesign::LargeScaleCppSoftwareDesignPlaceholderTesting);

    AddSuite(largeScaleCppSoftwareDesignSuite);
}

void BookAdvanced::TestingHelper::AddSecureCodingInCAndCppSuite()
{
    auto secureCodingInCAndCppSuite = GenerateSuite("C��C++��ȫ����");

    ADD_TEST(secureCodingInCAndCppSuite, SecureCodingInCAndCpp::SecureCodingInCAndCppPlaceholderTesting);

    AddSuite(secureCodingInCAndCppSuite);
}

void BookAdvanced::TestingHelper::AddDesigningAndCodingReusableCppSuite()
{
    auto designingAndCodingReusableCppSuite = GenerateSuite("C++ �������������");

    ADD_TEST(designingAndCodingReusableCppSuite, DesigningAndCodingReusableCpp::DesigningAndCodingReusableCppConstructorTesting);

    AddSuite(designingAndCodingReusableCppSuite);
}

void BookAdvanced::TestingHelper::AddMultiParadigmDesignForCppSuite()
{
    auto multiParadigmDesignForCppSuite = GenerateSuite("C++ �෶�����");

    ADD_TEST(multiParadigmDesignForCppSuite, MultiParadigmDesignForCpp::MultiParadigmDesignForCppPlaceholderTesting);

    AddSuite(multiParadigmDesignForCppSuite);
}

void BookAdvanced::TestingHelper::AddCppGUIProgrammingWithQt4Suite()
{
    auto cppGUIProgrammingWithQt4Suite = GenerateSuite("C++ GUI Qt 4���");

    ADD_TEST(cppGUIProgrammingWithQt4Suite, CppGUIProgrammingWithQt4::CppGUIProgrammingWithQt4PlaceholderTesting);

    AddSuite(cppGUIProgrammingWithQt4Suite);
}

void BookAdvanced::TestingHelper::AddAdvancedQtProgrammingSuite()
{
    auto advancedQtProgrammingSuite = GenerateSuite("Qt�߼����");

    ADD_TEST(advancedQtProgrammingSuite, AdvancedQtProgramming::AdvancedQtProgrammingPlaceholderTesting);

    AddSuite(advancedQtProgrammingSuite);
}
