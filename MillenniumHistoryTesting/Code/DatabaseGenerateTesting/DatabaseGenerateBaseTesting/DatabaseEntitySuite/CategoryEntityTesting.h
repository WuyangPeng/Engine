/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/11/30 22:38)

#ifndef DATABASE_GENERATE_BASE_TESTING_DATABASE_ENTITY_SUITE_CATEGORY_ENTITY_TESTING_H
#define DATABASE_GENERATE_BASE_TESTING_DATABASE_ENTITY_SUITE_CATEGORY_ENTITY_TESTING_H

#include "DatabaseEntityTesting.h"
#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/CategoryContainer.h"
#include "DatabaseGenerate/DatabaseGenerateBase/DatabaseEntity/DatabaseEntityFwd.h"
#include "Database/DatabaseInterface/DatabaseInterfaceFwd.h"

namespace DatabaseGenerateBaseTesting
{
    class CategoryEntityTesting final : public DatabaseEntityTesting
    {
    public:
        using ClassType = CategoryEntityTesting;
        using ParentType = DatabaseEntityTesting;

        using CategoryContainer = AncientBooks::CategoryContainer;

    public:
        CategoryEntityTesting(const OStreamShared& stream, const CategoryContainer& categoryContainer);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        using Category = AncientBooks::CategoryBase;
        using CategoryEntity = DatabaseEntity::CategoryEntity;
        using EntityContainer = std::map<int32_t, CategoryEntity>;

    private:
        void SelectOneTest(DatabaseFlush& databaseFlush) override;
        void SelectAllTest(DatabaseFlush& databaseFlush) override;
        void SelectAllSizeTest(const DatabaseFlush& databaseFlush) override;

        void SetEntity(CategoryEntity& categoryEntity, const Category& category);

        void DoSelectOneTest(DatabaseFlush& databaseFlush, const Category& category);
        void DoSelectAllTest(DatabaseFlush& databaseFlush, const Category& category, const EntityContainer& entityContainer);
        void EqualTest(const Category& category, const EntityContainer& entityContainer);

    private:
        CategoryContainer categoryContainer;
    };
}

#endif  // DATABASE_GENERATE_BASE_TESTING_DATABASE_ENTITY_SUITE_CATEGORY_ENTITY_TESTING_H