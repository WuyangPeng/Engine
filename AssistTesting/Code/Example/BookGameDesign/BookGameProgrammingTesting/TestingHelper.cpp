// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���渨�����԰汾��0.0.0.1 (2019/09/28 20:16)

#include "TestingHelper.h"
#include "Testing.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

CMAIN_FUNCTION_HELPER_SUBCLASS_COMPLETE_DEFINE(BookGameProgramming, TestingHelper, "�鼮 ��Ϸ���")

void BookGameProgramming::TestingHelper
	::AddSuites()
{
	AddGameProgrammingGemsSuite();
	AddGameProgrammingPatternsSuite();
}

void BookGameProgramming::TestingHelper
	::AddGameProgrammingGemsSuite()
{
	ADD_TEST_BEGIN(gameProgrammingGemsSuite, "��Ϸ��̾���");



	ADD_TEST_END(gameProgrammingGemsSuite);
}

void BookGameProgramming::TestingHelper
	::AddGameProgrammingGems1Suite(Suite& gameProgrammingGemsSuite)
{
	ADD_TEST_BEGIN(gameProgrammingGems1Suite, "��Ϸ��̾���1");



	gameProgrammingGemsSuite.AddSuite(gameProgrammingGems1Suite);
}

void BookGameProgramming::TestingHelper
	::AddGameProgrammingGems2Suite(Suite& gameProgrammingGemsSuite)
{
	ADD_TEST_BEGIN(gameProgrammingGems2Suite, "��Ϸ��̾���2");



	gameProgrammingGemsSuite.AddSuite(gameProgrammingGems2Suite);
}

void BookGameProgramming::TestingHelper
	::AddGameProgrammingGems3Suite(Suite& gameProgrammingGemsSuite)
{
	ADD_TEST_BEGIN(gameProgrammingGems3Suite, "��Ϸ��̾���3");



	gameProgrammingGemsSuite.AddSuite(gameProgrammingGems3Suite);
}

void BookGameProgramming::TestingHelper
	::AddGameProgrammingGems4Suite(Suite& gameProgrammingGemsSuite)
{
	ADD_TEST_BEGIN(gameProgrammingGems4Suite, "��Ϸ��̾���4");



	gameProgrammingGemsSuite.AddSuite(gameProgrammingGems4Suite);
}

void BookGameProgramming::TestingHelper
	::AddGameProgrammingGems5Suite(Suite& gameProgrammingGemsSuite)
{
	ADD_TEST_BEGIN(gameProgrammingGems5Suite, "��Ϸ��̾���5");



	gameProgrammingGemsSuite.AddSuite(gameProgrammingGems5Suite);
}

void BookGameProgramming::TestingHelper
	::AddGameProgrammingGems6Suite(Suite& gameProgrammingGemsSuite)
{
	ADD_TEST_BEGIN(gameProgrammingGems6Suite, "��Ϸ��̾���6");



	gameProgrammingGemsSuite.AddSuite(gameProgrammingGems6Suite);
}

void BookGameProgramming::TestingHelper
	::AddGameProgrammingGems7Suite(Suite& gameProgrammingGemsSuite)
{
	ADD_TEST_BEGIN(gameProgrammingGems7Suite, "��Ϸ��̾���7");



	gameProgrammingGemsSuite.AddSuite(gameProgrammingGems7Suite);
}

void BookGameProgramming::TestingHelper
	::AddGameProgrammingPatternsSuite()
{
	ADD_TEST_BEGIN(gameProgrammingPatternsSuite, "��Ϸ���ģʽ");



	ADD_TEST_END(gameProgrammingPatternsSuite);
}

