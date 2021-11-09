///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.2.5 (2021/11/02 22:56)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelperDetail.h"
#include "Example/BookOperatingSystem/BookConcurrentProgramming/Helper/BookConcurrentProgrammingClassInvariantMacro.h"

BookConcurrentProgramming::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "���鼮������ϵͳ��������̡���Ԫ�����׼�" }
{
    InitSuite();

    BOOK_CONCURRENT_PROGRAMMING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookConcurrentProgramming, TestingHelper)

void BookConcurrentProgramming::TestingHelper::InitSuite()
{
    AddConcurrentProgrammingOnWindowsSuite();
    AddParallelAndDistributedProgrammingUsingCppSuite();
    AddCppConcurrencyInActionSuite();
    AddCppMultithreadingCookbookSuite();

    AddMultithreadingApplicationsInWin32Suite();
    AddProfessionalMulticoreProgrammingSuite();
    AddObjectOrientedMultithreadingUsingCppSuite();
    AddDistributedSystemsSuite();
}

void BookConcurrentProgramming::TestingHelper::AddConcurrentProgrammingOnWindowsSuite()
{
    auto concurrentProgrammingOnWindowsSuite = GenerateSuite("Windows �������ָ��");

    ADD_TEST(concurrentProgrammingOnWindowsSuite, ConcurrentProgrammingOnWindows::ConcurrentProgrammingOnWindowsPlaceholderTesting);

    AddSuite(concurrentProgrammingOnWindowsSuite);
}

void BookConcurrentProgramming::TestingHelper::AddParallelAndDistributedProgrammingUsingCppSuite()
{
    auto parallelAndDistributedProgrammingUsingCppSuite = GenerateSuite("C++ ������ֲ�ʽ���");

    ADD_TEST(parallelAndDistributedProgrammingUsingCppSuite, ParallelAndDistributedProgrammingUsingCpp::ParallelAndDistributedProgrammingTesting);

    AddSuite(parallelAndDistributedProgrammingUsingCppSuite);
}

void BookConcurrentProgramming::TestingHelper::AddCppConcurrencyInActionSuite()
{
    auto cppConcurrencyInActionSuite = GenerateSuite("C++ �������ʵս");

    ADD_TEST(cppConcurrencyInActionSuite, CppConcurrencyInAction::CppConcurrencyInActionTesting);

    AddSuite(cppConcurrencyInActionSuite);
}

void BookConcurrentProgramming::TestingHelper::AddCppMultithreadingCookbookSuite()
{
    auto cppMultithreadingCookbookSuite = GenerateSuite("C++ ���̱߳��ʵս");

    ADD_TEST(cppMultithreadingCookbookSuite, CppMultithreadingCookbook::CppMultithreadingCookbookTesting);

    AddSuite(cppMultithreadingCookbookSuite);
}

void BookConcurrentProgramming::TestingHelper::AddMultithreadingApplicationsInWin32Suite()
{
    auto multithreadingApplicationsInWin32Suite = GenerateSuite("Win32 ���̳߳������");

    ADD_TEST(multithreadingApplicationsInWin32Suite, MultithreadingApplicationsInWin32::MultithreadingApplicationsInWin32Testing);

    AddSuite(multithreadingApplicationsInWin32Suite);
}

void BookConcurrentProgramming::TestingHelper::AddProfessionalMulticoreProgrammingSuite()
{
    auto professionalMulticoreProgrammingSuite = GenerateSuite("C++ ��˸߼����");

    ADD_TEST(professionalMulticoreProgrammingSuite, ProfessionalMulticoreProgramming::ProfessionalMulticoreProgrammingTesting);

    AddSuite(professionalMulticoreProgrammingSuite);
}

void BookConcurrentProgramming::TestingHelper::AddObjectOrientedMultithreadingUsingCppSuite()
{
    auto objectOrientedMultithreadingUsingCppSuite = GenerateSuite("C++ ���������̱߳��");

    ADD_TEST(objectOrientedMultithreadingUsingCppSuite, ObjectOrientedMultithreadingUsingCpp::ObjectOrientedMultithreadingUsingCppTesting);

    AddSuite(objectOrientedMultithreadingUsingCppSuite);
}

void BookConcurrentProgramming::TestingHelper::AddDistributedSystemsSuite()
{
    auto distributedSystemsSuite = GenerateSuite("�ֲ�ʽϵͳ�����������");

    ADD_TEST(distributedSystemsSuite, DistributedSystems::DistributedSystemsTesting);

    AddSuite(distributedSystemsSuite);
}
