// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���渨�����԰汾��0.0.0.1 (2019/09/28 20:49)

#include "TestingHelper.h"
#include "Testing.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

CMAIN_FUNCTION_HELPER_SUBCLASS_COMPLETE_DEFINE(BookPhysics, TestingHelper, "�鼮 ����ѧ")

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
	ADD_TEST_BEGIN(gamePhysicsEngineDevelopmentSuite, "��Ϸ�������濪��");



	ADD_TEST_END(gamePhysicsEngineDevelopmentSuite);
}

void BookPhysics::TestingHelper
	::AddPhysicsForGameDevelopersSuite()
{
	ADD_TEST_BEGIN(physicsForGameDevelopersSuite, "��Ϸ��������ѧ");



	ADD_TEST_END(physicsForGameDevelopersSuite);
}

void BookPhysics::TestingHelper
	::AddBeginningMathAndPhysicsSuite()
{
	ADD_TEST_BEGIN(beginningMathAndPhysicsSuite, "��Ϸ����е�����Ӧ��");



	ADD_TEST_END(beginningMathAndPhysicsSuite);
}

