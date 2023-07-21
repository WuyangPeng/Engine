///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/24 12:17)

#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/ReignTitle.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/ReignTitleContainerDetail.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/DatabaseEntity/ReignTitleEntity.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerCore/Helper/DatabaseGenerateServerCoreClassInvariantMacro.h"
#include "ReignTitleEntityTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Database/Configuration/ConfigurationStrategy.h"
#include "Database/DatabaseInterface/BasisDatabaseManager.h"
#include "Database/DatabaseInterface/DatabaseEnvironment.h"
#include "Database/DatabaseInterface/DatabaseFlush.h"

DatabaseGenerateServerBaseTesting::ReignTitleEntityTesting::ReignTitleEntityTesting(const OStreamShared& stream, const AncientBooksContainer& ancientBooksContainer)
    : ParentType{ stream }, ancientBooksContainer{ ancientBooksContainer }
{
    DATABASE_GENERATE_SERVER_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateServerBaseTesting, ReignTitleEntityTesting)

void DatabaseGenerateServerBaseTesting::ReignTitleEntityTesting::DoRunUnitTest()
{
    Database::DatabaseEnvironment::Create();

    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);

    Database::DatabaseEnvironment::Destroy();
}

void DatabaseGenerateServerBaseTesting::ReignTitleEntityTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(InitEnvironmentTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DatabaseFlushTest);
}

void DatabaseGenerateServerBaseTesting::ReignTitleEntityTesting::InitEnvironmentTest()
{
    const Database::ConfigurationStrategy configurationStrategy{ Database::WrappersStrategy::Mongo, "127.0.0.1", 3306, "tcretest", "root", "123456" };

    DATABASE_ENVIRONMENT_SINGLETON.InitEnvironment(configurationStrategy);
}

void DatabaseGenerateServerBaseTesting::ReignTitleEntityTesting::DatabaseFlushTest()
{
    const Database::ConfigurationStrategy::FlagsOption flagsOption{};
    const Database::ConfigurationStrategy::StringOption stringOption{};
    const Database::ConfigurationStrategy::BooleanOption booleanOption{};
    const Database::ConfigurationStrategy::IntOption intOption{};
    const Database::ConfigurationStrategy::SSLOption sslOption{};
    const Database::ConfigurationStrategy::DBMapping dbMapping{};

    const Database::ConfigurationStrategy configurationStrategy{ Database::WrappersStrategy::Mongo, "43.139.123.106", 27017, "tcretest", "dbOwner", "TCRE", true, 10, 1000, 500, 1, flagsOption, stringOption, booleanOption, intOption, sslOption, dbMapping };

    Database::DatabaseFlush mysqlConnectorDatabaseFlush{ configurationStrategy };

    const auto reignTitleContainer = ancientBooksContainer.GetReignTitleContainer();

    for (const auto& reignTitle : reignTitleContainer->GetContainer())
    {
        const auto database = mysqlConnectorDatabaseFlush.SelectOne(DatabaseEntity::ReignTitleEntity::GetSelect(Database::WrappersStrategy::Mongo, reignTitle->GetId()),
                                                                    DatabaseEntity::ReignTitleEntity::GetDatabaseFieldContainer());

        auto reignTitleEntity = DatabaseEntity::ReignTitleEntity::Create(database, Database::WrappersStrategy::Mongo, reignTitle->GetId());

        reignTitleEntity.SetName(CoreTools::StringConversion::StandardConversionUtf8(reignTitle->GetName()));
        reignTitleEntity.SetEmperor(reignTitle->GetEmperor());
        reignTitleEntity.SetSerial(reignTitle->GetSerial());
        reignTitleEntity.SetBeginYear(reignTitle->GetBeginYear());
        reignTitleEntity.SetBeginMonth(reignTitle->GetBeginMonth());
        reignTitleEntity.SetBeginSexagenaryCycle(reignTitle->GetBeginSexagenaryCycle());
        reignTitleEntity.SetBeginDay(reignTitle->GetBeginDay());
        reignTitleEntity.SetEndYear(reignTitle->GetEndYear());
        reignTitleEntity.SetEndMonth(reignTitle->GetEndMonth());
        reignTitleEntity.SetEndSexagenaryCycle(reignTitle->GetEndSexagenaryCycle());
        reignTitleEntity.SetEndDay(reignTitle->GetEndDay());

        mysqlConnectorDatabaseFlush.ChangeDatabase(0, reignTitleEntity.GetModify());
    }
}