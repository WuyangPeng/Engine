// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎辅助版本：0.0.0.2 (2019/09/28 16:40)

#include "TestingHelper.h"
#include "Testing.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

CMAIN_FUNCTION_HELPER_SUBCLASS_COMPLETE_DEFINE(BookArtificialIntellegence, TestingHelper, "书籍 人工智能")

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
	ADD_TEST_BEGIN(programmingGameAIByExampleSuite, "游戏人工智能编程案例精粹");



	ADD_TEST_END(programmingGameAIByExampleSuite);
}

void BookArtificialIntellegence::TestingHelper
	::AddAITechniquesForGameProgrammingSuite()
{
	ADD_TEST_BEGIN(aiTechniquesForGameProgrammingSuite, "游戏编程中的人工智能技术");



	ADD_TEST_END(aiTechniquesForGameProgrammingSuite);
}

void BookArtificialIntellegence::TestingHelper
	::AddAIForGameDevelopersSuite()
{
	ADD_TEST_BEGIN(aiForGameDevelopersSuite, "游戏开发中的人工智能");



	ADD_TEST_END(aiForGameDevelopersSuite);
}

void BookArtificialIntellegence::TestingHelper
	::AddAIGameEngineProgrammingSuite()
{
	ADD_TEST_BEGIN(aiGameEngineProgrammingSuite, "AI游戏引擎程序设计");



	ADD_TEST_END(aiGameEngineProgrammingSuite);
}

void BookArtificialIntellegence::TestingHelper
	::AddAIGameProgrammingWisdomSuite()
{
	ADD_TEST_BEGIN(aiGameProgrammingWisdomSuite, " 人工智能游戏编程真言");



	ADD_TEST_END(aiGameProgrammingWisdomSuite);
}

