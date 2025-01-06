/// Copyright (c) 2010-2025
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.2.0 (2025/01/06 10:06)

#include "ServerManager/ServerManagerCore/Helper/ServerManagerCoreClassInvariantMacro.h"
#include "Testing.h"
#include "TestingHelper.h"

ServerManagerTesting::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "服务器管理者单元测试" }
{
    InitSuite();

    SERVER_MANAGER_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(ServerManagerTesting, TestingHelper)

void ServerManagerTesting::TestingHelper::InitSuite() noexcept
{
}