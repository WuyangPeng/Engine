///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.5 (2023/04/03 17:08)

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
        explicit Year(int year) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetYear() const noexcept;

    private:
        int year;
    };
}

#endif  // CORE_TOOLS_TIME_TEAR_H
