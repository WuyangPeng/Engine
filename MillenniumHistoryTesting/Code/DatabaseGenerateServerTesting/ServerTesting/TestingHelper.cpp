///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.0 (2023/06/19 22:04)

#include "DatabaseGenerateServer/DatabaseGenerateServerCore/Helper/DatabaseGenerateServerCoreClassInvariantMacro.h"
#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelperDetail.h"

DatabaseGenerateServerTesting::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "���ݿ����ɷ���������" }
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
    auto databaseGenerateServerSuite = GenerateSuite("���ݿ����ɷ�����");

    ADD_TEST(databaseGenerateServerSuite, DatabaseGenerateServerHelperTesting);
    ADD_TEST(databaseGenerateServerSuite, DatabaseGenerateServerMessageTesting);

    AddSuite(databaseGenerateServerSuite);
}
