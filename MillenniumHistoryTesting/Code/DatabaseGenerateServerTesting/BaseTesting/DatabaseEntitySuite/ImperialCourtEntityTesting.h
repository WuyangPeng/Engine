///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/28 22:45)

#ifndef DATABASE_GENERATE_SERVER_BASE_TESTING_DATABASE_ENTITY_SUITE_IMPERIAL_COURT_ENTITY_TESTING_H
#define DATABASE_GENERATE_SERVER_BASE_TESTING_DATABASE_ENTITY_SUITE_IMPERIAL_COURT_ENTITY_TESTING_H

#include "DatabaseEntityTesting.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/ImperialCourtContainer.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/DatabaseEntity/DatabaseEntityFwd.h"
#include "Database/DatabaseInterface/DatabaseInterfaceFwd.h"

namespace DatabaseGenerateServerBaseTesting
{
    class ImperialCourtEntityTesting final : public DatabaseEntityTesting
    {
    public:
        using ClassType = ImperialCourtEntityTesting;
        using ParentType = DatabaseEntityTesting;

        using ImperialCourtContainer = AncientBooks::ImperialCourtContainer;

    public:
        ImperialCourtEntityTesting(const OStreamShared& stream, const ImperialCourtContainer& imperialCourtContainer);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        using ImperialCourt = AncientBooks::ImperialCourtBase;
        using ImperialCourtEntity = DatabaseEntity::ImperialCourtEntity;
        using EntityContainer = std::map<int32_t, ImperialCourtEntity>;

    private:
        void SelectOneTest(DatabaseFlush& databaseFlush) override;
        void SelectAllTest(DatabaseFlush& databaseFlush) override;
        void SelectAllSizeTest(const DatabaseFlush& databaseFlush) override;

        void SetEntity(ImperialCourtEntity& imperialCourtEntity, const ImperialCourt& imperialCourt);

        void DoSelectOneTest(DatabaseFlush& databaseFlush, const ImperialCourt& imperialCourt);
        void DoSelectAllTest(DatabaseFlush& databaseFlush, const ImperialCourt& imperialCourt, const EntityContainer& entityContainer);
        void EqualTest(const ImperialCourt& imperialCourt, const EntityContainer& entityContainer);

    private:
        ImperialCourtContainer imperialCourtContainer;
    };
}

#endif  // DATABASE_GENERATE_SERVER_BASE_TESTING_DATABASE_ENTITY_SUITE_IMPERIAL_COURT_ENTITY_TESTING_H