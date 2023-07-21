///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/24 12:17)

#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/Gather.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/GatherContainerDetail.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/DatabaseEntity/GatherEntity.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerCore/Helper/DatabaseGenerateServerCoreClassInvariantMacro.h"
#include "GatherConvertTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Database/Configuration/ConfigurationStrategy.h"
#include "Database/DatabaseInterface/BasisDatabaseManager.h"
#include "Database/DatabaseInterface/DatabaseEnvironment.h"
#include "Database/DatabaseInterface/DatabaseFlush.h"

DatabaseGenerateServerCoreTesting::GatherConvertTesting::GatherConvertTesting(const OStreamShared& stream, const AncientBooksContainer& ancientBooksContainer)
    : ParentType{ stream }, ancientBooksContainer{ ancientBooksContainer }
{
    DATABASE_GENERATE_SERVER_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateServerCoreTesting, GatherConvertTesting)

void DatabaseGenerateServerCoreTesting::GatherConvertTesting::DoRunUnitTest()
{
    Database::DatabaseEnvironment::Create();

    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);

    Database::DatabaseEnvironment::Destroy();
}

void DatabaseGenerateServerCoreTesting::GatherConvertTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(InitEnvironmentTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DatabaseFlushTest);
}

void DatabaseGenerateServerCoreTesting::GatherConvertTesting::InitEnvironmentTest()
{
    const Database::ConfigurationStrategy configurationStrategy{ Database::WrappersStrategy::Mongo, "127.0.0.1", 3306, "tcretest", "root", "123456" };

    DATABASE_ENVIRONMENT_SINGLETON.InitEnvironment(configurationStrategy);
}

void DatabaseGenerateServerCoreTesting::GatherConvertTesting::DatabaseFlushTest()
{
    const Database::ConfigurationStrategy::FlagsOption flagsOption{};
    const Database::ConfigurationStrategy::StringOption stringOption{};
    const Database::ConfigurationStrategy::BooleanOption booleanOption{};
    const Database::ConfigurationStrategy::IntOption intOption{};
    const Database::ConfigurationStrategy::SSLOption sslOption{};
    const Database::ConfigurationStrategy::DBMapping dbMapping{};

    const Database::ConfigurationStrategy configurationStrategy{ Database::WrappersStrategy::Mongo, "43.139.123.106", 27017, "tcretest", "dbOwner", "TCRE", true, 10, 1000, 500, 1, flagsOption, stringOption, booleanOption, intOption, sslOption, dbMapping };

    Database::DatabaseFlush mysqlConnectorDatabaseFlush{ configurationStrategy };

    const auto gatherContainer = ancientBooksContainer.GetGatherContainer();

    for (const auto& gather : gatherContainer->GetContainer())
    {
        const auto database = mysqlConnectorDatabaseFlush.SelectOne(DatabaseEntity::GatherEntity::GetSelect(Database::WrappersStrategy::Mongo, gather->GetId()),
                                                                    DatabaseEntity::GatherEntity::GetDatabaseFieldContainer());

        auto gatherEntity = DatabaseEntity::GatherEntity::Create(database, Database::WrappersStrategy::Mongo, gather->GetId());

        gatherEntity.SetGather(CoreTools::StringConversion::StandardConversionUtf8(gather->GetGather()));

        mysqlConnectorDatabaseFlush.ChangeDatabase(0, gatherEntity.GetModify());
    }
}
