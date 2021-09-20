// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ���渨�����԰汾��0.0.0.1 (2019/09/29 10:13)

#include "TestingHelper.h"
#include "Testing.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

CMAIN_FUNCTION_HELPER_SUBCLASS_COMPLETE_DEFINE(BookArtificialIntelligenceSoftware, TestingHelper, "�鼮 �˹�����")

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
	ADD_TEST_BEGIN(artificialIntelligenceStructuresAndStrategiesForComplexProblemSolvingSuite, "�˹����ܣ������������Ľṹ�Ͳ���");

	ADD_TEST_END(artificialIntelligenceStructuresAndStrategiesForComplexProblemSolvingSuite);
}

void BookArtificialIntelligenceSoftware::TestingHelper
	::AddArtificialIntelligenceAModernApproachSuite()
{
	ADD_TEST_BEGIN(artificialIntelligenceAModernApproachSuite, "�˹����ܡ���һ���ִ�����");

	ADD_TEST_END(artificialIntelligenceAModernApproachSuite);
}

void BookArtificialIntelligenceSoftware::TestingHelper
	::AddDeepLearningSuite()
{
	ADD_TEST_BEGIN(deepLearningSuite, "���ѧϰ");

	ADD_TEST_END(deepLearningSuite);
}

