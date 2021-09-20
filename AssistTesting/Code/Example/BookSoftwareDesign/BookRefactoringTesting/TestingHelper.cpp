// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎辅助测试版本：0.0.0.1 (2019/09/29 13:44)

#include "TestingHelper.h"
#include "Testing.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

CMAIN_FUNCTION_HELPER_SUBCLASS_COMPLETE_DEFINE(BookRefactoring, TestingHelper, "书籍 重构")

void BookRefactoring::TestingHelper
	::AddSuites()
{
	AddRefactoringImprovingTheDesignofExistingCodeSuite();
	AddRefactoringToPatternsSuite();
	AddRefactoringWorkbookSuite();
}

void BookRefactoring::TestingHelper
	::AddRefactoringImprovingTheDesignofExistingCodeSuite()
{
	ADD_TEST_BEGIN(refactoringImprovingTheDesignofExistingCodeSuite, "重构：改善既有代码的设计");

	ADD_TEST_END(refactoringImprovingTheDesignofExistingCodeSuite);
}

void BookRefactoring::TestingHelper
	::AddRefactoringToPatternsSuite()
{
	ADD_TEST_BEGIN(refactoringToPatternsSuite, "重构与模式");

	ADD_TEST_END(refactoringToPatternsSuite);
}

void BookRefactoring::TestingHelper
	::AddRefactoringWorkbookSuite()
{
	ADD_TEST_BEGIN(refactoringWorkbookSuite, "重构手册");

	ADD_TEST_END(refactoringWorkbookSuite);
}

