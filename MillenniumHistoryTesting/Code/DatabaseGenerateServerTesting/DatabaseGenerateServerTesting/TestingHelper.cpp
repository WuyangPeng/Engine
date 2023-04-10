///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	千年史策测试版本：0.9.0.5 (2023/04/03 13:38)

#include "DatabaseGenerateServer/DatabaseGenerateServerCore/Helper/DatabaseGenerateServerCoreClassInvariantMacro.h"
#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"

DatabaseGenerateServerTesting::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "数据库生成服务器测试" }
{
    InitSuite();

    DATABASE_GENERATE_SERVER_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateServerTesting, TestingHelper)

void DatabaseGenerateServerTesting::TestingHelper::InitSuite() noexcept
{
}
