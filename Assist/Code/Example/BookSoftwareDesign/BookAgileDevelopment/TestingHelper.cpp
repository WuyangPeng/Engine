// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ���渨���汾��0.0.0.2 (2019/09/29 09:43)

#include "TestingHelper.h"
#include "Testing.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

CMAIN_FUNCTION_HELPER_SUBCLASS_COMPLETE_DEFINE(BookAgileDevelopment, TestingHelper, "�鼮 ���ݿ���")

void BookAgileDevelopment::TestingHelper
	::AddSuites()
{
	AddAgileSoftwareDevelopmentPrinciplesPatternsAndPracticesSuite();	
	AddExtremeProgrammingExplainedSuite();
	AddAgileModelingSuite();
	AddPracticesOfAnAgileDeveloperSuite();
}

void BookAgileDevelopment::TestingHelper
	::AddAgileSoftwareDevelopmentPrinciplesPatternsAndPracticesSuite()
{
	ADD_TEST_BEGIN(agileSoftwareDevelopmentPrinciplesPatternsAndPracticesSuite, "�������������ԭ��ģʽ��ʵ��");

	AddAgileSoftwareDevelopmentPrinciplesPatternsAndPracticesJavaSuite(agileSoftwareDevelopmentPrinciplesPatternsAndPracticesSuite);
	AddAgileSoftwareDevelopmentPrinciplesPatternsAndPracticesCSharpSuite(agileSoftwareDevelopmentPrinciplesPatternsAndPracticesSuite);

	ADD_TEST_END(agileSoftwareDevelopmentPrinciplesPatternsAndPracticesSuite);
}

void BookAgileDevelopment::TestingHelper
	::AddAgileSoftwareDevelopmentPrinciplesPatternsAndPracticesJavaSuite(Suite& agileSoftwareDevelopmentPrinciplesPatternsAndPracticesSuite)
{
	ADD_TEST_BEGIN(agileSoftwareDevelopmentPrinciplesPatternsAndPracticesJavaSuite, "�������������ԭ��ģʽ��ʵ�� Java��");

	agileSoftwareDevelopmentPrinciplesPatternsAndPracticesSuite.AddSuite(agileSoftwareDevelopmentPrinciplesPatternsAndPracticesJavaSuite);
}

void BookAgileDevelopment::TestingHelper
	::AddAgileSoftwareDevelopmentPrinciplesPatternsAndPracticesCSharpSuite(Suite& agileSoftwareDevelopmentPrinciplesPatternsAndPracticesSuite)
{
	ADD_TEST_BEGIN(agileSoftwareDevelopmentPrinciplesPatternsAndPracticesCSharpSuite, "�������������ԭ��ģʽ��ʵ�� C#��");

	agileSoftwareDevelopmentPrinciplesPatternsAndPracticesSuite.AddSuite(agileSoftwareDevelopmentPrinciplesPatternsAndPracticesCSharpSuite);
}

void BookAgileDevelopment::TestingHelper
	::AddExtremeProgrammingExplainedSuite()
{
	ADD_TEST_BEGIN(extremeProgrammingExplainedSuite, "�������ޱ�̡���ӵ���仯");

	ADD_TEST_END(extremeProgrammingExplainedSuite);
}

void BookAgileDevelopment::TestingHelper
	::AddAgileModelingSuite()
{
	ADD_TEST_BEGIN(agileModelingSuite, "���ݽ�ģ�����ޱ�̺�ͳһ���̵���Чʵ��");

	ADD_TEST_END(agileModelingSuite);
}

void BookAgileDevelopment::TestingHelper
	::AddPracticesOfAnAgileDeveloperSuite()
{
	ADD_TEST_BEGIN(practicesOfAnAgileDeveloperSuite, "��Ч����Ա��45��ϰ�ߣ����ݿ�������֮��");

	ADD_TEST_END(practicesOfAnAgileDeveloperSuite);
}

