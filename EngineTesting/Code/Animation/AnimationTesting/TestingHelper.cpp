// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.0.0.4 (2019/09/09 19:22)

#include "TestingHelper.h"
#include "Testing.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestSuite.h"

CMAIN_FUNCTION_HELPER_SUBCLASS_COMPLETE_DEFINE(Animation, TestingHelper, "������")

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
	ADD_TEST_BEGIN(macroSuite, "��"); 

	ADD_TEST_END(macroSuite);
}

void Animation::TestingHelper
	::AddConsoleGraphSuite()
{
	ADD_TEST_BEGIN(consoleGraphSuite, "����̨ͼ��");

	ADD_TEST_END(consoleGraphSuite);
}

void Animation::TestingHelper
	::AddElfAnimationSuite()
{
	ADD_TEST_BEGIN(elfAnimationSuite, "���鶯��");

	ADD_TEST_END(elfAnimationSuite);
}

void Animation::TestingHelper
	::AddTextureAnimationSuite()
{
	ADD_TEST_BEGIN(textureAnimationSuite, "������");

	ADD_TEST_END(textureAnimationSuite);
}

void Animation::TestingHelper
	::AddRigidBodyHierarchyAnimationSuite()
{
	ADD_TEST_BEGIN(rigidBodyHierarchyAnimationSuite, "�����νṹ����");

	ADD_TEST_END(rigidBodyHierarchyAnimationSuite);
}

void Animation::TestingHelper
	::AddSkeletonAnimationSuite()
{
	ADD_TEST_BEGIN(skeletonAnimationSuite, "��������");

	ADD_TEST_END(skeletonAnimationSuite);
}

void Animation::TestingHelper
	::AddPerVertexAnimationSuite()
{
	ADD_TEST_BEGIN(perVertexAnimationSuite, "ÿ���㶯��");

	ADD_TEST_END(perVertexAnimationSuite);
}

void Animation::TestingHelper
	::AddMorphTargetAnimationSuite()
{
	ADD_TEST_BEGIN(morphTargetAnimationSuite, "����Ŀ�궯��");

	ADD_TEST_END(morphTargetAnimationSuite);
}

void Animation::TestingHelper
	::AddGradientAnimationSuite()
{
	ADD_TEST_BEGIN(gradientAnimationSuite, "���䶯��");

	ADD_TEST_END(gradientAnimationSuite);
}

void Animation::TestingHelper
	::AddAnimationManagerSuite()
{
	ADD_TEST_BEGIN(animationManagerSuite, "����������");

	ADD_TEST_END(animationManagerSuite);
}

