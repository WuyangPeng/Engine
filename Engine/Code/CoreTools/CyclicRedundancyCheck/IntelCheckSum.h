///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.4 (2023/03/22 19:20)

#ifndef CORE_TOOLS_CYCLIC_REDUNDANCY_CHECK_INTEL_CHECK_SUM_H
#define CORE_TOOLS_CYCLIC_REDUNDANCY_CHECK_INTEL_CHECK_SUM_H

#include "CoreTools/CoreToolsDll.h"

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE IntelCheckSum final
    {
    public:
        using ClassType = IntelCheckSum;

    public:
        IntelCheckSum(const char* data, int length) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetIntelCheckSum() const noexcept;

    private:
        void Calculation(const char* data, int length) noexcept;

    private:
        int intelCheckSum;
    };
}

#endif  // CORE_TOOLS_CYCLIC_REDUNDANCY_CHECK_INTEL_CHECK_SUM_H
