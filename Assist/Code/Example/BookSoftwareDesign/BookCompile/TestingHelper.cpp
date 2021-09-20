// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎辅助版本：0.0.0.2 (2019/09/29 09:46)

#include "TestingHelper.h"
#include "Testing.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

CMAIN_FUNCTION_HELPER_SUBCLASS_COMPLETE_DEFINE(BookCompile, TestingHelper, "书籍 编译")

void BookCompile::TestingHelper
	::AddSuites()
{
	AddLanguageImplementationPatternsSuite();
	AddCompilersPrinciplesTechniquesAndToolsSuite();
	AddAdvancedCompilerDesignAndImplementationSuite();

	AddModernCompilerImplementationInCSuite();
	AddStructureAndInterpretationOfComputerProgramsSuite();
}

void BookCompile::TestingHelper
	::AddLanguageImplementationPatternsSuite()
{
	ADD_TEST_BEGIN(languageImplementationPatternsSuite, "编程语言实现模式");

	ADD_TEST_END(languageImplementationPatternsSuite);
}

void BookCompile::TestingHelper
	::AddCompilersPrinciplesTechniquesAndToolsSuite()
{
	ADD_TEST_BEGIN(compilersPrinciplesTechniquesAndToolsSuite, "编译原理");

	ADD_TEST_END(compilersPrinciplesTechniquesAndToolsSuite);
}

void BookCompile::TestingHelper
	::AddAdvancedCompilerDesignAndImplementationSuite()
{
	ADD_TEST_BEGIN(advancedCompilerDesignAndImplementationSuite, "高级编译器设计与实现");

	ADD_TEST_END(advancedCompilerDesignAndImplementationSuite);
}

void BookCompile::TestingHelper
	::AddModernCompilerImplementationInCSuite()
{
	ADD_TEST_BEGIN(modernCompilerImplementationInCSuite, "现代编译原理——C语言描述");

	ADD_TEST_END(modernCompilerImplementationInCSuite);
}

void BookCompile::TestingHelper
	::AddStructureAndInterpretationOfComputerProgramsSuite()
{
	ADD_TEST_BEGIN(structureAndInterpretationOfComputerProgramsSuite, "计算机程序的构造和解释");

	ADD_TEST_END(structureAndInterpretationOfComputerProgramsSuite);
}

