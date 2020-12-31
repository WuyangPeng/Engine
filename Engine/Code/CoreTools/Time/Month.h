//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/22 19:26)

#ifndef CORE_TOOLS_TIME_MONTH_H
#define CORE_TOOLS_TIME_MONTH_H

#include "CoreTools/CoreToolsDll.h"

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE Month final
    {
    public:
        using ClassType = Month;

    public:
        explicit Month(int month) noexcept;

        CLASS_INVARIANT_DECLARE;

        int GetMonth() const noexcept;

        static Month Jan() noexcept;
        static Month Feb() noexcept;
        static Month Mar() noexcept;
        static Month Apr() noexcept;
        static Month May() noexcept;
        static Month Jun() noexcept;
        static Month Jul() noexcept;
        static Month Aug() noexcept;
        static Month Sep() noexcept;
        static Month Oct() noexcept;
        static Month Nov() noexcept;
        static Month Dec() noexcept;

    private:
        int m_Month;
    };
}

#endif  // CORE_TOOLS_TIME_MONTH_H
