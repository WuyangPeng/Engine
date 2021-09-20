// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���渨�����԰汾��0.0.3.0 (2020/03/24 21:37)

#include "TestingHelper.h"
#include "Testing.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

CMAIN_FUNCTION_HELPER_SUBCLASS_COMPLETE_DEFINE(BookMode, TestingHelper, "�鼮 ģʽ")

void BookMode::TestingHelper
	::AddSuites()
{
	AddDesignPatternsExplainedSuite();
	AddDesignPatternsElementsOfReusableObjectOrientedSoftwareSuite();
	AddPatternLanguagesOfProgramDesignSuite();

	AddPatternHatchingDesignPatternsAppliedSuite();
	AddPatternOrientedSoftwareArfhitectureSuite();
	AddPatternsOfEnterpriseApplicationArchitectureSuite();
}

void BookMode::TestingHelper
	::AddDesignPatternsExplainedSuite()
{
	ADD_TEST_BEGIN(designPatternsExplainedSuite, "���ģʽ����");

	ADD_TEST_END(designPatternsExplainedSuite);
}

void BookMode::TestingHelper
	::AddDesignPatternsElementsOfReusableObjectOrientedSoftwareSuite()
{
	ADD_TEST_BEGIN(designPatternsElementsOfReusableObjectOrientedSoftwareSuite, "���ģʽ���ɸ��������������Ļ���");

	ADD_TEST_END(designPatternsElementsOfReusableObjectOrientedSoftwareSuite);
}

void BookMode::TestingHelper
	::AddPatternLanguagesOfProgramDesignSuite()
{
	ADD_TEST_BEGIN(patternLanguagesOfProgramDesignSuite, "������Ƶ�ģʽ����");

	AddPatternLanguagesOfProgramDesign1Suite(patternLanguagesOfProgramDesignSuite);
	AddPatternLanguagesOfProgramDesign2Suite(patternLanguagesOfProgramDesignSuite);
	AddPatternLanguagesOfProgramDesign3Suite(patternLanguagesOfProgramDesignSuite);
	AddPatternLanguagesOfProgramDesign4Suite(patternLanguagesOfProgramDesignSuite);
	AddPatternLanguagesOfProgramDesign5Suite(patternLanguagesOfProgramDesignSuite);

	ADD_TEST_END(patternLanguagesOfProgramDesignSuite);
}

void BookMode::TestingHelper
	::AddPatternLanguagesOfProgramDesign1Suite(Suite& patternLanguagesOfProgramDesignSuite)
{
	ADD_TEST_BEGIN(patternLanguagesOfProgramDesignSuite1, "������Ƶ�ģʽ���� ��1");

	patternLanguagesOfProgramDesignSuite.AddSuite(patternLanguagesOfProgramDesignSuite1);
}

void BookMode::TestingHelper
	::AddPatternLanguagesOfProgramDesign2Suite(Suite& patternLanguagesOfProgramDesignSuite)
{
	ADD_TEST_BEGIN(patternLanguagesOfProgramDesignSuite2, "������Ƶ�ģʽ���� ��2");

	patternLanguagesOfProgramDesignSuite.AddSuite(patternLanguagesOfProgramDesignSuite2);
}

void BookMode::TestingHelper
	::AddPatternLanguagesOfProgramDesign3Suite(Suite& patternLanguagesOfProgramDesignSuite)
{
	ADD_TEST_BEGIN(patternLanguagesOfProgramDesignSuite3, "������Ƶ�ģʽ���� ��3");

	patternLanguagesOfProgramDesignSuite.AddSuite(patternLanguagesOfProgramDesignSuite3);
}

void BookMode::TestingHelper
	::AddPatternLanguagesOfProgramDesign4Suite(Suite& patternLanguagesOfProgramDesignSuite)
{
	ADD_TEST_BEGIN(patternLanguagesOfProgramDesignSuite4, "������Ƶ�ģʽ���� ��4");

	patternLanguagesOfProgramDesignSuite.AddSuite(patternLanguagesOfProgramDesignSuite4);
}

void BookMode::TestingHelper
	::AddPatternLanguagesOfProgramDesign5Suite(Suite& patternLanguagesOfProgramDesignSuite)
{
	ADD_TEST_BEGIN(patternLanguagesOfProgramDesignSuite5, "������Ƶ�ģʽ���� ��5");

	patternLanguagesOfProgramDesignSuite.AddSuite(patternLanguagesOfProgramDesignSuite5);
}

void BookMode::TestingHelper
	::AddPatternHatchingDesignPatternsAppliedSuite()
{
	ADD_TEST_BEGIN(patternHatchingDesignPatternsAppliedSuite, "���ģʽ��˼¼");

	ADD_TEST_END(patternHatchingDesignPatternsAppliedSuite);
}

void BookMode::TestingHelper
	::AddPatternOrientedSoftwareArfhitectureSuite()
{
	ADD_TEST_BEGIN(patternOrientedSoftwareArfhitectureSuite, "����ģʽ�������ϵ�ṹ");

	AddPatternOrientedSoftwareArfhitectureASystemOfPatternsSuite(patternOrientedSoftwareArfhitectureSuite);
	AddPatternOrientedSoftwareArfhitecturePatternsForConcurrentAndNetworkedObjectsSuite(patternOrientedSoftwareArfhitectureSuite);
	AddPatternOrientedSoftwareArfhitecturePatternsForResourceManagermentSuite(patternOrientedSoftwareArfhitectureSuite);
	AddPatternOrientedSoftwareArfhitectureAPatternLanguageForDistributedComputingSuite(patternOrientedSoftwareArfhitectureSuite);
	AddPatternOrientedSoftwareArfhitectureOnPatternsAndPatternLanguagesSuite(patternOrientedSoftwareArfhitectureSuite);

	ADD_TEST_END(patternOrientedSoftwareArfhitectureSuite);
}

void BookMode::TestingHelper
	::AddPatternOrientedSoftwareArfhitectureASystemOfPatternsSuite(Suite& patternOrientedSoftwareArfhitectureSuite)
{
	ADD_TEST_BEGIN(patternOrientedSoftwareArfhitectureASystemOfPatternsSuite, "����ģʽ�������ϵ�ṹ ģʽϵͳ");

	patternOrientedSoftwareArfhitectureSuite.AddSuite(patternOrientedSoftwareArfhitectureASystemOfPatternsSuite);
}

void BookMode::TestingHelper
	::AddPatternOrientedSoftwareArfhitecturePatternsForConcurrentAndNetworkedObjectsSuite(Suite& patternOrientedSoftwareArfhitectureSuite)
{
	ADD_TEST_BEGIN(patternOrientedSoftwareArfhitecturePatternsForConcurrentAndNetworkedObjectsSuite, "����ģʽ�������ϵ�ṹ ���ڲ��������绯����ģʽ");

	patternOrientedSoftwareArfhitectureSuite.AddSuite(patternOrientedSoftwareArfhitecturePatternsForConcurrentAndNetworkedObjectsSuite);
}

void BookMode::TestingHelper
	::AddPatternOrientedSoftwareArfhitecturePatternsForResourceManagermentSuite(Suite& patternOrientedSoftwareArfhitectureSuite)
{
	ADD_TEST_BEGIN(patternOrientedSoftwareArfhitecturePatternsForResourceManagermentSuite, "����ģʽ�������ϵ�ṹ ��Դ����");

	patternOrientedSoftwareArfhitectureSuite.AddSuite(patternOrientedSoftwareArfhitecturePatternsForResourceManagermentSuite);
}

void BookMode::TestingHelper
	::AddPatternOrientedSoftwareArfhitectureAPatternLanguageForDistributedComputingSuite(Suite& patternOrientedSoftwareArfhitectureSuite)
{
	ADD_TEST_BEGIN(patternOrientedSoftwareArfhitectureAPatternLanguageForDistributedComputingSuite, "����ģʽ�������ϵ�ṹ �ֲ�ʽ�����ģʽ����");

	patternOrientedSoftwareArfhitectureSuite.AddSuite(patternOrientedSoftwareArfhitectureAPatternLanguageForDistributedComputingSuite);
}

void BookMode::TestingHelper
	::AddPatternOrientedSoftwareArfhitectureOnPatternsAndPatternLanguagesSuite(Suite& patternOrientedSoftwareArfhitectureSuite)
{
	ADD_TEST_BEGIN(patternOrientedSoftwareArfhitectureOnPatternsAndPatternLanguagesSuite, "����ģʽ�������ϵ�ṹ ģʽ��ģʽ����");

	patternOrientedSoftwareArfhitectureSuite.AddSuite(patternOrientedSoftwareArfhitectureOnPatternsAndPatternLanguagesSuite);
}

void BookMode::TestingHelper
	::AddPatternsOfEnterpriseApplicationArchitectureSuite()
{
	ADD_TEST_BEGIN(patternsOfEnterpriseApplicationArchitectureSuite, "��ҵӦ�üܹ�ģʽ");

	ADD_TEST_END(patternsOfEnterpriseApplicationArchitectureSuite);
}

