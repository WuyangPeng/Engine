//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.1 (2020/10/06 20:23)

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
        explicit Year(int year) noexcept
            : m_Year{ year }
        {
        }

        int GetYear() const noexcept
        {
            return m_Year;
        }

    private:
        int m_Year;
    };
}

#endif  // CORE_TOOLS_TIME_TEAR_H
