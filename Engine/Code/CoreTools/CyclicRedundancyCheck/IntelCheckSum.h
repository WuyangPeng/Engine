//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.0 (2020/10/26 13:52)

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

        [[nodiscard]] int GetIntelCheckSum() const noexcept;

    private:
        void Calculation(const char* data, int length) noexcept;

    private:
        int m_IntelCheckSum;
    };
}

#endif  // CORE_TOOLS_CYCLIC_REDUNDANCY_CHECK_INTEL_CHECK_SUM_H
