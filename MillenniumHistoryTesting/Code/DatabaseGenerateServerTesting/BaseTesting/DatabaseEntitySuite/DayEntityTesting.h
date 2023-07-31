///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/27 21:27)

#ifndef DATABASE_GENERATE_SERVER_BASE_TESTING_DATABASE_ENTITY_SUITE_DAY_ENTITY_TESTING_H
#define DATABASE_GENERATE_SERVER_BASE_TESTING_DATABASE_ENTITY_SUITE_DAY_ENTITY_TESTING_H

#include "DatabaseEntityTesting.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/DayContainer.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/DatabaseEntity/DatabaseEntityFwd.h"
#include "Database/DatabaseInterface/DatabaseInterfaceFwd.h"

namespace DatabaseGenerateServerBaseTesting
{
    class DayEntityTesting final : public DatabaseEntityTesting
    {
    public:
        using ClassType = DayEntityTesting;
        using ParentType = DatabaseEntityTesting;

        using DayContainer = AncientBooks::DayContainer;

    public:
        DayEntityTesting(const OStreamShared& stream, const DayContainer& dayContainer);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private: 
        using Day = AncientBooks::DayBase;
        using DayEntity = DatabaseEntity::DayEntity;
        using EntityContainer = std::map<int32_t, DayEntity>;

    private:
        void SelectOneTest(DatabaseFlush& databaseFlush) override;
        void SelectAllTest(DatabaseFlush& databaseFlush) override;
        void SelectAllSizeTest(const DatabaseFlush& databaseFlush) override;

        void SetEntity(DayEntity& dayEntity, const Day& day);

        void DoSelectOneTest(DatabaseFlush& databaseFlush, const Day& day);
        void DoSelectAllTest(DatabaseFlush& databaseFlush, const Day& day, const EntityContainer& entityContainer);
        void EqualTest(const Day& day, const EntityContainer& entityContainer);

    private:
        DayContainer dayContainer;
    };
}

#endif  // DATABASE_GENERATE_SERVER_BASE_TESTING_DATABASE_ENTITY_SUITE_DAY_ENTITY_TESTING_H