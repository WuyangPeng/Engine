///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.5 (2023/09/23 09:28)

#ifndef CORE_TOOLS_CYCLIC_REDUNDANCY_CHECK_CYCLIC_REDUNDANCY_CHECK_16_H
#define CORE_TOOLS_CYCLIC_REDUNDANCY_CHECK_CYCLIC_REDUNDANCY_CHECK_16_H

#include "CoreTools/CoreToolsDll.h"

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE CyclicRedundancyCheck16 final
    {
    public:
        using ClassType = CyclicRedundancyCheck16;

    public:
        CyclicRedundancyCheck16(const char* data, int length);

        CLASS_INVARIANT_DECLARE;

        NODISCARD uint16_t GetCyclicRedundancyCheck16() const noexcept;

    private:
        void Calculation(const char* data, int length);

    private:
        uint16_t cyclicRedundancyCheck;
    };
}

#endif  // CORE_TOOLS_CYCLIC_REDUNDANCY_CHECK_CYCLIC_REDUNDANCY_CHECK_16_H
