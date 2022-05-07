// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ������԰汾��0.0.0.3 (2019/09/09 16:31)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Helper/ClassInvariant/PhysicsClassInvariantMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelperDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestSuite.h"

Physics::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "������" }
{
    InitSuite();

    PHYSICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Physics, TestingHelper)

// private
void Physics::TestingHelper ::InitSuite()
{
    AddMacroSuite();
    AddCollisionDetectionSuite();
    AddFluidSuite();
    AddIntersectionSuite();
    AddLCPSolverSuite();
    AddParticleSystemSuite();
    AddRigidBodySuite();
    AddMiscellaneousSuite();
}

void Physics::TestingHelper ::AddMacroSuite()
{
    auto macroSuite = GenerateSuite("��");

    AddSuite(macroSuite);
}

void Physics::TestingHelper ::AddCollisionDetectionSuite()
{
    auto collisionDetectionSuite = GenerateSuite("��ײ���");

    ADD_TEST(collisionDetectionSuite, BoundTreeProjectionInfoTesting);
    ADD_TEST(collisionDetectionSuite, BoundTreeSplitTrianglesTesting);
    ADD_TEST(collisionDetectionSuite, BoundTreeChildTesting);
    ADD_TEST(collisionDetectionSuite, BoundTreeTesting);

    AddSuite(collisionDetectionSuite);
}

void Physics::TestingHelper ::AddFluidSuite()
{
    auto fluidSuite = GenerateSuite("����");

    AddSuite(fluidSuite);
}

void Physics::TestingHelper ::AddIntersectionSuite()
{
    auto intersectionSuite = GenerateSuite("�ཻ");

    AddSuite(intersectionSuite);
}

void Physics::TestingHelper ::AddLCPSolverSuite()
{
    auto lCPSolverSuite = GenerateSuite("LCP���");

    AddSuite(lCPSolverSuite);
}

void Physics::TestingHelper ::AddParticleSystemSuite()
{
    auto particleSystemSuite = GenerateSuite("����ϵͳ"); 

    AddSuite(particleSystemSuite);
}

void Physics::TestingHelper ::AddRigidBodySuite()
{
    auto rigidBodySuite = GenerateSuite("����");   

    AddSuite(rigidBodySuite);
}

void Physics::TestingHelper ::AddMiscellaneousSuite()
{
    auto miscellaneousSuite = GenerateSuite("����");    

    AddSuite(miscellaneousSuite);
}