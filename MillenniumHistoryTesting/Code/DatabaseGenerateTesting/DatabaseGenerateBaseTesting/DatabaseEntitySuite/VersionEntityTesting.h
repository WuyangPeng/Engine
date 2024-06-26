/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/23 22:21)

#ifndef DATABASE_GENERATE_BASE_TESTING_DATABASE_ENTITY_SUITE_VERSION_ENTITY_TESTING_H
#define DATABASE_GENERATE_BASE_TESTING_DATABASE_ENTITY_SUITE_VERSION_ENTITY_TESTING_H

#include "DatabaseEntityTesting.h"
#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/VersionContainer.h"

namespace DatabaseGenerateBaseTesting
{
    class VersionEntityTesting final : public DatabaseEntityTesting
    {
    public:
        using ClassType = VersionEntityTesting;
        using ParentType = DatabaseEntityTesting;

        using VersionContainer = AncientBooks::VersionContainer;

    public:
        VersionEntityTesting(const OStreamShared& stream, VersionContainer versionContainer);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        using Version = AncientBooks::VersionBase;
        using VersionEntity = DatabaseEntity::VersionEntity;
        using EntityContainer = std::map<int32_t, VersionEntity>;

    private:
        void SelectOneTest(DatabaseFlush& databaseFlush) override;
        void SelectAllTest(DatabaseFlush& databaseFlush) override;
        void SelectAllSizeTest(const DatabaseFlush& databaseFlush) override;

        void SetEntity(VersionEntity& versionEntity, const Version& version);

        void DoSelectOneTest(DatabaseFlush& databaseFlush, const Version& version);
        void DoSelectAllTest(DatabaseFlush& databaseFlush, const Version& version, const EntityContainer& entityContainer);
        void EqualTest(const Version& version, const EntityContainer& entityContainer);

    private:
        VersionContainer versionContainer;
    };
}

#endif  // DATABASE_GENERATE_BASE_TESTING_DATABASE_ENTITY_SUITE_VERSION_ENTITY_TESTING_H