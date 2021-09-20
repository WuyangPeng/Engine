// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���渨�����԰汾��0.0.0.1 (2019/09/28 20:02)

#include "TestingHelper.h"
#include "Testing.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

CMAIN_FUNCTION_HELPER_SUBCLASS_COMPLETE_DEFINE(BookGameEngine, TestingHelper, "�鼮 ��Ϸ����")

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
	ADD_TEST_BEGIN(threeDGameEngineDesignSuite, "3D��Ϸ�������");



	ADD_TEST_END(threeDGameEngineDesignSuite);
}

void BookGameEngine::TestingHelper
	::AddMasteringUnrealTechnologySuite()
{
	ADD_TEST_BEGIN(masteringUnrealTechnologySuite, "��ͨUnreal Engine 3");



	ADD_TEST_END(masteringUnrealTechnologySuite);
}

void BookGameEngine::TestingHelper
	::AddMasteringUnrealTechnologyIntroductionToLevelDesignWithUnrealEngine3Suite(Suite& masteringUnrealTechnologySuite)
{
	ADD_TEST_BEGIN(masteringUnrealTechnologyIntroductionToLevelDesignWithUnrealEngine3Suite, "3D��Ϸ�ؿ���ƻ���ƪ");



	masteringUnrealTechnologySuite.AddSuite(masteringUnrealTechnologyIntroductionToLevelDesignWithUnrealEngine3Suite);
}

void BookGameEngine::TestingHelper
	::AddMasteringUnrealTechnologyAdvancedLevelDesignConceptsWithUnrealEngine3Suite(Suite& masteringUnrealTechnologySuite)
{
	ADD_TEST_BEGIN(masteringUnrealTechnologyAdvancedLevelDesignConceptsWithUnrealEngine3Suite, "3D��Ϸ�ؿ���Ƹ߼�ƪ");



	masteringUnrealTechnologySuite.AddSuite(masteringUnrealTechnologyAdvancedLevelDesignConceptsWithUnrealEngine3Suite);
}

void BookGameEngine::TestingHelper
	::AddGameEngineArchitectureSuite()
{
	ADD_TEST_BEGIN(gameEngineArchitectureSuite, "��Ϸ����ܹ�");



	ADD_TEST_END(gameEngineArchitectureSuite);
}

