///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助测试版本：0.7.0.0 (2021/02/05 23:36)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelperDetail.h"
#include "Example/BookCpp/BookIntermediate/Helper/BookIntermediateClassInvariantMacro.h"

BookIntermediate::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "书籍 C++ 中级" }
{
    InitSuite();

    BOOK_INTERMEDIATE_SELF_CLASS_IS_VALID_1;
}   

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookIntermediate, TestingHelper)

void BookIntermediate::TestingHelper::InitSuite()
{
    AddTheCppProgrammingLanguageSuite();
    AddRuminationsOnCppSuite();
    AddEfficientCppPerformanceProgrammingTechniquesSuite();
    AddImperfectCppSuite();
    AddAppliedCppSuite();

    AddOptimizedCppSuite();
    AddCppFootprintAndPerformanceOptimizationSuite();
    AddCppProgrammingTodaySuite();
    AddCppGotchasSuite();

    AddCppInActionIndustrialStrengthProgrammingTechniquesSuite();
    AddCppStrategiesAndTacticsSuite();
    AddCppCookbookSuite();
    AddAdvancedCppSuite();

    AddProfessionalCppSuite();
    AddCoreCppASoftwareEnginearingApproachSuite();
    AddCppEffectiveObjectOrientedSoftwareConstructionSuite();
    AddHowNotToProgramInCppSuite();
}

void BookIntermediate::TestingHelper::AddTheCppProgrammingLanguageSuite()
{
    auto theCppProgrammingLanguageSuite = GenerateSuite("C++ 程序设计语言");

    theCppProgrammingLanguageSuite.AddSuite(GetTheCppProgrammingLanguageSpecialEditionSuite());
    theCppProgrammingLanguageSuite.AddSuite(GetTheCppProgrammingLanguageSpecialEditionExerciseSuite());
    theCppProgrammingLanguageSuite.AddSuite(GetTheCppProgrammingLanguageFourthEditionSuite());

    AddSuite(theCppProgrammingLanguageSuite);
}

CoreTools::Suite BookIntermediate::TestingHelper::GetTheCppProgrammingLanguageSpecialEditionSuite()
{
    auto theCppProgrammingLanguageSpecialEditionSuite = GenerateSuite("C++ 程序设计语言 特别版");

    ADD_TEST(theCppProgrammingLanguageSpecialEditionSuite, TheCppProgrammingLanguage::TheCppProgrammingLanguageSpecialEditionPlaceholderTesting);

    return theCppProgrammingLanguageSpecialEditionSuite;
}

CoreTools::Suite BookIntermediate::TestingHelper::GetTheCppProgrammingLanguageSpecialEditionExerciseSuite()
{
    auto theCppProgrammingLanguageSpecialEditionExerciseSuite = GenerateSuite("C++ 程序设计语言 特别版 练习");

    ADD_TEST(theCppProgrammingLanguageSpecialEditionExerciseSuite, TheCppProgrammingLanguage::TheCppProgrammingLanguageSpecialEditionExercisePlaceholderTesting);

    return theCppProgrammingLanguageSpecialEditionExerciseSuite;
}

CoreTools::Suite BookIntermediate::TestingHelper::GetTheCppProgrammingLanguageFourthEditionSuite()
{
    auto theCppProgrammingLanguageFourthEditionSuite = GenerateSuite("C++ 程序设计语言 第4版");

    ADD_TEST(theCppProgrammingLanguageFourthEditionSuite, TheCppProgrammingLanguage::TheCppProgrammingLanguageFourthEditionPlaceholderTesting);

    return theCppProgrammingLanguageFourthEditionSuite;
}

void BookIntermediate::TestingHelper::AddRuminationsOnCppSuite()
{
    auto ruminationsOnCppSuite = GenerateSuite("C++ 沉思录");

    ADD_TEST(ruminationsOnCppSuite, RuminationsOnCpp::RuminationsOnCppPlaceholderTesting);

    AddSuite(ruminationsOnCppSuite);
}

void BookIntermediate::TestingHelper::AddEfficientCppPerformanceProgrammingTechniquesSuite()
{
    auto efficientCppPerformanceProgrammingTechniquesSuite = GenerateSuite("提高C++性能的编程技术");

    ADD_TEST(efficientCppPerformanceProgrammingTechniquesSuite, EfficientCppPerformanceProgrammingTechniques::EfficientCppPerformanceProgrammingTechniquesPlaceholderTesting);

    AddSuite(efficientCppPerformanceProgrammingTechniquesSuite);
}

void BookIntermediate::TestingHelper::AddImperfectCppSuite()
{
    auto imperfectCppSuite = GenerateSuite("Imperfect C++");

    ADD_TEST(imperfectCppSuite, ImperfectCpp::ImperfectCppPlaceholderTesting);

    AddSuite(imperfectCppSuite);
}

void BookIntermediate::TestingHelper::AddAppliedCppSuite()
{
    auto appliedCppSuite = GenerateSuite("Applied C++");

    ADD_TEST(appliedCppSuite, AppliedCpp::AppliedCppChapter2MainTesting);

    AddSuite(appliedCppSuite);
}

void BookIntermediate::TestingHelper::AddOptimizedCppSuite()
{
    auto optimizedCppSuite = GenerateSuite("C++ 性能优化指南");

    ADD_TEST(optimizedCppSuite, OptimizedCpp::OptimizedCppPlaceholderTesting);

    AddSuite(optimizedCppSuite);
}

void BookIntermediate::TestingHelper::AddCppFootprintAndPerformanceOptimizationSuite()
{
    auto cppFootprintAndPerformanceOptimizationSuite = GenerateSuite("C++ 高效编程：内存与性能优化");

    ADD_TEST(cppFootprintAndPerformanceOptimizationSuite, CppFootprintAndPerformanceOptimization::CppFootprintAndPerformanceOptimizationPlaceholderTesting);

    AddSuite(cppFootprintAndPerformanceOptimizationSuite);
}

void BookIntermediate::TestingHelper::AddCppProgrammingTodaySuite()
{
    auto cppProgrammingTodaySuite = GenerateSuite("现代C++程序设计");

    ADD_TEST(cppProgrammingTodaySuite, CppProgrammingToday::CppProgrammingTodayPlaceholderTesting);

    AddSuite(cppProgrammingTodaySuite);
}

void BookIntermediate::TestingHelper::AddCppGotchasSuite()
{
    auto cppGotchasSuite = GenerateSuite("C++ 程序设计陷阱");

    ADD_TEST(cppGotchasSuite, CppGotchas::CppGotchasPlaceholderTesting);

    AddSuite(cppGotchasSuite);
}

void BookIntermediate::TestingHelper::AddCppInActionIndustrialStrengthProgrammingTechniquesSuite()
{
    auto cppInActionIndustrialStrengthProgrammingTechniquesSuite = GenerateSuite("C++ 实践之路");

    ADD_TEST(cppInActionIndustrialStrengthProgrammingTechniquesSuite, CppInActionIndustrialStrengthProgrammingTechniques::CppInActionIndustrialStrengthProgrammingTechniquesPlaceholderTesting);

    AddSuite(cppInActionIndustrialStrengthProgrammingTechniquesSuite);
}

void BookIntermediate::TestingHelper::AddCppStrategiesAndTacticsSuite()
{
    auto cppStrategiesAndTacticsSuite = GenerateSuite("C++ 编程惯用法——高级程序员常用方法和技巧");

    ADD_TEST(cppStrategiesAndTacticsSuite, CppStrategiesAndTactics::CppStrategiesAndTacticsPlaceholderTesting);

    AddSuite(cppStrategiesAndTacticsSuite);
}

void BookIntermediate::TestingHelper::AddCppCookbookSuite()
{
    auto cppCookbookSuite = GenerateSuite("C++ Cookbook");

    ADD_TEST(cppCookbookSuite, CppCookbook::CppCookbookPlaceholderTesting);

    AddSuite(cppCookbookSuite);
}

void BookIntermediate::TestingHelper::AddAdvancedCppSuite()
{
    auto advancedCppSuite = GenerateSuite("Advanced C++");

    ADD_TEST(advancedCppSuite, AdvancedCpp::AdvancedCppPlaceholderTesting);

    AddSuite(advancedCppSuite);
}

void BookIntermediate::TestingHelper::AddProfessionalCppSuite()
{
    auto professionalCppSuite = GenerateSuite("C++ 高级编程");

    ADD_TEST(professionalCppSuite, ProfessionalCpp::ProfessionalCppPlaceholderTesting);

    AddSuite(professionalCppSuite);
}

void BookIntermediate::TestingHelper::AddCoreCppASoftwareEnginearingApproachSuite()
{
    auto coreCppASoftwareEnginearingApproachSuite = GenerateSuite("C++ 精髓——软件工程方法");

    ADD_TEST(coreCppASoftwareEnginearingApproachSuite, CoreCppASoftwareEnginearingApproach::CoreCppASoftwareEnginearingApproachPlaceholderTesting);

    AddSuite(coreCppASoftwareEnginearingApproachSuite);
}

void BookIntermediate::TestingHelper::AddCppEffectiveObjectOrientedSoftwareConstructionSuite()
{
    auto cppEffectiveObjectOrientedSoftwareConstructionSuite = GenerateSuite("C++ 面向对象高效编程");

    ADD_TEST(cppEffectiveObjectOrientedSoftwareConstructionSuite, CppEffectiveObjectOrientedSoftwareConstruction::CppEffectiveObjectOrientedSoftwareConstructionPlaceholderTesting);

    AddSuite(cppEffectiveObjectOrientedSoftwareConstructionSuite);
}

void BookIntermediate::TestingHelper::AddHowNotToProgramInCppSuite()
{
    auto howNotToProgramInCppSuite = GenerateSuite("捉虫历险记——常见C++ Bug大围剿");

    ADD_TEST(howNotToProgramInCppSuite, HowNotToProgramInCpp::HowNotToProgramInCppPlaceholderTesting);

    AddSuite(howNotToProgramInCppSuite);
}
