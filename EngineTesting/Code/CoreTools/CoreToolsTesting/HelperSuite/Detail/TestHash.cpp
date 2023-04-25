///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.6 (2023/04/11 21:04)

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
