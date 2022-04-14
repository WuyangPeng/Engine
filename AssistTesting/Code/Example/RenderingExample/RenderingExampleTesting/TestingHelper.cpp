// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
//
// ÒıÇæ¸¨Öú²âÊÔ°æ±¾£º0.0.2.2 (2020/01/26 16:04)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestSuite.h"

using namespace std::literals;

RenderingExample::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "äÖÈ¾Àı×Ó"s }
{
    InitSuite();

    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(RenderingExample, TestingHelper)

void RenderingExample::TestingHelper::InitSuite() noexcept
{
}
