///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/01 20:04)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Helper/ClassInvariant/AnimationClassInvariantMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestSuite.h"

Animation::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "动画库" }
{
    InitSuite();

    ANIMATION_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Animation, TestingHelper)

void Animation::TestingHelper::InitSuite()
{
    AddHelperSuite();
    AddSpriteAnimationSuite();
    AddTextureAnimationSuite();
    AddRigidBodyHierarchyAnimationSuite();
    AddSkeletonAnimationSuite();
    AddPerVertexAnimationSuite();
    AddMorphTargetAnimationSuite();
    AddGradientAnimationSuite();
    AddAnimationManagerSuite();
}

void Animation::TestingHelper::AddHelperSuite()
{
    auto helperSuite = GenerateSuite("帮助");

    AddSuite(helperSuite);
}

void Animation::TestingHelper::AddSpriteAnimationSuite()
{
    auto spriteAnimationSuite = GenerateSuite("精灵动画");

    AddSuite(spriteAnimationSuite);
}

void Animation::TestingHelper::AddTextureAnimationSuite()
{
    auto textureAnimationSuite = GenerateSuite("纹理动画");

    AddSuite(textureAnimationSuite);
}

void Animation::TestingHelper::AddRigidBodyHierarchyAnimationSuite()
{
    auto rigidBodyHierarchyAnimationSuite = GenerateSuite("刚体层次结构动画");

    AddSuite(rigidBodyHierarchyAnimationSuite);
}

void Animation::TestingHelper::AddSkeletonAnimationSuite()
{
    auto skeletonAnimationSuite = GenerateSuite("骨骼动画");

    AddSuite(skeletonAnimationSuite);
}

void Animation::TestingHelper::AddPerVertexAnimationSuite()
{
    auto perVertexAnimationSuite = GenerateSuite("每顶点动画");

    AddSuite(perVertexAnimationSuite);
}

void Animation::TestingHelper::AddMorphTargetAnimationSuite()
{
    auto morphTargetAnimationSuite = GenerateSuite("变形目标动画");

    AddSuite(morphTargetAnimationSuite);
}

void Animation::TestingHelper::AddGradientAnimationSuite()
{
    auto gradientAnimationSuite = GenerateSuite("渐变动画");

    AddSuite(gradientAnimationSuite);
}

void Animation::TestingHelper::AddAnimationManagerSuite()
{
    auto animationManagerSuite = GenerateSuite("动画管理器");

    AddSuite(animationManagerSuite);
}
