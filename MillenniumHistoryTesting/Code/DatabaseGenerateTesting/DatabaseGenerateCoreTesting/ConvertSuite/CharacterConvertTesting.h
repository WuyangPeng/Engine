/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/11/30 22:47)

#ifndef DATABASE_GENERATE_CORE_TESTING_DATABASE_ENTITY_SUITE_CHARACTER_CONVERT_TESTING_H
#define DATABASE_GENERATE_CORE_TESTING_DATABASE_ENTITY_SUITE_CHARACTER_CONVERT_TESTING_H

#include "ConvertTesting.h"
#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/CharacterContainer.h"
#include "DatabaseGenerate/DatabaseGenerateBase/DatabaseEntity/DatabaseEntityFwd.h"

namespace DatabaseGenerateCoreTesting
{
    class CharacterConvertTesting final : public ConvertTesting
    {
    public:
        using ClassType = CharacterConvertTesting;
        using ParentType = ConvertTesting;

        using CharacterContainer = AncientBooks::CharacterContainer;

    public:
        CharacterConvertTesting(const OStreamShared& stream, const CharacterContainer& characterContainer);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        using Character = AncientBooks::CharacterBase;
        using CharacterEntity = DatabaseEntity::CharacterEntity;

    private:
        void ConvertTest(const DatabaseFlushSharedPtr& databaseFlush) override;
        void EqualTest(const Character& character, const CharacterEntity& characterEntity);

    private:
        CharacterContainer characterContainer;
    };
}

#endif  // DATABASE_GENERATE_CORE_TESTING_DATABASE_ENTITY_SUITE_CHARACTER_CONVERT_TESTING_H