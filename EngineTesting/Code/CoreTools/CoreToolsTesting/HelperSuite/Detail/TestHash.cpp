///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/24 15:38)

#include "TestHash.h"
#include "TestHashKey.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/HashCombine.h"

CLASS_INVARIANT_STUB_DEFINE(CoreTools, TestHash);

NODISCARD size_t CoreTools::TestHash::operator()(const TestHashKey& rhs) const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return rhs.GetHashValue();
}
