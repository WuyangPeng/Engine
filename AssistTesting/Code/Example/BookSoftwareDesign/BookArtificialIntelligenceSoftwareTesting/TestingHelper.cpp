// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎辅助测试版本：0.0.0.1 (2019/09/29 10:13)

#include "TestingHelper.h"
#include "Testing.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

CMAIN_FUNCTION_HELPER_SUBCLASS_COMPLETE_DEFINE(BookArtificialIntelligenceSoftware, TestingHelper, "书籍 人工智能")

void BookArtificialIntelligenceSoftware::TestingHelper
	::AddSuites()
{
	AddArtificialIntelligenceStructuresAndStrategiesForComplexProblemSolvingSuite();
	AddArtificialIntelligenceAModernApproachSuite();
	AddDeepLearningSuite();
}

void BookArtificialIntelligenceSoftware::TestingHelper
	::AddArtificialIntelligenceStructuresAndStrategiesForComplexProblemSolvingSuite()
{
	ADD_TEST_BEGIN(artificialIntelligenceStructuresAndStrategiesForComplexProblemSolvingSuite, "人工智能：复杂问题求解的结构和策略");

	ADD_TEST_END(artificialIntelligenceStructuresAndStrategiesForComplexProblemSolvingSuite);
}

void BookArtificialIntelligenceSoftware::TestingHelper
	::AddArtificialIntelligenceAModernApproachSuite()
{
	ADD_TEST_BEGIN(artificialIntelligenceAModernApproachSuite, "人工智能——一种现代方法");

	ADD_TEST_END(artificialIntelligenceAModernApproachSuite);
}

void BookArtificialIntelligenceSoftware::TestingHelper
	::AddDeepLearningSuite()
{
	ADD_TEST_BEGIN(deepLearningSuite, "深度学习");

	ADD_TEST_END(deepLearningSuite);
}

