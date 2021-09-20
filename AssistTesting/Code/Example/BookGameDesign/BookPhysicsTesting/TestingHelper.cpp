// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎辅助测试版本：0.0.0.1 (2019/09/28 20:49)

#include "TestingHelper.h"
#include "Testing.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

CMAIN_FUNCTION_HELPER_SUBCLASS_COMPLETE_DEFINE(BookPhysics, TestingHelper, "书籍 物理学")

void BookPhysics::TestingHelper
	::AddSuites()
{
	AddGamePhysicsEngineDevelopmentSuite();
	AddPhysicsForGameDevelopersSuite();
	AddBeginningMathAndPhysicsSuite();
}

void BookPhysics::TestingHelper
	::AddGamePhysicsEngineDevelopmentSuite()
{
	ADD_TEST_BEGIN(gamePhysicsEngineDevelopmentSuite, "游戏物理引擎开发");



	ADD_TEST_END(gamePhysicsEngineDevelopmentSuite);
}

void BookPhysics::TestingHelper
	::AddPhysicsForGameDevelopersSuite()
{
	ADD_TEST_BEGIN(physicsForGameDevelopersSuite, "游戏开发物理学");



	ADD_TEST_END(physicsForGameDevelopersSuite);
}

void BookPhysics::TestingHelper
	::AddBeginningMathAndPhysicsSuite()
{
	ADD_TEST_BEGIN(beginningMathAndPhysicsSuite, "游戏编程中的数理应用");



	ADD_TEST_END(beginningMathAndPhysicsSuite);
}

