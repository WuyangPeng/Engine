/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/11/30 22:39)

#ifndef DATABASE_GENERATE_BASE_TESTING_DATABASE_ENTITY_SUITE_YEAR_ENTITY_TESTING_H
#define DATABASE_GENERATE_BASE_TESTING_DATABASE_ENTITY_SUITE_YEAR_ENTITY_TESTING_H

#include "DatabaseEntityTesting.h"
#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/YearContainer.h"
#include "DatabaseGenerate/DatabaseGenerateBase/DatabaseEntity/DatabaseEntityFwd.h"
#include "Database/DatabaseInterface/DatabaseInterfaceFwd.h"

namespace DatabaseGenerateBaseTesting
{
    class YearEntityTesting final : public DatabaseEntityTesting
    {
    public:
        using ClassType = YearEntityTesting;
        using ParentType = DatabaseEntityTesting;

        using YearContainer = AncientBooks::YearContainer;

    public:
        YearEntityTesting(const OStreamShared& stream, const YearContainer& yearContainer);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        using Year = AncientBooks::YearBase;
        using YearEntity = DatabaseEntity::YearEntity;
        using EntityContainer = std::map<int32_t, YearEntity>;

    private:
        void SelectOneTest(DatabaseFlush& databaseFlush) override;
        void SelectAllTest(DatabaseFlush& databaseFlush) override;
        void SelectAllSizeTest(const DatabaseFlush& databaseFlush) override;

        void SetEntity(YearEntity& yearEntity, const Year& year);

        void DoSelectOneTest(DatabaseFlush& databaseFlush, const Year& year);
        void DoSelectAllTest(DatabaseFlush& databaseFlush, const Year& year, const EntityContainer& entityContainer);
        void EqualTest(const Year& year, const EntityContainer& entityContainer);

    private:
        YearContainer yearContainer;
    };
}

#endif  // DATABASE_GENERATE_BASE_TESTING_DATABASE_ENTITY_SUITE_YEAR_ENTITY_TESTING_H