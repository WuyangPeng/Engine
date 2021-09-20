// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎辅助测试版本：0.1.0.3 (2020/04/28 0:07)

#include "TestingHelper.h"
#include "Testing.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "Example/BookSoftwareDesign/BookCode/Helper/BookCodeClassInvariantMacro.h"
#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelperDetail.h"
BookCode::TestingHelper
	::TestingHelper(int argc, char** argv)
	:ParentType{ argc,argv,"【书籍·软件设计·代码】单元测试套件" }
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
	auto codeCompleteSuite = GenerateSuite("代码大全");
 

	AddSuite(codeCompleteSuite);
}

void BookCode::TestingHelper
	::AddCleanCodeSuite()
{
	auto cleanCodeSuite = GenerateSuite("代码整洁之道");


	AddSuite(cleanCodeSuite); 
}

void BookCode::TestingHelper
	::AddCodeQualitySuite()
{
	auto codeQualitySuite = GenerateSuite("代码质量");


	AddSuite(codeQualitySuite); 
}

void BookCode::TestingHelper
	::AddCodeReadingSuite()
{
	auto codeReadingSuite = GenerateSuite("代码阅读");


	AddSuite(codeReadingSuite);
}

void BookCode::TestingHelper
	::AddTheCleanCoderSuite()
{
	auto theCleanCoderSuite = GenerateSuite("代码整洁之道：程序员的职业素养");

	ADD_TEST(theCleanCoderSuite, TheCleanCoderMainTesting);

	AddSuite(theCleanCoderSuite);
}

void BookCode::TestingHelper
	::AddCodeCraftSuite()
{
	auto codeCraftSuite = GenerateSuite("编程匠艺：编写卓越的代码");


	AddSuite(codeCraftSuite);
}

void BookCode::TestingHelper
	::AddBeautifulCodeSuite()
{
	auto beautifulCodeSuite = GenerateSuite("代码之美");


	AddSuite(beautifulCodeSuite);
}

void BookCode::TestingHelper
	::AddTheArtOfReadableCodeSuite()
{
	auto theArtOfReadableCodeSuite = GenerateSuite("编写可读代码的艺术");


	AddSuite(theArtOfReadableCodeSuite); 
}

void BookCode::TestingHelper
	::AddWorkingEffectivelyWithLegacyCodeSuite()
{
	auto workingEffectivelyWithLegacyCodeSuite = GenerateSuite("修改代码的艺术");


	AddSuite(workingEffectivelyWithLegacyCodeSuite); 
}

void BookCode::TestingHelper
	::AddDreamingInCodeSuite()
{
	auto dreamingInCodeSuite = GenerateSuite("梦断代码");


	AddSuite(dreamingInCodeSuite); 
}

void BookCode::TestingHelper
	::AddIMWrightsHardCodeSuite()
{
	auto imWrightsHardCodeSuite = GenerateSuite("代码之殇");


	AddSuite(imWrightsHardCodeSuite);
}

void BookCode::TestingHelper
	::AddProgrammingBeyondPracticesSuite()
{
	auto programmingBeyondPracticesSuite = GenerateSuite("代码之外的功夫：程序员精进之路");


	AddSuite(programmingBeyondPracticesSuite);
}

