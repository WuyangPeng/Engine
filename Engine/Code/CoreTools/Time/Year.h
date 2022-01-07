///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/16 21:52)

#ifndef CORE_TOOLS_TIME_TEAR_H
#define CORE_TOOLS_TIME_TEAR_H

#include "CoreTools/CoreToolsDll.h"

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE Year
    {
    public:
        using ClassType = Year;

    public:
        explicit Year(int year) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetYear() const noexcept;

    private:
        int year;
    };
}

#endif  // CORE_TOOLS_TIME_TEAR_H
