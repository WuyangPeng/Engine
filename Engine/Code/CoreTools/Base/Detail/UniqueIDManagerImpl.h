///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.2 (2021/08/26 19:06)

#ifndef CORE_TOOLS_BASE_UNIQUE_ID_MANAGER_IMPL_H
#define CORE_TOOLS_BASE_UNIQUE_ID_MANAGER_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include <vector>

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE UniqueIDManagerImpl final
    {
    public:
        using ClassType = UniqueIDManagerImpl;

    public:
        explicit UniqueIDManagerImpl(int count);

        CLASS_INVARIANT_DECLARE;

    public:
        NODISCARD uint64_t NextUniqueID(int index);

        void SetUniqueID(int index, uint64_t latestIndex);

    private:
        using Containers = std::vector<uint64_t>;

    private:
        Containers uniqueID;
    };
}

#endif  // CORE_TOOLS_BASE_UNIQUE_ID_MANAGER_IMPL_H
