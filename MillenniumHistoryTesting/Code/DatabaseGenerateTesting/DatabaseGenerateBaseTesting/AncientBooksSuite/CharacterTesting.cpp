/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/11/30 22:35)

#include "CharacterTesting.h"
#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/Character.h"
#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/CharacterContainerDetail.h"
#include "DatabaseGenerate/DatabaseGenerateCore/Helper/DatabaseGenerateCoreClassInvariantMacro.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

DatabaseGenerateBaseTesting::CharacterTesting::CharacterTesting(const OStreamShared& stream, const AncientBooksContainer& ancientBooksContainer)
    : ParentType{ stream },
      ancientBooksContainer{ ancientBooksContainer },
      characterContainer{ ancientBooksContainer.GetCharacterContainer() }
{
    DATABASE_GENERATE_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateBaseTesting, CharacterTesting)

void DatabaseGenerateBaseTesting::CharacterTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void DatabaseGenerateBaseTesting::CharacterTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MappingTest);
    ASSERT_NOT_THROW_EXCEPTION_0(EffectiveTest);
}

void DatabaseGenerateBaseTesting::CharacterTesting::MappingTest()
{
    for (const auto& character : characterContainer->GetContainer())
    {
        ASSERT_NOT_THROW_EXCEPTION_1(CountryMappingTest, *character);
        ASSERT_NOT_THROW_EXCEPTION_1(IdentityMappingTest, *character);
        ASSERT_NOT_THROW_EXCEPTION_1(ParentsMappingTest, *character);
        ASSERT_NOT_THROW_EXCEPTION_1(BirthMappingTest, *character);
        ASSERT_NOT_THROW_EXCEPTION_1(DeathMappingTest, *character);
    }
}

void DatabaseGenerateBaseTesting::CharacterTesting::CountryMappingTest(const Character& character)
{
    if (character.GetId() != 80000)
    {
        ASSERT_GREATER(character.GetCountry(), 0);
        ASSERT_UNEQUAL_NULL_PTR(character.GetCountry(ancientBooksContainer));
    }
}

void DatabaseGenerateBaseTesting::CharacterTesting::IdentityMappingTest(const Character& character)
{
    ASSERT_GREATER(character.GetIdentity(), 0);
    ASSERT_UNEQUAL_NULL_PTR(character.GetIdentity(ancientBooksContainer));
}

void DatabaseGenerateBaseTesting::CharacterTesting::ParentsMappingTest(const Character& character)
{
    if (0 < character.GetFather())
    {
        ASSERT_UNEQUAL_NULL_PTR(character.GetFather(ancientBooksContainer));
    }

    if (0 < character.GetMother())
    {
        ASSERT_UNEQUAL_NULL_PTR(character.GetMother(ancientBooksContainer));
    }

    ASSERT_EQUAL(character.GetFosterFather().size(), character.GetFosterFather(ancientBooksContainer).size());
    ASSERT_EQUAL(character.GetFosterMother().size(), character.GetFosterMother(ancientBooksContainer).size());
}

void DatabaseGenerateBaseTesting::CharacterTesting::BirthMappingTest(const Character& character)
{
    if (0 < character.GetBirthYear())
    {
        ASSERT_UNEQUAL_NULL_PTR(character.GetBirthYear(ancientBooksContainer));
    }

    if (0 < character.GetBirthMonth())
    {
        ASSERT_UNEQUAL_NULL_PTR(character.GetBirthMonth(ancientBooksContainer));
    }

    if (0 < character.GetBirthSexagenaryCycle())
    {
        ASSERT_UNEQUAL_NULL_PTR(character.GetBirthSexagenaryCycle(ancientBooksContainer));
    }

    if (0 < character.GetBirthDay())
    {
        ASSERT_UNEQUAL_NULL_PTR(character.GetBirthDay(ancientBooksContainer));
    }
}

void DatabaseGenerateBaseTesting::CharacterTesting::DeathMappingTest(const Character& character)
{
    if (0 < character.GetDeathYear())
    {
        ASSERT_UNEQUAL_NULL_PTR(character.GetDeathYear(ancientBooksContainer));
    }

    if (0 < character.GetDeathMonth())
    {
        ASSERT_UNEQUAL_NULL_PTR(character.GetDeathMonth(ancientBooksContainer));
    }

    if (0 < character.GetDeathSexagenaryCycle())
    {
        ASSERT_UNEQUAL_NULL_PTR(character.GetDeathSexagenaryCycle(ancientBooksContainer));
    }

    if (0 < character.GetDeathDay())
    {
        ASSERT_UNEQUAL_NULL_PTR(character.GetDeathDay(ancientBooksContainer));
    }
}

void DatabaseGenerateBaseTesting::CharacterTesting::EffectiveTest()
{
    for (const auto& character : characterContainer->GetContainer())
    {
        ASSERT_NOT_THROW_EXCEPTION_1(FullNameTest, *character);
        ASSERT_NOT_THROW_EXCEPTION_1(UnansweredQuestionTest, *character);
        ASSERT_NOT_THROW_EXCEPTION_1(IdTest, *character);
        ASSERT_NOT_THROW_EXCEPTION_1(SexTest, *character);
    }
}

void DatabaseGenerateBaseTesting::CharacterTesting::FullNameTest(const Character& character)
{
    ASSERT_EQUAL(character.GetFamily() + character.GetName(), character.GetFullName());
}

void DatabaseGenerateBaseTesting::CharacterTesting::UnansweredQuestionTest(const Character& character)
{
    const auto unansweredQuestion = character.GetUnansweredQuestion();

    for (const auto& element : unansweredQuestion)
    {
        ASSERT_TRUE(element == SYSTEM_TEXT("family") ||
                    element == SYSTEM_TEXT("name") ||
                    element == SYSTEM_TEXT("fullName") ||
                    element == SYSTEM_TEXT("alias") ||
                    element == SYSTEM_TEXT("styleName") ||
                    element == SYSTEM_TEXT("father") ||
                    element == SYSTEM_TEXT("mother") ||
                    element == SYSTEM_TEXT("fosterFather") ||
                    element == SYSTEM_TEXT("fosterMother") ||
                    element == SYSTEM_TEXT("birthYear") ||
                    element == SYSTEM_TEXT("birthMonth") ||
                    element == SYSTEM_TEXT("birthSexagenaryCycle") ||
                    element == SYSTEM_TEXT("birthDay") ||
                    element == SYSTEM_TEXT("deathYear") ||
                    element == SYSTEM_TEXT("deathMonth") ||
                    element == SYSTEM_TEXT("deathSexagenaryCycle") ||
                    element == SYSTEM_TEXT("deathDay"));
    }
}

void DatabaseGenerateBaseTesting::CharacterTesting::IdTest(const Character& character)
{
    ASSERT_EQUAL(character.GetId() / 100000, character.GetCountry());
    ASSERT_EQUAL((character.GetId() / 10000) % 10, character.GetIdentity());
}

void DatabaseGenerateBaseTesting::CharacterTesting::SexTest(const Character& character)
{
    if (character.GetIdentity() != 9)
    {
        ASSERT_EQUAL(character.GetSex(), 1);
    }
    else
    {
        ASSERT_EQUAL(character.GetSex(), 2);
    }
}
