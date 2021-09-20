// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎辅助版本：0.0.0.2 (2019/09/29 09:43)

#include "TestingHelper.h"
#include "Testing.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

CMAIN_FUNCTION_HELPER_SUBCLASS_COMPLETE_DEFINE(BookAgileDevelopment, TestingHelper, "书籍 敏捷开发")

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
	ADD_TEST_BEGIN(agileSoftwareDevelopmentPrinciplesPatternsAndPracticesSuite, "敏捷软件开发：原则、模式与实践");

	AddAgileSoftwareDevelopmentPrinciplesPatternsAndPracticesJavaSuite(agileSoftwareDevelopmentPrinciplesPatternsAndPracticesSuite);
	AddAgileSoftwareDevelopmentPrinciplesPatternsAndPracticesCSharpSuite(agileSoftwareDevelopmentPrinciplesPatternsAndPracticesSuite);

	ADD_TEST_END(agileSoftwareDevelopmentPrinciplesPatternsAndPracticesSuite);
}

void BookAgileDevelopment::TestingHelper
	::AddAgileSoftwareDevelopmentPrinciplesPatternsAndPracticesJavaSuite(Suite& agileSoftwareDevelopmentPrinciplesPatternsAndPracticesSuite)
{
	ADD_TEST_BEGIN(agileSoftwareDevelopmentPrinciplesPatternsAndPracticesJavaSuite, "敏捷软件开发：原则、模式与实践 Java版");

	agileSoftwareDevelopmentPrinciplesPatternsAndPracticesSuite.AddSuite(agileSoftwareDevelopmentPrinciplesPatternsAndPracticesJavaSuite);
}

void BookAgileDevelopment::TestingHelper
	::AddAgileSoftwareDevelopmentPrinciplesPatternsAndPracticesCSharpSuite(Suite& agileSoftwareDevelopmentPrinciplesPatternsAndPracticesSuite)
{
	ADD_TEST_BEGIN(agileSoftwareDevelopmentPrinciplesPatternsAndPracticesCSharpSuite, "敏捷软件开发：原则、模式与实践 C#版");

	agileSoftwareDevelopmentPrinciplesPatternsAndPracticesSuite.AddSuite(agileSoftwareDevelopmentPrinciplesPatternsAndPracticesCSharpSuite);
}

void BookAgileDevelopment::TestingHelper
	::AddExtremeProgrammingExplainedSuite()
{
	ADD_TEST_BEGIN(extremeProgrammingExplainedSuite, "解析极限编程——拥抱变化");

	ADD_TEST_END(extremeProgrammingExplainedSuite);
}

void BookAgileDevelopment::TestingHelper
	::AddAgileModelingSuite()
{
	ADD_TEST_BEGIN(agileModelingSuite, "敏捷建模：极限编程和统一过程的有效实践");

	ADD_TEST_END(agileModelingSuite);
}

void BookAgileDevelopment::TestingHelper
	::AddPracticesOfAnAgileDeveloperSuite()
{
	ADD_TEST_BEGIN(practicesOfAnAgileDeveloperSuite, "高效程序员的45个习惯：敏捷开发修炼之道");

	ADD_TEST_END(practicesOfAnAgileDeveloperSuite);
}

