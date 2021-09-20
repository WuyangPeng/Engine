// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎辅助测试版本：0.0.0.1 (2019/09/29 14:44)

#include "TestingHelper.h"
#include "Testing.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

CMAIN_FUNCTION_HELPER_SUBCLASS_COMPLETE_DEFINE(BookTestDrive, TestingHelper, "书籍 测试驱动")

void BookTestDrive::TestingHelper
	::AddSuites()
{
	AddTestDrivenDevelopmentByExampleSuite();
	AddTestDrivenDevelopmentAPracticalGuideSuite();
	AddTestDrivenPracticalTDDAndAcceptanceTDDForJaveDevelopersSuite();
	AddGrowingObjectOrientedSoftwareGuidedByTestsSuite();
}

void BookTestDrive::TestingHelper
	::AddTestDrivenDevelopmentByExampleSuite()
{
	ADD_TEST_BEGIN(testDrivenDevelopmentByExampleSuite, "测试驱动开发");

	ADD_TEST_END(testDrivenDevelopmentByExampleSuite);
}

void BookTestDrive::TestingHelper
	::AddTestDrivenDevelopmentAPracticalGuideSuite()
{
	ADD_TEST_BEGIN(testDrivenDevelopmentAPracticalGuideSuite, "测试驱动开发——实用指南");

	ADD_TEST_END(testDrivenDevelopmentAPracticalGuideSuite);
}

void BookTestDrive::TestingHelper
	::AddTestDrivenPracticalTDDAndAcceptanceTDDForJaveDevelopersSuite()
{
	ADD_TEST_BEGIN(testDrivenPracticalTDDAndAcceptanceTDDForJaveDevelopersSuite, "测试驱动开发的艺术");

	ADD_TEST_END(testDrivenPracticalTDDAndAcceptanceTDDForJaveDevelopersSuite);
}

void BookTestDrive::TestingHelper
	::AddGrowingObjectOrientedSoftwareGuidedByTestsSuite()
{
	ADD_TEST_BEGIN(growingObjectOrientedSoftwareGuidedByTestsSuite, "测试驱动的面向对象软件开发");

	ADD_TEST_END(growingObjectOrientedSoftwareGuidedByTestsSuite);
}

