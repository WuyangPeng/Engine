///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.1.1 (2021/03/21 19:24)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelperDetail.h"
#include "Example/BookCpp/BookBoost/Helper/BookBoostClassInvariantMacro.h"

BookBoost::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "�鼮 C++ boost" }
{
    InitSuite();

    BOOK_BOOST_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookBoost, TestingHelper)

void BookBoost::TestingHelper::InitSuite()
{
    AddTheCppStandardLibraryExtensionsSuite();
    AddBeyondTheCppStandardLibraryAnIntroductionToBoostSuite();
    AddBoostCppApplicationDevelopmentCookbookSuite();
}

void BookBoost::TestingHelper::AddTheCppStandardLibraryExtensionsSuite()
{
    auto theCppStandardLibraryExtensionsSuite = GenerateSuite("C++ ��׼����չȨ��ָ��"); 

    ADD_TEST(theCppStandardLibraryExtensionsSuite, TheCppStandardLibraryExtensions::TheCppStandardLibraryExtensionsConstructorTesting);

    AddSuite(theCppStandardLibraryExtensionsSuite);
}

void BookBoost::TestingHelper::AddBeyondTheCppStandardLibraryAnIntroductionToBoostSuite()
{
    auto beyondTheCppStandardLibraryAnIntroductionToBoostSuite = GenerateSuite("��ԽC++��׼�⣺Boost�⵼��");  

    ADD_TEST(beyondTheCppStandardLibraryAnIntroductionToBoostSuite, BeyondTheCppStandardLibraryAnIntroductionToBoost::BeyondTheCppStandardLibraryAnIntroductionToBoostPlaceholderTesting);

    AddSuite(beyondTheCppStandardLibraryAnIntroductionToBoostSuite);
}

void BookBoost::TestingHelper::AddBoostCppApplicationDevelopmentCookbookSuite()
{
    auto boostCppApplicationDevelopmentCookbookSuite = GenerateSuite("����ʵ��Boost");   

    ADD_TEST(boostCppApplicationDevelopmentCookbookSuite, BoostCppApplicationDevelopmentCookbook::BoostCppApplicationDevelopmentCookbookPlaceholderTesting);

    AddSuite(boostCppApplicationDevelopmentCookbookSuite);
}
