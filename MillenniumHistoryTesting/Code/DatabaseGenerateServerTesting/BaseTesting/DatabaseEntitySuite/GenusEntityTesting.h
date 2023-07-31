///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/27 21:51)

#ifndef DATABASE_GENERATE_SERVER_BASE_TESTING_DATABASE_ENTITY_SUITE_GENUS_ENTITY_TESTING_H
#define DATABASE_GENERATE_SERVER_BASE_TESTING_DATABASE_ENTITY_SUITE_GENUS_ENTITY_TESTING_H

#include "DatabaseEntityTesting.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/GenusContainer.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/DatabaseEntity/DatabaseEntityFwd.h"
#include "Database/DatabaseInterface/DatabaseInterfaceFwd.h"

namespace DatabaseGenerateServerBaseTesting
{
    class GenusEntityTesting final : public DatabaseEntityTesting
    {
    public:
        using ClassType = GenusEntityTesting;
        using ParentType = DatabaseEntityTesting;

        using GenusContainer = AncientBooks::GenusContainer;

    public:
        GenusEntityTesting(const OStreamShared& stream, const GenusContainer& genusContainer);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private: 
        using Genus = AncientBooks::GenusBase;
        using GenusEntity = DatabaseEntity::GenusEntity;
        using EntityContainer = std::map<int32_t, GenusEntity>;

    private:
        void SelectOneTest(DatabaseFlush& databaseFlush) override;
        void SelectAllTest(DatabaseFlush& databaseFlush) override;
        void SelectAllSizeTest(const DatabaseFlush& databaseFlush) override;

        void SetEntity(GenusEntity& genusEntity, const Genus& genus);

        void DoSelectOneTest(DatabaseFlush& databaseFlush, const Genus& genus);
        void DoSelectAllTest(DatabaseFlush& databaseFlush, const Genus& genus, const EntityContainer& entityContainer);
        void EqualTest(const Genus& genus, const EntityContainer& entityContainer);

    private:
        GenusContainer genusContainer;
    };
}

#endif  // DATABASE_GENERATE_SERVER_BASE_TESTING_DATABASE_ENTITY_SUITE_GENUS_ENTITY_TESTING_H