/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/25 22:17)

#include "ArticleConvertTesting.h"
#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/Article.h"
#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/ArticleContainerDetail.h"
#include "DatabaseGenerate/DatabaseGenerateCore/Convert/ConvertEntity.h"
#include "DatabaseGenerate/DatabaseGenerateCore/Helper/DatabaseGenerateCoreClassInvariantMacro.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

DatabaseGenerateCoreTesting::ArticleConvertTesting::ArticleConvertTesting(const OStreamShared& stream, ArticleContainer articleContainer)
    : ParentType{ stream }, articleContainer{ std::move(articleContainer) }
{
    DATABASE_GENERATE_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateCoreTesting, ArticleConvertTesting)

void DatabaseGenerateCoreTesting::ArticleConvertTesting::ConvertTest(const DatabaseFlushSharedPtr& databaseFlush)
{
    DatabaseGenerateCore::ConvertEntity convertEntity{ databaseFlush };

    for (const auto& article : articleContainer.GetContainer())
    {
        const auto articleEntity = convertEntity.Convert(*article);

        ASSERT_NOT_THROW_EXCEPTION_2(EqualTest, *article, articleEntity);
    }
}

void DatabaseGenerateCoreTesting::ArticleConvertTesting::EqualTest(const Article& article, const ArticleEntity& articleEntity)
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
