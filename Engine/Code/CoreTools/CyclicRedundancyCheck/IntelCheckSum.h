///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/10 17:13)

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
