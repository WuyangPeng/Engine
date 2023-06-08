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

    THROW_EXCEPTION(SYSTEM_TEXT("year����಻�����ȡ�ַ�����"s))
}

int AncientBooks::YearBase::GetSexagenaryCycle() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

std::shared_ptr<const AncientBooks::SexagenaryCycleMappingType> AncientBooks::YearBase::GetSexagenaryCycle(MAYBE_UNUSED const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("year����಻�����ȡӳ��ֵ��"s))
}

int64_t AncientBooks::YearBase::GetReignTitle() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

std::shared_ptr<const AncientBooks::ReignTitleMappingType> AncientBooks::YearBase::GetReignTitle(MAYBE_UNUSED const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("year����಻�����ȡӳ��ֵ��"s))
}

int AncientBooks::YearBase::GetYear() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

std::vector<int> AncientBooks::YearBase::GetUnorthodoxReignTitle() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("year����಻�����ȡ���顣"s))
}

int AncientBooks::YearBase::GetUnorthodoxReignTitleCount() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("year����಻�����ȡ���顣"s))
}

int AncientBooks::YearBase::GetUnorthodoxReignTitle(MAYBE_UNUSED int index) const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("year����಻�����ȡ���顣"s))
}

std::vector<int>::const_iterator AncientBooks::YearBase::GetUnorthodoxReignTitleBegin() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("year����಻�����ȡ���顣"s))
}

std::vector<int>::const_iterator AncientBooks::YearBase::GetUnorthodoxReignTitleEnd() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("year����಻�����ȡ���顣"s))
}

std::vector<int> AncientBooks::YearBase::GetUnorthodoxYear() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("year����಻�����ȡ���顣"s))
}

int AncientBooks::YearBase::GetUnorthodoxYearCount() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("year����಻�����ȡ���顣"s))
}

int AncientBooks::YearBase::GetUnorthodoxYear(MAYBE_UNUSED int index) const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("year����಻�����ȡ���顣"s))
}

std::vector<int>::const_iterator AncientBooks::YearBase::GetUnorthodoxYearBegin() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("year����಻�����ȡ���顣"s))
}

std::vector<int>::const_iterator AncientBooks::YearBase::GetUnorthodoxYearEnd() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("year����಻�����ȡ���顣"s))
}

