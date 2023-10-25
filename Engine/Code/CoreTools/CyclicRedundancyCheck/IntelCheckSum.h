///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/23 09:28)

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
