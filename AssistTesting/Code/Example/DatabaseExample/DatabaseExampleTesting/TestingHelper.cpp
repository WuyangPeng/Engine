// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
//
// ÒıÇæ¸¨Öú²âÊÔ°æ±¾£º0.0.2.2 (2020/01/24 0:19)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestSuite.h"

using namespace std::literals;

DatabaseExample::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "Êı¾İ¿âÀı×Ó"s }
{
    InitSuite();

    DATABASE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseExample, TestingHelper)

// private
void DatabaseExample::TestingHelper ::InitSuite() noexcept
{
}
