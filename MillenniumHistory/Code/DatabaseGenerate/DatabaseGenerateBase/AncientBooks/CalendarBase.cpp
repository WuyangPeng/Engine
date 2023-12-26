/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �Զ�����

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

    THROW_EXCEPTION(SYSTEM_TEXT("calendar�����಻������ȡ�ַ�����"s))
}

AncientBooks::CalendarBase::StringContainer AncientBooks::CalendarBase::GetAlias() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("calendar�����಻������ȡ���顣"s))
}

int AncientBooks::CalendarBase::GetAliasCount() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("calendar�����಻������ȡ���顣"s))
}

System::String AncientBooks::CalendarBase::GetAlias(int index) const
{
    USER_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(index);

    THROW_EXCEPTION(SYSTEM_TEXT("calendar�����಻������ȡ���顣"s))
}

AncientBooks::CalendarBase::StringContainerConstIter AncientBooks::CalendarBase::GetAliasBegin() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("calendar�����಻������ȡ���顣"s))
}

AncientBooks::CalendarBase::StringContainerConstIter AncientBooks::CalendarBase::GetAliasEnd() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("calendar�����಻������ȡ���顣"s))
}

AncientBooks::CalendarBase::IntContainer AncientBooks::CalendarBase::GetSource() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("calendar�����಻������ȡ���顣"s))
}

int AncientBooks::CalendarBase::GetSourceCount() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("calendar�����಻������ȡ���顣"s))
}

int AncientBooks::CalendarBase::GetSource(int index) const
{
    USER_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(index);

    THROW_EXCEPTION(SYSTEM_TEXT("calendar�����಻������ȡ���顣"s))
}

AncientBooks::CalendarBase::IntContainerConstIter AncientBooks::CalendarBase::GetSourceBegin() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("calendar�����಻������ȡ���顣"s))
}

AncientBooks::CalendarBase::IntContainerConstIter AncientBooks::CalendarBase::GetSourceEnd() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("calendar�����಻������ȡ���顣"s))
}

AncientBooks::CalendarBase::BookContainer AncientBooks::CalendarBase::GetSource(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(csvContainer);

    THROW_EXCEPTION(SYSTEM_TEXT("calendar�����಻������ȡӳ��ֵ��"s))
}

System::String AncientBooks::CalendarBase::GetPublication() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("calendar�����಻������ȡ�ַ�����"s))
}

AncientBooks::CalendarBase::IntContainer AncientBooks::CalendarBase::GetCreator() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("calendar�����಻������ȡ���顣"s))
}

int AncientBooks::CalendarBase::GetCreatorCount() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("calendar�����಻������ȡ���顣"s))
}

int AncientBooks::CalendarBase::GetCreator(int index) const
{
    USER_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(index);

    THROW_EXCEPTION(SYSTEM_TEXT("calendar�����಻������ȡ���顣"s))
}

AncientBooks::CalendarBase::IntContainerConstIter AncientBooks::CalendarBase::GetCreatorBegin() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("calendar�����಻������ȡ���顣"s))
}

AncientBooks::CalendarBase::IntContainerConstIter AncientBooks::CalendarBase::GetCreatorEnd() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("calendar�����಻������ȡ���顣"s))
}

AncientBooks::CalendarBase::CharacterContainer AncientBooks::CalendarBase::GetCreator(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(csvContainer);

    THROW_EXCEPTION(SYSTEM_TEXT("calendar�����಻������ȡӳ��ֵ��"s))
}

int AncientBooks::CalendarBase::GetFormulate() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

AncientBooks::CalendarBase::ConstYearSharedPtr AncientBooks::CalendarBase::GetFormulate(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(csvContainer);

    THROW_EXCEPTION(SYSTEM_TEXT("calendar�����಻������ȡӳ��ֵ��"s))
}

int AncientBooks::CalendarBase::GetCountry() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

AncientBooks::CalendarBase::ConstCountrySharedPtr AncientBooks::CalendarBase::GetCountry(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(csvContainer);

    THROW_EXCEPTION(SYSTEM_TEXT("calendar�����಻������ȡӳ��ֵ��"s))
}

int AncientBooks::CalendarBase::GetBegin() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

AncientBooks::CalendarBase::ConstYearSharedPtr AncientBooks::CalendarBase::GetBegin(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(csvContainer);

    THROW_EXCEPTION(SYSTEM_TEXT("calendar�����಻������ȡӳ��ֵ��"s))
}

int AncientBooks::CalendarBase::GetEnd() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

AncientBooks::CalendarBase::ConstYearSharedPtr AncientBooks::CalendarBase::GetEnd(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(csvContainer);

    THROW_EXCEPTION(SYSTEM_TEXT("calendar�����಻������ȡӳ��ֵ��"s))
}

int AncientBooks::CalendarBase::GetAgainBegin() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

AncientBooks::CalendarBase::ConstYearSharedPtr AncientBooks::CalendarBase::GetAgainBegin(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(csvContainer);

    THROW_EXCEPTION(SYSTEM_TEXT("calendar�����಻������ȡӳ��ֵ��"s))
}

int AncientBooks::CalendarBase::GetAgainEnd() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

AncientBooks::CalendarBase::ConstYearSharedPtr AncientBooks::CalendarBase::GetAgainEnd(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(csvContainer);

    THROW_EXCEPTION(SYSTEM_TEXT("calendar�����಻������ȡӳ��ֵ��"s))
}
