///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.1.1 (2021/03/06 23:49)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelperDetail.h"
#include "Example/BookCpp/BookTemplate/Helper/BookTemplateClassInvariantMacro.h"

BookTemplate::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "�鼮 C++ ģ��" }
{
    InitSuite();

    BOOK_TEMPLATE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookTemplate, TestingHelper)

void BookTemplate::TestingHelper::InitSuite()
{
    AddCppTemplatesSuite();
    AddCppTemplateMetaprogrammingSuite();
}

void BookTemplate::TestingHelper::AddCppTemplatesSuite()
{
    auto cppTemplatesSuite = GenerateSuite("C++ Templates");

    ADD_TEST(cppTemplatesSuite, CppTemplates::CppTemplatesPlaceholderTesting);

    AddSuite(cppTemplatesSuite);
}

void BookTemplate::TestingHelper::AddCppTemplateMetaprogrammingSuite()
{
    auto cppTemplateMetaprogrammingSuite = GenerateSuite("C++ ģ��Ԫ���");

    ADD_TEST(cppTemplateMetaprogrammingSuite, CppTemplateMetaprogramming::CppTemplateMetaprogrammingBinary1Testing);
    ADD_TEST(cppTemplateMetaprogrammingSuite, CppTemplateMetaprogramming::CppTemplateMetaprogrammingYyparseTesting);
    ADD_TEST(cppTemplateMetaprogrammingSuite, CppTemplateMetaprogramming::CppTemplateMetaprogrammingBinary3Testing);
    ADD_TEST(cppTemplateMetaprogrammingSuite, CppTemplateMetaprogramming::CppTemplateMetaprogrammingBinary4Testing);
    ADD_TEST(cppTemplateMetaprogrammingSuite, CppTemplateMetaprogramming::CppTemplateMetaprogrammingCalculatorTesting);

    ADD_TEST(cppTemplateMetaprogrammingSuite, CppTemplateMetaprogramming::CppTemplateMetaprogrammingApplyTesting);
    ADD_TEST(cppTemplateMetaprogrammingSuite, CppTemplateMetaprogramming::CppTemplateMetaprogrammingChapter2XInstantiateTesting);
    ADD_TEST(cppTemplateMetaprogrammingSuite, CppTemplateMetaprogramming::CppTemplateMetaprogrammingIteratorTesting);
    ADD_TEST(cppTemplateMetaprogrammingSuite, CppTemplateMetaprogramming::CppTemplateMetaprogrammingFiveTesting);
    ADD_TEST(cppTemplateMetaprogrammingSuite, CppTemplateMetaprogramming::CppTemplateMetaprogrammingTypeTraitsTesting);

    ADD_TEST(cppTemplateMetaprogrammingSuite, CppTemplateMetaprogramming::CppTemplateMetaprogrammingExercise2_0Testing);
    ADD_TEST(cppTemplateMetaprogrammingSuite, CppTemplateMetaprogramming::CppTemplateMetaprogrammingExercise2_1Testing);
    ADD_TEST(cppTemplateMetaprogrammingSuite, CppTemplateMetaprogramming::CppTemplateMetaprogrammingExercise2_2Testing);
    ADD_TEST(cppTemplateMetaprogrammingSuite, CppTemplateMetaprogramming::CppTemplateMetaprogrammingExercise2_3Testing);
    ADD_TEST(cppTemplateMetaprogrammingSuite, CppTemplateMetaprogramming::CppTemplateMetaprogrammingExercise2_4Testing);
    ADD_TEST(cppTemplateMetaprogrammingSuite, CppTemplateMetaprogramming::CppTemplateMetaprogrammingExercise2_5Testing);

    ADD_TEST(cppTemplateMetaprogrammingSuite, CppTemplateMetaprogramming::CppTemplateMetaprogrammingQuantityMainTesting);
    ADD_TEST(cppTemplateMetaprogrammingSuite, CppTemplateMetaprogramming::CppTemplateMetaprogrammingLambdaMainTesting);

    ADD_TEST(cppTemplateMetaprogrammingSuite, CppTemplateMetaprogramming::CppTemplateMetaprogrammingExercise3_0Testing);
    ADD_TEST(cppTemplateMetaprogrammingSuite, CppTemplateMetaprogramming::CppTemplateMetaprogrammingExercise3_5Testing);
    ADD_TEST(cppTemplateMetaprogrammingSuite, CppTemplateMetaprogramming::CppTemplateMetaprogrammingExercise3_8Testing);

    AddSuite(cppTemplateMetaprogrammingSuite);
}
