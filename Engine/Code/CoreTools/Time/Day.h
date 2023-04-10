///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/04/03 17:07)

#ifndef CORE_TOOLS_TIME_DAY_H
#define CORE_TOOLS_TIME_DAY_H

#include "CoreTools/CoreToolsDll.h"

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE Day final
    {
    public:
        using ClassType = Day;

    public:
        explicit Day(int day) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetDay() const noexcept;

    private:
        int day;
    };
}

#endif  // CORE_TOOLS_TIME_DAY_H
