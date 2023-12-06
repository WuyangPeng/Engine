/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/11/30 22:50)

#include "CalendarConvertTesting.h"
#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/Calendar.h"
#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/CalendarContainerDetail.h"
#include "DatabaseGenerate/DatabaseGenerateCore/Convert/ConvertEntity.h"
#include "DatabaseGenerate/DatabaseGenerateCore/Helper/DatabaseGenerateCoreClassInvariantMacro.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

DatabaseGenerateCoreTesting::CalendarConvertTesting::CalendarConvertTesting(const OStreamShared& stream, const CalendarContainer& calendarContainer)
    : ParentType{ stream }, calendarContainer{ calendarContainer }
{
    DATABASE_GENERATE_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateCoreTesting, CalendarConvertTesting)

void DatabaseGenerateCoreTesting::CalendarConvertTesting::ConvertTest(const DatabaseFlushSharedPtr& databaseFlush)
{
    DatabaseGenerateCore::ConvertEntity convertEntity{ databaseFlush };

    for (const auto& calendar : calendarContainer.GetContainer())
    {
        const auto calendarEntity = convertEntity.Convert(*calendar);

        ASSERT_NOT_THROW_EXCEPTION_2(EqualTest, *calendar, calendarEntity);
    }
}

void DatabaseGenerateCoreTesting::CalendarConvertTesting::EqualTest(const Calendar& calendar, const CalendarEntity& calendarEntity)
{
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
