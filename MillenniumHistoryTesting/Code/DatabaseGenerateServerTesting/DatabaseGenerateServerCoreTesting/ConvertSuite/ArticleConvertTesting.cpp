///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/08 19:02)

#include "ArticleConvertTesting.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/Article.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/ArticleContainerDetail.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/DatabaseEntity/ArticleEntity.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerCore/Helper/DatabaseGenerateServerCoreClassInvariantMacro.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Database/Configuration/ConfigurationStrategy.h"
#include "Database/DatabaseInterface/BasisDatabaseManager.h"
#include "Database/DatabaseInterface/DatabaseEnvironment.h"
#include "Database/DatabaseInterface/DatabaseFlush.h"

DatabaseGenerateServerCoreTesting::ArticleConvertTesting::ArticleConvertTesting(const OStreamShared& stream, const AncientBooksContainer& ancientBooksContainer)
    : ParentType{ stream }, ancientBooksContainer{ ancientBooksContainer }
{
    DATABASE_GENERATE_SERVER_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateServerCoreTesting, ArticleConvertTesting)

void DatabaseGenerateServerCoreTesting::ArticleConvertTesting::DoRunUnitTest()
{
    Database::DatabaseEnvironment::Create();

    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);

    Database::DatabaseEnvironment::Destroy();
}

void DatabaseGenerateServerCoreTesting::ArticleConvertTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(InitEnvironmentTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DatabaseFlushTest);
}

void DatabaseGenerateServerCoreTesting::ArticleConvertTesting::InitEnvironmentTest()
{
    const Database::ConfigurationStrategy configurationStrategy{ Database::WrappersStrategy::Mongo, "127.0.0.1", 3306, "tcretest", "root", "123456" };

    DATABASE_ENVIRONMENT_SINGLETON.InitEnvironment(configurationStrategy);
}

void DatabaseGenerateServerCoreTesting::ArticleConvertTesting::DatabaseFlushTest()
{
    const Database::ConfigurationStrategy::FlagsOption flagsOption{};
    const Database::ConfigurationStrategy::StringOption stringOption{};
    const Database::ConfigurationStrategy::BooleanOption booleanOption{};
    const Database::ConfigurationStrategy::IntOption intOption{};
    const Database::ConfigurationStrategy::SSLOption sslOption{};
    const Database::ConfigurationStrategy::DBMapping dbMapping{};

    const Database::ConfigurationStrategy configurationStrategy{ Database::WrappersStrategy::Mongo, "43.139.123.106", 27017, "tcretest", "dbOwner", "TCRE", true, 10, 1000, 500, 1, flagsOption, stringOption, booleanOption, intOption, sslOption, dbMapping };

    Database::DatabaseFlush mysqlConnectorDatabaseFlush{ configurationStrategy };

    const auto articleContainer = ancientBooksContainer.GetArticleContainer();

    for (const auto& article : articleContainer->GetContainer())
    {
        const auto database = mysqlConnectorDatabaseFlush.SelectOne(DatabaseEntity::ArticleEntity::GetSelect(Database::WrappersStrategy::Mongo, article->GetId()),
                                                                    DatabaseEntity::ArticleEntity::GetDatabaseFieldContainer());

        auto articleEntity = DatabaseEntity::ArticleEntity::Create(database, Database::WrappersStrategy::Mongo, article->GetId());

        articleEntity.SetVersion(article->GetVersion());
        articleEntity.SetChapter(article->GetChapter());
        articleEntity.SetChapterName(CoreTools::StringConversion::StandardConversionUtf8(article->GetChapterName()));
        articleEntity.SetChapterVolume(article->GetChapterVolume());
        articleEntity.SetOtherAuthor(article->GetOtherAuthor());
        Database::Traits::StringArray authorNotes{};
        for (auto iter = article->GetAuthorNotesBegin(); iter != article->GetAuthorNotesEnd(); ++iter)
        {
            authorNotes.emplace_back(CoreTools::StringConversion::StandardConversionUtf8(*iter));
        }
        articleEntity.SetAuthorNotes(authorNotes);
        articleEntity.SetTitle(CoreTools::StringConversion::StandardConversionUtf8(article->GetTitle()));
        articleEntity.SetAbbreviation(CoreTools::StringConversion::StandardConversionUtf8(article->GetAbbreviation()));
        articleEntity.SetDirectory(CoreTools::StringConversion::StandardConversionUtf8(article->GetDirectory()));

        mysqlConnectorDatabaseFlush.ChangeDatabase(0, articleEntity.GetModify());
    }
}
