///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.6 (2023/04/25 10:11)

#include "PropertiesBase.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

#include <string>

CoreTools::PropertiesBase::PropertiesBase() noexcept
    : value{ 0 }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, PropertiesBase)

int CoreTools::PropertiesBase::GetValue() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return value;
}

void CoreTools::PropertiesBase::SetValue(int aValue) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    value = aValue;
}

namespace CoreTools
{
    const ptrdiff_t CoreTools::PropertyBase<PropertiesBase::PropValue, PropertiesBase>::offset = offsetof(PropertiesBase, propValue);
}
