// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎辅助测试版本：0.0.0.1 (2019/09/28 20:02)

#include "TestingHelper.h"
#include "Testing.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

CMAIN_FUNCTION_HELPER_SUBCLASS_COMPLETE_DEFINE(BookGameEngine, TestingHelper, "书籍 游戏引擎")

void BookGameEngine::TestingHelper
	::AddSuites()
{
	Add3DGameEngineDesignSuite();
	AddMasteringUnrealTechnologySuite();
	AddGameEngineArchitectureSuite();
}

void BookGameEngine::TestingHelper
	::Add3DGameEngineDesignSuite()
{
	ADD_TEST_BEGIN(threeDGameEngineDesignSuite, "3D游戏引擎设计");



	ADD_TEST_END(threeDGameEngineDesignSuite);
}

void BookGameEngine::TestingHelper
	::AddMasteringUnrealTechnologySuite()
{
	ADD_TEST_BEGIN(masteringUnrealTechnologySuite, "精通Unreal Engine 3");



	ADD_TEST_END(masteringUnrealTechnologySuite);
}

void BookGameEngine::TestingHelper
	::AddMasteringUnrealTechnologyIntroductionToLevelDesignWithUnrealEngine3Suite(Suite& masteringUnrealTechnologySuite)
{
	ADD_TEST_BEGIN(masteringUnrealTechnologyIntroductionToLevelDesignWithUnrealEngine3Suite, "3D游戏关卡设计基础篇");



	masteringUnrealTechnologySuite.AddSuite(masteringUnrealTechnologyIntroductionToLevelDesignWithUnrealEngine3Suite);
}

void BookGameEngine::TestingHelper
	::AddMasteringUnrealTechnologyAdvancedLevelDesignConceptsWithUnrealEngine3Suite(Suite& masteringUnrealTechnologySuite)
{
	ADD_TEST_BEGIN(masteringUnrealTechnologyAdvancedLevelDesignConceptsWithUnrealEngine3Suite, "3D游戏关卡设计高级篇");



	masteringUnrealTechnologySuite.AddSuite(masteringUnrealTechnologyAdvancedLevelDesignConceptsWithUnrealEngine3Suite);
}

void BookGameEngine::TestingHelper
	::AddGameEngineArchitectureSuite()
{
	ADD_TEST_BEGIN(gameEngineArchitectureSuite, "游戏引擎架构");



	ADD_TEST_END(gameEngineArchitectureSuite);
}

