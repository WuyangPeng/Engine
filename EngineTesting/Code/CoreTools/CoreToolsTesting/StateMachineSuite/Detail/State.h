///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/18 11:03)

#ifndef CORE_TOOLS_STATE_MACHINE_SUITE_STATE_H
#define CORE_TOOLS_STATE_MACHINE_SUITE_STATE_H

#include <ctime>
#include <vector>

namespace CoreTools
{
    struct Play
    {
    };

    struct OpenClose
    {
    };

    struct CdDetected
    {
        CdDetected(char const*, std::vector<clock_t> const&) noexcept;
    };

    struct Pause
    {
    };

    struct Stop
    {
    };
}

#endif  // CORE_TOOLS_STATE_MACHINE_SUITE_STATE_H