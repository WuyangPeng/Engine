/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/10 20:05)

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
        NODISCARD int64_t NextUniqueId(int index);

        void SetUniqueId(int index, int64_t latestIndex);

    private:
        using Containers = std::vector<int64_t>;

    private:
        Containers uniqueId;
    };
}

#endif  // CORE_TOOLS_BASE_UNIQUE_ID_MANAGER_IMPL_H
