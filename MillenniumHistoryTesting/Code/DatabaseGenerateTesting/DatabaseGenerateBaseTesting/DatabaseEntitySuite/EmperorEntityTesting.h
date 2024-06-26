/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/23 22:19)

#ifndef DATABASE_GENERATE_BASE_TESTING_DATABASE_ENTITY_SUITE_EMPEROR_ENTITY_TESTING_H
#define DATABASE_GENERATE_BASE_TESTING_DATABASE_ENTITY_SUITE_EMPEROR_ENTITY_TESTING_H

#include "DatabaseEntityTesting.h"
#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/EmperorContainer.h"

namespace DatabaseGenerateBaseTesting
{
    class EmperorEntityTesting final : public DatabaseEntityTesting
    {
    public:
        using ClassType = EmperorEntityTesting;
        using ParentType = DatabaseEntityTesting;

        using EmperorContainer = AncientBooks::EmperorContainer;

    public:
        EmperorEntityTesting(const OStreamShared& stream, EmperorContainer emperorContainer);

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