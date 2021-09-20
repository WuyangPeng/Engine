// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���渨�����԰汾��0.0.0.1 (2019/09/29 21:41)

#include "TestingHelper.h"
#include "Testing.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

CMAIN_FUNCTION_HELPER_SUBCLASS_COMPLETE_DEFINE(BookCSharp, TestingHelper, "�鼮 C#")

void BookCSharp::TestingHelper
	::AddSuites()
{
	AddBeginningCSharp6ProgrammingWithVisualStudio2015Suite();
	AddProCSharp2010AndTheNET4PlatformSuite();
	AddProfessionalCSharp6AndNETCore1Suite();
	AddEffectiveCSharpSuite();

	AddMicrosoftVisualCSharp2010StepByStepSuite();
	AddEssentialCSharp5Suite();
	AddCSharpInDepthSuite();

	AddProgrammingCSharpSuite();
	AddIllstratedCSharp2012Suite();
	AddCLRViaCSharpSuite();
}

void BookCSharp::TestingHelper
	::AddBeginningCSharp6ProgrammingWithVisualStudio2015Suite()
{
	ADD_TEST_BEGIN(beginningCSharp6ProgrammingWithVisualStudio2015Suite, "C# ���ž���");



	ADD_TEST_END(beginningCSharp6ProgrammingWithVisualStudio2015Suite);
}

void BookCSharp::TestingHelper
	::AddProCSharp2010AndTheNET4PlatformSuite()
{
	ADD_TEST_BEGIN(proCSharp2010AndTheNET4PlatformSuite, "C# �� NET4 �߼��������");



	ADD_TEST_END(proCSharp2010AndTheNET4PlatformSuite);
}

void BookCSharp::TestingHelper
	::AddProfessionalCSharp6AndNETCore1Suite()
{
	ADD_TEST_BEGIN(professionalCSharp6AndNETCore1Suite, "C# �߼����");



	ADD_TEST_END(professionalCSharp6AndNETCore1Suite);
}

void BookCSharp::TestingHelper
	::AddEffectiveCSharpSuite()
{
	ADD_TEST_BEGIN(effectiveCSharpSuite, "C# ��Ч���");



	ADD_TEST_END(effectiveCSharpSuite);
}

void BookCSharp::TestingHelper
	::AddMicrosoftVisualCSharp2010StepByStepSuite()
{
	ADD_TEST_BEGIN(microsoftVisualCSharp2010StepByStepSuite, "Visual C# 2010 �����ŵ���ͨ");



	ADD_TEST_END(microsoftVisualCSharp2010StepByStepSuite);
}

void BookCSharp::TestingHelper
	::AddEssentialCSharp5Suite()
{
	ADD_TEST_BEGIN(essentialCSharp5Suite, "C# ������");



	ADD_TEST_END(essentialCSharp5Suite);
}

void BookCSharp::TestingHelper
	::AddCSharpInDepthSuite()
{
	ADD_TEST_BEGIN(cSharpInDepthSuite, "������� C#");



	ADD_TEST_END(cSharpInDepthSuite);
}

void BookCSharp::TestingHelper
	::AddProgrammingCSharpSuite()
{
	ADD_TEST_BEGIN(programmingCSharpSuite, " Programming C#");



	ADD_TEST_END(programmingCSharpSuite);
}

void BookCSharp::TestingHelper
	::AddIllstratedCSharp2012Suite()
{
	ADD_TEST_BEGIN(illstratedCSharp2012Suite, "C# ͼ��̳�");



	ADD_TEST_END(illstratedCSharp2012Suite);
}

void BookCSharp::TestingHelper
	::AddCLRViaCSharpSuite()
{
	ADD_TEST_BEGIN(cLRViaCSharpSuite, "CLR via C#");



	ADD_TEST_END(cLRViaCSharpSuite);
}

