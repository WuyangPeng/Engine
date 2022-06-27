///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.9 (2022/06/21 16:36)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Helper/ClassInvariant/AnimationClassInvariantMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestSuite.h"

// private
Animation::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "������" }
{
    InitSuite();

    ANIMATION_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Animation, TestingHelper)

// private
void Animation::TestingHelper::InitSuite()
{
    AddMacroSuite();
    AddConsoleGraphSuite();
    AddElfAnimationSuite();
    AddTextureAnimationSuite();
    AddRigidBodyHierarchyAnimationSuite();
    AddSkeletonAnimationSuite();
    AddPerVertexAnimationSuite();
    AddMorphTargetAnimationSuite();
    AddGradientAnimationSuite();
    AddAnimationManagerSuite();
}

void Animation::TestingHelper::AddMacroSuite()
{
    auto macroSuite = GenerateSuite("��");

    AddSuite(macroSuite);
}

void Animation::TestingHelper::AddConsoleGraphSuite()
{
    auto consoleGraphSuite = GenerateSuite("����̨ͼ��");

    AddSuite(consoleGraphSuite);
}

void Animation::TestingHelper::AddElfAnimationSuite()
{
    auto elfAnimationSuite = GenerateSuite("���鶯��");

    AddSuite(elfAnimationSuite);
}

void Animation::TestingHelper::AddTextureAnimationSuite()
{
    auto textureAnimationSuite = GenerateSuite("������");

    AddSuite(textureAnimationSuite);
}

void Animation::TestingHelper::AddRigidBodyHierarchyAnimationSuite()
{
    auto rigidBodyHierarchyAnimationSuite = GenerateSuite("�����νṹ����");

    AddSuite(rigidBodyHierarchyAnimationSuite);
}

void Animation::TestingHelper::AddSkeletonAnimationSuite()
{
    auto skeletonAnimationSuite = GenerateSuite("��������");

    AddSuite(skeletonAnimationSuite);
}

void Animation::TestingHelper::AddPerVertexAnimationSuite()
{
    auto perVertexAnimationSuite = GenerateSuite("ÿ���㶯��");

    AddSuite(perVertexAnimationSuite);
}

void Animation::TestingHelper::AddMorphTargetAnimationSuite()
{
    auto morphTargetAnimationSuite = GenerateSuite("����Ŀ�궯��");

    AddSuite(morphTargetAnimationSuite);
}

void Animation::TestingHelper::AddGradientAnimationSuite()
{
    auto gradientAnimationSuite = GenerateSuite("���䶯��");

    AddSuite(gradientAnimationSuite);
}

void Animation::TestingHelper::AddAnimationManagerSuite()
{
    auto animationManagerSuite = GenerateSuite("����������");

    AddSuite(animationManagerSuite);
}
