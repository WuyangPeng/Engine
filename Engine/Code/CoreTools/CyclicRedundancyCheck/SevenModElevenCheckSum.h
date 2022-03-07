///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/10 17:14)

#ifndef CORE_TOOLS_CYCLIC_REDUNDANCY_CHECK_SEVEN_MOD_ELEVEN_CHECK_SUM_H
#define CORE_TOOLS_CYCLIC_REDUNDANCY_CHECK_SEVEN_MOD_ELEVEN_CHECK_SUM_H

#include "CoreTools/CoreToolsDll.h"

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE SevenModElevenCheckSum final
    {
    public:
        using ClassType = SevenModElevenCheckSum;

    public:
        SevenModElevenCheckSum(const char* data, int length);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCheckSum() const noexcept;

    private:
        void Calculation(const char* data, int length);

    private:
        static constexpr auto powersSize = 10;
        NODISCARD static int GetPowers(int index);

    private:
        int checkSum;
    };
}

#endif  // CORE_TOOLS_CYCLIC_REDUNDANCY_CHECK_SEVEN_MOD_ELEVEN_CHECK_SUM_H
