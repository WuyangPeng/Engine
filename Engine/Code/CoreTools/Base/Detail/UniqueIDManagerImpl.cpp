//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.1 (2020/10/12 11:01)

#include "CoreTools/CoreToolsExport.h"

#include "UniqueIDManagerImpl.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::UniqueIDManagerImpl::UniqueIDManagerImpl(int count)
    : m_UniqueID(count)
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::UniqueIDManagerImpl::IsValid() const noexcept
{
    if (0u < m_UniqueID.size())
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

uint64_t CoreTools::UniqueIDManagerImpl::NextUniqueID(int index)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    auto& uniqueID = m_UniqueID.at(index);

    CORE_TOOLS_ASSERTION_3(uniqueID < uniqueID + 1, "��ֵ�����");

    return ++uniqueID;
}
