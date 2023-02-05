///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	历史的崛起测试版本：0.8.1.0 (2022/08/03 12:57)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"

GameClientTesting::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "游戏客户端管理器测试" }
{
    InitSuite();

    USER_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(GameClientTesting, TestingHelper)

void GameClientTesting::TestingHelper::InitSuite() noexcept
{
}
