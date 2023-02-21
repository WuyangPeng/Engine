///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.2 (2023/02/16 20:54)

#include "Properties.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::Properties::Properties() noexcept
    : value0{ 1 }, value2{}, value3{ 0 }, value4{ 0 }, value5{}, value6{}, value7{}, value8{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, Properties)

const int& CoreTools::Properties::GetValue0() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return value0;
}

int CoreTools::Properties::GetValue1() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return value0;
}

void CoreTools::Properties::SetValue2(const std::string& value)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    value2 = value;
}

std::string CoreTools::Properties::GetValue2() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return value2;
}

uint32_t CoreTools::Properties::GetValue3() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return value3;
}

void CoreTools::Properties::SetValue3(const uint32_t& value) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    value3 = value;
}

int CoreTools::Properties::GetValue4() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return value4;
}

void CoreTools::Properties::SetValue4(int value) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    value4 = value;
}

const std::string& CoreTools::Properties::GetValue5() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return value5;
}

void CoreTools::Properties::SetValue5(const std::string& value)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    value5 = value;
}

const std::string& CoreTools::Properties::GetValue6() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return value6;
}

void CoreTools::Properties::SetValue7(const std::string& value)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    value7 = value;
}

std::string CoreTools::Properties::GetValue7() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return value7;
}

std::string CoreTools::Properties::GetValue8() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return value8;
}

void CoreTools::Properties::SetValue8(const std::string& value)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    value8 = value;
}

namespace CoreTools
{
    TCRE_DEFINE_PROPERTY(Properties, Value4);
    TCRE_DEFINE_PROPERTY(Properties, Value5);
}
