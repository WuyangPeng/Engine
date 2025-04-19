/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/04/23 12:54)

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

#ifdef SYSTEM_PLATFORM_WIN32

namespace CoreTools
{
    const ptrdiff_t PropertyBase<PropertiesBase::PropValue, PropertiesBase>::offset = offsetof(PropertiesBase, propValue);
}

#endif  // SYSTEM_PLATFORM_WIN32