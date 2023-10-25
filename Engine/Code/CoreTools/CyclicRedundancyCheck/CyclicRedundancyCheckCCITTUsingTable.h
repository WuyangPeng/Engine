///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/23 09:28)

#ifndef CORE_TOOLS_CYCLIC_REDUNDANCY_CHECK_CYCLIC_REDUNDANCY_CHECK_CCITT_USING_TABLE_H
#define CORE_TOOLS_CYCLIC_REDUNDANCY_CHECK_CYCLIC_REDUNDANCY_CHECK_CCITT_USING_TABLE_H

#include "CoreTools/CoreToolsDll.h"

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE CyclicRedundancyCheckCCITTUsingTable final
    {
    public:
        using ClassType = CyclicRedundancyCheckCCITTUsingTable;

    public:
        CyclicRedundancyCheckCCITTUsingTable(const char* data, int length);

        CLASS_INVARIANT_DECLARE;

        NODISCARD uint16_t GetCyclicRedundancyCheck() const noexcept;

    private:
        void Calculation(const char* data, int length);
        NODISCARD static uint16_t GetCCITT(uint16_t cyclicRedundancyCheck, uint16_t value);

    private:
        uint16_t cyclicRedundancyCheck;
    };
}

#endif  // CORE_TOOLS_CYCLIC_REDUNDANCY_CHECK_CYCLIC_REDUNDANCY_CHECK_CCITT_USING_TABLE_H
