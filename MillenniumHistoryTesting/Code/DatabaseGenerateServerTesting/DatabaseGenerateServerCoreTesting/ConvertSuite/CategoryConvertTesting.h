///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/08/03 23:04)

#ifndef DATABASE_GENERATE_SERVER_CORE_TESTING_DATABASE_ENTITY_SUITE_CATEGORY_CONVERT_TESTING_H
#define DATABASE_GENERATE_SERVER_CORE_TESTING_DATABASE_ENTITY_SUITE_CATEGORY_CONVERT_TESTING_H

#include "ConvertTesting.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/CategoryContainer.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/DatabaseEntity/DatabaseEntityFwd.h"

namespace DatabaseGenerateServerCoreTesting
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

#endif  // DATABASE_GENERATE_SERVER_CORE_TESTING_DATABASE_ENTITY_SUITE_CATEGORY_CONVERT_TESTING_H