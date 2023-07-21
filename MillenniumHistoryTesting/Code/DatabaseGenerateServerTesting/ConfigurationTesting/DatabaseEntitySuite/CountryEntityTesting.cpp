///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/24 12:17)

#include "CountryEntityTesting.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/Country.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/CountryContainerDetail.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/DatabaseEntity/CountryEntity.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerCore/Helper/DatabaseGenerateServerCoreClassInvariantMacro.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Database/Configuration/ConfigurationStrategy.h"
#include "Database/DatabaseInterface/BasisDatabaseManager.h"
#include "Database/DatabaseInterface/DatabaseEnvironment.h"
#include "Database/DatabaseInterface/DatabaseFlush.h"

DatabaseGenerateServerBaseTesting::CountryEntityTesting::CountryEntityTesting(const OStreamShared& stream, const AncientBooksContainer& ancientBooksContainer)
    : ParentType{ stream }, ancientBooksContainer{ ancientBooksContainer }
{
    DATABASE_GENERATE_SERVER_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateServerBaseTesting, CountryEntityTesting)

void DatabaseGenerateServerBaseTesting::CountryEntityTesting::DoRunUnitTest()
{
    Database::DatabaseEnvironment::Create();

    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);

    Database::DatabaseEnvironment::Destroy();
}

void DatabaseGenerateServerBaseTesting::CountryEntityTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(InitEnvironmentTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DatabaseFlushTest);
}

void DatabaseGenerateServerBaseTesting::CountryEntityTesting::InitEnvironmentTest()
{
    const Database::ConfigurationStrategy configurationStrategy{ Database::WrappersStrategy::Mongo, "127.0.0.1", 3306, "tcretest", "root", "123456" };

    DATABASE_ENVIRONMENT_SINGLETON.InitEnvironment(configurationStrategy);
}

void DatabaseGenerateServerBaseTesting::CountryEntityTesting::DatabaseFlushTest()
{
    const Database::ConfigurationStrategy::FlagsOption flagsOption{};
    const Database::ConfigurationStrategy::StringOption stringOption{};
    const Database::ConfigurationStrategy::BooleanOption booleanOption{};
    const Database::ConfigurationStrategy::IntOption intOption{};
    const Database::ConfigurationStrategy::SSLOption sslOption{};
    const Database::ConfigurationStrategy::DBMapping dbMapping{};

    const Database::ConfigurationStrategy configurationStrategy{ Database::WrappersStrategy::Mongo, "43.139.123.106", 27017, "tcretest", "dbOwner", "TCRE", true, 10, 1000, 500, 1, flagsOption, stringOption, booleanOption, intOption, sslOption, dbMapping };

    Database::DatabaseFlush mysqlConnectorDatabaseFlush{ configurationStrategy };

    const auto countryContainer = ancientBooksContainer.GetCountryContainer();

    for (const auto& country : countryContainer->GetContainer())
    {
        const auto database = mysqlConnectorDatabaseFlush.SelectOne(DatabaseEntity::CountryEntity::GetSelect(Database::WrappersStrategy::Mongo, country->GetId()),
                                                                    DatabaseEntity::CountryEntity::GetDatabaseFieldContainer());

        auto countryEntity = DatabaseEntity::CountryEntity::Create(database, Database::WrappersStrategy::Mongo, country->GetId());

        countryEntity.SetImperialCourt(country->GetImperialCourt());
        countryEntity.SetCategory(CoreTools::StringConversion::StandardConversionUtf8(country->GetCategory()));
        countryEntity.SetBeginYear(country->GetBeginYear());
        countryEntity.SetBeginMonth(country->GetBeginMonth());
        countryEntity.SetBeginSexagenaryCycle(country->GetBeginSexagenaryCycle());
        countryEntity.SetBeginDay(country->GetBeginDay());
        countryEntity.SetEndYear(country->GetEndYear());
        countryEntity.SetEndMonth(country->GetEndMonth());
        countryEntity.SetEndSexagenaryCycle(country->GetEndSexagenaryCycle());
        countryEntity.SetEndDay(country->GetEndDay());
        Database::Traits::StringArray unansweredQuestion{};
        for (auto iter = country->GetUnansweredQuestionBegin(); iter != country->GetUnansweredQuestionEnd(); ++iter)
        {
            unansweredQuestion.emplace_back(CoreTools::StringConversion::StandardConversionUtf8(*iter));
        }
        countryEntity.SetUnansweredQuestion(unansweredQuestion);

        mysqlConnectorDatabaseFlush.ChangeDatabase(0, countryEntity.GetModify());
    }
}