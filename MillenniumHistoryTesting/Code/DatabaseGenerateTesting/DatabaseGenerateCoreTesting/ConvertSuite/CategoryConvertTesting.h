/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/11/30 22:47)

#ifndef DATABASE_GENERATE_CORE_TESTING_DATABASE_ENTITY_SUITE_CATEGORY_CONVERT_TESTING_H
#define DATABASE_GENERATE_CORE_TESTING_DATABASE_ENTITY_SUITE_CATEGORY_CONVERT_TESTING_H

#include "ConvertTesting.h"
#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/CategoryContainer.h"
#include "DatabaseGenerate/DatabaseGenerateBase/DatabaseEntity/DatabaseEntityFwd.h"

namespace DatabaseGenerateCoreTesting
{
    class CategoryConvertTesting final : public ConvertTesting
    {
    public:
        using ClassType = CategoryConvertTesting;
        using ParentType = ConvertTesting;

        using CategoryContainer = AncientBooks::CategoryContainer;

    public:
        CategoryConvertTesting(const OStreamShared& stream, const CategoryContainer& categoryContainer);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        using Category = AncientBooks::CategoryBase;
        using CategoryEntity = DatabaseEntity::CategoryEntity;

    private:
        void ConvertTest(const DatabaseFlushSharedPtr& databaseFlush) override;
        void EqualTest(const Category& category, const CategoryEntity& categoryEntity);

    private:
        CategoryContainer categoryContainer;
    };
}

#endif  // DATABASE_GENERATE_CORE_TESTING_DATABASE_ENTITY_SUITE_CATEGORY_CONVERT_TESTING_H