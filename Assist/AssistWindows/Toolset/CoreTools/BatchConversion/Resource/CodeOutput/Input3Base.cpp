/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �Զ�����

#include "Input3Base.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

CsvOutput::Input3Base::Input3Base(int key) noexcept
    : key{ key }
{
    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CsvOutput, Input3Base)

int CsvOutput::Input3Base::GetKey() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return key;
}

int CsvOutput::Input3Base::GetId() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

bool CsvOutput::Input3Base::IsTest0() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return false;
}

System::TChar CsvOutput::Input3Base::GetTest1() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return SYSTEM_TEXT('\0');
}

double CsvOutput::Input3Base::GetTest2() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0.0;
}

int CsvOutput::Input3Base::GetTest4() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

System::String CsvOutput::Input3Base::GetTest5() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("input3����಻�����ȡ�ַ�����"s))
}

