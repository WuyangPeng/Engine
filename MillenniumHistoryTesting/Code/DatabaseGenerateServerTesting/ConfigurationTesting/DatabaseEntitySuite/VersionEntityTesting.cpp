///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/24 12:17)

#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/Version.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/VersionContainerDetail.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/DatabaseEntity/VersionEntity.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerCore/Helper/DatabaseGenerateServerCoreClassInvariantMacro.h"
#include "VersionEntityTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Database/Configuration/ConfigurationStrategy.h"
#include "Database/DatabaseInterface/BasisDatabaseManager.h"
#include "Database/DatabaseInterface/DatabaseEnvironment.h"
#include "Database/DatabaseInterface/DatabaseFlush.h"

DatabaseGenerateServerBaseTesting::VersionEntityTesting::VersionEntityTesting(const OStreamShared& stream, const AncientBooksContainer& ancientBooksContainer)
    : ParentType{ stream }, ancientBooksContainer{ ancientBooksContainer }
{
    DATABASE_GENERATE_SERVER_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateServerBaseTesting, VersionEntityTesting)

void DatabaseGenerateServerBaseTesting::VersionEntityTesting::DoRunUnitTest()
{
    Database::DatabaseEnvironment::Create();

    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);

    Database::DatabaseEnvironment::Destroy();
}

void DatabaseGenerateServerBaseTesting::VersionEntityTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(InitEnvironmentTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DatabaseFlushTest);
}

void DatabaseGenerateServerBaseTesting::VersionEntityTesting::InitEnvironmentTest()
{
    const Database::ConfigurationStrategy configurationStrategy{ Database::WrappersStrategy::Mongo, "127.0.0.1", 3306, "tcretest", "root", "123456" };

    DATABASE_ENVIRONMENT_SINGLETON.InitEnvironment(configurationStrategy);
}

void DatabaseGenerateServerBaseTesting::VersionEntityTesting::DatabaseFlushTest()
{
    const Database::ConfigurationStrategy::FlagsOption flagsOption{};
    const Database::ConfigurationStrategy::StringOption stringOption{};
    const Database::ConfigurationStrategy::BooleanOption booleanOption{};
    const Database::ConfigurationStrategy::IntOption intOption{};
    const Database::ConfigurationStrategy::SSLOption sslOption{};
    const Database::ConfigurationStrategy::DBMapping dbMapping{};

    const Database::ConfigurationStrategy configurationStrategy{ Database::WrappersStrategy::Mongo, "43.139.123.106", 27017, "tcretest", "dbOwner", "TCRE", true, 10, 1000, 500, 1, flagsOption, stringOption, booleanOption, intOption, sslOption, dbMapping };

    Database::DatabaseFlush mysqlConnectorDatabaseFlush{ configurationStrategy };

    const auto versionContainer = ancientBooksContainer.GetVersionContainer();

    for (const auto& version : versionContainer->GetContainer())
    {
        const auto database = mysqlConnectorDatabaseFlush.SelectOne(DatabaseEntity::VersionEntity::GetSelect(Database::WrappersStrategy::Mongo, version->GetId()),
                                                                    DatabaseEntity::VersionEntity::GetDatabaseFieldContainer());

        auto versionEntity = DatabaseEntity::VersionEntity::Create(database, Database::WrappersStrategy::Mongo, version->GetId());

        versionEntity.SetBook(version->GetBook());
        versionEntity.SetSource(version->GetSource());
        versionEntity.SetSourceName(CoreTools::StringConversion::StandardConversionUtf8(version->GetSourceName()));
        versionEntity.SetCountry(version->GetCountry());
        versionEntity.SetReignTitle(version->GetReignTitle());
        versionEntity.SetYear(version->GetYear());
        versionEntity.SetVersion(CoreTools::StringConversion::StandardConversionUtf8(version->GetVersion()));
        versionEntity.SetOtherAuthor(version->GetOtherAuthor());

        Database::Traits::StringArray authorNotes{};
        for (auto iter = version->GetAuthorNotesBegin(); iter != version->GetAuthorNotesEnd(); ++iter)
        {
            authorNotes.emplace_back(CoreTools::StringConversion::StandardConversionUtf8(*iter));
        }
        versionEntity.SetAuthorNotes(authorNotes);

        mysqlConnectorDatabaseFlush.ChangeDatabase(0, versionEntity.GetModify());
    }
}