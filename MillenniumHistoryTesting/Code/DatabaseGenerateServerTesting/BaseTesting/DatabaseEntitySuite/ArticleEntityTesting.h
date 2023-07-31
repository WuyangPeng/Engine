///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/23 22:30)

#ifndef DATABASE_GENERATE_SERVER_BASE_TESTING_DATABASE_ENTITY_SUITE_ARTICLE_ENTITY_TESTING_H
#define DATABASE_GENERATE_SERVER_BASE_TESTING_DATABASE_ENTITY_SUITE_ARTICLE_ENTITY_TESTING_H

#include "DatabaseEntityTesting.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/ArticleContainer.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/DatabaseEntity/DatabaseEntityFwd.h"
#include "Database/DatabaseInterface/DatabaseInterfaceFwd.h"

namespace DatabaseGenerateServerBaseTesting
{
    class ArticleEntityTesting final : public DatabaseEntityTesting
    {
    public:
        using ClassType = ArticleEntityTesting;
        using ParentType = DatabaseEntityTesting;

        using ArticleContainer = AncientBooks::ArticleContainer;

    public:
        ArticleEntityTesting(const OStreamShared& stream, const ArticleContainer& articleContainer);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        using Article = AncientBooks::ArticleBase;
        using ArticleEntity = DatabaseEntity::ArticleEntity;
        using EntityContainer = std::map<int64_t, ArticleEntity>;

    private:
        void SelectOneTest(DatabaseFlush& databaseFlush) override;
        void SelectAllTest(DatabaseFlush& databaseFlush) override;
        void SelectAllSizeTest(const DatabaseFlush& databaseFlush) override;

        void SetEntity(ArticleEntity& articleEntity, const Article& article);

        void DoSelectOneTest(DatabaseFlush& databaseFlush, const Article& article);
        void DoSelectAllTest(DatabaseFlush& databaseFlush, const Article& article, const EntityContainer& entityContainer);
        void EqualTest(const Article& article, const EntityContainer& entityContainer);

    private:
        ArticleContainer articleContainer;
    };
}

#endif  // DATABASE_GENERATE_SERVER_BASE_TESTING_DATABASE_ENTITY_SUITE_ARTICLE_ENTITY_TESTING_H