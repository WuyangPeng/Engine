///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.0.1 (2021/02/16 11:55)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelperDetail.h"
#include "Example/BookCpp/BookExperience/Helper/BookExperienceClassInvariantMacro.h"

BookExperience::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "�鼮 C++ ����" }
{
    InitSuite();

    BOOK_EXPERIENCE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookExperience, TestingHelper)

void BookExperience::TestingHelper::InitSuite()
{
    AddEffectiveCppSuite();
    AddMoreEffectiveCppSuite();
    AddEffectiveSTLSuite();
    AddEffectiveModernCppSuite();

    AddExceptionalCppSuite();
    AddMoreExceptionalCppSuite();
    AddExceptionalCppStyleSuite();

    AddCppCommonKnowledgeSuite();
    AddCppCodingStandardsSuite();
}

void BookExperience::TestingHelper::AddEffectiveCppSuite()
{
    auto effectiveCppSuite = GenerateSuite("Effective C++");

    ADD_TEST(effectiveCppSuite, EffectiveCpp::EffectiveCppTerminologyTesting);
    ADD_TEST(effectiveCppSuite, EffectiveCpp::EffectiveCppNamingConventionsTesting);

    AddSuite(effectiveCppSuite);
}

void BookExperience::TestingHelper::AddMoreEffectiveCppSuite()
{
    auto moreEffectiveCppSuite = GenerateSuite("More Effective C++");

    ADD_TEST(moreEffectiveCppSuite, MoreEffectiveCpp::MoreEffectiveCppTerminologyTesting);

    AddSuite(moreEffectiveCppSuite);
}

void BookExperience::TestingHelper::AddEffectiveSTLSuite()
{
    auto effectiveSTLSuite = GenerateSuite("Effective STL");

    ADD_TEST(effectiveSTLSuite, EffectiveSTL::EffectiveSTLCodeExampleTesting);

    AddSuite(effectiveSTLSuite);
}

void BookExperience::TestingHelper::AddEffectiveModernCppSuite()
{
    auto effectiveModernCppSuite = GenerateSuite("Effective Modern C++");

    ADD_TEST(effectiveModernCppSuite, EffectiveModernCpp::Preface::EffectiveModernCppPrefaceExampleTesting);

    AddSuite(effectiveModernCppSuite);
}

void BookExperience::TestingHelper::AddExceptionalCppSuite()
{
    auto exceptionalCppSuite = GenerateSuite("Exceptional C++");

    ADD_TEST(exceptionalCppSuite, ExceptionalCpp::ExceptionalCppPlaceholderTesting);

    AddSuite(exceptionalCppSuite);
}

void BookExperience::TestingHelper::AddMoreExceptionalCppSuite()
{
    auto moreExceptionalCppSuite = GenerateSuite("More Exceptional C++");

    ADD_TEST(moreExceptionalCppSuite, MoreExceptionalCpp::MoreExceptionalCppPlaceholderTesting);

    AddSuite(moreExceptionalCppSuite);
}

void BookExperience::TestingHelper::AddExceptionalCppStyleSuite()
{
    auto exceptionalCppStyleSuite = GenerateSuite("C++ �������");

    ADD_TEST(exceptionalCppStyleSuite, ExceptionalCppStyle::ExceptionalCppStylePlaceholderTesting);

    AddSuite(exceptionalCppStyleSuite);
}

void BookExperience::TestingHelper::AddCppCommonKnowledgeSuite()
{
    auto cppCommonKnowledgeSuite = GenerateSuite("C++ ��֪�ػ�");

    ADD_TEST(cppCommonKnowledgeSuite, CppCommonKnowledge::CppCommonKnowledgeOverloadTesting);

    AddSuite(cppCommonKnowledgeSuite);
}

void BookExperience::TestingHelper::AddCppCodingStandardsSuite()
{
    auto cppCodingStandardsSuite = GenerateSuite("C++ ��̹淶");

    ADD_TEST(cppCodingStandardsSuite, CppCodingStandards::CppCodingStandardsPlaceholderTesting);

    AddSuite(cppCodingStandardsSuite);
}
