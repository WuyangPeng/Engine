// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ������԰汾��0.0.0.3 (2019/09/02 13:08)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Helper/ClassInvariant/ResourceManagerClassInvariantMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestSuite.h"

using namespace std::literals;

ResourceManager::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "��Դ�����"s }
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
    auto macroSuite = GenerateSuite("��");

    AddSuite(macroSuite);
}

void ResourceManager::TestingHelper ::AddThreeDimensionalModelSuite()
{
    auto threeDimensionalModelSuite = GenerateSuite("��άģ����Դ");

    AddSuite(threeDimensionalModelSuite);
}

void ResourceManager::TestingHelper ::AddTextureSuite()
{
    auto textureSuite = GenerateSuite("������Դ");

    AddSuite(textureSuite);
}

void ResourceManager::TestingHelper ::AddMaterialSuite()
{
    auto materialSuite = GenerateSuite("������Դ");

    AddSuite(materialSuite);
}

void ResourceManager::TestingHelper ::AddFontSuite()
{
    auto fontSuite = GenerateSuite("������Դ");

    AddSuite(fontSuite);
}

void ResourceManager::TestingHelper ::AddSkeletonSuite()
{
    auto skeletonSuite = GenerateSuite("������Դ");

    AddSuite(skeletonSuite);
}

void ResourceManager::TestingHelper ::AddCollisionSuite()
{
    auto collisionSuite = GenerateSuite("��ײ��Դ");

    AddSuite(collisionSuite);
}

void ResourceManager::TestingHelper ::AddPhysicalParametersSuite()
{
    auto physicalParametersSuite = GenerateSuite("�������");

    AddSuite(physicalParametersSuite);
}

void ResourceManager::TestingHelper ::AddGameWorldMapSuite()
{
    auto gameWorldMapSuite = GenerateSuite("��Ϸ����͵�ͼ");

    AddSuite(gameWorldMapSuite);
}

void ResourceManager::TestingHelper ::AddMiscellaneousSuite()
{
    auto miscellaneousSuite = GenerateSuite("����");

    AddSuite(miscellaneousSuite);
}
