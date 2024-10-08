/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.1.0 (2024/06/20 15:52)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"

ServerManagerTesting::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "服务器管理者单元测试" }
{
    InitSuite();

    USER_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(ServerManagerTesting, TestingHelper)

void ServerManagerTesting::TestingHelper::InitSuite() noexcept
{
}