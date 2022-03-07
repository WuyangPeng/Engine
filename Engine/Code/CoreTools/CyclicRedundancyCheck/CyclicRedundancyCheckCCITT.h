///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/10 17:11)

#ifndef CORE_TOOLS_CYCLIC_REDUNDANCY_CHECK_CYCLIC_REDUNDANCY_CHECK_CCITT_H
#define CORE_TOOLS_CYCLIC_REDUNDANCY_CHECK_CYCLIC_REDUNDANCY_CHECK_CCITT_H

#include "CoreTools/CoreToolsDll.h"

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE CyclicRedundancyCheckCCITT final
    {
    public:
        using ClassType = CyclicRedundancyCheckCCITT;

    public:
        CyclicRedundancyCheckCCITT(const char* data, int length) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD uint16_t GetCyclicRedundancyCheck() const noexcept;

    private:
        void Calculation(const char* data, int length) noexcept;
        NODISCARD static uint16_t GetCCITT(uint16_t cyclicRedundancyCheck, uint16_t value) noexcept;

    private:
        uint16_t cyclicRedundancyCheck;
    };
}

#endif  // CORE_TOOLS_CYCLIC_REDUNDANCY_CHECK_CYCLIC_REDUNDANCY_CHECK_CCITT_H
