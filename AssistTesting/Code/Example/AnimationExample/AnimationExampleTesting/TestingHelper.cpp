// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
//
// ÒıÇæ¸¨Öú²âÊÔ°æ±¾£º0.0.2.2 (2020/01/26 20:22)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Helper/ClassInvariant/AnimationClassInvariantMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestSuite.h"

AnimationExample::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "¶¯»­Àı×Ó" }
{
    InitSuite();

    ANIMATION_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(AnimationExample, TestingHelper)

// private
void AnimationExample::TestingHelper ::InitSuite() noexcept
{
}
