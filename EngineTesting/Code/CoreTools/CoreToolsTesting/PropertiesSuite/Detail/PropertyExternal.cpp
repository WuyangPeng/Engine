/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/04/23 12:55)

#include "PropertyExternal.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Properties/PropertyGetExternalDetail.h"
#include "CoreTools/Properties/PropertyGetSetExternalDetail.h"
#include "CoreTools/Properties/PropertySetExternalDetail.h"

CoreTools::PropertyExternal::PropertyExternal() noexcept
    : value{}, getType{ *this }, setType{ *this }, getSetType{ *this }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, PropertyExternal)

const std::string& CoreTools::PropertyExternal::GetValue() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return value;
}

void CoreTools::PropertyExternal::SetValue(const std::string& aValue)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    value = aValue;
}
