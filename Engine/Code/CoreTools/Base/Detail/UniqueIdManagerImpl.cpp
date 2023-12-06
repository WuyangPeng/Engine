///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.5 (2023/09/23 10:48)

#include "CoreTools/CoreToolsExport.h"

#include "UniqueIdManagerImpl.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

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

int64_t CoreTools::UniqueIdManagerImpl::NextUniqueId(int index)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    auto& currentUniqueId = uniqueId.at(index);

    if (currentUniqueId + 1 <= 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("��ֵ���"))
    }

    return ++currentUniqueId;
}

void CoreTools::UniqueIdManagerImpl::SetUniqueId(int index, int64_t latestIndex)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    if (auto& currentUniqueId = uniqueId.at(index); currentUniqueId < latestIndex)
    {
        currentUniqueId = latestIndex;
    }
}
