// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎辅助版本：0.0.0.2 (2019/09/29 09:51)

#include "TestingHelper.h"
#include "Testing.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

CMAIN_FUNCTION_HELPER_SUBCLASS_COMPLETE_DEFINE(BookSoftwareEngineering, TestingHelper, "书籍 软件工程")

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
	ADD_TEST_BEGIN(catastropheDisentanglementGettingSoftwareProjectsBackOnTrackSuite, "灾难拯救：让软件项目重回轨道");

	ADD_TEST_END(catastropheDisentanglementGettingSoftwareProjectsBackOnTrackSuite);
}

void BookSoftwareEngineering::TestingHelper
	::AddFuzzingBruteForceVulnerabilityDiscoverySuite()
{
	ADD_TEST_BEGIN(fuzzingBruteForceVulnerabilityDiscoverySuite, "模糊测试强制性安全漏洞发掘");

	ADD_TEST_END(fuzzingBruteForceVulnerabilityDiscoverySuite);
}

void BookSoftwareEngineering::TestingHelper
	::AddCodeOptimizationEffectiveMemoryUsageSuite()
{
	ADD_TEST_BEGIN(codeOptimizationEffectiveMemoryUsageSuite, "代码优化：有效使用内存");

	ADD_TEST_END(codeOptimizationEffectiveMemoryUsageSuite);
}

void BookSoftwareEngineering::TestingHelper
	::AddContinuousIntegrationImprovingSoftwareQualityAndReducingRiskSuite()
{
	ADD_TEST_BEGIN(continuousIntegrationImprovingSoftwareQualityAndReducingRiskSuite, "持续集成：软件质量改进和风险降低之道");

	ADD_TEST_END(continuousIntegrationImprovingSoftwareQualityAndReducingRiskSuite);
}

void BookSoftwareEngineering::TestingHelper
	::AddBeautifulArchitectureSuite()
{
	ADD_TEST_BEGIN(beautifulArchitectureSuite, "架构之美");

	ADD_TEST_END(beautifulArchitectureSuite);
}

void BookSoftwareEngineering::TestingHelper
	::AddApplyingDomainDrivenDesignAndPatternsSuite()
{
	ADD_TEST_BEGIN(applyingDomainDrivenDesignAndPatternsSuite, "领域驱动设计和模式实战");

	ADD_TEST_END(applyingDomainDrivenDesignAndPatternsSuite);
}

void BookSoftwareEngineering::TestingHelper
	::AddAntiPatternsRefactoringSoftwareArchitecturesAndProjectsInCrisisSuite()
{
	ADD_TEST_BEGIN(antiPatternsRefactoringSoftwareArchitecturesAndProjectsInCrisisSuite, "反模式：危机中软件、架构和项目的重构");

	ADD_TEST_END(antiPatternsRefactoringSoftwareArchitecturesAndProjectsInCrisisSuite);	
}

void BookSoftwareEngineering::TestingHelper
	::AddWritingEffectiveUseCasesSuite()
{
	ADD_TEST_BEGIN(writingEffectiveUseCasesSuite, "编写有效用例");

	ADD_TEST_END(writingEffectiveUseCasesSuite);
}

void BookSoftwareEngineering::TestingHelper
	::AddSoftwareEngineeringSuite()
{
	ADD_TEST_BEGIN(softwareEngineeringSuite, "软件工程：实践者的研究方法");

	AddSoftwareEngineeringSeventhEditionSuite(softwareEngineeringSuite);
	AddSoftwareEngineeringEighthEditionSuite(softwareEngineeringSuite);

	ADD_TEST_END(softwareEngineeringSuite);
}

void BookSoftwareEngineering::TestingHelper
	::AddSoftwareEngineeringSeventhEditionSuite(Suite& softwareEngineeringSuite)
{
	ADD_TEST_BEGIN(softwareEngineeringSeventhEditionSuite, "软件工程：实践者的研究方法 第7版");

	softwareEngineeringSuite.AddSuite(softwareEngineeringSeventhEditionSuite);
}

void BookSoftwareEngineering::TestingHelper
	::AddSoftwareEngineeringEighthEditionSuite(Suite& softwareEngineeringSuite)
{
	ADD_TEST_BEGIN(softwareEngineeringEighthEditionSuite, "软件工程：实践者的研究方法 第8版");

	softwareEngineeringSuite.AddSuite(softwareEngineeringEighthEditionSuite);
}

void BookSoftwareEngineering::TestingHelper
	::AddAnalysisPatternsReusableObjectModelsSuite()
{
	ADD_TEST_BEGIN(analysisPatternsReusableObjectModelsSuite, "分析模式：可复用的对象模型");

	ADD_TEST_END(analysisPatternsReusableObjectModelsSuite);
}

