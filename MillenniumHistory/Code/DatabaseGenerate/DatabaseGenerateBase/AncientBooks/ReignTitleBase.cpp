/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �Զ�����

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

    THROW_EXCEPTION(SYSTEM_TEXT("reignTitle����಻�����ȡ�ַ�����"s))
}

AncientBooks::ReignTitleBase::IntContainer AncientBooks::ReignTitleBase::GetEmperor() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("reignTitle����಻�����ȡ���顣"s))
}

int AncientBooks::ReignTitleBase::GetEmperorCount() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("reignTitle����಻�����ȡ���顣"s))
}

int AncientBooks::ReignTitleBase::GetEmperor(int index) const
{
    USER_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(index);

    THROW_EXCEPTION(SYSTEM_TEXT("reignTitle����಻�����ȡ���顣"s))
}

AncientBooks::ReignTitleBase::IntContainerConstIter AncientBooks::ReignTitleBase::GetEmperorBegin() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("reignTitle����಻�����ȡ���顣"s))
}

AncientBooks::ReignTitleBase::IntContainerConstIter AncientBooks::ReignTitleBase::GetEmperorEnd() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("reignTitle����಻�����ȡ���顣"s))
}

AncientBooks::ReignTitleBase::CharacterContainer AncientBooks::ReignTitleBase::GetEmperor(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(csvContainer);

    THROW_EXCEPTION(SYSTEM_TEXT("reignTitle����಻�����ȡӳ��ֵ��"s))
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

AncientBooks::ReignTitleBase::ConstYearSharedPtr AncientBooks::ReignTitleBase::GetBeginYear(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(csvContainer);

    THROW_EXCEPTION(SYSTEM_TEXT("reignTitle����಻�����ȡӳ��ֵ��"s))
}

int AncientBooks::ReignTitleBase::GetBeginMonth() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

AncientBooks::ReignTitleBase::ConstMonthSharedPtr AncientBooks::ReignTitleBase::GetBeginMonth(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(csvContainer);

    THROW_EXCEPTION(SYSTEM_TEXT("reignTitle����಻�����ȡӳ��ֵ��"s))
}

int AncientBooks::ReignTitleBase::GetBeginSexagenaryCycle() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

AncientBooks::ReignTitleBase::ConstSexagenaryCycleSharedPtr AncientBooks::ReignTitleBase::GetBeginSexagenaryCycle(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(csvContainer);

    THROW_EXCEPTION(SYSTEM_TEXT("reignTitle����಻�����ȡӳ��ֵ��"s))
}

int AncientBooks::ReignTitleBase::GetBeginDay() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

AncientBooks::ReignTitleBase::ConstDaySharedPtr AncientBooks::ReignTitleBase::GetBeginDay(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(csvContainer);

    THROW_EXCEPTION(SYSTEM_TEXT("reignTitle����಻�����ȡӳ��ֵ��"s))
}

int AncientBooks::ReignTitleBase::GetEndYear() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

AncientBooks::ReignTitleBase::ConstYearSharedPtr AncientBooks::ReignTitleBase::GetEndYear(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(csvContainer);

    THROW_EXCEPTION(SYSTEM_TEXT("reignTitle����಻�����ȡӳ��ֵ��"s))
}

int AncientBooks::ReignTitleBase::GetEndMonth() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

AncientBooks::ReignTitleBase::ConstMonthSharedPtr AncientBooks::ReignTitleBase::GetEndMonth(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(csvContainer);

    THROW_EXCEPTION(SYSTEM_TEXT("reignTitle����಻�����ȡӳ��ֵ��"s))
}

int AncientBooks::ReignTitleBase::GetEndSexagenaryCycle() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

AncientBooks::ReignTitleBase::ConstSexagenaryCycleSharedPtr AncientBooks::ReignTitleBase::GetEndSexagenaryCycle(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(csvContainer);

    THROW_EXCEPTION(SYSTEM_TEXT("reignTitle����಻�����ȡӳ��ֵ��"s))
}

int AncientBooks::ReignTitleBase::GetEndDay() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

AncientBooks::ReignTitleBase::ConstDaySharedPtr AncientBooks::ReignTitleBase::GetEndDay(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(csvContainer);

    THROW_EXCEPTION(SYSTEM_TEXT("reignTitle����಻�����ȡӳ��ֵ��"s))
}

