/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �Զ�����

#include "ImperialCourtBase.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

AncientBooks::ImperialCourtBase::ImperialCourtBase(int key) noexcept
    : key{ key }
{
    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(AncientBooks, ImperialCourtBase)

int AncientBooks::ImperialCourtBase::GetKey() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return key;
}

int AncientBooks::ImperialCourtBase::GetId() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

System::String AncientBooks::ImperialCourtBase::GetCategory() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("imperialCourt�����಻������ȡ�ַ�����"s))
}

System::String AncientBooks::ImperialCourtBase::GetBook() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("imperialCourt�����಻������ȡ�ַ�����"s))
}

int AncientBooks::ImperialCourtBase::GetBegin() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

AncientBooks::ImperialCourtBase::ConstYearSharedPtr AncientBooks::ImperialCourtBase::GetBegin(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(csvContainer);

    THROW_EXCEPTION(SYSTEM_TEXT("imperialCourt�����಻������ȡӳ��ֵ��"s))
}

int AncientBooks::ImperialCourtBase::GetEnd() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

AncientBooks::ImperialCourtBase::ConstYearSharedPtr AncientBooks::ImperialCourtBase::GetEnd(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(csvContainer);

    THROW_EXCEPTION(SYSTEM_TEXT("imperialCourt�����಻������ȡӳ��ֵ��"s))
}
