///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/19 22:19)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelperDetail.h"

DatabaseGenerateServerCoreTesting::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "数据库生成服务器核心测试" }
{
    InitSuite();

    USER_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateServerCoreTesting, TestingHelper)

void DatabaseGenerateServerCoreTesting::TestingHelper::InitSuite()
{
    AddEngineSuite();
    // AddConvertSuite(ancientBooksContainer);
}

void DatabaseGenerateServerCoreTesting::TestingHelper::AddEngineSuite()
{
    auto engineSuite = GenerateSuite("引擎");

    AddSuite(engineSuite);
}

void DatabaseGenerateServerCoreTesting::TestingHelper::AddConvertSuite(const AncientBooksContainer& ancientBooksContainer)
{
    auto convertSuite = GenerateSuite("转换");

    ADD_TEST_USE_PARAMETER_1(convertSuite, ArticleConvertTesting, ancientBooksContainer);
    ADD_TEST_USE_PARAMETER_1(convertSuite, BookConvertTesting, ancientBooksContainer);
    ADD_TEST_USE_PARAMETER_1(convertSuite, CalendarConvertTesting, ancientBooksContainer);
    ADD_TEST_USE_PARAMETER_1(convertSuite, CategoryConvertTesting, ancientBooksContainer);
    ADD_TEST_USE_PARAMETER_1(convertSuite, CharacterConvertTesting, ancientBooksContainer);
    ADD_TEST_USE_PARAMETER_1(convertSuite, CountryConvertTesting, ancientBooksContainer);
    ADD_TEST_USE_PARAMETER_1(convertSuite, DayConvertTesting, ancientBooksContainer);
    ADD_TEST_USE_PARAMETER_1(convertSuite, EmperorConvertTesting, ancientBooksContainer);
    ADD_TEST_USE_PARAMETER_1(convertSuite, GatherConvertTesting, ancientBooksContainer);
    ADD_TEST_USE_PARAMETER_1(convertSuite, GenusConvertTesting, ancientBooksContainer);
    ADD_TEST_USE_PARAMETER_1(convertSuite, GeographicConvertTesting, ancientBooksContainer);
    ADD_TEST_USE_PARAMETER_1(convertSuite, IdentityConvertTesting, ancientBooksContainer);
    ADD_TEST_USE_PARAMETER_1(convertSuite, ImperialCourtConvertTesting, ancientBooksContainer);
    ADD_TEST_USE_PARAMETER_1(convertSuite, MonthConvertTesting, ancientBooksContainer);
    ADD_TEST_USE_PARAMETER_1(convertSuite, ReignTitleConvertTesting, ancientBooksContainer);
    ADD_TEST_USE_PARAMETER_1(convertSuite, SexagenaryCycleConvertTesting, ancientBooksContainer);
    ADD_TEST_USE_PARAMETER_1(convertSuite, SourceConvertTesting, ancientBooksContainer);
    ADD_TEST_USE_PARAMETER_1(convertSuite, VersionConvertTesting, ancientBooksContainer);
    ADD_TEST_USE_PARAMETER_1(convertSuite, YearConvertTesting, ancientBooksContainer);

    AddSuite(convertSuite);
}
