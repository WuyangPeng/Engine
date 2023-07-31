///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/28 22:58)

#ifndef DATABASE_GENERATE_SERVER_BASE_TESTING_DATABASE_ENTITY_SUITE_REIGN_TITLE_ENTITY_TESTING_H
#define DATABASE_GENERATE_SERVER_BASE_TESTING_DATABASE_ENTITY_SUITE_REIGN_TITLE_ENTITY_TESTING_H

#include "DatabaseEntityTesting.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/ReignTitleContainer.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/DatabaseEntity/DatabaseEntityFwd.h"
#include "Database/DatabaseInterface/DatabaseInterfaceFwd.h"

namespace DatabaseGenerateServerBaseTesting
{
    class ReignTitleEntityTesting final : public DatabaseEntityTesting
    {
    public:
        using ClassType = ReignTitleEntityTesting;
        using ParentType = DatabaseEntityTesting;

        using ReignTitleContainer = AncientBooks::ReignTitleContainer;

    public:
        ReignTitleEntityTesting(const OStreamShared& stream, const ReignTitleContainer& reignTitleContainer);

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

#endif  // DATABASE_GENERATE_SERVER_BASE_TESTING_DATABASE_ENTITY_SUITE_REIGN_TITLE_ENTITY_TESTING_H