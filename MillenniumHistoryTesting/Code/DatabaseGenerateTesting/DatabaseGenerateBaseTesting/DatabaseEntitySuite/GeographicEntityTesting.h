/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.1 (2023/11/30 22:38)

#ifndef DATABASE_GENERATE_BASE_TESTING_DATABASE_ENTITY_SUITE_GEOGRAPHIC_ENTITY_TESTING_H
#define DATABASE_GENERATE_BASE_TESTING_DATABASE_ENTITY_SUITE_GEOGRAPHIC_ENTITY_TESTING_H

#include "DatabaseEntityTesting.h"
#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/GeographicContainer.h"
#include "DatabaseGenerate/DatabaseGenerateBase/DatabaseEntity/DatabaseEntityFwd.h"
#include "Database/DatabaseInterface/DatabaseInterfaceFwd.h"

namespace DatabaseGenerateBaseTesting
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

#endif  // DATABASE_GENERATE_BASE_TESTING_DATABASE_ENTITY_SUITE_GEOGRAPHIC_ENTITY_TESTING_H