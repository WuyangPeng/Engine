/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/23 22:22)

#include "CountryEntityTesting.h"
#include "DatabaseEntityTestingDetail.h"
#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/Country.h"
#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/CountryContainerDetail.h"
#include "DatabaseGenerate/DatabaseGenerateBase/DatabaseEntity/CountryEntity.h"
#include "DatabaseGenerate/DatabaseGenerateCore/Helper/DatabaseGenerateCoreClassInvariantMacro.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Database/DatabaseInterface/BasisDatabaseManager.h"
#include "Database/DatabaseInterface/DatabaseEnvironment.h"
#include "Database/DatabaseInterface/DatabaseFlush.h"

DatabaseGenerateBaseTesting::CountryEntityTesting::CountryEntityTesting(const OStreamShared& stream, CountryContainer countryContainer)
    : ParentType{ stream }, countryContainer{ std::move(countryContainer) }
{
    DATABASE_GENERATE_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateBaseTesting, CountryEntityTesting)

void DatabaseGenerateBaseTesting::CountryEntityTesting::SelectOneTest(DatabaseFlush& databaseFlush)
{
    auto index = 0;
    for (const auto& country : countryContainer.GetContainer())
    {
        ASSERT_NOT_THROW_EXCEPTION_2(DoSelectOneTest, databaseFlush, *country);

        ++index;
        if (index == GetTestLoopCount())
        {
            break;
        }
    }

    databaseFlush.Wait();
}

void DatabaseGenerateBaseTesting::CountryEntityTesting::SelectAllTest(DatabaseFlush& databaseFlush)
{
    const auto database = databaseFlush.SelectAll(CountryEntity::GetSelectAll(databaseFlush.GetWrappersStrategy()),
                                                  CountryEntity::GetDatabaseFieldContainer());

    const auto entityContainer = GetEntityContainer<int32_t, CountryEntity>(database);

    for (const auto& country : countryContainer.GetContainer())
    {
        ASSERT_NOT_THROW_EXCEPTION_3(DoSelectAllTest, databaseFlush, *country, entityContainer);
    }

    databaseFlush.Wait();
}

void DatabaseGenerateBaseTesting::CountryEntityTesting::SelectAllSizeTest(const DatabaseFlush& databaseFlush)
{
    const auto database = databaseFlush.SelectAll(CountryEntity::GetSelectAll(databaseFlush.GetWrappersStrategy()),
                                                  CountryEntity::GetDatabaseFieldContainer());

    ASSERT_EQUAL(boost::numeric_cast<int>(database.size()), countryContainer.GetContainerSize());

    const auto entityContainer = GetEntityContainer<int32_t, CountryEntity>(database);

    for (const auto& country : countryContainer.GetContainer())
    {
        ASSERT_NOT_THROW_EXCEPTION_2(EqualTest, *country, entityContainer);
    }
}

void DatabaseGenerateBaseTesting::CountryEntityTesting::SetEntity(CountryEntity& countryEntity, const Country& country)
{
    countryEntity.SetImperialCourt(country.GetImperialCourt());
    countryEntity.SetCategory(CoreTools::StringConversion::StandardConversionUtf8(country.GetCategory()));
    countryEntity.SetBeginYear(country.GetBeginYear());
    countryEntity.SetBeginMonth(country.GetBeginMonth());
    countryEntity.SetBeginSexagenaryCycle(country.GetBeginSexagenaryCycle());
    countryEntity.SetBeginDay(country.GetBeginDay());
    countryEntity.SetEndYear(country.GetEndYear());
    countryEntity.SetEndMonth(country.GetEndMonth());
    countryEntity.SetEndSexagenaryCycle(country.GetEndSexagenaryCycle());
    countryEntity.SetEndDay(country.GetEndDay());
    countryEntity.SetUnansweredQuestion(Convert(country.GetUnansweredQuestionBegin(), country.GetUnansweredQuestionEnd()));
}

void DatabaseGenerateBaseTesting::CountryEntityTesting::DoSelectOneTest(DatabaseFlush& databaseFlush, const Country& country)
{
    const auto database = databaseFlush.SelectOne(CountryEntity::GetSelect(databaseFlush.GetWrappersStrategy(), country.GetId()),
                                                  CountryEntity::GetDatabaseFieldContainer());

    auto countryEntity = CountryEntity::Create(database, databaseFlush.GetWrappersStrategy(), country.GetId());

    ASSERT_NOT_THROW_EXCEPTION_2(SetEntity, countryEntity, country);

    databaseFlush.ChangeDatabase(country.GetId(), countryEntity.GetModify());
}

void DatabaseGenerateBaseTesting::CountryEntityTesting::DoSelectAllTest(DatabaseFlush& databaseFlush, const Country& country, const EntityContainer& entityContainer)
{
    const auto result = entityContainer.find(country.GetId());
    auto countryEntity = result != entityContainer.cend() ? result->second : CountryEntity{ databaseFlush.GetWrappersStrategy(), country.GetId() };

    ASSERT_NOT_THROW_EXCEPTION_2(SetEntity, countryEntity, country);

    databaseFlush.ChangeDatabase(country.GetId(), countryEntity.GetModify());
}

void DatabaseGenerateBaseTesting::CountryEntityTesting::EqualTest(const Country& country, const EntityContainer& entityContainer)
{
    const auto result = entityContainer.find(country.GetId());

    ASSERT_UNEQUAL_FAILURE_THROW(result, entityContainer.cend(), "数据库中未找到对应数据。id = " + std::to_string(country.GetId()));

    const auto& countryEntity = result->second;

    ASSERT_EQUAL(countryEntity.GetImperialCourt(), country.GetImperialCourt());
    ASSERT_EQUAL(countryEntity.GetCategory(), CoreTools::StringConversion::StandardConversionUtf8(country.GetCategory()));
    ASSERT_EQUAL(countryEntity.GetBeginYear(), country.GetBeginYear());
    ASSERT_EQUAL(countryEntity.GetBeginMonth(), country.GetBeginMonth());
    ASSERT_EQUAL(countryEntity.GetBeginSexagenaryCycle(), country.GetBeginSexagenaryCycle());
    ASSERT_EQUAL(countryEntity.GetBeginDay(), country.GetBeginDay());
    ASSERT_EQUAL(countryEntity.GetEndYear(), country.GetEndYear());
    ASSERT_EQUAL(countryEntity.GetEndMonth(), country.GetEndMonth());
    ASSERT_EQUAL(countryEntity.GetEndSexagenaryCycle(), country.GetEndSexagenaryCycle());
    ASSERT_EQUAL(countryEntity.GetEndDay(), country.GetEndDay());
    ASSERT_EQUAL(countryEntity.GetUnansweredQuestion(), Convert(country.GetUnansweredQuestionBegin(), country.GetUnansweredQuestionEnd()));
}
