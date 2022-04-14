// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎测试版本：0.0.0.3 (2019/09/02 13:08)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Helper/ClassInvariant/ResourceManagerClassInvariantMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestSuite.h"

using namespace std::literals;

ResourceManager::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "资源管理库"s }
{
    InitSuite();

    RESOURCE_MANAGER_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(ResourceManager, TestingHelper)

void ResourceManager::TestingHelper::InitSuite()
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

void ResourceManager::TestingHelper ::AddMacroSuite()
{
    auto macroSuite = GenerateSuite("宏");

    AddSuite(macroSuite);
}

void ResourceManager::TestingHelper ::AddThreeDimensionalModelSuite()
{
    auto threeDimensionalModelSuite = GenerateSuite("三维模型资源");

    AddSuite(threeDimensionalModelSuite);
}

void ResourceManager::TestingHelper ::AddTextureSuite()
{
    auto textureSuite = GenerateSuite("纹理资源");

    AddSuite(textureSuite);
}

void ResourceManager::TestingHelper ::AddMaterialSuite()
{
    auto materialSuite = GenerateSuite("材质资源");

    AddSuite(materialSuite);
}

void ResourceManager::TestingHelper ::AddFontSuite()
{
    auto fontSuite = GenerateSuite("字体资源");

    AddSuite(fontSuite);
}

void ResourceManager::TestingHelper ::AddSkeletonSuite()
{
    auto skeletonSuite = GenerateSuite("骨骼资源");

    AddSuite(skeletonSuite);
}

void ResourceManager::TestingHelper ::AddCollisionSuite()
{
    auto collisionSuite = GenerateSuite("碰撞资源");

    AddSuite(collisionSuite);
}

void ResourceManager::TestingHelper ::AddPhysicalParametersSuite()
{
    auto physicalParametersSuite = GenerateSuite("物理参数");

    AddSuite(physicalParametersSuite);
}

void ResourceManager::TestingHelper ::AddGameWorldMapSuite()
{
    auto gameWorldMapSuite = GenerateSuite("游戏世界和地图");

    AddSuite(gameWorldMapSuite);
}

void ResourceManager::TestingHelper ::AddMiscellaneousSuite()
{
    auto miscellaneousSuite = GenerateSuite("杂项");

    AddSuite(miscellaneousSuite);
}
