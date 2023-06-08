/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �Զ�����

#include "CountryBase.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

AncientBooks::CountryBase::CountryBase(int key) noexcept
    : key{ key }
{
    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(AncientBooks, CountryBase)

int AncientBooks::CountryBase::GetKey() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return key;
}

int AncientBooks::CountryBase::GetId() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

int AncientBooks::CountryBase::GetImperialCourt() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

std::shared_ptr<const AncientBooks::ImperialCourtMappingType> AncientBooks::CountryBase::GetImperialCourt(MAYBE_UNUSED const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("country����಻�����ȡӳ��ֵ��"s))
}

System::String AncientBooks::CountryBase::GetCategory() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("country����಻�����ȡ�ַ�����"s))
}

int AncientBooks::CountryBase::GetBeginYear() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

std::shared_ptr<const AncientBooks::YearMappingType> AncientBooks::CountryBase::GetBeginYear(MAYBE_UNUSED const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("country����಻�����ȡӳ��ֵ��"s))
}

int AncientBooks::CountryBase::GetBeginMonth() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

std::shared_ptr<const AncientBooks::MonthMappingType> AncientBooks::CountryBase::GetBeginMonth(MAYBE_UNUSED const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("country����಻�����ȡӳ��ֵ��"s))
}

int AncientBooks::CountryBase::GetBeginSexagenaryCycle() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

std::shared_ptr<const AncientBooks::SexagenaryCycleMappingType> AncientBooks::CountryBase::GetBeginSexagenaryCycle(MAYBE_UNUSED const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("country����಻�����ȡӳ��ֵ��"s))
}

int AncientBooks::CountryBase::GetBeginDay() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

std::shared_ptr<const AncientBooks::DayMappingType> AncientBooks::CountryBase::GetBeginDay(MAYBE_UNUSED const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("country����಻�����ȡӳ��ֵ��"s))
}

int AncientBooks::CountryBase::GetEndYear() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

std::shared_ptr<const AncientBooks::YearMappingType> AncientBooks::CountryBase::GetEndYear(MAYBE_UNUSED const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("country����಻�����ȡӳ��ֵ��"s))
}

int AncientBooks::CountryBase::GetEndMonth() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

std::shared_ptr<const AncientBooks::MonthMappingType> AncientBooks::CountryBase::GetEndMonth(MAYBE_UNUSED const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("country����಻�����ȡӳ��ֵ��"s))
}

int AncientBooks::CountryBase::GetEndSexagenaryCycle() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

std::shared_ptr<const AncientBooks::SexagenaryCycleMappingType> AncientBooks::CountryBase::GetEndSexagenaryCycle(MAYBE_UNUSED const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("country����಻�����ȡӳ��ֵ��"s))
}

int AncientBooks::CountryBase::GetEndDay() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

std::shared_ptr<const AncientBooks::DayMappingType> AncientBooks::CountryBase::GetEndDay(MAYBE_UNUSED const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("country����಻�����ȡӳ��ֵ��"s))
}

std::vector<System::String> AncientBooks::CountryBase::GetUnansweredQuestion() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("country����಻�����ȡ���顣"s))
}

int AncientBooks::CountryBase::GetUnansweredQuestionCount() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("country����಻�����ȡ���顣"s))
}

System::String AncientBooks::CountryBase::GetUnansweredQuestion(MAYBE_UNUSED int index) const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("country����಻�����ȡ���顣"s))
}

std::vector<System::String>::const_iterator AncientBooks::CountryBase::GetUnansweredQuestionBegin() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("country����಻�����ȡ���顣"s))
}

std::vector<System::String>::const_iterator AncientBooks::CountryBase::GetUnansweredQuestionEnd() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("country����಻�����ȡ���顣"s))
}

