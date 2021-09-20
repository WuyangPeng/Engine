// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎辅助测试版本：0.0.3.0 (2020/03/24 21:37)

#include "TestingHelper.h"
#include "Testing.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

CMAIN_FUNCTION_HELPER_SUBCLASS_COMPLETE_DEFINE(BookMode, TestingHelper, "书籍 模式")

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
	ADD_TEST_BEGIN(designPatternsExplainedSuite, "设计模式解析");

	ADD_TEST_END(designPatternsExplainedSuite);
}

void BookMode::TestingHelper
	::AddDesignPatternsElementsOfReusableObjectOrientedSoftwareSuite()
{
	ADD_TEST_BEGIN(designPatternsElementsOfReusableObjectOrientedSoftwareSuite, "设计模式：可复用面向对象软件的基础");

	ADD_TEST_END(designPatternsElementsOfReusableObjectOrientedSoftwareSuite);
}

void BookMode::TestingHelper
	::AddPatternLanguagesOfProgramDesignSuite()
{
	ADD_TEST_BEGIN(patternLanguagesOfProgramDesignSuite, "程序设计的模式语言");

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
	ADD_TEST_BEGIN(patternLanguagesOfProgramDesignSuite1, "程序设计的模式语言 卷1");

	patternLanguagesOfProgramDesignSuite.AddSuite(patternLanguagesOfProgramDesignSuite1);
}

void BookMode::TestingHelper
	::AddPatternLanguagesOfProgramDesign2Suite(Suite& patternLanguagesOfProgramDesignSuite)
{
	ADD_TEST_BEGIN(patternLanguagesOfProgramDesignSuite2, "程序设计的模式语言 卷2");

	patternLanguagesOfProgramDesignSuite.AddSuite(patternLanguagesOfProgramDesignSuite2);
}

void BookMode::TestingHelper
	::AddPatternLanguagesOfProgramDesign3Suite(Suite& patternLanguagesOfProgramDesignSuite)
{
	ADD_TEST_BEGIN(patternLanguagesOfProgramDesignSuite3, "程序设计的模式语言 卷3");

	patternLanguagesOfProgramDesignSuite.AddSuite(patternLanguagesOfProgramDesignSuite3);
}

void BookMode::TestingHelper
	::AddPatternLanguagesOfProgramDesign4Suite(Suite& patternLanguagesOfProgramDesignSuite)
{
	ADD_TEST_BEGIN(patternLanguagesOfProgramDesignSuite4, "程序设计的模式语言 卷4");

	patternLanguagesOfProgramDesignSuite.AddSuite(patternLanguagesOfProgramDesignSuite4);
}

void BookMode::TestingHelper
	::AddPatternLanguagesOfProgramDesign5Suite(Suite& patternLanguagesOfProgramDesignSuite)
{
	ADD_TEST_BEGIN(patternLanguagesOfProgramDesignSuite5, "程序设计的模式语言 卷5");

	patternLanguagesOfProgramDesignSuite.AddSuite(patternLanguagesOfProgramDesignSuite5);
}

void BookMode::TestingHelper
	::AddPatternHatchingDesignPatternsAppliedSuite()
{
	ADD_TEST_BEGIN(patternHatchingDesignPatternsAppliedSuite, "设计模式沉思录");

	ADD_TEST_END(patternHatchingDesignPatternsAppliedSuite);
}

void BookMode::TestingHelper
	::AddPatternOrientedSoftwareArfhitectureSuite()
{
	ADD_TEST_BEGIN(patternOrientedSoftwareArfhitectureSuite, "面向模式的软件体系结构");

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
	ADD_TEST_BEGIN(patternOrientedSoftwareArfhitectureASystemOfPatternsSuite, "面向模式的软件体系结构 模式系统");

	patternOrientedSoftwareArfhitectureSuite.AddSuite(patternOrientedSoftwareArfhitectureASystemOfPatternsSuite);
}

void BookMode::TestingHelper
	::AddPatternOrientedSoftwareArfhitecturePatternsForConcurrentAndNetworkedObjectsSuite(Suite& patternOrientedSoftwareArfhitectureSuite)
{
	ADD_TEST_BEGIN(patternOrientedSoftwareArfhitecturePatternsForConcurrentAndNetworkedObjectsSuite, "面向模式的软件体系结构 用于并发和网络化对象模式");

	patternOrientedSoftwareArfhitectureSuite.AddSuite(patternOrientedSoftwareArfhitecturePatternsForConcurrentAndNetworkedObjectsSuite);
}

void BookMode::TestingHelper
	::AddPatternOrientedSoftwareArfhitecturePatternsForResourceManagermentSuite(Suite& patternOrientedSoftwareArfhitectureSuite)
{
	ADD_TEST_BEGIN(patternOrientedSoftwareArfhitecturePatternsForResourceManagermentSuite, "面向模式的软件体系结构 资源管理");

	patternOrientedSoftwareArfhitectureSuite.AddSuite(patternOrientedSoftwareArfhitecturePatternsForResourceManagermentSuite);
}

void BookMode::TestingHelper
	::AddPatternOrientedSoftwareArfhitectureAPatternLanguageForDistributedComputingSuite(Suite& patternOrientedSoftwareArfhitectureSuite)
{
	ADD_TEST_BEGIN(patternOrientedSoftwareArfhitectureAPatternLanguageForDistributedComputingSuite, "面向模式的软件体系结构 分布式计算的模式语言");

	patternOrientedSoftwareArfhitectureSuite.AddSuite(patternOrientedSoftwareArfhitectureAPatternLanguageForDistributedComputingSuite);
}

void BookMode::TestingHelper
	::AddPatternOrientedSoftwareArfhitectureOnPatternsAndPatternLanguagesSuite(Suite& patternOrientedSoftwareArfhitectureSuite)
{
	ADD_TEST_BEGIN(patternOrientedSoftwareArfhitectureOnPatternsAndPatternLanguagesSuite, "面向模式的软件体系结构 模式与模式语言");

	patternOrientedSoftwareArfhitectureSuite.AddSuite(patternOrientedSoftwareArfhitectureOnPatternsAndPatternLanguagesSuite);
}

void BookMode::TestingHelper
	::AddPatternsOfEnterpriseApplicationArchitectureSuite()
{
	ADD_TEST_BEGIN(patternsOfEnterpriseApplicationArchitectureSuite, "企业应用架构模式");

	ADD_TEST_END(patternsOfEnterpriseApplicationArchitectureSuite);
}

