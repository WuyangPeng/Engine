///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.0.0 (2021/02/06 1:18)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelperDetail.h"
#include "Example/BookCpp/BookPrimary/Helper/BookPrimaryClassInvariantMacro.h"

BookPrimary::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "�鼮 C++ ����" }
{
    InitSuite();

    BOOK_PRIMARY_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookPrimary, TestingHelper)

void BookPrimary::TestingHelper::InitSuite()
{
    AddThinkingInCppSuite();
    AddCppPrimerSuite();
    AddCppHowToProgramSuite();
    AddProgrammingPrinciplesAndPracticeUsingCppSuite();
    AddATourOfCppSuite();

    AddEssentialCppSuite();
    AddCppADialogSuite();
    AddSamsTeachYourselfCppInOneHourADaySuite();
    AddCppPrimerPlusSuite();
    AddBeginningCpp17Suite();

    AddAcceleratedCppSuite();
    AddCppForTheImpatientSuite();
    AddProblemSolvingWithCppSuite();
    AddCppProgrammingSuite();
    AddCAndCppCodeCapsulesSuite();

    AddCppDistilledSuite();
    AddComputingConceptsWithCppEssentialsSuite();
    AddCppTheCompleteReferenceSuite();
    AddCppTheCoreLanguageSuite();
}

void BookPrimary::TestingHelper::AddThinkingInCppSuite()
{
    auto thinkingInCppSuite = GenerateSuite("C++ ����˼��");

    thinkingInCppSuite.AddSuite(GetThinkingInCppVolumeOneSuite());
    thinkingInCppSuite.AddSuite(GetThinkingInCppVolumeOneExerciseSuite());
    thinkingInCppSuite.AddSuite(GetThinkingInCppVolumeTwoSuite());

    AddSuite(thinkingInCppSuite);
}

CoreTools::Suite BookPrimary::TestingHelper::GetThinkingInCppVolumeOneSuite()
{
    auto introductionToStandardCppSuite = GenerateSuite("��1�� ��׼C++����");

    ADD_TEST(introductionToStandardCppSuite, ThinkingInCpp::IntroductionToStandardCppPlaceholderTesting);

    return introductionToStandardCppSuite;
}

CoreTools::Suite BookPrimary::TestingHelper::GetThinkingInCppVolumeOneExerciseSuite()
{
    auto introductionToStandardCppExerciseSuite = GenerateSuite("��1�� ��׼C++���� ��ϰ");

    ADD_TEST(introductionToStandardCppExerciseSuite, ThinkingInCpp::IntroductionToStandardCppExercisePlaceholderTesting);

    return introductionToStandardCppExerciseSuite;
}

CoreTools::Suite BookPrimary::TestingHelper::GetThinkingInCppVolumeTwoSuite()
{
    auto practicalProgrammingSuite = GenerateSuite("��2�� ʵ�ñ�̼���");

    ADD_TEST(practicalProgrammingSuite, ThinkingInCpp::PracticalProgrammingPlaceholderTesting);

    return practicalProgrammingSuite;
}

void BookPrimary::TestingHelper::AddCppPrimerSuite()
{
    auto cppPrimerSuite = GenerateSuite("C++ Primer");

    cppPrimerSuite.AddSuite(GetCppPrimerFourthEditionSuite());
    cppPrimerSuite.AddSuite(GetCppPrimerFifthEditionSuite());

    AddSuite(cppPrimerSuite);
}

CoreTools::Suite BookPrimary::TestingHelper::GetCppPrimerFourthEditionSuite()
{
    auto cppPrimerFourthEditionSuite = GenerateSuite("C++ Primer ��4��");

    ADD_TEST(cppPrimerFourthEditionSuite, CppPrimer::CppPrimerFourthEditionPlaceholderTesting);

    return cppPrimerFourthEditionSuite;
}

CoreTools::Suite BookPrimary::TestingHelper::GetCppPrimerFifthEditionSuite()
{
    auto cppPrimerFifthEditionSuite = GenerateSuite("C++ Primer ��5��");

    ADD_TEST(cppPrimerFifthEditionSuite, CppPrimer::CppPrimerFifthEditionPlaceholderTesting);

    return cppPrimerFifthEditionSuite;
}

void BookPrimary::TestingHelper::AddCppHowToProgramSuite()
{
    auto cppHowToProgramSuite = GenerateSuite("C++ ��ѧ�̳�");

    cppHowToProgramSuite.AddSuite(GetHowToProgramSeventhEditionSuite());
    cppHowToProgramSuite.AddSuite(GetHowToProgramNinthEditionSuite());

    AddSuite(cppHowToProgramSuite);
}

CoreTools::Suite BookPrimary::TestingHelper::GetHowToProgramSeventhEditionSuite()
{
    auto cppHowToProgramSeventhEditionSuite = GenerateSuite("C++ ��ѧ�̳� ��7��");

    ADD_TEST(cppHowToProgramSeventhEditionSuite, CppHowToProgram::CppHowToProgramSeventhEditionPlaceholderTesting);

    return cppHowToProgramSeventhEditionSuite;
}

CoreTools::Suite BookPrimary::TestingHelper::GetHowToProgramNinthEditionSuite()
{
    auto cppHowToProgramNinthEditionSuite = GenerateSuite("C++ ��ѧ�̳� ��9��");

    ADD_TEST(cppHowToProgramNinthEditionSuite, CppHowToProgram::CppHowToProgramNinthEditionPlaceholderTesting);

    return cppHowToProgramNinthEditionSuite;
}

void BookPrimary::TestingHelper::AddProgrammingPrinciplesAndPracticeUsingCppSuite()
{
    auto programmingPrinciplesAndPracticeUsingCppSuite = GenerateSuite("C++ �������ԭ����ʵ��");

    ADD_TEST(programmingPrinciplesAndPracticeUsingCppSuite, ProgrammingPrinciplesAndPracticeUsingCpp::ISOStandardCppTesting);

    AddSuite(programmingPrinciplesAndPracticeUsingCppSuite);
}

void BookPrimary::TestingHelper::AddATourOfCppSuite()
{
    auto aTourOfCppSuite = GenerateSuite("C++ ���Ե�ѧ");

    ADD_TEST(aTourOfCppSuite, ATourOfCpp::ATourOfCppPlaceholderTesting);

    AddSuite(aTourOfCppSuite);
}

void BookPrimary::TestingHelper::AddEssentialCppSuite()
{
    auto essentialCppSuite = GenerateSuite("Essential C++");

    ADD_TEST(essentialCppSuite, EssentialCpp::EssentialCppPlaceholderTesting);

    AddSuite(essentialCppSuite);
}

void BookPrimary::TestingHelper::AddCppADialogSuite()
{
    auto cppADialogSuite = GenerateSuite("C++ ��̻���");

    ADD_TEST(cppADialogSuite, CppADialog::CppADialogPlaceholderTesting);

    AddSuite(cppADialogSuite);
}

void BookPrimary::TestingHelper::AddSamsTeachYourselfCppInOneHourADaySuite()
{
    auto samsTeachYourselfCppInOneHourADaySuit = GenerateSuite("21��ѧͨC++");

    ADD_TEST(samsTeachYourselfCppInOneHourADaySuit, SamsTeachYourselfCppInOneHourADay::SamsTeachYourselfCppInOneHourADayPlaceholderTesting);

    AddSuite(samsTeachYourselfCppInOneHourADaySuit);
}

void BookPrimary::TestingHelper::AddCppPrimerPlusSuite()
{
    auto cppPrimerPlusSuite = GenerateSuite("C++ Primer Plus");

    ADD_TEST(cppPrimerPlusSuite, CppPrimerPlus::BookConventionTesting);

    AddSuite(cppPrimerPlusSuite);
}

void BookPrimary::TestingHelper::AddBeginningCpp17Suite()
{
    auto beginningCpp17Suite = GenerateSuite("C++17 ���ž���");

    ADD_TEST(beginningCpp17Suite, BeginningCpp17::BeginningCpp17PlaceholderTesting);

    AddSuite(beginningCpp17Suite);
}

void BookPrimary::TestingHelper::AddAcceleratedCppSuite()
{
    auto acceleratedCppSuite = GenerateSuite("Accelerated C++");

    ADD_TEST(acceleratedCppSuite, AcceleratedCpp::AcceleratedCppPlaceholderTesting);

    AddSuite(acceleratedCppSuite);
}

void BookPrimary::TestingHelper::AddCppForTheImpatientSuite()
{
    auto cppForTheImpatientSuite = GenerateSuite("д����æ�˿���C++");

    ADD_TEST(cppForTheImpatientSuite, CppForTheImpatient::CppForTheImpatientPlaceholderTesting);

    AddSuite(cppForTheImpatientSuite);
}

void BookPrimary::TestingHelper::AddProblemSolvingWithCppSuite()
{
    auto problemSolvingWithCppSuite = GenerateSuite("C++ ���ž���");

    ADD_TEST(problemSolvingWithCppSuite, ProblemSolvingWithCpp::ProblemSolvingWithCppPlaceholderTesting);

    AddSuite(problemSolvingWithCppSuite);
}

void BookPrimary::TestingHelper::AddCppProgrammingSuite()
{
    auto cppProgrammingSuite = GenerateSuite("д����ҿ���C++��");

    ADD_TEST(cppProgrammingSuite, CppProgramming::CppProgrammingHelloTesting);

    AddSuite(cppProgrammingSuite);
}

void BookPrimary::TestingHelper::AddCAndCppCodeCapsulesSuite()
{
    auto cAndCppCodeCapsulesSuite = GenerateSuite("C��C++���뾫��");

    ADD_TEST(cAndCppCodeCapsulesSuite, CAndCppCodeCapsules::CAndCppCodeCapsulesPlaceholderTesting);

    AddSuite(cAndCppCodeCapsulesSuite);
}

void BookPrimary::TestingHelper::AddCppDistilledSuite()
{
    auto cppDistilledSuite = GenerateSuite("C++ ����");

    ADD_TEST(cppDistilledSuite, CppDistilled::CppDistilledHello1Testing);

    AddSuite(cppDistilledSuite);
}

void BookPrimary::TestingHelper::AddComputingConceptsWithCppEssentialsSuite()
{
    auto computingConceptsWithCppEssentialsSuite = GenerateSuite("C++ ����˼��");

    ADD_TEST(computingConceptsWithCppEssentialsSuite, ComputingConceptsWithCppEssentials::ComputingConceptsWithCppEssentialsPlaceholderTesting);

    AddSuite(computingConceptsWithCppEssentialsSuite);
}

void BookPrimary::TestingHelper::AddCppTheCompleteReferenceSuite()
{
    auto cppTheCompleteReferenceSuite = GenerateSuite("C++ �ο���ȫ");

    ADD_TEST(cppTheCompleteReferenceSuite, CppTheCompleteReference::CppTheCompleteReferencePlaceholderTesting);

    AddSuite(cppTheCompleteReferenceSuite);
}

void BookPrimary::TestingHelper::AddCppTheCoreLanguageSuite()
{
    auto cppTheCoreLanguageSuite = GenerateSuite("C++ ���Ժ���");

    ADD_TEST(cppTheCoreLanguageSuite, CppTheCoreLanguage::CppTheCoreLanguagePlaceholderTesting);

    AddSuite(cppTheCoreLanguageSuite);
}
