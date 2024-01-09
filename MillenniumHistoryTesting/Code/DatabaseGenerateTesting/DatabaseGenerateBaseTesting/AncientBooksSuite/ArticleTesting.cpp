/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/23 22:08)

#include "ArticleTesting.h"
#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/Article.h"
#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/ArticleContainerDetail.h"
#include "DatabaseGenerate/DatabaseGenerateCore/Helper/DatabaseGenerateCoreClassInvariantMacro.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

DatabaseGenerateBaseTesting::ArticleTesting::ArticleTesting(const OStreamShared& stream, const AncientBooksContainer& ancientBooksContainer)
    : ParentType{ stream },
      ancientBooksContainer{ ancientBooksContainer },
      articleContainer{ ancientBooksContainer.GetArticleContainer() }
{
    DATABASE_GENERATE_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateBaseTesting, ArticleTesting)

void DatabaseGenerateBaseTesting::ArticleTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void DatabaseGenerateBaseTesting::ArticleTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MappingTest);
    ASSERT_NOT_THROW_EXCEPTION_0(EffectiveTest);
}

void DatabaseGenerateBaseTesting::ArticleTesting::MappingTest()
{
    for (const auto& article : articleContainer->GetContainer())
    {
        ASSERT_NOT_THROW_EXCEPTION_1(VersionMappingTest, *article);
        ASSERT_NOT_THROW_EXCEPTION_1(OtherAuthorMappingTest, *article);
    }
}

void DatabaseGenerateBaseTesting::ArticleTesting::VersionMappingTest(const Article& article)
{
    ASSERT_GREATER(article.GetVersion(), 0);

    ASSERT_UNEQUAL_NULL_PTR(article.GetVersion(ancientBooksContainer));
}

void DatabaseGenerateBaseTesting::ArticleTesting::OtherAuthorMappingTest(const Article& article)
{
    ASSERT_EQUAL(article.GetOtherAuthor(ancientBooksContainer).size(), article.GetOtherAuthor().size());
}

void DatabaseGenerateBaseTesting::ArticleTesting::EffectiveTest()
{
    for (const auto& article : articleContainer->GetContainer())
    {
        ASSERT_NOT_THROW_EXCEPTION_1(ArticleTest, *article);
        ASSERT_NOT_THROW_EXCEPTION_1(AuthorNotesTest, *article);
        ASSERT_NOT_THROW_EXCEPTION_1(IdTest, *article);
    }
}

void DatabaseGenerateBaseTesting::ArticleTesting::ArticleTest(const Article& article)
{
    ASSERT_GREATER(article.GetChapter(), 0);
    ASSERT_FALSE(article.GetChapterName().empty());
    ASSERT_GREATER_EQUAL(article.GetVolume(), 0);
    ASSERT_GREATER(article.GetChapterVolume(), 0);
}

void DatabaseGenerateBaseTesting::ArticleTesting::AuthorNotesTest(const Article& article)
{
    if (!article.GetAuthorNotes().empty())
    {
        ASSERT_EQUAL(article.GetOtherAuthor().size(), article.GetAuthorNotes().size());
    }
}

void DatabaseGenerateBaseTesting::ArticleTesting::IdTest(const Article& article)
{
    ASSERT_EQUAL(article.GetId(), article.GetVersion() * 10000LL + article.GetChapter() * 1000LL + article.GetChapterVolume());
}
