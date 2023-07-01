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

AncientBooks::CharacterBase::ConstCountrySharedPtr AncientBooks::CharacterBase::GetCountry(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(csvContainer);

    THROW_EXCEPTION(SYSTEM_TEXT("character表基类不允许获取映射值。"s))
}

int AncientBooks::CharacterBase::GetIdentity() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

AncientBooks::CharacterBase::ConstIdentitySharedPtr AncientBooks::CharacterBase::GetIdentity(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(csvContainer);

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

AncientBooks::CharacterBase::StringContainer AncientBooks::CharacterBase::GetAlias() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("character表基类不允许获取数组。"s))
}

int AncientBooks::CharacterBase::GetAliasCount() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("character表基类不允许获取数组。"s))
}

System::String AncientBooks::CharacterBase::GetAlias(int index) const
{
    USER_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(index);

    THROW_EXCEPTION(SYSTEM_TEXT("character表基类不允许获取数组。"s))
}

AncientBooks::CharacterBase::StringContainerConstIter AncientBooks::CharacterBase::GetAliasBegin() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("character表基类不允许获取数组。"s))
}

AncientBooks::CharacterBase::StringContainerConstIter AncientBooks::CharacterBase::GetAliasEnd() const
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

AncientBooks::CharacterBase::ConstCharacterSharedPtr AncientBooks::CharacterBase::GetFather(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(csvContainer);

    THROW_EXCEPTION(SYSTEM_TEXT("character表基类不允许获取映射值。"s))
}

int AncientBooks::CharacterBase::GetMother() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

AncientBooks::CharacterBase::ConstCharacterSharedPtr AncientBooks::CharacterBase::GetMother(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(csvContainer);

    THROW_EXCEPTION(SYSTEM_TEXT("character表基类不允许获取映射值。"s))
}

AncientBooks::CharacterBase::IntContainer AncientBooks::CharacterBase::GetFosterFather() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("character表基类不允许获取数组。"s))
}

int AncientBooks::CharacterBase::GetFosterFatherCount() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("character表基类不允许获取数组。"s))
}

int AncientBooks::CharacterBase::GetFosterFather(int index) const
{
    USER_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(index);

    THROW_EXCEPTION(SYSTEM_TEXT("character表基类不允许获取数组。"s))
}

AncientBooks::CharacterBase::IntContainerConstIter AncientBooks::CharacterBase::GetFosterFatherBegin() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("character表基类不允许获取数组。"s))
}

AncientBooks::CharacterBase::IntContainerConstIter AncientBooks::CharacterBase::GetFosterFatherEnd() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("character表基类不允许获取数组。"s))
}

AncientBooks::CharacterBase::CharacterContainer AncientBooks::CharacterBase::GetFosterFather(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(csvContainer);

    THROW_EXCEPTION(SYSTEM_TEXT("character表基类不允许获取映射值。"s))
}

AncientBooks::CharacterBase::IntContainer AncientBooks::CharacterBase::GetFosterMother() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("character表基类不允许获取数组。"s))
}

int AncientBooks::CharacterBase::GetFosterMotherCount() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("character表基类不允许获取数组。"s))
}

int AncientBooks::CharacterBase::GetFosterMother(int index) const
{
    USER_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(index);

    THROW_EXCEPTION(SYSTEM_TEXT("character表基类不允许获取数组。"s))
}

AncientBooks::CharacterBase::IntContainerConstIter AncientBooks::CharacterBase::GetFosterMotherBegin() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("character表基类不允许获取数组。"s))
}

AncientBooks::CharacterBase::IntContainerConstIter AncientBooks::CharacterBase::GetFosterMotherEnd() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("character表基类不允许获取数组。"s))
}

AncientBooks::CharacterBase::CharacterContainer AncientBooks::CharacterBase::GetFosterMother(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(csvContainer);

    THROW_EXCEPTION(SYSTEM_TEXT("character表基类不允许获取映射值。"s))
}

int AncientBooks::CharacterBase::GetBirthYear() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

AncientBooks::CharacterBase::ConstYearSharedPtr AncientBooks::CharacterBase::GetBirthYear(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(csvContainer);

    THROW_EXCEPTION(SYSTEM_TEXT("character表基类不允许获取映射值。"s))
}

int AncientBooks::CharacterBase::GetBirthMonth() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

AncientBooks::CharacterBase::ConstMonthSharedPtr AncientBooks::CharacterBase::GetBirthMonth(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(csvContainer);

    THROW_EXCEPTION(SYSTEM_TEXT("character表基类不允许获取映射值。"s))
}

int AncientBooks::CharacterBase::GetBirthSexagenaryCycle() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

AncientBooks::CharacterBase::ConstSexagenaryCycleSharedPtr AncientBooks::CharacterBase::GetBirthSexagenaryCycle(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(csvContainer);

    THROW_EXCEPTION(SYSTEM_TEXT("character表基类不允许获取映射值。"s))
}

int AncientBooks::CharacterBase::GetBirthDay() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

AncientBooks::CharacterBase::ConstDaySharedPtr AncientBooks::CharacterBase::GetBirthDay(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(csvContainer);

    THROW_EXCEPTION(SYSTEM_TEXT("character表基类不允许获取映射值。"s))
}

int AncientBooks::CharacterBase::GetDeathYear() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

AncientBooks::CharacterBase::ConstYearSharedPtr AncientBooks::CharacterBase::GetDeathYear(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(csvContainer);

    THROW_EXCEPTION(SYSTEM_TEXT("character表基类不允许获取映射值。"s))
}

int AncientBooks::CharacterBase::GetDeathMonth() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

AncientBooks::CharacterBase::ConstMonthSharedPtr AncientBooks::CharacterBase::GetDeathMonth(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(csvContainer);

    THROW_EXCEPTION(SYSTEM_TEXT("character表基类不允许获取映射值。"s))
}

int AncientBooks::CharacterBase::GetDeathSexagenaryCycle() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

AncientBooks::CharacterBase::ConstSexagenaryCycleSharedPtr AncientBooks::CharacterBase::GetDeathSexagenaryCycle(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(csvContainer);

    THROW_EXCEPTION(SYSTEM_TEXT("character表基类不允许获取映射值。"s))
}

int AncientBooks::CharacterBase::GetDeathDay() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

AncientBooks::CharacterBase::ConstDaySharedPtr AncientBooks::CharacterBase::GetDeathDay(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(csvContainer);

    THROW_EXCEPTION(SYSTEM_TEXT("character表基类不允许获取映射值。"s))
}

AncientBooks::CharacterBase::StringContainer AncientBooks::CharacterBase::GetUnansweredQuestion() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("character表基类不允许获取数组。"s))
}

int AncientBooks::CharacterBase::GetUnansweredQuestionCount() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("character表基类不允许获取数组。"s))
}

System::String AncientBooks::CharacterBase::GetUnansweredQuestion(int index) const
{
    USER_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(index);

    THROW_EXCEPTION(SYSTEM_TEXT("character表基类不允许获取数组。"s))
}

AncientBooks::CharacterBase::StringContainerConstIter AncientBooks::CharacterBase::GetUnansweredQuestionBegin() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("character表基类不允许获取数组。"s))
}

AncientBooks::CharacterBase::StringContainerConstIter AncientBooks::CharacterBase::GetUnansweredQuestionEnd() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("character表基类不允许获取数组。"s))
}

