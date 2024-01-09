/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/23 22:20)

#ifndef DATABASE_GENERATE_BASE_TESTING_DATABASE_ENTITY_SUITE_IDENTITY_ENTITY_TESTING_H
#define DATABASE_GENERATE_BASE_TESTING_DATABASE_ENTITY_SUITE_IDENTITY_ENTITY_TESTING_H

#include "DatabaseEntityTesting.h"
#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/IdentityContainer.h"

namespace DatabaseGenerateBaseTesting
{
    class IdentityEntityTesting final : public DatabaseEntityTesting
    {
    public:
        using ClassType = IdentityEntityTesting;
        using ParentType = DatabaseEntityTesting;

        using IdentityContainer = AncientBooks::IdentityContainer;

    public:
        IdentityEntityTesting(const OStreamShared& stream, IdentityContainer identityContainer);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        using Identity = AncientBooks::IdentityBase;
        using IdentityEntity = DatabaseEntity::IdentityEntity;
        using EntityContainer = std::map<int32_t, IdentityEntity>;

    private:
        void SelectOneTest(DatabaseFlush& databaseFlush) override;
        void SelectAllTest(DatabaseFlush& databaseFlush) override;
        void SelectAllSizeTest(const DatabaseFlush& databaseFlush) override;

        void SetEntity(IdentityEntity& identityEntity, const Identity& identity);

        void DoSelectOneTest(DatabaseFlush& databaseFlush, const Identity& identity);
        void DoSelectAllTest(DatabaseFlush& databaseFlush, const Identity& identity, const EntityContainer& entityContainer);
        void EqualTest(const Identity& identity, const EntityContainer& entityContainer);

    private:
        IdentityContainer identityContainer;
    };
}

#endif  // DATABASE_GENERATE_BASE_TESTING_DATABASE_ENTITY_SUITE_IDENTITY_ENTITY_TESTING_H