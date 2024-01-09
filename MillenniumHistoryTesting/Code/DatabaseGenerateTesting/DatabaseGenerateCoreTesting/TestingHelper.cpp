/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/25 22:14)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelperDetail.h"

DatabaseGenerateCoreTesting::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "数据库生成核心单元测试" }
{
    InitSuite();

    USER_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateCoreTesting, TestingHelper)

void DatabaseGenerateCoreTesting::TestingHelper::InitSuite()
{
    const AncientBooksContainer ancientBooksContainer{ SYSTEM_TEXT("Resource/AncientBooksCsv") };

    AddHelperSuite();
    AddConvertSuite(ancientBooksContainer);
}

void DatabaseGenerateCoreTesting::TestingHelper::AddHelperSuite()
{
    auto helperSuite = GenerateSuite("帮助");

    AddSuite(helperSuite);
}

void DatabaseGenerateCoreTesting::TestingHelper::AddConvertSuite(const AncientBooksContainer& ancientBooksContainer)
{
    auto convertSuite = GenerateSuite("转换");

    ADD_TEST_USE_PARAMETER_1(convertSuite, ArticleConvertTesting, *ancientBooksContainer.GetArticleContainer());
    ADD_TEST_USE_PARAMETER_1(convertSuite, BookConvertTesting, *ancientBooksContainer.GetBookContainer());
    ADD_TEST_USE_PARAMETER_1(convertSuite, CalendarConvertTesting, *ancientBooksContainer.GetCalendarContainer());
    ADD_TEST_USE_PARAMETER_1(convertSuite, CategoryConvertTesting, *ancientBooksContainer.GetCategoryContainer());
    ADD_TEST_USE_PARAMETER_1(convertSuite, CharacterConvertTesting, *ancientBooksContainer.GetCharacterContainer());
    ADD_TEST_USE_PARAMETER_1(convertSuite, CountryConvertTesting, *ancientBooksContainer.GetCountryContainer());
    ADD_TEST_USE_PARAMETER_1(convertSuite, DayConvertTesting, *ancientBooksContainer.GetDayContainer());
    ADD_TEST_USE_PARAMETER_1(convertSuite, EmperorConvertTesting, *ancientBooksContainer.GetEmperorContainer());
    ADD_TEST_USE_PARAMETER_1(convertSuite, GatherConvertTesting, *ancientBooksContainer.GetGatherContainer());
    ADD_TEST_USE_PARAMETER_1(convertSuite, GenusConvertTesting, *ancientBooksContainer.GetGenusContainer());
    ADD_TEST_USE_PARAMETER_1(convertSuite, GeographicConvertTesting, *ancientBooksContainer.GetGeographicContainer());
    ADD_TEST_USE_PARAMETER_1(convertSuite, IdentityConvertTesting, *ancientBooksContainer.GetIdentityContainer());
    ADD_TEST_USE_PARAMETER_1(convertSuite, ImperialCourtConvertTesting, *ancientBooksContainer.GetImperialCourtContainer());
    ADD_TEST_USE_PARAMETER_1(convertSuite, MonthConvertTesting, *ancientBooksContainer.GetMonthContainer());
    ADD_TEST_USE_PARAMETER_1(convertSuite, ReignTitleConvertTesting, *ancientBooksContainer.GetReignTitleContainer());
    ADD_TEST_USE_PARAMETER_1(convertSuite, SexagenaryCycleConvertTesting, *ancientBooksContainer.GetSexagenaryCycleContainer());
    ADD_TEST_USE_PARAMETER_1(convertSuite, SourceConvertTesting, *ancientBooksContainer.GetSourceContainer());
    ADD_TEST_USE_PARAMETER_1(convertSuite, VersionConvertTesting, *ancientBooksContainer.GetVersionContainer());
    ADD_TEST_USE_PARAMETER_1(convertSuite, YearConvertTesting, *ancientBooksContainer.GetYearContainer());
    ADD_TEST_USE_PARAMETER_1(convertSuite, DeleteInvalidDatabaseTesting, ancientBooksContainer);
    ADD_TEST_USE_PARAMETER_1(convertSuite, AncientBooksDatabaseSaveTesting, ancientBooksContainer);

    AddSuite(convertSuite);
}
