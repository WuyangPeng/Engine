// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ���渨���汾��0.0.0.2 (2019/09/27 21:41)

#include "TestingHelper.h"
#include "Testing.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

CMAIN_FUNCTION_HELPER_SUBCLASS_COMPLETE_DEFINE(BookConcurrentProgramming, TestingHelper, "�鼮 ����ϵͳ �������")

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
	ADD_TEST_BEGIN(concurrentProgrammingOnWindowsSuite, "Windows �������ָ��");

 
	ADD_TEST_END(concurrentProgrammingOnWindowsSuite);
}

void BookConcurrentProgramming::TestingHelper
	::AddParallelAndDistributedProgrammingUsingCppSuite()
{
	ADD_TEST_BEGIN(parallelAndDistributedProgrammingUsingCppSuite, "C++ ������ֲ�ʽ���");


	ADD_TEST_END(parallelAndDistributedProgrammingUsingCppSuite);
}

void BookConcurrentProgramming::TestingHelper
	::AddCppConcurrencyInActionSuite()
{
	ADD_TEST_BEGIN(cppConcurrencyInActionSuite, "C++ �������ʵս");


	ADD_TEST_END(cppConcurrencyInActionSuite);
}

void BookConcurrentProgramming::TestingHelper
	::AddMultithreadingApplicationsInWin32Suite()
{
	ADD_TEST_BEGIN(multithreadingApplicationsInWin32Suite, "Win32 ���̳߳������");


	ADD_TEST_END(multithreadingApplicationsInWin32Suite);
}

void BookConcurrentProgramming::TestingHelper
	::AddProfessionalMulticoreProgrammingSuite()
{
	ADD_TEST_BEGIN(professionalMulticoreProgrammingSuite, "C++ ��˸߼����");


	ADD_TEST_END(professionalMulticoreProgrammingSuite);
}

void BookConcurrentProgramming::TestingHelper
	::AddObjectOrientedMultithreadingUsingCppSuite()
{
	ADD_TEST_BEGIN(objectOrientedMultithreadingUsingCppSuite, "C++ ���������̱߳��");


	ADD_TEST_END(objectOrientedMultithreadingUsingCppSuite);
}
