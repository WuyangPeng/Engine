///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎游戏测试版本：0.9.0.12 (2023/06/17 11:23)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"

Quest::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "任务" }
{
    InitSuite();

    USER_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Quest, TestingHelper)

void Quest::TestingHelper::InitSuite() noexcept
{
}
