/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.9 (2024/04/23 12:58)

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
        CdDetected(const char*, const std::vector<clock_t>&) noexcept;
    };

    struct Pause
    {
    };

    struct Stop
    {
    };
}

#endif  // CORE_TOOLS_STATE_MACHINE_SUITE_STATE_H