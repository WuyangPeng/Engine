///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.3 (2023/02/23 15:11)

#include "CoreTools/CoreToolsExport.h"

#include "UniqueIdManagerImpl.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::UniqueIdManagerImpl::UniqueIdManagerImpl(int count)
    : uniqueId(count)
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool CoreTools::UniqueIdManagerImpl::IsValid() const noexcept
{
    if (!uniqueId.empty())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

uint64_t CoreTools::UniqueIdManagerImpl::NextUniqueId(int index)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    auto& currentUniqueId = uniqueId.at(index);

    CORE_TOOLS_ASSERTION_3(currentUniqueId < currentUniqueId + 1, "数值溢出。");

    return ++currentUniqueId;
}

void CoreTools::UniqueIdManagerImpl::SetUniqueId(int index, uint64_t latestIndex)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    if (auto& currentUniqueId = uniqueId.at(index); currentUniqueId < latestIndex)
    {
        currentUniqueId = latestIndex;
    }
}
