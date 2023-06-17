///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	千年史策测试版本：0.9.0.12 (2023/06/14 20:20)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelperDetail.h"

using namespace std::literals;

DatabaseGenerateServerBaseTesting::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "数据库生成服务器配置测试"s }
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
    auto ancientBooksSuite = GenerateSuite("古籍"s);

    ADD_TEST(ancientBooksSuite, AncientBooksContainerTesting);

    AddSuite(ancientBooksSuite);
}
