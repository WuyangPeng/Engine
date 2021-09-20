// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ���渨�����԰汾��0.0.0.1 (2019/09/29 14:44)

#include "TestingHelper.h"
#include "Testing.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

CMAIN_FUNCTION_HELPER_SUBCLASS_COMPLETE_DEFINE(BookTestDrive, TestingHelper, "�鼮 ��������")

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
	ADD_TEST_BEGIN(testDrivenDevelopmentByExampleSuite, "������������");

	ADD_TEST_END(testDrivenDevelopmentByExampleSuite);
}

void BookTestDrive::TestingHelper
	::AddTestDrivenDevelopmentAPracticalGuideSuite()
{
	ADD_TEST_BEGIN(testDrivenDevelopmentAPracticalGuideSuite, "����������������ʵ��ָ��");

	ADD_TEST_END(testDrivenDevelopmentAPracticalGuideSuite);
}

void BookTestDrive::TestingHelper
	::AddTestDrivenPracticalTDDAndAcceptanceTDDForJaveDevelopersSuite()
{
	ADD_TEST_BEGIN(testDrivenPracticalTDDAndAcceptanceTDDForJaveDevelopersSuite, "������������������");

	ADD_TEST_END(testDrivenPracticalTDDAndAcceptanceTDDForJaveDevelopersSuite);
}

void BookTestDrive::TestingHelper
	::AddGrowingObjectOrientedSoftwareGuidedByTestsSuite()
{
	ADD_TEST_BEGIN(growingObjectOrientedSoftwareGuidedByTestsSuite, "������������������������");

	ADD_TEST_END(growingObjectOrientedSoftwareGuidedByTestsSuite);
}

