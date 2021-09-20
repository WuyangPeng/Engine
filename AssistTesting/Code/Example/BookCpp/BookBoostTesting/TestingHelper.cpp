///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助测试版本：0.7.1.1 (2021/03/21 19:24)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelperDetail.h"
#include "Example/BookCpp/BookBoost/Helper/BookBoostClassInvariantMacro.h"

BookBoost::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "书籍 C++ boost" }
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
    auto theCppStandardLibraryExtensionsSuite = GenerateSuite("C++ 标准库扩展权威指南"); 

    ADD_TEST(theCppStandardLibraryExtensionsSuite, TheCppStandardLibraryExtensions::TheCppStandardLibraryExtensionsConstructorTesting);

    AddSuite(theCppStandardLibraryExtensionsSuite);
}

void BookBoost::TestingHelper::AddBeyondTheCppStandardLibraryAnIntroductionToBoostSuite()
{
    auto beyondTheCppStandardLibraryAnIntroductionToBoostSuite = GenerateSuite("超越C++标准库：Boost库导论");  

    ADD_TEST(beyondTheCppStandardLibraryAnIntroductionToBoostSuite, BeyondTheCppStandardLibraryAnIntroductionToBoost::BeyondTheCppStandardLibraryAnIntroductionToBoostPlaceholderTesting);

    AddSuite(beyondTheCppStandardLibraryAnIntroductionToBoostSuite);
}

void BookBoost::TestingHelper::AddBoostCppApplicationDevelopmentCookbookSuite()
{
    auto boostCppApplicationDevelopmentCookbookSuite = GenerateSuite("深入实践Boost");   

    ADD_TEST(boostCppApplicationDevelopmentCookbookSuite, BoostCppApplicationDevelopmentCookbook::BoostCppApplicationDevelopmentCookbookPlaceholderTesting);

    AddSuite(boostCppApplicationDevelopmentCookbookSuite);
}
