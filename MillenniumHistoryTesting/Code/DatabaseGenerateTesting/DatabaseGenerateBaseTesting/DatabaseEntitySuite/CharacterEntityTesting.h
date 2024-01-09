/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/23 22:19)

#ifndef DATABASE_GENERATE_BASE_TESTING_DATABASE_ENTITY_SUITE_CHARACTER_ENTITY_TESTING_H
#define DATABASE_GENERATE_BASE_TESTING_DATABASE_ENTITY_SUITE_CHARACTER_ENTITY_TESTING_H

#include "DatabaseEntityTesting.h"
#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/CharacterContainer.h"
#include "DatabaseGenerate/DatabaseGenerateBase/DatabaseEntity/DatabaseEntityFwd.h"

namespace DatabaseGenerateBaseTesting
{
    class CharacterEntityTesting final : public DatabaseEntityTesting
    {
    public:
        using ClassType = CharacterEntityTesting;
        using ParentType = DatabaseEntityTesting;

        using CharacterContainer = AncientBooks::CharacterContainer;

    public:
        CharacterEntityTesting(const OStreamShared& stream, CharacterContainer characterContainer);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        using Character = AncientBooks::CharacterBase;
        using CharacterEntity = DatabaseEntity::CharacterEntity;
        using EntityContainer = std::map<int32_t, CharacterEntity>;

    private:
        void SelectOneTest(DatabaseFlush& databaseFlush) override;
        void SelectAllTest(DatabaseFlush& databaseFlush) override;
        void SelectAllSizeTest(const DatabaseFlush& databaseFlush) override;

        void SetEntity(CharacterEntity& characterEntity, const Character& character);

        void DoSelectOneTest(DatabaseFlush& databaseFlush, const Character& character);
        void DoSelectAllTest(DatabaseFlush& databaseFlush, const Character& character, const EntityContainer& entityContainer);
        void EqualTest(const Character& character, const EntityContainer& entityContainer);

    private:
        CharacterContainer characterContainer;
    };
}

#endif  // DATABASE_GENERATE_BASE_TESTING_DATABASE_ENTITY_SUITE_CHARACTER_ENTITY_TESTING_H