///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/26 23:05)

#include "BookEntityTesting.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/Book.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/BookContainerDetail.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/DatabaseEntity/BookEntity.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerCore/Helper/DatabaseGenerateServerCoreClassInvariantMacro.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Database/Configuration/ConfigurationStrategy.h"
#include "Database/DatabaseInterface/BasisDatabaseManager.h"
#include "Database/DatabaseInterface/DatabaseEnvironment.h"
#include "Database/DatabaseInterface/DatabaseFlush.h"

DatabaseGenerateServerBaseTesting::BookEntityTesting::BookEntityTesting(const OStreamShared& stream, const AncientBooksContainer& ancientBooksContainer)
    : ParentType{ stream }, ancientBooksContainer{ ancientBooksContainer }
{
    DATABASE_GENERATE_SERVER_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateServerBaseTesting, BookEntityTesting)

void DatabaseGenerateServerBaseTesting::BookEntityTesting::DoRunUnitTest()
{
    Database::DatabaseEnvironment::Create();

    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);

    Database::DatabaseEnvironment::Destroy();
}

void DatabaseGenerateServerBaseTesting::BookEntityTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(InitEnvironmentTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DatabaseFlushTest);
}

void DatabaseGenerateServerBaseTesting::BookEntityTesting::InitEnvironmentTest()
{
    const Database::ConfigurationStrategy configurationStrategy{ Database::WrappersStrategy::Mongo, "127.0.0.1", 3306, "tcretest", "root", "123456" };

    DATABASE_ENVIRONMENT_SINGLETON.InitEnvironment(configurationStrategy);
}

void DatabaseGenerateServerBaseTesting::BookEntityTesting::DatabaseFlushTest()
{
    const Database::ConfigurationStrategy::FlagsOption flagsOption{};
    const Database::ConfigurationStrategy::StringOption stringOption{};
    const Database::ConfigurationStrategy::BooleanOption booleanOption{};
    const Database::ConfigurationStrategy::IntOption intOption{};
    const Database::ConfigurationStrategy::SSLOption sslOption{};
    const Database::ConfigurationStrategy::DBMapping dbMapping{};

    const Database::ConfigurationStrategy configurationStrategy{ Database::WrappersStrategy::Mongo, "43.139.123.106", 27017, "tcretest", "dbOwner", "TCRE", true, 10, 1000, 500, 1, flagsOption, stringOption, booleanOption, intOption, sslOption, dbMapping };

    Database::DatabaseFlush mysqlConnectorDatabaseFlush{ configurationStrategy };

    const auto bookContainer = ancientBooksContainer.GetBookContainer();

    for (const auto& book : bookContainer->GetContainer())
    {
        const auto database = mysqlConnectorDatabaseFlush.SelectOne(DatabaseEntity::BookEntity::GetSelect(Database::WrappersStrategy::Mongo, book->GetId()),
                                                                    DatabaseEntity::BookEntity::GetDatabaseFieldContainer());

        auto bookEntity = DatabaseEntity::BookEntity::Create(database, Database::WrappersStrategy::Mongo, book->GetId());

        bookEntity.SetGenus(book->GetGenus());
        bookEntity.SetName(CoreTools::StringConversion::StandardConversionUtf8(book->GetName()));
        Database::Traits::StringArray alias{};
        for (auto iter = book->GetAliasBegin(); iter != book->GetAliasEnd(); ++iter)
        {
            alias.emplace_back(CoreTools::StringConversion::StandardConversionUtf8(*iter));
        }
        bookEntity.SetAlias(alias);
        bookEntity.SetVolume(book->GetVolume());
        bookEntity.SetAuthor(book->GetAuthor());
        Database::Traits::StringArray authorNotes{};
        for (auto iter = book->GetAuthorNotesBegin(); iter != book->GetAuthorNotesEnd(); ++iter)
        {
            authorNotes.emplace_back(CoreTools::StringConversion::StandardConversionUtf8(*iter));
        }
        bookEntity.SetAuthorNotes(authorNotes);
        bookEntity.SetAnnotator(book->GetAnnotator());
        Database::Traits::StringArray annotateNotes{};
        for (auto iter = book->GetAnnotateNotesBegin(); iter != book->GetAnnotateNotesEnd(); ++iter)
        {
            annotateNotes.emplace_back(CoreTools::StringConversion::StandardConversionUtf8(*iter));
        }
        bookEntity.SetAnnotateNotes(annotateNotes);
        bookEntity.SetCountry(book->GetCountry());
        bookEntity.SetPerson(book->GetPerson());

        Database::Traits::StringArray unansweredQuestion{};
        for (auto iter = book->GetUnansweredQuestionBegin(); iter != book->GetUnansweredQuestionEnd(); ++iter)
        {
            unansweredQuestion.emplace_back(CoreTools::StringConversion::StandardConversionUtf8(*iter));
        }
        bookEntity.SetUnansweredQuestion(unansweredQuestion);

        mysqlConnectorDatabaseFlush.ChangeDatabase(0, bookEntity.GetModify());
    }
}
