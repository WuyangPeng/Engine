// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���渨�����԰汾��0.1.0.1 (2020/04/05 23:56)

#include "TestingHelper.h"
#include "Testing.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "Example/BookSoftwareDesign/BookUML/Helper/BookUMLClassInvariantMacro.h"
#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelperDetail.h"
BookUML::TestingHelper
	::TestingHelper(int argc, char** argv)
	:ParentType{ argc,argv,"���鼮�������ơ�UML����Ԫ�����׼�" }
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
	auto objectOrientedModelingAndDesignWithUMLSuite = GenerateSuite("UML�������ģ�����");

	ADD_TEST(objectOrientedModelingAndDesignWithUMLSuite, ObjectOrientedModelingAndDesignWithUMLMainTesting);

	AddSuite(objectOrientedModelingAndDesignWithUMLSuite);
} 

void BookUML::TestingHelper
	::AddApplyingUMLAndPatternsSuite()
{
	auto applyingUMLAndPatternsSuite = GenerateSuite("UML��ģʽӦ��");

	ADD_TEST(applyingUMLAndPatternsSuite, ApplyingUMLAndPatternsMainTesting);

	AddSuite(applyingUMLAndPatternsSuite);
}

void BookUML::TestingHelper
	::AddTheUnifiedModelingLanguageUserGuideSuite()
{
	auto theUnifiedModelingLanguageUserGuideSuite = GenerateSuite("UML�û�ָ��");

	ADD_TEST(theUnifiedModelingLanguageUserGuideSuite, TheUnifiedModelingLanguageUserGuideMainTesting);

	AddSuite(theUnifiedModelingLanguageUserGuideSuite);
}

void BookUML::TestingHelper
	::AddUMLDistilledSuite()
{
	auto umlDistilledSuite = GenerateSuite("UML����");

	ADD_TEST(umlDistilledSuite, UMLDistilledMainTesting);

	AddSuite(umlDistilledSuite);
}

void BookUML::TestingHelper
	::AddSamsTeachYourselfUMLIn24HoursSuite()
{
	auto samsTeachYourselfUMLIn24HoursSuite = GenerateSuite("UML������������Ӧ��");

	ADD_TEST(samsTeachYourselfUMLIn24HoursSuite, SamsTeachYourselfUMLIn24HoursMainTesting);

	AddSuite(samsTeachYourselfUMLIn24HoursSuite);
}

void BookUML::TestingHelper
	::AddTheUnifiedModelingLanguageReferenceManualSuite()
{
	auto theUnifiedModelingLanguageReferenceManualSuite = GenerateSuite(" UML�ο��ֲ�");

	ADD_TEST(theUnifiedModelingLanguageReferenceManualSuite, TheUnifiedModelingLanguageReferenceManualMainTesting);

	AddSuite(theUnifiedModelingLanguageReferenceManualSuite);
}