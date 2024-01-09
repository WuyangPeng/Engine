/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/23 22:20)

#ifndef DATABASE_GENERATE_BASE_TESTING_DATABASE_ENTITY_SUITE_MONTH_ENTITY_TESTING_H
#define DATABASE_GENERATE_BASE_TESTING_DATABASE_ENTITY_SUITE_MONTH_ENTITY_TESTING_H

#include "DatabaseEntityTesting.h"
#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/MonthContainer.h"

namespace DatabaseGenerateBaseTesting
{
    class MonthEntityTesting final : public DatabaseEntityTesting
    {
    public:
        using ClassType = MonthEntityTesting;
        using ParentType = DatabaseEntityTesting;

        using MonthContainer = AncientBooks::MonthContainer;

    public:
        MonthEntityTesting(const OStreamShared& stream, MonthContainer monthContainer);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        using Month = AncientBooks::MonthBase;
        using MonthEntity = DatabaseEntity::MonthEntity;
        using EntityContainer = std::map<int32_t, MonthEntity>;

    private:
        void SelectOneTest(DatabaseFlush& databaseFlush) override;
        void SelectAllTest(DatabaseFlush& databaseFlush) override;
        void SelectAllSizeTest(const DatabaseFlush& databaseFlush) override;

        void SetEntity(MonthEntity& monthEntity, const Month& month);

        void DoSelectOneTest(DatabaseFlush& databaseFlush, const Month& month);
        void DoSelectAllTest(DatabaseFlush& databaseFlush, const Month& month, const EntityContainer& entityContainer);
        void EqualTest(const Month& month, const EntityContainer& entityContainer);

    private:
        MonthContainer monthContainer;
    };
}

#endif  // DATABASE_GENERATE_BASE_TESTING_DATABASE_ENTITY_SUITE_MONTH_ENTITY_TESTING_H