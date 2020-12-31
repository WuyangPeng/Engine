//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.1 (2020/10/12 11:01)

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
        [[nodiscard]] uint64_t NextUniqueID(int index);

    private:
        using Containers = std::vector<uint64_t>;

    private:
        Containers m_UniqueID;
    };
}

#endif  // CORE_TOOLS_BASE_UNIQUE_ID_MANAGER_IMPL_H
