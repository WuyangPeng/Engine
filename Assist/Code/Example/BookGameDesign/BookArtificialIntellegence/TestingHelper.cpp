// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���渨���汾��0.0.0.2 (2019/09/28 16:40)

#include "TestingHelper.h"
#include "Testing.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

CMAIN_FUNCTION_HELPER_SUBCLASS_COMPLETE_DEFINE(BookArtificialIntellegence, TestingHelper, "�鼮 �˹�����")

void BookArtificialIntellegence::TestingHelper
	::AddSuites()
{
	AddProgrammingGameAIByExampleSuite();
	AddAITechniquesForGameProgrammingSuite();
	AddAIForGameDevelopersSuite();
	AddAIGameEngineProgrammingSuite();
	AddAIGameProgrammingWisdomSuite();	 
}

void BookArtificialIntellegence::TestingHelper
	::AddProgrammingGameAIByExampleSuite()
{
	ADD_TEST_BEGIN(programmingGameAIByExampleSuite, "��Ϸ�˹����ܱ�̰�������");



	ADD_TEST_END(programmingGameAIByExampleSuite);
}

void BookArtificialIntellegence::TestingHelper
	::AddAITechniquesForGameProgrammingSuite()
{
	ADD_TEST_BEGIN(aiTechniquesForGameProgrammingSuite, "��Ϸ����е��˹����ܼ���");



	ADD_TEST_END(aiTechniquesForGameProgrammingSuite);
}

void BookArtificialIntellegence::TestingHelper
	::AddAIForGameDevelopersSuite()
{
	ADD_TEST_BEGIN(aiForGameDevelopersSuite, "��Ϸ�����е��˹�����");



	ADD_TEST_END(aiForGameDevelopersSuite);
}

void BookArtificialIntellegence::TestingHelper
	::AddAIGameEngineProgrammingSuite()
{
	ADD_TEST_BEGIN(aiGameEngineProgrammingSuite, "AI��Ϸ����������");



	ADD_TEST_END(aiGameEngineProgrammingSuite);
}

void BookArtificialIntellegence::TestingHelper
	::AddAIGameProgrammingWisdomSuite()
{
	ADD_TEST_BEGIN(aiGameProgrammingWisdomSuite, " �˹�������Ϸ�������");



	ADD_TEST_END(aiGameProgrammingWisdomSuite);
}

