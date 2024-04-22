/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/12 15:12)

#ifndef CORE_TOOLS_CYCLIC_REDUNDANCY_CHECK_CYCLIC_REDUNDANCY_CHECK_IMPL_H
#define CORE_TOOLS_CYCLIC_REDUNDANCY_CHECK_CYCLIC_REDUNDANCY_CHECK_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "CyclicRedundancyCheck16Table.h"
#include "CyclicRedundancyCheck32Table.h"
#include "CyclicRedundancyCheckCcittTable.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE CyclicRedundancyCheckHandleImpl final
    {
    public:
        using ClassType = CyclicRedundancyCheckHandleImpl;

    public:
        CyclicRedundancyCheckHandleImpl() noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD uint16_t GetCcitt(int index) const;
        NODISCARD uint16_t Get16Table(int index) const;
        NODISCARD uint32_t Get32Table(int index) const;

    private:
        CyclicRedundancyCheckCcittTable ccitt;
        CyclicRedundancyCheck16Table table16;
        CyclicRedundancyCheck32Table table32;
    };
}

#endif  // CORE_TOOLS_CYCLIC_REDUNDANCY_CHECK_CYCLIC_REDUNDANCY_CHECK_IMPL_H
