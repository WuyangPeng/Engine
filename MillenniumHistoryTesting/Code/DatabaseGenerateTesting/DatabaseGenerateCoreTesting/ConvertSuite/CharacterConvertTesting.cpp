/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/25 22:17)

#include "CharacterConvertTesting.h"
#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/Character.h"
#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/CharacterContainerDetail.h"
#include "DatabaseGenerate/DatabaseGenerateBase/DatabaseEntity/CharacterEntity.h"
#include "DatabaseGenerate/DatabaseGenerateCore/Convert/ConvertEntity.h"
#include "DatabaseGenerate/DatabaseGenerateCore/Helper/DatabaseGenerateCoreClassInvariantMacro.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

DatabaseGenerateCoreTesting::CharacterConvertTesting::CharacterConvertTesting(const OStreamShared& stream, CharacterContainer characterContainer)
    : ParentType{ stream }, characterContainer{ std::move(characterContainer) }
{
    DATABASE_GENERATE_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateCoreTesting, CharacterConvertTesting)

void DatabaseGenerateCoreTesting::CharacterConvertTesting::ConvertTest(const DatabaseFlushSharedPtr& databaseFlush)
{
    DatabaseGenerateCore::ConvertEntity convertEntity{ databaseFlush };

    for (const auto& character : characterContainer.GetContainer())
    {
        const auto characterEntity = convertEntity.Convert(*character);

        ASSERT_NOT_THROW_EXCEPTION_2(EqualTest, *character, characterEntity);
    }
}

void DatabaseGenerateCoreTesting::CharacterConvertTesting::EqualTest(const Character& character, const CharacterEntity& characterEntity)
{
    ASSERT_EQUAL(characterEntity.GetCountry(), character.GetCountry());
    ASSERT_EQUAL(characterEntity.GetIdentity(), character.GetIdentity());
    ASSERT_EQUAL(characterEntity.GetFamily(), CoreTools::StringConversion::StandardConversionUtf8(character.GetFamily()));
    ASSERT_EQUAL(characterEntity.GetName(), CoreTools::StringConversion::StandardConversionUtf8(character.GetName()));
    ASSERT_EQUAL(characterEntity.GetFullName(), CoreTools::StringConversion::StandardConversionUtf8(character.GetFullName()));
    ASSERT_EQUAL(characterEntity.GetAlias(), Convert(character.GetAliasBegin(), character.GetAliasEnd()));
    ASSERT_EQUAL(characterEntity.GetStyleName(), CoreTools::StringConversion::StandardConversionUtf8(character.GetStyleName()));
    ASSERT_EQUAL(characterEntity.GetSex(), character.GetSex());
    ASSERT_EQUAL(characterEntity.GetFather(), character.GetFather());
    ASSERT_EQUAL(characterEntity.GetMother(), character.GetMother());
    ASSERT_EQUAL(characterEntity.GetFosterFather(), character.GetFosterFather());
    ASSERT_EQUAL(characterEntity.GetFosterMother(), character.GetFosterMother());
    ASSERT_EQUAL(characterEntity.GetBirthYear(), character.GetBirthYear());
    ASSERT_EQUAL(characterEntity.GetBirthMonth(), character.GetBirthMonth());
    ASSERT_EQUAL(characterEntity.GetBirthSexagenaryCycle(), character.GetBirthSexagenaryCycle());
    ASSERT_EQUAL(characterEntity.GetBirthDay(), character.GetBirthDay());
    ASSERT_EQUAL(characterEntity.GetDeathYear(), character.GetDeathYear());
    ASSERT_EQUAL(characterEntity.GetDeathMonth(), character.GetDeathMonth());
    ASSERT_EQUAL(characterEntity.GetDeathSexagenaryCycle(), character.GetDeathSexagenaryCycle());
    ASSERT_EQUAL(characterEntity.GetDeathDay(), character.GetDeathDay());
    ASSERT_EQUAL(characterEntity.GetUnansweredQuestion(), Convert(character.GetUnansweredQuestionBegin(), character.GetUnansweredQuestionEnd()));
}
