//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.1 (2020/10/06 20:23)

#ifndef CORE_TOOLS_TIME_DATE_H
#define CORE_TOOLS_TIME_DATE_H

#include "Day.h"
#include "Month.h"
#include "Year.h"
#include "CoreTools/CoreToolsDll.h"

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE Date
    {
    public:
        using ClassType = Date;

    public:
        Date(const Year& year, const Month& month, const Day& day) noexcept
            : m_Year{ year }, m_Month{ month }, m_Day{ day }
        {
        }

        Year GetYear() const noexcept
        {
            return m_Year;
        }

    private:
        Year m_Year;
        Month m_Month;
        Day m_Day;
    };
}

#endif  // CORE_TOOLS_TIME_DATE_H
