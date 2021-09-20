// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎辅助测试版本：0.0.0.1 (2019/09/28 19:50)

#include "TestingHelper.h"
#include "Testing.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

CMAIN_FUNCTION_HELPER_SUBCLASS_COMPLETE_DEFINE(BookDirectX, TestingHelper, "书籍 DirectX")

void BookDirectX::TestingHelper
	::AddSuites()
{
	AddIntroductionTo3DGameProgrammingWithDirectX90cSuite();
	AddAdvanced3DGameProgrammingWithDirectX10Suite();
	AddGameCodingCompleteSuite();
	AddMultiplayerGameProgrammingSuite();

	AddBeginningGameProgrammingSuite();
	AddRealTimeRenderingTricksAndTechniquesInDirectXSuite();
	AddAdvancedAnimationWithDirectSuite();
	AddProgrammingRolePlayingGamesWithDirectXSuite();

	AddRickOfTheWindowsGameProgrammingGuruSuite();
	AddTricksOfThe3DGameProgrammingGurusSuite();
	AddGameProgrammingAllInOneSuite();
}

void BookDirectX::TestingHelper
	::AddIntroductionTo3DGameProgrammingWithDirectX90cSuite()
{
	ADD_TEST_BEGIN(introductionTo3DGameProgrammingWithDirectX90cSuite, "DirectX 9.0 3D 游戏开发编程基础");



	ADD_TEST_END(introductionTo3DGameProgrammingWithDirectX90cSuite);
}

void BookDirectX::TestingHelper
	::AddAdvanced3DGameProgrammingWithDirectX10Suite()
{
	ADD_TEST_BEGIN(advanced3DGameProgrammingWithDirectX10Suite, "DirectX 10 3D游戏编程深度探索");



	ADD_TEST_END(advanced3DGameProgrammingWithDirectX10Suite);
}

void BookDirectX::TestingHelper
	::AddGameCodingCompleteSuite()
{
	ADD_TEST_BEGIN(gameCodingCompleteSuite, "游戏编程全接触");



	ADD_TEST_END(gameCodingCompleteSuite);
}

void BookDirectX::TestingHelper
	::AddMultiplayerGameProgrammingSuite()
{
	ADD_TEST_BEGIN(multiplayerGameProgrammingSuite, "多玩家游戏程序设计");



	ADD_TEST_END(multiplayerGameProgrammingSuite);
}

void BookDirectX::TestingHelper
	::AddBeginningGameProgrammingSuite()
{
	ADD_TEST_BEGIN(beginningGameProgrammingSuite, "游戏编程入门");



	ADD_TEST_END(beginningGameProgrammingSuite);
}

void BookDirectX::TestingHelper
	::AddRealTimeRenderingTricksAndTechniquesInDirectXSuite()
{
	ADD_TEST_BEGIN(realTimeRenderingTricksAndTechniquesInDirectXSuite, "DirectX 实时渲染技术详解");



	ADD_TEST_END(realTimeRenderingTricksAndTechniquesInDirectXSuite);
}

void BookDirectX::TestingHelper
	::AddAdvancedAnimationWithDirectSuite()
{
	ADD_TEST_BEGIN(advancedAnimationWithDirectSuite, "DirectX 高级动画制作");



	ADD_TEST_END(advancedAnimationWithDirectSuite);
}

void BookDirectX::TestingHelper
	::AddProgrammingRolePlayingGamesWithDirectXSuite()
{
	ADD_TEST_BEGIN(programmingRolePlayingGamesWithDirectXSuite, "DirectX 角色扮演游戏编程");



	ADD_TEST_END(programmingRolePlayingGamesWithDirectXSuite);
}

void BookDirectX::TestingHelper
	::AddRickOfTheWindowsGameProgrammingGuruSuite()
{
	ADD_TEST_BEGIN(rickOfTheWindowsGameProgrammingGuruSuite, "Windows 游戏编程大师技巧");



	ADD_TEST_END(rickOfTheWindowsGameProgrammingGuruSuite);
}

void BookDirectX::TestingHelper
	::AddTricksOfThe3DGameProgrammingGurusSuite()
{
	ADD_TEST_BEGIN(tricksOfThe3DGameProgrammingGurusSuite, "3D游戏编程大师技巧");



	ADD_TEST_END(tricksOfThe3DGameProgrammingGurusSuite);
}

void BookDirectX::TestingHelper
	::AddGameProgrammingAllInOneSuite()
{
	ADD_TEST_BEGIN(gameProgrammingAllInOneSuite, "游戏编程 All In One");



	ADD_TEST_END(gameProgrammingAllInOneSuite);
}

