///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/02 20:21)

#include "ArticleConvertTesting.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/Article.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/ArticleContainerDetail.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerCore/Convert/ConvertEntity.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerCore/Helper/DatabaseGenerateServerCoreClassInvariantMacro.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

DatabaseGenerateServerCoreTesting::ArticleConvertTesting::ArticleConvertTesting(const OStreamShared& stream, const ArticleContainer& articleContainer)
    : ParentType{ stream }, articleContainer{ articleContainer }
{
    DATABASE_GENERATE_SERVER_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateServerCoreTesting, ArticleConvertTesting)

void DatabaseGenerateServerCoreTesting::ArticleConvertTesting::ConvertTest(const DatabaseFlushSharedPtr& databaseFlush)
{
    DatabaseGenerateServerCore::ConvertEntity convertEntity{ databaseFlush };

    for (const auto& article : articleContainer.GetContainer())
    {
        const auto articleEntity = convertEntity.Convert(*article);

        ASSERT_NOT_THROW_EXCEPTION_2(EqualTest, *article, articleEntity);
    }
}

void DatabaseGenerateServerCoreTesting::ArticleConvertTesting::EqualTest(const Article& article, const ArticleEntity& articleEntity)
{
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
