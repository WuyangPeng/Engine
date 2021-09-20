//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.7.1.1 (2020/10/22 19:28)

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

        int GetYear() const noexcept;

    private:
        int m_Year;
    };
}

#endif  // CORE_TOOLS_TIME_TEAR_H
