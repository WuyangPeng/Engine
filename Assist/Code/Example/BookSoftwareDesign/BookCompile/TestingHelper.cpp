// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ���渨���汾��0.0.0.2 (2019/09/29 09:46)

#include "TestingHelper.h"
#include "Testing.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

CMAIN_FUNCTION_HELPER_SUBCLASS_COMPLETE_DEFINE(BookCompile, TestingHelper, "�鼮 ����")

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
	ADD_TEST_BEGIN(languageImplementationPatternsSuite, "�������ʵ��ģʽ");

	ADD_TEST_END(languageImplementationPatternsSuite);
}

void BookCompile::TestingHelper
	::AddCompilersPrinciplesTechniquesAndToolsSuite()
{
	ADD_TEST_BEGIN(compilersPrinciplesTechniquesAndToolsSuite, "����ԭ��");

	ADD_TEST_END(compilersPrinciplesTechniquesAndToolsSuite);
}

void BookCompile::TestingHelper
	::AddAdvancedCompilerDesignAndImplementationSuite()
{
	ADD_TEST_BEGIN(advancedCompilerDesignAndImplementationSuite, "�߼������������ʵ��");

	ADD_TEST_END(advancedCompilerDesignAndImplementationSuite);
}

void BookCompile::TestingHelper
	::AddModernCompilerImplementationInCSuite()
{
	ADD_TEST_BEGIN(modernCompilerImplementationInCSuite, "�ִ�����ԭ����C��������");

	ADD_TEST_END(modernCompilerImplementationInCSuite);
}

void BookCompile::TestingHelper
	::AddStructureAndInterpretationOfComputerProgramsSuite()
{
	ADD_TEST_BEGIN(structureAndInterpretationOfComputerProgramsSuite, "���������Ĺ���ͽ���");

	ADD_TEST_END(structureAndInterpretationOfComputerProgramsSuite);
}

