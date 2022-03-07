///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/10 17:15)

#ifndef CORE_TOOLS_CYCLIC_REDUNDANCY_CHECK_SPECIFY_CHECK_SUM_H
#define CORE_TOOLS_CYCLIC_REDUNDANCY_CHECK_SPECIFY_CHECK_SUM_H

#include "CoreTools/CoreToolsDll.h"

#include "CyclicRedundancyCheckFwd.h"

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE SpecifyCheckSum final
    {
    public:
        using ClassType = SpecifyCheckSum;

    public:
        SpecifyCheckSum(const char* data, int length, SpecifyCheckSumPowers powers, int mod);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetOriginalCheckSum() const noexcept;
        NODISCARD int GetCollisions() const noexcept;

    private:
        void Calculation(const char* data, int length);
        NODISCARD int GetCheckSum(const char* data, int length);

    private:
        static constexpr auto sm_PowersSize = 10;
        NODISCARD static int GetSevenPowers(int index);
        NODISCARD static int GetNinePowers(int index);

    private:
        int originalCheckSum;
        SpecifyCheckSumPowers powers;
        int mod;
        int collisions;
    };
}

#endif  // CORE_TOOLS_CYCLIC_REDUNDANCY_CHECK_SPECIFY_CHECK_SUM_H
