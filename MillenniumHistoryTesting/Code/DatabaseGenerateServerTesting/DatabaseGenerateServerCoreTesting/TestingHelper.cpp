///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/07/31 22:02)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelperDetail.h"

DatabaseGenerateServerCoreTesting::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "���ݿ����ɷ��������Ĳ���" }
{
    InitSuite();

    USER_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateServerCoreTesting, TestingHelper)

void DatabaseGenerateServerCoreTesting::TestingHelper::InitSuite()
{
    const AncientBooksContainer ancientBooksContainer{ SYSTEM_TEXT("Resource/AncientBooksCsv") };

    AddConvertSuite(ancientBooksContainer);
}

void DatabaseGenerateServerCoreTesting::TestingHelper::AddConvertSuite(const AncientBooksContainer& ancientBooksContainer)
{
    auto convertSuite = GenerateSuite("ת��");

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
