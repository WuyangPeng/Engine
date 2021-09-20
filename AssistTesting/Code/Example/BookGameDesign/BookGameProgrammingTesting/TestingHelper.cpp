// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎辅助测试版本：0.0.0.1 (2019/09/28 20:16)

#include "TestingHelper.h"
#include "Testing.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

CMAIN_FUNCTION_HELPER_SUBCLASS_COMPLETE_DEFINE(BookGameProgramming, TestingHelper, "书籍 游戏编程")

void BookGameProgramming::TestingHelper
	::AddSuites()
{
	AddGameProgrammingGemsSuite();
	AddGameProgrammingPatternsSuite();
}

void BookGameProgramming::TestingHelper
	::AddGameProgrammingGemsSuite()
{
	ADD_TEST_BEGIN(gameProgrammingGemsSuite, "游戏编程精粹");



	ADD_TEST_END(gameProgrammingGemsSuite);
}

void BookGameProgramming::TestingHelper
	::AddGameProgrammingGems1Suite(Suite& gameProgrammingGemsSuite)
{
	ADD_TEST_BEGIN(gameProgrammingGems1Suite, "游戏编程精粹1");



	gameProgrammingGemsSuite.AddSuite(gameProgrammingGems1Suite);
}

void BookGameProgramming::TestingHelper
	::AddGameProgrammingGems2Suite(Suite& gameProgrammingGemsSuite)
{
	ADD_TEST_BEGIN(gameProgrammingGems2Suite, "游戏编程精粹2");



	gameProgrammingGemsSuite.AddSuite(gameProgrammingGems2Suite);
}

void BookGameProgramming::TestingHelper
	::AddGameProgrammingGems3Suite(Suite& gameProgrammingGemsSuite)
{
	ADD_TEST_BEGIN(gameProgrammingGems3Suite, "游戏编程精粹3");



	gameProgrammingGemsSuite.AddSuite(gameProgrammingGems3Suite);
}

void BookGameProgramming::TestingHelper
	::AddGameProgrammingGems4Suite(Suite& gameProgrammingGemsSuite)
{
	ADD_TEST_BEGIN(gameProgrammingGems4Suite, "游戏编程精粹4");



	gameProgrammingGemsSuite.AddSuite(gameProgrammingGems4Suite);
}

void BookGameProgramming::TestingHelper
	::AddGameProgrammingGems5Suite(Suite& gameProgrammingGemsSuite)
{
	ADD_TEST_BEGIN(gameProgrammingGems5Suite, "游戏编程精粹5");



	gameProgrammingGemsSuite.AddSuite(gameProgrammingGems5Suite);
}

void BookGameProgramming::TestingHelper
	::AddGameProgrammingGems6Suite(Suite& gameProgrammingGemsSuite)
{
	ADD_TEST_BEGIN(gameProgrammingGems6Suite, "游戏编程精粹6");



	gameProgrammingGemsSuite.AddSuite(gameProgrammingGems6Suite);
}

void BookGameProgramming::TestingHelper
	::AddGameProgrammingGems7Suite(Suite& gameProgrammingGemsSuite)
{
	ADD_TEST_BEGIN(gameProgrammingGems7Suite, "游戏编程精粹7");



	gameProgrammingGemsSuite.AddSuite(gameProgrammingGems7Suite);
}

void BookGameProgramming::TestingHelper
	::AddGameProgrammingPatternsSuite()
{
	ADD_TEST_BEGIN(gameProgrammingPatternsSuite, "游戏编程模式");



	ADD_TEST_END(gameProgrammingPatternsSuite);
}

