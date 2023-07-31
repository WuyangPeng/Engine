///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/26 22:36)

#ifndef DATABASE_GENERATE_SERVER_BASE_TESTING_DATABASE_ENTITY_SUITE_CATEGORY_ENTITY_TESTING_H
#define DATABASE_GENERATE_SERVER_BASE_TESTING_DATABASE_ENTITY_SUITE_CATEGORY_ENTITY_TESTING_H

#include "DatabaseEntityTesting.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/CategoryContainer.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/DatabaseEntity/DatabaseEntityFwd.h"
#include "Database/DatabaseInterface/DatabaseInterfaceFwd.h"

namespace DatabaseGenerateServerBaseTesting
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

#endif  // DATABASE_GENERATE_SERVER_BASE_TESTING_DATABASE_ENTITY_SUITE_CATEGORY_ENTITY_TESTING_H