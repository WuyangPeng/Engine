///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.3 (2023/02/23 15:11)

#ifndef CORE_TOOLS_BASE_UNIQUE_ID_MANAGER_IMPL_H
#define CORE_TOOLS_BASE_UNIQUE_ID_MANAGER_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include <vector>

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE UniqueIdManagerImpl final
    {
    public:
        using ClassType = UniqueIdManagerImpl;

    public:
        explicit UniqueIdManagerImpl(int count);

        CLASS_INVARIANT_DECLARE;

    public:
        NODISCARD uint64_t NextUniqueId(int index);

        void SetUniqueId(int index, uint64_t latestIndex);

    private:
        using Containers = std::vector<uint64_t>;

    private:
        Containers uniqueId;
    };
}

#endif  // CORE_TOOLS_BASE_UNIQUE_ID_MANAGER_IMPL_H
