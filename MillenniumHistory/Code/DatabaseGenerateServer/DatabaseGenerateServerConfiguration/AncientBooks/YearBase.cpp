/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#include "YearBase.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

AncientBooks::YearBase::YearBase(int key) noexcept
    : key{ key }
{
    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(AncientBooks, YearBase)

int AncientBooks::YearBase::GetKey() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return key;
}

int AncientBooks::YearBase::GetId() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

System::String AncientBooks::YearBase::GetName() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("year表基类不允许获取字符串。"s))
}

int AncientBooks::YearBase::GetSexagenaryCycle() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

std::shared_ptr<const AncientBooks::SexagenaryCycleMappingType> AncientBooks::YearBase::GetSexagenaryCycle(MAYBE_UNUSED const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("year表基类不允许获取映射值。"s))
}

int64_t AncientBooks::YearBase::GetReignTitle() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

std::shared_ptr<const AncientBooks::ReignTitleMappingType> AncientBooks::YearBase::GetReignTitle(MAYBE_UNUSED const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("year表基类不允许获取映射值。"s))
}

int AncientBooks::YearBase::GetYear() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

std::vector<int> AncientBooks::YearBase::GetUnorthodoxReignTitle() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("year表基类不允许获取数组。"s))
}

int AncientBooks::YearBase::GetUnorthodoxReignTitleCount() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("year表基类不允许获取数组。"s))
}

int AncientBooks::YearBase::GetUnorthodoxReignTitle(MAYBE_UNUSED int index) const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("year表基类不允许获取数组。"s))
}

std::vector<int>::const_iterator AncientBooks::YearBase::GetUnorthodoxReignTitleBegin() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("year表基类不允许获取数组。"s))
}

std::vector<int>::const_iterator AncientBooks::YearBase::GetUnorthodoxReignTitleEnd() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("year表基类不允许获取数组。"s))
}

std::vector<int> AncientBooks::YearBase::GetUnorthodoxYear() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("year表基类不允许获取数组。"s))
}

int AncientBooks::YearBase::GetUnorthodoxYearCount() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("year表基类不允许获取数组。"s))
}

int AncientBooks::YearBase::GetUnorthodoxYear(MAYBE_UNUSED int index) const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("year表基类不允许获取数组。"s))
}

std::vector<int>::const_iterator AncientBooks::YearBase::GetUnorthodoxYearBegin() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("year表基类不允许获取数组。"s))
}

std::vector<int>::const_iterator AncientBooks::YearBase::GetUnorthodoxYearEnd() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("year表基类不允许获取数组。"s))
}

