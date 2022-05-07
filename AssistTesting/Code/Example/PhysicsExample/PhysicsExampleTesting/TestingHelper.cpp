// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎辅助测试版本：0.0.2.2 (2020/01/26 16:04)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestSuite.h"
#include "CoreTools/Helper/ClassInvariant/PhysicsClassInvariantMacro.h"

PhysicsExample::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "物理例子" }
{
    InitSuite();

    PHYSICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(PhysicsExample, TestingHelper)

// private
void PhysicsExample::TestingHelper ::InitSuite() noexcept
{
}
