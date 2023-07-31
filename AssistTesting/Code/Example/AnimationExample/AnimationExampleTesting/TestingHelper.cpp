///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/31 18:29)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Helper/ClassInvariant/AnimationClassInvariantMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestSuite.h"

AnimationExample::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "动画例子" }
{
    InitSuite();

    ANIMATION_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(AnimationExample, TestingHelper)

// private
void AnimationExample::TestingHelper ::InitSuite() noexcept
{
}
