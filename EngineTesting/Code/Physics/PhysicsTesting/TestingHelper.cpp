// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎测试版本：0.0.0.3 (2019/09/09 16:31)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelperDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestSuite.h"
CMAIN_FUNCTION_HELPER_SUBCLASS_COMPLETE_DEFINE(Physics, TestingHelper, "物理库")

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
    ADD_TEST_BEGIN(macroSuite, "宏");

    ADD_TEST_END(macroSuite);
}

void Physics::TestingHelper ::AddCollisionDetectionSuite()
{
    ADD_TEST_BEGIN(collisionDetectionSuite, "碰撞检测");

    ADD_TEST(collisionDetectionSuite, BoundTreeProjectionInfoTesting);
    ADD_TEST(collisionDetectionSuite, BoundTreeSplitTrianglesTesting);
    ADD_TEST(collisionDetectionSuite, BoundTreeChildTesting);
    ADD_TEST(collisionDetectionSuite, BoundTreeTesting);

    ADD_TEST_END(collisionDetectionSuite);
}

void Physics::TestingHelper ::AddFluidSuite()
{
    ADD_TEST_BEGIN(fluidSuite, "流体");

    ADD_TEST_END(fluidSuite);
}

void Physics::TestingHelper ::AddIntersectionSuite()
{
    ADD_TEST_BEGIN(intersectionSuite, "相交");

    ADD_TEST_END(intersectionSuite);
}

void Physics::TestingHelper ::AddLCPSolverSuite()
{
    ADD_TEST_BEGIN(lCPSolverSuite, "LCP求解");

    ADD_TEST_END(lCPSolverSuite);
}

void Physics::TestingHelper ::AddParticleSystemSuite()
{
    ADD_TEST_BEGIN(particleSystemSuite, "粒子系统");

    ADD_TEST_END(particleSystemSuite);
}

void Physics::TestingHelper ::AddRigidBodySuite()
{
    ADD_TEST_BEGIN(rigidBodySuite, "刚体");

    ADD_TEST_END(rigidBodySuite);
}

void Physics::TestingHelper ::AddMiscellaneousSuite()
{
    ADD_TEST_BEGIN(miscellaneousSuite, "杂项");

    ADD_TEST_END(miscellaneousSuite);
}
