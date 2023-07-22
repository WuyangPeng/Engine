/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �Զ�����

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

    THROW_EXCEPTION(SYSTEM_TEXT("year�����಻������ȡ�ַ�����"s))
}

int AncientBooks::YearBase::GetSexagenaryCycle() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

AncientBooks::YearBase::ConstSexagenaryCycleSharedPtr AncientBooks::YearBase::GetSexagenaryCycle(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(csvContainer);

    THROW_EXCEPTION(SYSTEM_TEXT("year�����಻������ȡӳ��ֵ��"s))
}

int64_t AncientBooks::YearBase::GetReignTitle() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

AncientBooks::YearBase::ConstReignTitleSharedPtr AncientBooks::YearBase::GetReignTitle(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(csvContainer);

    THROW_EXCEPTION(SYSTEM_TEXT("year�����಻������ȡӳ��ֵ��"s))
}

int AncientBooks::YearBase::GetYear() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

AncientBooks::YearBase::Int64Container AncientBooks::YearBase::GetUnorthodoxReignTitle() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("year�����಻������ȡ���顣"s))
}

int AncientBooks::YearBase::GetUnorthodoxReignTitleCount() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("year�����಻������ȡ���顣"s))
}

int64_t AncientBooks::YearBase::GetUnorthodoxReignTitle(int index) const
{
    USER_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(index);

    THROW_EXCEPTION(SYSTEM_TEXT("year�����಻������ȡ���顣"s))
}

AncientBooks::YearBase::Int64ContainerConstIter AncientBooks::YearBase::GetUnorthodoxReignTitleBegin() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("year�����಻������ȡ���顣"s))
}

AncientBooks::YearBase::Int64ContainerConstIter AncientBooks::YearBase::GetUnorthodoxReignTitleEnd() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("year�����಻������ȡ���顣"s))
}

AncientBooks::YearBase::ReignTitleContainer AncientBooks::YearBase::GetUnorthodoxReignTitle(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(csvContainer);

    THROW_EXCEPTION(SYSTEM_TEXT("year�����಻������ȡӳ��ֵ��"s))
}

AncientBooks::YearBase::IntContainer AncientBooks::YearBase::GetUnorthodoxYear() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("year�����಻������ȡ���顣"s))
}

int AncientBooks::YearBase::GetUnorthodoxYearCount() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("year�����಻������ȡ���顣"s))
}

int AncientBooks::YearBase::GetUnorthodoxYear(int index) const
{
    USER_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(index);

    THROW_EXCEPTION(SYSTEM_TEXT("year�����಻������ȡ���顣"s))
}

AncientBooks::YearBase::IntContainerConstIter AncientBooks::YearBase::GetUnorthodoxYearBegin() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("year�����಻������ȡ���顣"s))
}

AncientBooks::YearBase::IntContainerConstIter AncientBooks::YearBase::GetUnorthodoxYearEnd() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("year�����಻������ȡ���顣"s))
}

AncientBooks::YearBase::YearContainer AncientBooks::YearBase::GetUnorthodoxYear(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(csvContainer);

    THROW_EXCEPTION(SYSTEM_TEXT("year�����಻������ȡӳ��ֵ��"s))
}
