// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎辅助版本：0.0.0.2 (2019/09/27 21:41)

#include "TestingHelper.h"
#include "Testing.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

CMAIN_FUNCTION_HELPER_SUBCLASS_COMPLETE_DEFINE(BookConcurrentProgramming, TestingHelper, "书籍 操作系统 并发编程")

void BookConcurrentProgramming::TestingHelper
	::AddSuites()
{
	AddConcurrentProgrammingOnWindowsSuite();
	AddParallelAndDistributedProgrammingUsingCppSuite();
	AddCppConcurrencyInActionSuite();

	AddMultithreadingApplicationsInWin32Suite();
	AddProfessionalMulticoreProgrammingSuite();
	AddObjectOrientedMultithreadingUsingCppSuite();
}

void BookConcurrentProgramming::TestingHelper
	::AddConcurrentProgrammingOnWindowsSuite()
{
	ADD_TEST_BEGIN(concurrentProgrammingOnWindowsSuite, "Windows 并发编程指南");

 
	ADD_TEST_END(concurrentProgrammingOnWindowsSuite);
}

void BookConcurrentProgramming::TestingHelper
	::AddParallelAndDistributedProgrammingUsingCppSuite()
{
	ADD_TEST_BEGIN(parallelAndDistributedProgrammingUsingCppSuite, "C++ 并行与分布式编程");


	ADD_TEST_END(parallelAndDistributedProgrammingUsingCppSuite);
}

void BookConcurrentProgramming::TestingHelper
	::AddCppConcurrencyInActionSuite()
{
	ADD_TEST_BEGIN(cppConcurrencyInActionSuite, "C++ 并发编程实战");


	ADD_TEST_END(cppConcurrencyInActionSuite);
}

void BookConcurrentProgramming::TestingHelper
	::AddMultithreadingApplicationsInWin32Suite()
{
	ADD_TEST_BEGIN(multithreadingApplicationsInWin32Suite, "Win32 多线程程序设计");


	ADD_TEST_END(multithreadingApplicationsInWin32Suite);
}

void BookConcurrentProgramming::TestingHelper
	::AddProfessionalMulticoreProgrammingSuite()
{
	ADD_TEST_BEGIN(professionalMulticoreProgrammingSuite, "C++ 多核高级编程");


	ADD_TEST_END(professionalMulticoreProgrammingSuite);
}

void BookConcurrentProgramming::TestingHelper
	::AddObjectOrientedMultithreadingUsingCppSuite()
{
	ADD_TEST_BEGIN(objectOrientedMultithreadingUsingCppSuite, "C++ 面向对象多线程编程");


	ADD_TEST_END(objectOrientedMultithreadingUsingCppSuite);
}
