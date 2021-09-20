//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.7.1.1 (2020/10/22 19:15)

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

        [[nodiscard]] int GetDay() const noexcept;

    private:
        int m_Day;
    };
}

#endif  // CORE_TOOLS_TIME_DAY_H
