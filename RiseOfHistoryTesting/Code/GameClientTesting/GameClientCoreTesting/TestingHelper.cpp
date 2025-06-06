/// Copyright (c) 2010-2025
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.2.0 (2025/01/06 10:53)

#include "GameClient/GameClientCore/Helper/GameClientCoreClassInvariantMacro.h"
#include "Testing.h"
#include "TestingHelper.h"

GameClientTesting::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "游戏客户端核心单元测试" }
{
    InitSuite();

    GAME_CLIENT_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(GameClientTesting, TestingHelper)

void GameClientTesting::TestingHelper::InitSuite() noexcept
{
}