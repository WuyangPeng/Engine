// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎辅助版本：0.0.0.2 (2019/09/28 16:41)

#include "TestingHelper.h"
#include "Testing.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

CMAIN_FUNCTION_HELPER_SUBCLASS_COMPLETE_DEFINE(BookGameDesignChild, TestingHelper, "书籍 游戏设计")

void BookGameDesignChild::TestingHelper
	::AddSuites()
{
	AddTheArtOfGameDesignABookOfLensesSuite();
	AddGameDesignTheoryAndPracticeSuite();
	AddObjectOrientedGameDevelopmentSuite();
	AddMassivelyMultiplayerGameDevelopmentSuite();
}

void BookGameDesignChild::TestingHelper
	::AddTheArtOfGameDesignABookOfLensesSuite()
{
	ADD_TEST_BEGIN(theArtOfGameDesignABookOfLensesSuite, "全景探秘游戏设计艺术");



	ADD_TEST_END(theArtOfGameDesignABookOfLensesSuite);
}

void BookGameDesignChild::TestingHelper
	::AddGameDesignTheoryAndPracticeSuite()
{
	ADD_TEST_BEGIN(gameDesignTheoryAndPracticeSuite, "游戏设计：原理与实践");



	ADD_TEST_END(gameDesignTheoryAndPracticeSuite);
}

void BookGameDesignChild::TestingHelper
	::AddObjectOrientedGameDevelopmentSuite()
{
	ADD_TEST_BEGIN(objectOrientedGameDevelopmentSuite, "面向对象的游戏开发");



	ADD_TEST_END(objectOrientedGameDevelopmentSuite);
}

void BookGameDesignChild::TestingHelper
	::AddMassivelyMultiplayerGameDevelopmentSuite()
{
	ADD_TEST_BEGIN(massivelyMultiplayerGameDevelopmentSuite, "大型多人在线游戏开发");



	ADD_TEST_END(massivelyMultiplayerGameDevelopmentSuite);
}

