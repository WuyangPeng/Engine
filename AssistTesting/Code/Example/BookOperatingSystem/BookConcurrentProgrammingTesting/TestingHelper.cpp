///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助测试版本：0.7.2.5 (2021/11/02 22:56)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelperDetail.h"
#include "Example/BookOperatingSystem/BookConcurrentProgramming/Helper/BookConcurrentProgrammingClassInvariantMacro.h"

BookConcurrentProgramming::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "【书籍·操作系统·并发编程】单元测试套件" }
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
    auto concurrentProgrammingOnWindowsSuite = GenerateSuite("Windows 并发编程指南");

    ADD_TEST(concurrentProgrammingOnWindowsSuite, ConcurrentProgrammingOnWindows::ConcurrentProgrammingOnWindowsPlaceholderTesting);

    AddSuite(concurrentProgrammingOnWindowsSuite);
}

void BookConcurrentProgramming::TestingHelper::AddParallelAndDistributedProgrammingUsingCppSuite()
{
    auto parallelAndDistributedProgrammingUsingCppSuite = GenerateSuite("C++ 并行与分布式编程");

    ADD_TEST(parallelAndDistributedProgrammingUsingCppSuite, ParallelAndDistributedProgrammingUsingCpp::ParallelAndDistributedProgrammingTesting);

    AddSuite(parallelAndDistributedProgrammingUsingCppSuite);
}

void BookConcurrentProgramming::TestingHelper::AddCppConcurrencyInActionSuite()
{
    auto cppConcurrencyInActionSuite = GenerateSuite("C++ 并发编程实战");

    ADD_TEST(cppConcurrencyInActionSuite, CppConcurrencyInAction::CppConcurrencyInActionTesting);

    AddSuite(cppConcurrencyInActionSuite);
}

void BookConcurrentProgramming::TestingHelper::AddCppMultithreadingCookbookSuite()
{
    auto cppMultithreadingCookbookSuite = GenerateSuite("C++ 多线程编程实战");

    ADD_TEST(cppMultithreadingCookbookSuite, CppMultithreadingCookbook::CppMultithreadingCookbookTesting);

    AddSuite(cppMultithreadingCookbookSuite);
}

void BookConcurrentProgramming::TestingHelper::AddMultithreadingApplicationsInWin32Suite()
{
    auto multithreadingApplicationsInWin32Suite = GenerateSuite("Win32 多线程程序设计");

    ADD_TEST(multithreadingApplicationsInWin32Suite, MultithreadingApplicationsInWin32::MultithreadingApplicationsInWin32Testing);

    AddSuite(multithreadingApplicationsInWin32Suite);
}

void BookConcurrentProgramming::TestingHelper::AddProfessionalMulticoreProgrammingSuite()
{
    auto professionalMulticoreProgrammingSuite = GenerateSuite("C++ 多核高级编程");

    ADD_TEST(professionalMulticoreProgrammingSuite, ProfessionalMulticoreProgramming::ProfessionalMulticoreProgrammingTesting);

    AddSuite(professionalMulticoreProgrammingSuite);
}

void BookConcurrentProgramming::TestingHelper::AddObjectOrientedMultithreadingUsingCppSuite()
{
    auto objectOrientedMultithreadingUsingCppSuite = GenerateSuite("C++ 面向对象多线程编程");

    ADD_TEST(objectOrientedMultithreadingUsingCppSuite, ObjectOrientedMultithreadingUsingCpp::ObjectOrientedMultithreadingUsingCppTesting);

    AddSuite(objectOrientedMultithreadingUsingCppSuite);
}

void BookConcurrentProgramming::TestingHelper::AddDistributedSystemsSuite()
{
    auto distributedSystemsSuite = GenerateSuite("分布式系统：概念与设计");

    ADD_TEST(distributedSystemsSuite, DistributedSystems::DistributedSystemsTesting);

    AddSuite(distributedSystemsSuite);
}
