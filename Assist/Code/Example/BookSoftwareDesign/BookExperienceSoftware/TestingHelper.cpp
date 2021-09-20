// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ���渨���汾��0.0.0.2 (2019/09/29 09:46)

#include "TestingHelper.h"
#include "Testing.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

CMAIN_FUNCTION_HELPER_SUBCLASS_COMPLETE_DEFINE(BookExperienceSoftware, TestingHelper, "�鼮 ����")

void BookExperienceSoftware::TestingHelper
	::AddSuites()
{
	AddThePragmaticProgrammerFromJourneymanToMasterSuite();
	AddPragmaticThinkingAndLearningRefactorYourWetwareSuite();
	AddTheMythicalManMonthSuite();
	AddMoreJoelOnSoftwareSuite();
}

void BookExperienceSoftware::TestingHelper
	::AddThePragmaticProgrammerFromJourneymanToMasterSuite()
{
	ADD_TEST_BEGIN(thePragmaticProgrammerFromJourneymanToMasterSuite, "����Ա����֮��������С����ר��");

	ADD_TEST_END(thePragmaticProgrammerFromJourneymanToMasterSuite);
}

void BookExperienceSoftware::TestingHelper
	::AddPragmaticThinkingAndLearningRefactorYourWetwareSuite()
{
	ADD_TEST_BEGIN(pragmaticThinkingAndLearningRefactorYourWetwareSuite, "����Ա��˼ά������������֪Ǳ�ܵľ��ÿ�");

	ADD_TEST_END(pragmaticThinkingAndLearningRefactorYourWetwareSuite);
}

void BookExperienceSoftware::TestingHelper
	::AddTheMythicalManMonthSuite()
{
	ADD_TEST_BEGIN(theMythicalManMonthSuite, "������");

	ADD_TEST_END(theMythicalManMonthSuite);
}

void BookExperienceSoftware::TestingHelper
	::AddMoreJoelOnSoftwareSuite()
{
	ADD_TEST_BEGIN(moreJoelOnSoftwareSuite, "�������¼������Ա��������Joel̸���");

	ADD_TEST_END(moreJoelOnSoftwareSuite);
}

