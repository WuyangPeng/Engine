///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/27 21:56)

#ifndef DATABASE_GENERATE_SERVER_BASE_TESTING_DATABASE_ENTITY_SUITE_GEOGRAPHIC_ENTITY_TESTING_H
#define DATABASE_GENERATE_SERVER_BASE_TESTING_DATABASE_ENTITY_SUITE_GEOGRAPHIC_ENTITY_TESTING_H

#include "DatabaseEntityTesting.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/GeographicContainer.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/DatabaseEntity/DatabaseEntityFwd.h"
#include "Database/DatabaseInterface/DatabaseInterfaceFwd.h"

namespace DatabaseGenerateServerBaseTesting
{
    class GeographicEntityTesting final : public DatabaseEntityTesting
    {
    public:
        using ClassType = GeographicEntityTesting;
        using ParentType = DatabaseEntityTesting;

        using GeographicContainer = AncientBooks::GeographicContainer;

    public:
        GeographicEntityTesting(const OStreamShared& stream, const GeographicContainer& geographicContainer);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        using Geographic = AncientBooks::GeographicBase;
        using GeographicEntity = DatabaseEntity::GeographicEntity;
        using EntityContainer = std::map<int32_t, GeographicEntity>;

    private:
        void SelectOneTest(DatabaseFlush& databaseFlush) override;
        void SelectAllTest(DatabaseFlush& databaseFlush) override;
        void SelectAllSizeTest(const DatabaseFlush& databaseFlush) override;

        void SetEntity(GeographicEntity& geographicEntity, const Geographic& geographic);

        void DoSelectOneTest(DatabaseFlush& databaseFlush, const Geographic& geographic);
        void DoSelectAllTest(DatabaseFlush& databaseFlush, const Geographic& geographic, const EntityContainer& entityContainer);
        void EqualTest(const Geographic& geographic, const EntityContainer& entityContainer);

    private:
        GeographicContainer geographicContainer;
    };
}

#endif  // DATABASE_GENERATE_SERVER_BASE_TESTING_DATABASE_ENTITY_SUITE_GEOGRAPHIC_ENTITY_TESTING_H