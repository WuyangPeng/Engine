///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	ǧ��ʷ�߲��԰汾��0.9.0.12 (2023/06/14 20:20)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelperDetail.h"

using namespace std::literals;

DatabaseGenerateServerBaseTesting::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "���ݿ����ɷ��������ò���"s }
{
    InitSuite();

    USER_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateServerBaseTesting, TestingHelper)

void DatabaseGenerateServerBaseTesting::TestingHelper::InitSuite()
{
    AddAncientBooksSuite();
}

void DatabaseGenerateServerBaseTesting::TestingHelper::AddAncientBooksSuite()
{
    auto ancientBooksSuite = GenerateSuite("�ż�"s);

    ADD_TEST(ancientBooksSuite, AncientBooksContainerTesting);

    AddSuite(ancientBooksSuite);
}
