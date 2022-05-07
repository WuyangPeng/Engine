// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���渨�����԰汾��0.0.0.1 (2019/09/28 19:54)

#include "TestingHelper.h"
#include "Testing.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

CMAIN_FUNCTION_HELPER_SUBCLASS_COMPLETE_DEFINE(BookGameDesignChild, TestingHelper, "�鼮 ��Ϸ���")

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
	ADD_TEST_BEGIN(theArtOfGameDesignABookOfLensesSuite, "ȫ��̽����Ϸ�������");



	ADD_TEST_END(theArtOfGameDesignABookOfLensesSuite);
}

void BookGameDesignChild::TestingHelper
	::AddGameDesignTheoryAndPracticeSuite()
{
	ADD_TEST_BEGIN(gameDesignTheoryAndPracticeSuite, "��Ϸ��ƣ�ԭ����ʵ��");



	ADD_TEST_END(gameDesignTheoryAndPracticeSuite);
}

void BookGameDesignChild::TestingHelper
	::AddObjectOrientedGameDevelopmentSuite()
{
	ADD_TEST_BEGIN(objectOrientedGameDevelopmentSuite, "����������Ϸ����");



	ADD_TEST_END(objectOrientedGameDevelopmentSuite);
}

void BookGameDesignChild::TestingHelper
	::AddMassivelyMultiplayerGameDevelopmentSuite()
{
	ADD_TEST_BEGIN(massivelyMultiplayerGameDevelopmentSuite, "���Ͷ���������Ϸ����");



	ADD_TEST_END(massivelyMultiplayerGameDevelopmentSuite);
}
