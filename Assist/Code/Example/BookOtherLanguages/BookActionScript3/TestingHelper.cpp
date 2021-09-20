// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���渨���汾��0.0.0.2 (2019/09/29 21:01)

#include "TestingHelper.h"
#include "Testing.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

CMAIN_FUNCTION_HELPER_SUBCLASS_COMPLETE_DEFINE(BookActionScript3, TestingHelper, "�鼮 Action Script 3.0")

void BookActionScript3::TestingHelper
	::AddSuites()
{
	AddFoundationActionScript3AnimationMakingThingsMoveSuite();
	AddAdvancedActionScript3AnimationSuite();
	AddActionScriptForMultiplayerGamesAndVirtualWorldsSuite();
	AddAdvancedActionScript3WithDesignPatternsSuite();

	AddAdvancedActionScript3VisualQuickStartGuideSuite();
	AddActionScript3BibleSuite();
	AddActionScript3CookbookSuite();
}

void BookActionScript3::TestingHelper
	::AddFoundationActionScript3AnimationMakingThingsMoveSuite()
{
	ADD_TEST_BEGIN(foundationActionScript3AnimationMakingThingsMoveSuite, "Flash ActionScript 3.0 �����̳�");



	ADD_TEST_END(foundationActionScript3AnimationMakingThingsMoveSuite);
}

void BookActionScript3::TestingHelper
	::AddAdvancedActionScript3AnimationSuite()
{
	ADD_TEST_BEGIN(advancedActionScript3AnimationSuite, "Flash ActionScript 3.0 �����߼��̳�");



	ADD_TEST_END(advancedActionScript3AnimationSuite);
}

void BookActionScript3::TestingHelper
	::AddActionScriptForMultiplayerGamesAndVirtualWorldsSuite()
{
	ADD_TEST_BEGIN(actionScriptForMultiplayerGamesAndVirtualWorldsSuite, "Action Script ������ҳ��Ϸ����");



	ADD_TEST_END(actionScriptForMultiplayerGamesAndVirtualWorldsSuite);
}

void BookActionScript3::TestingHelper
	::AddAdvancedActionScript3WithDesignPatternsSuite()
{
	ADD_TEST_BEGIN(advancedActionScript3WithDesignPatternsSuite, "ActionScrip 3 ���ģʽ");



	ADD_TEST_END(advancedActionScript3WithDesignPatternsSuite);
}

void BookActionScript3::TestingHelper
	::AddAdvancedActionScript3VisualQuickStartGuideSuite()
{
	ADD_TEST_BEGIN(advancedActionScript3VisualQuickStartGuideSuite, "ActionScript 3.0 �����̳�");



	ADD_TEST_END(advancedActionScript3VisualQuickStartGuideSuite);
}

void BookActionScript3::TestingHelper
	::AddActionScript3BibleSuite()
{
	ADD_TEST_BEGIN(actionScript3BibleSuite, "ActionScript 3.0 ����");



	ADD_TEST_END(actionScript3BibleSuite);
}

void BookActionScript3::TestingHelper
	::AddActionScript3CookbookSuite()
{
	ADD_TEST_BEGIN(actionScript3CookbookSuite, "ActionScript 3.0 Cookbook");



	ADD_TEST_END(actionScript3CookbookSuite);
}

