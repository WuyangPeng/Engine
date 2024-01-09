/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.3 (2023/12/25 23:45)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelperDetail.h"

DatabaseGenerateTesting::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "���ݿ����ɵ�Ԫ����" }
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
    auto databaseGenerateSuite = GenerateSuite("���ݿ�����");

    ADD_TEST(databaseGenerateSuite, DatabaseGenerateHelperTesting);
    ADD_TEST(databaseGenerateSuite, DatabaseGenerateMessageTesting);

    AddSuite(databaseGenerateSuite);
}
