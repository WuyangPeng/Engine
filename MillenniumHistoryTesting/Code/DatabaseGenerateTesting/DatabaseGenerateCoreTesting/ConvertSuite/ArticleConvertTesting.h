/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.1 (2023/11/30 22:47)

#ifndef DATABASE_GENERATE_CORE_TESTING_DATABASE_ENTITY_SUITE_ARTICLE_CONVERT_TESTING_H
#define DATABASE_GENERATE_CORE_TESTING_DATABASE_ENTITY_SUITE_ARTICLE_CONVERT_TESTING_H

#include "ConvertTesting.h"
#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/ArticleContainer.h"
#include "DatabaseGenerate/DatabaseGenerateBase/DatabaseEntity/DatabaseEntityFwd.h"

namespace DatabaseGenerateCoreTesting
{
    class ArticleConvertTesting final : public ConvertTesting
    {
    public:
        using ClassType = ArticleConvertTesting;
        using ParentType = ConvertTesting;

        using ArticleContainer = AncientBooks::ArticleContainer;

    public:
        ArticleConvertTesting(const OStreamShared& stream, const ArticleContainer& articleContainer);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        using Article = AncientBooks::ArticleBase;
        using ArticleEntity = DatabaseEntity::ArticleEntity;

    private:
        void ConvertTest(const DatabaseFlushSharedPtr& databaseFlush) override;
        void EqualTest(const Article& article, const ArticleEntity& articleEntity);

    private:
        ArticleContainer articleContainer;
    };
}

#endif  // DATABASE_GENERATE_CORE_TESTING_DATABASE_ENTITY_SUITE_ARTICLE_CONVERT_TESTING_H