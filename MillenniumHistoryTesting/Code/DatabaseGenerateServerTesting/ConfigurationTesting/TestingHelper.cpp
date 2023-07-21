///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/20 23:43)

#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/AncientBooksContainer.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerCore/Helper/DatabaseGenerateServerCoreClassInvariantMacro.h"
#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelperDetail.h"

DatabaseGenerateServerBaseTesting::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "数据库生成服务器配置测试" }
{
    InitSuite();

    DATABASE_GENERATE_SERVER_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateServerBaseTesting, TestingHelper)

void DatabaseGenerateServerBaseTesting::TestingHelper::InitSuite()
{
    AncientBooksContainer ancientBooksContainer{ SYSTEM_TEXT("Resource/AncientBooksCsv") };

    AddAncientBooksSuite(ancientBooksContainer);
    AddDatabaseEntitySuite(ancientBooksContainer);
}

void DatabaseGenerateServerBaseTesting::TestingHelper::AddAncientBooksSuite(const AncientBooksContainer& ancientBooksContainer)
{
    auto ancientBooksSuite = GenerateSuite("古籍");

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

void DatabaseGenerateServerBaseTesting::TestingHelper::AddDatabaseEntitySuite(const AncientBooksContainer& ancientBooksContainer)
{
    auto databaseEntitySuite = GenerateSuite("数据库实体");

    ADD_TEST_USE_PARAMETER_1(databaseEntitySuite, ArticleEntityTesting, ancientBooksContainer);
    ADD_TEST_USE_PARAMETER_1(databaseEntitySuite, BookEntityTesting, ancientBooksContainer);
    ADD_TEST_USE_PARAMETER_1(databaseEntitySuite, CalendarEntityTesting, ancientBooksContainer);
    ADD_TEST_USE_PARAMETER_1(databaseEntitySuite, CategoryEntityTesting, ancientBooksContainer);
    ADD_TEST_USE_PARAMETER_1(databaseEntitySuite, CharacterEntityTesting, ancientBooksContainer);
    ADD_TEST_USE_PARAMETER_1(databaseEntitySuite, CountryEntityTesting, ancientBooksContainer);
    ADD_TEST_USE_PARAMETER_1(databaseEntitySuite, DayEntityTesting, ancientBooksContainer);
    ADD_TEST_USE_PARAMETER_1(databaseEntitySuite, EmperorEntityTesting, ancientBooksContainer);
    ADD_TEST_USE_PARAMETER_1(databaseEntitySuite, GatherEntityTesting, ancientBooksContainer);
    ADD_TEST_USE_PARAMETER_1(databaseEntitySuite, GenusEntityTesting, ancientBooksContainer);
    ADD_TEST_USE_PARAMETER_1(databaseEntitySuite, GeographicEntityTesting, ancientBooksContainer);
    ADD_TEST_USE_PARAMETER_1(databaseEntitySuite, IdentityEntityTesting, ancientBooksContainer);
    ADD_TEST_USE_PARAMETER_1(databaseEntitySuite, ImperialCourtEntityTesting, ancientBooksContainer);
    ADD_TEST_USE_PARAMETER_1(databaseEntitySuite, MonthEntityTesting, ancientBooksContainer);
    ADD_TEST_USE_PARAMETER_1(databaseEntitySuite, ReignTitleEntityTesting, ancientBooksContainer);
    ADD_TEST_USE_PARAMETER_1(databaseEntitySuite, SexagenaryCycleEntityTesting, ancientBooksContainer);
    ADD_TEST_USE_PARAMETER_1(databaseEntitySuite, SourceEntityTesting, ancientBooksContainer);
    ADD_TEST_USE_PARAMETER_1(databaseEntitySuite, VersionEntityTesting, ancientBooksContainer);
    ADD_TEST_USE_PARAMETER_1(databaseEntitySuite, YearEntityTesting, ancientBooksContainer);

    AddSuite(databaseEntitySuite);
}
