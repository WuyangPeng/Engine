///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/12 16:49)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Helper/ClassInvariant/PhysicsClassInvariantMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelperDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestSuite.h"

Physics::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "物理库" }
{
    InitSuite();

    PHYSICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Physics, TestingHelper)

// private
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
    auto helperSuite = GenerateSuite("帮助");

    AddSuite(helperSuite);
}

void Physics::TestingHelper::AddCollisionDetectionSuite()
{
    auto collisionDetectionSuite = GenerateSuite("碰撞检测");

    ADD_TEST(collisionDetectionSuite, BoundTreeProjectionInfoTesting);
    ADD_TEST(collisionDetectionSuite, BoundTreeSplitTrianglesTesting);
    ADD_TEST(collisionDetectionSuite, BoundTreeChildTesting);
    ADD_TEST(collisionDetectionSuite, BoundTreeTesting);

    AddSuite(collisionDetectionSuite);
}

void Physics::TestingHelper::AddFluidSuite()
{
    auto fluidSuite = GenerateSuite("流体");

    AddSuite(fluidSuite);
}

void Physics::TestingHelper::AddIntersectionSuite()
{
    auto intersectionSuite = GenerateSuite("相交");

    AddSuite(intersectionSuite);
}

void Physics::TestingHelper::AddLCPSolverSuite()
{
    auto lCPSolverSuite = GenerateSuite("LCP求解");

    AddSuite(lCPSolverSuite);
}

void Physics::TestingHelper::AddParticleSystemSuite()
{
    auto particleSystemSuite = GenerateSuite("粒子系统");

    AddSuite(particleSystemSuite);
}

void Physics::TestingHelper::AddRigidBodySuite()
{
    auto rigidBodySuite = GenerateSuite("刚体");

    AddSuite(rigidBodySuite);
}

void Physics::TestingHelper::AddMiscellaneousSuite()
{
    auto miscellaneousSuite = GenerateSuite("杂项");

    AddSuite(miscellaneousSuite);
}
