// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎辅助版本：0.0.0.2 (2019/09/29 09:46)

#include "TestingHelper.h"
#include "Testing.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

CMAIN_FUNCTION_HELPER_SUBCLASS_COMPLETE_DEFINE(BookExperienceSoftware, TestingHelper, "书籍 经验")

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
	ADD_TEST_BEGIN(thePragmaticProgrammerFromJourneymanToMasterSuite, "程序员修炼之道——从小工到专家");

	ADD_TEST_END(thePragmaticProgrammerFromJourneymanToMasterSuite);
}

void BookExperienceSoftware::TestingHelper
	::AddPragmaticThinkingAndLearningRefactorYourWetwareSuite()
{
	ADD_TEST_BEGIN(pragmaticThinkingAndLearningRefactorYourWetwareSuite, "程序员的思维修炼：开发认知潜能的九堂课");

	ADD_TEST_END(pragmaticThinkingAndLearningRefactorYourWetwareSuite);
}

void BookExperienceSoftware::TestingHelper
	::AddTheMythicalManMonthSuite()
{
	ADD_TEST_BEGIN(theMythicalManMonthSuite, "人月神话");

	ADD_TEST_END(theMythicalManMonthSuite);
}

void BookExperienceSoftware::TestingHelper
	::AddMoreJoelOnSoftwareSuite()
{
	ADD_TEST_BEGIN(moreJoelOnSoftwareSuite, "软件随想录：程序员部落酋长Joel谈软件");

	ADD_TEST_END(moreJoelOnSoftwareSuite);
}

