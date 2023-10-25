///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.5 (2023/09/20 14:08)

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
