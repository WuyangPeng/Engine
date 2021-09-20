// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎辅助测试版本：0.0.0.1 (2019/09/29 21:41)

#include "TestingHelper.h"
#include "Testing.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

CMAIN_FUNCTION_HELPER_SUBCLASS_COMPLETE_DEFINE(BookCSharp, TestingHelper, "书籍 C#")

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
	ADD_TEST_BEGIN(beginningCSharp6ProgrammingWithVisualStudio2015Suite, "C# 入门经典");



	ADD_TEST_END(beginningCSharp6ProgrammingWithVisualStudio2015Suite);
}

void BookCSharp::TestingHelper
	::AddProCSharp2010AndTheNET4PlatformSuite()
{
	ADD_TEST_BEGIN(proCSharp2010AndTheNET4PlatformSuite, "C# 与 NET4 高级程序设计");



	ADD_TEST_END(proCSharp2010AndTheNET4PlatformSuite);
}

void BookCSharp::TestingHelper
	::AddProfessionalCSharp6AndNETCore1Suite()
{
	ADD_TEST_BEGIN(professionalCSharp6AndNETCore1Suite, "C# 高级编程");



	ADD_TEST_END(professionalCSharp6AndNETCore1Suite);
}

void BookCSharp::TestingHelper
	::AddEffectiveCSharpSuite()
{
	ADD_TEST_BEGIN(effectiveCSharpSuite, "C# 高效编程");



	ADD_TEST_END(effectiveCSharpSuite);
}

void BookCSharp::TestingHelper
	::AddMicrosoftVisualCSharp2010StepByStepSuite()
{
	ADD_TEST_BEGIN(microsoftVisualCSharp2010StepByStepSuite, "Visual C# 2010 从入门到精通");



	ADD_TEST_END(microsoftVisualCSharp2010StepByStepSuite);
}

void BookCSharp::TestingHelper
	::AddEssentialCSharp5Suite()
{
	ADD_TEST_BEGIN(essentialCSharp5Suite, "C# 本质论");



	ADD_TEST_END(essentialCSharp5Suite);
}

void BookCSharp::TestingHelper
	::AddCSharpInDepthSuite()
{
	ADD_TEST_BEGIN(cSharpInDepthSuite, "深入理解 C#");



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
	ADD_TEST_BEGIN(illstratedCSharp2012Suite, "C# 图解教程");



	ADD_TEST_END(illstratedCSharp2012Suite);
}

void BookCSharp::TestingHelper
	::AddCLRViaCSharpSuite()
{
	ADD_TEST_BEGIN(cLRViaCSharpSuite, "CLR via C#");



	ADD_TEST_END(cLRViaCSharpSuite);
}

