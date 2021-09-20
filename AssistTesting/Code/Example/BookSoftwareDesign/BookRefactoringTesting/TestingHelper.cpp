// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ���渨�����԰汾��0.0.0.1 (2019/09/29 13:44)

#include "TestingHelper.h"
#include "Testing.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

CMAIN_FUNCTION_HELPER_SUBCLASS_COMPLETE_DEFINE(BookRefactoring, TestingHelper, "�鼮 �ع�")

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
	ADD_TEST_BEGIN(refactoringImprovingTheDesignofExistingCodeSuite, "�ع������Ƽ��д�������");

	ADD_TEST_END(refactoringImprovingTheDesignofExistingCodeSuite);
}

void BookRefactoring::TestingHelper
	::AddRefactoringToPatternsSuite()
{
	ADD_TEST_BEGIN(refactoringToPatternsSuite, "�ع���ģʽ");

	ADD_TEST_END(refactoringToPatternsSuite);
}

void BookRefactoring::TestingHelper
	::AddRefactoringWorkbookSuite()
{
	ADD_TEST_BEGIN(refactoringWorkbookSuite, "�ع��ֲ�");

	ADD_TEST_END(refactoringWorkbookSuite);
}

