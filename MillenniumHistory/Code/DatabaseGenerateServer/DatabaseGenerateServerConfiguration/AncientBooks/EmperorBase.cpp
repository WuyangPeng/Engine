/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#include "EmperorBase.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

AncientBooks::EmperorBase::EmperorBase(int key) noexcept
    : key{ key }
{
    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(AncientBooks, EmperorBase)

int AncientBooks::EmperorBase::GetKey() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return key;
}

int AncientBooks::EmperorBase::GetId() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

int AncientBooks::EmperorBase::GetCharacter() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

std::shared_ptr<const AncientBooks::CharacterMappingType> AncientBooks::EmperorBase::GetCharacter(MAYBE_UNUSED const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("emperor表基类不允许获取映射值。"s))
}

System::String AncientBooks::EmperorBase::GetName() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("emperor表基类不允许获取字符串。"s))
}

System::String AncientBooks::EmperorBase::GetDynasticTitle() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("emperor表基类不允许获取字符串。"s))
}

std::vector<System::String> AncientBooks::EmperorBase::GetDynasticTitleAlias() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("emperor表基类不允许获取数组。"s))
}

int AncientBooks::EmperorBase::GetDynasticTitleAliasCount() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("emperor表基类不允许获取数组。"s))
}

System::String AncientBooks::EmperorBase::GetDynasticTitleAlias(MAYBE_UNUSED int index) const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("emperor表基类不允许获取数组。"s))
}

std::vector<System::String>::const_iterator AncientBooks::EmperorBase::GetDynasticTitleAliasBegin() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("emperor表基类不允许获取数组。"s))
}

std::vector<System::String>::const_iterator AncientBooks::EmperorBase::GetDynasticTitleAliasEnd() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("emperor表基类不允许获取数组。"s))
}

System::String AncientBooks::EmperorBase::GetPosthumousTitle() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("emperor表基类不允许获取字符串。"s))
}

std::vector<System::String> AncientBooks::EmperorBase::GetPosthumousTitleAlias() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("emperor表基类不允许获取数组。"s))
}

int AncientBooks::EmperorBase::GetPosthumousTitleAliasCount() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("emperor表基类不允许获取数组。"s))
}

System::String AncientBooks::EmperorBase::GetPosthumousTitleAlias(MAYBE_UNUSED int index) const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("emperor表基类不允许获取数组。"s))
}

std::vector<System::String>::const_iterator AncientBooks::EmperorBase::GetPosthumousTitleAliasBegin() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("emperor表基类不允许获取数组。"s))
}

std::vector<System::String>::const_iterator AncientBooks::EmperorBase::GetPosthumousTitleAliasEnd() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("emperor表基类不允许获取数组。"s))
}

int AncientBooks::EmperorBase::GetBeginYear() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

std::shared_ptr<const AncientBooks::YearMappingType> AncientBooks::EmperorBase::GetBeginYear(MAYBE_UNUSED const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("emperor表基类不允许获取映射值。"s))
}

int AncientBooks::EmperorBase::GetBeginMonth() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

std::shared_ptr<const AncientBooks::MonthMappingType> AncientBooks::EmperorBase::GetBeginMonth(MAYBE_UNUSED const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("emperor表基类不允许获取映射值。"s))
}

int AncientBooks::EmperorBase::GetBeginSexagenaryCycle() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

std::shared_ptr<const AncientBooks::SexagenaryCycleMappingType> AncientBooks::EmperorBase::GetBeginSexagenaryCycle(MAYBE_UNUSED const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("emperor表基类不允许获取映射值。"s))
}

int AncientBooks::EmperorBase::GetBeginDay() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

std::shared_ptr<const AncientBooks::DayMappingType> AncientBooks::EmperorBase::GetBeginDay(MAYBE_UNUSED const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("emperor表基类不允许获取映射值。"s))
}

int AncientBooks::EmperorBase::GetEndYear() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

std::shared_ptr<const AncientBooks::YearMappingType> AncientBooks::EmperorBase::GetEndYear(MAYBE_UNUSED const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("emperor表基类不允许获取映射值。"s))
}

int AncientBooks::EmperorBase::GetEndMonth() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

std::shared_ptr<const AncientBooks::MonthMappingType> AncientBooks::EmperorBase::GetEndMonth(MAYBE_UNUSED const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("emperor表基类不允许获取映射值。"s))
}

int AncientBooks::EmperorBase::GetEndSexagenaryCycle() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

std::shared_ptr<const AncientBooks::SexagenaryCycleMappingType> AncientBooks::EmperorBase::GetEndSexagenaryCycle(MAYBE_UNUSED const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("emperor表基类不允许获取映射值。"s))
}

int AncientBooks::EmperorBase::GetEndDay() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

std::shared_ptr<const AncientBooks::DayMappingType> AncientBooks::EmperorBase::GetEndDay(MAYBE_UNUSED const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("emperor表基类不允许获取映射值。"s))
}

int AncientBooks::EmperorBase::GetAgainBeginYear() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

std::shared_ptr<const AncientBooks::YearMappingType> AncientBooks::EmperorBase::GetAgainBeginYear(MAYBE_UNUSED const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("emperor表基类不允许获取映射值。"s))
}

int AncientBooks::EmperorBase::GetAgainBeginMonth() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

std::shared_ptr<const AncientBooks::MonthMappingType> AncientBooks::EmperorBase::GetAgainBeginMonth(MAYBE_UNUSED const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("emperor表基类不允许获取映射值。"s))
}

int AncientBooks::EmperorBase::GetAgainBeginSexagenaryCycle() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

std::shared_ptr<const AncientBooks::SexagenaryCycleMappingType> AncientBooks::EmperorBase::GetAgainBeginSexagenaryCycle(MAYBE_UNUSED const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("emperor表基类不允许获取映射值。"s))
}

int AncientBooks::EmperorBase::GetAgainBeginDay() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

std::shared_ptr<const AncientBooks::DayMappingType> AncientBooks::EmperorBase::GetAgainBeginDay(MAYBE_UNUSED const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("emperor表基类不允许获取映射值。"s))
}

int AncientBooks::EmperorBase::GetAgainEndYear() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

std::shared_ptr<const AncientBooks::YearMappingType> AncientBooks::EmperorBase::GetAgainEndYear(MAYBE_UNUSED const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("emperor表基类不允许获取映射值。"s))
}

int AncientBooks::EmperorBase::GetAgainEndMonth() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

std::shared_ptr<const AncientBooks::MonthMappingType> AncientBooks::EmperorBase::GetAgainEndMonth(MAYBE_UNUSED const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("emperor表基类不允许获取映射值。"s))
}

int AncientBooks::EmperorBase::GetAgainEndSexagenaryCycle() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

std::shared_ptr<const AncientBooks::SexagenaryCycleMappingType> AncientBooks::EmperorBase::GetAgainEndSexagenaryCycle(MAYBE_UNUSED const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("emperor表基类不允许获取映射值。"s))
}

int AncientBooks::EmperorBase::GetAgainEndDay() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

std::shared_ptr<const AncientBooks::DayMappingType> AncientBooks::EmperorBase::GetAgainEndDay(MAYBE_UNUSED const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("emperor表基类不允许获取映射值。"s))
}

std::vector<System::String> AncientBooks::EmperorBase::GetUnansweredQuestion() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("emperor表基类不允许获取数组。"s))
}

int AncientBooks::EmperorBase::GetUnansweredQuestionCount() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("emperor表基类不允许获取数组。"s))
}

System::String AncientBooks::EmperorBase::GetUnansweredQuestion(MAYBE_UNUSED int index) const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("emperor表基类不允许获取数组。"s))
}

std::vector<System::String>::const_iterator AncientBooks::EmperorBase::GetUnansweredQuestionBegin() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("emperor表基类不允许获取数组。"s))
}

std::vector<System::String>::const_iterator AncientBooks::EmperorBase::GetUnansweredQuestionEnd() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("emperor表基类不允许获取数组。"s))
}

