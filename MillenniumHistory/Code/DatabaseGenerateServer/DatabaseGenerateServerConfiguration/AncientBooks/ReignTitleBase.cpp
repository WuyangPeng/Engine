/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#include "ReignTitleBase.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

AncientBooks::ReignTitleBase::ReignTitleBase(int64_t key) noexcept
    : key{ key }
{
    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(AncientBooks, ReignTitleBase)

int64_t AncientBooks::ReignTitleBase::GetKey() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return key;
}

int64_t AncientBooks::ReignTitleBase::GetId() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

System::String AncientBooks::ReignTitleBase::GetName() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("reignTitle表基类不允许获取字符串。"s))
}

std::vector<int> AncientBooks::ReignTitleBase::GetEmperor() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("reignTitle表基类不允许获取数组。"s))
}

int AncientBooks::ReignTitleBase::GetEmperorCount() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("reignTitle表基类不允许获取数组。"s))
}

int AncientBooks::ReignTitleBase::GetEmperor(MAYBE_UNUSED int index) const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("reignTitle表基类不允许获取数组。"s))
}

std::vector<int>::const_iterator AncientBooks::ReignTitleBase::GetEmperorBegin() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("reignTitle表基类不允许获取数组。"s))
}

std::vector<int>::const_iterator AncientBooks::ReignTitleBase::GetEmperorEnd() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("reignTitle表基类不允许获取数组。"s))
}

int AncientBooks::ReignTitleBase::GetSerial() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

int AncientBooks::ReignTitleBase::GetBeginYear() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

std::shared_ptr<const AncientBooks::YearMappingType> AncientBooks::ReignTitleBase::GetBeginYear(MAYBE_UNUSED const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("reignTitle表基类不允许获取映射值。"s))
}

int AncientBooks::ReignTitleBase::GetBeginMonth() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

std::shared_ptr<const AncientBooks::MonthMappingType> AncientBooks::ReignTitleBase::GetBeginMonth(MAYBE_UNUSED const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("reignTitle表基类不允许获取映射值。"s))
}

int AncientBooks::ReignTitleBase::GetBeginSexagenaryCycle() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

std::shared_ptr<const AncientBooks::SexagenaryCycleMappingType> AncientBooks::ReignTitleBase::GetBeginSexagenaryCycle(MAYBE_UNUSED const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("reignTitle表基类不允许获取映射值。"s))
}

int AncientBooks::ReignTitleBase::GetBeginDay() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

std::shared_ptr<const AncientBooks::DayMappingType> AncientBooks::ReignTitleBase::GetBeginDay(MAYBE_UNUSED const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("reignTitle表基类不允许获取映射值。"s))
}

int AncientBooks::ReignTitleBase::GetEndYear() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

std::shared_ptr<const AncientBooks::YearMappingType> AncientBooks::ReignTitleBase::GetEndYear(MAYBE_UNUSED const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("reignTitle表基类不允许获取映射值。"s))
}

int AncientBooks::ReignTitleBase::GetEndMonth() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

std::shared_ptr<const AncientBooks::MonthMappingType> AncientBooks::ReignTitleBase::GetEndMonth(MAYBE_UNUSED const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("reignTitle表基类不允许获取映射值。"s))
}

int AncientBooks::ReignTitleBase::GetEndSexagenaryCycle() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

std::shared_ptr<const AncientBooks::SexagenaryCycleMappingType> AncientBooks::ReignTitleBase::GetEndSexagenaryCycle(MAYBE_UNUSED const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("reignTitle表基类不允许获取映射值。"s))
}

int AncientBooks::ReignTitleBase::GetEndDay() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

std::shared_ptr<const AncientBooks::DayMappingType> AncientBooks::ReignTitleBase::GetEndDay(MAYBE_UNUSED const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("reignTitle表基类不允许获取映射值。"s))
}

