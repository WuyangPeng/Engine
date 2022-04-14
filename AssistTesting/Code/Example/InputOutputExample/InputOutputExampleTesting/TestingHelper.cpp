// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
//
// ÒıÇæ¸¨Öú²âÊÔ°æ±¾£º0.0.2.2 (2020/01/25 22:55)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestSuite.h"
#include "CoreTools/Helper/ClassInvariant/InputOutputClassInvariantMacro.h"

using namespace std::literals;

InputOutputExample::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "ÊäÈëÊä³öÀı×Ó"s }
{
    InitSuite();

    INPUT_OUTPUT_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(InputOutputExample, TestingHelper)

void InputOutputExample::TestingHelper::InitSuite() noexcept

{
}
