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

AncientBooks::CountryBase::ConstImperialCourtSharedPtr AncientBooks::CountryBase::GetImperialCourt(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(csvContainer);

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

AncientBooks::CountryBase::ConstYearSharedPtr AncientBooks::CountryBase::GetBeginYear(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(csvContainer);

    THROW_EXCEPTION(SYSTEM_TEXT("country����಻�����ȡӳ��ֵ��"s))
}

int AncientBooks::CountryBase::GetBeginMonth() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

AncientBooks::CountryBase::ConstMonthSharedPtr AncientBooks::CountryBase::GetBeginMonth(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(csvContainer);

    THROW_EXCEPTION(SYSTEM_TEXT("country����಻�����ȡӳ��ֵ��"s))
}

int AncientBooks::CountryBase::GetBeginSexagenaryCycle() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

AncientBooks::CountryBase::ConstSexagenaryCycleSharedPtr AncientBooks::CountryBase::GetBeginSexagenaryCycle(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(csvContainer);

    THROW_EXCEPTION(SYSTEM_TEXT("country����಻�����ȡӳ��ֵ��"s))
}

int AncientBooks::CountryBase::GetBeginDay() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

AncientBooks::CountryBase::ConstDaySharedPtr AncientBooks::CountryBase::GetBeginDay(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(csvContainer);

    THROW_EXCEPTION(SYSTEM_TEXT("country����಻�����ȡӳ��ֵ��"s))
}

int AncientBooks::CountryBase::GetEndYear() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

AncientBooks::CountryBase::ConstYearSharedPtr AncientBooks::CountryBase::GetEndYear(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(csvContainer);

    THROW_EXCEPTION(SYSTEM_TEXT("country����಻�����ȡӳ��ֵ��"s))
}

int AncientBooks::CountryBase::GetEndMonth() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

AncientBooks::CountryBase::ConstMonthSharedPtr AncientBooks::CountryBase::GetEndMonth(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(csvContainer);

    THROW_EXCEPTION(SYSTEM_TEXT("country����಻�����ȡӳ��ֵ��"s))
}

int AncientBooks::CountryBase::GetEndSexagenaryCycle() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

AncientBooks::CountryBase::ConstSexagenaryCycleSharedPtr AncientBooks::CountryBase::GetEndSexagenaryCycle(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(csvContainer);

    THROW_EXCEPTION(SYSTEM_TEXT("country����಻�����ȡӳ��ֵ��"s))
}

int AncientBooks::CountryBase::GetEndDay() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

AncientBooks::CountryBase::ConstDaySharedPtr AncientBooks::CountryBase::GetEndDay(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(csvContainer);

    THROW_EXCEPTION(SYSTEM_TEXT("country����಻�����ȡӳ��ֵ��"s))
}

AncientBooks::CountryBase::StringContainer AncientBooks::CountryBase::GetUnansweredQuestion() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("country����಻�����ȡ���顣"s))
}

int AncientBooks::CountryBase::GetUnansweredQuestionCount() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("country����಻�����ȡ���顣"s))
}

System::String AncientBooks::CountryBase::GetUnansweredQuestion(int index) const
{
    USER_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(index);

    THROW_EXCEPTION(SYSTEM_TEXT("country����಻�����ȡ���顣"s))
}

AncientBooks::CountryBase::StringContainerConstIter AncientBooks::CountryBase::GetUnansweredQuestionBegin() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("country����಻�����ȡ���顣"s))
}

AncientBooks::CountryBase::StringContainerConstIter AncientBooks::CountryBase::GetUnansweredQuestionEnd() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("country����಻�����ȡ���顣"s))
}

