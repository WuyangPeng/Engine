//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.7.1.1 (2020/10/26 13:52)

#ifndef CORE_TOOLS_CYCLIC_REDUNDANCY_CHECK_CYCLIC_REDUNDANCY_CHECK_32_H
#define CORE_TOOLS_CYCLIC_REDUNDANCY_CHECK_CYCLIC_REDUNDANCY_CHECK_32_H

#include "CoreTools/CoreToolsDll.h"

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE CyclicRedundancyCheck32 final
    {
    public:
        using ClassType = CyclicRedundancyCheck32;

    public:
        CyclicRedundancyCheck32(const char* data, int length);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] uint32_t GetCyclicRedundancyCheck32() const noexcept;

    private:
        void Calculation(const char* data, int length);

    private:
        uint32_t m_CyclicRedundancyCheck;
    };
}

#endif  // CORE_TOOLS_CYCLIC_REDUNDANCY_CHECK_CYCLIC_REDUNDANCY_CHECK_32_H
