/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/23 22:20)

#ifndef DATABASE_GENERATE_BASE_TESTING_DATABASE_ENTITY_SUITE_REIGN_TITLE_ENTITY_TESTING_H
#define DATABASE_GENERATE_BASE_TESTING_DATABASE_ENTITY_SUITE_REIGN_TITLE_ENTITY_TESTING_H

#include "DatabaseEntityTesting.h"
#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/ReignTitleContainer.h"

namespace DatabaseGenerateBaseTesting
{
    class ReignTitleEntityTesting final : public DatabaseEntityTesting
    {
    public:
        using ClassType = ReignTitleEntityTesting;
        using ParentType = DatabaseEntityTesting;

        using ReignTitleContainer = AncientBooks::ReignTitleContainer;

    public:
        ReignTitleEntityTesting(const OStreamShared& stream, ReignTitleContainer reignTitleContainer);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        using ReignTitle = AncientBooks::ReignTitleBase;
        using ReignTitleEntity = DatabaseEntity::ReignTitleEntity;
        using EntityContainer = std::map<int64_t, ReignTitleEntity>;

    private:
        void SelectOneTest(DatabaseFlush& databaseFlush) override;
        void SelectAllTest(DatabaseFlush& databaseFlush) override;
        void SelectAllSizeTest(const DatabaseFlush& databaseFlush) override;

        void SetEntity(ReignTitleEntity& reignTitleEntity, const ReignTitle& reignTitle);

        void DoSelectOneTest(DatabaseFlush& databaseFlush, const ReignTitle& reignTitle);
        void DoSelectAllTest(DatabaseFlush& databaseFlush, const ReignTitle& reignTitle, const EntityContainer& entityContainer);
        void EqualTest(const ReignTitle& reignTitle, const EntityContainer& entityContainer);

    private:
        ReignTitleContainer reignTitleContainer;
    };
}

#endif  // DATABASE_GENERATE_BASE_TESTING_DATABASE_ENTITY_SUITE_REIGN_TITLE_ENTITY_TESTING_H