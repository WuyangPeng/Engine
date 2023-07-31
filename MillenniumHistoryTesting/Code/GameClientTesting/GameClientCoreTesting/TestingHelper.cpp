///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/25 21:22)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"

GameClientTesting::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "游戏客户端核心测试" }
{
    InitSuite();

    USER_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(GameClientTesting, TestingHelper)

void GameClientTesting::TestingHelper::InitSuite() noexcept
{
}
