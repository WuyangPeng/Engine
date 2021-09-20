// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.0.0.3 (2019/09/02 13:08)

#include "TestingHelper.h"
#include "Testing.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestSuite.h"

CMAIN_FUNCTION_HELPER_SUBCLASS_COMPLETE_DEFINE(ResourceManager, TestingHelper, "��Դ�����") 

// private
void ResourceManager::TestingHelper ::AddSuites()
{
	AddMacroSuite(); 
	AddThreeDimensionalModelSuite();
	AddTextureSuite();
	AddMaterialSuite();
	AddFontSuite();
	AddSkeletonSuite();
	AddCollisionSuite();
	AddPhysicalParametersSuite();
	AddGameWorldMapSuite();
	AddMiscellaneousSuite();
}

void ResourceManager::TestingHelper
	::AddMacroSuite()
{
	ADD_TEST_BEGIN(macroSuite, "��");

	ADD_TEST_END(macroSuite);
}

void ResourceManager::TestingHelper
	::AddThreeDimensionalModelSuite()
{
	ADD_TEST_BEGIN(threeDimensionalModelSuite, "��άģ����Դ");

	ADD_TEST_END(threeDimensionalModelSuite);
}

void ResourceManager::TestingHelper
	::AddTextureSuite()
{
	ADD_TEST_BEGIN(textureSuite, "������Դ");

	ADD_TEST_END(textureSuite);
}

void ResourceManager::TestingHelper
	::AddMaterialSuite()
{
	ADD_TEST_BEGIN(materialSuite, "������Դ");

	ADD_TEST_END(materialSuite);
}

void ResourceManager::TestingHelper
	::AddFontSuite()
{
	ADD_TEST_BEGIN(fontSuite, "������Դ");

	ADD_TEST_END(fontSuite);
}

void ResourceManager::TestingHelper
	::AddSkeletonSuite()
{
	ADD_TEST_BEGIN(skeletonSuite, "������Դ");

	ADD_TEST_END(skeletonSuite);
}

void ResourceManager::TestingHelper
	::AddCollisionSuite()
{
	ADD_TEST_BEGIN(collisionSuite, "��ײ��Դ");

	ADD_TEST_END(collisionSuite);
}

void ResourceManager::TestingHelper
	::AddPhysicalParametersSuite()
{
	ADD_TEST_BEGIN(physicalParametersSuite, "�������");

	ADD_TEST_END(physicalParametersSuite);
}

void ResourceManager::TestingHelper
	::AddGameWorldMapSuite()
{
	ADD_TEST_BEGIN(gameWorldMapSuite, "��Ϸ����͵�ͼ");

	ADD_TEST_END(gameWorldMapSuite);
}

void ResourceManager::TestingHelper
	::AddMiscellaneousSuite()
{
	ADD_TEST_BEGIN(miscellaneousSuite, "����");

	ADD_TEST_END(miscellaneousSuite);
}

