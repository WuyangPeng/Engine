/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/04/23 12:55)

#include "StaticPropertyExternal.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

std::string CoreTools::StaticPropertyExternal::value;

CoreTools::StaticPropertyExternal::StaticPropertyExternal() noexcept
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, StaticPropertyExternal)

const std::string& CoreTools::StaticPropertyExternal::GetValue() noexcept
{
    return value;
}

void CoreTools::StaticPropertyExternal::SetValue(const std::string& aValue)
{
    value = aValue;
}
