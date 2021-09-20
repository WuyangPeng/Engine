// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���渨�����԰汾��0.1.0.3 (2020/04/28 0:07)

#include "TestingHelper.h"
#include "Testing.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "Example/BookSoftwareDesign/BookCode/Helper/BookCodeClassInvariantMacro.h"
#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelperDetail.h"
BookCode::TestingHelper
	::TestingHelper(int argc, char** argv)
	:ParentType{ argc,argv,"���鼮�������ơ����롿��Ԫ�����׼�" }
{
	InitSuite();

	BOOK_CODE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookCode, TestingHelper) 

void BookCode::TestingHelper
	::InitSuite()
{
	AddCodeCompleteSuite();
	AddCleanCodeSuite();
	AddCodeQualitySuite();
	AddCodeReadingSuite();
	AddTheCleanCoderSuite();
	AddCodeCraftSuite();

	AddBeautifulCodeSuite();
	AddTheArtOfReadableCodeSuite();
	AddWorkingEffectivelyWithLegacyCodeSuite();	 
	AddDreamingInCodeSuite();
	AddIMWrightsHardCodeSuite();
	AddProgrammingBeyondPracticesSuite();
}

void BookCode::TestingHelper
	::AddCodeCompleteSuite()
{
	auto codeCompleteSuite = GenerateSuite("�����ȫ");
 

	AddSuite(codeCompleteSuite);
}

void BookCode::TestingHelper
	::AddCleanCodeSuite()
{
	auto cleanCodeSuite = GenerateSuite("��������֮��");


	AddSuite(cleanCodeSuite); 
}

void BookCode::TestingHelper
	::AddCodeQualitySuite()
{
	auto codeQualitySuite = GenerateSuite("��������");


	AddSuite(codeQualitySuite); 
}

void BookCode::TestingHelper
	::AddCodeReadingSuite()
{
	auto codeReadingSuite = GenerateSuite("�����Ķ�");


	AddSuite(codeReadingSuite);
}

void BookCode::TestingHelper
	::AddTheCleanCoderSuite()
{
	auto theCleanCoderSuite = GenerateSuite("��������֮��������Ա��ְҵ����");

	ADD_TEST(theCleanCoderSuite, TheCleanCoderMainTesting);

	AddSuite(theCleanCoderSuite);
}

void BookCode::TestingHelper
	::AddCodeCraftSuite()
{
	auto codeCraftSuite = GenerateSuite("��̽��գ���д׿Խ�Ĵ���");


	AddSuite(codeCraftSuite);
}

void BookCode::TestingHelper
	::AddBeautifulCodeSuite()
{
	auto beautifulCodeSuite = GenerateSuite("����֮��");


	AddSuite(beautifulCodeSuite);
}

void BookCode::TestingHelper
	::AddTheArtOfReadableCodeSuite()
{
	auto theArtOfReadableCodeSuite = GenerateSuite("��д�ɶ����������");


	AddSuite(theArtOfReadableCodeSuite); 
}

void BookCode::TestingHelper
	::AddWorkingEffectivelyWithLegacyCodeSuite()
{
	auto workingEffectivelyWithLegacyCodeSuite = GenerateSuite("�޸Ĵ��������");


	AddSuite(workingEffectivelyWithLegacyCodeSuite); 
}

void BookCode::TestingHelper
	::AddDreamingInCodeSuite()
{
	auto dreamingInCodeSuite = GenerateSuite("�ζϴ���");


	AddSuite(dreamingInCodeSuite); 
}

void BookCode::TestingHelper
	::AddIMWrightsHardCodeSuite()
{
	auto imWrightsHardCodeSuite = GenerateSuite("����֮��");


	AddSuite(imWrightsHardCodeSuite);
}

void BookCode::TestingHelper
	::AddProgrammingBeyondPracticesSuite()
{
	auto programmingBeyondPracticesSuite = GenerateSuite("����֮��Ĺ��򣺳���Ա����֮·");


	AddSuite(programmingBeyondPracticesSuite);
}

