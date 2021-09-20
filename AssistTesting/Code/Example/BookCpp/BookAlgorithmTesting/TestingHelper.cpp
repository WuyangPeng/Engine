///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.0.1 (2021/02/15 1:07)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelperDetail.h"
#include "Example/BookCpp/BookAlgorithm/Helper/BookAlgorithmClassInvariantMacro.h"

BookAlgorithm::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "�鼮 C++ �㷨" }
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
    auto discreteMathematicsAndItsApplicationsSuite = GenerateSuite("��ɢ��ѧ����Ӧ��");

    discreteMathematicsAndItsApplicationsSuite.AddSuite(GetDiscreteMathematicsAndItsApplicationsSixthEditionSuite());
    discreteMathematicsAndItsApplicationsSuite.AddSuite(GetDiscreteMathematicsAndItsApplicationsSeventhEditionSuite());

    AddSuite(discreteMathematicsAndItsApplicationsSuite);
}

CoreTools::Suite BookAlgorithm::TestingHelper::GetDiscreteMathematicsAndItsApplicationsSixthEditionSuite()
{
    auto discreteMathematicsAndItsApplicationsSixthEditionSuite = GenerateSuite("��ɢ��ѧ����Ӧ�� ��6��");

    ADD_TEST(discreteMathematicsAndItsApplicationsSixthEditionSuite, DiscreteMathematicsAndItsApplications::DiscreteMathematicsAndItsApplicationsSixthEditionPlaceholderTesting);

    return discreteMathematicsAndItsApplicationsSixthEditionSuite;
}

CoreTools::Suite BookAlgorithm::TestingHelper::GetDiscreteMathematicsAndItsApplicationsSeventhEditionSuite()
{
    auto discreteMathematicsAndItsApplicationsSeventhEditionSuite = GenerateSuite("��ɢ��ѧ����Ӧ�� ��7��");

    ADD_TEST(discreteMathematicsAndItsApplicationsSeventhEditionSuite, DiscreteMathematicsAndItsApplications::DiscreteMathematicsAndItsApplicationsSeventhEditionPlaceholderTesting);

    return discreteMathematicsAndItsApplicationsSeventhEditionSuite;
}

void BookAlgorithm::TestingHelper::AddIntroductionToAlgorithmsSuite()
{
    auto introductionToAlgorithmsSuite = GenerateSuite("�㷨����");

    introductionToAlgorithmsSuite.AddSuite(GetIntroductionToAlgorithmsSecondEditionSuite());
    introductionToAlgorithmsSuite.AddSuite(GetIntroductionToAlgorithmsThirdEditionSuite());

    AddSuite(introductionToAlgorithmsSuite);
}

CoreTools::Suite BookAlgorithm::TestingHelper::GetIntroductionToAlgorithmsSecondEditionSuite()
{
    auto introductionToAlgorithmsSecondEditionSuite = GenerateSuite("�㷨���� ��2��");

    ADD_TEST(introductionToAlgorithmsSecondEditionSuite, IntroductionToAlgorithms::IntroductionToAlgorithmsSecondEditionPlaceholderTesting);

    return introductionToAlgorithmsSecondEditionSuite;
}

CoreTools::Suite BookAlgorithm::TestingHelper::GetIntroductionToAlgorithmsThirdEditionSuite()
{
    auto introductionToAlgorithmsThirdEditionSuite = GenerateSuite("�㷨���� ��3��");

    ADD_TEST(introductionToAlgorithmsThirdEditionSuite, IntroductionToAlgorithms::IntroductionToAlgorithmsThirdEditionPlaceholderTesting);

    return introductionToAlgorithmsThirdEditionSuite;
}

void BookAlgorithm::TestingHelper::AddProgrammingPearlsSuite()
{
    auto programmingPearlsSuite = GenerateSuite("�������");

    programmingPearlsSuite.AddSuite(GetProgrammingPearlsOneSuite());
    programmingPearlsSuite.AddSuite(GetMoreProgrammingPearlsSuite());

    AddSuite(programmingPearlsSuite);
}

CoreTools::Suite BookAlgorithm::TestingHelper::GetProgrammingPearlsOneSuite()
{
    auto programmingPearlsOneSuite = GenerateSuite("�������");

    ADD_TEST(programmingPearlsOneSuite, ProgrammingPearls::ProgrammingPearlsOnePlaceholderTesting);

    return programmingPearlsOneSuite;
}

CoreTools::Suite BookAlgorithm::TestingHelper::GetMoreProgrammingPearlsSuite()
{
    auto moreProgrammingPearlsSuite = GenerateSuite("���������");

    ADD_TEST(moreProgrammingPearlsSuite, ProgrammingPearls::MoreProgrammingPearlsPlaceholderTesting);

    return moreProgrammingPearlsSuite;
}

void BookAlgorithm::TestingHelper::AddTheArtOfComputerProgrammingSuite()
{
    auto theArtOfComputerProgrammingSuite = GenerateSuite("�����������Ƶ�����");

    ADD_TEST(theArtOfComputerProgrammingSuite, TheArtOfComputerProgramming::TheArtOfComputerProgrammingPlaceholderTesting);

    AddSuite(theArtOfComputerProgrammingSuite);
}

void BookAlgorithm::TestingHelper::AddAlgorithmsUnlockedSuite()
{
    auto algorithmsUnlockedSuite = GenerateSuite("�㷨���������㷨֮��");

    ADD_TEST(algorithmsUnlockedSuite, AlgorithmsUnlocked::AlgorithmsUnlockedPlaceholderTesting);

    AddSuite(algorithmsUnlockedSuite);
}

void BookAlgorithm::TestingHelper::AddCryptographyForDevelopersSuite()
{
    auto cryptographyForDevelopersSuite = GenerateSuite("����Ա����ѧ");

    ADD_TEST(cryptographyForDevelopersSuite, CryptographyForDevelopers::CryptographyForDevelopersPlaceholderTesting);

    AddSuite(cryptographyForDevelopersSuite);
}

void BookAlgorithm::TestingHelper::AddAlgorithmsSuite()
{
    auto algorithmsSuite = GenerateSuite("�㷨");

    algorithmsSuite.AddSuite(GetAlgorithmsInCppParts1_4Suite());
    algorithmsSuite.AddSuite(GetAlgorithmsInCppParts5Suite());
    algorithmsSuite.AddSuite(GetAlgorithmsFourthEditionSuite());

    AddSuite(algorithmsSuite);
}

CoreTools::Suite BookAlgorithm::TestingHelper::GetAlgorithmsInCppParts1_4Suite()
{
    auto algorithmsInCppParts1_4Suite = GenerateSuite("�㷨I-IV��C++ʵ�֣�");

    ADD_TEST(algorithmsInCppParts1_4Suite, Algorithms::AlgorithmsInCppParts1_4PlaceholderTesting);

    return algorithmsInCppParts1_4Suite;
}

CoreTools::Suite BookAlgorithm::TestingHelper::GetAlgorithmsInCppParts5Suite()
{
    auto algorithmsInCppParts5Suite = GenerateSuite("�㷨V��C++ʵ�֣�");

    ADD_TEST(algorithmsInCppParts5Suite, Algorithms::AlgorithmsInCppParts5PlaceholderTesting);

    return algorithmsInCppParts5Suite;
}

CoreTools::Suite BookAlgorithm::TestingHelper::GetAlgorithmsFourthEditionSuite()
{
    auto algorithmsFourthEditionSuite = GenerateSuite("�㷨 ���İ�");

    ADD_TEST(algorithmsFourthEditionSuite, Algorithms::AlgorithmsFourthEditionPlaceholderTesting);

    return algorithmsFourthEditionSuite;
}

void BookAlgorithm::TestingHelper::AddAlgorithmsSanjoyDasguptaSuite()
{
    auto algorithmsSanjoyDasguptaSuite = GenerateSuite("�㷨����");

    ADD_TEST(algorithmsSanjoyDasguptaSuite, AlgorithmsSanjoyDasgupta::AlgorithmsSanjoyDasguptaPlaceholderTesting);

    AddSuite(algorithmsSanjoyDasguptaSuite);
}

void BookAlgorithm::TestingHelper::AddWriteGreatCodeSuite()
{
    auto writeGreatCodeSuite = GenerateSuite("���׿Խ֮��");

    writeGreatCodeSuite.AddSuite(GetUnderstandingTheMachineSuite());
    writeGreatCodeSuite.AddSuite(GetThinkingLowLevelWritingHighLevelSuite());

    AddSuite(writeGreatCodeSuite);
}

CoreTools::Suite BookAlgorithm::TestingHelper::GetUnderstandingTheMachineSuite()
{
    auto understandingTheMachineSuite = GenerateSuite("���׿Խ֮�� ��һ�������������");

    ADD_TEST(understandingTheMachineSuite, WriteGreatCode::UnderstandingTheMachinePlaceholderTesting);

    return understandingTheMachineSuite;
}

CoreTools::Suite BookAlgorithm::TestingHelper::GetThinkingLowLevelWritingHighLevelSuite()
{
    auto thinkingLowLevelWritingHighLevelSuite = GenerateSuite("���׿Խ֮�� �ڶ������õײ�����˼���д�߼����Դ���");

    ADD_TEST(thinkingLowLevelWritingHighLevelSuite, WriteGreatCode::ThinkingLowLevelWritingHighLevelPlaceholderTesting);

    return thinkingLowLevelWritingHighLevelSuite;
}

void BookAlgorithm::TestingHelper::AddHackersDelightSuite()
{
    auto hackersDelightSuite = GenerateSuite("��Ч����İ���");

    ADD_TEST(hackersDelightSuite, HackersDelight::HackersDelightPrintItselfTesting);

    AddSuite(hackersDelightSuite);
}

void BookAlgorithm::TestingHelper::AddPracticalAlgorithmsForProgrammersSuite()
{
    auto practicalAlgorithmsForProgrammersSuite = GenerateSuite("����Աʵ���㷨");

    ADD_TEST(practicalAlgorithmsForProgrammersSuite, PracticalAlgorithmsForProgrammers::PracticalAlgorithmsForProgrammersPlaceholderTesting);

    AddSuite(practicalAlgorithmsForProgrammersSuite);
}

void BookAlgorithm::TestingHelper::AddDataStructuresWithCppUsingSTLSuite()
{
    auto dataStructuresWithCppUsingSTLSuite = GenerateSuite("���ݽṹ C++��������");

    ADD_TEST(dataStructuresWithCppUsingSTLSuite, DataStructuresWithCppUsingSTL::DataStructuresWithCppUsingSTLPlaceholderTesting);

    AddSuite(dataStructuresWithCppUsingSTLSuite);
}

void BookAlgorithm::TestingHelper::AddAppliedCryptographySuite()
{
    auto appliedCryptographySuite = GenerateSuite("Ӧ������ѧ��Э�顢�㷨��CԴ����");

    ADD_TEST(appliedCryptographySuite, AppliedCryptography::AppliedCryptographyPlaceholderTesting);

    AddSuite(appliedCryptographySuite);
}

void BookAlgorithm::TestingHelper::AddDataStructuresAndAlgorithmAnalysisInCppSuite()
{
    auto dataStructuresAndAlgorithmAnalysisInCppSuite = GenerateSuite("���ݽṹ���㷨����C++����");

    ADD_TEST(dataStructuresAndAlgorithmAnalysisInCppSuite, DataStructuresAndAlgorithmAnalysisInCpp::DataStructuresAndAlgorithmAnalysisInCppPlaceholderTesting);

    AddSuite(dataStructuresAndAlgorithmAnalysisInCppSuite);
}

void BookAlgorithm::TestingHelper::AddElementaryNumberTheoryAndItsApplicationsSuite()
{
    auto elementaryNumberTheoryAndItsApplicationsSuite = GenerateSuite("�������ۼ���Ӧ��");

    ADD_TEST(elementaryNumberTheoryAndItsApplicationsSuite, ElementaryNumberTheoryAndItsApplications::ElementaryNumberTheoryAndItsApplicationsPlaceholderTesting);

    AddSuite(elementaryNumberTheoryAndItsApplicationsSuite);
}

void BookAlgorithm::TestingHelper::AddLinearAlgebraAndItsApplicationsSuite()
{
    auto linearAlgebraAndItsApplicationsSuite = GenerateSuite("���Դ�������Ӧ��");

    ADD_TEST(linearAlgebraAndItsApplicationsSuite, LinearAlgebraAndItsApplications::LinearAlgebraAndItsApplicationsPlaceholderTesting);

    AddSuite(linearAlgebraAndItsApplicationsSuite);
}

void BookAlgorithm::TestingHelper::AddDataStructuresAndAlgorithmsInCppSuite()
{
    auto dataStructuresAndAlgorithmsInCppSuite = GenerateSuite("C++ ���ݽṹ���㷨");

    ADD_TEST(dataStructuresAndAlgorithmsInCppSuite, DataStructuresAndAlgorithmsInCpp::DataStructuresAndAlgorithmsInCppPlaceholderTesting);

    AddSuite(dataStructuresAndAlgorithmsInCppSuite);
}

void BookAlgorithm::TestingHelper::AddAlgorithmicPuzzlesSuite()
{
    auto algorithmicPuzzlesSuite = GenerateSuite("�㷨����");

    ADD_TEST(algorithmicPuzzlesSuite, AlgorithmicPuzzles::AlgorithmicPuzzlesPlaceholderTesting);

    AddSuite(algorithmicPuzzlesSuite);
}

void BookAlgorithm::TestingHelper::AddNumericalRecipesInCppSuite()
{
    auto numericalRecipesInCppSuite = GenerateSuite("C++ ��ֵ�㷨");

    ADD_TEST(numericalRecipesInCppSuite, NumericalRecipesInCpp::NumericalRecipesInCppPlaceholderTesting);

    AddSuite(numericalRecipesInCppSuite);
}

void BookAlgorithm::TestingHelper::AddConcreteMathematicSuite()
{
    auto concreteMathematicSuite = GenerateSuite("������ѧ");

    ADD_TEST(concreteMathematicSuite, ConcreteMathematic::ConcreteMathematicPlaceholderTesting);

    AddSuite(concreteMathematicSuite);
}

void BookAlgorithm::TestingHelper::AddGrokkingAlgorithmsSuite()
{
    auto grokkingAlgorithmsSuite = GenerateSuite("�㷨ͼ��");

    ADD_TEST(grokkingAlgorithmsSuite, GrokkingAlgorithms::GrokkingAlgorithmsPlaceholderTesting);

    AddSuite(grokkingAlgorithmsSuite);
}

void BookAlgorithm::TestingHelper::AddHowToSolveSuite()
{
    auto howToSolveSuite = GenerateSuite("��������");

    ADD_TEST(howToSolveSuite, HowToSolve::HowToSolvePlaceholderTesting);

    AddSuite(howToSolveSuite);
}

void BookAlgorithm::TestingHelper::AddIntroductionToTheDesignAndAnalysisOfAlgorithmsSuite()
{
    auto introductionToTheDesignAndAnalysisOfAlgorithmsSuite = GenerateSuite("�㷨������������");

    ADD_TEST(introductionToTheDesignAndAnalysisOfAlgorithmsSuite, IntroductionToTheDesignAndAnalysisOfAlgorithms::IntroductionToTheDesignAndAnalysisOfAlgorithmsPlaceholderTesting);

    AddSuite(introductionToTheDesignAndAnalysisOfAlgorithmsSuite);
}

void BookAlgorithm::TestingHelper::AddDataAbstractionAndProblemSolvingWithCppSuite()
{
    auto dataAbstractionAndProblemSolvingWithCppSuite = GenerateSuite("C++ ���ݳ�����������");

    ADD_TEST(dataAbstractionAndProblemSolvingWithCppSuite, DataAbstractionAndProblemSolvingWithCpp::DataAbstractionAndProblemSolvingWithCppPlaceholderTesting);

    AddSuite(dataAbstractionAndProblemSolvingWithCppSuite);
}
