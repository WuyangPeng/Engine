//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.7.1.1 (2020/10/22 18:44)

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

        NODISCARD Year GetYear() const noexcept;
        NODISCARD Month GetMonth() const noexcept;
        NODISCARD Day GetDay() const noexcept;

    private:
        Year year;
        Month month;
        Day day;
    };
}

#endif  // CORE_TOOLS_TIME_DATE_H
