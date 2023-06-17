///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/10 14:22)

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
    AddHelperSuite();
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

void ResourceManager::TestingHelper::AddHelperSuite()
{
    auto helperSuite = GenerateSuite("����");

    AddSuite(helperSuite);
}

void ResourceManager::TestingHelper::AddThreeDimensionalModelSuite()
{
    auto threeDimensionalModelSuite = GenerateSuite("��άģ����Դ");

    AddSuite(threeDimensionalModelSuite);
}

void ResourceManager::TestingHelper::AddTextureSuite()
{
    auto textureSuite = GenerateSuite("������Դ");

    AddSuite(textureSuite);
}

void ResourceManager::TestingHelper::AddMaterialSuite()
{
    auto materialSuite = GenerateSuite("������Դ");

    AddSuite(materialSuite);
}

void ResourceManager::TestingHelper::AddFontSuite()
{
    auto fontSuite = GenerateSuite("������Դ");

    AddSuite(fontSuite);
}

void ResourceManager::TestingHelper::AddSkeletonSuite()
{
    auto skeletonSuite = GenerateSuite("������Դ");

    AddSuite(skeletonSuite);
}

void ResourceManager::TestingHelper::AddCollisionSuite()
{
    auto collisionSuite = GenerateSuite("��ײ��Դ");

    AddSuite(collisionSuite);
}

void ResourceManager::TestingHelper::AddPhysicalParametersSuite()
{
    auto physicalParametersSuite = GenerateSuite("�������");

    AddSuite(physicalParametersSuite);
}

void ResourceManager::TestingHelper::AddGameWorldMapSuite()
{
    auto gameWorldMapSuite = GenerateSuite("��Ϸ����͵�ͼ");

    AddSuite(gameWorldMapSuite);
}

void ResourceManager::TestingHelper::AddMiscellaneousSuite()
{
    auto miscellaneousSuite = GenerateSuite("����");

    AddSuite(miscellaneousSuite);
}
