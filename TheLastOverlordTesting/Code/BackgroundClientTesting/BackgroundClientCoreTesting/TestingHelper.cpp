// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 最后的霸王测试版本：0.0.0.0 (2019/10/10 17:53)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"

BackgroundClientTesting::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "后台客户端核心测试" }
{
    InitSuite();

    USER_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BackgroundClientTesting, TestingHelper)

void BackgroundClientTesting::TestingHelper::InitSuite() noexcept
{
}
