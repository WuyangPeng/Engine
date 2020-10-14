//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.1 (2020/10/06 20:23)

#ifndef CORE_TOOLS_TIME_DAY_H
#define CORE_TOOLS_TIME_DAY_H

#include "CoreTools/CoreToolsDll.h"

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE Day
    {
    public:
        using ClassType = Day;

    public:
        explicit Day(int day) noexcept
            : m_Day{ day }
        {
        }

        int GetDay() const noexcept
        {
            return m_Day;
        }

    private:
        int m_Day;
    };
}

#endif  // CORE_TOOLS_TIME_DAY_H
