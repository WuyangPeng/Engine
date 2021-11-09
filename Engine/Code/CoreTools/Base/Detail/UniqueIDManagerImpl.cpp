///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.2.2 (2021/08/26 19:08)

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

    CORE_TOOLS_ASSERTION_3(currentUniqueID < currentUniqueID + 1, "��ֵ�����");

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
