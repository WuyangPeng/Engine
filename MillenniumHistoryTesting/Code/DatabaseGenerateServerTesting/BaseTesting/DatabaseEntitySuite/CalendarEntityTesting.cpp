///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/26 22:14)

#include "CalendarEntityTesting.h"
#include "DatabaseEntityTestingDetail.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/Calendar.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/CalendarContainerDetail.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/DatabaseEntity/CalendarEntity.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerCore/Helper/DatabaseGenerateServerCoreClassInvariantMacro.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Database/Configuration/ConfigurationStrategy.h"
#include "Database/DatabaseInterface/BasisDatabaseManager.h"
#include "Database/DatabaseInterface/DatabaseEnvironment.h"
#include "Database/DatabaseInterface/DatabaseFlush.h"

DatabaseGenerateServerBaseTesting::CalendarEntityTesting::CalendarEntityTesting(const OStreamShared& stream, const CalendarContainer& calendarContainer)
    : ParentType{ stream }, calendarContainer{ calendarContainer }
{
    DATABASE_GENERATE_SERVER_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateServerBaseTesting, CalendarEntityTesting)

void DatabaseGenerateServerBaseTesting::CalendarEntityTesting::SelectOneTest(DatabaseFlush& databaseFlush)
{
    auto index = 0;
    for (const auto& calendar : calendarContainer.GetContainer())
    {
        ASSERT_NOT_THROW_EXCEPTION_2(DoSelectOneTest, databaseFlush, *calendar);

        ++index;
        if (index == GetTestLoopCount())
        {
            break;
        }
    }

    databaseFlush.Wait();
}

void DatabaseGenerateServerBaseTesting::CalendarEntityTesting::SelectAllTest(DatabaseFlush& databaseFlush)
{
    const auto database = databaseFlush.SelectAll(CalendarEntity::GetSelectAll(databaseFlush.GetWrappersStrategy()),
                                                  CalendarEntity::GetDatabaseFieldContainer());

    const auto entityContainer = GetEntityContainer<int32_t, CalendarEntity>(database);

    for (const auto& calendar : calendarContainer.GetContainer())
    {
        ASSERT_NOT_THROW_EXCEPTION_3(DoSelectAllTest, databaseFlush, *calendar, entityContainer);
    }

    databaseFlush.Wait();
}

void DatabaseGenerateServerBaseTesting::CalendarEntityTesting::SelectAllSizeTest(const DatabaseFlush& databaseFlush)
{
    const auto database = databaseFlush.SelectAll(CalendarEntity::GetSelectAll(databaseFlush.GetWrappersStrategy()),
                                                  CalendarEntity::GetDatabaseFieldContainer());

    ASSERT_EQUAL(boost::numeric_cast<int>(database.size()), calendarContainer.GetContainerSize());

    const auto entityContainer = GetEntityContainer<int32_t, CalendarEntity>(database);

    for (const auto& calendar : calendarContainer.GetContainer())
    {
        ASSERT_NOT_THROW_EXCEPTION_2(EqualTest, *calendar, entityContainer);
    }
}

void DatabaseGenerateServerBaseTesting::CalendarEntityTesting::SetEntity(CalendarEntity& calendarEntity, const Calendar& calendar)
{
    calendarEntity.SetName(CoreTools::StringConversion::StandardConversionUtf8(calendar.GetName()));
    calendarEntity.SetAlias(Convert(calendar.GetAliasBegin(), calendar.GetAliasEnd()));
    calendarEntity.SetSource(calendar.GetSource());
    calendarEntity.SetPublication(CoreTools::StringConversion::StandardConversionUtf8(calendar.GetPublication()));
    calendarEntity.SetCreator(calendar.GetCreator());
    calendarEntity.SetFormulate(calendar.GetFormulate());
    calendarEntity.SetCountry(calendar.GetCountry());
    calendarEntity.SetBegin(calendar.GetBegin());
    calendarEntity.SetEnd(calendar.GetEnd());
    calendarEntity.SetAgainBegin(calendar.GetAgainBegin());
    calendarEntity.SetAgainEnd(calendar.GetAgainEnd());
}

void DatabaseGenerateServerBaseTesting::CalendarEntityTesting::DoSelectOneTest(DatabaseFlush& databaseFlush, const Calendar& calendar)
{
    const auto database = databaseFlush.SelectOne(CalendarEntity::GetSelect(databaseFlush.GetWrappersStrategy(), calendar.GetId()),
                                                  CalendarEntity::GetDatabaseFieldContainer());

    auto calendarEntity = CalendarEntity::Create(database, databaseFlush.GetWrappersStrategy(), calendar.GetId());

    ASSERT_NOT_THROW_EXCEPTION_2(SetEntity, calendarEntity, calendar);

    databaseFlush.ChangeDatabase(calendar.GetId(), calendarEntity.GetModify());
}

void DatabaseGenerateServerBaseTesting::CalendarEntityTesting::DoSelectAllTest(DatabaseFlush& databaseFlush, const Calendar& calendar, const EntityContainer& entityContainer)
{
    const auto result = entityContainer.find(calendar.GetId());
    auto calendarEntity = result != entityContainer.cend() ? result->second : CalendarEntity{ databaseFlush.GetWrappersStrategy(), calendar.GetId() };

    ASSERT_NOT_THROW_EXCEPTION_2(SetEntity, calendarEntity, calendar);

    databaseFlush.ChangeDatabase(calendar.GetId(), calendarEntity.GetModify());
}

void DatabaseGenerateServerBaseTesting::CalendarEntityTesting::EqualTest(const Calendar& calendar, const EntityContainer& entityContainer)
{
    const auto result = entityContainer.find(calendar.GetId());

    ASSERT_UNEQUAL_FAILURE_THROW(result, entityContainer.cend(), "数据库中未找到对应数据。id = " + std::to_string(calendar.GetId()));

    const auto& calendarEntity = result->second;

    ASSERT_EQUAL(calendarEntity.GetName(), CoreTools::StringConversion::StandardConversionUtf8(calendar.GetName()));
    ASSERT_EQUAL(calendarEntity.GetAlias(), Convert(calendar.GetAliasBegin(), calendar.GetAliasEnd()));
    ASSERT_EQUAL(calendarEntity.GetSource(), calendar.GetSource());
    ASSERT_EQUAL(calendarEntity.GetPublication(), CoreTools::StringConversion::StandardConversionUtf8(calendar.GetPublication()));
    ASSERT_EQUAL(calendarEntity.GetCreator(), calendar.GetCreator());
    ASSERT_EQUAL(calendarEntity.GetFormulate(), calendar.GetFormulate());
    ASSERT_EQUAL(calendarEntity.GetCountry(), calendar.GetCountry());
    ASSERT_EQUAL(calendarEntity.GetBegin(), calendar.GetBegin());
    ASSERT_EQUAL(calendarEntity.GetEnd(), calendar.GetEnd());
    ASSERT_EQUAL(calendarEntity.GetAgainBegin(), calendar.GetAgainBegin());
    ASSERT_EQUAL(calendarEntity.GetAgainEnd(), calendar.GetAgainEnd());
}
