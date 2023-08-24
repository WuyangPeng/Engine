///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/08/02 14:18)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Helper/ClassInvariant/PhysicsClassInvariantMacro.h"
#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelperDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestSuite.h"

Physics::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "�����" }
{
    InitSuite();

    PHYSICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Physics, TestingHelper)

void Physics::TestingHelper::InitSuite()
{
    AddHelperSuite();
    AddCollisionDetectionSuite();
    AddFluidSuite();
    AddIntersectionSuite();
    AddLCPSolverSuite();
    AddParticleSystemSuite();
    AddRigidBodySuite();
    AddMiscellaneousSuite();
}

void Physics::TestingHelper::AddHelperSuite()
{
    auto helperSuite = GenerateSuite("����");

    AddSuite(helperSuite);
}

void Physics::TestingHelper::AddCollisionDetectionSuite()
{
    auto collisionDetectionSuite = GenerateSuite("��ײ���");

    AddSuite(collisionDetectionSuite);
}

void Physics::TestingHelper::AddFluidSuite()
{
    auto fluidSuite = GenerateSuite("����");

    AddSuite(fluidSuite);
}

void Physics::TestingHelper::AddIntersectionSuite()
{
    auto intersectionSuite = GenerateSuite("�ཻ");

    AddSuite(intersectionSuite);
}

void Physics::TestingHelper::AddLCPSolverSuite()
{
    auto lCPSolverSuite = GenerateSuite("LCP���");

    AddSuite(lCPSolverSuite);
}

void Physics::TestingHelper::AddParticleSystemSuite()
{
    auto particleSystemSuite = GenerateSuite("����ϵͳ");

    AddSuite(particleSystemSuite);
}

void Physics::TestingHelper::AddRigidBodySuite()
{
    auto rigidBodySuite = GenerateSuite("����");

    AddSuite(rigidBodySuite);
}

void Physics::TestingHelper::AddMiscellaneousSuite()
{
    auto miscellaneousSuite = GenerateSuite("����");

    AddSuite(miscellaneousSuite);
}
