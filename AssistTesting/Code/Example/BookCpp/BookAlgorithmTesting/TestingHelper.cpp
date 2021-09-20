///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助测试版本：0.7.0.1 (2021/02/15 1:07)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelperDetail.h"
#include "Example/BookCpp/BookAlgorithm/Helper/BookAlgorithmClassInvariantMacro.h"

BookAlgorithm::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "书籍 C++ 算法" }
{
    InitSuite();

    BOOK_ALGORITHM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookAlgorithm, TestingHelper)

void BookAlgorithm::TestingHelper::InitSuite()
{
    AddDiscreteMathematicsAndItsApplicationsSuite();
    AddIntroductionToAlgorithmsSuite();
    AddProgrammingPearlsSuite();
    AddTheArtOfComputerProgrammingSuite();
    AddAlgorithmsUnlockedSuite();

    AddCryptographyForDevelopersSuite();
    AddAlgorithmsSuite();
    AddAlgorithmsSanjoyDasguptaSuite();
    AddWriteGreatCodeSuite();
    AddHackersDelightSuite();

    AddPracticalAlgorithmsForProgrammersSuite();
    AddDataStructuresWithCppUsingSTLSuite();
    AddAppliedCryptographySuite();
    AddDataStructuresAndAlgorithmAnalysisInCppSuite();
    AddElementaryNumberTheoryAndItsApplicationsSuite();

    AddLinearAlgebraAndItsApplicationsSuite();
    AddDataStructuresAndAlgorithmsInCppSuite();
    AddAlgorithmicPuzzlesSuite();
    AddNumericalRecipesInCppSuite();
    AddConcreteMathematicSuite();

    AddGrokkingAlgorithmsSuite();
    AddHowToSolveSuite();
    AddIntroductionToTheDesignAndAnalysisOfAlgorithmsSuite();
    AddDataAbstractionAndProblemSolvingWithCppSuite();
}

void BookAlgorithm::TestingHelper::AddDiscreteMathematicsAndItsApplicationsSuite()
{
    auto discreteMathematicsAndItsApplicationsSuite = GenerateSuite("离散数学及其应用");

    discreteMathematicsAndItsApplicationsSuite.AddSuite(GetDiscreteMathematicsAndItsApplicationsSixthEditionSuite());
    discreteMathematicsAndItsApplicationsSuite.AddSuite(GetDiscreteMathematicsAndItsApplicationsSeventhEditionSuite());

    AddSuite(discreteMathematicsAndItsApplicationsSuite);
}

CoreTools::Suite BookAlgorithm::TestingHelper::GetDiscreteMathematicsAndItsApplicationsSixthEditionSuite()
{
    auto discreteMathematicsAndItsApplicationsSixthEditionSuite = GenerateSuite("离散数学及其应用 第6版");

    ADD_TEST(discreteMathematicsAndItsApplicationsSixthEditionSuite, DiscreteMathematicsAndItsApplications::DiscreteMathematicsAndItsApplicationsSixthEditionPlaceholderTesting);

    return discreteMathematicsAndItsApplicationsSixthEditionSuite;
}

CoreTools::Suite BookAlgorithm::TestingHelper::GetDiscreteMathematicsAndItsApplicationsSeventhEditionSuite()
{
    auto discreteMathematicsAndItsApplicationsSeventhEditionSuite = GenerateSuite("离散数学及其应用 第7版");

    ADD_TEST(discreteMathematicsAndItsApplicationsSeventhEditionSuite, DiscreteMathematicsAndItsApplications::DiscreteMathematicsAndItsApplicationsSeventhEditionPlaceholderTesting);

    return discreteMathematicsAndItsApplicationsSeventhEditionSuite;
}

void BookAlgorithm::TestingHelper::AddIntroductionToAlgorithmsSuite()
{
    auto introductionToAlgorithmsSuite = GenerateSuite("算法导论");

    introductionToAlgorithmsSuite.AddSuite(GetIntroductionToAlgorithmsSecondEditionSuite());
    introductionToAlgorithmsSuite.AddSuite(GetIntroductionToAlgorithmsThirdEditionSuite());

    AddSuite(introductionToAlgorithmsSuite);
}

CoreTools::Suite BookAlgorithm::TestingHelper::GetIntroductionToAlgorithmsSecondEditionSuite()
{
    auto introductionToAlgorithmsSecondEditionSuite = GenerateSuite("算法导论 第2版");

    ADD_TEST(introductionToAlgorithmsSecondEditionSuite, IntroductionToAlgorithms::IntroductionToAlgorithmsSecondEditionPlaceholderTesting);

    return introductionToAlgorithmsSecondEditionSuite;
}

CoreTools::Suite BookAlgorithm::TestingHelper::GetIntroductionToAlgorithmsThirdEditionSuite()
{
    auto introductionToAlgorithmsThirdEditionSuite = GenerateSuite("算法导论 第3版");

    ADD_TEST(introductionToAlgorithmsThirdEditionSuite, IntroductionToAlgorithms::IntroductionToAlgorithmsThirdEditionPlaceholderTesting);

    return introductionToAlgorithmsThirdEditionSuite;
}

void BookAlgorithm::TestingHelper::AddProgrammingPearlsSuite()
{
    auto programmingPearlsSuite = GenerateSuite("编程珠玑");

    programmingPearlsSuite.AddSuite(GetProgrammingPearlsOneSuite());
    programmingPearlsSuite.AddSuite(GetMoreProgrammingPearlsSuite());

    AddSuite(programmingPearlsSuite);
}

CoreTools::Suite BookAlgorithm::TestingHelper::GetProgrammingPearlsOneSuite()
{
    auto programmingPearlsOneSuite = GenerateSuite("编程珠玑");

    ADD_TEST(programmingPearlsOneSuite, ProgrammingPearls::ProgrammingPearlsOnePlaceholderTesting);

    return programmingPearlsOneSuite;
}

CoreTools::Suite BookAlgorithm::TestingHelper::GetMoreProgrammingPearlsSuite()
{
    auto moreProgrammingPearlsSuite = GenerateSuite("编程珠玑续");

    ADD_TEST(moreProgrammingPearlsSuite, ProgrammingPearls::MoreProgrammingPearlsPlaceholderTesting);

    return moreProgrammingPearlsSuite;
}

void BookAlgorithm::TestingHelper::AddTheArtOfComputerProgrammingSuite()
{
    auto theArtOfComputerProgrammingSuite = GenerateSuite("计算机程序设计的艺术");

    ADD_TEST(theArtOfComputerProgrammingSuite, TheArtOfComputerProgramming::TheArtOfComputerProgrammingPlaceholderTesting);

    AddSuite(theArtOfComputerProgrammingSuite);
}

void BookAlgorithm::TestingHelper::AddAlgorithmsUnlockedSuite()
{
    auto algorithmsUnlockedSuite = GenerateSuite("算法基础：打开算法之门");

    ADD_TEST(algorithmsUnlockedSuite, AlgorithmsUnlocked::AlgorithmsUnlockedPlaceholderTesting);

    AddSuite(algorithmsUnlockedSuite);
}

void BookAlgorithm::TestingHelper::AddCryptographyForDevelopersSuite()
{
    auto cryptographyForDevelopersSuite = GenerateSuite("程序员密码学");

    ADD_TEST(cryptographyForDevelopersSuite, CryptographyForDevelopers::CryptographyForDevelopersPlaceholderTesting);

    AddSuite(cryptographyForDevelopersSuite);
}

void BookAlgorithm::TestingHelper::AddAlgorithmsSuite()
{
    auto algorithmsSuite = GenerateSuite("算法");

    algorithmsSuite.AddSuite(GetAlgorithmsInCppParts1_4Suite());
    algorithmsSuite.AddSuite(GetAlgorithmsInCppParts5Suite());
    algorithmsSuite.AddSuite(GetAlgorithmsFourthEditionSuite());

    AddSuite(algorithmsSuite);
}

CoreTools::Suite BookAlgorithm::TestingHelper::GetAlgorithmsInCppParts1_4Suite()
{
    auto algorithmsInCppParts1_4Suite = GenerateSuite("算法I-IV（C++实现）");

    ADD_TEST(algorithmsInCppParts1_4Suite, Algorithms::AlgorithmsInCppParts1_4PlaceholderTesting);

    return algorithmsInCppParts1_4Suite;
}

CoreTools::Suite BookAlgorithm::TestingHelper::GetAlgorithmsInCppParts5Suite()
{
    auto algorithmsInCppParts5Suite = GenerateSuite("算法V（C++实现）");

    ADD_TEST(algorithmsInCppParts5Suite, Algorithms::AlgorithmsInCppParts5PlaceholderTesting);

    return algorithmsInCppParts5Suite;
}

CoreTools::Suite BookAlgorithm::TestingHelper::GetAlgorithmsFourthEditionSuite()
{
    auto algorithmsFourthEditionSuite = GenerateSuite("算法 第四版");

    ADD_TEST(algorithmsFourthEditionSuite, Algorithms::AlgorithmsFourthEditionPlaceholderTesting);

    return algorithmsFourthEditionSuite;
}

void BookAlgorithm::TestingHelper::AddAlgorithmsSanjoyDasguptaSuite()
{
    auto algorithmsSanjoyDasguptaSuite = GenerateSuite("算法概论");

    ADD_TEST(algorithmsSanjoyDasguptaSuite, AlgorithmsSanjoyDasgupta::AlgorithmsSanjoyDasguptaPlaceholderTesting);

    AddSuite(algorithmsSanjoyDasguptaSuite);
}

void BookAlgorithm::TestingHelper::AddWriteGreatCodeSuite()
{
    auto writeGreatCodeSuite = GenerateSuite("编程卓越之道");

    writeGreatCodeSuite.AddSuite(GetUnderstandingTheMachineSuite());
    writeGreatCodeSuite.AddSuite(GetThinkingLowLevelWritingHighLevelSuite());

    AddSuite(writeGreatCodeSuite);
}

CoreTools::Suite BookAlgorithm::TestingHelper::GetUnderstandingTheMachineSuite()
{
    auto understandingTheMachineSuite = GenerateSuite("编程卓越之道 第一卷：深入理解计算机");

    ADD_TEST(understandingTheMachineSuite, WriteGreatCode::UnderstandingTheMachinePlaceholderTesting);

    return understandingTheMachineSuite;
}

CoreTools::Suite BookAlgorithm::TestingHelper::GetThinkingLowLevelWritingHighLevelSuite()
{
    auto thinkingLowLevelWritingHighLevelSuite = GenerateSuite("编程卓越之道 第二卷：运用底层语言思想编写高级语言代码");

    ADD_TEST(thinkingLowLevelWritingHighLevelSuite, WriteGreatCode::ThinkingLowLevelWritingHighLevelPlaceholderTesting);

    return thinkingLowLevelWritingHighLevelSuite;
}

void BookAlgorithm::TestingHelper::AddHackersDelightSuite()
{
    auto hackersDelightSuite = GenerateSuite("高效程序的奥秘");

    ADD_TEST(hackersDelightSuite, HackersDelight::HackersDelightPrintItselfTesting);

    AddSuite(hackersDelightSuite);
}

void BookAlgorithm::TestingHelper::AddPracticalAlgorithmsForProgrammersSuite()
{
    auto practicalAlgorithmsForProgrammersSuite = GenerateSuite("程序员实用算法");

    ADD_TEST(practicalAlgorithmsForProgrammersSuite, PracticalAlgorithmsForProgrammers::PracticalAlgorithmsForProgrammersPlaceholderTesting);

    AddSuite(practicalAlgorithmsForProgrammersSuite);
}

void BookAlgorithm::TestingHelper::AddDataStructuresWithCppUsingSTLSuite()
{
    auto dataStructuresWithCppUsingSTLSuite = GenerateSuite("数据结构 C++语言描述");

    ADD_TEST(dataStructuresWithCppUsingSTLSuite, DataStructuresWithCppUsingSTL::DataStructuresWithCppUsingSTLPlaceholderTesting);

    AddSuite(dataStructuresWithCppUsingSTLSuite);
}

void BookAlgorithm::TestingHelper::AddAppliedCryptographySuite()
{
    auto appliedCryptographySuite = GenerateSuite("应用密码学：协议、算法与C源程序");

    ADD_TEST(appliedCryptographySuite, AppliedCryptography::AppliedCryptographyPlaceholderTesting);

    AddSuite(appliedCryptographySuite);
}

void BookAlgorithm::TestingHelper::AddDataStructuresAndAlgorithmAnalysisInCppSuite()
{
    auto dataStructuresAndAlgorithmAnalysisInCppSuite = GenerateSuite("数据结构与算法分析C++描述");

    ADD_TEST(dataStructuresAndAlgorithmAnalysisInCppSuite, DataStructuresAndAlgorithmAnalysisInCpp::DataStructuresAndAlgorithmAnalysisInCppPlaceholderTesting);

    AddSuite(dataStructuresAndAlgorithmAnalysisInCppSuite);
}

void BookAlgorithm::TestingHelper::AddElementaryNumberTheoryAndItsApplicationsSuite()
{
    auto elementaryNumberTheoryAndItsApplicationsSuite = GenerateSuite("初等数论及其应用");

    ADD_TEST(elementaryNumberTheoryAndItsApplicationsSuite, ElementaryNumberTheoryAndItsApplications::ElementaryNumberTheoryAndItsApplicationsPlaceholderTesting);

    AddSuite(elementaryNumberTheoryAndItsApplicationsSuite);
}

void BookAlgorithm::TestingHelper::AddLinearAlgebraAndItsApplicationsSuite()
{
    auto linearAlgebraAndItsApplicationsSuite = GenerateSuite("线性代数及其应用");

    ADD_TEST(linearAlgebraAndItsApplicationsSuite, LinearAlgebraAndItsApplications::LinearAlgebraAndItsApplicationsPlaceholderTesting);

    AddSuite(linearAlgebraAndItsApplicationsSuite);
}

void BookAlgorithm::TestingHelper::AddDataStructuresAndAlgorithmsInCppSuite()
{
    auto dataStructuresAndAlgorithmsInCppSuite = GenerateSuite("C++ 数据结构与算法");

    ADD_TEST(dataStructuresAndAlgorithmsInCppSuite, DataStructuresAndAlgorithmsInCpp::DataStructuresAndAlgorithmsInCppPlaceholderTesting);

    AddSuite(dataStructuresAndAlgorithmsInCppSuite);
}

void BookAlgorithm::TestingHelper::AddAlgorithmicPuzzlesSuite()
{
    auto algorithmicPuzzlesSuite = GenerateSuite("算法谜题");

    ADD_TEST(algorithmicPuzzlesSuite, AlgorithmicPuzzles::AlgorithmicPuzzlesPlaceholderTesting);

    AddSuite(algorithmicPuzzlesSuite);
}

void BookAlgorithm::TestingHelper::AddNumericalRecipesInCppSuite()
{
    auto numericalRecipesInCppSuite = GenerateSuite("C++ 数值算法");

    ADD_TEST(numericalRecipesInCppSuite, NumericalRecipesInCpp::NumericalRecipesInCppPlaceholderTesting);

    AddSuite(numericalRecipesInCppSuite);
}

void BookAlgorithm::TestingHelper::AddConcreteMathematicSuite()
{
    auto concreteMathematicSuite = GenerateSuite("具体数学");

    ADD_TEST(concreteMathematicSuite, ConcreteMathematic::ConcreteMathematicPlaceholderTesting);

    AddSuite(concreteMathematicSuite);
}

void BookAlgorithm::TestingHelper::AddGrokkingAlgorithmsSuite()
{
    auto grokkingAlgorithmsSuite = GenerateSuite("算法图解");

    ADD_TEST(grokkingAlgorithmsSuite, GrokkingAlgorithms::GrokkingAlgorithmsPlaceholderTesting);

    AddSuite(grokkingAlgorithmsSuite);
}

void BookAlgorithm::TestingHelper::AddHowToSolveSuite()
{
    auto howToSolveSuite = GenerateSuite("怎样解题");

    ADD_TEST(howToSolveSuite, HowToSolve::HowToSolvePlaceholderTesting);

    AddSuite(howToSolveSuite);
}

void BookAlgorithm::TestingHelper::AddIntroductionToTheDesignAndAnalysisOfAlgorithmsSuite()
{
    auto introductionToTheDesignAndAnalysisOfAlgorithmsSuite = GenerateSuite("算法设计与分析基础");

    ADD_TEST(introductionToTheDesignAndAnalysisOfAlgorithmsSuite, IntroductionToTheDesignAndAnalysisOfAlgorithms::IntroductionToTheDesignAndAnalysisOfAlgorithmsPlaceholderTesting);

    AddSuite(introductionToTheDesignAndAnalysisOfAlgorithmsSuite);
}

void BookAlgorithm::TestingHelper::AddDataAbstractionAndProblemSolvingWithCppSuite()
{
    auto dataAbstractionAndProblemSolvingWithCppSuite = GenerateSuite("C++ 数据抽象和问题求解");

    ADD_TEST(dataAbstractionAndProblemSolvingWithCppSuite, DataAbstractionAndProblemSolvingWithCpp::DataAbstractionAndProblemSolvingWithCppPlaceholderTesting);

    AddSuite(dataAbstractionAndProblemSolvingWithCppSuite);
}
