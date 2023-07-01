///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/24 12:16)

#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/AncientBooksContainer.h"
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

    AncientBooks::AncientBooksContainer ancientBooksContainer{ SYSTEM_TEXT("Resource/AncientBooksCsv") };

    ADD_TEST_USE_PARAMETER_1(ancientBooksSuite, AncientBooksContainerTesting, ancientBooksContainer);
    ADD_TEST_USE_PARAMETER_1(ancientBooksSuite, ArticleTesting, ancientBooksContainer);
    ADD_TEST_USE_PARAMETER_1(ancientBooksSuite, BookTesting, ancientBooksContainer);
    ADD_TEST_USE_PARAMETER_1(ancientBooksSuite, CalendarTesting, ancientBooksContainer);
    ADD_TEST_USE_PARAMETER_1(ancientBooksSuite, CategoryTesting, ancientBooksContainer);
    ADD_TEST_USE_PARAMETER_1(ancientBooksSuite, CharacterTesting, ancientBooksContainer);
    ADD_TEST_USE_PARAMETER_1(ancientBooksSuite, CountryTesting, ancientBooksContainer);
    ADD_TEST_USE_PARAMETER_1(ancientBooksSuite, DayTesting, ancientBooksContainer);
    ADD_TEST_USE_PARAMETER_1(ancientBooksSuite, EmperorTesting, ancientBooksContainer);
    ADD_TEST_USE_PARAMETER_1(ancientBooksSuite, GatherTesting, ancientBooksContainer);
    ADD_TEST_USE_PARAMETER_1(ancientBooksSuite, GenusTesting, ancientBooksContainer);
    ADD_TEST_USE_PARAMETER_1(ancientBooksSuite, GeographicTesting, ancientBooksContainer);
    ADD_TEST_USE_PARAMETER_1(ancientBooksSuite, IdentityTesting, ancientBooksContainer);
    ADD_TEST_USE_PARAMETER_1(ancientBooksSuite, ImperialCourtTesting, ancientBooksContainer);
    ADD_TEST_USE_PARAMETER_1(ancientBooksSuite, MonthTesting, ancientBooksContainer);
    ADD_TEST_USE_PARAMETER_1(ancientBooksSuite, ReignTitleTesting, ancientBooksContainer);
    ADD_TEST_USE_PARAMETER_1(ancientBooksSuite, SexagenaryCycleTesting, ancientBooksContainer);
    ADD_TEST_USE_PARAMETER_1(ancientBooksSuite, SourceTesting, ancientBooksContainer);
    ADD_TEST_USE_PARAMETER_1(ancientBooksSuite, VersionTesting, ancientBooksContainer);
    ADD_TEST_USE_PARAMETER_1(ancientBooksSuite, YearTesting, ancientBooksContainer);

    AddSuite(ancientBooksSuite);
}
