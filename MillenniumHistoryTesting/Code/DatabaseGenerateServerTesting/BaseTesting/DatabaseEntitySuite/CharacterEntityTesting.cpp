///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.0 (2023/06/28 20:16)

#include "CharacterEntityTesting.h"
#include "DatabaseEntityTestingDetail.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/Character.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/CharacterContainerDetail.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/DatabaseEntity/CharacterEntity.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerCore/Helper/DatabaseGenerateServerCoreClassInvariantMacro.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Database/Configuration/ConfigurationStrategy.h"
#include "Database/DatabaseInterface/BasisDatabaseManager.h"
#include "Database/DatabaseInterface/DatabaseEnvironment.h"
#include "Database/DatabaseInterface/DatabaseFlush.h"

DatabaseGenerateServerBaseTesting::CharacterEntityTesting::CharacterEntityTesting(const OStreamShared& stream, const CharacterContainer& characterContainer)
    : ParentType{ stream }, characterContainer{ characterContainer }
{
    DATABASE_GENERATE_SERVER_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateServerBaseTesting, CharacterEntityTesting)

void DatabaseGenerateServerBaseTesting::CharacterEntityTesting::SelectOneTest(DatabaseFlush& databaseFlush)
{
    auto index = 0;
    for (const auto& character : characterContainer.GetContainer())
    {
        ASSERT_NOT_THROW_EXCEPTION_2(DoSelectOneTest, databaseFlush, *character);

        ++index;
        if (index == GetTestLoopCount())
        {
            break;
        }
    }

    databaseFlush.Wait();
}

void DatabaseGenerateServerBaseTesting::CharacterEntityTesting::SelectAllTest(DatabaseFlush& databaseFlush)
{
    const auto database = databaseFlush.SelectAll(CharacterEntity::GetSelectAll(databaseFlush.GetWrappersStrategy()),
                                                  CharacterEntity::GetDatabaseFieldContainer());

    const auto entityContainer = GetEntityContainer<int32_t, CharacterEntity>(database);

    for (const auto& character : characterContainer.GetContainer())
    {
        ASSERT_NOT_THROW_EXCEPTION_3(DoSelectAllTest, databaseFlush, *character, entityContainer);
    }

    databaseFlush.Wait();
}

void DatabaseGenerateServerBaseTesting::CharacterEntityTesting::SelectAllSizeTest(const DatabaseFlush& databaseFlush)
{
    const auto database = databaseFlush.SelectAll(CharacterEntity::GetSelectAll(databaseFlush.GetWrappersStrategy()),
                                                  CharacterEntity::GetDatabaseFieldContainer());

    ASSERT_EQUAL(boost::numeric_cast<int>(database.size()), characterContainer.GetContainerSize());

    const auto entityContainer = GetEntityContainer<int32_t, CharacterEntity>(database);

    for (const auto& character : characterContainer.GetContainer())
    {
        ASSERT_NOT_THROW_EXCEPTION_2(EqualTest, *character, entityContainer);
    }
}

void DatabaseGenerateServerBaseTesting::CharacterEntityTesting::SetEntity(CharacterEntity& characterEntity, const Character& character)
{
    characterEntity.SetCountry(character.GetCountry());
    characterEntity.SetIdentity(character.GetIdentity());
    characterEntity.SetFamily(CoreTools::StringConversion::StandardConversionUtf8(character.GetFamily()));
    characterEntity.SetName(CoreTools::StringConversion::StandardConversionUtf8(character.GetName()));
    characterEntity.SetFullName(CoreTools::StringConversion::StandardConversionUtf8(character.GetFullName()));
    characterEntity.SetAlias(Convert(character.GetAliasBegin(), character.GetAliasEnd()));
    characterEntity.SetStyleName(CoreTools::StringConversion::StandardConversionUtf8(character.GetStyleName()));
    characterEntity.SetSex(character.GetSex());
    characterEntity.SetFather(character.GetFather());
    characterEntity.SetMother(character.GetMother());
    characterEntity.SetFosterFather(character.GetFosterFather());
    characterEntity.SetFosterMother(character.GetFosterMother());
    characterEntity.SetBirthYear(character.GetBirthYear());
    characterEntity.SetBirthMonth(character.GetBirthMonth());
    characterEntity.SetBirthSexagenaryCycle(character.GetBirthSexagenaryCycle());
    characterEntity.SetBirthDay(character.GetBirthDay());
    characterEntity.SetDeathYear(character.GetDeathYear());
    characterEntity.SetDeathMonth(character.GetDeathMonth());
    characterEntity.SetDeathSexagenaryCycle(character.GetDeathSexagenaryCycle());
    characterEntity.SetDeathDay(character.GetDeathDay());
    characterEntity.SetUnansweredQuestion(Convert(character.GetUnansweredQuestionBegin(), character.GetUnansweredQuestionEnd()));
}

void DatabaseGenerateServerBaseTesting::CharacterEntityTesting::DoSelectOneTest(DatabaseFlush& databaseFlush, const Character& character)
{
    const auto database = databaseFlush.SelectOne(CharacterEntity::GetSelect(databaseFlush.GetWrappersStrategy(), character.GetId()),
                                                  CharacterEntity::GetDatabaseFieldContainer());

    auto characterEntity = CharacterEntity::Create(database, databaseFlush.GetWrappersStrategy(), character.GetId());

    ASSERT_NOT_THROW_EXCEPTION_2(SetEntity, characterEntity, character);

    databaseFlush.ChangeDatabase(character.GetId(), characterEntity.GetModify());
}

void DatabaseGenerateServerBaseTesting::CharacterEntityTesting::DoSelectAllTest(DatabaseFlush& databaseFlush, const Character& character, const EntityContainer& entityContainer)
{
    const auto result = entityContainer.find(character.GetId());
    auto characterEntity = result != entityContainer.cend() ? result->second : CharacterEntity{ databaseFlush.GetWrappersStrategy(), character.GetId() };

    ASSERT_NOT_THROW_EXCEPTION_2(SetEntity, characterEntity, character);

    databaseFlush.ChangeDatabase(character.GetId(), characterEntity.GetModify());
}

void DatabaseGenerateServerBaseTesting::CharacterEntityTesting::EqualTest(const Character& character, const EntityContainer& entityContainer)
{
    const auto result = entityContainer.find(character.GetId());

    ASSERT_UNEQUAL_FAILURE_THROW(result, entityContainer.cend(), "���ݿ���δ�ҵ���Ӧ���ݡ�id = " + std::to_string(character.GetId()));

    const auto& characterEntity = result->second;

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
