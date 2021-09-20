// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ���渨���汾��0.0.0.2 (2019/09/29 09:51)

#include "TestingHelper.h"
#include "Testing.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

CMAIN_FUNCTION_HELPER_SUBCLASS_COMPLETE_DEFINE(BookSoftwareEngineering, TestingHelper, "�鼮 �������")

void BookSoftwareEngineering::TestingHelper
	::AddSuites()
{
	AddCatastropheDisentanglementGettingSoftwareProjectsBackOnTrackSuite();
	AddFuzzingBruteForceVulnerabilityDiscoverySuite();
	AddCodeOptimizationEffectiveMemoryUsageSuite();
	AddContinuousIntegrationImprovingSoftwareQualityAndReducingRiskSuite();

	 AddBeautifulArchitectureSuite();
	 AddApplyingDomainDrivenDesignAndPatternsSuite();
	 AddAntiPatternsRefactoringSoftwareArchitecturesAndProjectsInCrisisSuite();

	 AddWritingEffectiveUseCasesSuite();
	 AddSoftwareEngineeringSuite();
	 AddAnalysisPatternsReusableObjectModelsSuite();
}

void BookSoftwareEngineering::TestingHelper
	::AddCatastropheDisentanglementGettingSoftwareProjectsBackOnTrackSuite()
{
	ADD_TEST_BEGIN(catastropheDisentanglementGettingSoftwareProjectsBackOnTrackSuite, "�������ȣ��������Ŀ�ػع��");

	ADD_TEST_END(catastropheDisentanglementGettingSoftwareProjectsBackOnTrackSuite);
}

void BookSoftwareEngineering::TestingHelper
	::AddFuzzingBruteForceVulnerabilityDiscoverySuite()
{
	ADD_TEST_BEGIN(fuzzingBruteForceVulnerabilityDiscoverySuite, "ģ������ǿ���԰�ȫ©������");

	ADD_TEST_END(fuzzingBruteForceVulnerabilityDiscoverySuite);
}

void BookSoftwareEngineering::TestingHelper
	::AddCodeOptimizationEffectiveMemoryUsageSuite()
{
	ADD_TEST_BEGIN(codeOptimizationEffectiveMemoryUsageSuite, "�����Ż�����Чʹ���ڴ�");

	ADD_TEST_END(codeOptimizationEffectiveMemoryUsageSuite);
}

void BookSoftwareEngineering::TestingHelper
	::AddContinuousIntegrationImprovingSoftwareQualityAndReducingRiskSuite()
{
	ADD_TEST_BEGIN(continuousIntegrationImprovingSoftwareQualityAndReducingRiskSuite, "�������ɣ���������Ľ��ͷ��ս���֮��");

	ADD_TEST_END(continuousIntegrationImprovingSoftwareQualityAndReducingRiskSuite);
}

void BookSoftwareEngineering::TestingHelper
	::AddBeautifulArchitectureSuite()
{
	ADD_TEST_BEGIN(beautifulArchitectureSuite, "�ܹ�֮��");

	ADD_TEST_END(beautifulArchitectureSuite);
}

void BookSoftwareEngineering::TestingHelper
	::AddApplyingDomainDrivenDesignAndPatternsSuite()
{
	ADD_TEST_BEGIN(applyingDomainDrivenDesignAndPatternsSuite, "����������ƺ�ģʽʵս");

	ADD_TEST_END(applyingDomainDrivenDesignAndPatternsSuite);
}

void BookSoftwareEngineering::TestingHelper
	::AddAntiPatternsRefactoringSoftwareArchitecturesAndProjectsInCrisisSuite()
{
	ADD_TEST_BEGIN(antiPatternsRefactoringSoftwareArchitecturesAndProjectsInCrisisSuite, "��ģʽ��Σ����������ܹ�����Ŀ���ع�");

	ADD_TEST_END(antiPatternsRefactoringSoftwareArchitecturesAndProjectsInCrisisSuite);	
}

void BookSoftwareEngineering::TestingHelper
	::AddWritingEffectiveUseCasesSuite()
{
	ADD_TEST_BEGIN(writingEffectiveUseCasesSuite, "��д��Ч����");

	ADD_TEST_END(writingEffectiveUseCasesSuite);
}

void BookSoftwareEngineering::TestingHelper
	::AddSoftwareEngineeringSuite()
{
	ADD_TEST_BEGIN(softwareEngineeringSuite, "������̣�ʵ���ߵ��о�����");

	AddSoftwareEngineeringSeventhEditionSuite(softwareEngineeringSuite);
	AddSoftwareEngineeringEighthEditionSuite(softwareEngineeringSuite);

	ADD_TEST_END(softwareEngineeringSuite);
}

void BookSoftwareEngineering::TestingHelper
	::AddSoftwareEngineeringSeventhEditionSuite(Suite& softwareEngineeringSuite)
{
	ADD_TEST_BEGIN(softwareEngineeringSeventhEditionSuite, "������̣�ʵ���ߵ��о����� ��7��");

	softwareEngineeringSuite.AddSuite(softwareEngineeringSeventhEditionSuite);
}

void BookSoftwareEngineering::TestingHelper
	::AddSoftwareEngineeringEighthEditionSuite(Suite& softwareEngineeringSuite)
{
	ADD_TEST_BEGIN(softwareEngineeringEighthEditionSuite, "������̣�ʵ���ߵ��о����� ��8��");

	softwareEngineeringSuite.AddSuite(softwareEngineeringEighthEditionSuite);
}

void BookSoftwareEngineering::TestingHelper
	::AddAnalysisPatternsReusableObjectModelsSuite()
{
	ADD_TEST_BEGIN(analysisPatternsReusableObjectModelsSuite, "����ģʽ���ɸ��õĶ���ģ��");

	ADD_TEST_END(analysisPatternsReusableObjectModelsSuite);
}

