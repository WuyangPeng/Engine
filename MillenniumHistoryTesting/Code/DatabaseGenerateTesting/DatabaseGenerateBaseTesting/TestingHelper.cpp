/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/22 23:07)

#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/AncientBooksContainer.h"
#include "DatabaseGenerate/DatabaseGenerateCore/Helper/DatabaseGenerateCoreClassInvariantMacro.h"
#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelperDetail.h"

DatabaseGenerateBaseTesting::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "数据库生成基础单元测试" }
{
    InitSuite();

    DATABASE_GENERATE_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateBaseTesting, TestingHelper)

void DatabaseGenerateBaseTesting::TestingHelper::InitSuite()
{
    const AncientBooksContainer ancientBooksContainer{ SYSTEM_TEXT("Resource/AncientBooksCsv") };

    AddAncientBooksSuite(ancientBooksContainer);
    AddDatabaseEntitySuite(ancientBooksContainer);
}

void DatabaseGenerateBaseTesting::TestingHelper::AddAncientBooksSuite(const AncientBooksContainer& ancientBooksContainer)
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

void DatabaseGenerateBaseTesting::TestingHelper::AddDatabaseEntitySuite(const AncientBooksContainer& ancientBooksContainer)
{
    auto databaseEntitySuite = GenerateSuite("数据库实体");

    ADD_TEST_USE_PARAMETER_1(databaseEntitySuite, ArticleEntityTesting, *ancientBooksContainer.GetArticleContainer());
    ADD_TEST_USE_PARAMETER_1(databaseEntitySuite, BookEntityTesting, *ancientBooksContainer.GetBookContainer());
    ADD_TEST_USE_PARAMETER_1(databaseEntitySuite, CalendarEntityTesting, *ancientBooksContainer.GetCalendarContainer());
    ADD_TEST_USE_PARAMETER_1(databaseEntitySuite, CategoryEntityTesting, *ancientBooksContainer.GetCategoryContainer());
    ADD_TEST_USE_PARAMETER_1(databaseEntitySuite, CharacterEntityTesting, *ancientBooksContainer.GetCharacterContainer());
    ADD_TEST_USE_PARAMETER_1(databaseEntitySuite, CountryEntityTesting, *ancientBooksContainer.GetCountryContainer());
    ADD_TEST_USE_PARAMETER_1(databaseEntitySuite, DayEntityTesting, *ancientBooksContainer.GetDayContainer());
    ADD_TEST_USE_PARAMETER_1(databaseEntitySuite, EmperorEntityTesting, *ancientBooksContainer.GetEmperorContainer());
    ADD_TEST_USE_PARAMETER_1(databaseEntitySuite, GatherEntityTesting, *ancientBooksContainer.GetGatherContainer());
    ADD_TEST_USE_PARAMETER_1(databaseEntitySuite, GenusEntityTesting, *ancientBooksContainer.GetGenusContainer());
    ADD_TEST_USE_PARAMETER_1(databaseEntitySuite, GeographicEntityTesting, *ancientBooksContainer.GetGeographicContainer());
    ADD_TEST_USE_PARAMETER_1(databaseEntitySuite, IdentityEntityTesting, *ancientBooksContainer.GetIdentityContainer());
    ADD_TEST_USE_PARAMETER_1(databaseEntitySuite, ImperialCourtEntityTesting, *ancientBooksContainer.GetImperialCourtContainer());
    ADD_TEST_USE_PARAMETER_1(databaseEntitySuite, MonthEntityTesting, *ancientBooksContainer.GetMonthContainer());
    ADD_TEST_USE_PARAMETER_1(databaseEntitySuite, ReignTitleEntityTesting, *ancientBooksContainer.GetReignTitleContainer());
    ADD_TEST_USE_PARAMETER_1(databaseEntitySuite, SexagenaryCycleEntityTesting, *ancientBooksContainer.GetSexagenaryCycleContainer());
    ADD_TEST_USE_PARAMETER_1(databaseEntitySuite, SourceEntityTesting, *ancientBooksContainer.GetSourceContainer());
    ADD_TEST_USE_PARAMETER_1(databaseEntitySuite, VersionEntityTesting, *ancientBooksContainer.GetVersionContainer());
    ADD_TEST_USE_PARAMETER_1(databaseEntitySuite, YearEntityTesting, *ancientBooksContainer.GetYearContainer());

    AddSuite(databaseEntitySuite);
}
