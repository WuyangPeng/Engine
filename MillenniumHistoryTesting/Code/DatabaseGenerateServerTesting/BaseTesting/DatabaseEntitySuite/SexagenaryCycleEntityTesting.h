///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/28 23:04)

#ifndef DATABASE_GENERATE_SERVER_BASE_TESTING_DATABASE_ENTITY_SUITE_SEXAGENARY_CYCLE_ENTITY_TESTING_H
#define DATABASE_GENERATE_SERVER_BASE_TESTING_DATABASE_ENTITY_SUITE_SEXAGENARY_CYCLE_ENTITY_TESTING_H

#include "DatabaseEntityTesting.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/SexagenaryCycleContainer.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/DatabaseEntity/DatabaseEntityFwd.h"
#include "Database/DatabaseInterface/DatabaseInterfaceFwd.h"

namespace DatabaseGenerateServerBaseTesting
{
    class SexagenaryCycleEntityTesting final : public DatabaseEntityTesting
    {
    public:
        using ClassType = SexagenaryCycleEntityTesting;
        using ParentType = DatabaseEntityTesting;

        using SexagenaryCycleContainer = AncientBooks::SexagenaryCycleContainer;

    public:
        SexagenaryCycleEntityTesting(const OStreamShared& stream, const SexagenaryCycleContainer& sexagenaryCycleContainer);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private: 
        using SexagenaryCycle = AncientBooks::SexagenaryCycleBase;
        using SexagenaryCycleEntity = DatabaseEntity::SexagenaryCycleEntity;
        using EntityContainer = std::map<int32_t, SexagenaryCycleEntity>;

    private:
        void SelectOneTest(DatabaseFlush& databaseFlush) override;
        void SelectAllTest(DatabaseFlush& databaseFlush) override;
        void SelectAllSizeTest(const DatabaseFlush& databaseFlush) override;

        void SetEntity(SexagenaryCycleEntity& sexagenaryCycleEntity, const SexagenaryCycle& sexagenaryCycle);

        void DoSelectOneTest(DatabaseFlush& databaseFlush, const SexagenaryCycle& sexagenaryCycle);
        void DoSelectAllTest(DatabaseFlush& databaseFlush, const SexagenaryCycle& sexagenaryCycle, const EntityContainer& entityContainer);
        void EqualTest(const SexagenaryCycle& sexagenaryCycle, const EntityContainer& entityContainer);

    private:
        SexagenaryCycleContainer sexagenaryCycleContainer;
    };
}

#endif  // DATABASE_GENERATE_SERVER_BASE_TESTING_DATABASE_ENTITY_SUITE_SEXAGENARY_CYCLE_ENTITY_TESTING_H