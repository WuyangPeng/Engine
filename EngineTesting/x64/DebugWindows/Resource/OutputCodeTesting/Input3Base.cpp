/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#include "Input3Base.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

OutputCSVTesting::Input3Base::Input3Base(int key) noexcept
    : key{ key }
{
    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(OutputCSVTesting, Input3Base)

int OutputCSVTesting::Input3Base::GetKey() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return key;
}

int OutputCSVTesting::Input3Base::GetId() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

bool OutputCSVTesting::Input3Base::IsTest0() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return false;
}

System::TChar OutputCSVTesting::Input3Base::GetTest1() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return SYSTEM_TEXT('\0');
}

double OutputCSVTesting::Input3Base::GetTest2() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0.0;
}

int OutputCSVTesting::Input3Base::GetTest4() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

System::String OutputCSVTesting::Input3Base::GetTest5() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("input3表基类不允许获取字符串。"s))
}

