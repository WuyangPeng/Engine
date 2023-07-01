///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/19 22:19)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"

DatabaseGenerateServerCoreTesting::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "数据库生成服务器核心测试" }
{
    InitSuite();

    USER_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateServerCoreTesting, TestingHelper)

void DatabaseGenerateServerCoreTesting::TestingHelper::InitSuite()
{
    AddEngineSuite();
}

void DatabaseGenerateServerCoreTesting::TestingHelper::AddEngineSuite()
{
    auto engineSuite = GenerateSuite("引擎");

    AddSuite(engineSuite);
}
