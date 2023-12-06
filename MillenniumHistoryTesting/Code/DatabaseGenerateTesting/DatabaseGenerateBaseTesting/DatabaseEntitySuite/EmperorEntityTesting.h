/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.1 (2023/11/30 22:38)

#ifndef DATABASE_GENERATE_BASE_TESTING_DATABASE_ENTITY_SUITE_EMPEROR_ENTITY_TESTING_H
#define DATABASE_GENERATE_BASE_TESTING_DATABASE_ENTITY_SUITE_EMPEROR_ENTITY_TESTING_H

#include "DatabaseEntityTesting.h"
#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/EmperorContainer.h"
#include "DatabaseGenerate/DatabaseGenerateBase/DatabaseEntity/DatabaseEntityFwd.h"
#include "Database/DatabaseInterface/DatabaseInterfaceFwd.h"

namespace DatabaseGenerateBaseTesting
{
    class EmperorEntityTesting final : public DatabaseEntityTesting
    {
    public:
        using ClassType = EmperorEntityTesting;
        using ParentType = DatabaseEntityTesting;

        using EmperorContainer = AncientBooks::EmperorContainer;

    public:
        EmperorEntityTesting(const OStreamShared& stream, const EmperorContainer& emperorContainer);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        using Emperor = AncientBooks::EmperorBase;
        using EmperorEntity = DatabaseEntity::EmperorEntity;
        using EntityContainer = std::map<int32_t, EmperorEntity>;

    private:
        void SelectOneTest(DatabaseFlush& databaseFlush) override;
        void SelectAllTest(DatabaseFlush& databaseFlush) override;
        void SelectAllSizeTest(const DatabaseFlush& databaseFlush) override;

        void SetEntity(EmperorEntity& emperorEntity, const Emperor& emperor);

        void DoSelectOneTest(DatabaseFlush& databaseFlush, const Emperor& emperor);
        void DoSelectAllTest(DatabaseFlush& databaseFlush, const Emperor& emperor, const EntityContainer& entityContainer);
        void EqualTest(const Emperor& emperor, const EntityContainer& entityContainer);

    private:
        EmperorContainer emperorContainer;
    };
}

#endif  // DATABASE_GENERATE_BASE_TESTING_DATABASE_ENTITY_SUITE_EMPEROR_ENTITY_TESTING_H