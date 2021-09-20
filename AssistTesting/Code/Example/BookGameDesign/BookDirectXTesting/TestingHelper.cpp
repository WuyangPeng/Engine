// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���渨�����԰汾��0.0.0.1 (2019/09/28 19:50)

#include "TestingHelper.h"
#include "Testing.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

CMAIN_FUNCTION_HELPER_SUBCLASS_COMPLETE_DEFINE(BookDirectX, TestingHelper, "�鼮 DirectX")

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
	ADD_TEST_BEGIN(introductionTo3DGameProgrammingWithDirectX90cSuite, "DirectX 9.0 3D ��Ϸ������̻���");



	ADD_TEST_END(introductionTo3DGameProgrammingWithDirectX90cSuite);
}

void BookDirectX::TestingHelper
	::AddAdvanced3DGameProgrammingWithDirectX10Suite()
{
	ADD_TEST_BEGIN(advanced3DGameProgrammingWithDirectX10Suite, "DirectX 10 3D��Ϸ������̽��");



	ADD_TEST_END(advanced3DGameProgrammingWithDirectX10Suite);
}

void BookDirectX::TestingHelper
	::AddGameCodingCompleteSuite()
{
	ADD_TEST_BEGIN(gameCodingCompleteSuite, "��Ϸ���ȫ�Ӵ�");



	ADD_TEST_END(gameCodingCompleteSuite);
}

void BookDirectX::TestingHelper
	::AddMultiplayerGameProgrammingSuite()
{
	ADD_TEST_BEGIN(multiplayerGameProgrammingSuite, "�������Ϸ�������");



	ADD_TEST_END(multiplayerGameProgrammingSuite);
}

void BookDirectX::TestingHelper
	::AddBeginningGameProgrammingSuite()
{
	ADD_TEST_BEGIN(beginningGameProgrammingSuite, "��Ϸ�������");



	ADD_TEST_END(beginningGameProgrammingSuite);
}

void BookDirectX::TestingHelper
	::AddRealTimeRenderingTricksAndTechniquesInDirectXSuite()
{
	ADD_TEST_BEGIN(realTimeRenderingTricksAndTechniquesInDirectXSuite, "DirectX ʵʱ��Ⱦ�������");



	ADD_TEST_END(realTimeRenderingTricksAndTechniquesInDirectXSuite);
}

void BookDirectX::TestingHelper
	::AddAdvancedAnimationWithDirectSuite()
{
	ADD_TEST_BEGIN(advancedAnimationWithDirectSuite, "DirectX �߼���������");



	ADD_TEST_END(advancedAnimationWithDirectSuite);
}

void BookDirectX::TestingHelper
	::AddProgrammingRolePlayingGamesWithDirectXSuite()
{
	ADD_TEST_BEGIN(programmingRolePlayingGamesWithDirectXSuite, "DirectX ��ɫ������Ϸ���");



	ADD_TEST_END(programmingRolePlayingGamesWithDirectXSuite);
}

void BookDirectX::TestingHelper
	::AddRickOfTheWindowsGameProgrammingGuruSuite()
{
	ADD_TEST_BEGIN(rickOfTheWindowsGameProgrammingGuruSuite, "Windows ��Ϸ��̴�ʦ����");



	ADD_TEST_END(rickOfTheWindowsGameProgrammingGuruSuite);
}

void BookDirectX::TestingHelper
	::AddTricksOfThe3DGameProgrammingGurusSuite()
{
	ADD_TEST_BEGIN(tricksOfThe3DGameProgrammingGurusSuite, "3D��Ϸ��̴�ʦ����");



	ADD_TEST_END(tricksOfThe3DGameProgrammingGurusSuite);
}

void BookDirectX::TestingHelper
	::AddGameProgrammingAllInOneSuite()
{
	ADD_TEST_BEGIN(gameProgrammingAllInOneSuite, "��Ϸ��� All In One");



	ADD_TEST_END(gameProgrammingAllInOneSuite);
}

