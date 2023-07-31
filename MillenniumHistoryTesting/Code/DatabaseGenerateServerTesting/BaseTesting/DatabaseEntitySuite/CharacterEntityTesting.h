///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/26 22:58)

#ifndef DATABASE_GENERATE_SERVER_BASE_TESTING_DATABASE_ENTITY_SUITE_CHARACTER_ENTITY_TESTING_H
#define DATABASE_GENERATE_SERVER_BASE_TESTING_DATABASE_ENTITY_SUITE_CHARACTER_ENTITY_TESTING_H

#include "DatabaseEntityTesting.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/CharacterContainer.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/DatabaseEntity/DatabaseEntityFwd.h"
#include "Database/DatabaseInterface/DatabaseInterfaceFwd.h"

namespace DatabaseGenerateServerBaseTesting
{
    class CharacterEntityTesting final : public DatabaseEntityTesting
    {
    public:
        using ClassType = CharacterEntityTesting;
        using ParentType = DatabaseEntityTesting;

        using CharacterContainer = AncientBooks::CharacterContainer;

    public:
        CharacterEntityTesting(const OStreamShared& stream, const CharacterContainer& characterContainer);

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

#endif  // DATABASE_GENERATE_SERVER_BASE_TESTING_DATABASE_ENTITY_SUITE_CHARACTER_ENTITY_TESTING_H