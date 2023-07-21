///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/25 20:32)

#include "ArticleTesting.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/Article.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/ArticleContainerDetail.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerCore/Helper/DatabaseGenerateServerCoreClassInvariantMacro.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

DatabaseGenerateServerBaseTesting::ArticleTesting::ArticleTesting(const OStreamShared& stream, const AncientBooksContainer& ancientBooksContainer)
    : ParentType{ stream }, ancientBooksContainer{ ancientBooksContainer }
{
    DATABASE_GENERATE_SERVER_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateServerBaseTesting, ArticleTesting)

void DatabaseGenerateServerBaseTesting::ArticleTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void DatabaseGenerateServerBaseTesting::ArticleTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MappingTest);
    ASSERT_NOT_THROW_EXCEPTION_0(EffectiveTest);
}

void DatabaseGenerateServerBaseTesting::ArticleTesting::MappingTest()
{
    const auto articleContainer = ancientBooksContainer.GetArticleContainer();

    for (const auto& article : articleContainer->GetContainer())
    {
        ASSERT_GREATER(article->GetVersion(), 0);

        ASSERT_UNEQUAL_NULL_PTR(article->GetVersion(ancientBooksContainer));

        ASSERT_EQUAL(article->GetOtherAuthor(ancientBooksContainer).size(), article->GetOtherAuthor().size());
    }
}

void DatabaseGenerateServerBaseTesting::ArticleTesting::EffectiveTest()
{
    const auto articleContainer = ancientBooksContainer.GetArticleContainer();

    for (const auto& article : articleContainer->GetContainer())
    {
        ASSERT_GREATER(article->GetChapter(), 0);
        ASSERT_FALSE(article->GetChapterName().empty());
        ASSERT_GREATER_EQUAL(article->GetVolume(), 0);
        ASSERT_GREATER(article->GetChapterVolume(), 0);

        if (!article->GetAuthorNotes().empty())
        {
            ASSERT_EQUAL(article->GetOtherAuthor().size(), article->GetAuthorNotes().size());
        }

        ASSERT_EQUAL(article->GetId(), article->GetVersion() * 10000LL + article->GetChapter() * 1000LL + article->GetChapterVolume());
    }
}
