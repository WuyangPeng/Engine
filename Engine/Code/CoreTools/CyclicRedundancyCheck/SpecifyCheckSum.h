//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.7.1.1 (2020/10/26 13:55)

#ifndef CORE_TOOLS_CYCLIC_REDUNDANCY_CHECK_SPECIFY_CHECK_SUM_H
#define CORE_TOOLS_CYCLIC_REDUNDANCY_CHECK_SPECIFY_CHECK_SUM_H

#include "CoreTools/CoreToolsDll.h"

#include "CyclicRedundancyCheckFwd.h"

#include <array>

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE SpecifyCheckSum final
    {
    public:
        using ClassType = SpecifyCheckSum;

    public:
        SpecifyCheckSum(const char* data, int length, SpecifyCheckSumPowers powers, int mod);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] int GetOriginalCheckSum() const noexcept;
        [[nodiscard]] int GetCollisions() const noexcept;

    private:
        void Calculation(const char* data, int length);
        [[nodiscard]] int GetCheckSum(const char* data, int length);

    private:
        static constexpr auto sm_PowersSize = 10;
        static const int GetSevenPowers(int index);
        static const int GetNinePowers(int index);

    private:
        int m_OriginalCheckSum;
        SpecifyCheckSumPowers m_Powers;
        int m_Mod;
        int m_Collisions;
    };
}

#endif  // CORE_TOOLS_CYCLIC_REDUNDANCY_CHECK_SPECIFY_CHECK_SUM_H
