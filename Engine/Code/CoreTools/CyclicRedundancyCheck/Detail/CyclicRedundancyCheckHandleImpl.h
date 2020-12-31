//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/26 13:49)

#ifndef CORE_TOOLS_CYCLIC_REDUNDANCY_CHECK_CYCLIC_REDUNDANCY_CHECK_IMPL_H
#define CORE_TOOLS_CYCLIC_REDUNDANCY_CHECK_CYCLIC_REDUNDANCY_CHECK_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "CyclicRedundancyCheck16Table.h"
#include "CyclicRedundancyCheck32Table.h"
#include "CyclicRedundancyCheckCCITTTable.h"

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE CyclicRedundancyCheckHandleImpl final
    {
    public:
        using ClassType = CyclicRedundancyCheckHandleImpl;

    public:
        CyclicRedundancyCheckHandleImpl() noexcept;

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] uint16_t GetCCITT(int index) const;
        [[nodiscard]] uint16_t Get16Table(int index) const;
        [[nodiscard]] uint32_t Get32Table(int index) const;

    private:
        CyclicRedundancyCheckCCITTTable m_CCITT;
        CyclicRedundancyCheck16Table m_Table16;
        CyclicRedundancyCheck32Table m_Table32;
    };
}

#endif  // CORE_TOOLS_CYCLIC_REDUNDANCY_CHECK_CYCLIC_REDUNDANCY_CHECK_IMPL_H
