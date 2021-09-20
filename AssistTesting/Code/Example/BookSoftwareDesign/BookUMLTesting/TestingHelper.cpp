// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎辅助测试版本：0.1.0.1 (2020/04/05 23:56)

#include "TestingHelper.h"
#include "Testing.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "Example/BookSoftwareDesign/BookUML/Helper/BookUMLClassInvariantMacro.h"
#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelperDetail.h"
BookUML::TestingHelper
	::TestingHelper(int argc, char** argv)
	:ParentType{ argc,argv,"【书籍·软件设计·UML】单元测试套件" }
{
	InitSuite();

	BOOK_UML_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookUML, TestingHelper) 

void BookUML::TestingHelper
	::InitSuite()
{
	AddObjectOrientedModelingAndDesignWithUMLSuite();
	AddApplyingUMLAndPatternsSuite();
	AddTheUnifiedModelingLanguageUserGuideSuite();
	AddUMLDistilledSuite();
	AddSamsTeachYourselfUMLIn24HoursSuite();
	AddTheUnifiedModelingLanguageReferenceManualSuite();
}

void BookUML::TestingHelper
	::AddObjectOrientedModelingAndDesignWithUMLSuite()
{
	auto objectOrientedModelingAndDesignWithUMLSuite = GenerateSuite("UML面向对象建模与设计");

	ADD_TEST(objectOrientedModelingAndDesignWithUMLSuite, ObjectOrientedModelingAndDesignWithUMLMainTesting);

	AddSuite(objectOrientedModelingAndDesignWithUMLSuite);
} 

void BookUML::TestingHelper
	::AddApplyingUMLAndPatternsSuite()
{
	auto applyingUMLAndPatternsSuite = GenerateSuite("UML和模式应用");

	ADD_TEST(applyingUMLAndPatternsSuite, ApplyingUMLAndPatternsMainTesting);

	AddSuite(applyingUMLAndPatternsSuite);
}

void BookUML::TestingHelper
	::AddTheUnifiedModelingLanguageUserGuideSuite()
{
	auto theUnifiedModelingLanguageUserGuideSuite = GenerateSuite("UML用户指南");

	ADD_TEST(theUnifiedModelingLanguageUserGuideSuite, TheUnifiedModelingLanguageUserGuideMainTesting);

	AddSuite(theUnifiedModelingLanguageUserGuideSuite);
}

void BookUML::TestingHelper
	::AddUMLDistilledSuite()
{
	auto umlDistilledSuite = GenerateSuite("UML精粹");

	ADD_TEST(umlDistilledSuite, UMLDistilledMainTesting);

	AddSuite(umlDistilledSuite);
}

void BookUML::TestingHelper
	::AddSamsTeachYourselfUMLIn24HoursSuite()
{
	auto samsTeachYourselfUMLIn24HoursSuite = GenerateSuite("UML基础、案例与应用");

	ADD_TEST(samsTeachYourselfUMLIn24HoursSuite, SamsTeachYourselfUMLIn24HoursMainTesting);

	AddSuite(samsTeachYourselfUMLIn24HoursSuite);
}

void BookUML::TestingHelper
	::AddTheUnifiedModelingLanguageReferenceManualSuite()
{
	auto theUnifiedModelingLanguageReferenceManualSuite = GenerateSuite(" UML参考手册");

	ADD_TEST(theUnifiedModelingLanguageReferenceManualSuite, TheUnifiedModelingLanguageReferenceManualMainTesting);

	AddSuite(theUnifiedModelingLanguageReferenceManualSuite);
}