/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �Զ�����

#include "SexagenaryCycleBase.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

AncientBooks::SexagenaryCycleBase::SexagenaryCycleBase(int key) noexcept
    : key{ key }
{
    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(AncientBooks, SexagenaryCycleBase)

int AncientBooks::SexagenaryCycleBase::GetKey() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return key;
}

int AncientBooks::SexagenaryCycleBase::GetId() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

System::String AncientBooks::SexagenaryCycleBase::GetHeavenly() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("sexagenaryCycle����಻�����ȡ�ַ�����"s))
}

System::String AncientBooks::SexagenaryCycleBase::GetBranch() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("sexagenaryCycle����಻�����ȡ�ַ�����"s))
}

System::String AncientBooks::SexagenaryCycleBase::GetName() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("sexagenaryCycle����಻�����ȡ�ַ�����"s))
}

