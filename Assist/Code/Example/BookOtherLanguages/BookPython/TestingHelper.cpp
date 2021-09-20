// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎辅助版本：0.0.0.2 (2019/09/29 21:19)

#include "TestingHelper.h"
#include "Testing.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

CMAIN_FUNCTION_HELPER_SUBCLASS_COMPLETE_DEFINE(BookPython, TestingHelper, "书籍 Python")

void BookPython::TestingHelper
	::AddSuites()
{
	AddCorePythonApplicationsProgrammingSuite();
	AddExpertPythonProgrammingSuite();
	AddProgrammingCollectiveIntelligenceSuite();
	AddGrayHatPythonSuite();

	AddPythonCookbookSuite();
	AddPythonInANutsbellSuite();
	AddProgrammingInPython3Suite();

	AddPythonEssentialReferenceSuite();
	AddLearningPythonSuite();
	AddBeginningPythonFromNoviceToProfessionalSuite();
}

void BookPython::TestingHelper
	::AddCorePythonApplicationsProgrammingSuite()
{
	ADD_TEST_BEGIN(corePythonApplicationsProgrammingSuite, " Python 核心编程");



	ADD_TEST_END(corePythonApplicationsProgrammingSuite);
}

void BookPython::TestingHelper
	::AddExpertPythonProgrammingSuite()
{
	ADD_TEST_BEGIN(expertPythonProgrammingSuite, "Python 高级编程");



	ADD_TEST_END(expertPythonProgrammingSuite);
}

void BookPython::TestingHelper
	::AddProgrammingCollectiveIntelligenceSuite()
{
	ADD_TEST_BEGIN(programmingCollectiveIntelligenceSuite, "集体智慧编程");



	ADD_TEST_END(programmingCollectiveIntelligenceSuite);
}

void BookPython::TestingHelper
	::AddGrayHatPythonSuite()
{
	ADD_TEST_BEGIN(grayHatPythonSuite, "Python 灰帽子");



	ADD_TEST_END(grayHatPythonSuite);
}

void BookPython::TestingHelper
	::AddPythonCookbookSuite()
{
	ADD_TEST_BEGIN(pythonCookbookSuite, "Python Cookbook");



	ADD_TEST_END(pythonCookbookSuite);
}

void BookPython::TestingHelper
	::AddPythonInANutsbellSuite()
{
	ADD_TEST_BEGIN(pythonInANutsbellSuite, "Python 技术手册");



	ADD_TEST_END(pythonInANutsbellSuite);
}

void BookPython::TestingHelper
	::AddProgrammingInPython3Suite()
{
	ADD_TEST_BEGIN(programmingInPython3Suite, "Python3 程序开发指南");



	ADD_TEST_END(programmingInPython3Suite);
}

void BookPython::TestingHelper
	::AddPythonEssentialReferenceSuite()
{
	ADD_TEST_BEGIN(pythonEssentialReferenceSuite, "Python 参考手册");



	ADD_TEST_END(pythonEssentialReferenceSuite);
}

void BookPython::TestingHelper
	::AddLearningPythonSuite()
{
	ADD_TEST_BEGIN(learningPythonSuite, "Python 学习手册");



	ADD_TEST_END(learningPythonSuite);
}

void BookPython::TestingHelper
	::AddBeginningPythonFromNoviceToProfessionalSuite()
{
	ADD_TEST_BEGIN(beginningPythonFromNoviceToProfessionalSuite, "Python 基础教程");



	ADD_TEST_END(beginningPythonFromNoviceToProfessionalSuite);
}

