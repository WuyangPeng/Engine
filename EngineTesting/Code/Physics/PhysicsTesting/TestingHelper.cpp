// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ������԰汾��0.0.0.3 (2019/09/09 16:31)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelperDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestSuite.h"
CMAIN_FUNCTION_HELPER_SUBCLASS_COMPLETE_DEFINE(Physics, TestingHelper, "�����")

// private
void Physics::TestingHelper ::AddSuites()
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
    ADD_TEST_BEGIN(macroSuite, "��");

    ADD_TEST_END(macroSuite);
}

void Physics::TestingHelper ::AddCollisionDetectionSuite()
{
    ADD_TEST_BEGIN(collisionDetectionSuite, "��ײ���");

    ADD_TEST(collisionDetectionSuite, BoundTreeProjectionInfoTesting);
    ADD_TEST(collisionDetectionSuite, BoundTreeSplitTrianglesTesting);
    ADD_TEST(collisionDetectionSuite, BoundTreeChildTesting);
    ADD_TEST(collisionDetectionSuite, BoundTreeTesting);

    ADD_TEST_END(collisionDetectionSuite);
}

void Physics::TestingHelper ::AddFluidSuite()
{
    ADD_TEST_BEGIN(fluidSuite, "����");

    ADD_TEST_END(fluidSuite);
}

void Physics::TestingHelper ::AddIntersectionSuite()
{
    ADD_TEST_BEGIN(intersectionSuite, "�ཻ");

    ADD_TEST_END(intersectionSuite);
}

void Physics::TestingHelper ::AddLCPSolverSuite()
{
    ADD_TEST_BEGIN(lCPSolverSuite, "LCP���");

    ADD_TEST_END(lCPSolverSuite);
}

void Physics::TestingHelper ::AddParticleSystemSuite()
{
    ADD_TEST_BEGIN(particleSystemSuite, "����ϵͳ");

    ADD_TEST_END(particleSystemSuite);
}

void Physics::TestingHelper ::AddRigidBodySuite()
{
    ADD_TEST_BEGIN(rigidBodySuite, "����");

    ADD_TEST_END(rigidBodySuite);
}

void Physics::TestingHelper ::AddMiscellaneousSuite()
{
    ADD_TEST_BEGIN(miscellaneousSuite, "����");

    ADD_TEST_END(miscellaneousSuite);
}
