///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	最后的霸王测试版本：0.8.0.12 (2022/07/30 20:02)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"

GatewayServerTesting::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "网关服务器管理器测试" }
{
    InitSuite();

    USER_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(GatewayServerTesting, TestingHelper)

void GatewayServerTesting::TestingHelper::InitSuite() noexcept
{
}
