/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �Զ�����

#include "Input1Base.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

CsvOutput::Input1Base::Input1Base(int key) noexcept
    : key{ key }
{
    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CsvOutput, Input1Base)

int CsvOutput::Input1Base::GetKey() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return key;
}

int CsvOutput::Input1Base::GetId() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

bool CsvOutput::Input1Base::IsTest0() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return false;
}

System::TChar CsvOutput::Input1Base::GetTest1() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return SYSTEM_TEXT('\0');
}

double CsvOutput::Input1Base::GetTest2() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0.0;
}

int CsvOutput::Input1Base::GetTest4() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

System::String CsvOutput::Input1Base::GetTest5() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("input1����಻�����ȡ�ַ�����"s))
}

CsvOutput::Input1Base::StringContainer CsvOutput::Input1Base::GetTest6() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("input1����಻�����ȡ���顣"s))
}

int CsvOutput::Input1Base::GetTest6Count() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("input1����಻�����ȡ���顣"s))
}

System::String CsvOutput::Input1Base::GetTest6(int index) const
{
    USER_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(index);

    THROW_EXCEPTION(SYSTEM_TEXT("input1����಻�����ȡ���顣"s))
}

CsvOutput::Input1Base::StringContainerConstIter CsvOutput::Input1Base::GetTest6Begin() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("input1����಻�����ȡ���顣"s))
}

CsvOutput::Input1Base::StringContainerConstIter CsvOutput::Input1Base::GetTest6End() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("input1����಻�����ȡ���顣"s))
}

