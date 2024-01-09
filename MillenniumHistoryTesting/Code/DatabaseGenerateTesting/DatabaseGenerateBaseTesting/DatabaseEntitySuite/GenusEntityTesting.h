/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.3 (2023/12/23 22:20)

#ifndef DATABASE_GENERATE_BASE_TESTING_DATABASE_ENTITY_SUITE_GENUS_ENTITY_TESTING_H
#define DATABASE_GENERATE_BASE_TESTING_DATABASE_ENTITY_SUITE_GENUS_ENTITY_TESTING_H

#include "DatabaseEntityTesting.h"
#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/GenusContainer.h"

namespace DatabaseGenerateBaseTesting
{
    class GenusEntityTesting final : public DatabaseEntityTesting
    {
    public:
        using ClassType = GenusEntityTesting;
        using ParentType = DatabaseEntityTesting;

        using GenusContainer = AncientBooks::GenusContainer;

    public:
        GenusEntityTesting(const OStreamShared& stream, GenusContainer genusContainer);

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

#endif  // DATABASE_GENERATE_BASE_TESTING_DATABASE_ENTITY_SUITE_GENUS_ENTITY_TESTING_H