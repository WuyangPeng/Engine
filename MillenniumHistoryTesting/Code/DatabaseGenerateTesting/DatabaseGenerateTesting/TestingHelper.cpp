/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/11/25 20:42)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelperDetail.h"

DatabaseGenerateTesting::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "数据库生成单元测试" }
{
    InitSuite();

    USER_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateTesting, TestingHelper)

void DatabaseGenerateTesting::TestingHelper::InitSuite()  
{
    AddDatabaseGenerateSuite();
}

void DatabaseGenerateTesting::TestingHelper::AddDatabaseGenerateSuite()
{
    auto databaseGenerateSuite = GenerateSuite("数据库生成");

    ADD_TEST(databaseGenerateSuite, DatabaseGenerateHelperTesting);
    ADD_TEST(databaseGenerateSuite, DatabaseGenerateMessageTesting);

    AddSuite(databaseGenerateSuite);
}
