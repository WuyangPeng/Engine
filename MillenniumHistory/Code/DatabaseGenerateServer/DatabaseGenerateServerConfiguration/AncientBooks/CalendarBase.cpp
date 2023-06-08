/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#include "CalendarBase.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

AncientBooks::CalendarBase::CalendarBase(int key) noexcept
    : key{ key }
{
    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(AncientBooks, CalendarBase)

int AncientBooks::CalendarBase::GetKey() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return key;
}

int AncientBooks::CalendarBase::GetId() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

System::String AncientBooks::CalendarBase::GetName() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("calendar表基类不允许获取字符串。"s))
}

std::vector<System::String> AncientBooks::CalendarBase::GetAlias() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("calendar表基类不允许获取数组。"s))
}

int AncientBooks::CalendarBase::GetAliasCount() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("calendar表基类不允许获取数组。"s))
}

System::String AncientBooks::CalendarBase::GetAlias(MAYBE_UNUSED int index) const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("calendar表基类不允许获取数组。"s))
}

std::vector<System::String>::const_iterator AncientBooks::CalendarBase::GetAliasBegin() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("calendar表基类不允许获取数组。"s))
}

std::vector<System::String>::const_iterator AncientBooks::CalendarBase::GetAliasEnd() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("calendar表基类不允许获取数组。"s))
}

std::vector<int> AncientBooks::CalendarBase::GetSource() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("calendar表基类不允许获取数组。"s))
}

int AncientBooks::CalendarBase::GetSourceCount() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("calendar表基类不允许获取数组。"s))
}

int AncientBooks::CalendarBase::GetSource(MAYBE_UNUSED int index) const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("calendar表基类不允许获取数组。"s))
}

std::vector<int>::const_iterator AncientBooks::CalendarBase::GetSourceBegin() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("calendar表基类不允许获取数组。"s))
}

std::vector<int>::const_iterator AncientBooks::CalendarBase::GetSourceEnd() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("calendar表基类不允许获取数组。"s))
}

System::String AncientBooks::CalendarBase::GetPublication() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("calendar表基类不允许获取字符串。"s))
}

std::vector<int> AncientBooks::CalendarBase::GetCreator() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("calendar表基类不允许获取数组。"s))
}

int AncientBooks::CalendarBase::GetCreatorCount() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("calendar表基类不允许获取数组。"s))
}

int AncientBooks::CalendarBase::GetCreator(MAYBE_UNUSED int index) const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("calendar表基类不允许获取数组。"s))
}

std::vector<int>::const_iterator AncientBooks::CalendarBase::GetCreatorBegin() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("calendar表基类不允许获取数组。"s))
}

std::vector<int>::const_iterator AncientBooks::CalendarBase::GetCreatorEnd() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("calendar表基类不允许获取数组。"s))
}

int AncientBooks::CalendarBase::GetFormulate() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

std::shared_ptr<const AncientBooks::YearMappingType> AncientBooks::CalendarBase::GetFormulate(MAYBE_UNUSED const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("calendar表基类不允许获取映射值。"s))
}

int AncientBooks::CalendarBase::GetCountry() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

std::shared_ptr<const AncientBooks::CountryMappingType> AncientBooks::CalendarBase::GetCountry(MAYBE_UNUSED const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("calendar表基类不允许获取映射值。"s))
}

int AncientBooks::CalendarBase::GetBegin() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

std::shared_ptr<const AncientBooks::YearMappingType> AncientBooks::CalendarBase::GetBegin(MAYBE_UNUSED const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("calendar表基类不允许获取映射值。"s))
}

int AncientBooks::CalendarBase::GetEnd() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

std::shared_ptr<const AncientBooks::YearMappingType> AncientBooks::CalendarBase::GetEnd(MAYBE_UNUSED const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("calendar表基类不允许获取映射值。"s))
}

int AncientBooks::CalendarBase::GetAgainBegin() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

std::shared_ptr<const AncientBooks::YearMappingType> AncientBooks::CalendarBase::GetAgainBegin(MAYBE_UNUSED const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("calendar表基类不允许获取映射值。"s))
}

int AncientBooks::CalendarBase::GetAgainEnd() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

std::shared_ptr<const AncientBooks::YearMappingType> AncientBooks::CalendarBase::GetAgainEnd(MAYBE_UNUSED const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("calendar表基类不允许获取映射值。"s))
}

