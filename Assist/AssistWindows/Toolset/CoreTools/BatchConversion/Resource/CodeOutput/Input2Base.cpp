/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#include "Input2Base.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

CsvOutput::Input2Base::Input2Base(int key) noexcept
    : key{ key }
{
    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CsvOutput, Input2Base)

int CsvOutput::Input2Base::GetKey() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return key;
}

int CsvOutput::Input2Base::GetId() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

bool CsvOutput::Input2Base::IsTest0() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return false;
}

System::TChar CsvOutput::Input2Base::GetTest1() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return SYSTEM_TEXT('\0');
}

double CsvOutput::Input2Base::GetTest2() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0.0;
}

int CsvOutput::Input2Base::GetTest4() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

System::String CsvOutput::Input2Base::GetTest5() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("input2表基类不允许获取字符串。"s))
}

