//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.1 (2020/10/06 20:23)

#ifndef CORE_TOOLS_TIME_MONTH_H
#define CORE_TOOLS_TIME_MONTH_H

#include "CoreTools/CoreToolsDll.h"

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE Month
    {
    public:
        using ClassType = Month;

    public:
        explicit Month(int month) noexcept
            : m_Month{ month }
        {
        }

        int GetMonth() const noexcept
        {
            return m_Month;
        }

        static Month Jan() noexcept
        {
            return Month{ 1 };
        }

        static Month Feb() noexcept
        {
            return Month{ 2 };
        }

        static Month Mar() noexcept
        {
            return Month{ 3 };
        }

        static Month Apr() noexcept
        {
            return Month{ 4 };
        }

        static Month May() noexcept
        {
            return Month{ 5 };
        }

        static Month Jun() noexcept
        {
            return Month{ 6 };
        }

        static Month Jul() noexcept
        {
            return Month{ 7 };
        }

        static Month Aug() noexcept
        {
            return Month{ 8 };
        }

        static Month Sep() noexcept
        {
            return Month{ 9 };
        }

        static Month Oct() noexcept
        {
            return Month{ 10 };
        }

        static Month Nov() noexcept
        {
            return Month{ 11 };
        }

        static Month Dec() noexcept
        {
            return Month{ 12 };
        }

    private:
        int m_Month;
    };
}

#endif  // CORE_TOOLS_TIME_MONTH_H
