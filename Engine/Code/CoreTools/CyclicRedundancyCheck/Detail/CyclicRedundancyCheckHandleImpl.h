///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/23 09:28)

#ifndef CORE_TOOLS_CYCLIC_REDUNDANCY_CHECK_CYCLIC_REDUNDANCY_CHECK_IMPL_H
#define CORE_TOOLS_CYCLIC_REDUNDANCY_CHECK_CYCLIC_REDUNDANCY_CHECK_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "CyclicRedundancyCheck16Table.h"
#include "CyclicRedundancyCheck32Table.h"
#include "CyclicRedundancyCheckCCITTTable.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE CyclicRedundancyCheckHandleImpl final
    {
    public:
        using ClassType = CyclicRedundancyCheckHandleImpl;

    public:
        CyclicRedundancyCheckHandleImpl() noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD uint16_t GetCCITT(int index) const;
        NODISCARD uint16_t Get16Table(int index) const;
        NODISCARD uint32_t Get32Table(int index) const;

    private:
        CyclicRedundancyCheckCCITTTable ccitt;
        CyclicRedundancyCheck16Table table16;
        CyclicRedundancyCheck32Table table32;
    };
}

#endif  // CORE_TOOLS_CYCLIC_REDUNDANCY_CHECK_CYCLIC_REDUNDANCY_CHECK_IMPL_H
