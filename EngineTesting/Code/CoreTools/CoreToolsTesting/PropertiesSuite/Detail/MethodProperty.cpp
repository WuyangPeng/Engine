///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/18 13:42)

#include "MethodProperty.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::string;

CoreTools::MethodProperty::MethodProperty() noexcept
    : firstValue{ 0 }, getType{}, setType{}, getSetType{}, getExternalType{}, setExternalType{}, getSetExternalType{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, MethodProperty)

ptrdiff_t CoreTools::MethodProperty::FirstValueGetOffset() noexcept
{
    return offsetof(ClassType, getType);
}

ptrdiff_t CoreTools::MethodProperty::FirstValueSetOffset() noexcept
{
    return offsetof(ClassType, setType);
}

const int& CoreTools::MethodProperty::GetFirstValue() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return firstValue;
}

void CoreTools::MethodProperty::SetFirstValue(const int& value) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    firstValue = value;
}

ptrdiff_t CoreTools::MethodProperty::FirstValueGetSetOffset() noexcept
{
    return offsetof(ClassType, getSetType);
}

ptrdiff_t CoreTools::MethodProperty::FirstValueGetExternalOffset() noexcept
{
    return offsetof(ClassType, getExternalType);
}

ptrdiff_t CoreTools::MethodProperty::FirstValueSetExternalOffset() noexcept
{
    return offsetof(ClassType, setExternalType);
}

ptrdiff_t CoreTools::MethodProperty::FirstValueGetSetExternalOffset() noexcept
{
    return offsetof(ClassType, getSetExternalType);
}
