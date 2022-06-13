///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/18 16:32)

#include "Parameters.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::make_shared;

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

    return CloneClassType();
}

CoreTools::Parameters::ParametersSharedPtr CoreTools::Parameters::CloneClassType() const
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return make_shared<ClassType>(*this);
}
