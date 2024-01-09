/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/23 22:21)

#ifndef DATABASE_GENERATE_BASE_TESTING_DATABASE_ENTITY_SUITE_SOURCE_ENTITY_TESTING_H
#define DATABASE_GENERATE_BASE_TESTING_DATABASE_ENTITY_SUITE_SOURCE_ENTITY_TESTING_H

#include "DatabaseEntityTesting.h"
#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/SourceContainer.h"

namespace DatabaseGenerateBaseTesting
{
    class SourceEntityTesting final : public DatabaseEntityTesting
    {
    public:
        using ClassType = SourceEntityTesting;
        using ParentType = DatabaseEntityTesting;

        using SourceContainer = AncientBooks::SourceContainer;

    public:
        SourceEntityTesting(const OStreamShared& stream, SourceContainer sourceContainer);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        using Source = AncientBooks::SourceBase;
        using SourceEntity = DatabaseEntity::SourceEntity;
        using EntityContainer = std::map<int32_t, SourceEntity>;

    private:
        void SelectOneTest(DatabaseFlush& databaseFlush) override;
        void SelectAllTest(DatabaseFlush& databaseFlush) override;
        void SelectAllSizeTest(const DatabaseFlush& databaseFlush) override;

        void SetEntity(SourceEntity& sourceEntity, const Source& source);

        void DoSelectOneTest(DatabaseFlush& databaseFlush, const Source& source);
        void DoSelectAllTest(DatabaseFlush& databaseFlush, const Source& source, const EntityContainer& entityContainer);
        void EqualTest(const Source& source, const EntityContainer& entityContainer);

    private:
        SourceContainer sourceContainer;
    };
}

#endif  // DATABASE_GENERATE_BASE_TESTING_DATABASE_ENTITY_SUITE_SOURCE_ENTITY_TESTING_H