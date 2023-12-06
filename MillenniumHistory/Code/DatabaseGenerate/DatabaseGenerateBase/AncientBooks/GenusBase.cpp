/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �Զ�����

#include "GenusBase.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

AncientBooks::GenusBase::GenusBase(int key) noexcept
    : key{ key }
{
    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(AncientBooks, GenusBase)

int AncientBooks::GenusBase::GetKey() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return key;
}

int AncientBooks::GenusBase::GetId() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

int AncientBooks::GenusBase::GetCategory() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

AncientBooks::GenusBase::ConstCategorySharedPtr AncientBooks::GenusBase::GetCategory(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(csvContainer);

    THROW_EXCEPTION(SYSTEM_TEXT("genus����಻�����ȡӳ��ֵ��"s))
}

System::String AncientBooks::GenusBase::GetName() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("genus����಻�����ȡ�ַ�����"s))
}

int AncientBooks::GenusBase::GetFather() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

AncientBooks::GenusBase::ConstGenusSharedPtr AncientBooks::GenusBase::GetFather(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(csvContainer);

    THROW_EXCEPTION(SYSTEM_TEXT("genus����಻�����ȡӳ��ֵ��"s))
}

System::String AncientBooks::GenusBase::GetBegin() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("genus����಻�����ȡ�ַ�����"s))
}

System::String AncientBooks::GenusBase::GetEnd() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("genus����಻�����ȡ�ַ�����"s))
}

