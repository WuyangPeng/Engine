///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/12 14:31)

#include "CoreTools/CoreToolsExport.h"

#include "UniqueIDManagerImpl.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::UniqueIDManagerImpl::UniqueIDManagerImpl(int count)
    : uniqueID(count)
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool CoreTools::UniqueIDManagerImpl::IsValid() const noexcept
{
    if (!uniqueID.empty())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

uint64_t CoreTools::UniqueIDManagerImpl::NextUniqueID(int index)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    auto& currentUniqueID = uniqueID.at(index);

    CORE_TOOLS_ASSERTION_3(currentUniqueID < currentUniqueID + 1, "数值溢出。");

    return ++currentUniqueID;
}

void CoreTools::UniqueIDManagerImpl::SetUniqueID(int index, uint64_t latestIndex)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    auto& currentUniqueID = uniqueID.at(index);

    if (currentUniqueID < latestIndex)
    {
        currentUniqueID = latestIndex;
    }
}
