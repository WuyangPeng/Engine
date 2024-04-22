/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/12 15:12)

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
