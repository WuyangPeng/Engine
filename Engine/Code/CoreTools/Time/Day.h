///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/16 21:49)

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

        NODISCARD int GetDay() const noexcept;

    private:
        int day;
    };
}

#endif  // CORE_TOOLS_TIME_DAY_H
