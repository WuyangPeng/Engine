/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/04/23 13:01)

#include "Parameters.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::Parameters::ParametersSharedPtr CoreTools::Parameters::Create(int value)
{
    return std::make_shared<Parameters>(value);
}

CoreTools::Parameters::Parameters(int value) noexcept
    : value{ value }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, Parameters)

int CoreTools::Parameters::GetValue() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return value;
}

void CoreTools::Parameters::SetValue(int aValue) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    value = aValue;
}

CoreTools::Parameters::BaseSharedPtr CoreTools::Parameters::Clone() const
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return CloneParameters();
}

CoreTools::Parameters::ParametersSharedPtr CoreTools::Parameters::CloneParameters() const
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return std::make_shared<ClassType>(*this);
}
