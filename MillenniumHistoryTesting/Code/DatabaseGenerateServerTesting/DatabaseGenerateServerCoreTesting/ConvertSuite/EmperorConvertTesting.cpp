///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/29 22:26)

#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/Emperor.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/EmperorContainerDetail.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/DatabaseEntity/EmperorEntity.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerCore/Helper/DatabaseGenerateServerCoreClassInvariantMacro.h"
#include "EmperorConvertTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Database/Configuration/ConfigurationStrategy.h"
#include "Database/DatabaseInterface/BasisDatabaseManager.h"
#include "Database/DatabaseInterface/DatabaseEnvironment.h"
#include "Database/DatabaseInterface/DatabaseFlush.h"

DatabaseGenerateServerCoreTesting::EmperorConvertTesting::EmperorConvertTesting(const OStreamShared& stream, const AncientBooksContainer& ancientBooksContainer)
    : ParentType{ stream }, ancientBooksContainer{ ancientBooksContainer }
{
    DATABASE_GENERATE_SERVER_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateServerCoreTesting, EmperorConvertTesting)

void DatabaseGenerateServerCoreTesting::EmperorConvertTesting::DoRunUnitTest()
{
    Database::DatabaseEnvironment::Create();

    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);

    Database::DatabaseEnvironment::Destroy();
}

void DatabaseGenerateServerCoreTesting::EmperorConvertTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(InitEnvironmentTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DatabaseFlushTest);
}

void DatabaseGenerateServerCoreTesting::EmperorConvertTesting::InitEnvironmentTest()
{
    const Database::ConfigurationStrategy configurationStrategy{ Database::WrappersStrategy::Mongo, "127.0.0.1", 3306, "tcretest", "root", "123456" };

    DATABASE_ENVIRONMENT_SINGLETON.InitEnvironment(configurationStrategy);
}

void DatabaseGenerateServerCoreTesting::EmperorConvertTesting::DatabaseFlushTest()
{
    const Database::ConfigurationStrategy::FlagsOption flagsOption{};
    const Database::ConfigurationStrategy::StringOption stringOption{};
    const Database::ConfigurationStrategy::BooleanOption booleanOption{};
    const Database::ConfigurationStrategy::IntOption intOption{};
    const Database::ConfigurationStrategy::SSLOption sslOption{};
    const Database::ConfigurationStrategy::DBMapping dbMapping{};

    const Database::ConfigurationStrategy configurationStrategy{ Database::WrappersStrategy::Mongo, "43.139.123.106", 27017, "tcretest", "dbOwner", "TCRE", true, 10, 1000, 500, 1, flagsOption, stringOption, booleanOption, intOption, sslOption, dbMapping };

    Database::DatabaseFlush mysqlConnectorDatabaseFlush{ configurationStrategy };

    const auto emperorContainer = ancientBooksContainer.GetEmperorContainer();

    for (const auto& emperor : emperorContainer->GetContainer())
    {
        const auto database = mysqlConnectorDatabaseFlush.SelectOne(DatabaseEntity::EmperorEntity::GetSelect(Database::WrappersStrategy::Mongo, emperor->GetId()),
                                                                    DatabaseEntity::EmperorEntity::GetDatabaseFieldContainer());

        auto emperorEntity = DatabaseEntity::EmperorEntity::Create(database, Database::WrappersStrategy::Mongo, emperor->GetId());

        emperorEntity.SetCharacter(emperor->GetCharacter());
        emperorEntity.SetName(CoreTools::StringConversion::StandardConversionUtf8(emperor->GetName()));
        emperorEntity.SetDynasticTitle(CoreTools::StringConversion::StandardConversionUtf8(emperor->GetDynasticTitle()));
        Database::Traits::StringArray dynasticTitleAlias{};
        for (auto iter = emperor->GetDynasticTitleAliasBegin(); iter != emperor->GetDynasticTitleAliasEnd(); ++iter)
        {
            dynasticTitleAlias.emplace_back(CoreTools::StringConversion::StandardConversionUtf8(*iter));
        }
        emperorEntity.SetDynasticTitleAlias(dynasticTitleAlias);

        emperorEntity.SetPosthumousTitle(CoreTools::StringConversion::StandardConversionUtf8(emperor->GetPosthumousTitle()));
        Database::Traits::StringArray posthumousTitleAlias{};
        for (auto iter = emperor->GetPosthumousTitleAliasBegin(); iter != emperor->GetPosthumousTitleAliasEnd(); ++iter)
        {
            posthumousTitleAlias.emplace_back(CoreTools::StringConversion::StandardConversionUtf8(*iter));
        }
        emperorEntity.SetPosthumousTitleAlias(posthumousTitleAlias);

        emperorEntity.SetBeginYear(emperor->GetBeginYear());
        emperorEntity.SetBeginMonth(emperor->GetBeginMonth());
        emperorEntity.SetBeginSexagenaryCycle(emperor->GetBeginSexagenaryCycle());
        emperorEntity.SetBeginDay(emperor->GetBeginDay());
        emperorEntity.SetEndYear(emperor->GetEndYear());
        emperorEntity.SetEndMonth(emperor->GetEndMonth());
        emperorEntity.SetEndSexagenaryCycle(emperor->GetEndSexagenaryCycle());
        emperorEntity.SetEndDay(emperor->GetEndDay());
        emperorEntity.SetAgainBeginYear(emperor->GetAgainBeginYear());
        emperorEntity.SetAgainBeginMonth(emperor->GetAgainBeginMonth());
        emperorEntity.SetAgainBeginSexagenaryCycle(emperor->GetAgainBeginSexagenaryCycle());
        emperorEntity.SetAgainBeginDay(emperor->GetAgainBeginDay());
        emperorEntity.SetAgainEndYear(emperor->GetAgainEndYear());
        emperorEntity.SetAgainEndMonth(emperor->GetAgainEndMonth());
        emperorEntity.SetAgainEndSexagenaryCycle(emperor->GetAgainEndSexagenaryCycle());
        emperorEntity.SetAgainEndDay(emperor->GetAgainEndDay());
        Database::Traits::StringArray unansweredQuestion{};
        for (auto iter = emperor->GetUnansweredQuestionBegin(); iter != emperor->GetUnansweredQuestionEnd(); ++iter)
        {
            unansweredQuestion.emplace_back(CoreTools::StringConversion::StandardConversionUtf8(*iter));
        }
        emperorEntity.SetUnansweredQuestion(unansweredQuestion);

        mysqlConnectorDatabaseFlush.ChangeDatabase(0, emperorEntity.GetModify());
    }
}