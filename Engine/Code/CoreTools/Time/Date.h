//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/22 18:44)

#ifndef CORE_TOOLS_TIME_DATE_H
#define CORE_TOOLS_TIME_DATE_H

#include "CoreTools/CoreToolsDll.h"

#include "Day.h"
#include "Month.h"
#include "Year.h"

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE Date final
    {
    public:
        using ClassType = Date;

    public:
        Date(const Year& year, const Month& month, const Day& day) noexcept;

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] Year GetYear() const noexcept;
        [[nodiscard]] Month GetMonth() const noexcept;
        [[nodiscard]] Day GetDay() const noexcept;

    private:
        Year m_Year;
        Month m_Month;
        Day m_Day;
    };
}

#endif  // CORE_TOOLS_TIME_DATE_H
