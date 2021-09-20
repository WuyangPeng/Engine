// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎测试版本：0.0.0.3 (2019/09/02 13:08)

#include "TestingHelper.h"
#include "Testing.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestSuite.h"

CMAIN_FUNCTION_HELPER_SUBCLASS_COMPLETE_DEFINE(ResourceManager, TestingHelper, "资源管理库") 

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
	ADD_TEST_BEGIN(macroSuite, "宏");

	ADD_TEST_END(macroSuite);
}

void ResourceManager::TestingHelper
	::AddThreeDimensionalModelSuite()
{
	ADD_TEST_BEGIN(threeDimensionalModelSuite, "三维模型资源");

	ADD_TEST_END(threeDimensionalModelSuite);
}

void ResourceManager::TestingHelper
	::AddTextureSuite()
{
	ADD_TEST_BEGIN(textureSuite, "纹理资源");

	ADD_TEST_END(textureSuite);
}

void ResourceManager::TestingHelper
	::AddMaterialSuite()
{
	ADD_TEST_BEGIN(materialSuite, "材质资源");

	ADD_TEST_END(materialSuite);
}

void ResourceManager::TestingHelper
	::AddFontSuite()
{
	ADD_TEST_BEGIN(fontSuite, "字体资源");

	ADD_TEST_END(fontSuite);
}

void ResourceManager::TestingHelper
	::AddSkeletonSuite()
{
	ADD_TEST_BEGIN(skeletonSuite, "骨骼资源");

	ADD_TEST_END(skeletonSuite);
}

void ResourceManager::TestingHelper
	::AddCollisionSuite()
{
	ADD_TEST_BEGIN(collisionSuite, "碰撞资源");

	ADD_TEST_END(collisionSuite);
}

void ResourceManager::TestingHelper
	::AddPhysicalParametersSuite()
{
	ADD_TEST_BEGIN(physicalParametersSuite, "物理参数");

	ADD_TEST_END(physicalParametersSuite);
}

void ResourceManager::TestingHelper
	::AddGameWorldMapSuite()
{
	ADD_TEST_BEGIN(gameWorldMapSuite, "游戏世界和地图");

	ADD_TEST_END(gameWorldMapSuite);
}

void ResourceManager::TestingHelper
	::AddMiscellaneousSuite()
{
	ADD_TEST_BEGIN(miscellaneousSuite, "杂项");

	ADD_TEST_END(miscellaneousSuite);
}

