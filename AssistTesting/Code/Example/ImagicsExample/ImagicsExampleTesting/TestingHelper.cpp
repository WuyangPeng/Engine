// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
//
// ÒıÇæ¸¨Öú²âÊÔ°æ±¾£º0.0.2.2 (2020/01/26 19:17)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Helper/ClassInvariant/ImagicsClassInvariantMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestSuite.h"

ImagicsExample::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "Í¼Ïñ·ÖÎöÀı×Ó" }
{
    InitSuite();

    IMAGICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(ImagicsExample, TestingHelper)

// private
void ImagicsExample::TestingHelper ::InitSuite() noexcept
{
}
