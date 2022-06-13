///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/18 13:46)

#include "StaticPropertyExternal.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::string;

string CoreTools::StaticPropertyExternal::value;

CoreTools::StaticPropertyExternal::StaticPropertyExternal() noexcept
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, StaticPropertyExternal)

const string& CoreTools::StaticPropertyExternal::GetValue() noexcept
{
    return value;
}

void CoreTools::StaticPropertyExternal::SetValue(const string& aValue)
{
    value = aValue;
}
