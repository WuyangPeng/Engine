///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/31 18:13)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Helper/ClassInvariant/PhysicsClassInvariantMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestSuite.h"

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
