// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎测试版本：0.0.0.4 (2019/09/09 19:22)

#include "TestingHelper.h"
#include "Testing.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestSuite.h"

CMAIN_FUNCTION_HELPER_SUBCLASS_COMPLETE_DEFINE(Animation, TestingHelper, "动画库")

// private
void Animation::TestingHelper
	::AddSuites()
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

void Animation::TestingHelper
	::AddMacroSuite()
{
	ADD_TEST_BEGIN(macroSuite, "宏"); 

	ADD_TEST_END(macroSuite);
}

void Animation::TestingHelper
	::AddConsoleGraphSuite()
{
	ADD_TEST_BEGIN(consoleGraphSuite, "控制台图形");

	ADD_TEST_END(consoleGraphSuite);
}

void Animation::TestingHelper
	::AddElfAnimationSuite()
{
	ADD_TEST_BEGIN(elfAnimationSuite, "精灵动画");

	ADD_TEST_END(elfAnimationSuite);
}

void Animation::TestingHelper
	::AddTextureAnimationSuite()
{
	ADD_TEST_BEGIN(textureAnimationSuite, "纹理动画");

	ADD_TEST_END(textureAnimationSuite);
}

void Animation::TestingHelper
	::AddRigidBodyHierarchyAnimationSuite()
{
	ADD_TEST_BEGIN(rigidBodyHierarchyAnimationSuite, "刚体层次结构动画");

	ADD_TEST_END(rigidBodyHierarchyAnimationSuite);
}

void Animation::TestingHelper
	::AddSkeletonAnimationSuite()
{
	ADD_TEST_BEGIN(skeletonAnimationSuite, "骨骼动画");

	ADD_TEST_END(skeletonAnimationSuite);
}

void Animation::TestingHelper
	::AddPerVertexAnimationSuite()
{
	ADD_TEST_BEGIN(perVertexAnimationSuite, "每顶点动画");

	ADD_TEST_END(perVertexAnimationSuite);
}

void Animation::TestingHelper
	::AddMorphTargetAnimationSuite()
{
	ADD_TEST_BEGIN(morphTargetAnimationSuite, "变形目标动画");

	ADD_TEST_END(morphTargetAnimationSuite);
}

void Animation::TestingHelper
	::AddGradientAnimationSuite()
{
	ADD_TEST_BEGIN(gradientAnimationSuite, "渐变动画");

	ADD_TEST_END(gradientAnimationSuite);
}

void Animation::TestingHelper
	::AddAnimationManagerSuite()
{
	ADD_TEST_BEGIN(animationManagerSuite, "动画管理器");

	ADD_TEST_END(animationManagerSuite);
}

