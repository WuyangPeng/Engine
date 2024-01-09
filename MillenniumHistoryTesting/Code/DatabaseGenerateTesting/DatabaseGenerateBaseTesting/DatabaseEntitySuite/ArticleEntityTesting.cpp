/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/23 22:21)

#include "ArticleEntityTesting.h"
#include "DatabaseEntityTestingDetail.h"
#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/Article.h"
#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/ArticleContainerDetail.h"
#include "DatabaseGenerate/DatabaseGenerateBase/DatabaseEntity/ArticleEntity.h"
#include "DatabaseGenerate/DatabaseGenerateCore/Helper/DatabaseGenerateCoreClassInvariantMacro.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Database/DatabaseInterface/BasisDatabaseManager.h"
#include "Database/DatabaseInterface/DatabaseFlush.h"

DatabaseGenerateBaseTesting::ArticleEntityTesting::ArticleEntityTesting(const OStreamShared& stream, ArticleContainer articleContainer)
    : ParentType{ stream }, articleContainer{ std::move(articleContainer) }
{
    DATABASE_GENERATE_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateBaseTesting, ArticleEntityTesting)

void DatabaseGenerateBaseTesting::ArticleEntityTesting::SelectOneTest(DatabaseFlush& databaseFlush)
{
    auto index = 0;
    for (const auto& article : articleContainer.GetContainer())
    {
        ASSERT_NOT_THROW_EXCEPTION_2(DoSelectOneTest, databaseFlush, *article);

        ++index;
        if (index == GetTestLoopCount())
        {
            break;
        }
    }

    databaseFlush.Wait();
}

void DatabaseGenerateBaseTesting::ArticleEntityTesting::SelectAllTest(DatabaseFlush& databaseFlush)
{
    const auto database = databaseFlush.SelectAll(ArticleEntity::GetSelectAll(databaseFlush.GetWrappersStrategy()),
                                                  ArticleEntity::GetDatabaseFieldContainer());

    const auto entityContainer = GetEntityContainer<int64_t, ArticleEntity>(database);

    for (const auto& article : articleContainer.GetContainer())
    {
        ASSERT_NOT_THROW_EXCEPTION_3(DoSelectAllTest, databaseFlush, *article, entityContainer);
    }

    databaseFlush.Wait();
}

void DatabaseGenerateBaseTesting::ArticleEntityTesting::SelectAllSizeTest(const DatabaseFlush& databaseFlush)
{
    const auto database = databaseFlush.SelectAll(ArticleEntity::GetSelectAll(databaseFlush.GetWrappersStrategy()),
                                                  ArticleEntity::GetDatabaseFieldContainer());

    ASSERT_EQUAL(boost::numeric_cast<int>(database.size()), articleContainer.GetContainerSize());

    const auto entityContainer = GetEntityContainer<int64_t, ArticleEntity>(database);

    for (const auto& article : articleContainer.GetContainer())
    {
        ASSERT_NOT_THROW_EXCEPTION_2(EqualTest, *article, entityContainer);
    }
}

void DatabaseGenerateBaseTesting::ArticleEntityTesting::SetEntity(ArticleEntity& articleEntity, const Article& article)
{
    articleEntity.SetVersion(article.GetVersion());
    articleEntity.SetChapter(article.GetChapter());
    articleEntity.SetChapterName(CoreTools::StringConversion::StandardConversionUtf8(article.GetChapterName()));
    articleEntity.SetChapterVolume(article.GetChapterVolume());
    articleEntity.SetOtherAuthor(article.GetOtherAuthor());
    articleEntity.SetAuthorNotes(Convert(article.GetAuthorNotesBegin(), article.GetAuthorNotesEnd()));
    articleEntity.SetTitle(CoreTools::StringConversion::StandardConversionUtf8(article.GetTitle()));
    articleEntity.SetAbbreviation(CoreTools::StringConversion::StandardConversionUtf8(article.GetAbbreviation()));
    articleEntity.SetDirectory(CoreTools::StringConversion::StandardConversionUtf8(article.GetDirectory()));
}

void DatabaseGenerateBaseTesting::ArticleEntityTesting::DoSelectOneTest(DatabaseFlush& databaseFlush, const Article& article)
{
    const auto database = databaseFlush.SelectOne(ArticleEntity::GetSelect(databaseFlush.GetWrappersStrategy(), article.GetId()),
                                                  ArticleEntity::GetDatabaseFieldContainer());

    auto articleEntity = ArticleEntity::Create(database, databaseFlush.GetWrappersStrategy(), article.GetId());

    ASSERT_NOT_THROW_EXCEPTION_2(SetEntity, articleEntity, article);

    databaseFlush.ChangeDatabase(article.GetId(), articleEntity.GetModify());
}

void DatabaseGenerateBaseTesting::ArticleEntityTesting::DoSelectAllTest(DatabaseFlush& databaseFlush, const Article& article, const EntityContainer& entityContainer)
{
    const auto result = entityContainer.find(article.GetId());
    auto articleEntity = result != entityContainer.cend() ? result->second : ArticleEntity{ databaseFlush.GetWrappersStrategy(), article.GetId() };

    ASSERT_NOT_THROW_EXCEPTION_2(SetEntity, articleEntity, article);

    databaseFlush.ChangeDatabase(article.GetId(), articleEntity.GetModify());
}

void DatabaseGenerateBaseTesting::ArticleEntityTesting::EqualTest(const Article& article, const EntityContainer& entityContainer)
{
    const auto result = entityContainer.find(article.GetId());

    ASSERT_UNEQUAL_FAILURE_THROW(result, entityContainer.cend(), "数据库中未找到对应数据。id = " + std::to_string(article.GetId()));

    const auto& articleEntity = result->second;

    ASSERT_EQUAL(articleEntity.GetVersion(), article.GetVersion());
    ASSERT_EQUAL(articleEntity.GetChapter(), article.GetChapter());
    ASSERT_EQUAL(articleEntity.GetChapterName(), CoreTools::StringConversion::StandardConversionUtf8(article.GetChapterName()));
    ASSERT_EQUAL(articleEntity.GetChapterVolume(), article.GetChapterVolume());
    ASSERT_EQUAL(articleEntity.GetOtherAuthor(), article.GetOtherAuthor());
    ASSERT_EQUAL(articleEntity.GetAuthorNotes(), Convert(article.GetAuthorNotesBegin(), article.GetAuthorNotesEnd()));
    ASSERT_EQUAL(articleEntity.GetTitle(), CoreTools::StringConversion::StandardConversionUtf8(article.GetTitle()));
    ASSERT_EQUAL(articleEntity.GetAbbreviation(), CoreTools::StringConversion::StandardConversionUtf8(article.GetAbbreviation()));
    ASSERT_EQUAL(articleEntity.GetDirectory(), CoreTools::StringConversion::StandardConversionUtf8(article.GetDirectory()));
}
