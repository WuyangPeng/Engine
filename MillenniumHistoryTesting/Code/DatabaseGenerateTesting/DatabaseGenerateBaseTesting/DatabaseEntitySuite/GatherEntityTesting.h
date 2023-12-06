/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.1 (2023/11/30 22:38)

#ifndef DATABASE_GENERATE_BASE_TESTING_DATABASE_ENTITY_SUITE_GATHER_ENTITY_TESTING_H
#define DATABASE_GENERATE_BASE_TESTING_DATABASE_ENTITY_SUITE_GATHER_ENTITY_TESTING_H

#include "DatabaseEntityTesting.h"
#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/GatherContainer.h"
#include "DatabaseGenerate/DatabaseGenerateBase/DatabaseEntity/DatabaseEntityFwd.h"
#include "Database/DatabaseInterface/DatabaseInterfaceFwd.h"

namespace DatabaseGenerateBaseTesting
{
    class GatherEntityTesting final : public DatabaseEntityTesting
    {
    public:
        using ClassType = GatherEntityTesting;
        using ParentType = DatabaseEntityTesting;

        using GatherContainer = AncientBooks::GatherContainer;

    public:
        GatherEntityTesting(const OStreamShared& stream, const GatherContainer& gatherContainer);

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