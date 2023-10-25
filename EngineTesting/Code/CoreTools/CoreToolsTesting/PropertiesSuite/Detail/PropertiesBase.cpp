///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/25 14:43)

#include "PropertiesBase.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

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
