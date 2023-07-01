///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/19 22:04)

#include "DatabaseGenerateServer/DatabaseGenerateServerCore/Helper/DatabaseGenerateServerCoreClassInvariantMacro.h"
#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelperDetail.h"

DatabaseGenerateServerTesting::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "数据库生成服务器测试" }
{
    InitSuite();

    DATABASE_GENERATE_SERVER_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateServerTesting, TestingHelper)

void DatabaseGenerateServerTesting::TestingHelper::InitSuite()
{
    AddDatabaseGenerateServerSuite();
}

void DatabaseGenerateServerTesting::TestingHelper::AddDatabaseGenerateServerSuite()
{
    auto databaseGenerateServerSuite = GenerateSuite("数据库生成服务器");

    ADD_TEST(databaseGenerateServerSuite, DatabaseGenerateServerHelperTesting);
    ADD_TEST(databaseGenerateServerSuite, DatabaseGenerateServerMessageTesting);

    AddSuite(databaseGenerateServerSuite);
}
