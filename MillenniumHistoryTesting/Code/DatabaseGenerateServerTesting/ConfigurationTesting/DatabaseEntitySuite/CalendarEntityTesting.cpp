///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/27 22:45)

#include "CalendarEntityTesting.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/Calendar.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/CalendarContainerDetail.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/DatabaseEntity/CalendarEntity.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerCore/Helper/DatabaseGenerateServerCoreClassInvariantMacro.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Database/Configuration/ConfigurationStrategy.h"
#include "Database/DatabaseInterface/BasisDatabaseManager.h"
#include "Database/DatabaseInterface/DatabaseEnvironment.h"
#include "Database/DatabaseInterface/DatabaseFlush.h"

DatabaseGenerateServerBaseTesting::CalendarEntityTesting::CalendarEntityTesting(const OStreamShared& stream, const AncientBooksContainer& ancientBooksContainer)
    : ParentType{ stream }, ancientBooksContainer{ ancientBooksContainer }
{
    DATABASE_GENERATE_SERVER_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateServerBaseTesting, CalendarEntityTesting)

void DatabaseGenerateServerBaseTesting::CalendarEntityTesting::DoRunUnitTest()
{
    Database::DatabaseEnvironment::Create();

    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);

    Database::DatabaseEnvironment::Destroy();
}

void DatabaseGenerateServerBaseTesting::CalendarEntityTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(InitEnvironmentTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DatabaseFlushTest);
}

void DatabaseGenerateServerBaseTesting::CalendarEntityTesting::InitEnvironmentTest()
{
    const Database::ConfigurationStrategy configurationStrategy{ Database::WrappersStrategy::Mongo, "127.0.0.1", 3306, "tcretest", "root", "123456" };

    DATABASE_ENVIRONMENT_SINGLETON.InitEnvironment(configurationStrategy);
}

void DatabaseGenerateServerBaseTesting::CalendarEntityTesting::DatabaseFlushTest()
{
    const Database::ConfigurationStrategy::FlagsOption flagsOption{};
    const Database::ConfigurationStrategy::StringOption stringOption{};
    const Database::ConfigurationStrategy::BooleanOption booleanOption{};
    const Database::ConfigurationStrategy::IntOption intOption{};
    const Database::ConfigurationStrategy::SSLOption sslOption{};
    const Database::ConfigurationStrategy::DBMapping dbMapping{};

    const Database::ConfigurationStrategy configurationStrategy{ Database::WrappersStrategy::Mongo, "43.139.123.106", 27017, "tcretest", "dbOwner", "TCRE", true, 10, 1000, 500, 1, flagsOption, stringOption, booleanOption, intOption, sslOption, dbMapping };

    Database::DatabaseFlush mysqlConnectorDatabaseFlush{ configurationStrategy };

    const auto calendarContainer = ancientBooksContainer.GetCalendarContainer();

    for (const auto& calendar : calendarContainer->GetContainer())
    {
        const auto database = mysqlConnectorDatabaseFlush.SelectOne(DatabaseEntity::CalendarEntity::GetSelect(Database::WrappersStrategy::Mongo, calendar->GetId()),
                                                                    DatabaseEntity::CalendarEntity::GetDatabaseFieldContainer());

        auto calendarEntity = DatabaseEntity::CalendarEntity::Create(database, Database::WrappersStrategy::Mongo, calendar->GetId());

        calendarEntity.SetName(CoreTools::StringConversion::StandardConversionUtf8(calendar->GetName()));
        Database::Traits::StringArray alias{};
        for (auto iter = calendar->GetAliasBegin(); iter != calendar->GetAliasEnd(); ++iter)
        {
            alias.emplace_back(CoreTools::StringConversion::StandardConversionUtf8(*iter));
        }
        calendarEntity.SetAlias(alias);
        calendarEntity.SetSource(calendar->GetSource());
        calendarEntity.SetPublication(CoreTools::StringConversion::StandardConversionUtf8(calendar->GetPublication()));
        calendarEntity.SetCreator(calendar->GetCreator());
        calendarEntity.SetFormulate(calendar->GetFormulate());
        calendarEntity.SetCountry(calendar->GetCountry());
        calendarEntity.SetBegin(calendar->GetBegin());
        calendarEntity.SetEnd(calendar->GetEnd());
        calendarEntity.SetAgainBegin(calendar->GetAgainBegin());
        calendarEntity.SetAgainEnd(calendar->GetAgainEnd());

        mysqlConnectorDatabaseFlush.ChangeDatabase(0, calendarEntity.GetModify());
    }
}
