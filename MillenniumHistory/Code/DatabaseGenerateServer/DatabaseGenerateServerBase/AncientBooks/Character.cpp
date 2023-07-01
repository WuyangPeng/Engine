/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#include "AncientBooksContainer.h"
#include "Character.h"
#include "CharacterContainer.h"
#include "CountryContainer.h"
#include "DayContainer.h"
#include "IdentityContainer.h"
#include "MonthContainer.h"
#include "SexagenaryCycleContainer.h"
#include "YearContainer.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/TextParsing/CSV/CSVRowDetail.h"

using namespace std::literals;

AncientBooks::Character::Character(const CSVRow& csvRow)
    : ParentType{},
      id{ csvRow.GetInt(SYSTEM_TEXT("id"s)) },
      country{ csvRow.GetInt(SYSTEM_TEXT("country"s)) },
      identity{ csvRow.GetInt(SYSTEM_TEXT("identity"s)) },
      family{ csvRow.GetString(SYSTEM_TEXT("family"s)) },
      name{ csvRow.GetString(SYSTEM_TEXT("name"s)) },
      fullName{ csvRow.GetString(SYSTEM_TEXT("fullName"s)) },
      alias{ csvRow.GetStringArray(SYSTEM_TEXT("alias"s)) },
      styleName{ csvRow.GetString(SYSTEM_TEXT("styleName"s)) },
      sex{ csvRow.GetInt(SYSTEM_TEXT("sex"s)) },
      father{ csvRow.GetInt(SYSTEM_TEXT("father"s)) },
      mother{ csvRow.GetInt(SYSTEM_TEXT("mother"s)) },
      fosterFather{ csvRow.GetIntArray(SYSTEM_TEXT("fosterFather"s)) },
      fosterMother{ csvRow.GetIntArray(SYSTEM_TEXT("fosterMother"s)) },
      birthYear{ csvRow.GetInt(SYSTEM_TEXT("birthYear"s)) },
      birthMonth{ csvRow.GetInt(SYSTEM_TEXT("birthMonth"s)) },
      birthSexagenaryCycle{ csvRow.GetInt(SYSTEM_TEXT("birthSexagenaryCycle"s)) },
      birthDay{ csvRow.GetInt(SYSTEM_TEXT("birthDay"s)) },
      deathYear{ csvRow.GetInt(SYSTEM_TEXT("deathYear"s)) },
      deathMonth{ csvRow.GetInt(SYSTEM_TEXT("deathMonth"s)) },
      deathSexagenaryCycle{ csvRow.GetInt(SYSTEM_TEXT("deathSexagenaryCycle"s)) },
      deathDay{ csvRow.GetInt(SYSTEM_TEXT("deathDay"s)) },
      unansweredQuestion{ csvRow.GetStringArray(SYSTEM_TEXT("unansweredQuestion"s)) }
{
    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(AncientBooks, Character)

int AncientBooks::Character::GetKey() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return id;
}

int AncientBooks::Character::GetId() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return id;
}

int AncientBooks::Character::GetCountry() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return country;
}

AncientBooks::Character::ConstCountrySharedPtr AncientBooks::Character::GetCountry(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    return csvContainer.GetCountryContainer()->GetCountry(country);
}

int AncientBooks::Character::GetIdentity() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return identity;
}

AncientBooks::Character::ConstIdentitySharedPtr AncientBooks::Character::GetIdentity(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    return csvContainer.GetIdentityContainer()->GetIdentity(identity);
}

System::String AncientBooks::Character::GetFamily() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return family;
}

System::String AncientBooks::Character::GetName() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return name;
}

System::String AncientBooks::Character::GetFullName() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return fullName;
}

AncientBooks::Character::StringContainer AncientBooks::Character::GetAlias() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return alias;
}

int AncientBooks::Character::GetAliasCount() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(alias.size());
}

System::String AncientBooks::Character::GetAlias(int index) const
{
    USER_CLASS_IS_VALID_CONST_9;

    return alias.at(index);
}

AncientBooks::Character::StringContainerConstIter AncientBooks::Character::GetAliasBegin() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return alias.cbegin();
}

AncientBooks::Character::StringContainerConstIter AncientBooks::Character::GetAliasEnd() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return alias.cend();
}

System::String AncientBooks::Character::GetStyleName() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return styleName;
}

int AncientBooks::Character::GetSex() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return sex;
}

int AncientBooks::Character::GetFather() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return father;
}

AncientBooks::Character::ConstCharacterSharedPtr AncientBooks::Character::GetFather(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    return csvContainer.GetCharacterContainer()->GetCharacter(father);
}

int AncientBooks::Character::GetMother() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return mother;
}

AncientBooks::Character::ConstCharacterSharedPtr AncientBooks::Character::GetMother(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    return csvContainer.GetCharacterContainer()->GetCharacter(mother);
}

AncientBooks::Character::IntContainer AncientBooks::Character::GetFosterFather() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return fosterFather;
}

int AncientBooks::Character::GetFosterFatherCount() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(fosterFather.size());
}

int AncientBooks::Character::GetFosterFather(int index) const
{
    USER_CLASS_IS_VALID_CONST_9;

    return fosterFather.at(index);
}

AncientBooks::Character::IntContainerConstIter AncientBooks::Character::GetFosterFatherBegin() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return fosterFather.cbegin();
}

AncientBooks::Character::IntContainerConstIter AncientBooks::Character::GetFosterFatherEnd() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return fosterFather.cend();
}

AncientBooks::Character::CharacterContainer AncientBooks::Character::GetFosterFather(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    CharacterContainer result{};

    const auto container = csvContainer.GetCharacterContainer();

    for (const auto& element : fosterFather)
    {
        result.emplace_back(container->GetCharacter(element));
    }

    return result;
}

AncientBooks::Character::IntContainer AncientBooks::Character::GetFosterMother() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return fosterMother;
}

int AncientBooks::Character::GetFosterMotherCount() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(fosterMother.size());
}

int AncientBooks::Character::GetFosterMother(int index) const
{
    USER_CLASS_IS_VALID_CONST_9;

    return fosterMother.at(index);
}

AncientBooks::Character::IntContainerConstIter AncientBooks::Character::GetFosterMotherBegin() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return fosterMother.cbegin();
}

AncientBooks::Character::IntContainerConstIter AncientBooks::Character::GetFosterMotherEnd() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return fosterMother.cend();
}

AncientBooks::Character::CharacterContainer AncientBooks::Character::GetFosterMother(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    CharacterContainer result{};

    const auto container = csvContainer.GetCharacterContainer();

    for (const auto& element : fosterMother)
    {
        result.emplace_back(container->GetCharacter(element));
    }

    return result;
}

int AncientBooks::Character::GetBirthYear() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return birthYear;
}

AncientBooks::Character::ConstYearSharedPtr AncientBooks::Character::GetBirthYear(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    return csvContainer.GetYearContainer()->GetYear(birthYear);
}

int AncientBooks::Character::GetBirthMonth() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return birthMonth;
}

AncientBooks::Character::ConstMonthSharedPtr AncientBooks::Character::GetBirthMonth(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    return csvContainer.GetMonthContainer()->GetMonth(birthMonth);
}

int AncientBooks::Character::GetBirthSexagenaryCycle() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return birthSexagenaryCycle;
}

AncientBooks::Character::ConstSexagenaryCycleSharedPtr AncientBooks::Character::GetBirthSexagenaryCycle(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    return csvContainer.GetSexagenaryCycleContainer()->GetSexagenaryCycle(birthSexagenaryCycle);
}

int AncientBooks::Character::GetBirthDay() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return birthDay;
}

AncientBooks::Character::ConstDaySharedPtr AncientBooks::Character::GetBirthDay(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    return csvContainer.GetDayContainer()->GetDay(birthDay);
}

int AncientBooks::Character::GetDeathYear() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return deathYear;
}

AncientBooks::Character::ConstYearSharedPtr AncientBooks::Character::GetDeathYear(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    return csvContainer.GetYearContainer()->GetYear(deathYear);
}

int AncientBooks::Character::GetDeathMonth() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return deathMonth;
}

AncientBooks::Character::ConstMonthSharedPtr AncientBooks::Character::GetDeathMonth(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    return csvContainer.GetMonthContainer()->GetMonth(deathMonth);
}

int AncientBooks::Character::GetDeathSexagenaryCycle() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return deathSexagenaryCycle;
}

AncientBooks::Character::ConstSexagenaryCycleSharedPtr AncientBooks::Character::GetDeathSexagenaryCycle(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    return csvContainer.GetSexagenaryCycleContainer()->GetSexagenaryCycle(deathSexagenaryCycle);
}

int AncientBooks::Character::GetDeathDay() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return deathDay;
}

AncientBooks::Character::ConstDaySharedPtr AncientBooks::Character::GetDeathDay(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    return csvContainer.GetDayContainer()->GetDay(deathDay);
}

AncientBooks::Character::StringContainer AncientBooks::Character::GetUnansweredQuestion() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return unansweredQuestion;
}

int AncientBooks::Character::GetUnansweredQuestionCount() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(unansweredQuestion.size());
}

System::String AncientBooks::Character::GetUnansweredQuestion(int index) const
{
    USER_CLASS_IS_VALID_CONST_9;

    return unansweredQuestion.at(index);
}

AncientBooks::Character::StringContainerConstIter AncientBooks::Character::GetUnansweredQuestionBegin() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return unansweredQuestion.cbegin();
}

AncientBooks::Character::StringContainerConstIter AncientBooks::Character::GetUnansweredQuestionEnd() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return unansweredQuestion.cend();
}

