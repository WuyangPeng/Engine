/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/23 22:20)

#ifndef DATABASE_GENERATE_BASE_TESTING_DATABASE_ENTITY_SUITE_GATHER_ENTITY_TESTING_H
#define DATABASE_GENERATE_BASE_TESTING_DATABASE_ENTITY_SUITE_GATHER_ENTITY_TESTING_H

#include "DatabaseEntityTesting.h"
#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/GatherContainer.h"

namespace DatabaseGenerateBaseTesting
{
    class GatherEntityTesting final : public DatabaseEntityTesting
    {
    public:
        using ClassType = GatherEntityTesting;
        using ParentType = DatabaseEntityTesting;

        using GatherContainer = AncientBooks::GatherContainer;

    public:
        GatherEntityTesting(const OStreamShared& stream, GatherContainer gatherContainer);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        using Gather = AncientBooks::GatherBase;
        using GatherEntity = DatabaseEntity::GatherEntity;
        using EntityContainer = std::map<int32_t, GatherEntity>;

    private:
        void SelectOneTest(DatabaseFlush& databaseFlush) override;
        void SelectAllTest(DatabaseFlush& databaseFlush) override;
        void SelectAllSizeTest(const DatabaseFlush& databaseFlush) override;

        void SetEntity(GatherEntity& gatherEntity, const Gather& gather);

        void DoSelectOneTest(DatabaseFlush& databaseFlush, const Gather& gather);
        void DoSelectAllTest(DatabaseFlush& databaseFlush, const Gather& gather, const EntityContainer& entityContainer);
        void EqualTest(const Gather& gather, const EntityContainer& entityContainer);

    private:
        GatherContainer gatherContainer;
    };
}

#endif  // DATABASE_GENERATE_BASE_TESTING_DATABASE_ENTITY_SUITE_GATHER_ENTITY_TESTING_H