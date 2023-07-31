///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/28 23:19)

#include "DatabaseEntityTestingDetail.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/Year.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/YearContainerDetail.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/DatabaseEntity/YearEntity.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerCore/Helper/DatabaseGenerateServerCoreClassInvariantMacro.h"
#include "YearEntityTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Database/Configuration/ConfigurationStrategy.h"
#include "Database/DatabaseInterface/BasisDatabaseManager.h"
#include "Database/DatabaseInterface/DatabaseEnvironment.h"
#include "Database/DatabaseInterface/DatabaseFlush.h"

DatabaseGenerateServerBaseTesting::YearEntityTesting::YearEntityTesting(const OStreamShared& stream, const YearContainer& yearContainer)
    : ParentType{ stream }, yearContainer{ yearContainer }
{
    DATABASE_GENERATE_SERVER_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateServerBaseTesting, YearEntityTesting)

void DatabaseGenerateServerBaseTesting::YearEntityTesting::SelectOneTest(DatabaseFlush& databaseFlush)
{
    auto index = 0;
    for (const auto& year : yearContainer.GetContainer())
    {
        ASSERT_NOT_THROW_EXCEPTION_2(DoSelectOneTest, databaseFlush, *year);

        ++index;
        if (index == GetTestLoopCount())
        {
            break;
        }
    }

    databaseFlush.Wait();
}

void DatabaseGenerateServerBaseTesting::YearEntityTesting::SelectAllTest(DatabaseFlush& databaseFlush)
{
    const auto database = databaseFlush.SelectAll(YearEntity::GetSelectAll(databaseFlush.GetWrappersStrategy()),
                                                  YearEntity::GetDatabaseFieldContainer());

    const auto entityContainer = GetEntityContainer<int32_t, YearEntity>(database);

    for (const auto& year : yearContainer.GetContainer())
    {
        ASSERT_NOT_THROW_EXCEPTION_3(DoSelectAllTest, databaseFlush, *year, entityContainer);
    }

    databaseFlush.Wait();
}

void DatabaseGenerateServerBaseTesting::YearEntityTesting::SelectAllSizeTest(const DatabaseFlush& databaseFlush)
{
    const auto database = databaseFlush.SelectAll(YearEntity::GetSelectAll(databaseFlush.GetWrappersStrategy()),
                                                  YearEntity::GetDatabaseFieldContainer());

    ASSERT_EQUAL(boost::numeric_cast<int>(database.size()), yearContainer.GetContainerSize());

    const auto entityContainer = GetEntityContainer<int32_t, YearEntity>(database);

    for (const auto& year : yearContainer.GetContainer())
    {
        ASSERT_NOT_THROW_EXCEPTION_2(EqualTest, *year, entityContainer);
    }
}

void DatabaseGenerateServerBaseTesting::YearEntityTesting::SetEntity(YearEntity& yearEntity, const Year& year)
{
    yearEntity.SetName(CoreTools::StringConversion::StandardConversionUtf8(year.GetName()));
    yearEntity.SetSexagenaryCycle(year.GetSexagenaryCycle());
    yearEntity.SetReignTitle(year.GetReignTitle());
    yearEntity.SetYear(year.GetYear());
    yearEntity.SetUnorthodoxReignTitle(year.GetUnorthodoxReignTitle());
    yearEntity.SetUnorthodoxYear(year.GetUnorthodoxYear());
}

void DatabaseGenerateServerBaseTesting::YearEntityTesting::DoSelectOneTest(DatabaseFlush& databaseFlush, const Year& year)
{
    const auto database = databaseFlush.SelectOne(YearEntity::GetSelect(databaseFlush.GetWrappersStrategy(), year.GetId()),
                                                  YearEntity::GetDatabaseFieldContainer());

    auto yearEntity = YearEntity::Create(database, databaseFlush.GetWrappersStrategy(), year.GetId());

    ASSERT_NOT_THROW_EXCEPTION_2(SetEntity, yearEntity, year);

    databaseFlush.ChangeDatabase(year.GetId(), yearEntity.GetModify());
}

void DatabaseGenerateServerBaseTesting::YearEntityTesting::DoSelectAllTest(DatabaseFlush& databaseFlush, const Year& year, const EntityContainer& entityContainer)
{
    const auto result = entityContainer.find(year.GetId());
    auto yearEntity = result != entityContainer.cend() ? result->second : YearEntity{ databaseFlush.GetWrappersStrategy(), year.GetId() };

    ASSERT_NOT_THROW_EXCEPTION_2(SetEntity, yearEntity, year);

    databaseFlush.ChangeDatabase(year.GetId(), yearEntity.GetModify());
}

void DatabaseGenerateServerBaseTesting::YearEntityTesting::EqualTest(const Year& year, const EntityContainer& entityContainer)
{
    const auto result = entityContainer.find(year.GetId());

    ASSERT_UNEQUAL_FAILURE_THROW(result, entityContainer.cend(), "数据库中未找到对应数据。id = " + std::to_string(year.GetId()));

    const auto& yearEntity = result->second;

    ASSERT_EQUAL(yearEntity.GetName(), CoreTools::StringConversion::StandardConversionUtf8(year.GetName()));
    ASSERT_EQUAL(yearEntity.GetSexagenaryCycle(), year.GetSexagenaryCycle());
    ASSERT_EQUAL(yearEntity.GetReignTitle(), year.GetReignTitle());
    ASSERT_EQUAL(yearEntity.GetYear(), year.GetYear());
    ASSERT_EQUAL(yearEntity.GetUnorthodoxReignTitle(), year.GetUnorthodoxReignTitle());
    ASSERT_EQUAL(yearEntity.GetUnorthodoxYear(), year.GetUnorthodoxYear());
}
