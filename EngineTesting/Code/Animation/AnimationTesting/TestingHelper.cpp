///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.9 (2022/06/21 16:36)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Helper/ClassInvariant/AnimationClassInvariantMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestSuite.h"

// private
Animation::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "动画库" }
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
    auto macroSuite = GenerateSuite("宏");

    AddSuite(macroSuite);
}

void Animation::TestingHelper::AddConsoleGraphSuite()
{
    auto consoleGraphSuite = GenerateSuite("控制台图形");

    AddSuite(consoleGraphSuite);
}

void Animation::TestingHelper::AddElfAnimationSuite()
{
    auto elfAnimationSuite = GenerateSuite("精灵动画");

    AddSuite(elfAnimationSuite);
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
