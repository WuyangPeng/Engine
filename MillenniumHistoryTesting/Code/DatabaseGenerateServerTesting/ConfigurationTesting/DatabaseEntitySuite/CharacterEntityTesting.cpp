///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/28 20:16)

#include "CharacterEntityTesting.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/Character.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/CharacterContainerDetail.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/DatabaseEntity/CharacterEntity.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerCore/Helper/DatabaseGenerateServerCoreClassInvariantMacro.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Database/Configuration/ConfigurationStrategy.h"
#include "Database/DatabaseInterface/BasisDatabaseManager.h"
#include "Database/DatabaseInterface/DatabaseEnvironment.h"
#include "Database/DatabaseInterface/DatabaseFlush.h"

DatabaseGenerateServerBaseTesting::CharacterEntityTesting::CharacterEntityTesting(const OStreamShared& stream, const AncientBooksContainer& ancientBooksContainer)
    : ParentType{ stream }, ancientBooksContainer{ ancientBooksContainer }
{
    DATABASE_GENERATE_SERVER_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateServerBaseTesting, CharacterEntityTesting)

void DatabaseGenerateServerBaseTesting::CharacterEntityTesting::DoRunUnitTest()
{
    Database::DatabaseEnvironment::Create();

    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);

    Database::DatabaseEnvironment::Destroy();
}

void DatabaseGenerateServerBaseTesting::CharacterEntityTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(InitEnvironmentTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DatabaseFlushTest);
}

void DatabaseGenerateServerBaseTesting::CharacterEntityTesting::InitEnvironmentTest()
{
    const Database::ConfigurationStrategy configurationStrategy{ Database::WrappersStrategy::Mongo, "127.0.0.1", 3306, "tcretest", "root", "123456" };

    DATABASE_ENVIRONMENT_SINGLETON.InitEnvironment(configurationStrategy);
}

void DatabaseGenerateServerBaseTesting::CharacterEntityTesting::DatabaseFlushTest()
{
    const Database::ConfigurationStrategy::FlagsOption flagsOption{};
    const Database::ConfigurationStrategy::StringOption stringOption{};
    const Database::ConfigurationStrategy::BooleanOption booleanOption{};
    const Database::ConfigurationStrategy::IntOption intOption{};
    const Database::ConfigurationStrategy::SSLOption sslOption{};
    const Database::ConfigurationStrategy::DBMapping dbMapping{};

    const Database::ConfigurationStrategy configurationStrategy{ Database::WrappersStrategy::Mongo, "43.139.123.106", 27017, "tcretest", "dbOwner", "TCRE", true, 10, 1000, 500, 1, flagsOption, stringOption, booleanOption, intOption, sslOption, dbMapping };

    Database::DatabaseFlush mysqlConnectorDatabaseFlush{ configurationStrategy };

    const auto characterContainer = ancientBooksContainer.GetCharacterContainer();

    for (const auto& character : characterContainer->GetContainer())
    {
        const auto database = mysqlConnectorDatabaseFlush.SelectOne(DatabaseEntity::CharacterEntity::GetSelect(Database::WrappersStrategy::Mongo, character->GetId()),
                                                                    DatabaseEntity::CharacterEntity::GetDatabaseFieldContainer());

        auto characterEntity = DatabaseEntity::CharacterEntity::Create(database, Database::WrappersStrategy::Mongo, character->GetId());

        characterEntity.SetCountry(character->GetCountry());
        characterEntity.SetIdentity(character->GetIdentity());
        characterEntity.SetFamily(CoreTools::StringConversion::StandardConversionUtf8(character->GetFamily()));
        characterEntity.SetName(CoreTools::StringConversion::StandardConversionUtf8(character->GetName()));
        characterEntity.SetFullName(CoreTools::StringConversion::StandardConversionUtf8(character->GetFullName()));
        Database::Traits::StringArray alias{};
        for (auto iter = character->GetAliasBegin(); iter != character->GetAliasEnd(); ++iter)
        {
            alias.emplace_back(CoreTools::StringConversion::StandardConversionUtf8(*iter));
        }
        characterEntity.SetAlias(alias);
        characterEntity.SetStyleName(CoreTools::StringConversion::StandardConversionUtf8(character->GetStyleName()));
        characterEntity.SetSex(character->GetSex());
        characterEntity.SetFather(character->GetFather());
        characterEntity.SetMother(character->GetMother());
        characterEntity.SetFosterFather(character->GetFosterFather());
        characterEntity.SetFosterMother(character->GetFosterMother());
        characterEntity.SetBirthYear(character->GetBirthYear());
        characterEntity.SetBirthMonth(character->GetBirthMonth());
        characterEntity.SetBirthSexagenaryCycle(character->GetBirthSexagenaryCycle());
        characterEntity.SetBirthDay(character->GetBirthDay());
        characterEntity.SetDeathYear(character->GetDeathYear());
        characterEntity.SetDeathMonth(character->GetDeathMonth());
        characterEntity.SetDeathSexagenaryCycle(character->GetDeathSexagenaryCycle());
        characterEntity.SetDeathDay(character->GetDeathDay());
        Database::Traits::StringArray unansweredQuestion{};
        for (auto iter = character->GetUnansweredQuestionBegin(); iter != character->GetUnansweredQuestionEnd(); ++iter)
        {
            unansweredQuestion.emplace_back(CoreTools::StringConversion::StandardConversionUtf8(*iter));
        }
        characterEntity.SetUnansweredQuestion(unansweredQuestion);

        mysqlConnectorDatabaseFlush.ChangeDatabase(0, characterEntity.GetModify());
    }
}