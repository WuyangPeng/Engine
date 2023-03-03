///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.2 (2023/02/19 12:54)

#include "TestHashKey.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/HashCombine.h"

CoreTools::TestHashKey::TestHashKey(std::string name) noexcept
    : name{ std::move(name) }, buffer{ 5 }, key{ 2 }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, TestHashKey);

std::size_t CoreTools::TestHashKey::GetHashValue() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return HashValue(name, buffer, key);
}

bool CoreTools::TestHashKey::operator==(const TestHashKey& rhs) const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return name == rhs.name && buffer == rhs.buffer && key == rhs.key;
}
