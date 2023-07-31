///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/21 20:33)

#ifndef DATABASE_GENERATE_SERVER_BASE_TESTING_ANCIENT_BOOKS_SUITE_ARTICLE_TESTING_H
#define DATABASE_GENERATE_SERVER_BASE_TESTING_ANCIENT_BOOKS_SUITE_ARTICLE_TESTING_H

#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/AncientBooksContainer.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace DatabaseGenerateServerBaseTesting
{
    class ArticleTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = ArticleTesting;
        using ParentType = UnitTest;

        using AncientBooksContainer = AncientBooks::AncientBooksContainer;

    public:
        ArticleTesting(const OStreamShared& stream, const AncientBooksContainer& ancientBooksContainer);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        using Article = AncientBooks::ArticleBase;
        using ConstArticleContainerSharedPtr = AncientBooksContainer::ConstArticleContainerSharedPtr;

    private:
        void MainTest();
        void DoRunUnitTest() override;

        void MappingTest();
        void EffectiveTest();

        void VersionMappingTest(const Article& article);
        void OtherAuthorMappingTest(const Article& article);

        void ArticleTest(const Article& article);
        void AuthorNotesTest(const Article& article);
        void IdTest(const Article& article);

    private:
        AncientBooksContainer ancientBooksContainer;
        ConstArticleContainerSharedPtr articleContainer;
    };
}

#endif  // DATABASE_GENERATE_SERVER_BASE_TESTING_ANCIENT_BOOKS_SUITE_ARTICLE_TESTING_H