/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#include "CharacterBase.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

AncientBooks::CharacterBase::CharacterBase(int key) noexcept
    : key{ key }
{
    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(AncientBooks, CharacterBase)

int AncientBooks::CharacterBase::GetKey() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return key;
}

int AncientBooks::CharacterBase::GetId() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

int AncientBooks::CharacterBase::GetCountry() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

std::shared_ptr<const AncientBooks::CountryMappingType> AncientBooks::CharacterBase::GetCountry(MAYBE_UNUSED const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("character表基类不允许获取映射值。"s))
}

int AncientBooks::CharacterBase::GetIdentity() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

std::shared_ptr<const AncientBooks::IdentityMappingType> AncientBooks::CharacterBase::GetIdentity(MAYBE_UNUSED const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("character表基类不允许获取映射值。"s))
}

System::String AncientBooks::CharacterBase::GetFamily() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("character表基类不允许获取字符串。"s))
}

System::String AncientBooks::CharacterBase::GetName() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("character表基类不允许获取字符串。"s))
}

System::String AncientBooks::CharacterBase::GetFullName() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("character表基类不允许获取字符串。"s))
}

std::vector<System::String> AncientBooks::CharacterBase::GetAlias() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("character表基类不允许获取数组。"s))
}

int AncientBooks::CharacterBase::GetAliasCount() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("character表基类不允许获取数组。"s))
}

System::String AncientBooks::CharacterBase::GetAlias(MAYBE_UNUSED int index) const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("character表基类不允许获取数组。"s))
}

std::vector<System::String>::const_iterator AncientBooks::CharacterBase::GetAliasBegin() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("character表基类不允许获取数组。"s))
}

std::vector<System::String>::const_iterator AncientBooks::CharacterBase::GetAliasEnd() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("character表基类不允许获取数组。"s))
}

System::String AncientBooks::CharacterBase::GetStyleName() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("character表基类不允许获取字符串。"s))
}

int AncientBooks::CharacterBase::GetSex() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

int AncientBooks::CharacterBase::GetFather() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

int AncientBooks::CharacterBase::GetMother() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

std::vector<int> AncientBooks::CharacterBase::GetFosterFather() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("character表基类不允许获取数组。"s))
}

int AncientBooks::CharacterBase::GetFosterFatherCount() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("character表基类不允许获取数组。"s))
}

int AncientBooks::CharacterBase::GetFosterFather(MAYBE_UNUSED int index) const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("character表基类不允许获取数组。"s))
}

std::vector<int>::const_iterator AncientBooks::CharacterBase::GetFosterFatherBegin() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("character表基类不允许获取数组。"s))
}

std::vector<int>::const_iterator AncientBooks::CharacterBase::GetFosterFatherEnd() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("character表基类不允许获取数组。"s))
}

std::vector<int> AncientBooks::CharacterBase::GetFosterMother() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("character表基类不允许获取数组。"s))
}

int AncientBooks::CharacterBase::GetFosterMotherCount() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("character表基类不允许获取数组。"s))
}

int AncientBooks::CharacterBase::GetFosterMother(MAYBE_UNUSED int index) const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("character表基类不允许获取数组。"s))
}

std::vector<int>::const_iterator AncientBooks::CharacterBase::GetFosterMotherBegin() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("character表基类不允许获取数组。"s))
}

std::vector<int>::const_iterator AncientBooks::CharacterBase::GetFosterMotherEnd() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("character表基类不允许获取数组。"s))
}

int AncientBooks::CharacterBase::GetBirthYear() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

std::shared_ptr<const AncientBooks::YearMappingType> AncientBooks::CharacterBase::GetBirthYear(MAYBE_UNUSED const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("character表基类不允许获取映射值。"s))
}

int AncientBooks::CharacterBase::GetBirthMonth() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

std::shared_ptr<const AncientBooks::MonthMappingType> AncientBooks::CharacterBase::GetBirthMonth(MAYBE_UNUSED const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("character表基类不允许获取映射值。"s))
}

int AncientBooks::CharacterBase::GetBirthSexagenaryCycle() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

std::shared_ptr<const AncientBooks::SexagenaryCycleMappingType> AncientBooks::CharacterBase::GetBirthSexagenaryCycle(MAYBE_UNUSED const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("character表基类不允许获取映射值。"s))
}

int AncientBooks::CharacterBase::GetBirthDay() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

std::shared_ptr<const AncientBooks::DayMappingType> AncientBooks::CharacterBase::GetBirthDay(MAYBE_UNUSED const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("character表基类不允许获取映射值。"s))
}

int AncientBooks::CharacterBase::GetDeathYear() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

std::shared_ptr<const AncientBooks::YearMappingType> AncientBooks::CharacterBase::GetDeathYear(MAYBE_UNUSED const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("character表基类不允许获取映射值。"s))
}

int AncientBooks::CharacterBase::GetDeathMonth() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

std::shared_ptr<const AncientBooks::MonthMappingType> AncientBooks::CharacterBase::GetDeathMonth(MAYBE_UNUSED const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("character表基类不允许获取映射值。"s))
}

int AncientBooks::CharacterBase::GetDeathSexagenaryCycle() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

std::shared_ptr<const AncientBooks::SexagenaryCycleMappingType> AncientBooks::CharacterBase::GetDeathSexagenaryCycle(MAYBE_UNUSED const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("character表基类不允许获取映射值。"s))
}

int AncientBooks::CharacterBase::GetDeathDay() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

std::shared_ptr<const AncientBooks::DayMappingType> AncientBooks::CharacterBase::GetDeathDay(MAYBE_UNUSED const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("character表基类不允许获取映射值。"s))
}

std::vector<System::String> AncientBooks::CharacterBase::GetUnansweredQuestion() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("character表基类不允许获取数组。"s))
}

int AncientBooks::CharacterBase::GetUnansweredQuestionCount() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("character表基类不允许获取数组。"s))
}

System::String AncientBooks::CharacterBase::GetUnansweredQuestion(MAYBE_UNUSED int index) const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("character表基类不允许获取数组。"s))
}

std::vector<System::String>::const_iterator AncientBooks::CharacterBase::GetUnansweredQuestionBegin() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("character表基类不允许获取数组。"s))
}

std::vector<System::String>::const_iterator AncientBooks::CharacterBase::GetUnansweredQuestionEnd() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("character表基类不允许获取数组。"s))
}

